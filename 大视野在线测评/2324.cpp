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
#define wp(i,v) for(int i=int(v.size())-1;i>=0;--i)
typedef long long ll;
using namespace std;
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
#define wp(i,v) for(int i=int(v.size())-1;i>=0;--i)
typedef long long ll;
using namespace std;
#include<queue>
namespace mcmf{
    const int N=1010;
    struct edge{
        edge(int _v,int _c,ll _w):
            v(_v),c(_c),w(_w){}
        int v,c;
        ll w;
    };
    vector<edge>eg;
    vector<int>to[N];
    ll dis[N];int in[N],vcnt;
    void add(int u,int v,int c,ll w){
        to[u].pb(eg.size());
        eg.pb(edge(v,c,w));
        to[v].pb(eg.size());
        eg.pb(edge(u,0,-w));
        //pf("[%d,%d,%d,%lld]\n",u,v,c,w);
    }
    bool spfa(){
        lp(i,1,vcnt)dis[i]=10000000000000000ll;
        dis[1]=0;priority_queue<pair<ll,int> >qu;
        qu.push(mp(-0,1));
        while(!qu.empty()){
            int u=qu.top().second;ll d=-qu.top().first;qu.pop();
            if(dis[u]!=d)continue;
            vp(i,to[u]){
                edge&e=eg[to[u][i]],&ev=eg[to[u][i]^1];
                if(e.c&&dis[u]+e.w<dis[e.v]){
                    dis[e.v]=dis[u]+e.w;
                    qu.push(mp(-dis[e.v],e.v));
                }
            }
        }
        return dis[vcnt]!=10000000000000000ll;
    }
    ll cst;int flw;
    int dfs(int u,int f){
        if(u==vcnt)return f;
        int g=f;in[u]=1;
        vp(i,to[u]){
            edge&e=eg[to[u][i]],&ev=eg[to[u][i]^1];
            if(e.c&&dis[u]+e.w==dis[e.v]&&!in[e.v]){
                int t=dfs(e.v,min(g,e.c));
                e.c-=t;ev.c+=t;g-=t;cst+=e.w*t;
                if(!g)return f;
            }
        }
        return f-g;
    }
    void run(){
        while(spfa()){
            int t;
            do{
                lp(i,1,vcnt)in[i]=0;
                t=dfs(1,~0u>>1);
                flw+=t;
            }while(0);
        }
    }
}
int n,m,k;
int idst,idet,idx[210][2],nw;
int dp[210][210];
int main(){
	sf("%d%d%d",&n,&m,&k);
	idst=++nw;
	idx[0][0]=++nw;
	lp(i,1,n)idx[i][1]=++nw,idx[i][0]=++nw;
	idet=++nw;
	mcmf::vcnt=nw;
	lp(i,0,n)lp(j,0,n)dp[i][j]=~0u>>1;
	lp(i,1,m){
		int u,v,c;sf("%d%d%d",&u,&v,&c);
		dp[u][v]=min(dp[u][v],c);
		dp[v][u]=min(dp[v][u],c);
	}
	lp(l,0,n){
		lp(i,0,n)lp(j,0,n){
			if(dp[i][l]!=~0u>>1&&dp[l][j]!=~0u>>1&&dp[i][l]+dp[l][j]<dp[i][j])
				dp[i][j]=dp[i][l]+dp[l][j];
		}
		lp(i,0,l-1)if(dp[i][l]!=~0u>>1)mcmf::add(idx[i][0],idx[l][1],1,dp[i][l]);
	}
	lp(i,1,n)mcmf::add(idx[i][1],idx[i][0],1,-ll(~0u>>1));
	mcmf::add(idst,idx[0][0],k,0);
	lp(i,1,n)mcmf::add(idx[i][0],idet,1,0);
	mcmf::add(idx[0][0],idet,k,0);
	mcmf::run();
	ll tmp=~0u>>1;
	//pf("%lld\n",mcmf::cst);
	pf("%lld\n",(mcmf::cst%tmp+tmp)%tmp);
	return 0;
}
