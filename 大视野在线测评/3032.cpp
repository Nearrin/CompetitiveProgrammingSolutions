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
namespace calc{
	int n;ll a[1000010],b[1000010],s[1000010];
	ll solve(){
		ll tsum=0;
    	lp(i,1,n)tsum+=a[i];
    	if(tsum%n!=0)return -1;
    	lp(i,1,n)b[i]=tsum/n;
		s[1]=0;
		lp(i,2,n)s[i]=s[i-1]+a[i-1]-b[i-1];
		sort(s+1,s+n+1);
		ll t=s[(n+1)/2];
		ll ans=0;
		lp(i,1,n)if(s[i]>t)ans+=s[i]-t;else ans+=t-s[i];
		return ans;
	}
}
int main(){
	int n,m,t;vector<pair<int,int> >a;
	sf("%d%d%d",&n,&m,&t);
	lp(i,1,t){
		int x,y;sf("%d%d",&x,&y);
		a.pb(mp(x,y));
	}
	int f0=0,f1=0;
	ll ans=0;
	calc::n=n;
	lp(i,1,n)calc::a[i]=0;
	vp(i,a)++calc::a[a[i].first];
	ll tt=calc::solve();
	if(tt==-1)f0=1;
	else ans+=tt;
	calc::n=m;
	lp(i,1,m)calc::a[i]=0;
	vp(i,a)++calc::a[a[i].second];
	tt=calc::solve();
	if(tt==-1)f1=1;
	else ans+=tt;
	if(f1&&f0)pf("impossible\n");
	else if(f1)pf("row %lld\n",ans);
	else if(f0)pf("column %lld\n",ans);
	else pf("both %lld\n",ans);
	return 0;
}
