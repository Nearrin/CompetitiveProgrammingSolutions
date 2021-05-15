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
ll n,d,s[100010],x[100010];
double slope(pair<ll,ll>a,pair<ll,ll>b){
	return (a.second-b.second)/double(a.first-b.first);
}
int main(){
	sf("%lld%lld",&n,&d);
	lp(i,1,n){
		sf("%lld%lld",&s[i],&x[i]);
		s[i]+=s[i-1];
	}
	vector<pair<ll,ll> >pts;
	double ans=0;
	lp(i,1,n){
		while(pts.size()>2){
			pair<ll,ll>a=pts[pts.size()-2],b=pts.back();
			if(slope(a,b)>slope(b,mp(i*d,s[i-1]))-1e-8)pts.pop_back();
			else break;
		}
		pts.pb(mp(i*d,s[i-1]));
		int l=0,r=pts.size()-1;
		while(r-l>=3){
			int m1=l+(r-l)/3,m2=r-(r-l)/3;
			if(slope(pts[m1],mp(x[i]+i*d,s[i]))>slope(pts[m2],mp(x[i]+i*d,s[i])))
				r=m2;
			else
				l=m1;
		}
		/*if(i==2){
			vp(j,pts)pf("(%lld,%lld)\n",pts[j].first,pts[j].second);
			pf("(%lld,%lld)\n",x[i]+i*d,s[i]);
			pf("[%d,%d]\n",l,r);
		}*/
		double tans=0;
		lp(j,l,r)tans=max(tans,slope(pts[j],mp(x[i]+i*d,s[i])));
		//pf("%lf\n",tans);
		ans+=tans;
	}
	pf("%.0lf\n",ans);
	return 0;
}
