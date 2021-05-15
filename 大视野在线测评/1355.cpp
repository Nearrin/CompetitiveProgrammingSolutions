#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
#include<cstring>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
char A[1000010];int L,P[1000010];
int main(){
    sf("%d%s",&L,A+1);
    P[1]=0;
    for(int i=2,j=0;i<=L;++i){
        while(j&&A[j+1]!=A[i])j=P[j];
        if(A[j+1]==A[i])++j;
        P[i]=j;
    }
    pf("%d\n",L-P[L]);
    //ps;
    return 0;
}
