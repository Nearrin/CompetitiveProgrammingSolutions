#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#define sf scanf
#define pf printf
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int A[50010],F[50010][20],G[50010][20],N;
void init(){
    lp(i,1,N)F[i][0]=A[i];
    lp(i,1,N)G[i][0]=A[i];
    for(int j=1;(1<<j)<=N;++j)
        for(int i=1;i+(1<<j)-1<=N;++i)
            F[i][j]=min(F[i][j-1],F[i+(1<<(j-1))][j-1]),
            G[i][j]=max(G[i][j-1],G[i+(1<<(j-1))][j-1]);
}
int rmq(int l,int r){
    int k=0;
    while((1<<(k+1))<=r-l+1)++k;
    //int k=log((r-l+1)*1.0)/log(2.0);
    return max(G[l][k],G[r-(1<<k)+1][k])-min(F[l][k],F[r-(1<<k)+1][k]);
}
int main(){
    //freopen("lineup.in","r",stdin);
    //freopen("lineup.out","w",stdout);
    int q;
    sf("%d%d",&N,&q);
    lp(i,1,N)sf("%d",&A[i]);
    init();
    lp(i,1,q){
        int a,b;sf("%d%d",&a,&b);
        pf("%d\n",rmq(a,b));
    }
    //ps;
    return 0;
}
