#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<deque>
#include<cstdlib>
#include<stack>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define pb push_back
#define mp make_pair
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
#define vp(i,v) for(int i=0;i<v.size();++i)
using namespace std;
typedef long long ll;
int main(){
    ll n,a=0;sf("%lld",&n);n=2*n+1;
    for(ll i=1;i*i<=n;++i){
        if(n%i==0)a+=i;
        if(n%i==0&&i*i!=n)a+=n/i; 
    } 
    pf("%lld\n",a);
    //ps;
    return 0;
} 
