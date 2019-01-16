#!/bin/bash

cd $CMSSW_BASE/../
CMSSW=`echo $CMSSW_BASE | awk -F '/' '{print $NF}'`
tar -cf workingArea.tar $CMSSW --exclude='*.dag.*' --exclude='*tar' --exclude='${CMSSW}/RA2bZinvEst/src/*root' --exclude='*eps' --exclude='*png' --exclude='*pdf' --exclude='*stdout' --exclude='*stderr' --exclude='*condor' --exclude='${CMSSW}/RA2bZinvEst/bin/*'
mv workingArea.tar ${CMSSW}/src/RA2bZinvEst/src/.