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
/*A
ΣΣ[i=1->n,j=1->m,i!=j](n%i)*(m%j)
=ΣΣ[i=1->n,j=1->m](n%i)*(m%j)-Σ[i=1->min(n,m)](n%i)*(m%i)
=ΣΣ[i=1->n,j=1->m](n-n/i*i)*(m-m/j*j)-Σ[i=1->min(n,m)](n-n/i*i)*(m-m/i*i)
=ΣΣ[i=1->n,j=1->m]nm-ΣΣ[i=1->n,j=1->m]n*m/j*j-ΣΣ[i=1->n,j=1->m]m*n/i*i+ΣΣ[i=1->n,j=1->m]i*j*n/i*m/j-Σ[i=1->min(n,m)](n-n/i*i)*(m-m/i*i)
=n^2*m^2-n^2*Σ[j=1->m]m/j*j-m^2*Σ[i=1->n]n/i*i+ΣΣ[i=1->n,j=1->m]i*j*n/i*m/j-Σ[i=1->min(n,m)](n-n/i*i)*(m-m/i*i)
=n^2*m^2-n^2*Σ[j=1->m]m/j*j-m^2*Σ[i=1->n]n/i*i+ΣΣ[i=1->n,j=1->m]i*j*n/i*m/j-min(n,m)*n*m+n*Σ[i=1->min(n,m)]m/i*i+m*Σ[i=1->min(n,m)]n/i*i-Σ[i=1->min(n,m)]i*i*n/i*m/i

subtask1:O(1)
n^2*m^2

subtask2:O(sqrt(m))
-n^2*Σ[j=1->m]m/j*j

subtask3:O(sqrt(n))
-m^2*Σ[i=1->n]n/i*i

subtask4:O(sqrt(n)+sqrt(m))
ΣΣ[i=1->n,j=1->m]i*j*n/i*m/j
=(Σ[i=1->n]i*n/i)*(Σ[j=1->m]j*m/j)

subtask5:O(1)
-min(n,m)*n*m

subtask6:O(sqrt(m))
n*Σ[i=1->min(n,m)]m/i*i

subtask7:O(sqrt(n))
m*Σ[i=1->min(n,m)]n/i*i

subtask8:O(sqrt(n)+sqrt(m))
-Σ[i=1->min(n,m)]i*i*n/i*m/i
*/
ll n,m,p=19940417;
ll subtask1(){
	ll r=n*n%p*m%p*m%p;
	return r;
}
ll subtask2(){
	ll r=0;
	for(ll j=1;j<=m;++j){
		ll t=m/(m/j);
		r=(r+(m/j)*((j+t)*(t-j+1)/2%p)%p)%p;
		j=t;
	}
	r=n*n%p*r%p;
	r=(-r+p)%p;
	return r;
}
ll subtask3(){
	ll r=0;
	for(ll i=1;i<=n;++i){
		ll t=n/(n/i);
		r=(r+(n/i)*((i+t)*(t-i+1)/2%p)%p)%p;
		i=t;
	}
	r=m*m%p*r%p;
	r=(-r+p)%p;
	return r;
}
ll subtask4(){
	ll r1=0;
	for(ll j=1;j<=m;++j){
		ll t=m/(m/j);
		r1=(r1+(m/j)*((j+t)*(t-j+1)/2%p)%p)%p;
		j=t;
	}
	ll r2=0;
	for(ll i=1;i<=n;++i){
		ll t=n/(n/i);
		r2=(r2+(n/i)*((i+t)*(t-i+1)/2%p)%p)%p;
		i=t;
	}
	return r1*r2%p;
}
ll subtask5(){
	ll r=min(n,m)*n%p*m%p;
	r=(-r+p)%p;
	return r;
}
ll subtask6(){
	ll r=0;
	for(ll j=1;j<=min(n,m);++j){
		ll t=min(m/(m/j),min(n,m));
		r=(r+(m/j)*((j+t)*(t-j+1)/2%p)%p)%p;
		j=t;
	}
	r=r*n%p;
	return r;
}
ll subtask7(){
	ll r=0;
	for(ll i=1;i<=min(n,m);++i){
		ll t=min(n/(n/i),min(n,m));
		r=(r+(n/i)*((i+t)*(t-i+1)/2%p)%p)%p;
		i=t;
	}
	r=r*m%p;
	return r;
}
ll subtask8calc(ll x){
	ll t1=x,t2=x+1,t3=2*x+1;
	if(t1%2==0)t1/=2;
	else t2/=2;
	if(t1%3==0)t1/=3;
	else if(t2%3==0)t2/=3;
	else t3/=3;
	return t1*t2%p*t3%p;
}
ll subtask8(){
	ll r=0;
	for(ll i=1;i<=min(n,m);++i){
		ll t=min(min(n/(n/i),m/(m/i)),min(n,m));
		ll t1=subtask8calc(t);
		ll t2=subtask8calc(i-1);
		ll t3=(t1-t2+p)%p;
		r=(r+t3*(n/i)%p*(m/i)%p)%p;
		i=t;
	}
	r=(-r+p)%p;
	return r;
}
ll brute(){
	ll r=0;
	lp(i,1,n)lp(j,1,m)if(i!=j)r=(r+(n%i)*(m%j))%p;
	return r;
}
int main(){
	sf("%lld%lld",&n,&m);
	pf("%lld\n",(subtask1()+subtask2()+subtask3()+subtask4()
		+subtask5()+subtask6()+subtask7()+subtask8())%p);
	//pf("%lld\n",brute());
	return 0;
}
