#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#include<utility>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>

int n,m,d[110],c[110][21];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>d[i];
        for(int j=1;j<=m;++j){
            cin>>c[i][j];
        }
    }
    static int dp[110][70010];
    for(int i=1;i<=n;++i){
        if(i==1){

                for(int s=0;s<(1<<m);++s){
                    if(s==0)
                        dp[i][s]=0;
                    else{
                        dp[i][s]=d[i];
                        for(int j=1;j<=m;++j){
                            if((s>>(j-1))&1){
                                dp[i][s]+=c[i][j];
                            }
                        }
                    }
                }
        }
        else{
             for(int s=0;s<(1<<m);++s){
                 dp[i][s]=dp[i-1][s]+d[i];
             }
             for(int j=1;j<=m;++j){
                  for(int s=0;s<(1<<m);++s){
                      if(((s>>(j-1))&1)==0)
                          dp[i][s + (1 <<( j - 1))] = min(dp[i][s + (1 <<( j - 1))], dp[i][s] + c[i][j]);
                  }
             }
             for(int s=0;s<(1<<m);++s)
                 dp[i][s]=min(dp[i][s],dp[i-1][s]);
        }
    }
    printf("%d\n",dp[n][(1<<m)-1]);
    return 0;
}
