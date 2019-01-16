#!/bin/bash

newDir=$1

if [ -d /eos/uscms/store/user/$USER/RA2bZinvEst/$newDir ] 
    then
    echo "DIRECTORY ALREADY EXISTS -- I DON'T KNOW HOW TO HANDLE THIS...BYE"
    exit 1
fi

mkdir -p /eos/uscms/store/user/$USER/RA2bZinvEst/$newDir
mkdir -p /eos/uscms/store/user/$USER/RA2bZinvEst/$newDir/plots
plotsDirList="Properties_plots RzGamma_DR0p05_plots RzGamma_plots fragmentationFits plotObs_baseline_plots plotPurityProperties_plots purityFits purityResults triggerEff_plots"
for i in $plotsDirList 
do 
    mkdir -p /eos/uscms/store/user/$USER/RA2bZinvEst/$newDir/plots/$i
done


