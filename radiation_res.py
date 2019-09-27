import os
import shutil
import sys
import json
import matplotlib
import matplotlib.pyplot as plt
import numpy as np
from math import floor,ceil
import re

directory=sys.argv[1]
rad=sys.argv[2]
output_dir=sys.argv[3]
iter_nr=sys.argv[4]
jsons_it=[]
data={}
for i in range(int(iter_nr)): jsons_it.append([])

r_list=[]
with open(rad) as f:
    line=f.readline()[3:]
    while line:
        line=f.readline().rstrip()[3:]
        r_list.append((line.split(" --> ")))
r_list.pop()
r_list=dict(r_list)

for fname in sorted(os.listdir(directory)):
    if fname.endswith(".json"):
        run_id=""
        if len(fname.split("_"))>2:
            run_id=re.search(r"Run\d\d\d\d\d\d",fname).group(0)[3:]
            iteration_id=int(re.search(r"_L\d",fname).group(0)[2])
            if iteration_id!=0 and (iteration_id>1 or "Cut16" in fname):
                f=open(os.path.join(directory,fname),"r")
                d=json.loads(f.read())
                if run_id in r_list: jsons_it[iteration_id].append((d,r_list[run_id]))

output_path=os.path.join(output_dir,"Resolutions_per_rad_plots")
if os.path.isdir(output_path): shutil.rmtree(output_path)
os.makedirs(output_path)

for i in range(len(jsons_it)):
    it_channel_dict={}
    for j in jsons_it[i]:
        for sec in j[0]["Parameters"]["Sectors"]:
            channel_key_0="sector: "+sec["sector"]
            sec_path=os.path.join(output_path,"Sector_"+sec["sector"])
            if not os.path.isdir(sec_path): os.makedirs(sec_path)

            for stations in sec["Stations"]:
                channel_key_1=", station: "+stations["station"]
                stat_path=os.path.join(sec_path,"Station_"+stations["station"])
                if not os.path.isdir(stat_path): os.makedirs(stat_path)

                for pls in stations["Planes"]:
                    channel_key_2=", plane: "+pls["plane"]
                    pl_path=os.path.join(stat_path,"Plane_"+pls["plane"])
                    if not os.path.isdir(pl_path): os.makedirs(pl_path)

                    for chs in pls["Channels"]:
                        channel_key_3=", channel: "+chs["channel"]
                        ch_key=channel_key_0+channel_key_1+channel_key_2+channel_key_3

                        tmp=[]
                        if ch_key in it_channel_dict: tmp=it_channel_dict[ch_key]
                        tmp.append((float(chs["time_precision"]),j[1]))
                        it_channel_dict.update({ch_key : tmp})
    data.update({i : it_channel_dict})

for key,value in data.items():
    for k,v in value.items():
        v=sorted(v,key=lambda x: x[1])
        x=[float(seq[1][:-2]) for seq in v]
        v=[seq[0] for seq in v]
        x2=[]
        v2=[]

        for e,e2 in zip(x,v):
            if e2!=1000:
                x2.append(e)
                v2.append(e2)

        if x2 and v2:
            plt.plot(sorted(x2),v2,"-o",label="L"+str(key))
            plt.xticks(np.arange(floor(min(x2)),ceil(max(x2))+2,2))
            plt.xlabel('Integrated luminosity ($fb^{-1}$)',labelpad=20,fontsize=25)
            plt.ylabel("Resolution (ns)",fontsize=25)
            plt.yticks(np.arange(0.1,0.4,0.01))
            plt.tick_params(labelsize=12)
            plt.title("Resolution for different radiation intakes and iterations in "+k+", L"+str(key),pad=20,fontsize=18)
            plt.grid()

            t=k.split(":")
            sector="Sector_"+t[1][1]
            station="Station_"+t[2][1]
            plane="Plane_"+t[3][1]

            fig=plt.gcf()
            fig.set_size_inches(15,8)
            fig.savefig(os.path.join(output_path,sector,station,plane,"resolution_per_rad in "+k+", L"+str(key)))
            fig.clf()
