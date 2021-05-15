#include<cstdio>
#include<algorithm>
#include<vector>
#define sf scanf
#define pf printf
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int w[1000010],h[1000010],v[1000010],n;
vector<int>b[1000010];
long long dp[1000010][2];
int qu1[1000010],qu2[1000010],qu3[1000010],qu3f,qu3b;
void tree(int x){
    qu2[0]=0;
    qu3f=1,qu3b=2;qu3[1]=x;
    while(qu3f!=qu3b){
        int u=qu3[qu3f++];if(qu3f>1000005)qu3f=1;
        qu2[++qu2[0]]=u;
        lp(i,0,int(b[u].size()-1)){
            if(v[b[u][i]])continue;
            qu3[qu3b++]=b[u][i];
            if(qu3b>1000005)qu3b=1;
        }
    }
    for(int i=qu2[0];i;--i){
        int u=qu2[i];
        dp[u][0]=0;dp[u][1]=w[u];
        lp(j,0,int(b[u].size()-1)){
            if(v[b[u][j]])continue;
            dp[u][0]+=max(dp[b[u][j]][0],dp[b[u][j]][1]);
            dp[u][1]+=dp[b[u][j]][0];
        }
    }
    lp(i,1,qu2[0])v[qu2[i]]=1;
} 
int main(){
    sf("%d",&n);
    lp(i,1,n){
        sf("%d%d",&w[i],&h[i]);
        b[h[i]].push_back(i);
    }
    long long ans=0;
    lp(i,1,n)if(!v[i]){
        int t=i;v[t]=1;
        while(!v[h[t]])v[h[t]]=1,t=h[t];t=h[t];
        for(int j=i;j!=t;j=h[j])v[j]=0;
        qu1[0]=0;qu1[++qu1[0]]=t;
        for(int j=h[t];j!=t;j=h[j])qu1[++qu1[0]]=j;
        lp(j,1,qu1[0])tree(qu1[j]);
        long long f0=0,f1=0,tc=0;
        for(int j=2;j<=qu1[0];++j){
            long long g0=max(f0,f1)+dp[qu1[j]][0],g1=f0+dp[qu1[j]][1];
            f0=g0;f1=g1;
        }
        tc=max(f0,f1)+dp[qu1[1]][0];
        f0=0,f1=0;
        for(int j=1;j<=qu1[0]-1;++j){
            long long g0=max(f0,f1)+dp[qu1[j]][0],g1=f0+dp[qu1[j]][1];
            f0=g0;f1=g1;
        }
        tc=max(tc,max(f0,f1)+dp[qu1[qu1[0]]][0]);
        ans+=tc;
    }
    pf("%lld\n",ans);
    //ps;
    return 0;
}
