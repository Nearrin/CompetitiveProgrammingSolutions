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
ll big=10000000000000000ll;
namespace isap{
    struct edge{
        edge(int a,ll b):v(a),c(b){}
        int v;ll c;
    };
    vector<edge>eg;vector<int>to[100010];
    int dis[100010],gap[100010],vcnt;
    void clear(){
        lp(i,1,vcnt){
            to[i].clear();
            dis[i]=0;
            gap[i]=0;
        }
        eg.clear();
        gap[0]=vcnt;
    }
    void add(int u,int v,ll c){
        to[u].pb(eg.size());
        eg.pb(edge(v,c));
        to[v].pb(eg.size());
        eg.pb(edge(u,0));
    }
    ll dfs(int u,ll f){
        if(u==vcnt)return f;
        ll g=f;
        vp(i,to[u]){
            edge&e=eg[to[u][i]],&ev=eg[to[u][i]^1];
            if(e.c&&dis[u]==dis[e.v]+1){
                ll t=dfs(e.v,min(g,e.c));
                e.c-=t,ev.c+=t,g-=t;
                if(!g)return f-g;
            }
        }
        if(!--gap[dis[u]])dis[1]=vcnt;
        ++gap[++dis[u]];
        return f-g;
    }
    ll solve(){
        ll r=0;
        while(dis[1]<vcnt)r+=dfs(1,big);
        return r;
    }
}
ll n,m,a[110][110],idst,idet,idx[110][110];
bool check(ll mid){
    isap::clear();
    ll ret=0;
    lp(i,1,n)lp(j,1,m){
        if((i+j)&1){
            isap::add(idst,idx[i][j],mid-a[i][j]);
            ret+=mid-a[i][j];
            if(i!=1)isap::add(idx[i][j],idx[i-1][j],big);
            if(i!=n)isap::add(idx[i][j],idx[i+1][j],big);
            if(j!=1)isap::add(idx[i][j],idx[i][j-1],big);
            if(j!=m)isap::add(idx[i][j],idx[i][j+1],big);
        }else{
            isap::add(idx[i][j],idet,mid-a[i][j]);
        }
    }
    return isap::solve()==ret;
}
int main(){
    ll test;sf("%lld",&test);
    lp(kase,1,test){
        ll cj=0,co=0,sj=0,so=0;
        sf("%lld%lld",&n,&m);
        lp(i,1,n)lp(j,1,m){
            sf("%lld",&a[i][j]);
            if((i+j)&1)++cj,sj+=a[i][j];
            else ++co,so+=a[i][j];
        }
        ll nw=0;
        idst=++nw;lp(i,1,n)lp(j,1,m)idx[i][j]=++nw;idet=++nw;
        isap::vcnt=nw;
        if(cj==co){
            ll l=0,r=2000000000;
            lp(i,1,n)lp(j,1,m)l=max(l,a[i][j]);
            --l;
            if(!check(r))pf("-1\n");
            else{
                while(l+1<r){
                    ll mid=(l+r)/2;
                    if(check(mid))r=mid;
                    else l=mid;
                }
                //pf("[%lld]\n",r);
                pf("%lld\n",(n*m*r-(so+sj))/2);
            }
        }else{
            if(cj>co)swap(cj,co),swap(sj,so);
            if(so<sj)pf("-1\n");
            else if((so-sj)%(co-cj)!=0)pf("-1\n");
            else{
                ll t=(so-sj)/(co-cj),flg=0;
                lp(i,1,n)lp(j,1,m)if(a[i][j]>t)flg=1;
                if(flg)pf("-1\n");
                else if(check(t))pf("%lld\n",(n*m*t-(so+sj))/2);
                else pf("-1\n");
            }
        }
    }
    return 0;
}
