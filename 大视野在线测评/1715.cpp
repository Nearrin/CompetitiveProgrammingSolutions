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
namespace bellman{
	vector<int>to[1010],we[1010];int vcnt;
	void clear(){
		lp(i,1,vcnt)to[i].clear(),we[i].clear();
	}
	void add(int u,int v,int w){
		to[u].pb(v);
		we[u].pb(w);
	}
	bool solve(){
		static int dis[1010];
		lp(i,1,vcnt)dis[i]=0;
		lp(i,1,vcnt)lp(j,1,vcnt)vp(k,to[j]){
			int u=j,v=to[j][k],w=we[j][k];
			if(dis[u]+w<dis[v])dis[v]=dis[u]+w;
		}
		lp(i,1,vcnt)lp(j,1,vcnt)vp(k,to[j]){
			int u=j,v=to[j][k],w=we[j][k];
			if(dis[u]+w<dis[v])return false;
		}
		return true;
	}
}
int main(){
	int test;sf("%d",&test);
	lp(kase,1,test){
		int n,m,w;sf("%d%d%d",&n,&m,&w);
		bellman::vcnt=n;bellman::clear();
		lp(i,1,m){
			int u,v,w;sf("%d%d%d",&u,&v,&w);
			bellman::add(u,v,w);
			bellman::add(v,u,w);
		}
		lp(i,1,w){
			int u,v,w;sf("%d%d%d",&u,&v,&w);
			bellman::add(u,v,-w);
		}
		pf("%s\n",bellman::solve()?"NO":"YES");
	}
	return 0;
}
