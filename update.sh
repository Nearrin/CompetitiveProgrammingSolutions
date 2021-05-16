#!/bin/zsh
cd $(git rev-parse --show-toplevel)
echo "# Number of Problems Solved\nThe table below is a rough estimate based on the code I save." >>README.md
ls -d */* | grep '\.' | cut -d/ -f1 | sort | uniq -c | sort -k1nr | awk 'NR==1{print "|Platform|Number|\n|---|---|"}{c=$1;$1="";print "|"substr($0,2)"|"c"|"}' >>README.md
git add *
git commit -m 'Updated.'
git push
