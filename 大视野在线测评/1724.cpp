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
#include<queue>
#include<functional>
int main(){
	priority_queue<ll,vector<ll>,greater<ll> >qu;
	int n;ll ans=0;sf("%d",&n);
	lp(i,1,n){
		int t;sf("%d",&t);
		qu.push(t);
	}
	while(qu.size()>1){
		ll u1=qu.top();qu.pop();
		ll u2=qu.top();qu.pop();
		ans+=u1+u2;
		qu.push(u1+u2);
	}
	pf("%lld\n",ans);
	return 0;
}
