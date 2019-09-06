import os
import shutil
import sys
import json
import matplotlib
import matplotlib.pyplot as plt
from matplotlib.lines import Line2D
import numpy as np

directory=sys.argv[1]
output_dir=sys.argv[2]
jsons=[]
data={}
matplotlib.use("GTK3Agg")

for fname in sorted(os.listdir(directory)):
    if fname.endswith(".json"):
        run_id=""
        if len(fname.split("_"))>2:
            iteration_id=int(fname[fname.index("L")+1])
            if iteration_id==5:
                f=open(os.path.join(directory,fname),"r")
                d=json.loads(f.read())
                jsons.append(d)

output_path=os.path.join(output_dir,"Resolutions_per_channel_L5_plots")
if os.path.isdir(output_path): shutil.rmtree(output_path)
os.makedirs(output_path)

for j in jsons:
    for sec in j["Parameters"]["Sectors"]:
        channel_key_0="sector: "+sec["sector"]

        for stations in sec["Stations"]:
            channel_key_1=", station: "+stations["station"]

            for pls in stations["Planes"]:
                channel_key_2=", plane: "+pls["plane"]

                ch_dict={}
                for chs in pls["Channels"]:
                    pl_key=channel_key_0+channel_key_1+channel_key_2
                    ch_key=chs["channel"]

                    tmp=[]
                    if pl_key in data and ch_key in data[pl_key]: tmp=data[pl_key][ch_key]
                    tmp.append(float(chs["time_precision"]))
                    ch_dict.update({ch_key : tmp})
                data.update({pl_key : ch_dict})

for key,value in data.items():
    ax=plt.gca()
    order=[]
    kk=list(value.keys())
    for i in range(int(len(kk)/2)):
        order.append(kk[i])
        if kk[i]!=kk[len(kk)-(i+1)]: order.append(kk[len(kk)-(i+1)])

    list_value=[]
    for k,v in value.items(): list_value.append((k,v))
    list_value=[tuple for x in order for tuple in list_value if tuple[0]==x]

    for k,v in list_value:
        v=list(filter(lambda x: x!=1000,v))
        plt.scatter([k]*len(v),v,color="red",s=10)
        if v:
            plt.scatter(k,v[0],color="green",s=15)
            plt.scatter(k,v[-1],color="blue",s=15)

        plt.xlabel("Channel",fontsize=25)
        plt.ylabel("Resolution",fontsize=25)
        plt.yticks(np.arange(0.0,0.4,0.01))
        plt.tick_params(labelsize=10)
        plt.title("Resolution for different channels for all runs in "+key+", L5",pad=20,fontsize=18)

    legend_elements=[Line2D([0],[0],marker='o',color='w',label='Oldest run',markerfacecolor='g',markersize=10),
                    Line2D([0],[0],marker='o',color='w',label='Newest run',markerfacecolor='b',markersize=10)]

    ax.set_axisbelow(True)
    ax.legend(handles=legend_elements)
    plt.grid()

    fig=plt.gcf()
    fig.set_size_inches(15,8)
    fig.savefig(os.path.join(output_path,"resolution_per_plane_all_channels_all_runs in "+key+", L5"))
    fig.clf()
