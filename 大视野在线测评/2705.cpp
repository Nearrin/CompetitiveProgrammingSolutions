#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<queue>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long ll;
ll phi(ll n){
    ll r=n;
    for(ll i=2;i*i<=n;++i){
        if(n%i==0){
            r=r/i*(i-1);
            while(n%i==0)n/=i;
        }
    }
    if(n!=1)r=r/n*(n-1);
    return r;
}
int main(){
    //lp(i,1,10)pf("%d\n",phi(i));
    ll n;sf("%lld",&n);ll ans=0;
    for(ll i=1;i*i<=n;++i){
        if(n%i==0){
            ans+=phi(n/i)*i;
            if(i*i!=n)
                ans+=phi(i)*(n/i);
        }
    }
    pf("%lld\n",ans);//ps;
    return 0;
}
