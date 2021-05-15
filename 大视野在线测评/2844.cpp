#include<cstdio>
#include<algorithm>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int a[100010],n,q;
int main(){
    sf("%d",&n);
    lp(i,1,n)sf("%d",&a[i]);
    int l=0;
    for(int i=30;i>=0;--i){
        int j=l+1;while(j<=n&&!((a[j]>>i)&1))++j;
        if(j<=n){
            swap(a[j],a[++l]);
            lp(k,1,n)if(k!=l&&((a[k]>>i)&1))a[k]^=a[l];
        }
    }
    //lp(i,1,l)pf("[%d]",a[i]);ps;
    long long ans=0;
    sf("%d",&q);
    lp(i,1,l){
        int j=30;while(!((a[i]>>j)&1))--j;
        if((q>>j)&1){
            q^=a[i];
            ans=(ans+(1ll<<(l-i)))%10086;
        }
    }
    lp(i,1,n-l)ans=ans*2%10086;
    //ans=ans*(1ll<<(n-l))%10086;//long long dead... 
    ans=(ans+1)%10086;
    pf("%lld\n",ans);
    //ps;
    return 0;
}
