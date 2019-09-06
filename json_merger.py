import os
import sys
import shutil
import json

main_json=sys.argv[1]
input_dir=sys.argv[2]
output_dir=sys.argv[3]

f=open(main_json,"r")
main=json.loads(f.read())
f.close()

output_path=os.path.join(output_dir,"JSON_merged")
if os.path.isdir(output_path): shutil.rmtree(output_path)
os.makedirs(output_path)

for fname in sorted(os.listdir(input_dir)):
    if fname.endswith(".json"):
        if len(fname.split("_"))>2:
            run_id=fname.split("_")[2][3:]
            iteration_id=int(fname[fname.index("L")+1])
            if iteration_id>1 or "Cut16" in fname:
                f=open(os.path.join(input_dir,fname),"r")
                d=json.loads(f.read())
                f.close()

                for sec,sec2 in zip(d["Parameters"]["Sectors"],main["Parameters"]["Sectors"]):
                    for stations,stations2 in zip(sec["Stations"],sec2["Stations"]):
                        for pls,pls2 in zip(stations["Planes"],stations2["Planes"]):
                            for chs,chs2 in zip(pls["Channels"],pls2["Channels"]):
                                chs["time_precision"]=chs2["time_precision"]

                with open(os.path.join(output_path,"PLCTest_Run"+run_id+"_L"+str(iteration_id)+".json"),"w") as f:
                    json.dump(d,f,indent=4)
