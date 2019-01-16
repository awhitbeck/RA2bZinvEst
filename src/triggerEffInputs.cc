#include "TLegend.h"
#include "TGraphAsymmErrors.h"
#include "TString.h"
#include "TChain.h"
#include "TH1F.h"
#include "TROOT.h"
#include "THStack.h"

#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <cassert>
#include <stdlib.h>

#include "CMS_lumi.cc"

#include "plotterUtils.cc"
#include "definitions.h"
#include "RA2bTree.cc"

using namespace std;

int main(int argc, char** argv){
  
    int region;

    if( argc != 2 ){
        cerr << "need one arguments" << endl;
        cerr << "Arg. 1 - 0: signal, 1: LDP" << endl;
        return 1;
    }else{
        region = atoi(argv[1]);
        assert( region == 0 || region == 1 );
    }

    gROOT->ProcessLine(".L tdrstyle.C");
    gROOT->ProcessLine("setTDRStyle()");

    typedef plot<RA2bTree> plot;
  
    vector<TString> xlabels;
    xlabels.push_back("H_{T}^{miss} [GeV]");
    xlabels.push_back("p_{T,#gamma} [GeV]");
    xlabels.push_back("H_{T} [GeV]");
    xlabels.push_back("n_{j}");
    const int MHTbins = 8;
    const int HTbins = 7;
    double MHTbinning[MHTbins]={ 150. , 200. , 250. , 300. , 350. , 500. , 750. , 1500. };
    double HTbinning[HTbins]={ 300. ,  350. , 400. , 475. , 600. , 800. , 1200. };
    //plot tarMHTplot(*fillMHT<RA2bTree>,"MHT_tarTrigger","H_{T}^{miss} [GeV]",MHTbins-1,MHTbinning);
    //plot tarMHTplotEB(*fillMHT<RA2bTree>,"MHT_tarTrigger_EB","H_{T}^{miss} [GeV]",MHTbins-1,MHTbinning);
    //plot tarMHTplotEE(*fillMHT<RA2bTree>,"MHT_tarTrigger_EE","H_{T}^{miss} [GeV]",MHTbins-1,MHTbinning);
    plot tarMHTplot(*fillMHT<RA2bTree>,"MHT_tarTrigger","H_{T}^{miss} [GeV]",90,100,1000);
    plot tarMHTplotEB(*fillMHT<RA2bTree>,"MHT_tarTrigger_EB","H_{T}^{miss} [GeV]",90,100,1000);
    plot tarMHTplotEE(*fillMHT<RA2bTree>,"MHT_tarTrigger_EE","H_{T}^{miss} [GeV]",90,100,1000);

    plot tarPhotonPtplot(*photonPt<RA2bTree>,"photonPt_tarTrigger","p_{T} [GeV]",90,100,1000);
    plot tarPhotonPtplotEB(*photonPt<RA2bTree>,"photonPt_tarTrigger_EB","p_{T} [GeV]",90,100,1000);
    plot tarPhotonPtplotEE(*photonPt<RA2bTree>,"photonPt_tarTrigger_EE","p_{T} [GeV]",90,100,1000);

    plot tarHTplot(*fillHT<RA2bTree>,"HT_tarTrigger","H_{T} [GeV]",30,200,1700);
    plot tarHTplotEB(*fillHT<RA2bTree>,"HT_tarTrigger_EB","H_{T} [GeV]",30,200,1700);
    plot tarHTplotEE(*fillHT<RA2bTree>,"HT_tarTrigger_EE","H_{T} [GeV]",30,200,1700);

    plot tarNJetsplot(*fillNJets<RA2bTree>,"NJets_tarTrigger","n_{j}",7,1.5,8.5);
    plot tarNJetsplotEB(*fillNJets<RA2bTree>,"NJets_tarTrigger_EB","n_{j}",7,1.5,8.5);
    plot tarNJetsplotEE(*fillNJets<RA2bTree>,"NJets_tarTrigger_EE","n_{j}",7,1.5,8.5);

    //plot refMHTplot(*fillMHT<RA2bTree>,"MHT_refTrigger","H_{T}^{miss} [GeV]",MHTbins-1,MHTbinning);
    //plot refMHTplotEB(*fillMHT<RA2bTree>,"MHT_refTrigger_EB","H_{T}^{miss} [GeV]",MHTbins-1,MHTbinning);
    //plot refMHTplotEE(*fillMHT<RA2bTree>,"MHT_refTrigger_EE","H_{T}^{miss} [GeV]",MHTbins-1,MHTbinning);
    plot refMHTplot(*fillMHT<RA2bTree>,"MHT_refTrigger","H_{T}^{miss} [GeV]",90,100,1000);
    plot refMHTplotEB(*fillMHT<RA2bTree>,"MHT_refTrigger_EB","H_{T}^{miss} [GeV]",90,100,1000);
    plot refMHTplotEE(*fillMHT<RA2bTree>,"MHT_refTrigger_EE","H_{T}^{miss} [GeV]",90,100,1000);

    plot refPhotonPtplot(*photonPt<RA2bTree>,"photonPt_refTrigger","H_{T}^{miss} [GeV]",90,100,1000);
    plot refPhotonPtplotEB(*photonPt<RA2bTree>,"photonPt_refTrigger_EB","H_{T}^{miss} [GeV]",90,100,1000);
    plot refPhotonPtplotEE(*photonPt<RA2bTree>,"photonPt_refTrigger_EE","H_{T}^{miss} [GeV]",90,100,1000);


    plot refHTplot(*fillHT<RA2bTree>,"HT_refTrigger","H_{T} [GeV]",30,200,1700);
    plot refHTplotEB(*fillHT<RA2bTree>,"HT_refTrigger_EB","H_{T} [GeV]",30,200,1700);
    plot refHTplotEE(*fillHT<RA2bTree>,"HT_refTrigger_EE","H_{T} [GeV]",30,200,1700);

    plot refNJetsplot(*fillNJets<RA2bTree>,"NJets_refTrigger","n_{j}",7,1.5,8.5);
    plot refNJetsplotEB(*fillNJets<RA2bTree>,"NJets_refTrigger_EB","n_{j}",7,1.5,8.5);
    plot refNJetsplotEE(*fillNJets<RA2bTree>,"NJets_refTrigger_EE","n_{j}",7,1.5,8.5);

    vector<plot> refPlotMHTversusHT,tarPlotMHTversusHT;
    for( int iPlot = 0 ; iPlot < HTbins-1 ; iPlot++ ){
        TString plotName = "HT_refTrigger_HT";
        plotName+=HTbinning[iPlot];
        refPlotMHTversusHT.push_back(plot(*fillMHT<RA2bTree>,plotName,"H_{T} [GeV]",MHTbins-1,MHTbinning));
        plotName = "HT_tarTrigger_HT";
        plotName+=HTbinning[iPlot];
        tarPlotMHTversusHT.push_back(plot(*fillMHT<RA2bTree>,plotName,"H_{T} [GeV]",MHTbins-1,MHTbinning));
    }

    vector<plot> plotsTarget;
    plotsTarget.push_back(tarMHTplot);
    plotsTarget.push_back(tarPhotonPtplot);
    plotsTarget.push_back(tarHTplot);
    plotsTarget.push_back(tarNJetsplot);
    vector<plot> plotsTargetEB;
    plotsTargetEB.push_back(tarMHTplotEB);
    plotsTargetEB.push_back(tarPhotonPtplotEB);
    plotsTargetEB.push_back(tarHTplotEB);
    plotsTargetEB.push_back(tarNJetsplotEB);
    vector<plot> plotsTargetEE;
    plotsTargetEE.push_back(tarMHTplotEE);
    plotsTargetEE.push_back(tarPhotonPtplotEE);
    plotsTargetEE.push_back(tarHTplotEE);
    plotsTargetEE.push_back(tarNJetsplotEE);
    vector<plot> plotsReference;
    plotsReference.push_back(refMHTplot);
    plotsReference.push_back(refPhotonPtplot);
    plotsReference.push_back(refHTplot);
    plotsReference.push_back(refNJetsplot);
    vector<plot> plotsReferenceEB;
    plotsReferenceEB.push_back(refMHTplotEB);
    plotsReferenceEB.push_back(refPhotonPtplotEB);
    plotsReferenceEB.push_back(refHTplotEB);
    plotsReferenceEB.push_back(refNJetsplotEB);
    vector<plot> plotsReferenceEE;
    plotsReferenceEE.push_back(refMHTplotEE);
    plotsReferenceEE.push_back(refPhotonPtplotEE);
    plotsReferenceEE.push_back(refHTplotEE);
    plotsReferenceEE.push_back(refNJetsplotEE);

    // samples
    //skim inputs
    vector<RA2bTree*> samples;
    vector<TString> sampleNames;
    TChain* JetHTdata = new TChain("tree");
    if( region == 0 )
      JetHTdata->Add("/Volumes/Whitbeck Backup/CMS_DATA/SusyRA2Analysis2015/Skims/Run2ProductionV16/tree_GJetLoose_CleanVars/tree_JetHT_2017*.root");
      
    samples.push_back(new RA2bTree(JetHTdata));
    sampleNames.push_back("JetHTdata");

    for( int iSample = 0 ; iSample < samples.size() ; iSample++){

        RA2bTree* ntuple = samples[iSample];

        for( int iPlot = 0 ; iPlot < plotsTarget.size() ; iPlot++){
            plotsTarget[iPlot].addDataNtuple(ntuple,sampleNames[iSample]);
        }
        for( int iPlot = 0 ; iPlot < plotsReference.size() ; iPlot++){
            plotsReference[iPlot].addDataNtuple(ntuple,sampleNames[iSample]);
        }
        for( int iPlot = 0 ; iPlot < plotsTargetEB.size() ; iPlot++){
            plotsTargetEB[iPlot].addDataNtuple(ntuple,sampleNames[iSample]);
        }
        for( int iPlot = 0 ; iPlot < plotsReferenceEB.size() ; iPlot++){
            plotsReferenceEB[iPlot].addDataNtuple(ntuple,sampleNames[iSample]);
        }
        for( int iPlot = 0 ; iPlot < plotsTargetEE.size() ; iPlot++){
            plotsTargetEE[iPlot].addDataNtuple(ntuple,sampleNames[iSample]);
        }
        for( int iPlot = 0 ; iPlot < plotsReferenceEE.size() ; iPlot++){
            plotsReferenceEE[iPlot].addDataNtuple(ntuple,sampleNames[iSample]);
        }
        for( int iPlot = 0 ; iPlot < tarPlotMHTversusHT.size() ; iPlot++){
            tarPlotMHTversusHT[iPlot].addDataNtuple(ntuple,sampleNames[iSample]);
        }
        for( int iPlot = 0 ; iPlot < refPlotMHTversusHT.size() ; iPlot++){
            refPlotMHTversusHT[iPlot].addDataNtuple(ntuple,sampleNames[iSample]);
        }

	vector<int> reference_triggers={67,68,69,70,73,74,75,81,85,89,92,93,94,96,97,100,103,104,105,106,107,108};
	vector<int> target_triggers={/*137,138,139,*/140,141/*,142,143,144,145*/};

        int numEvents = ntuple->fChain->GetEntries();
        ntupleBranchStatus<RA2bTree>(ntuple);
        for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){
            ntuple->GetEntry(iEvt);
            if( iEvt % 1000000 == 0 ) cout << sampleNames[iSample] << ": " << iEvt << "/" << numEvents << endl;

	    bool pass_ref_trigger=false;
	    for( unsigned int  itrig = 0 ; itrig < reference_triggers.size() ; itrig++ ){
	      //cout << "reference trigger: " << reference_triggers[itrig] << " pass: " << int(ntuple->TriggerPass->at(reference_triggers[itrig])==1) << endl;
	      pass_ref_trigger|=(ntuple->TriggerPass->at(reference_triggers[itrig])==1);
	    }
	    //cout << "pass reference trigger?: " << pass_ref_trigger << endl;
	    if( ! pass_ref_trigger ) continue;
	    //cout << "event passing reference triggers" << endl;

	    bool pass_tar_trigger=false;
	    for( unsigned int  itrig = 0 ; itrig < target_triggers.size() ; itrig++ ){
	      //cout << "target trigger: " << target_triggers[itrig] << " pass: " << int(ntuple->TriggerPass->at(target_triggers[itrig])==1) << endl;
	      pass_tar_trigger|=(ntuple->TriggerPass->at(target_triggers[itrig])==1);
	    }
	    //cout << "pass target trigger?: " << pass_tar_trigger << endl;

	    if( !RA2bBaselineWideCut(ntuple) ) continue;

            int HTbin = -1;
            for( int iHT = 0 ; iHT < HTbins-1 ; iHT++ ){
                if( iHT == HTbins-1 ){
                    if( ntuple->HT > HTbinning[iHT] )
                        HTbin = iHT;
                }else if( ntuple->HT > HTbinning[iHT] && ntuple->HT < HTbinning[iHT+1] ) 
                    HTbin = iHT;
            }

            if( HTbin < 0 ) continue;
	    //cout << "HTbin: " << HTbin << endl;
	    
            for( int iPlot = 0 ; iPlot < plotsTarget.size() ; iPlot++ ){
                if( ntuple->Photons_isEB->at(0) ){
		    //cout << "barrel photon" << endl;
                    plotsReferenceEB[iPlot].fillData(ntuple);
                    plotsReference[iPlot].fillData(ntuple);
                    refPlotMHTversusHT[HTbin].fillData(ntuple);
                    if( pass_tar_trigger ){
		        //cout << "pass target trigger" << endl;
                        plotsTarget[iPlot].fillData(ntuple);
                        plotsTargetEB[iPlot].fillData(ntuple);
                        tarPlotMHTversusHT[HTbin].fillData(ntuple);
                    }// end if pass target trigger
                }// if endcap photon
            
                if( !ntuple->Photons_isEB->at(0) ){
		    //cout << "endcap photon" << endl;
                    plotsReferenceEE[iPlot].fillData(ntuple);
                    plotsReference[iPlot].fillData(ntuple);
                    refPlotMHTversusHT[HTbin].fillData(ntuple);
                    if( pass_tar_trigger ){
		        //cout << "pass target trigger" << endl;
                        plotsTarget[iPlot].fillData(ntuple);
                        plotsTargetEE[iPlot].fillData(ntuple);
                        tarPlotMHTversusHT[HTbin].fillData(ntuple);
                    }// end if pass target trigger
                }// if barrel photon
            }// end loop over plots
        }// end loop over events
    }// end loop over samples
  
    TFile* outputFile;
    if( region == 0 )
        outputFile = new TFile("triggerEff_histo.root","RECREATE");
    if( region == 1 )
        outputFile = new TFile("triggerEff_LDP_histo.root","RECREATE");

    for( int iHT = 0 ; iHT < HTbins-1 ; iHT++ ){
        refPlotMHTversusHT[iHT].Write();
        tarPlotMHTversusHT[iHT].Write();
    }

    TCanvas* can = new TCanvas("can","can",500,500);
    for( int iPlot = 0 ; iPlot < plotsTarget.size() ; iPlot++){
        plotsTarget[iPlot].Write();
        plotsReference[iPlot].Write();
        TGraphAsymmErrors* ratio = new TGraphAsymmErrors(plotsTarget[iPlot].dataHist,plotsReference[iPlot].dataHist);
        ratio->SetMarkerStyle(8);
        ratio->GetXaxis()->SetTitle(xlabels[iPlot]);
        ratio->GetXaxis()->SetNdivisions(505);
        ratio->GetYaxis()->SetTitle("#epsilon");
        ratio->GetYaxis()->SetRangeUser(0.,1.0);

        plotsTargetEB[iPlot].Write();
        plotsReferenceEB[iPlot].Write();
        TGraphAsymmErrors* ratioEB = new TGraphAsymmErrors(plotsTargetEB[iPlot].dataHist,plotsReferenceEB[iPlot].dataHist);
        ratioEB->SetMarkerStyle(8);
        ratioEB->SetMarkerColor(2);

        plotsTargetEE[iPlot].Write();
        plotsReferenceEE[iPlot].Write();
        TGraphAsymmErrors* ratioEE = new TGraphAsymmErrors(plotsTargetEE[iPlot].dataHist,plotsReferenceEE[iPlot].dataHist);
        ratioEE->SetMarkerStyle(8);
        ratioEE->SetMarkerColor(4);

        TLegend* leg = new TLegend(.45,.25,.7,.5);
        leg->SetBorderSize(0);
        leg->SetFillColor(0);
        leg->AddEntry(ratioEB,"barrel","p");
        leg->AddEntry(ratioEE,"endcap","p");
        leg->AddEntry(ratio,"inclusive","p");

        can->cd();

        ratio->Draw("Ap");
        ratioEE->Draw("p");
        ratioEB->Draw("p");
        leg->Draw();
        writeExtraText = true;
        extraText = "Preliminary";
        TString lumi_s="";
        lumi_s+=lumi;
        lumi_13TeV = lumi_s;
        CMS_lumi( can , 4 , 0 );
        can->Update();
        //can->RedrawAxis();
        can->GetFrame()->Draw();
        if( region == 0 ){
            can->SaveAs("../plots/triggerEff_plots/"+TString(plotsTarget[iPlot].dataHist->GetName())+".png");
            can->SaveAs("../plots/triggerEff_plots/"+TString(plotsTarget[iPlot].dataHist->GetName())+".eps");
            can->SaveAs("../plots/triggerEff_plots/"+TString(plotsTarget[iPlot].dataHist->GetName())+".pdf");
        }else{
            can->SaveAs("../plots/triggerEff_plots/"+TString(plotsTarget[iPlot].dataHist->GetName())+"_LDP.png");
            can->SaveAs("../plots/triggerEff_plots/"+TString(plotsTarget[iPlot].dataHist->GetName())+"_LDP.eps");
            can->SaveAs("../plots/triggerEff_plots/"+TString(plotsTarget[iPlot].dataHist->GetName())+"_LDP.pdf");
        }


//         cout << " - - - - - - - - - - - - - - - - - - - - - - " << endl;
//         cout << plotsTarget[iPlot].dataHist->GetName() << endl;
//         cout << " - - - - - - - - - - - - - - - - - - - - - - " << endl;        
//         TString heading="Trigger $\\epsilon$[\\%] & ";
//         TString inclEffic="Incl. & ";
//         TString EBeffic="Barrel & ";
//         TString EEeffic="Endcap & ";
//         double x,y;
//         double yEB;
//         double yEE;
//         char temp[128];
//         cout << "Trigger $\\epsilon$[\\%] & Incl. & Barrel & Endcap \\\\ \\hline " << endl;
//         for( int i = 0 ; i < plotsTarget[iPlot].dataHist->GetNbinsX() ; i++ ){
//             ratio->GetPoint(i,x,y);
//             ratioEB->GetPoint(i,x,yEB);
//             ratioEE->GetPoint(i,x,yEE);
//             /*
//               sprintf(temp," %i $<$ %s $<$ %i & ",int(x-ratio->GetErrorXlow(i)),plotsTarget[iPlot].dataHist->GetTitle(),int(x+ratio->GetErrorXhigh(i)));
//               heading+=TString(temp);
//               sprintf(temp," %.3f$_{%.3f}^{%.3f}$ & ",y,ratio->GetErrorYlow(i),ratio->GetErrorYhigh(i));
//               inclEffic+=TString(temp);

//               ratioEB->GetPoint(i,x,y);
//               sprintf(temp," %.3f$_{%.3f}^{%.3f}$ & ",y,ratioEB->GetErrorYlow(i),ratioEB->GetErrorYhigh(i));
//               EBeffic+=TString(temp);

//               ratioEE->GetPoint(i,x,y);
//               sprintf(temp," %.3f$_{%.3f}^{%.3f}$ & ",y,ratioEE->GetErrorYlow(i),ratioEE->GetErrorYhigh(i));
//               EEeffic+=TString(temp);
//             */
//             sprintf(temp," %i $<%s<$ %i & %.3f$_{%.3f}^{%.3f}$ & %.3f$_{%.3f}^{%.3f}$ &%.3f$_{%.3f}^{%.3f}$ \\\\",int(x-ratio->GetErrorXlow(i)),plotsTarget[iPlot].dataHist->GetTitle(),int(x+ratio->GetErrorXhigh(i)),y,ratio->GetErrorYlow(i),ratio->GetErrorYhigh(i),yEB,ratioEB->GetErrorYlow(i),ratioEB->GetErrorYhigh(i),yEE,ratioEE->GetErrorYlow(i),ratioEE->GetErrorYhigh(i)  );
//             cout << temp << endl;
//         }       
	
        //cout << heading << endl;
        //cout << inclEffic << endl;
        //cout << EBeffic << endl;
        //cout << EEeffic << endl;

    }
    outputFile->Close();
}
