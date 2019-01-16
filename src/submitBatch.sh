#!/bin/bash

submitDir=$PWD
branch=$1
hash=`git rev-parse origin/${branch}`
CMSSW=`echo $CMSSW_BASE | awk -F '/' '{print $NF}'`
echo $CMSSW
echo "hash ${hash}"               # this is intended to correspond to the hash of your git commit for tracking/reproducibility
                                  # -- you can get the hash with `git rev-parse origin/RA2b_V12_v0`
source makeOutputDir.sh $hash     # setup directories in eos for output
source makeTar.sh                 # package up code to transfer to worker nodes
cd $submitDir
condor_submit batchExecute.jdl exec_name="cutFlow" arguments="${hash} cutFlow ${CMSSW}"
condor_submit batchExecute.jdl exec_name="plotObs_baseline_2" arguments="${hash} plotObs_baseline ${CMSSW} 2"
condor_submit batchExecute.jdl exec_name="plotObs_baseline_4" arguments="${hash} plotObs_baseline ${CMSSW} 4"
condor_submit batchExecute.jdl exec_name="plotRzGamma_0" arguments="${hash} plotRzGamma ${CMSSW} 0"
condor_submit batchExecute.jdl exec_name="plotRzGamma_1" arguments="${hash} plotRzGamma ${CMSSW} 1"
condor_submit batchExecute.jdl exec_name="plotPurityProperties_3" arguments="${hash} plotPurityProperties ${CMSSW} 3"
condor_submit batchExecute.jdl exec_name="plotPurityProperties_5" arguments="${hash} plotPurityProperties ${CMSSW} 5"
condor_submit batchExecute.jdl exec_name="triggerEffInputs_0" arguments="${hash} triggerEffInputs ${CMSSW} 0"
condor_submit batchExecute.jdl exec_name="triggerEffInputs_1" arguments="${hash} triggerEffInputs ${CMSSW} 1"
condor_submit batchExecute.jdl exec_name="photonNbExtrapolation" arguments="${hash} photonNbExtrapolation ${CMSSW}"
condor_submit batchExecute.jdl exec_name="fragmentationFits_2" arguments="${hash} fragmentationFits ${CMSSW} 2"
condor_submit batchExecute.jdl exec_name="fragmentationFits_4" arguments="${hash} fragmentationFits ${CMSSW} 4"
condor_submit batchExecute.jdl exec_name="triggerUncertainties_0" arguments="${hash} triggerUncertainties ${CMSSW} 0"
condor_submit batchExecute.jdl exec_name="triggerUncertainties_1" arguments="${hash} triggerUncertainties ${CMSSW} 1"
