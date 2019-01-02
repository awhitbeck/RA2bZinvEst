CC=g++
CFLAGS=
LIBS=`root-config --cflags --glibs` -Wl,-rpath,$(ROOTSYS)/lib
INCLUDES=-I$(CMSSW_BASE)/src/
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
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) cutFlow.cc -o ../bin/$@
fragmentationFits:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) fragmentationFits.cc -o ../bin/$@
photonNbExtrapolation:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) photonNbExtrapolation.cc -o ../bin/$@
triggerUncertainties:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) triggerUncertainties.cc -o ../bin/$@
plotPurityProperties:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotPurityProperties.cc -o ../bin/$@
triggerEffInputs:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) triggerEffInputs.cc -o ../bin/$@
plotRzGamma:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotRzGamma.cc -o ../bin/$@
plotObs_baseline:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_baseline.cc -o ../bin/$@
plotObs_weightGJets:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_weightGJets.cc -o ../bin/$@

clean : 
	rm ../bin/*