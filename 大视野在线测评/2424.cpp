#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
struct edge{int v,c,w;}edges[200010];int nw=1;
vector<int>to[1010];int vcnt;
void add(int u,int v,int c,int w){
    edge&e=edges[++nw];
    e.v=v,e.c=c,e.w=w;
    to[u].push_back(nw);
}
int dis[1010],in[1010],cst;
int spfa(){
    dis[1]=0;lp(i,2,vcnt)dis[i]=~0u>>2;
    in[1]=1;lp(i,2,vcnt)in[i]=0;
    queue<int>qu;qu.push(1);
    while(!qu.empty()){
        int u=qu.front();qu.pop();in[u]=0;
        lp(i,0,int(to[u].size()-1)){
            edge&e=edges[to[u][i]];
            if(e.c&&dis[u]+e.w<dis[e.v]){
                dis[e.v]=dis[u]+e.w;
                if(!in[e.v]){
                    in[e.v]=1;
                    qu.push(e.v);
                }
            }
        }
    }
    return dis[vcnt]!=~0u>>2;
}
int dfs(int u,int f){
    if(u==vcnt)return f;
    in[u]=1;
    int g=f;
    lp(i,0,int(to[u].size()-1)){
        edge&e=edges[to[u][i]];
        if(e.c&&!in[e.v]&&dis[u]+e.w==dis[e.v]){
            int t=dfs(e.v,min(g,e.c));
            e.c-=t,edges[to[u][i]^1].c+=t,g-=t;
            cst+=t*e.w;
            if(!g)return f;
        }
    }
    return f-g;
}
void mcmf(){
    while(spfa()){do{lp(i,1,vcnt)in[i]=0;}while(dfs(1,~0u>>2));}
}
int n,m,s,uu[110],dd[110];
int main(){
    sf("%d%d%d",&n,&m,&s);
    lp(i,1,n)sf("%d",&uu[i]);
    lp(i,1,n)sf("%d",&dd[i]);
    vcnt=2*n+2;
    lp(i,1,n)add(1,i*2,~0u>>2,dd[i]),add(i*2,1,0,-dd[i]);
    lp(i,1,n)add(i*2+1,2*n+2,uu[i],0),add(2*n+2,i*2+1,0,0);
    lp(i,1,n)add(i*2,i*2+1,~0u>>2,0),add(i*2+1,i*2,0,0);
    lp(i,1,n-1)add(i*2+1,(i+1)*2,s,m),add((i+1)*2,i*2+1,0,-m);
    mcmf();
    pf("%d\n",cst);//ps;
    return 0;
}
