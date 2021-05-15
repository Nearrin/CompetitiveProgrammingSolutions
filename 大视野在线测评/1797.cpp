#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define pb push_back
#define mp make_pair
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
#define vp(i,v) for(int i=0;i<v.size();++i)
#define wp(i,v) for(int i=int(v.size()-1);i>=0;--i)
typedef long long ll;
using namespace std;
namespace isap{
    struct edge{
        edge(int a,int b,int d):u(a),v(b),c(d){}
        int u,v,c;
    };
    vector<edge>eg;
    vector<int>to[4010];
    void add(int u,int v,int c){
        to[u].pb(eg.size());
        eg.pb(edge(u,v,c));
    }
    int gap[4010],dis[4010],vcnt,str,edr;
    int dfs(int u,int f){
        if(u==edr)return f;
        int g=f;
        vp(i,to[u]){
            edge&e=eg[to[u][i]],&ev=eg[to[u][i]^1];
            if(e.c&&dis[u]==dis[e.v]+1){
                int t=dfs(e.v,min(g,e.c));
                e.c-=t,ev.c+=t,g-=t;
                if(!g||dis[1]==vcnt)return f-g;
            }
        }
        if(!--gap[dis[u]])dis[1]=vcnt;
        ++gap[++dis[u]];
        return f-g;
    }
    int solve(){
        gap[0]=vcnt;
        int r=0;
        while(dis[1]<vcnt)r+=dfs(str,~0u>>1);
        return r;
    }
}
namespace tarjan{
    vector<int>to[4010];int vcnt;
    void add(int u,int v){
        to[u].pb(v);
        //pf("(%d,%d)\n",u,v);
    }
    int bel[4010],df[4010],lw[4010],ti,in[4010],nw;
    vector<int>stk;
    void dfs(int u){
        df[u]=lw[u]=++ti;in[u]=1;stk.pb(u);
        vp(i,to[u]){
            int v=to[u][i];
            if(!df[v])dfs(v),lw[u]=min(lw[u],lw[v]);
            else if(in[v])lw[u]=min(lw[u],df[v]);
        }
        if(df[u]==lw[u]){
            int t;++nw;
            do{
                t=stk.back();stk.pop_back();
                bel[t]=nw;
                in[t]=0;
            }while(t!=u);
        }
    }
    void solve(){
        lp(i,1,vcnt)if(!df[i])dfs(i);
    }
}
int main(){
    int n,m,s,t;sf("%d%d%d%d",&n,&m,&s,&t);
    isap::str=s;
    isap::edr=t;
    isap::vcnt=n;
    lp(i,1,m){
        int u,v,c;sf("%d%d%d",&u,&v,&c);
        isap::add(u,v,c);
        isap::add(v,u,0);
    }
    isap::solve();
    tarjan::vcnt=n;
    lp(i,1,n)vp(j,isap::to[i]){
        isap::edge e=isap::eg[isap::to[i][j]];
        if(e.c)tarjan::add(i,e.v);
    }
    tarjan::solve();
    lp(i,0,m-1){
        int u=isap::eg[i*2].u;
        int v=isap::eg[i*2].v;
        int c=isap::eg[i*2].c;
        if(tarjan::bel[u]!=tarjan::bel[v]&&c==0)pf("1 ",1);
        else pf("0 ",0);
        if(tarjan::bel[u]==tarjan::bel[s]&&tarjan::bel[v]==tarjan::bel[t])pf("1\n");
        else pf("0\n");
    }
    //ps;
    return 0;
}
