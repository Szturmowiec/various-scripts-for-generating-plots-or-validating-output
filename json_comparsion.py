import sys
import json

fname=sys.argv[1]
fname2=sys.argv[2]
prec_d={}
off_d={}
param_d={}

f=open(fname,"r")
f2=open(fname2,"r")

t=True
x,x2=(json.loads(f.read()),json.loads(f2.read()))
if x["formula"]!=x2["formula"]:
    t=False
    print("Different formulas: "+x["formula"]+" and "+x2["formula"])

for sec,sec2 in zip(x["Parameters"]["Sectors"],x2["Parameters"]["Sectors"]):
    channel_key_0="sector: "+sec["sector"]

    for stations,stations2 in zip(sec["Stations"],sec2["Stations"]):
        channel_key_1=", station: "+stations["station"]

        for pls,pls2 in zip(stations["Planes"],stations2["Planes"]):
            channel_key_2=", plane: "+pls["plane"]

            for chs,chs2 in zip(pls["Channels"],pls2["Channels"]):
                channel_key_3=", channel: "+chs["channel"]
                key=channel_key_0+channel_key_1+channel_key_2+channel_key_3

                prec,prec2=(chs["time_precision"],chs2["time_precision"])
                off,off2=(chs["time_offset"],chs2["time_offset"])
                param,param2=(chs["param"],chs2["param"])
                if prec!=prec2:
                    t=False
                    print("Different time precision: "+prec+" and "+prec2+" in "+key)
                    prec_d.update({key : (prec,prec2)})
                if off!=off2:
                    t=False
                    print("Different time offset: "+off+" and "+off2+" in "+key)
                    off_d.update({key : (off,off2)})
                for p,p2 in zip(param,param2):
                    if p!=p2:
                        t=False
                        print("Different calibration parameters: "+p+" and "+p2+" in "+key)

if t: print("Specified JSON files are identical")
