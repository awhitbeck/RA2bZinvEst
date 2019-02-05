# RA2bZinvEst
RA2bZinvEst
Setup CMS environment:

cmsrel CMSSW_8_1_0_pre9
cd CMSSW_8_1_0_pre9/src/
cmsenv

Checkout code:

git clone https://github.com/awhitbeck/RA2bZinvEst
cd RA2bZinvEst
git checkout RA2b_V12_v0.1.2

Setup local environment:

source setup.csh
voms-proxy-init -voms cms

Build executables:

cd src/
make all

Submit jobs:

bash makeTar.sh
bash submitBatch.sh RA2b_V12_v0.1.2
