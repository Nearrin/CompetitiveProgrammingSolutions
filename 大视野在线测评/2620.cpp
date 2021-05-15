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
int n;ll a[100010],b[100010],s[100010];
int main(){
	sf("%d",&n);
	lp(i,1,n)sf("%lld%lld",a+i,b+i);
	lp(i,2,n)s[i]=s[i-1]+a[i-1]-b[i-1];
	sort(s+1,s+n+1);
	ll t=s[(n+1)/2];
	ll ans=0;
	lp(i,1,n)if(s[i]>t)ans+=s[i]-t;else ans+=t-s[i];
	pf("%lld\n",ans);
	return 0;
}
