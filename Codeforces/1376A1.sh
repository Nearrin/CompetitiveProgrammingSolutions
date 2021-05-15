cat sort.in|tr ' ' '\n'|awk 'NR>1'|sort -n|tr '\n' ' '>sort.out
