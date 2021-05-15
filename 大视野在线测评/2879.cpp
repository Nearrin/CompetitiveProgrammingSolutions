#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
struct edge{int v,c,w;}edges[2000010];int nw=1;
vector<int>to[100010];int vcnt;
void add(int u,int v,int c,int w){
    edge&e=edges[++nw];
    e.v=v,e.c=c,e.w=w;
    to[u].push_back(nw);
}
int tim[110][110],n,m;
int dis[100010],in[100010],cst;
int spfa(){
    dis[1]=0;lp(i,2,vcnt)dis[i]=~0u>>2;
    in[1]=1;lp(i,2,vcnt)in[i]=0;
    deque<int>qu;qu.push_back(1);
    while(!qu.empty()){
        int u=qu.front();qu.pop_front();in[u]=0;
        lp(i,0,int(to[u].size()-1)){
            edge&e=edges[to[u][i]];
            if(e.c&&dis[u]+e.w<dis[e.v]){
                dis[e.v]=dis[u]+e.w;
                if(!in[e.v]){
                    in[e.v]=1;
                    if(!qu.empty()&&dis[e.v]<dis[qu.front()])
                        qu.push_front(e.v);
                    else
                        qu.push_back(e.v);
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
int cnt[110]; int s=0;
int now[110],nowe[110];
void mcmf(){
    while(spfa()){
        do{lp(i,1,vcnt)in[i]=0;}while(dfs(1,~0u>>2));
        lp(j,1,m)if(!edges[nowe[j]].c){
            int k=++now[j];
            lp(i,1,n){
                add(i+1,n+1+(j-1)*s+k,1,k*tim[i][j]);
                add(n+1+(j-1)*s+k,i+1,0,-k*tim[i][j]);
            }
            add(n+1+(j-1)*s+k,s*m+n+2,1,0),now[j]=k,nowe[j]=nw,add(s*m+n+2,n+1+(j-1)*s+k,0,0);
        }
    }
}
int main(){
    sf("%d%d",&n,&m);
    lp(i,1,n)sf("%d",&cnt[i]),s+=cnt[i];
    lp(i,1,n)lp(j,1,m)sf("%d",&tim[i][j]);
    lp(i,1,n)lp(j,1,m)lp(k,1,1)
        add(i+1,n+1+(j-1)*s+k,1,k*tim[i][j]),
        add(n+1+(j-1)*s+k,i+1,0,-k*tim[i][j]);
    lp(i,1,n)add(1,i+1,cnt[i],0),add(i+1,1,0,0);
    lp(i,1,m)lp(j,1,1)add(n+1+(i-1)*s+j,s*m+n+2,1,0),now[i]=1,nowe[i]=nw,add(s*m+n+2,n+1+(i-1)*s+j,0,0);
    vcnt=s*m+n+2;
    mcmf();
    pf("%d\n",cst);
    //ps;
    return 0;
}
