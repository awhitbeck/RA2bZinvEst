#include "TGraphAsymmErrors.h"
#include "TString.h"
#include "TChain.h"
#include "TH1F.h"
#include "TROOT.h"
#include "THStack.h"
#include "TPad.h"

#include <vector>
#include <map>
#include <iostream>

#include "CMS_lumi.cc"

#include "plotterUtils.cc"
#include "skimSamples.cc"
#include "definitions.h"
#include "RA2bTree.cc"

using namespace std;

int main(int argc, char** argv){

  bool DR0p4 = false;

  if( argc != 2 ){ 
    cout << "1 argument needed:" << endl;
    cout << "0 - signal (single-photon) region will be used" << endl;
    cout << "1 - LDP (single-photon - LDP) region will be used" << endl;
    return 1;
  }
  int region = atoi(argv[1]);
  if( region < 0 || region > 1 ){
    cout << "argument 1 doesn't have an acceptible value" << endl;
    return 1;
  }

  TString regionNames[2] = {"signal","LDP"};

  gROOT->ProcessLine(".L tdrstyle.C");
  gROOT->ProcessLine("setTDRStyle()");

  typedef plot<RA2bTree> plot;
  
  TH2F* MHTplot = new TH2F("MHT_"+regionNames[region],"H_{T}^{miss} [GeV]",15,300.,1800.,1000.,0.,1.);
  TH2F* Bins46plot = new TH2F("AnalysisBins_BTag0_"+regionNames[region],"i^{th} Bin",46,0.5,46.5,1000.,0.,1.);
  TH2F* Bins59plot = new TH2F("AnalysisBins_BTag0plusQCDCR_RzGamma_"+regionNames[region],"i^{th} Bin",59,0.5,59.5,1000.,0.,1.);

  // background MC samples
  vector<RA2bTree*> samples;
  vector<TString> sampleNames;

  TString skimType;
  if( region == 0 )
    skimType=BASE_DIR+"tree_GJet_CleanVars/";
  if( region == 1 )
    skimType=BASE_DIR+"tree_GJetLDP_CleanVars/";

  vector<TString> GJetsFileNames;
  if( DR0p4 ){ 
    GJetsFileNames.push_back("tree_GJets_DR-0p4_HT-100to200.root");
    GJetsFileNames.push_back("tree_GJets_DR-0p4_HT-200to400.root");
    GJetsFileNames.push_back("tree_GJets_DR-0p4_HT-400to600.root");
    GJetsFileNames.push_back("tree_GJets_DR-0p4_HT-600toInf.root");
  }else{
        GJetsFileNames.push_back("tree_GJets_HT-100to200_MC2017.root");
        GJetsFileNames.push_back("tree_GJets_HT-200to400_MC2017.root");
        GJetsFileNames.push_back("tree_GJets_HT-400to600_MC2017.root");
        GJetsFileNames.push_back("tree_GJets_HT-600toInf_MC2017.root"); 
  }
  TChain* GJets = new TChain("tree");
  for( int i = 0 ; i < GJetsFileNames.size() ; i++ ){
    GJets->Add(skimType+"/"+GJetsFileNames[i]);
  }
  samples.push_back(new RA2bTree(GJets));
  sampleNames.push_back("GJets");

  for( int iSample = 0 ; iSample < samples.size() ; iSample++){

    RA2bTree* ntuple = samples[iSample];
    int numEvents = ntuple->fChain->GetEntries();
    ntupleBranchStatus<RA2bTree>(ntuple);
    for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
      ntuple->GetEntry(iEvt);
      if( iEvt % 10000 == 0 ) cout << sampleNames[iSample] << ": " << iEvt << "/" << numEvents << endl;
      
      if( sampleNames[iSample] == "GJets" && !isPromptPhoton(ntuple) ) continue;
      if( sampleNames[iSample] == "GJets" && !( ntuple->madMinPhotonDeltaR>0.4 ) ) continue;
      if( sampleNames[iSample] == "GJets" && ntuple->Photons->size() != 1 ) continue;
      if( sampleNames[iSample] == "GJets" && ntuple->Photons->at(0).Pt() < 200. ) continue;      
      if( ( region == 0 && !RA2bBaselineCut(ntuple) ) || ( region == 1 && !RA2bLDPBaselineCut(ntuple) ) ) continue;

      for( int i=0 ; i<100 ; i++ ){
          MHTplot->Fill(ntuple->MHT,photonTriggerWeightRand(ntuple),ntuple->Weight*customPUweights(ntuple));
          Bins46plot->Fill(fillRA2b46Bins(ntuple),photonTriggerWeightRand(ntuple),ntuple->Weight*customPUweights(ntuple));
          Bins59plot->Fill(fillRA2b59Bins(ntuple),photonTriggerWeightRand(ntuple),ntuple->Weight*customPUweights(ntuple));
      }

    }
  }

  TFile* outputFile;
  if( DR0p4 ) 
    outputFile = new TFile("triggerUnc_"+regionNames[region]+"_histo.root","RECREATE");
  else 
    outputFile = new TFile("triggerUnc_DR0p05_"+regionNames[region]+"_histo.root","RECREATE");
  MHTplot->Write();
  Bins46plot->Write();
  Bins59plot->Write();
  outputFile->Close();

}
