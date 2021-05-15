#include <iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;
const int inf=(~0u>>2);
char l1[200010],l2[200010];
int len;
int dp[200010][3];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%s%s",l1+1,l2+1);
        len=strlen(l1+1);
        for(int i=len;i>=1;--i){
            if(i==len){
                if(l1[i]=='#')
                    dp[i][1]=inf;
                else
                    dp[i][1]=0;
                if(l2[i]=='#')
                    dp[i][2]=inf;
                else
                    dp[i][2]=0;
            }else{
                if(l1[i]=='#')
                    dp[i][1]=inf;
                else{
                    dp[i][1]=inf;
                    dp[i][1]=min(dp[i][1],dp[i+1][1]);
                    dp[i][1]=min(dp[i][1],dp[i+1][2]+1);
                }
                if(l2[i]=='#')
                    dp[i][2]=inf;
                else{
                    dp[i][2]=inf;
                    dp[i][2]=min(dp[i][2],dp[i+1][2]);
                    dp[i][2]=min(dp[i][2],dp[i+1][1]+1);
                }
                dp[i][1]=min(dp[i][1],dp[i][2]+1);
                dp[i][2]=min(dp[i][2],dp[i][1]+1);
            }
        }
        int ans=min(dp[1][1],dp[1][2]);
        if(ans==inf)printf("No\n");
        else printf("Yes\n%d\n",ans);
    }
    return 0;
}
