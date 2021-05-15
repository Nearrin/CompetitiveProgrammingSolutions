#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>
#include<map>
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
	int test;sf("%d",&test);
	lp(kase,1,test){
		ll p,a,b,x1,t;
		sf("%lld%lld%lld%lld%lld",&p,&a,&b,&x1,&t);
		if(a==0){
			if(t==x1)pf("1\n");
			else if(t==b)pf("2\n");
			else pf("-1\n");
		}else if(a==1){
			if(b==0){
				if(x1==t)pf("1\n");
				else pf("-1\n");
			}else{
				ll u=b,v=((t-x1+b)%p+p)%p;
				ll ans=v*qpow(u,p-2,p)%p;
				pf("%lld\n",ans==0?p:ans);
			}
		}else{
			ll u=((a*t-t+b)%p+p)%p;
			ll v=((a*x1-x1+b)%p+p)%p;
			if(v==0){
				if(u==0)pf("1\n");
				else pf("-1\n");
			}else{
				u=u*qpow(v,p-2,p)%p;
				ll ans=bsgs(a,u,p);
				pf("%lld\n",ans==-1?-1:ans+1);
			}
		}
	}
	return 0;
}
/*
3
7 1 1 3 3
7 2 2 2 0
7 2 2 2 1
*/
