#!/bin/zsh
cd `git rev-parse --show-toplevel`
echo "# Number of Problems Solved">README.md
ls -d */*|grep '\.'|cut -d/ -f1|sort|uniq -c|sort -k1nr|awk 'NR==1{print "|Platform|Number|\n|---|---|"}{print "|"$2"|"$1"|"}'>>README.md
git add *
git commit -m 'Updated.'
git push