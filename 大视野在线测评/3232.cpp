#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define pb push_back
#define mp make_pair
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
#define vp(i,v) for(int i=0;i<v.size();++i)
#define wp(i,v) for(int i=int(v.size()-1);i>=0;--i)
typedef long long ll;
using namespace std;
double fab(double a){return a>0?a:-a;}
double eps=1e-6,inf=1e100;
namespace isap{
    struct edge{int v;double c;};
    vector<edge>eg;vector<int>to[100010];
    int dis[100010],vcnt,gap[100010];
    void clear(){
        lp(i,0,vcnt)to[i].clear(),dis[i]=gap[i]=0;
        eg.clear();gap[0]=vcnt;
    }
 void add(int u,int v,double c){edge t;t.v=v;t.c=c;to[u].pb(eg.size());eg.pb(t);}
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
        //pf("[%lf,%d]\n",r,vcnt);
        return r;
    }
}
namespace mcut{
    double wei[100010];vector<int>to[100010];int vcnt;
    void clear(){
        lp(i,1,vcnt)to[i].clear();
    }
    void add(int u,int v){
        to[u].pb(v);
    }
    double solve(){
        isap::vcnt=vcnt+2;isap::clear();
        double ret=0;
        lp(i,1,vcnt)if(wei[i]>eps)isap::add(1,i+1,wei[i]),isap::add(i+1,1,0),ret+=wei[i];
        else isap::add(i+1,vcnt+2,-wei[i]),isap::add(vcnt+2,i+1,0);
        lp(i,1,vcnt)vp(j,to[i])isap::add(i+1,to[i][j]+1,inf),isap::add(to[i][j]+1,i+1,0);
        return ret-isap::solve();
    }
}
int n,m;double lr[60][60],ud[60][60],wt[60][60];
int idnw,id[60][60],idlr[60][60],idud[60][60];
double calc(double t){
    mcut::vcnt=idnw;
    mcut::clear();
    lp(i,1,n)lp(j,1,m){
        mcut::wei[id[i][j]]=wt[i][j]-(lr[i][j]+lr[i+1][j]+ud[i][j]+ud[i][j+1])*t;
        //pf("[%lf,%lf]\n",lr[i][j]+lr[i+1][j]+ud[i][j]+ud[i][j+1],t);
    }
    lp(i,1,n+1)lp(j,1,m){
        mcut::wei[idlr[i][j]]=lr[i][j]*t*2;
        if(i!=1&&i!=n+1)mcut::add(idlr[i][j],id[i-1][j]),mcut::add(idlr[i][j],id[i][j]);
        else mcut::wei[idlr[i][j]]=0;
    }
    lp(i,1,n)lp(j,1,m+1){
        mcut::wei[idud[i][j]]=ud[i][j]*t*2;
        if(j!=1&&j!=m+1)mcut::add(idud[i][j],id[i][j-1]),mcut::add(idud[i][j],id[i][j]);
        else mcut::wei[idud[i][j]]=0;
    }
    return mcut::solve();
}
int main(){
    sf("%d%d",&n,&m);
    lp(i,1,n)lp(j,1,m)sf("%lf",&wt[i][j]),id[i][j]=++idnw;
    lp(i,1,n+1)lp(j,1,m)sf("%lf",&lr[i][j]),idlr[i][j]=++idnw;
    lp(i,1,n)lp(j,1,m+1)sf("%lf",&ud[i][j]),idud[i][j]=++idnw;
    //pf("%lf\n",calc(0.2));ps;
    double l=0,r=1;
    while(calc(r)>eps)r*=2;
    while(r-l>eps){
        double m=(l+r)/2;
        if(calc(m)>eps)l=m;
        else r=m;
    }
    pf("%.3lf\n",l);
    //ps;
    return 0;
}
