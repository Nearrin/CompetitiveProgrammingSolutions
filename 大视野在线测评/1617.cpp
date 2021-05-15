#include<cstdio>
#include<algorithm>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
int n,m,c[2510],f[2500];
int main(){
    sf("%d%d",&n,&m);
    lp(i,1,n)sf("%d",&c[i]),c[i]+=c[i-1];
    lp(i,1,n)f[i]=m+c[i];
    lp(i,1,n)lp(j,1,i-1)f[i]=min(f[i],f[i-j]+m+c[j]+m);
    pf("%d\n",f[n]);
    //ps;
    return 0;
}
