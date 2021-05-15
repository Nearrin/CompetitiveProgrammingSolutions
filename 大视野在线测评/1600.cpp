#include<cstdio>
#include<algorithm>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
ll dp[5][3010];
int main(){
    int n;sf("%d",&n);
    dp[0][0]=1;
    lp(i,1,4)
        lp(j,1,n)
            for(int k=1;2*k<n;++k)
                if(j>=k)
                    dp[i][j]+=dp[i-1][j-k];
    pf("%lld\n",dp[4][n]);
    //ps;
    return 0;
} 
