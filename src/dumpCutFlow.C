


void dumpCutFlow(TString input_file_name="cutFlow_synchTroy.root"){

  TFile* fin = new TFile(input_file_name,"READ");
  if (!fin->IsOpen()) {
    cout << "[[ERROR]] Cannot open input file " << input_file_name << endl;
    exit(1);
  }

  TList* list = fin->GetListOfKeys() ;
  if (!list) { printf("<E> No keys found in file\n") ; exit(1) ; }
  TIter next(list) ;
  TKey* key ;
  TObject* obj ;

  key  = (TKey*)next();
  while ( key ){
    obj = key->ReadObj() ;
    if ( !obj->InheritsFrom("TH2") ) {
      TH1F* temp = (TH1F*)obj;
      cout << temp->GetName() << endl;
      cout << temp->Integral() << endl;
    }
    key = (TKey*)next();
  }

}
