#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
int main(){
    int n;sf("%d",&n);
    static int a[10010];
    lp(i,1,n)sf("%d",&a[i]);
    sort(a+1,a+n+1);
    pf("%d\n",a[(n+1)/2]); 
    //ps;
    return 0; 
} 
