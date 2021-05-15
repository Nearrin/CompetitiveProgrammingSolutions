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
#include<map>
#include<cmath>
ll qpow(ll x,ll y,ll z){
	ll r=1;
	while(y){
		if(y&1)r=r*x%z;
		x=x*x%z;
		y>>=1;
	}
	return r;
}
ll bsgs(ll a,ll b,ll c){
    ll m=ll(sqrt(double(c-1))+0.5);
    map<ll,ll>pm;
    lp(i,0,m-1)pm[qpow(a,i,c)]=i;
    lp(i,0,(c-1)/m){
        ll t=qpow(qpow(a,i*m,c),c-2,c)*b%c;
        if(pm.count(t))return pm[t]+i*m;
    }
    return -1;
}
int main(){
	ll a,b,c;
	while(sf("%lld%lld%lld",&c,&a,&b)!=EOF){
		ll ans=bsgs(a,b,c);
		if(ans==-1)pf("no solution\n");
		else pf("%lld\n",ans);
	}
	return 0;
}
