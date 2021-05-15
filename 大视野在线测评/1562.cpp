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
vector<int>to[10010],stk;int lk[10010],vis[10010],ans[10010];
int dfs(int u){
	vp(i,to[u]){
		int v=to[u][i];
		if(!vis[v]){
			vis[v]=1;
			stk.pb(v);
			if(!lk[v]||dfs(lk[v])){
				lk[v]=u;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	int n;sf("%d",&n);
	lp(i,0,n-1){
		int t;sf("%d",&t);
		int x=(i-t+n)%n;
		int y=(i+t)%n;
		if(x>y)swap(x,y);
		to[i+1].pb(x+1);
		to[i+1].pb(y+1);
	}
	int r=0;
	rp(i,n,1){
		r+=dfs(i);
		vp(j,stk)vis[stk[j]]=0;
		stk.clear();
	}
	if(r!=n)pf("No Answer\n");
	else{
		lp(i,1,n)ans[lk[i]]=i;
		lp(i,1,n)pf("%d%c",ans[i]-1,i==n?'\n':' ');
	}
	return 0;
}
