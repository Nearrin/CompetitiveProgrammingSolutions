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
vector<int>to[10010],ch[10010];
int f[10010],g[10010],h[10010],n;
void treedp(int u,int p){
	vp(i,to[u])if(to[u][i]!=p)treedp(to[u][i],u),ch[u].pb(to[u][i]);
	f[u]=1;vp(i,ch[u]){
		int v=ch[u][i];
		f[u]+=min(min(f[v],g[v]),h[v]);
	}
	h[u]=0;
	vp(i,ch[u]){
		int v=ch[u][i];
		h[u]+=min(f[v],g[v]);
	}
	g[u]=~0u>>1;
	vp(i,ch[u]){
		int v=ch[u][i];
		g[u]=min(g[u],h[u]-min(f[v],g[v])+f[v]);
	}
	//pf("[%d,%d,%d,%d]\n",u,f[u],g[u],h[u]);
}
int main(){
	sf("%d",&n);
	lp(i,1,n-1){
		int a,b;sf("%d%d",&a,&b);
		to[a].pb(b);
		to[b].pb(a);
	}
	treedp(1,0);
	/*lp(i,1,n){
		vp(j,ch[i])pf("{%d}",ch[i][j]);
		pf("\n");
	}*/
	pf("%d\n",min(f[1],g[1]));
	return 0;
}
