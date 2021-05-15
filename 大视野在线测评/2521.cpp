#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<queue>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
namespace isap{
    struct edge{
        int v,c;
    };
    vector<edge>eg;vector<int>to[50010];
    void add(int u,int v,int c){
        edge t;t.v=v;t.c=c;
        to[u].push_back(eg.size());eg.push_back(t);
        //pf("[%d,%d,%d]\n",u,v,c);
    }
    int dis[50010],vcnt,st,et;
    int dfs(int u,int f){
        if(u==et)return f;
        int g=f;
        lp(i,0,int(to[u].size()-1)){
            edge&e=eg[to[u][i]],&ev=eg[to[u][i]^1];
            if(e.c&&dis[u]==dis[e.v]+1){
                int t=dfs(e.v,min(e.c,g));
                e.c-=t,ev.c+=t,g-=t;
                if(!g)return f; 
            }
        }
        ++dis[u];
        return f-g;
    }
    int isap(){
        int r=0;
        while(dis[st]<vcnt)r+=dfs(st,~0u>>1);
        return r;
    }
}
struct edge2{
    int u,v,w;
};
vector<edge2>eg2;edge2 to;
int main(){
    int n,m,k;
    sf("%d%d%d",&n,&m,&k);
    lp(i,1,m){
        int u,v,w;
        sf("%d%d%d",&u,&v,&w);
        edge2 t;t.u=u;t.v=v;t.w=w;
        if(i==k)to=t;
        else eg2.push_back(t);
    }
    isap::vcnt=n;isap::st=to.u;isap::et=to.v;
    lp(i,0,int(eg2.size()-1)){
        int u=eg2[i].u,v=eg2[i].v,w=eg2[i].w;
        if(w<=to.w)
            isap::add(u,v,to.w-w+1),
            isap::add(v,u,to.w-w+1);
    }
    pf("%d\n",isap::isap());
    //ps;
    return 0;
}
