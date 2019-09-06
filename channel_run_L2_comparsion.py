import os
import shutil
import sys
import json
import matplotlib
import matplotlib.pyplot as plt
import numpy as np

def contains_run(l,id):
    for e in l:
        if id in e: return True
    return False

directory=sys.argv[1]
directory2=sys.argv[2]
output_dir=sys.argv[3]
jsons_it=[]
data={}
matplotlib.use("GTK3Agg")

l=sorted(os.listdir(directory))
l2=[]
for f in l:
    if len(f.split("_"))>2:
        run_id=f.split("_")[2][3:]
        iteration_id=int(f[f.index("L")+1])
        if iteration_id==2 and contains_run(os.listdir(directory2),run_id): l2.append(f)

for fname,fname2 in zip(l2,sorted(os.listdir(directory2))):
    if fname.endswith(".json") and fname2.endswith(".json"):
        run_id=""
        if len(fname.split("_"))>2 and len(fname2.split("_"))>2:
            run_id=fname.split("_")[2][3:]
            run_id2=fname2.split("_")[1][3:]

            if run_id==run_id2:
                f=open(os.path.join(directory,fname),"r")
                d=json.loads(f.read())
                f2=open(os.path.join(directory2,fname2),"r")
                d2=json.loads(f2.read())
                i=(d,run_id)
                j=(d2,run_id)
                jsons_it.append((i,j))

output_path=os.path.join(output_dir,"Resolutions_per_run_plots")
if os.path.isdir(output_path): shutil.rmtree(output_path)
os.makedirs(output_path)

it_channel_dict={}
it_channel_dict2={}
for i,j in jsons_it:
    for sec,sec2 in zip(i[0]["Parameters"]["Sectors"],j[0]["Parameters"]["Sectors"]):
        channel_key_0="sector: "+sec["sector"]
        sec_path=os.path.join(output_path,"Sector_"+sec["sector"])
        if not os.path.isdir(sec_path): os.makedirs(sec_path)

        for stations,stations2 in zip(sec["Stations"],sec2["Stations"]):
            channel_key_1=", station: "+stations["station"]
            stat_path=os.path.join(sec_path,"Station_"+stations["station"])
            if not os.path.isdir(stat_path): os.makedirs(stat_path)

            for pls,pls2 in zip(stations["Planes"],stations2["Planes"]):
                channel_key_2=", plane: "+pls["plane"]
                pl_path=os.path.join(stat_path,"Plane_"+pls["plane"])
                if not os.path.isdir(pl_path): os.makedirs(pl_path)

                for chs,chs2 in zip(pls["Channels"],pls2["Channels"]):
                    channel_key_3=", channel: "+chs["channel"]
                    ch_key=channel_key_0+channel_key_1+channel_key_2+channel_key_3

                    tmp=[]
                    if ch_key in it_channel_dict: tmp=it_channel_dict[ch_key]
                    tmp.append((float(chs["time_precision"]),i[1]))
                    it_channel_dict.update({ch_key : tmp})

                    tmp=[]
                    if ch_key in it_channel_dict2: tmp=it_channel_dict2[ch_key]
                    tmp.append((float(chs2["time_precision"]),j[1]))
                    it_channel_dict2.update({ch_key : tmp})

for k,v,k2,v2 in zip(it_channel_dict.keys(),it_channel_dict.values(),it_channel_dict2.keys(),it_channel_dict2.values()):
    v=sorted(v,key=lambda a: a[1])
    x=[seq[1] for seq in v]
    v=[seq[0] for seq in v]
    xx=[]
    vv=[]

    v2=sorted(v2,key=lambda b: b[1])
    x2=[seq[1] for seq in v2]
    v2=[seq[0] for seq in v2]
    xx2=[]
    vv2=[]

    for e,e2,e3,e4 in zip(x,v,x2,v2):
        if e2!=1000 and e4!=1000:
            xx.append(e)
            vv.append(e2)
            xx2.append(e3)
            vv2.append(e4)

    if xx and vv and xx2 and vv2:
        plt.plot(xx,vv,"-o",color="blue",label="Second iteration, computed using original code")
        plt.plot(xx2,vv2,"-o",color="red",label="Second iteration, computed using PCL flow")
    plt.xlabel("Run",labelpad=20,fontsize=25)
    plt.ylabel("Resolution",fontsize=25)
    plt.yticks(np.arange(0.1,0.4,0.01))
    plt.tick_params(labelsize=15)
    plt.title("Resolution for different runs and iterations in "+k+", L2",pad=20,fontsize=18)
    plt.grid()
    plt.legend()

    t=k.split(":")
    sector="Sector_"+t[1][1]
    station="Station_"+t[2][1]
    plane="Plane_"+t[3][1]

    fig=plt.gcf()
    fig.set_size_inches(15,8)
    fig.autofmt_xdate()
    fig.savefig(os.path.join(output_path,sector,station,plane,"resolution_per_run in "+k+", L2"))
    fig.clf()
