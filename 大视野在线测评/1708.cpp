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
int n,v,a[31];
ll f[10010];
int main(){
    sf("%d%d",&n,&v);
    lp(i,1,n)sf("%d",&a[i]);
    f[0]=1;
    lp(i,1,n)lp(j,0,v){
        if(j>=a[i])
            f[j]+=f[j-a[i]];
    }
    pf("%lld\n",f[v]);
    //ps;
    return 0;
} 
