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
∑[i=1->n]∑[j=1->m]lcm(i,j)
=∑[d=1->min(n,m)]f(n/d,m/d)*d
f(a,b,x)=∑[i=1->a]∑[j=1->b,(i,j)=x]ij
g(a,b,x)=∑[i=1->a/x]∑[j=1->b/x]ij*x*x=a/x(a/x+1)b/x(b/x+1)/4*x*x
g(a,b,x)=∑[x|y]f(a,b,y)
f(a,b,x)=∑[x|y]g(a,b,y)*u(y/x)
f(a,b,1)=∑[d=1->min(a,b)]g(a,b,d)*u(d)
*/
ll p=20101009;
namespace brute{
	ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
	ll solve(ll n,ll m){
		ll ret=0;
		lp(i,1,n)lp(j,1,m)ret=(ret+i*j/gcd(i,j))%p;
		return ret;
	}
}
namespace task{
	ll g(ll a,ll b,ll d){
		ll t1=a/d,t2=a/d+1,t3=b/d,t4=b/d+1;
		if(t1&1)t2/=2;
		else t1/=2;
		if(t3&1)t4/=2;
		else t3/=2;
		return t1*t2%p*t3%p*t4%p;
	}
	ll u[10000010];
	ll f(ll a,ll b){
		ll ret=0;
		for(ll i=1;i<=min(a,b);++i){
			ll j=min(min(a,b),min(a/(a/i),b/(b/i)));
			ll gt=g(a,b,i);
			ret=(ret+(u[j]-u[i-1]+p)*gt)%p;
			i=j;
		}
		return ret;
	}
	ll solve(ll n,ll m){
		static ll isp[10000010],pri[10000010];
		u[1]=1;
		for(ll i=2;i<=min(n,m);++i){
			if(!isp[i]){
				pri[++pri[0]]=i;
				u[i]=-1;
			}
			for(ll j=1;j<=pri[0]&&i*pri[j]<=min(n,m);++j){
				isp[i*pri[j]]=1;
				if(i%pri[j]==0){
					break;
				}else{
					u[i*pri[j]]=-u[i];
				}
			}
		}
		lp(i,1,min(n,m))u[i]=(u[i]+p)*i%p*i%p;
		lp(i,1,min(n,m))u[i]=(u[i]+u[i-1])%p;
		//lp(i,1,50)pf("%d,%lld\n",i,u[i]);
		ll ret=0;
		for(ll i=1;i<=min(n,m);++i){
			ll j=min(min(n,m),min(n/(n/i),m/(m/i)));
			ll ft=f(n/i,m/i);
			ret=(ret+(i+j)*(j-i+1)/2%p*ft)%p;
			i=j;
		}
		return ret;
	}
}
int main(){
	ll n,m;sf("%lld%lld",&n,&m);
	//pf("%lld\n",brute::solve(n,m));
	pf("%lld\n",task::solve(n,m));
	return 0;
}
