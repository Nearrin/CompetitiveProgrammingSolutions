#include<cstdio>
#include<algorithm>
#define sf scanf
#define pf printf
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int n;
struct cow{int w,s;}cs[50010];
bool operator<(cow a,cow b){return a.w+a.s<b.w+b.s;}
int main(){
    sf("%d",&n);
    lp(i,1,n)sf("%d%d",&cs[i].w,&cs[i].s);
    sort(cs+1,cs+n+1);
    int ans=-(~0u>>1),sum=0;
    lp(i,1,n){ans=max(ans,sum-cs[i].s);sum+=cs[i].w;}
    pf("%d\n",ans);//ps;
    return 0;
}
