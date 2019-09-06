from ROOT import TFile, Double
import sys

f=TFile.Open(sys.argv[1])
f2=TFile.Open(sys.argv[2])

def compare_histos(h,h2):
    binsh=h.GetXaxis().GetNbins();
    binsh2=h2.GetXaxis().GetNbins();
    if binsh!=binsh2:
        print("Histograms have different number of bins, "+str(binsh)+" and "+str(binsh2))
        print(h.GetName(),h2.GetName())
        return False

    for i in range(binsh):
        if h.GetBinContent(i)!=h2.GetBinContent(i):
            print(str(i)+" differs from "+str(h.GetBinContent(i))+" and "+str(h2.GetBinContent(i)))
            print(h.GetName(),h2.GetName())
            return False
    return True

def GetPoint_own(g,i):
    if i<0 or i>=g.GetN(): return -1
    if not g.GetX() or not g.GetY(): return -1
    x=g.GetX()[i]
    y=g.GetY()[i]
    return (x,y)

def compare_graphs(h,h2):
    n=h.GetN()
    n2=h2.GetN()
    if n!=n2:
        print("Graphs have different number of points, "+str(n)+" and "+str(n2))
        print(h.GetName(),h2.GetName())
        return False

    for i in range(n):
        x,y=GetPoint_own(h,i)
        x2,y2=GetPoint_own(h2,i)
        if (x,y)!=(x2,y2):
            print("Graphs are different, differentiating points: ("+str(x)+","+str(y)+") and ("+str(x2)+","+str(y2)+")")
            print(h.GetName(),h2.GetName())
            return False
    return True

hl=[]
hl2=[]
t=True

def search_root_rec((keys,keys2)):
    global t
    global hl
    global hl2
    for k in keys: hl.append(k.GetName())
    for k in keys2: hl2.append(k.GetName())

    keys=sorted(keys)
    keys2=sorted(keys2)
    for k,k2 in zip(keys,keys2):
        h=k.ReadObj()
        h2=k2.ReadObj()
        if h.GetName()!=h2.GetName() and (h.GetName()!="DiamondTimingAnalyzer" and h2.GetName()!="DiamondTimingAnalyzer"):
            print("Specified root files have different file structure, keys: "+h.GetName()+" "+h2.GetName())
            t=False
            continue
        if (h.ClassName()=="TH1F" or h.ClassName()=="TH2F") and (h2.ClassName()=="TH1F" or h2.ClassName()=="TH2F"):
            if not compare_histos(h,h2): t=False
        if h.ClassName()=="TGraph" and h2.ClassName()=="TGraph":
            if not compare_graphs(h,h2): t=False
        if h.ClassName()=="TDirectoryFile" and h2.ClassName()=="TDirectoryFile": search_root_rec((h.GetListOfKeys(),h2.GetListOfKeys()))

search_root_rec((f.GetListOfKeys(),f2.GetListOfKeys()))
if t: print("The root files are identical")
else:
    hl=set(hl)
    hl2=set(hl2)
    print("Things present in the second file but not in the first one: ")
    out=hl2-hl
    for e in out: print(e)
    if not out: print("None")

    print("\nThings present in the first file but not in the second one: \n")
    out=hl-hl2
    for e in out: print(e)
    if not out: print("None")
    print("Numbers of keys in the first and second file:")
    print(len(hl),len(hl2))
