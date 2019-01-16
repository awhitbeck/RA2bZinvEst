#!/bin/bash
output_dir=$1
executable=$2
cmssw=$3
args=$4
echo "output_dir ${output_dir}"
echo "executable ${executable}"
echo "cmssw ${cmssw}"
echo "args ${args}"

mv ../../workingArea.tar .
tar -xf workingArea.tar
cd ${cmssw}/src/
eval `scramv1 runtime -sh`
echo "step 2"
cd RA2bZinvEst
source setup.sh
export PATH=$PWD/bin/:$PATH
echo "PWD ${PWD}"
echo "PATH ${PATH}"
cd src
make all

`echo $executable $args`

for file in $(ls *root)
do
    xrdcp -f $file root://cmseos.fnal.gov//store/user/tmishra/RA2bZinvEst/$output_dir/$file
done

cd ../
for file in $(ls plots/*/*)
do 
    xrdcp -f $file root://cmseos.fnal.gov//store/user/tmishra/RA2bZinvEst/$output_dir/$file
done
