#!/bin/bash

inputDir=$1



#python photonPurityChargedIso.py -s "MHT200_225" -b "MHT_200" -d $inputDir
#python photonPurityChargedIso.py -s "MHT225_250" -b "MHT_225" -d $inputDir

python photonPurityChargedIso.py -s "MHT250_300" -b "MHT_250" -d $inputDir
python photonPurityChargedIso.py -s "MHT300_350" -b "MHT_300" -d $inputDir
python photonPurityChargedIso.py -s "MHT350_500" -b "MHT_350" -d $inputDir
python photonPurityChargedIso.py -s "MHT500" -b "MHT_500" -d $inputDir

#python photonPurityChargedIso.py -e -s "MHT200_225" -b "MHT_200" -d $inputDir
#python photonPurityChargedIso.py -e -s "MHT225_250" -b "MHT_225" -d $inputDir
python photonPurityChargedIso.py -e -s "MHT250_300" -b "MHT_250" -d $inputDir
python photonPurityChargedIso.py -e -s "MHT300_350" -b "MHT_300" -d $inputDir
python photonPurityChargedIso.py -e -s "MHT350_500" -b "MHT_350" -d $inputDir
python photonPurityChargedIso.py -e -s "MHT500" -b "MHT_500" -d $inputDir

python photonPurityChargedIso.py -s "HT250_300" -b "HT_250" -d $inputDir
python photonPurityChargedIso.py -s "HT300_500" -b "HT_300" -d $inputDir
python photonPurityChargedIso.py -s "HT500_800" -b "HT_500" -d $inputDir
python photonPurityChargedIso.py -s "HT800_1500" -b "HT_800" -d $inputDir
python photonPurityChargedIso.py -s "HT1500_3000" -b "HT_1500" -d $inputDir

python photonPurityChargedIso.py -e -s "HT250_300" -b "HT_250" -d $inputDir
python photonPurityChargedIso.py -e -s "HT300_500" -b "HT_300" -d $inputDir
python photonPurityChargedIso.py -e -s "HT500_800" -b "HT_500" -d $inputDir
python photonPurityChargedIso.py -e -s "HT800_1500" -b "HT_800" -d $inputDir
python photonPurityChargedIso.py -e -s "HT1500_3000" -b "HT_1500" -d $inputDir

python photonPurityChargedIso.py -e -s "NJets0p5_1p5" -b "NJets_0.5" -d $inputDir
python photonPurityChargedIso.py -e -s "NJets1p5_2.5" -b "NJets_1.5" -d $inputDir
python photonPurityChargedIso.py -e -s "NJets2p5_3p5" -b "NJets_2.5" -d $inputDir
python photonPurityChargedIso.py -e -s "NJets3p5_5p5" -b "NJets_3.5" -d $inputDir
python photonPurityChargedIso.py -e -s "NJets5p5_7p5" -b "NJets_5.5" -d $inputDir
python photonPurityChargedIso.py -e -s "NJets7p5_15p5" -b "NJets_7.5" -d $inputDir

python photonPurityChargedIso.py -s "NJets0p5_1p5" -b "NJets_0.5" -d $inputDir
python photonPurityChargedIso.py -s "NJets1p5_2.5" -b "NJets_1.5" -d $inputDir
python photonPurityChargedIso.py -s "NJets2p5_3p5" -b "NJets_2.5" -d $inputDir
python photonPurityChargedIso.py -s "NJets3p5_5p5" -b "NJets_3.5" -d $inputDir
python photonPurityChargedIso.py -s "NJets5p5_7p5" -b "NJets_5.5" -d $inputDir
python photonPurityChargedIso.py -s "NJets7p5_15p5" -b "NJets_7.5" -d $inputDir
