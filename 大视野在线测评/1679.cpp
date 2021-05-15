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
int n;ll a[10010],s[10010];
int main(){
	sf("%d",&n);
	lp(i,1,n)sf("%lld",&a[i]);
	sort(a+1,a+n+1);
	lp(i,1,n)s[i]=s[i-1]+a[i];
	ll ans=0;
	lp(i,1,n)ans+=a[i]*(i-1)-s[i-1]+s[n]-s[i]-a[i]*(n-i);
	pf("%lld\n",ans);
	return 0;
}
