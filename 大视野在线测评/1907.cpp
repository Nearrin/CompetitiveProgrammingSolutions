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
#include<stack>
int main(){
	int test;sf("%d",&test);
	lp(kase,1,test){
		int n;sf("%d",&n);
		static vector<int>to[100010],chd[100010];
		lp(i,1,n)to[i].clear(),chd[i].clear();
		lp(i,1,n-1){
			int u,v;sf("%d%d",&u,&v);
			to[u].pb(v);
			to[v].pb(u);
		}
		vector<int>tmp;stack<int>stk;
		static int vis[100010];
		lp(i,1,n)vis[i]=0;vis[1]=1;
		stk.push(1);while(!stk.empty()){
			int u=stk.top();stk.pop();
			tmp.pb(u);
			vp(i,to[u]){
				int v=to[u][i];
				if(!vis[v]){
					vis[v]=1;
					stk.push(v);
					chd[u].pb(v);
				}
			}
		}
		static int f[100010],up[100010];
		lp(i,1,n)f[i]=0,up[i]=1;
		wp(i,tmp){
			int u=tmp[i];
			vp(j,chd[u])f[u]+=f[chd[u][j]];
			int pcnt=0;
			vp(j,chd[u])pcnt+=up[chd[u][j]];
			if(pcnt>=2)--f[u],up[u]=0;
			else if(pcnt==0)++f[u];
		}
		pf("%d\n",f[1]);
	}
	//ps;
	return 0;
}
