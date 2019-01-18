CC=g++
CFLAGS=
LIBS=`root-config --cflags --glibs` -L $(ROOTSYS)/lib
INCLUDES=-I$(CMSSW_BASE)/src/
EXECS=plotObs_baseline plotRzGamma cutFlow 
$(EXECS):RA2bTree.cc definitions.h skimSamples.cc plotterUtils.cc cutFlow.cc
plotObs_baseline: plotObs_baseline.cc
plotRzGamma:plotRzGamma.cc CMS_lumi.h CMS_lumi.cc

all:$(EXECS)

plotRzGamma:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotRzGamma.cc -o ../bin/$@
plotObs_baseline:
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) plotObs_baseline.cc -o ../bin/$@

clean : 
	rm ../bin/*
