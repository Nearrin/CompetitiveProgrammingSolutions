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
		edge(int a,int b):
			v(a),c(b){}
		int v,c;
	};
	vector<edge>eg;vector<int>to[10010];
	int vcnt,dis[10010],gap[10010];
	void add(int u,int v,int c){
		to[u].pb(eg.size());
		eg.pb(edge(v,c));
	}
	int dfs(int u,int f){
		if(u==vcnt)return f;
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
	int run(){
		gap[0]=vcnt;
		int ret=0;
		while(dis[1]<vcnt)ret+=dfs(1,~0u>>1);
		return ret;
	}
}
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int main(){
	static int n,m,nw,a[110][110],b[110][110],c[110][110],idst,id[110][110],idet;
	int ans=0;
	sf("%d%d",&n,&m);
	lp(i,1,n)lp(j,1,m)sf("%d",&a[i][j]),ans+=a[i][j];
	lp(i,1,n)lp(j,1,m)sf("%d",&b[i][j]),ans+=b[i][j];
	lp(i,1,n)lp(j,1,m)sf("%d",&c[i][j]);
	idst=++nw;
	lp(i,1,n)lp(j,1,m)id[i][j]=++nw;
	idet=++nw;
	isap::vcnt=nw;
	lp(i,1,n)lp(j,1,m){
		if((i+j)%2==1){
			isap::add(idst,id[i][j],a[i][j]);
			isap::add(id[i][j],idst,0);
			isap::add(id[i][j],idet,b[i][j]);
			isap::add(idet,id[i][j],0);
			lp(k,0,3){
				int ti=i+dir[k][0],tj=j+dir[k][1];
				if(ti>0&&ti<=n&&tj>0&&tj<=m){
					ans+=c[i][j]+c[ti][tj];
					isap::add(id[i][j],id[ti][tj],c[i][j]+c[ti][tj]);
					isap::add(id[ti][tj],id[i][j],c[i][j]+c[ti][tj]);
				}
			}
		}else{
			isap::add(idst,id[i][j],b[i][j]);
			isap::add(id[i][j],idst,0);
			isap::add(id[i][j],idet,a[i][j]);
			isap::add(idet,id[i][j],0);
		}
	}
	pf("%d\n",ans-isap::run());
	return 0;
}
