#include<cstdio>
#include<algorithm>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=n;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
ll a,b,c,f[1000010];
int main(){
    sf("%lld%lld%lld",&a,&b,&c);
    for(ll i=max(a,b);i>=1;--i){
        f[i]=(a/i)*(b/i);
        for(ll j=2;j*i<=max(a,b);++j)
            f[i]-=f[j*i];
    }
    pf("%lld\n",f[c]);
    //ps;
    return 0;
} 
