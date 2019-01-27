void makeclass()
 {

 TFile *f = new TFile("/eos/uscms/store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV16/tree_GJet_CleanVars/tree_GJets_HT-100to200_MC2017.root");
 TTree *v = (TTree*)f->Get("tree");
 f->ls();

 v->MakeClass("RA2bTree");
 }
