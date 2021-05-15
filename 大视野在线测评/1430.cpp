#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long ll;
ll p=9999991;
ll pmod(ll a,ll b,ll c){
    ll r=1;
    while(b){
        if(b&1)r=r*a%c;
        a=a*a%c;
        b>>=1;
    }
    return r;
}
ll fac(ll a,ll b){
    ll r=1;
    for(ll i=1;i<=a;++i)r=r*i%b;
    return r;
}
int main(){
    ll n;sf("%lld",&n);
    pf("%lld\n",pmod(n,n-2,p)*fac(n-1,p)%p);
    //ps;
    return 0;
}
