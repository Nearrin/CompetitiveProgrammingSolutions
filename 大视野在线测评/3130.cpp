#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define pb push_back
#define mp make_pair
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
#define vp(i,v) for(int i=0;i<v.size();++i)
using namespace std;
typedef long long ll;
namespace isap{
    struct edge{int v;double c;};
    vector<edge>eg;vector<int>to[110];
    void add(int u,int v,double c){edge t;t.v=v;t.c=c;to[u].pb(eg.size());eg.pb(t);}
    int vcnt,dis[110],gap[110];
    void clear(){lp(i,1,vcnt)dis[i]=gap[i]=0,to[i].clear();eg.clear();gap[0]=vcnt;}
    double dfs(int u,double f){
        if(u==vcnt)return f;
        double g=f;
        vp(i,to[u]){
            edge&e=eg[to[u][i]],&ev=eg[to[u][i]^1];
            if(e.c>1e-6&&dis[u]==dis[e.v]+1){
                double t=dfs(e.v,min(g,e.c));
                g-=t,e.c-=t,ev.c+=t;
                if(g<1e-6||dis[1]==vcnt)return f-g;
            }
        }
        if(!--gap[dis[u]])dis[1]=vcnt;
        ++gap[++dis[u]];
        return f-g;
    }
    double solve(){
        double r=0;
        while(dis[1]<vcnt)r+=dfs(1,~0u>>1);
        return r;
    }
}
struct data{
    data(){sf("%d%d%d",&u,&v,&c);}
    int u,v,c;
};
double tabs(double a){return a>0?a:-a;}
int main(){
    int n,m,p;double mx;
    sf("%d%d%d",&n,&m,&p);
    vector<data>v;
    lp(i,1,m)v.pb(data());
    isap::vcnt=n;
    isap::clear();
    vp(i,v)isap::add(v[i].u,v[i].v,v[i].c),isap::add(v[i].v,v[i].u,0);
    mx=isap::solve();
    double lft=0,rht=500000;
    while(rht-lft>1e-8){
        double mid=(lft+rht)/2;
        isap::clear();
        vp(i,v)isap::add(v[i].u,v[i].v,min(double(v[i].c),mid)),isap::add(v[i].v,v[i].u,0);
        if(tabs(isap::solve()-mx)<1e-6)rht=mid;
        else lft=mid;
    }
    pf("%.0lf\n%.4lf\n",mx,lft*p);
    //ps;
    return 0;
}
