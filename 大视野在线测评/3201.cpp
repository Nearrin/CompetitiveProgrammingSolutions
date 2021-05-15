#include<cstdio>
#include<algorithm>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
ll p=1000000007;
ll pmod(ll a,ll b){
    ll r=1;
    while(b){
        if(b&1)r=r*a%p;
        a=a*a%p;
        b>>=1;
    }
    return r;
}
ll com[1010][1010];
ll a[1010],f[1010];int n;
int main(){
    lp(i,0,1005)lp(j,0,i)
        if(j==0||j==i)com[i][j]=1;
        else com[i][j]=(com[i-1][j]+com[i-1][j-1])%p;
    int test;sf("%d",&test);
    lp(kase,1,test){
        sf("%d",&n);
        lp(i,1,n)sf("%lld",&a[i]);
        f[0]=1;
        sort(a+1,a+n+1);
        lp(i,1,n){
            f[i]=pmod(a[i],i);
            lp(j,1,i-1){
                f[i]=(f[i]-f[j-1]*com[i][j-1]%p*pmod(a[i]-a[j],i-j+1)%p+p)%p;
            }
        }
        pf("%lld\n",f[n]); 
    }
    //ps;
    return 0;
}
