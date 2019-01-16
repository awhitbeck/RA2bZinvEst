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
    vector<int> trigger_indices = {140,141};

    int regInt = atoi(argv[1]);
    skimSamples::region reg = static_cast<skimSamples::region>(regInt);
    skimSamples skims(reg);
    typedef plot<RA2bTree> plot;
    cout << skims.skimType << endl;
    for( int i = 0 ; i < skims.ntuples.size() ; i++){
        cout << "sample name: " << skims.sampleName[i] << endl;
    }
  
    plot MHTplot(*fillMHT<RA2bTree>,"MHT_"+skims.regionNames[regInt]+"_baseline","H_{T}^{miss} [GeV]",64,200.,1800.);
    plot HTplot(*fillHT<RA2bTree>,"HT_"+skims.regionNames[regInt]+"_baseline","H_{T} [GeV]",50,300,2800.);
    plot NJetsplot(*fillNJets<RA2bTree>,"NJets_"+skims.regionNames[regInt]+"_baseline","N_{jet}",14,1.5,15.5);
    plot BTagsplot(*fillBTags<RA2bTree>,"BTags_"+skims.regionNames[regInt]+"_baseline","N_{b-jet}",6,-0.5,5.5);
    plot Binsplot(*fillRA2b174Bins<RA2bTree>,"AnalysisBins_"+skims.regionNames[regInt]+"_baseline","Search Bin",174,0.5,174.5);
    plot Bins46plot(*fillRA2b46Bins<RA2bTree>,"AnalysisBins_BTag0_"+skims.regionNames[regInt]+"_baseline","Search Bin",46,0.5,46.5);
    plot Bins59plot(*fillRA2b59Bins<RA2bTree>,"AnalysisBins_BTag0plusQCDCR_"+skims.regionNames[regInt]+"_baseline","Search Bin",59,0.5,59.5);
    plot BinsNJet2plot(*fillRA2bNJet2Bins<RA2bTree>,"AnalysisBins_NJet2_"+skims.regionNames[regInt]+"_baseline","Search Bin",30,0.5,30.5);

    plot DeltaPhi1plot(*fillDeltaPhi1<RA2bTree>,"DeltaPhi1_"+skims.regionNames[regInt]+"_baseline","#Delta#Phi_{1}",20,0.,3.1415);
    plot DeltaPhi2plot(*fillDeltaPhi2<RA2bTree>,"DeltaPhi2_"+skims.regionNames[regInt]+"_baseline","#Delta#Phi_{2}",20,0.,3.1415);
    plot DeltaPhi3plot(*fillDeltaPhi3<RA2bTree>,"DeltaPhi3_"+skims.regionNames[regInt]+"_baseline","#Delta#Phi_{3}",20,0.,3.1415);
    plot DeltaPhi4plot(*fillDeltaPhi4<RA2bTree>,"DeltaPhi4_"+skims.regionNames[regInt]+"_baseline","#Delta#Phi_{4}",20,0.,3.1415);

    plot PhotonPtplot(*photonPt<RA2bTree>,"PhotonPt_"+skims.regionNames[regInt]+"_baseline","p_{T,#gamma} [GeV]",50,200,1400);
    plot PhotonEtaplot(*photonEta<RA2bTree>,"PhotonEta_"+skims.regionNames[regInt]+"_baseline","#eta_{#gamma}",60,-3.,3.);

    plot PhotonMinDeltaR(*fillRecoPhotonDeltaR<RA2bTree>,"PhotonMinDeltaR_"+skims.regionNames[regInt]+"_baseline","min#Delta R(jet,#gamma)",40,0,4);

    plot verticesplot(*fillNumVertices<RA2bTree>,"NumVertices_"+skims.regionNames[regInt]+"_baseline","n_{vtx}",40,0,80);

    vector<plot> plotsAllEvents;
    plotsAllEvents.push_back(MHTplot);
    plotsAllEvents.push_back(HTplot);
    plotsAllEvents.push_back(NJetsplot);
    plotsAllEvents.push_back(BTagsplot);
    plotsAllEvents.push_back(Binsplot);
    plotsAllEvents.push_back(Bins46plot);
    plotsAllEvents.push_back(Bins59plot);
    plotsAllEvents.push_back(BinsNJet2plot);
    plotsAllEvents.push_back(DeltaPhi1plot);
    plotsAllEvents.push_back(DeltaPhi2plot);
    plotsAllEvents.push_back(DeltaPhi3plot);
    plotsAllEvents.push_back(DeltaPhi4plot);
    plotsAllEvents.push_back(PhotonPtplot);
    plotsAllEvents.push_back(PhotonEtaplot);
    plotsAllEvents.push_back(PhotonMinDeltaR);
    plotsAllEvents.push_back(verticesplot);

    plot MHTplotEB(*fillMHT<RA2bTree>,"MHT_"+skims.regionNames[regInt]+"_baseline_EB","H_{T}^{miss} [GeV]",64,200.,1800.);
    plot HTplotEB(*fillHT<RA2bTree>,"HT_"+skims.regionNames[regInt]+"_baseline_EB","H_{T} [GeV]",50,300,2800.);
    plot NJetsplotEB(*fillNJets<RA2bTree>,"NJets_"+skims.regionNames[regInt]+"_baseline_EB","N_{jet}",14,1.5,15.5);
    plot BTagsplotEB(*fillBTags<RA2bTree>,"BTags_"+skims.regionNames[regInt]+"_baseline_EB","N_{b-jet}",6,-0.5,5.5);
    plot BinsplotEB(*fillRA2b174Bins<RA2bTree>,"AnalysisBins_"+skims.regionNames[regInt]+"_baseline_EB","Search Bin",174,0.5,174.5);
    plot Bins46plotEB(*fillRA2b46Bins<RA2bTree>,"AnalysisBins_BTag0_"+skims.regionNames[regInt]+"_baseline_EB","Search Bin",46,0.5,46.5);
    plot Bins59plotEB(*fillRA2b59Bins<RA2bTree>,"AnalysisBins_BTag0plusQCDCR_"+skims.regionNames[regInt]+"_baseline_EB","Search Bin",59,0.5,59.5);
    plot BinsNJet2plotEB(*fillRA2bNJet2Bins<RA2bTree>,"AnalysisBins_NJet2_"+skims.regionNames[regInt]+"_baseline_EB","Search Bin",30,0.5,30.5);

    plot DeltaPhi1plotEB(*fillDeltaPhi1<RA2bTree>,"DeltaPhi1_"+skims.regionNames[regInt]+"_baseline_EB","#Delta#Phi_{1}",20,0.,3.1415);
    plot DeltaPhi2plotEB(*fillDeltaPhi2<RA2bTree>,"DeltaPhi2_"+skims.regionNames[regInt]+"_baseline_EB","#Delta#Phi_{2}",20,0.,3.1415);
    plot DeltaPhi3plotEB(*fillDeltaPhi3<RA2bTree>,"DeltaPhi3_"+skims.regionNames[regInt]+"_baseline_EB","#Delta#Phi_{3}",20,0.,3.1415);
    plot DeltaPhi4plotEB(*fillDeltaPhi4<RA2bTree>,"DeltaPhi4_"+skims.regionNames[regInt]+"_baseline_EB","#Delta#Phi_{4}",20,0.,3.1415);

    plot PhotonPtplotEB(*photonPt<RA2bTree>,"PhotonPt_"+skims.regionNames[regInt]+"_baseline_EB","p_{T,#gamma} [GeV]",50,200,1400);
    plot PhotonEtaplotEB(*photonEta<RA2bTree>,"PhotonEta_"+skims.regionNames[regInt]+"_baseline_EB","#eta_{#gamma}",60,-3.,3.);

    plot PhotonMinDeltaREB(*fillRecoPhotonDeltaR<RA2bTree>,"PhotonMinDeltaR_"+skims.regionNames[regInt]+"_baseline_EB","min#Delta R(jet,#gamma)",40,0,4);
  
    plot verticesplotEB(*fillNumVertices<RA2bTree>,"NumVertices_"+skims.regionNames[regInt]+"_baseline_EB","n_{vtx}",40,0,80);

    vector<plot> plotsEBevents;
    plotsEBevents.push_back(MHTplotEB);
    plotsEBevents.push_back(HTplotEB);
    plotsEBevents.push_back(NJetsplotEB);
    plotsEBevents.push_back(BTagsplotEB);
    plotsEBevents.push_back(BinsplotEB);
    plotsEBevents.push_back(Bins46plotEB);
    plotsEBevents.push_back(Bins59plotEB);
    plotsEBevents.push_back(BinsNJet2plotEB);
    plotsEBevents.push_back(DeltaPhi1plotEB);
    plotsEBevents.push_back(DeltaPhi2plotEB);
    plotsEBevents.push_back(DeltaPhi3plotEB);
    plotsEBevents.push_back(DeltaPhi4plotEB);
    plotsEBevents.push_back(PhotonPtplotEB);
    plotsEBevents.push_back(PhotonEtaplotEB);
    plotsEBevents.push_back(PhotonMinDeltaREB);
    plotsEBevents.push_back(verticesplotEB);

    plot MHTplotEE(*fillMHT<RA2bTree>,"MHT_"+skims.regionNames[regInt]+"_baseline_EE","H_{T}^{miss} [GeV]",64,200.,1800.);
    plot HTplotEE(*fillHT<RA2bTree>,"HT_"+skims.regionNames[regInt]+"_baseline_EE","H_{T} [GeV]",50,300,2800.);
    plot NJetsplotEE(*fillNJets<RA2bTree>,"NJets_"+skims.regionNames[regInt]+"_baseline_EE","N_{jet}",14,1.5,15.5);
    plot BTagsplotEE(*fillBTags<RA2bTree>,"BTags_"+skims.regionNames[regInt]+"_baseline_EE","N_{b-jet}",6,-0.5,5.5);
    plot BinsplotEE(*fillRA2b174Bins<RA2bTree>,"AnalysisBins_"+skims.regionNames[regInt]+"_baseline_EE","Search Bin",174,0.5,174.5);
    plot Bins46plotEE(*fillRA2b46Bins<RA2bTree>,"AnalysisBins_BTag0_"+skims.regionNames[regInt]+"_baseline_EE","Search Bin",46,0.5,46.5);
    plot Bins59plotEE(*fillRA2b59Bins<RA2bTree>,"AnalysisBins_BTag0plusQCDCR_"+skims.regionNames[regInt]+"_baseline_EE","Search Bin",59,0.5,59.5);
    plot BinsNJet2plotEE(*fillRA2bNJet2Bins<RA2bTree>,"AnalysisBins_NJet2_"+skims.regionNames[regInt]+"_baseline_EE","Search Bin",30,0.5,30.5);

    plot DeltaPhi1plotEE(*fillDeltaPhi1<RA2bTree>,"DeltaPhi1_"+skims.regionNames[regInt]+"_baseline_EE","#Delta#Phi_{1}",20,0.,3.1415);
    plot DeltaPhi2plotEE(*fillDeltaPhi2<RA2bTree>,"DeltaPhi2_"+skims.regionNames[regInt]+"_baseline_EE","#Delta#Phi_{2}",20,0.,3.1415);
    plot DeltaPhi3plotEE(*fillDeltaPhi3<RA2bTree>,"DeltaPhi3_"+skims.regionNames[regInt]+"_baseline_EE","#Delta#Phi_{3}",20,0.,3.1415);
    plot DeltaPhi4plotEE(*fillDeltaPhi4<RA2bTree>,"DeltaPhi4_"+skims.regionNames[regInt]+"_baseline_EE","#Delta#Phi_{4}",20,0.,3.1415);

    plot PhotonPtplotEE(*photonPt<RA2bTree>,"PhotonPt_"+skims.regionNames[regInt]+"_baseline_EE","p_{T,#gamma} [GeV]",50,200,1400);
    plot PhotonEtaplotEE(*photonEta<RA2bTree>,"PhotonEta_"+skims.regionNames[regInt]+"_baseline_EE","#eta_{#gamma}",60,-3.,3.);

    plot PhotonMinDeltaREE(*fillRecoPhotonDeltaR<RA2bTree>,"PhotonMinDeltaR_"+skims.regionNames[regInt]+"_baseline_EE","min#Delta R(jet,#gamma)",40,0,4);

    plot verticesplotEE(*fillNumVertices<RA2bTree>,"NumVertices_"+skims.regionNames[regInt]+"_baseline_EE","n_{vtx}",40,0,80);

    vector<plot> plotsEEevents;
    plotsEEevents.push_back(MHTplotEE);
    plotsEEevents.push_back(HTplotEE);
    plotsEEevents.push_back(NJetsplotEE);
    plotsEEevents.push_back(BTagsplotEE);
    plotsEEevents.push_back(BinsplotEE);
    plotsEEevents.push_back(Bins46plotEE);
    plotsEEevents.push_back(Bins59plotEE);
    plotsEEevents.push_back(BinsNJet2plotEE);
    plotsEEevents.push_back(DeltaPhi1plotEE);
    plotsEEevents.push_back(DeltaPhi2plotEE);
    plotsEEevents.push_back(DeltaPhi3plotEE);
    plotsEEevents.push_back(DeltaPhi4plotEE);
    plotsEEevents.push_back(PhotonPtplotEE);
    plotsEEevents.push_back(PhotonEtaplotEE);
    plotsEEevents.push_back(PhotonMinDeltaREE);
    plotsEEevents.push_back(verticesplotEE);
    
    int count_QCD = 0, count_TT = 0, count_Others = 0, count_GJets = 0, count_QCD_jet = 0, count_TT_jet = 0, count_Others_jet = 0, count_GJets_jet = 0, TT_total = 0, Others_total = 0, GJets_total = 0, QCD_total = 0 ; 
    // background MC samples
    for( int iSample = 0 ; iSample < skims.ntuples.size() ; iSample++){

        RA2bTree* ntuple = skims.ntuples[iSample];

        for( int iPlot = 0 ; iPlot < plotsAllEvents.size() ; iPlot++){
            plotsAllEvents[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
            plotsAllEvents[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
        }
        for( int iPlot = 0 ; iPlot < plotsEBevents.size() ; iPlot++){
            plotsEBevents[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
            plotsEBevents[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
        }
        for( int iPlot = 0 ; iPlot < plotsEEevents.size() ; iPlot++){
            plotsEEevents[iPlot].addNtuple(ntuple,skims.sampleName[iSample]);
            plotsEEevents[iPlot].setFillColor(ntuple,skims.fillColor[iSample]);
        }

        int numEvents = ntuple->fChain->GetEntries();
        ntupleBranchStatus<RA2bTree>(ntuple);
        double weight = 1.0;
        
        for( int iEvt = 0 ; iEvt < min(MAX_EVENTS,numEvents) ; iEvt++ ){
            ntuple->GetEntry(iEvt);
            if( iEvt % 1000000 == 0 ) cout << skims.sampleName[iSample] << ": " << iEvt << "/" << numEvents << endl;

         //   if( ( reg == skimSamples::kSignal || reg == skimSamples::kPhoton || reg == skimSamples::kDYe || reg == skimSamples::kDYm ) && !RA2bBaselineCut(ntuple) ) continue;
          //  if( ( reg == skimSamples::kLDP || reg == skimSamples::kPhotonLDP || reg == skimSamples::kDYeLDP || reg == skimSamples::kDYmLDP ) && !RA2bLDPBaselineCut(ntuple) ) continue;

      //      if( skims.regionNames[regInt] == "photonLDP" || skims.regionNames[regInt] == "photon" ){
            if( skims.sampleName[iSample] == "QCD" && isPromptPhoton(ntuple) ) continue;
            if( skims.sampleName[iSample] == "GJets" && ( !isPromptPhoton(ntuple) || ntuple->madMinPhotonDeltaR < 0.4 ) ) continue;
            if( ntuple->Photons->size() != 1 ) continue;
            if( ntuple->Photons->at(0).Pt() < 200. ) continue;
            if( !ntuple->Photons_fullID->at(0) ) continue;    
         //   }
         //   if( skims.sampleName[iSample] == "GJets" && ((fabs(ntuple->Photons->at(0).Eta())>=1.4442 && fabs(ntuple->Photons->at(0).Eta()<=1.566))))continue;
         //   if( skims.sampleName[iSample] == "GJets" && fabs(ntuple->Photons->at(0).Eta())>=2)continue;
         //   }

    
   /*       for (int unsigned s = 0; s < ntuple->Jets->size();s++){
            weight*=prefiring_weight_jet(ntuple,iEvt,s);
            }
           
    */
           if( skims.sampleName[iSample] == "QCD") {QCD_total ++ ; }
           if( skims.sampleName[iSample] == "QCD" && prefiring_weight_photon(ntuple,iEvt) != 1) {count_QCD ++ ; }
           if( skims.sampleName[iSample] == "QCD" && prefiring_weight_jet(ntuple,iEvt,0) != 1) {count_QCD_jet ++ ; }

             if( skims.sampleName[iSample] == "TT") { TT_total ++ ; }
           if( skims.sampleName[iSample] == "TT" && prefiring_weight_photon(ntuple,iEvt) != 1) { count_TT ++ ; }
           if( skims.sampleName[iSample] == "TT" && prefiring_weight_jet(ntuple,iEvt,0) != 1) { count_TT_jet ++ ; }
           
           if( skims.sampleName[iSample] == "Others") {Others_total ++ ; }
           if( skims.sampleName[iSample] == "Others" && prefiring_weight_photon(ntuple,iEvt) != 1) {count_Others ++ ; }
           if( skims.sampleName[iSample] == "Others" && prefiring_weight_jet(ntuple,iEvt,0) != 1) {count_Others_jet ++ ; }
           
           if( skims.sampleName[iSample] == "GJets") { GJets_total ++ ; }  
           if( skims.sampleName[iSample] == "GJets" && prefiring_weight_photon(ntuple,iEvt) != 1) { count_GJets ++ ; }  
           if( skims.sampleName[iSample] == "GJets" && prefiring_weight_jet(ntuple,iEvt,0) != 1) { count_GJets_jet ++ ; }  
     
  

           for( int iPlot = 0 ; iPlot < plotsAllEvents.size() ; iPlot++ ){
                weight = lumi*ntuple->Weight/*(ntuple->puWeight + ntuple->puSysUp)*customPUweights(ntuple)*prefiring_weight_photon(ntuple,iEvt)*/;       // prefiring weight here
          //
          //      weight = lumi*ntuple->Weight;              // prefiring weight here
              /*  if( reg == skimSamples::kPhoton || reg == skimSamples::kPhotonLDP ) 
                   weight *= photonTriggerWeight(ntuple);
                if( skims.sampleName[iSample] == "GJets" ){
                   weight *= GJets0p4Weights(ntuple)*dRweights(ntuple);
                }
                */
               if( ntuple->Photons_isEB->at(0) ){
                    plotsAllEvents[iPlot].fill(ntuple,weight);
                    plotsEBevents[iPlot].fill(ntuple,weight);
                }
                else  {
                    plotsAllEvents[iPlot].fill(ntuple,weight);
                    plotsEEevents[iPlot].fill(ntuple,weight);
                }
            }

        }
    }

    cout<<"QCD Total \t"<<QCD_total<<"\t TT total\t "<<TT_total<<"\tOthers total\t"<<Others_total<<"\tGJets total\t"<<GJets_total<<"\n";
    cout<<"QCD count PHOTONS PREFIRED \t"<<count_QCD<<"\t TT count\t "<<count_TT<<"\t Others count\t"<<count_Others<<"\tGJets count\t"<<count_GJets<<"\n";
    cout<<"QCD count Jets Prefired \t"<<count_QCD_jet<<"\t TT count\t "<<count_TT_jet<<"\t Others count\t"<<count_Others_jet<<"\tGJets count\t"<<count_GJets_jet<<"\n";

    // Data samples
    RA2bTree* ntuple = skims.dataNtuple;
    for( int iPlot = 0 ; iPlot < plotsAllEvents.size() ; iPlot++){
        plotsAllEvents[iPlot].addDataNtuple(ntuple,"data");
        plotsEBevents[iPlot].addDataNtuple(ntuple,"data");
        plotsEEevents[iPlot].addDataNtuple(ntuple,"data");
    }
  
    int numEvents = ntuple->fChain->GetEntries();
    ntupleBranchStatus<RA2bTree>(ntuple);
    for( int iEvt = 0 ; iEvt < min(MAX_EVENTS,numEvents); iEvt++ ){
        ntuple->GetEntry(iEvt);
        if( iEvt % 1000000 == 0 ) cout << "data: " << iEvt << "/" << numEvents << endl;

     //   if( ( reg == skimSamples::kSignal || reg == skimSamples::kPhoton || reg == skimSamples::kDYe || reg == skimSamples::kDYm ) && !RA2bBaselineCut(ntuple) ) continue;
      // if( ( reg == skimSamples::kLDP || reg == skimSamples::kPhotonLDP || reg == skimSamples::kDYeLDP || reg == skimSamples::kDYmLDP ) && !RA2bLDPBaselineCut(ntuple) ) continue;
        if( ( reg == skimSamples::kPhoton || reg == skimSamples::kPhotonLDP ) && ntuple->Photons->at(0).Pt()<200. ) continue;
        if( ( reg == skimSamples::kPhoton || reg == skimSamples::kPhotonLDP ) && ntuple->Photons->size() != 1 ) continue;
        if( ( reg == skimSamples::kPhoton || reg == skimSamples::kPhotonLDP ) && !ntuple->Photons_fullID->at(0)  ) continue;


     //   if( ( reg == skimSamples::kPhoton || reg == skimSamples::kPhotonLDP ) && ((fabs(ntuple->Photons->at(0).Eta())>=1.4442 && fabs(ntuple->Photons->at(0).Eta()<=1.566))))continue;
     //   if( ( reg == skimSamples::kPhoton || reg == skimSamples::kPhotonLDP ) && fabs(ntuple->Photons->at(0).Eta())>=2)continue;
                    
 //       if( ntuple->TriggerPass->size() < 138 || ntuple->TriggerPass->size() > 146 ) continue;

        if( ntuple->TriggerPass->at(137) || ntuple->TriggerPass->at(138) || ntuple->TriggerPass->at(139)||  ntuple->TriggerPass->at(140) || ntuple->TriggerPass->at(141) || ntuple->TriggerPass->at(142) ||  ntuple->TriggerPass->at(143) || ntuple->TriggerPass->at(144) || ntuple->TriggerPass->at(145)  ) {
     //   if( ntuple->TriggerPass->size() < 143 || !ntuple->TriggerPass->at(142) ) continue;

        for( int iPlot = 0 ; iPlot < plotsAllEvents.size() ; iPlot++){
            if( ntuple->Photons_isEB->at(0) ){
                plotsAllEvents[iPlot].fillData(ntuple);
                plotsEBevents[iPlot].fillData(ntuple);
            }
            else {
                plotsAllEvents[iPlot].fillData(ntuple);
                plotsEEevents[iPlot].fillData(ntuple);
            }
        }
	}
    }

    TFile* outputFile = new TFile("plotObs_"+skims.regionNames[regInt]+".root","UPDATE");

    for( int iPlot = 0 ; iPlot < plotsAllEvents.size() ; iPlot++){
        TCanvas* can = new TCanvas("can","can",500,500);
        can->SetTopMargin(0.05);
        plotsAllEvents[iPlot].Write();
        plotsAllEvents[iPlot].Draw(can,skims.ntuples,skims.signalNtuples,"../plots/plotObs_baseline_plots");
    }
    for( int iPlot = 0 ; iPlot < plotsEEevents.size() ; iPlot++){
        TCanvas* can = new TCanvas("can","can",500,500);
        can->SetTopMargin(0.05);
        plotsEEevents[iPlot].Write();
        plotsEEevents[iPlot].Draw(can,skims.ntuples,skims.signalNtuples,"../plots/plotObs_baseline_plots");
    }
    for( int iPlot = 0 ; iPlot < plotsEBevents.size() ; iPlot++){
        TCanvas* can = new TCanvas("can","can",500,500);
        can->SetTopMargin(0.05);
        plotsEBevents[iPlot].Write();
        plotsEBevents[iPlot].Draw(can,skims.ntuples,skims.signalNtuples,"../plots/plotObs_baseline_plots");
    }
  
    outputFile->Close();

}
