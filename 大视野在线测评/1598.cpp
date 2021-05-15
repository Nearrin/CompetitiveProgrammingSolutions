#include<cstdio>
#include<vector>
#include<algorithm>
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
#define wp(i,v) for(int i=int(v.size()-1);i>=0;--i)
using namespace std;
typedef long long ll;
vector<int>to[1010],we[1010],f[1010];int n,m,k;
int vis[1010];
void dfs(int u){
	if(vis[u])return;
	vis[u]=1;
	vp(i,to[u]){
		int v=to[u][i],w=we[u][i];
		dfs(v);
		vp(j,f[v])f[u].pb(f[v][j]+w);
	}
	sort(f[u].begin(),f[u].end());
	while(f[u].size()>k)f[u].pop_back();
}
int main(){
	sf("%d%d%d",&n,&m,&k);
	lp(i,1,m){
		int x,y,d;sf("%d%d%d",&x,&y,&d);
		to[x].pb(y);
		we[x].pb(d);
	}
	vis[1]=1;f[1].pb(0);
	dfs(n);
	lp(i,1,k)if(i-1<f[n].size())pf("%d\n",f[n][i-1]);else pf("-1\n");
	return 0;
}
