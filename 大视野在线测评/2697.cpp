#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int n,k,c[310];
int main(){
    sf("%d%d",&n,&k);
    lp(i,1,k)sf("%d",&c[i]);
    sort(c+1,c+k+1);
    int ans=0;
    for(int i=k;i;--i){
        if(n<2)break;
        ans+=(n-1)*c[i];
        n-=2;
    }
    pf("%d\n",ans);
    //ps;
    return 0;
}
