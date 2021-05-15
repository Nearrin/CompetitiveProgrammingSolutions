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
int n;vector<int>to[100010];
int bg[100010],ed[100010],ti;
void dfs(int u,int p){
	bg[u]=++ti;
	vp(i,to[u])if(to[u][i]!=p)dfs(to[u][i],u);
	ed[u]=ti;
}
int sum[100010*4];
void add(int x,int l,int r,int b,int e){
	if(b<=l&&e>=r)++sum[x];
	else{
		int m=(l+r)/2;
		if(b<=m)add(x*2,l,m,b,e);
		if(e>m)add(x*2+1,m+1,r,b,e);
	}
}
int ask(int x,int l,int r,int p){
	if(l==r)return sum[x];
	else{
		int m=(l+r)/2;
		if(p<=m)return ask(x*2,l,m,p)+sum[x];
		else return ask(x*2+1,m+1,r,p)+sum[x];
	}
}
int main(){
	sf("%d",&n);
	lp(i,2,n){
		int a,b;sf("%d%d",&a,&b);
		to[a].pb(b);
		to[b].pb(a);
	}
	dfs(1,0);
	lp(i,1,n){
		int t;sf("%d",&t);
		pf("%d\n",ask(1,1,n,bg[t]));
		add(1,1,n,bg[t],ed[t]);
	}
	return 0;
}
