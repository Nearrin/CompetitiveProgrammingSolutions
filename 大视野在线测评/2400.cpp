#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
namespace isap{
    struct edge{
        int v,c;
    };
    vector<edge>eg;vector<int>to[510];
    int dis[510],gap[510];int vcnt;
    void init(){
        eg.clear();
        lp(i,1,vcnt)to[i].clear();
    }
    void add(int u,int v,int c){
        edge t;t.v=v;t.c=c;
        to[u].push_back(eg.size());eg.push_back(t);
    }
    void bfs(){
        lp(i,1,vcnt)dis[i]=~0u>>1;dis[1]=0;
        queue<int>qu;qu.push(1);
        while(!qu.empty()){
            int u=qu.front();qu.pop();
            lp(i,0,int(to[u].size()-1)){
                edge&e=eg[to[u][i]],&ev=eg[to[u][i]^1];
                if(e.c&&dis[e.v]==~0u>>1){
                    dis[e.v]=dis[u]+1;
                    qu.push(e.v);
                }
            }
        }
        lp(i,0,vcnt)gap[i]=0;
        int t=dis[vcnt];
        lp(i,1,vcnt)dis[i]=t-dis[i];
        lp(i,1,vcnt)++gap[dis[i]];
    }
    int dfs(int u,int f){
        if(u==vcnt)return f;
        int g=f;int mh=vcnt-1;
        lp(i,0,int(to[u].size()-1)){
            edge&e=eg[to[u][i]],&ev=eg[to[u][i]^1];
            if(e.c&&dis[u]==dis[e.v]+1){
                int t=dfs(e.v,min(g,e.c));
                g-=t,e.c-=t,ev.c+=t;
                if(!g||dis[1]==vcnt)return f-g;
            }
            if(e.c)mh=min(mh,dis[e.v]);
        }
        if(!--gap[dis[u]])dis[1]=vcnt;
        ++gap[dis[u]=mh+1];
        return f-g;
    }
    int solve(){
        int r=0;//bfs();
        lp(i,1,vcnt)gap[i]=0;gap[0]=vcnt;
        lp(i,1,vcnt)dis[i]=0;
        while(dis[1]<vcnt)r+=dfs(1,~0u>>1);
        return r;
    }
    void ddfs(int u){
        dis[u]=1;
        lp(i,0,int(to[u].size()-1)){
            edge&e=eg[to[u][i]],&ev=eg[to[u][i]^1];
            if(e.c&&!dis[e.v]){
                ddfs(e.v);
            }
        }
    }
    int gtone(){
        lp(i,1,vcnt)dis[i]=0;
        ddfs(1);
        int r=0;
        lp(i,2,vcnt-1)r+=dis[i];
        return r;
    }
}
int main(){
    static int n,m,v[510];
    sf("%d%d",&n,&m);
    lp(i,1,n)sf("%d",&v[i]);
    vector<pair<int,int> >eg;
    lp(i,1,m){
        int a,b;sf("%d%d",&a,&b);
        eg.push_back(make_pair(a,b));
    }
    ll ans1=0,ans2=0;
    lp(i,0,30){
        isap::vcnt=n+2;
        isap::init();
        lp(j,0,int(eg.size()-1))
            isap::add(eg[j].first+1,eg[j].second+1,1),
            isap::add(eg[j].second+1,eg[j].first+1,1);
        lp(j,1,n)if(v[j]>=0){
            if((v[j]>>i)&1)
                isap::add(1,j+1,~0u>>1),
                isap::add(j+1,1,0);
            else
                isap::add(n+2,j+1,0),
                isap::add(j+1,n+2,~0u>>1);
        }
        int t1=isap::solve(),t2=isap::gtone();
        ans1+=(1ll<<i)*t1;ans2+=(1ll<<i)*t2;
    }
    pf("%lld\n%lld\n",ans1,ans2);
    //ps;
    return 0;
}
