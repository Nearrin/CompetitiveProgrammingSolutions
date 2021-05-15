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
ll p=20100403;
ll fac[2000010],n,m;
ll inv(ll a){
	ll ret=1;
	for(int i=p-2;i;i>>=1){
		if(i&1)ret=ret*a%p;
		a=a*a%p;
	}
	return ret;
}
ll calc(ll n,ll r){
	return fac[n]*inv(fac[r]*fac[n-r]%p)%p;
}
int main(){
	sf("%lld%lld",&n,&m);
	if(n<m)pf("0\n");
	else{
		fac[0]=1;
		lp(i,1,n+m)fac[i]=fac[i-1]*i%p;
		pf("%lld\n",(calc(n+m,m)-calc(n+m,m-1)+p)%p);
	}
	return 0;
}
