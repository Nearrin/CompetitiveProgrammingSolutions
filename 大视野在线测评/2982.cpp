#include<cstdio>
#include<algorithm>
#include<vector>
#define sf scanf
#define pf printf
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long ll;
ll exgcd(ll a,ll b,ll&x,ll&y){
    if(!b){x=1,y=0;return a;}
    else{ll r=exgcd(b,a%b,y,x);y-=a/b*x;return r;}
}
ll fac[10010];
ll com(int n,int k,int p){
    if(n<k)return 0;
    ll t1=fac[n],t2=fac[k]*fac[n-k]%p;
    ll x,y;
    exgcd(t2,p,x,y);
    return (t1*x%p+p)%p;
}
ll lucas(int n,int k,int p){
    if(!n&&!k)return 1;
    else return com(n%p,k%p,p)*lucas(n/p,k/p,p)%p;
}
int main(){
    fac[0]=1;
    lp(i,1,10010)fac[i]=fac[i-1]*i%10007;
    int T;sf("%d",&T);
    lp(test,1,T){
        int n,k;sf("%d%d",&n,&k);
        pf("%lld\n",lucas(n,k,10007));
    }//ps;
    return 0;
}
