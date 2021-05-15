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
#include<set>
int n,m,p;vector<int>to[100010];
vector<int>bg[100010];
int cnt[100010];
namespace tarjan{
	int ti,df[100010],lw[100010],bl[100010],in[100010],nw;
	vector<int>stk;
	void dfs(int u){
		df[u]=lw[u]=++ti;
		stk.pb(u);in[u]=1;
		vp(i,to[u]){
			int v=to[u][i];
			if(!df[v])dfs(v),lw[u]=min(lw[u],lw[v]);
			else if(in[v])lw[u]=min(lw[u],df[v]);
		}
		if(df[u]==lw[u]){
			++nw;int t;
			do{
				t=stk.back();stk.pop_back();
				in[t]=0;
				bl[t]=nw;
				++cnt[nw];
			}while(t!=u);
		}
	}
	void solve(){
		lp(i,1,n)if(!df[i])dfs(i);
		set<pair<int,int> >eg;
		lp(i,1,n)vp(j,to[i])if(bl[i]!=bl[to[i][j]])eg.insert(mp(bl[i],bl[to[i][j]]));
		for(set<pair<int,int> >::iterator it=eg.begin();it!=eg.end();++it){
			bg[it->first].pb(it->second);
		}
		n=nw;
		//lp(i,1,n)vp(j,bg[i])pf("[%d->%d]\n",i,bg[i][j]);
		//lp(i,1,n)pf("[%d]",cnt[i]);pf("\n");
	}
}
int f[100010],g[100010],vis[100010];
void dp(int u){
	if(vis[u])return;
	vis[u]=1;
	if(bg[u].size()==0){f[u]=cnt[u],g[u]=1;return;}
	vp(i,bg[u]){
		int v=bg[u][i];
		dp(v);
		f[u]=max(f[u],f[v]);
	}
	vp(i,bg[u]){
		int v=bg[u][i];
		if(f[v]==f[u])g[u]=(g[v]+g[u])%p;
	}
	f[u]+=cnt[u];
}
int main(){
	sf("%d%d%d",&n,&m,&p);
	lp(i,1,m){
		int u,v;sf("%d%d",&u,&v);
		to[u].pb(v);
	}
	tarjan::solve();
	lp(i,1,n)bg[0].pb(i);
	dp(0);
	pf("%d\n%d\n",f[0],g[0]);
	return 0;
}
