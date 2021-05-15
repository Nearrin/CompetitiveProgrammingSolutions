#include<cstdio>
#include<algorithm>
#include<vector>
#define sf scanf
#define pf printf
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
vector<int> to[30010];int wei[30010],n;
int dep[30010],siz[30010],pr[30010],len[30010],tp[30010],ch[30010];
int sum[30010],mxx[30010];
void dfs(int x,int p){
    pr[x]=p;dep[x]=dep[p]+1;siz[x]=1;
    lp(i,0,int(to[x].size()-1)){ 
        int y=to[x][i]; 
        if(y!=p){
            dfs(y,x),siz[x]+=siz[y];
            if(siz[y]>siz[ch[x]])ch[x]=y;
        }
    } 
}
void build(int x,int t){
    if(x==t)mxx[t]=-(~0u>>2);
    tp[x]=t,++len[t];sum[t]+=wei[x];mxx[t]=max(mxx[t],wei[x]);
    if(len[t]<300&&ch[x])build(ch[x],t);
    else ch[x]=0;
    lp(i,0,int(to[x].size()-1)){ 
        int y=to[x][i]; 
        if(y!=pr[x]&&y!=ch[x])build(y,y);
    }
}
void modify(int x,int w){
    sum[tp[x]]+=-wei[x]+w;int t=wei[x];wei[x]=w;
    if(mxx[tp[x]]==t){
        if(w>t)mxx[tp[x]]=w;
        else{
            mxx[tp[x]]=-(~0u>>2); 
            for(int y=tp[x];y;y=ch[y])mxx[tp[x]]=max(mxx[tp[x]],wei[y]);
        }
    }else if(w>mxx[tp[x]])mxx[tp[x]]=w;
}
int qmax(int x,int y){
    int r=-(~0u>>2);
    while(tp[x]!=tp[y]){
        if(dep[tp[x]]>dep[tp[y]])swap(x,y);
        if(ch[y]==0)r=max(r,mxx[tp[y]]);
        else for(int z=y;z!=pr[tp[y]];z=pr[z])r=max(r,wei[z]);
        y=pr[tp[y]];
    }
    if(dep[x]>dep[y])swap(x,y);
    for(int z=x;z!=ch[y];z=ch[z])r=max(r,wei[z]);
    return r; 
}
int qsum(int x,int y){
    int r=0;
    while(tp[x]!=tp[y]){
        if(dep[tp[x]]>dep[tp[y]])swap(x,y);
        if(ch[y]==0)r+=sum[tp[y]];
        else for(int z=y;z!=pr[tp[y]];z=pr[z])r+=wei[z];
        y=pr[tp[y]];
    }
    if(dep[x]>dep[y])swap(x,y);
    for(int z=x;z!=ch[y];z=ch[z])r+=wei[z];
    return r; 
}
int main(){
    sf("%d",&n);
    lp(i,1,n-1){
        int u,v;sf("%d%d",&u,&v);
        to[u].push_back(v);to[v].push_back(u);
    }
    lp(i,1,n)sf("%d",&wei[i]);
    dfs(1,0);build(1,1);
    int q;sf("%d",&q);
    lp(i,1,q){
        char op[20];int u,v;
        sf("%s",op);sf("%d%d",&u,&v);
        if(op[1]=='H')modify(u,v);
        else if(op[1]=='M')pf("%d\n",qmax(u,v));
        else pf("%d\n",qsum(u,v));
    }//ps;
    return 0;
}
