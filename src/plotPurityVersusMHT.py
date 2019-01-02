from ROOT import *
from array import array

#purity_fb6795fa13173ba165a794d7c5e9ee8e93864edd.log
inputs="""
REGION: EB MHT_250
purity in SR:  0.914067608018 +/- 0.00198545221579
purity in SR:  0.921886937174 +/- 0.00193310512635
purity in SR:  0.944951515741 +/- 0.00175325914801
--
REGION: EB MHT_300
purity in SR:  0.903155725061 +/- 0.00244800257653
purity in SR:  0.918787680731 +/- 0.00231201359405
purity in SR:  0.932138095539 +/- 0.00218108661442
--
REGION: EB MHT_350
purity in SR:  0.928855329305 +/- 0.00232084965121
purity in SR:  0.936630938394 +/- 0.00222728241393
purity in SR:  0.953084802293 +/- 0.00202854959705
--
REGION: EB MHT_500
purity in SR:  0.960179593818 +/- 0.00363574770227
purity in SR:  0.964551397052 +/- 0.00348515458057
purity in SR:  0.973742611485 +/- 0.00318668091321
--
REGION: EE MHT_250
purity in SR:  0.836018099894 +/- 0.00393513475475
purity in SR:  0.841421459516 +/- 0.00388710451785
purity in SR:  0.900451936434 +/- 0.00346608260322
--
REGION: EE MHT_300
purity in SR:  0.839817408879 +/- 0.00487775237725
purity in SR:  0.856289037819 +/- 0.00475804022266
purity in SR:  0.897756481146 +/- 0.00434502579303
--
REGION: EE MHT_350
purity in SR:  0.874058160456 +/- 0.00515390141592
purity in SR:  0.856333508003 +/- 0.00539821149326
purity in SR:  0.904406551892 +/- 0.00478317674579
--
REGION: EE MHT_500
purity in SR:  0.887527435083 +/- 0.0124866310344
purity in SR:  0.873066796967 +/- 0.0130534815689
purity in SR:  0.913841942954 +/- 0.0116508610323
"""

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

for i in range(len(EE["nom"])):
    EB["avg"].append((EB["nom"][i]+EB["mcalt"][i]+EB["alt"][i])/3.)
    EE["avg"].append((EE["nom"][i]+EE["mcalt"][i]+EE["alt"][i])/3.)

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

can.SaveAs("../plots/purityResults/photonPurity_ALL_MHT.pdf")
can.SaveAs("../plots/purityResults/photonPurity_ALL_MHT.png")
can.SaveAs("../plots/purityResults/photonPurity_ALL_MHT.eps")

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

canAvg.SaveAs("../plots/purityResults/photonPurity_MHT.pdf")
canAvg.SaveAs("../plots/purityResults/photonPurity_MHT.png")
canAvg.SaveAs("../plots/purityResults/photonPurity_MHT.eps")
