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
namespace hug{
	int cx,cy;vector<int>to[210];int lk[210],vi[210];
	int dfs(int u){
		vp(i,to[u]){
			int v=to[u][i];
			if(!vi[v]){
				vi[v]=1;
				if(!lk[v]||dfs(lk[v])){
					lk[v]=u;
					return 1;
				}
			}
		}
		return 0;
	}
	int solve(){
		int r=0;
		lp(i,1,cx){
			fill(vi+1,vi+cy+1,0);
			r+=dfs(i);
		}
		return r;
	}
}
int fld[210][210],n,m;
int main(){
	sf("%d%d",&n,&m);
	lp(i,1,m){
		int a,b;sf("%d%d",&a,&b);
		fld[a][b]=1;
	}
	lp(k,1,n)lp(i,1,n)lp(j,1,n)if(fld[i][k]&&fld[k][j])fld[i][j]=1;
	hug::cx=hug::cy=n;
	lp(i,1,n)lp(j,1,n)if(fld[i][j])hug::to[i].pb(j);
	pf("%d\n",n-hug::solve());
	return 0;
}
