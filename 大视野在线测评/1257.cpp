#include<cstdio>
#include<algorithm>
#define sf scanf
#define pf printf
#define fr(a,b,c) freopen(a,b,c)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long ll;
ll n,k;
int main(){
	//fr("data.in","r",stdin);
	//fr("hehe.out","w",stdout);
	sf("%lld%lld",&n,&k);
	ll ans=0;
	if(n>k)ans+=(n-k)*k,n=k;
	for(ll i=1;i<=n;){
		ll t=k/i,j=min(n,k/t);
		ans+=(j-i+1)*k-t*(j-i+1)*(i+j)/2;
		i=j+1;
	}
	pf("%lld\n",ans);
	return 0;
}
