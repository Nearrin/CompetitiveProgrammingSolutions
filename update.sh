#!/bin/zsh
cd $(git rev-parse --show-toplevel)
echo "# Competitive Programming Solutions\nThe table below is a rough estimate of number of problems solved based on the code I have saved from multiple accounts I have. Some pieces of code are probably written back in 2012, when things are pretty different. I am never really great at competitive programming. The best I've ever got is a bronze medal in National Olympiad in Informatics, China, but it's pretty much similar to a souls-like game, where you suffer, learn and enjoy." >README.md
echo "|Platform|Number|\n|---|---|" >>README.md
ls -d */* | grep '\.' | cut -d/ -f1 | sort | uniq -c | sort -k1nr | awk '{c=$1;$1="";print "|"substr($0,2)"|"c"|"}' >>README.md
echo "|Total|"$(ls -d */* | grep '\.' | wc -l)"|" | sed s@' '@@g >>README.md
echo "\n|Language|Number|\n|---|---|" >>README.md
ls -d */* | grep '\.' | cut -d. -f2 | sort | uniq -c | sort -k1nr | awk '$2=="cpp"{$2="CPP"}$2=="py"{$2="Python"}$2=="sql"{$2="SQL"}$2=="sh"{$2="Linux Shell"}$2=="go"{$2="Go"}{print "|"$2"|"$1"|"}' >>README.md
echo "|Total|"$(ls -d */* | grep '\.' | wc -l)"|" | sed s@' '@@g >>README.md
git add -A
git commit -m 'Updated.'
git push
