#include<cstdio>
#include<algorithm>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
ll sum[50010],mui[50010],pri[50010],isp[50010];
ll solve(ll a,ll b){
    if(a==0||b==0)return 0;
    ll r=0;
    for(ll i=1;i<=min(a,b);++i){
        ll t1=(a/i),t2=(b/i);
        ll j=min(a/t1,b/t2);
        r+=(sum[j]-sum[i-1])*t1*t2;
        i=j;
    }
    return r;
}
int main(){
    mui[1]=1;
    lp(i,2,50005){
        if(!isp[i]){
            pri[++pri[0]]=i;
            mui[i]=-1;
        }
        for(int j=1;j<=pri[0]&&pri[j]*i<=50005;++j){
            if(i%pri[j]==0){
                isp[i*pri[j]]=1;
                mui[i*pri[j]]=0;
            }else{
                isp[i*pri[j]]=1;
                mui[i*pri[j]]=-mui[i];
            }
        }
    }
    lp(i,1,50005)sum[i]=sum[i-1]+mui[i];
    int n;sf("%d",&n);
    lp(i,1,n){
        ll a,b,c,d,k;
        sf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&k);
        a=(a-1)/k;
        b/=k;
        c=(c-1)/k;
        d/=k;
        pf("%lld\n",solve(b,d)-solve(a,d)-solve(b,c)+solve(a,c));
    }
    //ps;
    return 0;
}
