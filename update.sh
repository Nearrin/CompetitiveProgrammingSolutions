#!/bin/zsh
cd $(git rev-parse --show-toplevel)
echo "# Number of Problems Solved\nThe table below is a rough estimate based on the code I have saved from multiple accounts I have." >README.md
echo "|Platform|Number|\n|---|---|" >>README.md
ls -d */* | grep '\.' | cut -d/ -f1 | sort | uniq -c | sort -k1nr | awk '{c=$1;$1="";print "|"substr($0,2)"|"c"|"}' >>README.md
echo "|Total|"$(ls -d */* | grep '\.' | wc -l)"|" | sed s@' '@@g >>README.md
git add *
git commit -m 'Updated.'
git push
