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
int f,p,c,m,dis[510];
vector<int>to[510],we[510];
int main(){
	sf("%d%d%d%d",&f,&p,&c,&m);
	lp(i,1,p){
		int f1,f2,t;sf("%d%d%d",&f1,&f2,&t);
		to[f1].pb(f2);
		we[f1].pb(t);
		to[f2].pb(f1);
		we[f2].pb(t);
	}
	lp(i,2,f)dis[i]=~0u>>1;
	lp(i,1,f)lp(u,1,f)vp(j,to[u]){
		int v=to[u][j],w=we[u][j];
		if(dis[u]==~0u>>1)continue;
		if(dis[u]+w<dis[v])dis[v]=dis[u]+w;
	}
	vector<int>ans2;
	int ans=0;
	lp(i,1,c){
		int t;sf("%d",&t);
		if(dis[t]<=m)++ans,ans2.pb(i);
	}
	pf("%d\n",ans);
	vp(i,ans2)pf("%d\n",ans2[i]);
	return 0;
}
