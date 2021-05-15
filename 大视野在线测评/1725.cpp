#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define pb push_back
#define mp make_pair
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
#define vp(i,v) for(int i=0;i<v.size();++i)
#define wp(i,v) for(int i=int(v.size()-1);i>=0;--i)
typedef long long ll;
using namespace std;
int n,m,forbid[21][21],p=100000000,dp[21][21][10010];
int main(){
    sf("%d%d",&n,&m);
    lp(i,1,n)lp(j,1,m){
        sf("%d",&forbid[i][j]);
        forbid[i][j]^=1;
    }
    dp[0][m][0]=1;
    lp(i,0,n)lp(j,1,m)lp(k,0,(1<<m)-1){
        if(j==m){
            if(!(k&1)&&!forbid[i+1][1]){
                dp[i+1][1][k+1]+=dp[i][j][k];
                dp[i+1][1][k+1]%=p;
            }
            int t=k;if(t&1)--t;
            dp[i+1][1][t]+=dp[i][j][k];
            dp[i+1][1][t]%=p;
        }else{
            if(!((k>>(j-1))&1)&&!((k>>j)&1)&&!forbid[i][j+1]){
                dp[i][j+1][k+(1<<j)]+=dp[i][j][k];
                dp[i][j+1][k+(1<<j)]%=p;
            }
            int t=k;if((t>>j)&1)t-=(1<<j);
            dp[i][j+1][t]+=dp[i][j][k];
            dp[i][j+1][t]%=p;
        }
    }
    int ans=0;
    lp(i,0,(1<<m)-1){
        ans+=dp[n][m][i];
        ans%=p;
    }
    pf("%d\n",ans);
    //ps;
    return 0;
}
