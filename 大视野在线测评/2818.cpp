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
ll phi[10000010],pri[10000010];
bool isp[10000010];
int main(){
    ll n;sf("%lld",&n);
    phi[1]=1;
    lp(i,2,n){
        if(!isp[i]){
            pri[++pri[0]]=i;
            phi[i]=i-1;
        }
        for(int j=1;j<=pri[0]&&pri[j]*i<=n;++j){
            if(i%pri[j]==0){
                isp[i*pri[j]]=1;
                phi[i*pri[j]]=phi[i]*pri[j];
                break;
            }else{
                isp[i*pri[j]]=1;
                phi[i*pri[j]]=phi[i]*(pri[j]-1);
            }
        }
    }
    //lp(i,1,20)pf("%lld\n",phi[i]);
    lp(i,1,n)phi[i]+=phi[i-1];
    ll ans=0;
    lp(i,1,pri[0]){
        ans+=phi[n/pri[i]]*2-1;
    }
    pf("%lld\n",ans);
    //ps;
    return 0;
}
