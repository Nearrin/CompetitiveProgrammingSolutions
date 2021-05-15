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
	vector<edge>eg;vector<int>to[100010];
	int dis[100010],gap[100010],vcnt;
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
				if(!g||dis[1]==vcnt)return f-g;
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
int n,m,nw,lft[3010],rht[3010],spa[3010],cov[3010];
vector<int>item[1010];
int idcow[3010],itid[3010],idst,idet;
int idx[1010*4];
void build(int x,int l,int r){
	idx[x]=++nw;
	if(l!=r){
		int m=(l+r)/2;
		build(x*2,l,m);
		build(x*2+1,m+1,r);
		isap::add(idx[x],idx[x*2],~0u>>1);
		isap::add(idx[x],idx[x*2+1],~0u>>1);
	}else{
		vp(i,item[l]){
			isap::add(idx[x],item[l][i],~0u>>1);
		}
	}
}
void query(int x,int l,int r,int b,int e,int he){
	if(b<=l&&e>=r)isap::add(he,idx[x],1);
	else{
		int m=(l+r)/2;
		if(b<=m)query(x*2,l,m,b,e,he);
		if(e>m)query(x*2+1,m+1,r,b,e,he);
	}
}
int main(){
	sf("%d%d",&n,&m);
	lp(i,1,n)sf("%d%d",&lft[i],&rht[i]);
	lp(i,1,m)sf("%d%d",&spa[i],&cov[i]);
	idst=++nw;
	lp(i,1,n)idcow[i]=++nw;
	lp(i,1,m)itid[i]=++nw;
	lp(i,1,m)item[spa[i]].pb(itid[i]);
	build(1,1,1000);
	idet=++nw;isap::vcnt=nw;
	lp(i,1,n)isap::add(idst,idcow[i],1);
	lp(i,1,m)isap::add(itid[i],idet,cov[i]);
	lp(i,1,n)query(1,1,1000,lft[i],rht[i],idcow[i]);
	pf("%d\n",isap::solve());
	return 0;
}
