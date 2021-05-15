#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
pair<int,int>a[1010];int n;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
bool check(ll x,ll y){
    ll t=sqrt(double(x*x+y*y));
    if(t*t<x*x+y*y)++t;
    if(t*t>x*x+y*y)--t;
    return t*t==x*x+y*y&&gcd(x,y)==1;
}
namespace isap{
    struct edge{int v,c;};vector<edge>edges;
    int vcnt;vector<int>to[1010];
    void add(int u,int v,int c){
        edge e;e.v=v;e.c=c;to[u].push_back(edges.size());
        edges.push_back(e);
    }
    int dis[1010],gap[1010];
    int dfs(int u,int f){
        if(u==vcnt)return f;
        int g=f;
        lp(i,0,int(to[u].size()-1)){
            edge&e=edges[to[u][i]],&ev=edges[to[u][i]^1];
            if(e.c&&dis[e.v]+1==dis[u]){
                int t=dfs(e.v,min(e.c,g));
                g-=t,e.c-=t,ev.c+=t;
                if(!g||dis[1]==vcnt)return f-g;
            }
        }
        if(!--gap[dis[u]])dis[1]=vcnt;
        ++gap[++dis[u]];
        return f-g;
    }
    int isap(){
        gap[0]=vcnt;int r=0;
        while(dis[1]<vcnt)r+=dfs(1,~0u>>1);
        return r;
    }
}
int main(){
    sf("%d",&n);
    lp(i,1,n)sf("%d",&a[i].first);
    lp(i,1,n)sf("%d",&a[i].second);
    isap::vcnt=n+2;
    lp(i,1,n)if(a[i].first&1){
        isap::add(1,i+1,a[i].second);
        isap::add(i+1,1,0);
        lp(j,1,n)if(a[j].first%2==0){
            if(check(a[i].first,a[j].first)){
                isap::add(i+1,j+1,~0u>>1);
                isap::add(j+1,i+1,0);
            }
        }
    }else{
        isap::add(i+1,n+2,a[i].second);
        isap::add(n+2,i+1,0);
    }
    int ans=0;lp(i,1,n)ans+=a[i].second;
    pf("%d\n",ans-isap::isap());
    //ps;
    return 0;
}
