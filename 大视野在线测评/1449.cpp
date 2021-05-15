#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<queue>
#include<utility>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
namespace mcmf{
    struct edge{
        int v,c,w;
    };
    vector<edge>eg;
    vector<int>bg[10010];
    int vcnt,dis[10010],vis[10010];
    void add(int u,int v,int c,int w){
        edge t;t.v=v;t.c=c;t.w=w;
        bg[u].push_back(eg.size());
        eg.push_back(t);
    }
    int cst;
    bool spfa(){
        lp(i,1,vcnt)dis[i]=~0u>>1,vis[i]=0;
        dis[1]=0;vis[1]=1;
        queue<int>qu;qu.push(1);
        while(!qu.empty()){
            int u=qu.front();qu.pop();vis[u]=0;
            lp(i,0,int(bg[u].size()-1)){
                edge e=eg[bg[u][i]];
                if(e.c&&dis[u]+e.w<dis[e.v]){
                    dis[e.v]=dis[u]+e.w;
                    if(!vis[e.v]){
                        vis[e.v]=1;
                        qu.push(e.v);
                    }
                }
            }
        }
        return dis[vcnt]!=~0u>>1;
    }
    int dfs(int u,int f){
        if(u==vcnt)return f;
        int g=f;
        vis[u]=1;
        lp(i,0,int(bg[u].size()-1)){
            edge&e=eg[bg[u][i]],&ev=eg[bg[u][i]^1];
            if(e.c&&!vis[e.v]&&dis[u]+e.w==dis[e.v]){
                int t=dfs(e.v,min(e.c,g));
                e.c-=t,ev.c+=t,g-=t;cst+=t*e.w;
                if(!g)return f; 
            }
        }
        return f-g;
    }
    int solve(){
        while(spfa()){lp(i,1,vcnt)vis[i]=0;dfs(1,~0u>>1);}
        return cst;
    }
}
int n,m,all[5010],win[5010],lose[5010],dd[5010],cc[5010];
int px[1010],py[1010];
// 1 source
// 1 + 1 -> 1 + m conest
// 1 + m + 1-> 1+ m+ n team
// m+n+2 sink 
int main(){
    sf("%d%d",&n,&m);
    lp(i,1,n)sf("%d%d%d%d",&win[i],&lose[i],&cc[i],&dd[i]),all[i]+=win[i]+lose[i];
    lp(i,1,m)sf("%d%d",&px[i],&py[i]),++all[px[i]],++all[py[i]];
    mcmf::vcnt=n+m+2;
    lp(i,1,n)lp(j,win[i]+1,all[i]){ 
        int c=(cc[i]*j*j+dd[i]*(all[i]-j)*(all[i]-j))-(cc[i]*(j-1)*(j-1)+dd[i]*(all[i]-(j-1))*(all[i]-(j-1)));
        mcmf::add(1+m+i,m+n+2,1,c);
        mcmf::add(m+n+2,1+m+i,0,-c);
    } 
    lp(i,1,m){
        mcmf::add(1,1+i,1,0);
        mcmf::add(1+i,1,0,0);
        mcmf::add(1+i,px[i]+m+1,1,0);
        mcmf::add(px[i]+m+1,1+i,0,0);
        mcmf::add(1+i,py[i]+m+1,1,0);
        mcmf::add(py[i]+m+1,1+i,0,0);
    }
    int ans=mcmf::solve();
    lp(i,1,n)ans+=cc[i]*win[i]*win[i]+dd[i]*(all[i]-win[i])*(all[i]-win[i]);
    pf("%d\n",ans);
    //ps;
    return 0;
}
