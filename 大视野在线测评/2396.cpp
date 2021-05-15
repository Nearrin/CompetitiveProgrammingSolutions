#include<cstdio>
#include<algorithm>
#include<queue>
#include<map>
#include<iostream>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long ll;
ll A[1010][1010],B[1010][1010],C[1010][1010],D[1010];
ll Ans1[1010],Ans2[1010],Ans3[1010],N;
int main(){
    while(sf("%lld",&N)!=EOF){
        lp(i,1,N)lp(j,1,N)sf("%lld",&A[i][j]);
        lp(i,1,N)lp(j,1,N)sf("%lld",&B[i][j]);
        lp(i,1,N)lp(j,1,N)sf("%lld",&C[i][j]);
        lp(i,1,N)D[i]=i;
        lp(i,1,N)lp(j,1,N)Ans1[i]+=B[i][j]*D[j];
        lp(i,1,N)lp(j,1,N)Ans2[i]+=A[i][j]*Ans1[j];
        lp(i,1,N)lp(j,1,N)Ans3[i]+=C[i][j]*D[j];
        int f=1;lp(i,1,N)if(Ans2[i]!=Ans3[i])f=0;
        pf("%s\n",f?"Yes":"No");
    }//ps;
    return 0;
}
