import os
import shutil
import sys
import json
import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import re

directory=sys.argv[1]
output_dir=sys.argv[2]
data=[]
channels_data={}
clean_data={}
x=[]

if not os.path.exists(output_dir): os.mkdir(output_dir)

for fname in sorted(os.listdir(directory)):
    if fname.endswith(".json"):
        if len(fname.split("_"))>2:
            year=2018
            try:
                year=int(re.search(r"_201\d_",fname).group(0)[1:-1])
            except AttributeError:
                continue

            if year!=2017:
                f=open(os.path.join(directory,fname),"r")
                data.append(json.loads(f.read()))

for i in range(len(data)):
    for sec in data[i]["Parameters"]["Sectors"]:
        channel_key_0="sector: "+sec["sector"]

        for stations in sec["Stations"]:
            channel_key_1=", station: "+stations["station"]

            for pls in stations["Planes"]:
                channel_key_2=", plane: "+pls["plane"]
                channel_dict={}

                for chs in pls["Channels"]:
                    key=channel_key_0+channel_key_1+channel_key_2
                    ch_key=chs["channel"]

                    tmp=[]
                    if key in clean_data and ch_key in clean_data[key]: tmp=clean_data[key][ch_key]
                    tmp.append(float(chs["time_precision"]))
                    channel_dict.update({ch_key: tmp})
                clean_data.update({key: channel_dict})
    x.append(str(i))

output_path=os.path.join(output_dir,"Resolution_per_plane_plots")
if os.path.isdir(output_path): shutil.rmtree(output_path)
os.makedirs(output_path)

for key,value in clean_data.items():
    maxx=0.0
    minn=100.0
    colors=["tab:blue","tab:orange","tab:green","tab:red","tab:purple","tab:brown","tab:pink","tab:gray","tab:olive","black","magenta","deepskyblue"]
    for k,v in value.items():
        if not 1000 in v:
            plt.plot(x,v,"-o",label="channel "+str(k),color=colors[int(k)])
            if min(v)<minn: minn=min(v)
            if max(v)>maxx: maxx=max(v)

    plt.xlabel("Iterations",fontsize=15)
    plt.ylabel("Resolution",fontsize=15)
    plt.yticks(np.arange(0.1,0.4,0.01))
    plt.tick_params(labelsize=10)
    plt.title("Resolution for each iteration in channels in "+key,pad=20,fontsize=18)
    plt.grid()
    ax=plt.gca()
    ax.legend(loc='upper right')

    fig=plt.gcf()
    fig.set_size_inches(15,8)
    fig.savefig(os.path.join(output_path,"time_precision_planes_"+key.replace(" ","_").replace(":","")))
    fig.clf()
