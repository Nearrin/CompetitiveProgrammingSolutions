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
	vector<int>to[10010];int vi[1000010],lk[1000010];
	vector<int>tmp;
	int dfs(int u){
		vp(i,to[u]){
			int v=to[u][i];
			if(!vi[v]){
				vi[v]=1;tmp.pb(v);
				if(!lk[v]||dfs(lk[v])){
					lk[v]=u;
					return 1;
				}
			}
		}
		return 0;
	}
}
int main(){
	int n;sf("%d",&n);
	lp(i,1,n){
		int a,b;sf("%d%d",&a,&b);
		hug::to[a].pb(i);
		hug::to[b].pb(i);
	}
	lp(i,1,10001){
		if(hug::dfs(i)){
			vp(j,hug::tmp)hug::vi[hug::tmp[j]]=0;
			hug::tmp.clear();
		}else{pf("%d\n",i-1);break;}
	}
	return 0;
}
