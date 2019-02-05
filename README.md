# RA2bZinvEst
# Setup CMS environment:

cmsrel CMSSW_9_4_6
cd CMSSW_9_4_6/src/
cmsenv

Checkout code:

git clone https://github.com/tmishra2018/RA2bZinvEst
cd RA2bZinvEst
git checkout RA2b_V16_2016

Setup local environment:

source setup.csh
voms-proxy-init -voms cms

Build executables:

cd src/
make all

Submit jobs:

bash makeTar.sh
bash submitBatch.sh RA2b_V16_2016
