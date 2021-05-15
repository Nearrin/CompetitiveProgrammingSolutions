#include<cstdio>
#include<algorithm>
#include<vector>
#define sf scanf
#define pf printf
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
vector<int>to[500010];int n;
int bg[500010],ed[500010],tim;
int vis[500010],stk[500010*2];
int at[500010];
void init(){
    sf("%d",&n);lp(i,1,n)sf("%d",&at[i]);
    lp(i,1,n-1){
        int u,v;sf("%d%d",&u,&v);
        to[u].push_back(v);
        to[v].push_back(u);
    }
}
int up[500010][21],dep[500010];
void dfs(){
    stk[0]=2;stk[1]=1;stk[2]=1;vis[1]=1;
    while(stk[0]){
        int u=stk[stk[0]--],t=stk[stk[0]--];
        lp(i,1,20)up[u][i]=up[up[u][i-1]][i-1];
        if(t==1){
            //pf("[%d]",u);
            bg[u]=++tim;
            stk[++stk[0]]=2;stk[++stk[0]]=u;
            lp(i,0,int(to[u].size()-1)){
                int v=to[u][i];
                if(!vis[v]){
                    vis[v]=1;up[v][0]=u;dep[v]=dep[u]+1;
                    stk[++stk[0]]=1;stk[++stk[0]]=v;
                }
            }
        }else{
            ed[u]=tim;
        }
    }
}
int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    for(int i=0;i<=20;++i)if(((dep[x]-dep[y])>>i)&1)x=up[x][i];
    if(x==y)return x;
    for(int i=20;i>=0;--i)
        if(up[x][i]!=up[y][i])
            x=up[x][i],y=up[y][i];
    return up[x][0];
}
int bd[500010];
void add(int x,int d){for(;x<=n;x+=x&-x)bd[x]^=d;}
int qu(int x){
    int r=0;
    for(;x;x-=x&-x)r^=bd[x];
    return r;
}
int qu2(int x){
    return qu(bg[x]);
}
void ans(){
    //pf("hi");
    lp(i,1,n)add(ed[i]+1,at[i]),add(bg[i],at[i]);
    int q;sf("%d",&q);
    lp(i,1,q){
        int u,v;
        char op[11];sf("%s%d%d",op,&u,&v);
        if(op[0]=='Q'){
            int z=lca(u,v);
            int t=(qu2(u)^qu2(v)^qu2(z));
            //pf("[%d,%d]",v,qu2(v));
            if(up[z][0]!=0)t^=qu2(up[z][0]);
            if(!t)pf("No\n");else pf("Yes\n");
        }else{
            add(ed[u]+1,at[u]),add(bg[u],at[u]);
            at[u]=v;
            add(ed[u]+1,at[u]),add(bg[u],at[u]);
        }
    }
}
int main(){
    init();
    dfs();
    //lp(i,1,n)pf("[%d,%d]",bg[i],ed[i]);
    //lp(i,1,n)lp(j,1,n)pf("[%d,%d,%d]\n",i,j,lca(i,j));
    ans();
    //ps;
    return 0;
}
