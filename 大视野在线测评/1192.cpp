#include<cstdio>
#include<algorithm>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int main(){
    long long n,ans=0;sf("%lld",&n);
    for(long long i=1;;i*=2){
        if(n>=i)n-=i,++ans;else break; 
    }
    if(n!=0){
        if((n&-n)==n)ans+=1;
        else ans+=1;
    }
    pf("%lld\n",ans);
    //ps;
    return 0;
}
