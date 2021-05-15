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
ll f(ll n,ll k){
	if(n<=k||n%2!=k%2)return 1;
	else return f((n+k)/2,k)+f((n-k)/2,k);
}
int main(){
	ll n,k;sf("%lld%lld",&n,&k);
	pf("%lld\n",f(n,k));
    return 0;
}
