#include "TString.h"
#include "TChain.h"
#include "TH1F.h"
#include "TROOT.h"
#include "THStack.h"
#include "TPad.h"

#include <vector>
#include <map>
#include <iostream>

#include "plotterUtils.cc"
#include "skimSamples.cc"
#include "definitions.h"
#include "RA2bTree.cc"

using namespace std;

int main(int argc, char** argv){

    gROOT->ProcessLine(".L tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");

    int regInt = 2;
    skimSamples::region reg = static_cast<skimSamples::region>(regInt);
    skimSamples skims(reg);
    typedef plot<RA2bTree> plot;
  
    plot Binsplot(*fillRA2b174Bins<RA2bTree>,"AnalysisBins_"+skims.regionNames[regInt]+"_baseline","i^{th} Bin",174,0.5,174.5);
    plot BinsWithweightsplot(*fillRA2b174Bins<RA2bTree>,"AnalysisBins_"+skims.regionNames[regInt]+"_baseline_withWeights","i^{th} Bin",174,0.5,174.5);
    vector<plot> plotsAllEvents;
    plotsAllEvents.push_back(Binsplot);
    plotsAllEvents.push_back(BinsWithweightsplot);

    // Data samples
    RA2bTree* ntuple = skims.dataNtuple;
    for( int iPlot = 0 ; iPlot < plotsAllEvents.size() ; iPlot++){
        plotsAllEvents[iPlot].addDataNtuple(ntuple,"data");
    }
  
    int numEvents = ntuple->fChain->GetEntries();
    ntupleBranchStatus<RA2bTree>(ntuple);
    for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
        ntuple->GetEntry(iEvt);
        if( iEvt % 1000000 == 0 ) cout << "data: " << iEvt << "/" << numEvents << endl;

        if( ( reg == skimSamples::kSignal || reg == skimSamples::kPhoton || reg == skimSamples::kDYe || reg == skimSamples::kDYm ) && !RA2bBaselineCut(ntuple) ) continue;
        if( ( reg == skimSamples::kLDP || reg == skimSamples::kPhotonLDP || reg == skimSamples::kDYeLDP || reg == skimSamples::kDYmLDP ) && !RA2bLDPBaselineCut(ntuple) ) continue;    
        if( ( reg == skimSamples::kPhoton || reg == skimSamples::kPhotonLDP ) && ntuple->Photons->at(0).Pt()<200. ) continue;
        if( ntuple->TriggerPass->size() < 53 || !ntuple->TriggerPass->at(52) ) continue;

        plotsAllEvents[0].fillData(ntuple);
        plotsAllEvents[1].fillData(ntuple,1./photonTriggerWeight(ntuple));

    }
  
    TFile* outputFile = new TFile("photonNbExtrapolation.root","RECREATE");
    plotsAllEvents[0].Write();
    plotsAllEvents[1].Write();
    outputFile->Close();
    
}
