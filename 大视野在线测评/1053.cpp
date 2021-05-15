#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<cstdlib>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define pb push_back
#define mp make_pair
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
#define vp(i,v) for(int i=0;i<v.size();++i)
using namespace std;
typedef long long ll;
ll pr[9]={2,3,5,7,11,13,17,19,23},n,tcnt,tans;
void dfs(ll lev,ll cnt,ll ans,ll pre){
	if(lev==9){
		if(cnt>tcnt||(cnt==tcnt&&ans<tans))
			tcnt=cnt,tans=ans;
	}else{
		for(ll i=0;i<=pre&&ans<=n;++i){
			dfs(lev+1,cnt*(i+1),ans,i);
			ans*=pr[lev];
		}
	}
}
int main(){
	sf("%lld",&n);
	dfs(0,1,1,~0u>>1);
	pf("%lld\n",tans);
	//ps;
	return 0;
}
