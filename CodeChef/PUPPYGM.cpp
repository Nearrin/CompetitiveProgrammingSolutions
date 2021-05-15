#include <iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int dp[210][210];
int vis[210][210];
void calc(int i,int j){
    if(vis[i][j])return;
    vis[i][j]=1;
    for(int k=1;k<j;++k){
        calc(k,j-k);
        if(!dp[k][j-k]){
            dp[i][j]=1;
        }
    }
    for(int k=1;k<i;++k){
        calc(k,i-k);
        if(!dp[k][i-k]){
            dp[i][j]=1;
        }
    }
}

int main()
{
//    freopen("1.txt","w",stdout);
//    calc(200,200);
//    for(int i=1;i<=200;++i){
//        for(int j=1;j<=200;++j){
//                 if(i<=j&&dp[i][j])printf("(%d,%d):%d\n",i,j,dp[i][j]);
//            }

//        }
int T;scanf("%d",&T);
while(T--){
    int x,y;
    scanf("%d%d",&x,&y);
    if(x>y)
        swap(x,y);
    int ans=0;
    if(x%2==1&&y%2==0)
        ans=1;
    if(x%2==0)
        ans=1;
    if(ans)printf("Tuzik\n");
    else printf("Vanka\n");
}
    return 0;
}
