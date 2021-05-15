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
struct edge{
	edge(int a,int b,edge*c):
		v(a),id(b),nxt(c){}
	int v,id;edge*nxt;
}*bg[100010];
void add(int u,int v,int i){
	bg[u]=new edge(v,i,bg[u]);
}
ll val[100010],ans[100010];int n,m;
namespace tree{
	int vis[100010];
	ll tval[100010];
	bool dfs(int u,int p){
		vis[u]=1;
		for(edge*e=bg[u];e;e=e->nxt){
			if(e->v!=p){
				if(vis[e->v])return false;
				if(!dfs(e->v,u))return false;
				tval[u]+=ans[e->id];
			}
		}
		for(edge*e=bg[u];e;e=e->nxt){
			if(e->v==p){
				ans[e->id]=val[u]-tval[u];
			}
		}
		return true;
	}
	bool run(){
		return dfs(1,0);
	}
}
namespace circle{
	vector<int>cir;
	int incir[100010];
	int vis[100010],nw;
	ll tval[100010];
	int prt[100010];
	bool dfs(int u,int p){
		vis[u]=++nw;prt[u]=p;
		for(edge*e=bg[u];e;e=e->nxt){
			if(e->v!=p){
				if(vis[e->v]){
					if(vis[e->v]>vis[u])continue;
					else if(cir.size()==0){
						for(int i=u;i!=prt[e->v];i=prt[i]){
							cir.pb(i);
							incir[i]=1;
						}
					}else return false;
				}else if(!dfs(e->v,u))return false;
			}
		}
		return true;
	}
	void dfs2(int u,int p){
		for(edge*e=bg[u];e;e=e->nxt){
			if(e->v!=p&&!incir[e->v]){
				dfs2(e->v,u);
				tval[u]+=ans[e->id];
			}
		}
		for(edge*e=bg[u];e;e=e->nxt){
			if(e->v==p){
				ans[e->id]=val[u]-tval[u];
			}
		}
	}
	ll a[100010];int x[100010];
	bool run(){
		if(!dfs(1,0))return false;
		if(cir.size()%2==0)return false;
		vp(i,cir)dfs2(cir[i],0);
		lp(i,1,cir.size())a[i]=val[cir[i-1]]-tval[cir[i-1]];
		lp(i,1,cir.size()){
			for(edge*e=bg[cir[i-1]];e;e=e->nxt){
				if(i==1){
					if(e->v==cir.back()){
						x[1]=e->id;
					}
				}else{
					if(e->v==cir[i-2]){
						x[i]=e->id;
					}
				}
			}
		}
		//lp(i,1,cir.size())pf("[%d]",cir[i-1]);pf("\n");
		//lp(i,1,cir.size())pf("[%d]",x[i]);pf("\n");
		ll tmp=0;
		lp(i,1,cir.size()){
			if(i&1)tmp+=a[i];
			else tmp-=a[i];
		}
		ans[x[1]]=tmp/2;
		lp(i,2,cir.size())ans[x[i]]=a[i-1]-ans[x[i-1]];
		return true;
	}
}
int main(){
	sf("%d%d",&n,&m);
	lp(i,1,n)sf("%lld",&val[i]);
	lp(i,1,m){
		int u,v;sf("%d%d",&u,&v);
		add(u,v,i);add(v,u,i);
	}
	if(tree::run()||circle::run()){
		lp(i,1,m)pf("%lld\n",ans[i]*2);
	}else{
		pf("0\n");
	}
	return 0;
}

/*
7 7
8
11
7
17
11
5
1
1 2
2 3
3 4
4 5
5 1
4 6
2 7
*/
