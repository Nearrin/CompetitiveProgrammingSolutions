#include<cstdio>
#include<algorithm>
#include<cmath>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
ll comb[110][110],p=10000007;
ll pmd(ll x,ll y){
    ll r=1;
    while(y){
        if(y&1)r=r*x%p;
        x=x*x%p;
        y>>=1;
    }
    return r;
}
ll calc(int d0,int po,ll n){
    if(po==0){
        //pf("[%d,%d,%lld,%lld]\n",d0,po,n,n%2==0?d0:d0*(d0+1)%p);
        if(n%2==0)return d0;
        else return d0*(d0+1)%p;
    }else{
        if(((n>>po)&1)==0)return calc(d0,po-1,n);
        else{
            ll r=1;
            lp(i,(d0==0?1:0),po)r=r*pmd(i+d0,comb[po][i])%p;
            r=calc(d0+1,po-1,n)*r%p;
            //pf("[%d,%d,%lld,%lld]\n",d0,po,n,r);
            return r;
        }
    }
}
int main(){
    lp(i,0,105)
        lp(j,0,i)
            if(j==0||j==i)comb[i][j]=1;
            else comb[i][j]=(comb[i-1][j]+comb[i-1][j-1]);
    ll n;sf("%lld",&n);
    pf("%lld\n",calc(0,59,n));
    //ps;
    return 0;
} 
