from ROOT import *
from array import array

#purity_fb6795fa13173ba165a794d7c5e9ee8e93864edd.log
inputs="""
REGION: EB MHT_250
purity in SR:  0.928952013919 +/- 0.00149336551704
purity in SR:  0.905820353148 +/- 0.00166795579796
purity in SR:  0.945260419855 +/- 0.00141151938162
--
REGION: EB MHT_300
purity in SR:  0.928585108869 +/- 0.00174615752355
purity in SR:  0.89905954869 +/- 0.00197560416128
purity in SR:  0.92835509724 +/- 0.00175816962937
--
REGION: EB MHT_350
purity in SR:  0.934390705978 +/- 0.0017263076844
purity in SR:  0.904456550677 +/- 0.00201917124961
purity in SR:  0.946050557084 +/- 0.00168928052302
--
REGION: EB MHT_500
purity in SR:  0.9469240369 +/- 0.00310911964308
purity in SR:  0.922917679498 +/- 0.00362120919086
purity in SR:  0.956273538153 +/- 0.00303769641034
--
REGION: EE MHT_250
purity in SR:  0.840365832199 +/- 0.00336088265716
purity in SR:  0.844061352116 +/- 0.00327044338018
purity in SR:  0.852878089263 +/- 0.00322985298497
--
REGION: EE MHT_300
purity in SR:  0.813732923217 +/- 0.00422230308771
purity in SR:  0.845714672705 +/- 0.00399547640766
purity in SR:  0.861209965965 +/- 0.00380687284365
--
REGION: EE MHT_350
purity in SR:  0.887873032523 +/- 0.0040610131906
purity in SR:  0.860302718924 +/- 0.00440941539314
purity in SR:  0.922976711756 +/- 0.00370819189324
--
REGION: EE MHT_500
purity in SR:  0.924936513488 +/- 0.00923730234314
purity in SR:  0.906586906152 +/- 0.0100080580085
purity in SR:  0.948397774762 +/- 0.00842386735973
"""

f= open("Purity/Purity_Output_FINAL_17Data+16MC.txt","a")
f.write("#purity EB:              purity EB error:      purity EE:          purity EE error:\n")

x=[275,325,425,650]
xErr=[25,25,75,150]
EB={"nom":[],"alt":[],"mcalt":[],"nomErr":[],"altErr":[],"mcaltErr":[]}
EE={"nom":[],"alt":[],"mcalt":[],"nomErr":[],"altErr":[],"mcaltErr":[]}
for measurement in inputs.split("--"):
    lines = measurement[1:].split("\n")
    print lines
    if lines[0].find("EB") != -1 : 
        EB["alt"].append(float(lines[1].split(":  ")[1].split(" +/- ")[0]))
        EB["altErr"].append(float(lines[1].split(":  ")[1].split(" +/- ")[1]))
        EB["nom"].append(float(lines[2].split(":  ")[1].split(" +/- ")[0]))
        EB["nomErr"].append(float(lines[2].split(":  ")[1].split(" +/- ")[1]))
        EB["mcalt"].append(float(lines[3].split(":  ")[1].split(" +/- ")[0]))
        EB["mcaltErr"].append(float(lines[3].split(":  ")[1].split(" +/- ")[1]))
        
    else :
        EE["alt"].append(float(lines[1].split(":  ")[1].split(" +/- ")[0]))
        EE["altErr"].append(float(lines[1].split(":  ")[1].split(" +/- ")[1]))
        EE["nom"].append(float(lines[2].split(":  ")[1].split(" +/- ")[0]))
        EE["nomErr"].append(float(lines[2].split(":  ")[1].split(" +/- ")[1]))
        EE["mcalt"].append(float(lines[3].split(":  ")[1].split(" +/- ")[0]))
        EE["mcaltErr"].append(float(lines[3].split(":  ")[1].split(" +/- ")[1]))

EB["avg"] = []
EB["avgErr"] = []
EE["avg"] = []
EE["avgErr"] = []

