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
		edge(int a,int b):v(a),c(b){}
		int v,c;
	};
	vector<edge>eg;vector<int>to[10010];
	int dis[10010],gap[10010],vcnt;
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
			if(e.c&&dis[u]==dis[e.v]+1){
				int t=dfs(e.v,min(g,e.c));
				e.c-=t,ev.c+=t,g-=t;
				if(!g)return f-g;
			}
		}
		if(!--gap[dis[u]])dis[1]=vcnt;
		++gap[++dis[u]];
		return f-g;
	}
	int solve(){
		gap[0]=vcnt;int r=0;
		while(dis[1]<vcnt)r+=dfs(1,~0u>>1);
		return r;
	}
}
int main(){
	int n,f,d;static int idcow[110][2],idfood[110],iddrink[110],idst,idet;
	int nw=0;
	sf("%d%d%d",&n,&f,&d);
	idst=++nw;
	lp(i,1,n)idcow[i][0]=++nw,idcow[i][1]=++nw;
	lp(i,1,f)idfood[i]=++nw;
	lp(i,1,d)iddrink[i]=++nw;
	idet=++nw;
	isap::vcnt=nw;
	lp(i,1,n){
		int fi,di;sf("%d%d",&fi,&di);
		lp(j,1,fi){
			int t;sf("%d",&t);
			isap::add(idfood[t],idcow[i][0],1);
		}
		lp(j,1,di){
			int t;sf("%d",&t);
			isap::add(idcow[i][1],iddrink[t],1);
		}
		isap::add(idcow[i][0],idcow[i][1],1);
	}
	lp(i,1,f)isap::add(idst,idfood[i],1);
	lp(i,1,d)isap::add(iddrink[i],idet,1);
	pf("%d\n",isap::solve());
	return 0;
}
