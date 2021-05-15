#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<vector>
#define sf scanf
#define pf printf
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
vector<int> chd[100010];
int n,m,ci[100010],li[100010];
int lchd[100010],rchd[100010],val[100010],siz[100010],now,dist[100010]={-1};
long long sum[100010],ans;
int make(int v){
    int x=++now;
    val[x]=v;siz[x]=1;sum[x]=v;
    return x;
}
int link(int x,int y){
    if(!x)return y;
    if(!y)return x;
    if(val[x]<val[y])swap(x,y);
    rchd[x]=link(rchd[x],y);
    if(dist[lchd[x]]<dist[rchd[x]])swap(lchd[x],rchd[x]);
    siz[x]=siz[rchd[x]]+siz[lchd[x]]+1;
    sum[x]=sum[rchd[x]]+sum[lchd[x]]+val[x];
    dist[x]=dist[rchd[x]]+1;
    return x;
}
int calc(int u){
    int t=make(ci[u]);
    lp(i,0,int(chd[u].size())-1)
        t=link(t,calc(chd[u][i]));
    while(sum[t]>m)t=link(lchd[t],rchd[t]);
    ans=max(ans,(long long)siz[t]*li[u]);
    return t;
}
int main(){
    sf("%d%d",&n,&m);
    lp(i,1,n){
        int b;sf("%d%d%d",&b,&ci[i],&li[i]);
        chd[b].push_back(i);
    }
    calc(1);
    cout<<ans<<endl;
    //while(1);
    return 0;
}
