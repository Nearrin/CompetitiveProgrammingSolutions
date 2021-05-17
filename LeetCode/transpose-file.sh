# Read from the file file.txt and print its transposed content to stdout.
awk '{for(i=1;i<=NF;++i)table[NR,i]=$i;num_cols=NF;num_rows=NR}END{for(i=1;i<=num_cols;++i){tmp="";for(j=1;j<=NR;++j){if(j!=1)tmp
    =tmp" ";tmp=tmp""table[j,i];}print tmp}}' file.txt
