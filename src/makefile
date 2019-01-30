CC=`root-config --cxx --cflags`
CFLAGS=`root-config --cflags`
LIBS=`root-config --glibs`
INCLUDES= #-I$(ROOTSYS)/include
EXECS=plotObs_baseline plotObs_weightGJets plotRzGamma triggerEffInputs plotPurityProperties triggerUncertainties cutFlow fragmentationFits photonNbExtrapolation
$(EXECS):RA2bTree.cc definitions.h skimSamples.cc plotterUtils.cc 
plotObs_baseline: plotObs_baseline.cc
plotObs_weightGJets: plotObs_weightGJets.cc
plotRzGamma:plotRzGamma.cc CMS_lumi.h CMS_lumi.cc
triggerEffInputs:triggerEffInputs.cc  
plotPurityProperties:plotPurityProperties.cc  
triggerUncertainties:triggerUncertainties.cc 
photonNbExtrapolation:photonNbExtrapolation.cc  
cutFlow:cutFlow.cc  
fragmentationFits:fragmentationFits.cc  

all:$(EXECS)

cutFlow:
	$(CC) $(CFLAGS) cutFlow.cc -o ../bin/$@                  $(LIBS) $(INCLUDES) 
fragmentationFits:						                     
	$(CC) $(CFLAGS) fragmentationFits.cc -o ../bin/$@	 $(LIBS) $(INCLUDES) 
photonNbExtrapolation:						                     
	$(CC) $(CFLAGS) photonNbExtrapolation.cc -o ../bin/$@	 $(LIBS) $(INCLUDES) 
triggerUncertainties:						                     
	$(CC) $(CFLAGS) triggerUncertainties.cc -o ../bin/$@	 $(LIBS) $(INCLUDES) 
plotPurityProperties:						                     
	$(CC) $(CFLAGS) plotPurityProperties.cc -o ../bin/$@	 $(LIBS) $(INCLUDES) 
triggerEffInputs:						                     
	$(CC) $(CFLAGS) triggerEffInputs.cc -o ../bin/$@	 $(LIBS) $(INCLUDES) 
plotRzGamma:							                     
	$(CC) $(CFLAGS) plotRzGamma.cc -o ../bin/$@		 $(LIBS) $(INCLUDES) 
plotObs_baseline:						                     
	$(CC) $(CFLAGS) plotObs_baseline.cc -o ../bin/$@	 $(LIBS) $(INCLUDES) 
plotObs_weightGJets:						                     
	$(CC) $(CFLAGS) plotObs_weightGJets.cc -o ../bin/$@	 $(LIBS) $(INCLUDES) 

clean : 
	rm ../bin/*
