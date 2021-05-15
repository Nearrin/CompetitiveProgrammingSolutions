#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
#include<vector>
#include<queue>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
namespace isap{
    struct edge{int v,c;}edges[100010];int nw=1;
    vector<int>bg[1010];
    void add(int u,int v,int c){
        edge&e=edges[++nw];e.v=v;e.c=c;bg[u].push_back(nw);
    }
    int vcnt,dis[1010];
    int dfs(int u,int f){
        if(u==vcnt)return f;
        int g=f;
        lp(i,0,int(bg[u].size()-1)){
            edge&e=edges[bg[u][i]],&ev=edges[bg[u][i]^1];
            if(e.c&&dis[u]==dis[e.v]+1){
                int t=dfs(e.v,min(e.c,g));
                g-=t,e.c-=t,ev.c+=t;
                if(!g)return f;
            }
        }
        ++dis[u];return f-g;
    }
    int solve(){
        int r=0;while(dis[1]<vcnt)r+=dfs(1,~0u>>1);
        return r;
    }
}
namespace mcmf{
    struct edge{int v,c,w;}edges[100010];int nw=1;
    vector<int>bg[1010];
    void add(int u,int v,int c,int w){
        edge&e=edges[++nw];e.v=v;e.c=c;e.w=w;bg[u].push_back(nw);
    }
    int vcnt,dis[1010],in[1010];
    int spfa(){
        lp(i,1,vcnt)dis[i]=~0u>>1,in[i]=0;dis[1]=0;in[1]=1;
        queue<int>qu;qu.push(1);
        while(!qu.empty()){
            int u=qu.front();qu.pop();in[u]=0;
            lp(i,0,int(bg[u].size()-1)){
                edge&e=edges[bg[u][i]];
                if(e.c&&dis[u]+e.w<dis[e.v]){
                    dis[e.v]=dis[u]+e.w;
                    if(!in[e.v]){
                        in[e.v]=1;
                        qu.push(e.v);
                    }
                }
            }
        }
        return dis[vcnt]!=~0u>>1;
    }
    int cst;
    int dfs(int u,int f){
        if(u==vcnt)return f;
        in[u]=1;
        int g=f;
        lp(i,0,int(bg[u].size()-1)){
            edge&e=edges[bg[u][i]],&ev=edges[bg[u][i]^1];
            if(e.c&&dis[u]+e.w==dis[e.v]&&!in[e.v]){
                int t=dfs(e.v,min(g,e.c));
                e.c-=t;g-=t;ev.c+=t;cst+=t*e.w;
                if(!g)return f;
            }
        }
        return f-g;
    }
    int solve(){
        while(spfa()){
            do{
                lp(i,1,vcnt)in[i]=0;
            }while(dfs(1,~0u>>1));
        }
        return cst;
    }
}
int main(){
    int n,m,k;sf("%d%d%d",&n,&m,&k);
    isap::vcnt=n;mcmf::vcnt=n+1;
    lp(i,1,m){
        int u,v,c,w;sf("%d%d%d%d",&u,&v,&c,&w);
        isap::add(u,v,c);isap::add(v,u,0);
        mcmf::add(u+1,v+1,c,0);mcmf::add(v+1,u+1,0,0);
        mcmf::add(u+1,v+1,~0u>>1,w);mcmf::add(v+1,u+1,0,-w);
    }
    int t=isap::solve();
    mcmf::add(1,2,t+k,0);
    mcmf::add(2,1,0,0);
    pf("%d %d\n",t,mcmf::solve());
    //ps;
    return 0;
}
