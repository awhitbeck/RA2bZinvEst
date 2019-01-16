from ROOT import *
from array import array

inputs="""REGION: EB MHT_250
purity in SR:  0.973466096551 +/- 0.00162928782857
ALT purity in SR:  0.964239661421 +/- 0.00181237348774
MCALT purity in SR:  0.974027537126 +/- 0.00140917965426
--
REGION: EB MHT_300
purity in SR:  0.975509602818 +/- 0.00185361836017
ALT purity in SR:  0.954404697291 +/- 0.00241514144864
MCALT purity in SR:  0.969454094809 +/- 0.0016662321643
--
REGION: EB MHT_350
purity in SR:  0.981757748422 +/- 0.00174085375809
ALT purity in SR:  0.920524138301 +/- 0.0039385077422
MCALT purity in SR:  0.970036307774 +/- 0.00148638631716
--
REGION: EB MHT_500
purity in SR:  0.993224600585 +/- 0.00242050870638
ALT purity in SR:  0.882406918084 +/- 0.0172345202464
MCALT purity in SR:  0.98795565185 +/- 0.0021080832843
--
REGION: EE MHT_250
purity in SR:  0.88688631074 +/- 0.00394922194656
ALT purity in SR:  0.851776737779 +/- 0.00434835846051
MCALT purity in SR:  0.882042751545 +/- 0.00354908672516
--
REGION: EE MHT_300
purity in SR:  0.901156139894 +/- 0.00473781820932
ALT purity in SR:  0.861975494219 +/- 0.00529643063127
MCALT purity in SR:  0.888270558499 +/- 0.00436244361582
--
REGION: EE MHT_350
purity in SR:  0.933326559899 +/- 0.00473578878866
ALT purity in SR:  0.885993356208 +/- 0.00567414277755
MCALT purity in SR:  0.912317918029 +/- 0.00434135861779
--
REGION: EE MHT_500
purity in SR:  0.968586799591 +/- 0.00932934653271
ALT purity in SR:  0.882556239686 +/- 0.0158512855099
MCALT purity in SR:  0.942058620977 +/- 0.00787214238654
"""

x=[275,325,425,650]
xErr=[25,25,75,150]
EB={"nom":[0.973,0.976,0.982,0.993],"alt":[0.964,0.954,0.921,0.882],"mcalt":[0.974,0.969,0.970,0.988],"nomErr":[0.0016,0.0019,0.0017,0.0024],"altErr":[0.0018,0.0024,0.0039,0.017],"mcaltErr":[0.0014,0.0017,0.0014,0.0021]}
EE={"nom":[0.887,0.901,0.933,0.969],"alt":[0.852,0.862,0.886,0.883],"mcalt":[0.882,0.888,0.912,0.942],"nomErr":[0.0039,0.0047,0.0047,0.0093],"altErr":[0.0043,0.0053,0.0057,0.016],"mcaltErr":[0.0035,0.0044,0.0043,0.0079]}


gROOT.ProcessLine(".L ~/tdrstyle.C")
gROOT.ProcessLine("setTDRStyle()")

can = TCanvas("can","can",500,500)
can.SetTopMargin(0.08)

nomEB = TGraphErrors(len(x),array("f",x),array("f",EB["nom"]),array("f",xErr),array("f",EB["nomErr"]))
nomEB.SetMarkerStyle(8)
nomEB.GetXaxis().SetTitle("H_{T}^{miss} [GeV]")
nomEB.GetYaxis().SetRangeUser(.5,1.)
nomEB.GetYaxis().SetTitle("Photon Purity")

nomEE = TGraphErrors(len(x),array("f",x),array("f",EE["nom"]),array("f",xErr),array("f",EE["nomErr"]))
nomEE.SetMarkerStyle(4)

altEB = TGraphErrors(len(x),array("f",x),array("f",EB["alt"]),array("f",xErr),array("f",EB["altErr"]))
altEB.SetMarkerStyle(8)
altEB.SetMarkerColor(2)
altEB.SetLineColor(2)

altEE = TGraphErrors(len(x),array("f",x),array("f",EE["alt"]),array("f",xErr),array("f",EE["altErr"]))
altEE.SetMarkerStyle(4)
altEE.SetMarkerColor(2)
altEE.SetLineColor(2)

mcaltEB = TGraphErrors(len(x),array("f",x),array("f",EB["mcalt"]),array("f",xErr),array("f",EB["mcaltErr"]))
mcaltEB.SetMarkerStyle(8)
mcaltEB.SetMarkerColor(4)
mcaltEB.SetLineColor(4)

mcaltEE = TGraphErrors(len(x),array("f",x),array("f",EE["mcalt"]),array("f",xErr),array("f",EE["mcaltErr"]))
mcaltEE.SetMarkerStyle(4)
mcaltEE.SetMarkerColor(4)
mcaltEE.SetLineColor(4)

leg = TLegend(.2,.2,.5,.5)
leg.SetBorderSize(0)
leg.SetFillColor(0)
leg.AddEntry(nomEB,"nominal (EB)","p")
leg.AddEntry(nomEE,"nominal (EE)","p")
leg.AddEntry(altEB,"data SB (EB)","p")
leg.AddEntry(altEE,"data SB (EE)","p")
leg.AddEntry(mcaltEB,"MC SB (EB)","p")
leg.AddEntry(mcaltEE,"MC SB (EE)","p")

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

SIMtext = TText(285,1.01,"simulation")
SIMtext.SetTextFont(52)
SIMtext.SetTextSize(0.045)
SIMtext.Draw()

LUMItext = TText(600,1.01,"13 TeV (24.5/fb)")
LUMItext.SetTextFont(51)
LUMItext.SetTextSize(0.045)
LUMItext.Draw()

can.SaveAs("photonPurity_ALL_MHT.pdf")
can.SaveAs("photonPurity_ALL_MHT.png")
can.SaveAs("photonPurity_ALL_MHT.eps")
