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
#include<queue>
int n,m,dist[510],inq[510];
vector<int>bg[510],we[510],ct[510];
namespace isap{
	struct edge{
		edge(int a,int b):
			v(a),c(b){}
		int v,c;
	};
	vector<edge>eg;vector<int>to[510];
	int dis[510],vcnt,gap[510];
	void add(int u,int v,int c){
		to[u].pb(eg.size());
		eg.pb(edge(v,c));
		to[v].pb(eg.size());
		eg.pb(edge(u,0));
	}
	int dfs(int u,int f){
		if(u==vcnt)return f;
		int g=f;
		vp(i,to[u]){
			edge&e=eg[to[u][i]],&ev=eg[to[u][i]^1];
			if(e.c&&dis[e.v]+1==dis[u]){
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
		while(dis[1]<vcnt)r+=dfs(1,~0u>>1);
		return r;
	}
}
int main(){
	sf("%d%d",&n,&m);
	lp(i,1,m){
		int u,v,w,c;sf("%d%d%d%d",&u,&v,&w,&c);
		bg[u].pb(v);
		we[u].pb(w);
		ct[u].pb(c);
		bg[v].pb(u);
		we[v].pb(w);
		ct[v].pb(c);
	}
	lp(i,2,n)dist[i]=~0u>>1;queue<int>qu;qu.push(1);inq[1]=1;
	while(!qu.empty()){
		int u=qu.front();qu.pop();inq[u]=0;
		vp(i,bg[u]){
			int v=bg[u][i],w=we[u][i];
			if(dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
				if(!inq[v]){
					qu.push(v);
					inq[v]=1;
				}
			}
		}
	}
	isap::vcnt=n;
	lp(u,1,n)vp(i,bg[u]){
		int v=bg[u][i],w=we[u][i],c=ct[u][i];
		if(dist[u]!=~0u>>1&&dist[u]+w==dist[v]){
			isap::add(u,v,c);
		}
	}
	pf("%d\n%d\n",dist[n],isap::solve());
	return 0;
}
