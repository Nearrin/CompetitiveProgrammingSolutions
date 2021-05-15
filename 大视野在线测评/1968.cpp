#include<cstdio>
#include<algorithm>
#include<vector>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long ll;
int main(){
    ll n,ans=0;sf("%lld",&n);
    for(ll i=1;i<=n;++i)ans+=n/i;
    pf("%lld\n",ans);
    //ps;
    return 0;
}
