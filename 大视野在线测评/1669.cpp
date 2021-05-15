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
int main(){
	int n;sf("%d",&n);vector<ll>f;
	lp(i,1,n){
		ll t;sf("%lld",&t);
		if(f.empty()||f.back()<t)f.pb(t);
		else *lower_bound(f.begin(),f.end(),t)=t;
	}
	pf("%d\n",int(f.size()));
    return 0;
}
