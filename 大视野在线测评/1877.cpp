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
		edge(int _v,int _c,int _w):
			v(_v),c(_c),w(_w){}
		int v,c,w;
	};
	vector<edge>eg;
	vector<int>to[N];
	int dis[N],in[N],vcnt;
	void add(int u,int v,int c,int w){
		to[u].pb(eg.size());
		eg.pb(edge(v,c,w));
		to[v].pb(eg.size());
		eg.pb(edge(u,0,-w));
	}
	bool spfa(){
		lp(i,1,vcnt)dis[i]=~0u>>1;
		dis[1]=0;priority_queue<pair<int,int> >qu;
		qu.push(mp(-0,1));
		while(!qu.empty()){
			int u=qu.top().second,d=-qu.top().first;qu.pop();
			if(dis[u]!=d)continue;
			vp(i,to[u]){
				edge&e=eg[to[u][i]],&ev=eg[to[u][i]^1];
				if(e.c&&dis[u]+e.w<dis[e.v]){
					dis[e.v]=dis[u]+e.w;
					qu.push(mp(-dis[e.v],e.v));
				}
			}
		}
		return dis[vcnt]!=~0u>>1;
	}
	int cst,flw;
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
int main(){
	int n,m,nw=0;sf("%d%d",&n,&m);
	static int id[210][2];
	id[1][0]=++nw;
	lp(i,2,n-1)id[i][0]=++nw,id[i][1]=++nw;
	id[n][1]=++nw;
	mcmf::vcnt=nw;
	lp(i,1,m){
		int u,v,w;
		sf("%d%d%d",&u,&v,&w);
		if(u!=n&&v!=1)
			mcmf::add(id[u][0],id[v][1],1,w);
	}
	lp(i,2,n-1){
		mcmf::add(id[i][1],id[i][0],1,0);
	}
	mcmf::run();
	pf("%d %d\n",mcmf::flw,mcmf::cst);
	return 0;
}
