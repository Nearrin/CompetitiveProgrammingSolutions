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
/*
1/x+1/y=1/z的正整数解个数为z^2的约数个数
*/
ll pri[1000010],isp[1000010],n,p=1000000007;
ll fac(ll x,ll y){
	ll r=0;
	while(x){
		r+=x/y;
		x/=y;
	}
	return r;
}
ll ans[1000010];
int main(){
	sf("%lld",&n);
	lp(i,2,n){
		if(!isp[i])pri[++pri[0]]=i;
		for(int j=1;j<=pri[0]&&pri[j]*i<=n;++j){
			isp[pri[j]*i]=1;
			if(i%pri[j]==0)break;
		}
	}
	lp(i,1,pri[0])ans[i]=fac(n,pri[i])*2;
	ll t1=1;
	lp(i,1,pri[0])t1=t1*(ans[i]+1)%p;
	pf("%lld\n",t1);
	return 0;
}