f.write("#purity EB:       purity EE: \n")

for i in range(len(EE["nom"])):
    EB["avg"].append((EB["nom"][i]+EB["mcalt"][i]+EB["alt"][i])/3.)
    EE["avg"].append((EE["nom"][i]+EE["mcalt"][i]+EE["alt"][i])/3.)
    f.write(str(EB["avg"][i])+"    "+str(EE["avg"][i])+"\n")

f.write("#purity EB error:       purity EE error: \n")
for i in range(len(EE["nom"])):
    EB["avgErr"].append(0.)
    EE["avgErr"].append(0.)
    if( abs(EB["avg"][i] - EB["nom"][i]) > EB["avgErr"][i] ):  
        EB["avgErr"][i]=abs(EB["avg"][i] - EB["nom"][i])
    if( abs(EB["avg"][i] - EB["alt"][i]) > EB["avgErr"][i] ):  
        EB["avgErr"][i]=abs(EB["avg"][i] - EB["alt"][i])
    if( abs(EB["avg"][i] - EB["mcalt"][i]) > EB["avgErr"][i] ):  
        EB["avgErr"][i]=abs(EB["avg"][i] - EB["mcalt"][i])

    if( abs(EE["avg"][i] - EE["nom"][i]) > EE["avgErr"][i] ):  
        EE["avgErr"][i]=abs(EE["avg"][i] - EE["nom"][i])
    if( abs(EE["avg"][i] - EE["alt"][i]) > EE["avgErr"][i] ):  
        EE["avgErr"][i]=abs(EE["avg"][i] - EE["alt"][i])
    if( abs(EE["avg"][i] - EE["mcalt"][i]) > EE["avgErr"][i] ):  
        EE["avgErr"][i]=abs(EE["avg"][i] - EE["mcalt"][i])
    f.write(str(EB["avgErr"][i])+"    "+str(EE["avgErr"][i])+"\n")

print "x:",x
print "EB['nom']:",EB["nom"]
print "EB['nomErr']:",EB["nomErr"]
print "EB['mcalt']:",EB["mcalt"]
print "EB['mcaltErr']:",EB["mcaltErr"]
print "EB['alt']:",EB["alt"]
print "EB['altErr']:",EB["altErr"]

print "EE['nom']:",EE["nom"]
print "EE['nomErr']:",EE["nomErr"]
print "EE['mcalt']:",EE["mcalt"]
print "EE['mcaltErr']:",EE["mcaltErr"]
print "EE['alt']:",EE["alt"]
print "EE['altErr']:",EE["altErr"]

print "---------------------------------"
print "---------------------------------"
print "EB['avg']",EB["avg"]
print "EB['avgErr']",EB["avgErr"]
print "EE['avg']",EE["avg"]
print "EE['avgErr']",EE["avgErr"]

#f.write(str(EB["avg"])+"    "+str(EB["avgErr"])+"    "+str(EE["avg"])+"    "+str(EE["avgErr"])+ "\n")

gROOT.ProcessLine(".L ~/tdrstyle.C")
gROOT.ProcessLine("setTDRStyle()")

can = TCanvas("can","can",500,500)
can.SetTopMargin(0.08)

avgEB = TGraphErrors(len(x),array("f",x),array("f",EB["avg"]),array("f",xErr),array("f",EB["avgErr"]))
avgEB.SetMarkerStyle(8)
avgEB.GetXaxis().SetTitle("H_{T}^{miss} [GeV]")
avgEB.GetYaxis().SetRangeUser(.5,1.)
avgEB.GetYaxis().SetTitle("Photon Purity")

avgEE = TGraphErrors(len(x),array("f",x),array("f",EE["avg"]),array("f",xErr),array("f",EE["avgErr"]))
avgEE.SetMarkerStyle(4)

# - - - - - - - -
nomEB = TGraphErrors(len(x),array("f",x),array("f",EB["nom"]),array("f",xErr),array("f",EB["nomErr"]))
nomEB.SetMarkerStyle(8)
nomEB.GetXaxis().SetTitle("H_{T}^{miss} [GeV]")
nomEB.GetYaxis().SetRangeUser(.5,1.)
nomEB.GetYaxis().SetTitle("Photon Purity")

