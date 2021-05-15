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
#include<stack>
int ans=0,n,a[50010];
void solve(){
	stack<int>stk;
	lp(i,1,n){
		while(!stk.empty()&&a[stk.top()]<a[i]){
			int l=stk.top(),r=i;
			int k=a[stk.top()];
			lp(j,l+1,r)ans=max(ans,(k^a[j]));
			for(int j=r+1;j<=n&&a[j]<k;++j)
				ans=max(ans,(k^a[j]));
			for(int j=l-1;j&&a[j]<k;--j)
				ans=max(ans,(k^a[j]));
			stk.pop();
		}
		stk.push(i);
	}
}
int main(){
	sf("%d",&n);
	lp(i,1,n)sf("%d",&a[i]);
	solve();
	reverse(a+1,a+n+1);
	solve();
	pf("%d\n",ans);
	return 0;
}
