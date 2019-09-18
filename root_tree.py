import os
import sys
import json
import re
import ROOT
from array import array

directory=sys.argv[1]
rad=sys.argv[2]
output_dir=sys.argv[3]
out=sys.argv[4]
data=[]

run=array('i',[0])
sectors=array('i',[0])
stations=array('i',[0])
planes=array('i',[0])
channels=array('i',[0])
iterations=array('i',[0])
res=array('d',[0.0])
luminosity=array('d',[0.0])

r_list=[]
with open(rad) as f:
    lines=f.readlines()
    for line in lines:
        line=line.rstrip()[3:]
        r_list.append((line.split(" --> ")))
r_list.pop()
r_list=dict(r_list)

for fname in sorted(os.listdir(directory)):
    if fname.endswith(".json"):
        if len(fname.split("_"))>2:
            run_id=int(re.search(r"Run\d\d\d\d\d\d",fname).group(0)[3:])
            iteration_id=int(re.search(r"_L\d",fname).group(0)[2])
            f=open(os.path.join(directory,fname),"r")
            data.append(((json.loads(f.read())),iteration_id,run_id))
            f.close()

f=ROOT.TFile(out,'RECREATE')
tree=ROOT.TTree('Output','')

tree.Branch('Run',run,'run/I')
tree.Branch('Sector',sectors,'sector/I')
tree.Branch('Station',stations,'station/I')
tree.Branch('Plane',planes,'plane/I')
tree.Branch('Channel',channels,'channel/I')
tree.Branch('Iteration',iterations,'iteration/I')
tree.Branch('Resolution',res,'resolution/D')
tree.Branch('Luminosity',luminosity,'luminosity/D')

for i in range(len(data)):
    iterations[0]=data[i][1]
    run[0]=data[i][2]
    if str(run[0]) in r_list.keys(): luminosity[0]=float(r_list.get(str(run[0])))
    else: luminosity[0]=-1.0

    for sec in data[i][0]["Parameters"]["Sectors"]:
        sectors[0]=int(sec["sector"])

        for stat in sec["Stations"]:
            stations[0]=int(stat["station"])

            for pls in stat["Planes"]:
                planes[0]=int(pls["plane"])

                for chs in pls["Channels"]:
                    channels[0]=int(chs["channel"])
                    res[0]=float(chs["time_precision"])
                    tree.Fill()

f.Write()
f.Close()
