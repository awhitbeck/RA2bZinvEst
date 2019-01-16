#!/bin/sh
for file in $(ls *root)
do
    xrdcp -f $file root://cmseos.fnal.gov//store/user/tmishra/RA2bZinvEst/$output_dir/$file
done

cd ../
for file in $(ls plots/*/*)
do 
    xrdcp -f $file root://cmseos.fnal.gov//store/user/tmishra/RA2bZinvEst/$output_dir/$file
done
