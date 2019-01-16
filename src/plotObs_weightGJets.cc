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

static const int MAX_EVENTS=999999999;

int main(int argc, char** argv){

    gROOT->ProcessLine(".L tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");

    if(argc != 2 ) return 1;
  
    int regInt = atoi(argv[1]);
    skimSamples::region reg = static_cast<skimSamples::region>(regInt);
    skimSamples skims(reg);
    typedef plot<RA2bTree> plot;
    cout << skims.skimType << endl;
    for( int i = 0 ; i < skims.ntuples.size() ; i++){
        cout << "sample name: " << skims.sampleName[i] << endl;
    }
  
    plot MHTplotUn(*fillMHT<RA2bTree>,"MHT_uncorr_"+skims.regionNames[regInt]+"_baseline","MHT [GeV]",64,200.,1800.);
    plot HTplotUn(*fillHT<RA2bTree>,"HT_uncorr_"+skims.regionNames[regInt]+"_baseline","H_{T} [GeV]",50,300,2800.);
    plot NJetsplotUn(*fillNJets<RA2bTree>,"NJets_uncorr_"+skims.regionNames[regInt]+"_baseline","n_{j}",14,1.5,15.5);
    plot PhotonPtplotUn(*photonPt<RA2bTree>,"PhotonPt_uncorr_"+skims.regionNames[regInt]+"_baseline","p_{T,#gamma} [GeV]",50,0,1000);

    plot MHTplot(*fillMHT<RA2bTree>,"MHT_"+skims.regionNames[regInt]+"_baseline","MHT [GeV]",64,200.,1800.);
    plot HTplot(*fillHT<RA2bTree>,"HT_"+skims.regionNames[regInt]+"_baseline","H_{T} [GeV]",50,300,2800.);
    plot NJetsplot(*fillNJets<RA2bTree>,"NJets_"+skims.regionNames[regInt]+"_baseline","n_{j}",14,1.5,15.5);
    plot PhotonPtplot(*photonPt<RA2bTree>,"PhotonPt_"+skims.regionNames[regInt]+"_baseline","p_{T,#gamma} [GeV]",50,0,1000);

    plot MHTplot_lowNj(*fillMHT<RA2bTree>,"MHT_lowNj_"+skims.regionNames[regInt]+"_baseline","MHT [GeV]",64,200.,1800.);
    plot HTplot_lowNj(*fillHT<RA2bTree>,"HT_lowNj_"+skims.regionNames[regInt]+"_baseline","H_{T} [GeV]",50,300,2800.);
    plot NJetsplot_lowNj(*fillNJets<RA2bTree>,"NJets_lowNj_"+skims.regionNames[regInt]+"_baseline","n_{j}",14,1.5,15.5);
    plot PhotonPtplot_lowNj(*photonPt<RA2bTree>,"PhotonPt_lowNj_"+skims.regionNames[regInt]+"_baseline","p_{T,#gamma} [GeV]",50,0,1000);

    plot MHTplot_medNj(*fillMHT<RA2bTree>,"MHT_medNj_"+skims.regionNames[regInt]+"_baseline","MHT [GeV]",64,200.,1800.);
    plot HTplot_medNj(*fillHT<RA2bTree>,"HT_medNj_"+skims.regionNames[regInt]+"_baseline","H_{T} [GeV]",50,300,2800.);
    plot NJetsplot_medNj(*fillNJets<RA2bTree>,"NJets_medNj_"+skims.regionNames[regInt]+"_baseline","n_{j}",14,1.5,15.5);
    plot PhotonPtplot_medNj(*photonPt<RA2bTree>,"PhotonPt_medNj_"+skims.regionNames[regInt]+"_baseline","p_{T,#gamma} [GeV]",50,0,1000);

    plot MHTplot_highNj(*fillMHT<RA2bTree>,"MHT_highNj_"+skims.regionNames[regInt]+"_baseline","MHT [GeV]",64,200.,1800.);
    plot HTplot_highNj(*fillHT<RA2bTree>,"HT_highNj_"+skims.regionNames[regInt]+"_baseline","H_{T} [GeV]",50,300,2800.);
    plot NJetsplot_highNj(*fillNJets<RA2bTree>,"NJets_highNj_"+skims.regionNames[regInt]+"_baseline","n_{j}",14,1.5,15.5);
    plot PhotonPtplot_highNj(*photonPt<RA2bTree>,"PhotonPt_highNj_"+skims.regionNames[regInt]+"_baseline","p_{T,#gamma} [GeV]",50,0,1000);

    vector<plot> plotsAllEventsUn;
    plotsAllEventsUn.push_back(MHTplotUn);
    plotsAllEventsUn.push_back(HTplotUn);
    plotsAllEventsUn.push_back(NJetsplotUn);
    plotsAllEventsUn.push_back(PhotonPtplotUn);

    vector<plot> plotsAllEvents;
    plotsAllEvents.push_back(MHTplot);
    plotsAllEvents.push_back(HTplot);
    plotsAllEvents.push_back(NJetsplot);
    plotsAllEvents.push_back(PhotonPtplot);

    vector<plot> plotsLowNjEvents;
    plotsLowNjEvents.push_back(MHTplot_lowNj);
    plotsLowNjEvents.push_back(HTplot_lowNj);
    plotsLowNjEvents.push_back(NJetsplot_lowNj);
    plotsLowNjEvents.push_back(PhotonPtplot_lowNj);

    vector<plot> plotsMedNjEvents;
    plotsMedNjEvents.push_back(MHTplot_medNj);
    plotsMedNjEvents.push_back(HTplot_medNj);
    plotsMedNjEvents.push_back(NJetsplot_medNj);
    plotsMedNjEvents.push_back(PhotonPtplot_medNj);

    vector<plot> plotsHighNjEvents;
    plotsHighNjEvents.push_back(MHTplot_highNj);
    plotsHighNjEvents.push_back(HTplot_highNj);
    plotsHighNjEvents.push_back(NJetsplot_highNj);
    plotsHighNjEvents.push_back(PhotonPtplot_highNj);

    // up 
    plot MHTplotUP(*fillMHT<RA2bTree>,"MHT_up_"+skims.regionNames[regInt]+"_baseline","MHT [GeV]",64,200.,1800.);
    plot HTplotUP(*fillHT<RA2bTree>,"HT_up_"+skims.regionNames[regInt]+"_baseline","H_{T} [GeV]",50,300,2800.);
    plot NJetsplotUP(*fillNJets<RA2bTree>,"NJets_up_"+skims.regionNames[regInt]+"_baseline","n_{j}",14,1.5,15.5);
    plot PhotonPtplotUP(*photonPt<RA2bTree>,"PhotonPt_up_"+skims.regionNames[regInt]+"_baseline","p_{T,#gamma} [GeV]",50,0,1000);

    plot MHTplot_lowNjUP(*fillMHT<RA2bTree>,"MHT_lowNj_up_"+skims.regionNames[regInt]+"_baseline","MHT [GeV]",64,200.,1800.);
    plot HTplot_lowNjUP(*fillHT<RA2bTree>,"HT_lowNj_up_"+skims.regionNames[regInt]+"_baseline","H_{T} [GeV]",50,300,2800.);
    plot NJetsplot_lowNjUP(*fillNJets<RA2bTree>,"NJets_lowNj_up_"+skims.regionNames[regInt]+"_baseline","n_{j}",14,1.5,15.5);
    plot PhotonPtplot_lowNjUP(*photonPt<RA2bTree>,"PhotonPt_lowNj_up_"+skims.regionNames[regInt]+"_baseline","p_{T,#gamma} [GeV]",50,0,1000);

    plot MHTplot_medNjUP(*fillMHT<RA2bTree>,"MHT_medNj_up_"+skims.regionNames[regInt]+"_baseline","MHT [GeV]",64,200.,1800.);
    plot HTplot_medNjUP(*fillHT<RA2bTree>,"HT_medNj_up_"+skims.regionNames[regInt]+"_baseline","H_{T} [GeV]",50,300,2800.);
    plot NJetsplot_medNjUP(*fillNJets<RA2bTree>,"NJets_medNj_up_"+skims.regionNames[regInt]+"_baseline","n_{j}",14,1.5,15.5);
    plot PhotonPtplot_medNjUP(*photonPt<RA2bTree>,"PhotonPt_medNj_up_"+skims.regionNames[regInt]+"_baseline","p_{T,#gamma} [GeV]",50,0,1000);

    plot MHTplot_highNjUP(*fillMHT<RA2bTree>,"MHT_highNj_up_"+skims.regionNames[regInt]+"_baseline","MHT [GeV]",64,200.,1800.);
    plot HTplot_highNjUP(*fillHT<RA2bTree>,"HT_highNj_up_"+skims.regionNames[regInt]+"_baseline","H_{T} [GeV]",50,300,2800.);
    plot NJetsplot_highNjUP(*fillNJets<RA2bTree>,"NJets_highNj_up_"+skims.regionNames[regInt]+"_baseline","n_{j}",14,1.5,15.5);
    plot PhotonPtplot_highNjUP(*photonPt<RA2bTree>,"PhotonPt_highNj_up_"+skims.regionNames[regInt]+"_baseline","p_{T,#gamma} [GeV]",50,0,1000);

    vector<plot> plotsAllUPEvents;
    plotsAllUPEvents.push_back(MHTplotUP);
    plotsAllUPEvents.push_back(HTplotUP);
    plotsAllUPEvents.push_back(NJetsplotUP);
    plotsAllUPEvents.push_back(PhotonPtplotUP);

    vector<plot> plotsLowNjUPEvents;
    plotsLowNjUPEvents.push_back(MHTplot_lowNjUP);
    plotsLowNjUPEvents.push_back(HTplot_lowNjUP);
    plotsLowNjUPEvents.push_back(NJetsplot_lowNjUP);
    plotsLowNjUPEvents.push_back(PhotonPtplot_lowNjUP);

    vector<plot> plotsMedNjUPEvents;
    plotsMedNjUPEvents.push_back(MHTplot_medNjUP);
    plotsMedNjUPEvents.push_back(HTplot_medNjUP);
    plotsMedNjUPEvents.push_back(NJetsplot_medNjUP);
    plotsMedNjUPEvents.push_back(PhotonPtplot_medNjUP);

    vector<plot> plotsHighNjUPEvents;
    plotsHighNjUPEvents.push_back(MHTplot_highNjUP);
    plotsHighNjUPEvents.push_back(HTplot_highNjUP);
    plotsHighNjUPEvents.push_back(NJetsplot_highNjUP);
    plotsHighNjUPEvents.push_back(PhotonPtplot_highNjUP);

    // down 
    plot MHTplotDOWN(*fillMHT<RA2bTree>,"MHT_down_"+skims.regionNames[regInt]+"_baseline","MHT [GeV]",64,200.,1800.);
    plot HTplotDOWN(*fillHT<RA2bTree>,"HT_down_"+skims.regionNames[regInt]+"_baseline","H_{T} [GeV]",50,300,2800.);
    plot NJetsplotDOWN(*fillNJets<RA2bTree>,"NJets_down_"+skims.regionNames[regInt]+"_baseline","n_{j}",14,1.5,15.5);
    plot PhotonPtplotDOWN(*photonPt<RA2bTree>,"PhotonPt_down_"+skims.regionNames[regInt]+"_baseline","p_{T,#gamma} [GeV]",50,0,1000);

    plot MHTplot_lowNjDOWN(*fillMHT<RA2bTree>,"MHT_lowNj_down_"+skims.regionNames[regInt]+"_baseline","MHT [GeV]",64,200.,1800.);
    plot HTplot_lowNjDOWN(*fillHT<RA2bTree>,"HT_lowNj_down_"+skims.regionNames[regInt]+"_baseline","H_{T} [GeV]",50,300,2800.);
    plot NJetsplot_lowNjDOWN(*fillNJets<RA2bTree>,"NJets_lowNj_down_"+skims.regionNames[regInt]+"_baseline","n_{j}",14,1.5,15.5);
    plot PhotonPtplot_lowNjDOWN(*photonPt<RA2bTree>,"PhotonPt_lowNj_down_"+skims.regionNames[regInt]+"_baseline","p_{T,#gamma} [GeV]",50,0,1000);

    plot MHTplot_medNjDOWN(*fillMHT<RA2bTree>,"MHT_medNj_down_"+skims.regionNames[regInt]+"_baseline","MHT [GeV]",64,200.,1800.);
    plot HTplot_medNjDOWN(*fillHT<RA2bTree>,"HT_medNj_down_"+skims.regionNames[regInt]+"_baseline","H_{T} [GeV]",50,300,2800.);
    plot NJetsplot_medNjDOWN(*fillNJets<RA2bTree>,"NJets_medNj_down_"+skims.regionNames[regInt]+"_baseline","n_{j}",14,1.5,15.5);
    plot PhotonPtplot_medNjDOWN(*photonPt<RA2bTree>,"PhotonPt_medNj_down_"+skims.regionNames[regInt]+"_baseline","p_{T,#gamma} [GeV]",50,0,1000);

    plot MHTplot_highNjDOWN(*fillMHT<RA2bTree>,"MHT_highNj_down_"+skims.regionNames[regInt]+"_baseline","MHT [GeV]",64,200.,1800.);
    plot HTplot_highNjDOWN(*fillHT<RA2bTree>,"HT_highNj_down_"+skims.regionNames[regInt]+"_baseline","H_{T} [GeV]",50,300,2800.);
    plot NJetsplot_highNjDOWN(*fillNJets<RA2bTree>,"NJets_highNj_down_"+skims.regionNames[regInt]+"_baseline","n_{j}",14,1.5,15.5);
    plot PhotonPtplot_highNjDOWN(*photonPt<RA2bTree>,"PhotonPt_highNj_down_"+skims.regionNames[regInt]+"_baseline","p_{T,#gamma} [GeV]",50,0,1000);

    vector<plot> plotsAllDOWNEvents;
    plotsAllDOWNEvents.push_back(MHTplotDOWN);
    plotsAllDOWNEvents.push_back(HTplotDOWN);
    plotsAllDOWNEvents.push_back(NJetsplotDOWN);
    plotsAllDOWNEvents.push_back(PhotonPtplotDOWN);

    vector<plot> plotsLowNjDOWNEvents;
    plotsLowNjDOWNEvents.push_back(MHTplot_lowNjDOWN);
    plotsLowNjDOWNEvents.push_back(HTplot_lowNjDOWN);
    plotsLowNjDOWNEvents.push_back(NJetsplot_lowNjDOWN);
    plotsLowNjDOWNEvents.push_back(PhotonPtplot_lowNjDOWN);

    vector<plot> plotsMedNjDOWNEvents;
    plotsMedNjDOWNEvents.push_back(MHTplot_medNjDOWN);
    plotsMedNjDOWNEvents.push_back(HTplot_medNjDOWN);
    plotsMedNjDOWNEvents.push_back(NJetsplot_medNjDOWN);
    plotsMedNjDOWNEvents.push_back(PhotonPtplot_medNjDOWN);

    vector<plot> plotsHighNjDOWNEvents;
    plotsHighNjDOWNEvents.push_back(MHTplot_highNjDOWN);
    plotsHighNjDOWNEvents.push_back(HTplot_highNjDOWN);
    plotsHighNjDOWNEvents.push_back(NJetsplot_highNjDOWN);
    plotsHighNjDOWNEvents.push_back(PhotonPtplot_highNjDOWN);

    // background MC samples
    for( int iSample = 0 ; iSample < skims.ntuples.size() ; iSample++){

        RA2bTree* ntuple = skims.ntuples[iSample];

        for( int iPlot = 0 ; iPlot < plotsAllEvents.size() ; iPlot++){
            plotsAllEvents[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
            plotsAllEvents[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
        }
        for( int iPlot = 0 ; iPlot < plotsAllEventsUn.size() ; iPlot++){
            plotsAllEventsUn[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
            plotsAllEventsUn[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
        }
        for( int iPlot = 0 ; iPlot < plotsLowNjEvents.size() ; iPlot++){
            plotsLowNjEvents[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
            plotsLowNjEvents[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
        }
        for( int iPlot = 0 ; iPlot < plotsMedNjEvents.size() ; iPlot++){
            plotsMedNjEvents[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
            plotsMedNjEvents[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
        }
        for( int iPlot = 0 ; iPlot < plotsHighNjEvents.size() ; iPlot++){
            plotsHighNjEvents[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
            plotsHighNjEvents[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
        }
        // up
        for( int iPlot = 0 ; iPlot < plotsAllUPEvents.size() ; iPlot++){
            plotsAllUPEvents[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
            plotsAllUPEvents[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
        }
        for( int iPlot = 0 ; iPlot < plotsLowNjUPEvents.size() ; iPlot++){
            plotsLowNjUPEvents[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
            plotsLowNjUPEvents[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
        }
        for( int iPlot = 0 ; iPlot < plotsMedNjUPEvents.size() ; iPlot++){
            plotsMedNjUPEvents[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
            plotsMedNjUPEvents[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
        }
        for( int iPlot = 0 ; iPlot < plotsHighNjUPEvents.size() ; iPlot++){
            plotsHighNjUPEvents[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
            plotsHighNjUPEvents[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
        }
        // down
        for( int iPlot = 0 ; iPlot < plotsAllDOWNEvents.size() ; iPlot++){
            plotsAllDOWNEvents[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
            plotsAllDOWNEvents[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
        }
        for( int iPlot = 0 ; iPlot < plotsLowNjDOWNEvents.size() ; iPlot++){
            plotsLowNjDOWNEvents[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
            plotsLowNjDOWNEvents[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
        }
        for( int iPlot = 0 ; iPlot < plotsMedNjDOWNEvents.size() ; iPlot++){
            plotsMedNjDOWNEvents[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
            plotsMedNjDOWNEvents[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
        }
        for( int iPlot = 0 ; iPlot < plotsHighNjDOWNEvents.size() ; iPlot++){
            plotsHighNjDOWNEvents[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
            plotsHighNjDOWNEvents[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
        }

        int numEvents = ntuple->fChain->GetEntries();
        ntupleBranchStatus<RA2bTree>(ntuple);
        double weight = 1.0;
        double weightun = 1.0;
        double weightup = 1.0;
        double weightdn = 1.0;
        for( int iEvt = 0 ; iEvt < min(MAX_EVENTS,numEvents) ; iEvt++ ){

            //cout << "sample: " << skims.sampleName[iSample] << endl;
            ntuple->GetEntry(iEvt);
            if( iEvt % 1000000 == 0 ) cout << skims.sampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;

            if( ( reg == skimSamples::kSignal || reg == skimSamples::kPhoton || reg == skimSamples::kDYe || reg == skimSamples::kDYm ) && !RA2bBaselineCut(ntuple) ) continue;
            if( ( reg == skimSamples::kLDP || reg == skimSamples::kPhotonLDP || reg == skimSamples::kDYeLDP || reg == skimSamples::kDYmLDP ) && !RA2bLDPBaselineCut(ntuple) ) continue;

            if( skims.regionNames[regInt] == "photonLDP" || skims.regionNames[regInt] == "photon" ){
                if( skims.sampleName[iSample] == "QCD" && isPromptPhoton(ntuple) ) continue;
                if( skims.sampleName[iSample] == "GJets" && ( !isPromptPhoton(ntuple) || ntuple->madMinPhotonDeltaR < 0.4 ) ) continue;
                if( ntuple->Photons->size() != 1 ) continue;
                if( ntuple->Photons->at(0).Pt() < 200. ) continue;
            }
 
            for( int iPlot = 0 ; iPlot < plotsAllEvents.size() ; iPlot++ ){
                weight = lumi*ntuple->Weight*photonTriggerWeight(ntuple)*customPUweights(ntuple)*NLOw.get(ntuple->Photons->at(0).Pt(),kNLO)/NLOw.get(ntuple->Photons->at(0).Pt(),kLO);
                weightun = lumi*ntuple->Weight*photonTriggerWeight(ntuple)*customPUweights(ntuple);
                weightup = lumi*ntuple->Weight*photonTriggerWeight(ntuple)*customPUweights(ntuple)*NLOw.get(ntuple->Photons->at(0).Pt(),kUpVar)/NLOw.get(ntuple->Photons->at(0).Pt(),kLO);
                weightdn = lumi*ntuple->Weight*photonTriggerWeight(ntuple)*customPUweights(ntuple)*NLOw.get(ntuple->Photons->at(0).Pt(),kDnVar)/NLOw.get(ntuple->Photons->at(0).Pt(),kLO);
                if( reg == skimSamples::kPhoton || reg == skimSamples::kPhotonLDP ) 
                    weight *= photonTriggerWeight(ntuple);
                if( skims.sampleName[iSample] == "GJets" ){
                    //cout << "before: " << weight << endl;
                    weight *= GJets0p4Weights(ntuple);
                    //cout << "after: " << weight << endl;                    
                }
                plotsAllEvents[iPlot].fill(ntuple,weight);
                plotsAllEventsUn[iPlot].fill(ntuple,weightun);
                plotsAllUPEvents[iPlot].fill(ntuple,weightup);
                plotsAllDOWNEvents[iPlot].fill(ntuple,weightdn);
                if( ntuple->NJets >= 2 && ntuple->NJets <= 3 ){  
                    plotsLowNjEvents[iPlot].fill(ntuple,weight);
                    plotsLowNjUPEvents[iPlot].fill(ntuple,weightup);
                    plotsLowNjDOWNEvents[iPlot].fill(ntuple,weightdn);
                }else if( ntuple->NJets >=4 && ntuple->NJets <= 6 ){ 
                    plotsMedNjEvents[iPlot].fill(ntuple,weight);
                    plotsMedNjUPEvents[iPlot].fill(ntuple,weightup);
                    plotsMedNjDOWNEvents[iPlot].fill(ntuple,weightdn);
                }else if( ntuple->NJets >= 7 ){ 
                    plotsHighNjEvents[iPlot].fill(ntuple,weight);
                    plotsHighNjUPEvents[iPlot].fill(ntuple,weightup);
                    plotsHighNjDOWNEvents[iPlot].fill(ntuple,weightdn);
                }
            }
        }
    }

    // Data samples
    RA2bTree* ntuple = skims.dataNtuple;
    for( int iPlot = 0 ; iPlot < plotsAllEvents.size() ; iPlot++){
        plotsAllEvents[iPlot].addDataNtuple(ntuple,"data");
        plotsAllEventsUn[iPlot].addDataNtuple(ntuple,"data");
        plotsAllUPEvents[iPlot].addDataNtuple(ntuple,"data");
        plotsAllDOWNEvents[iPlot].addDataNtuple(ntuple,"data");
        plotsLowNjEvents[iPlot].addDataNtuple(ntuple,"data");
        plotsLowNjUPEvents[iPlot].addDataNtuple(ntuple,"data");
        plotsLowNjDOWNEvents[iPlot].addDataNtuple(ntuple,"data");
        plotsMedNjEvents[iPlot].addDataNtuple(ntuple,"data");
        plotsMedNjUPEvents[iPlot].addDataNtuple(ntuple,"data");
        plotsMedNjDOWNEvents[iPlot].addDataNtuple(ntuple,"data");
        plotsHighNjEvents[iPlot].addDataNtuple(ntuple,"data");
        plotsHighNjUPEvents[iPlot].addDataNtuple(ntuple,"data");
        plotsHighNjDOWNEvents[iPlot].addDataNtuple(ntuple,"data");
    }
  
    int numEvents = ntuple->fChain->GetEntries();
    ntupleBranchStatus<RA2bTree>(ntuple);
    for( int iEvt = 0 ; iEvt < min(MAX_EVENTS,numEvents) ; iEvt++ ){
        ntuple->GetEntry(iEvt);
        if( iEvt % 1000000 == 0 ) cout << "data: " << iEvt << "/" << numEvents << endl;

        if( ( reg == skimSamples::kSignal || reg == skimSamples::kPhoton || reg == skimSamples::kDYe || reg == skimSamples::kDYm ) && !RA2bBaselineCut(ntuple) ) continue;
        if( ( reg == skimSamples::kLDP || reg == skimSamples::kPhotonLDP || reg == skimSamples::kDYeLDP || reg == skimSamples::kDYmLDP ) && !RA2bLDPBaselineCut(ntuple) ) continue;
    
        if( ( reg == skimSamples::kPhoton || reg == skimSamples::kPhotonLDP ) && ntuple->Photons->at(0).Pt()<200. ) continue;

        if( ntuple->TriggerPass->size() < 53 || !ntuple->TriggerPass->at(52) ) continue;

        for( int iPlot = 0 ; iPlot < plotsAllEvents.size() ; iPlot++){
            plotsAllEvents[iPlot].fillData(ntuple);
            plotsAllEventsUn[iPlot].fillData(ntuple);
            plotsAllUPEvents[iPlot].fillData(ntuple);
            plotsAllDOWNEvents[iPlot].fillData(ntuple);
            if( ntuple->NJets >= 2 && ntuple->NJets <= 3 ){  
                plotsLowNjEvents[iPlot].fillData(ntuple);
                plotsLowNjUPEvents[iPlot].fillData(ntuple);
                plotsLowNjDOWNEvents[iPlot].fillData(ntuple);
            }else if( ntuple->NJets >=4 && ntuple->NJets <= 6 ){ 
                plotsMedNjEvents[iPlot].fillData(ntuple);
                plotsMedNjUPEvents[iPlot].fillData(ntuple);
                plotsMedNjDOWNEvents[iPlot].fillData(ntuple);
            }else if( ntuple->NJets >= 7 ){ 
                plotsHighNjEvents[iPlot].fillData(ntuple);
                plotsHighNjUPEvents[iPlot].fillData(ntuple);
                plotsHighNjDOWNEvents[iPlot].fillData(ntuple);
            }
        }
    }

    TFile* outputFile = new TFile("plotObs_weightGJets_"+skims.regionNames[regInt]+"_baseline.root","UPDATE");

    for( int iPlot = 0 ; iPlot < plotsAllEvents.size() ; iPlot++){
        TCanvas* can = new TCanvas("can","can",500,500);
        can->SetTopMargin(0.05);
        plotsAllEvents[iPlot].Write();
        plotsAllEvents[iPlot].Draw(can,skims.ntuples,skims.signalNtuples,"../plots/plotObs_weightGJets_plots");
    }
    for( int iPlot = 0 ; iPlot < plotsAllEventsUn.size() ; iPlot++){
        TCanvas* can = new TCanvas("can","can",500,500);
        can->SetTopMargin(0.05);
        plotsAllEventsUn[iPlot].Write();
        plotsAllEventsUn[iPlot].Draw(can,skims.ntuples,skims.signalNtuples,"../plots/plotObs_weightGJets_plots");
    }
    for( int iPlot = 0 ; iPlot < plotsLowNjEvents.size() ; iPlot++){
        TCanvas* can = new TCanvas("can","can",500,500);
        can->SetTopMargin(0.05);
        plotsLowNjEvents[iPlot].Write();
        plotsLowNjEvents[iPlot].Draw(can,skims.ntuples,skims.signalNtuples,"../plots/plotObs_weightGJets_plots");
    }
    for( int iPlot = 0 ; iPlot < plotsMedNjEvents.size() ; iPlot++){
        TCanvas* can = new TCanvas("can","can",500,500);
        can->SetTopMargin(0.05);
        plotsMedNjEvents[iPlot].Write();
        plotsMedNjEvents[iPlot].Draw(can,skims.ntuples,skims.signalNtuples,"../plots/plotObs_weightGJets_plots");
    }
    for( int iPlot = 0 ; iPlot < plotsHighNjEvents.size() ; iPlot++){
        TCanvas* can = new TCanvas("can","can",500,500);
        can->SetTopMargin(0.05);
        plotsHighNjEvents[iPlot].Write();
        plotsHighNjEvents[iPlot].Draw(can,skims.ntuples,skims.signalNtuples,"../plots/plotObs_weightGJets_plots");
    }

    // up 
    for( int iPlot = 0 ; iPlot < plotsAllUPEvents.size() ; iPlot++){
        TCanvas* can = new TCanvas("can","can",500,500);
        can->SetTopMargin(0.05);
        plotsAllUPEvents[iPlot].Write();
        plotsAllUPEvents[iPlot].Draw(can,skims.ntuples,skims.signalNtuples,"../plots/plotObs_weightGJets_plots");
    }
    for( int iPlot = 0 ; iPlot < plotsLowNjUPEvents.size() ; iPlot++){
        TCanvas* can = new TCanvas("can","can",500,500);
        can->SetTopMargin(0.05);
        plotsLowNjUPEvents[iPlot].Write();
        plotsLowNjUPEvents[iPlot].Draw(can,skims.ntuples,skims.signalNtuples,"../plots/plotObs_weightGJets_plots");
    }
    for( int iPlot = 0 ; iPlot < plotsMedNjUPEvents.size() ; iPlot++){
        TCanvas* can = new TCanvas("can","can",500,500);
        can->SetTopMargin(0.05);
        plotsMedNjUPEvents[iPlot].Write();
        plotsMedNjUPEvents[iPlot].Draw(can,skims.ntuples,skims.signalNtuples,"../plots/plotObs_weightGJets_plots");
    }
    for( int iPlot = 0 ; iPlot < plotsHighNjUPEvents.size() ; iPlot++){
        TCanvas* can = new TCanvas("can","can",500,500);
        can->SetTopMargin(0.05);
        plotsHighNjUPEvents[iPlot].Write();
        plotsHighNjUPEvents[iPlot].Draw(can,skims.ntuples,skims.signalNtuples,"../plots/plotObs_weightGJets_plots");
    }

    // down
    for( int iPlot = 0 ; iPlot < plotsAllDOWNEvents.size() ; iPlot++){
        TCanvas* can = new TCanvas("can","can",500,500);
        can->SetTopMargin(0.05);
        plotsAllDOWNEvents[iPlot].Write();
        plotsAllDOWNEvents[iPlot].Draw(can,skims.ntuples,skims.signalNtuples,"../plots/plotObs_weightGJets_plots");
    }
    for( int iPlot = 0 ; iPlot < plotsLowNjDOWNEvents.size() ; iPlot++){
        TCanvas* can = new TCanvas("can","can",500,500);
        can->SetTopMargin(0.05);
        plotsLowNjDOWNEvents[iPlot].Write();
        plotsLowNjDOWNEvents[iPlot].Draw(can,skims.ntuples,skims.signalNtuples,"../plots/plotObs_weightGJets_plots");
    }
    for( int iPlot = 0 ; iPlot < plotsMedNjDOWNEvents.size() ; iPlot++){
        TCanvas* can = new TCanvas("can","can",500,500);
        can->SetTopMargin(0.05);
        plotsMedNjDOWNEvents[iPlot].Write();
        plotsMedNjDOWNEvents[iPlot].Draw(can,skims.ntuples,skims.signalNtuples,"../plots/plotObs_weightGJets_plots");
    }
    for( int iPlot = 0 ; iPlot < plotsHighNjDOWNEvents.size() ; iPlot++){
        TCanvas* can = new TCanvas("can","can",500,500);
        can->SetTopMargin(0.05);
        plotsHighNjDOWNEvents[iPlot].Write();
        plotsHighNjDOWNEvents[iPlot].Draw(can,skims.ntuples,skims.signalNtuples,"../plots/plotObs_weightGJets_plots");
    }

    outputFile->Close();

}
