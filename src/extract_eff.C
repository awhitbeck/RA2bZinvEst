void extract_eff()
{

// This part extract the function TF1
//
//
/*
TFile *f = new TFile("triggersRa2bRun2_v1_withTEffs.root");

TF1 * f_trig_eb =(TF1 *)f->Get("tf1_SinglePhotonBarrelLoose_hists_Run2017_JetHT");
f_trig_eb->SetName("f_trig_eb");

TF1 *f_trig_ec = (TF1*)f->Get("tf1_SinglePhotonEndcapLoose_hists_Run2017_JetHT");
f_trig_ec->SetName("f_trig_ec");



TFile *fnew = new TFile ("fnew.root","RECREATE");
f_trig_eb ->Write();
f_trig_ec ->Write();



*/
TFile *fnew = new TFile ("fnew.root","UPDATE");

     std::vector<TF1*> fTrigEff_;  // store EB, EC in a vector

     fTrigEff_.push_back((TF1*)fnew->Get("f_trig_eb"));
     if (fTrigEff_.back() == nullptr) {
       cout << "***** Histogram f_trig_eb not found *****" << endl;
     } else {
       cout << "Asymptotic EB trigger efficiency = " << 1 + fTrigEff_[0]->GetParameter(0) << "+/-" << fTrigEff_[0]->GetParError(0) << endl;
     }

     fTrigEff_.push_back((TF1*)fnew->Get("f_trig_ec"));
     if (fTrigEff_.back() == nullptr) {
       cout << "***** Histogram f_trig_ec not found *****" << endl;
     } else {
       cout << "Asymptotic EC trigger efficiency = " << 1 + fTrigEff_[1]->GetParameter(0) << "+/-" << fTrigEff_[1]->GetParError(0) << endl;
     }



}
