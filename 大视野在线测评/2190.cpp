#include<cstdio>
#include<algorithm>
#include<cstdlib>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
int phi(int n){
    int r=n;
    for(int i=2;i*i<=n;++i){
        if(n%i==0){
            r/=i;r*=i-1;
            while(n%i==0)n/=i;
        }
    }
    if(n!=1)r/=n,r*=n-1;
    return r;
} 
int main(){
    int n;sf("%d",&n);
    long long ans=0;
    lp(i,2,n-1)ans+=phi(i);
    ans*=2;
    ans+=3;
    pf("%lld\n",ans);
    //ps;
    return 0;
}
