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
#include<stack>
vector<int>to[10010];int n,m;
namespace tarjan{
	int tim,df[10010],lw[10010],in[10010];stack<int>stk;
	int nw,bel[10010],siz[10010];
	void dfs(int u){
		df[u]=lw[u]=++tim;in[u]=1;stk.push(u);
		vp(i,to[u]){
			int v=to[u][i];
			if(!df[v])dfs(v),lw[u]=min(lw[u],lw[v]);
			else if(in[v])lw[u]=min(lw[u],df[v]);
		}
		if(df[u]==lw[u]){
			++nw;int t;
			do{
				t=stk.top();
				stk.pop();
				bel[t]=nw;
				in[t]=0;
				++siz[nw];
			}while(t!=u);
		}
	}
	void run(){
		dfs(1);
	}
}
int outd[10010];
int main(){
	sf("%d%d",&n,&m);
	lp(i,1,m){
		int u,v;sf("%d%d",&u,&v);
		to[u].pb(v);
	}
	tarjan::run();
	//pf("[%d]",tarjan::nw);
	lp(u,1,n)vp(i,to[u]){
		int v=to[u][i];
		if(tarjan::bel[u]!=tarjan::bel[v])
			++outd[tarjan::bel[u]];
	}
	int o0=0;
	lp(i,1,tarjan::nw)if(outd[i]==0)++o0;
	if(o0==1){
		lp(i,1,tarjan::nw)if(outd[i]==0)pf("%d\n",tarjan::siz[i]);
	}else pf("0\n");
    return 0;
}