nomEE = TGraphErrors(len(x),array("f",x),array("f",EE["nom"]),array("f",xErr),array("f",EE["nomErr"]))
nomEE.SetMarkerStyle(4)

# - - - - - - - - 

altEB = TGraphErrors(len(x),array("f",x),array("f",EB["alt"]),array("f",xErr),array("f",EB["altErr"]))
altEB.SetMarkerStyle(8)
altEB.SetMarkerColor(2)
altEB.SetLineColor(2)
altEB.GetXaxis().SetTitle("H_{T}^{miss} [GeV]")
altEB.GetYaxis().SetRangeUser(.5,1.)
altEB.GetYaxis().SetTitle("Photon Purity")

altEE = TGraphErrors(len(x),array("f",x),array("f",EE["alt"]),array("f",xErr),array("f",EE["altErr"]))
altEE.SetMarkerStyle(4)
altEE.SetMarkerColor(2)
altEE.SetLineColor(2)

# - - - - - - - - 

mcaltEB = TGraphErrors(len(x),array("f",x),array("f",EB["mcalt"]),array("f",xErr),array("f",EB["mcaltErr"]))
mcaltEB.SetMarkerStyle(8)
mcaltEB.SetMarkerColor(4)
mcaltEB.SetLineColor(4)
mcaltEB.GetXaxis().SetTitle("H_{T}^{miss} [GeV]")
mcaltEB.GetYaxis().SetRangeUser(.5,1.)
mcaltEB.GetYaxis().SetTitle("Photon Purity")

mcaltEE = TGraphErrors(len(x),array("f",x),array("f",EE["mcalt"]),array("f",xErr),array("f",EE["mcaltErr"]))
mcaltEE.SetMarkerStyle(4)
mcaltEE.SetMarkerColor(4)
mcaltEE.SetLineColor(4)

# - - - - - - - - 

leg = TLegend(.2,.2,.5,.5)
leg.SetBorderSize(0)
leg.SetFillColor(0)
leg.AddEntry(nomEB,"EB","p")
leg.AddEntry(nomEE,"EE","p")
leg.AddEntry(altEB,"altEB","p")
leg.AddEntry(altEE,"altEE","p")
leg.AddEntry(mcaltEB,"mcaltEB","p")
leg.AddEntry(mcaltEE,"mcaltEE","p")

nomEB.Draw("Ap")
nomEE.Draw("p")
altEB.Draw("p")
altEE.Draw("p")
mcaltEB.Draw("p")
mcaltEE.Draw("p")
leg.Draw()

CMStext = TText(200,1.01,"CMS")
CMStext.SetTextFont(61)
CMStext.SetTextSize(0.045)
CMStext.Draw()

SIMtext = TText(285,1.01,"preliminary")
SIMtext.SetTextFont(52)
SIMtext.SetTextSize(0.045)
SIMtext.Draw()

LUMItext = TText(600,1.01,"13 TeV (35.9/fb)")
LUMItext.SetTextFont(51)
LUMItext.SetTextSize(0.045)
LUMItext.Draw()

can.SaveAs("../plots/purityResults/photonPurity_ALL_MHT.png")

# - - - - - - - - 
canAvg = TCanvas("canAvg","canAvg",500,500)
canAvg.SetTopMargin(0.08)

legAvg = TLegend(.2,.2,.5,.5)
legAvg.SetBorderSize(0)
legAvg.SetFillColor(0)
legAvg.AddEntry(nomEB,"EB","p")
legAvg.AddEntry(nomEE,"EE","p")

avgEB.Draw("Ap")
avgEE.Draw("p")
leg.Draw()

CMStext.Draw()
SIMtext.Draw()
LUMItext.Draw()

canAvg.SaveAs("../plots/purityResults/photonPurity_MHT.png")
