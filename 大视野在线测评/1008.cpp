#include<cstdio>
#include<algorithm>
#define sf scanf
#define pf printf
#define fr(a,b,c) freopen(a,b,c)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long ll;
ll pmod(ll a,ll b){
	ll r=1;
	while(b){
		if(b&1)r=r*a%100003;
		a=a*a%100003;
		b>>=1;
	}
	return r;
}
int main(){
	//fr("data.in","r",stdin);
	//fr("hehe.out","w",stdout);
	ll m,n;sf("%lld%lld",&m,&n);
	pf("%lld\n",((pmod(m,n)-m*pmod(m-1,n-1))%100003+100003)%100003);
    return 0;
} 
