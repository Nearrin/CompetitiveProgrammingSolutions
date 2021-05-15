#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<queue>
#include<utility>
#include<cmath>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
ll check(ll n){
    ll r=0;
    for(ll i=1;i*i<n;++i){
        ll j=n-i*i;
        ll k=sqrt(double(j));
        if(k*k>j)--k;
        if(k*k<j)++k;
        if(k*k==j){
            if(gcd(i,k)==1&&(i+k)%2==1&&i>k){
                ++r;
            }
        }
    }
    return r;
}
int main(){
    ll n,a=0;
    sf("%lld",&n);
    for(ll i=1;i*i<=n;++i){
        if(n%i==0){
            a+=check(n/i);
            if(i*i!=n)a+=check(i);
        }
    }
    pf("%lld\n",a*8+4);
    //ps;
    return 0;
} 
