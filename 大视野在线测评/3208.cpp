#include<cstdio>
#include<algorithm>
#include<queue>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
int n,m,a[710][710],b[710][710],p[710][710];
struct data{
    int x,y;
};
bool operator<(data x,data y){
    return a[x.x][x.y]<a[y.x][y.y];
}
bool ava(int x,int y){
    return x>=1&&x<=n&&y>=1&&y<=n&&!b[x][y];
}
int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
int ind[710][710],dp[710][710];
int dfs(int x,int y){
    if(ind[x][y])return dp[x][y];
    ind[x][y]=1;dp[x][y]=1;
    lp(j,0,3){
        int tx=x+dir[j][0],ty=y+dir[j][1];
            if(ava(tx,ty)&&a[tx][ty]<a[x][y]){
                dp[x][y]=max(dp[x][y],dfs(tx,ty)+1);
            }
        }
    return dp[x][y];
} 
int dpp(){
    int flg=0;
    lp(i,1,n)lp(j,1,n)if(!b[i][j]){
       ind[i][j]=0;
       flg=1;
    }
    if(!flg)return 0;
    int ans=0;
    lp(i,1,n)lp(j,1,n)if(!b[i][j]){
       ans=max(ans,dfs(i,j));
    }
    return ans;
}
int main(){
    sf("%d",&n);
    lp(i,1,n)lp(j,1,n)sf("%d",&a[i][j]);
    sf("%d",&m);
    lp(i,1,m){
        char op[11];sf("%s",op);
        if(op[0]=='C'){
            int x,y,z;sf("%d%d%d",&x,&y,&z);
            a[x][y]=z;
        }else if(op[0]=='S'){
            int x1,y1,x2,y2;sf("%d%d%d%d",&x1,&y1,&x2,&y2);
            lp(j,x1,x2)lp(k,y1,y2)b[j][k]=1; 
        }else if(op[0]=='B'){
            int x1,y1,x2,y2;sf("%d%d%d%d",&x1,&y1,&x2,&y2);
            lp(j,x1,x2)lp(k,y1,y2)b[j][k]=0; 
        }else{
            pf("%d\n",dpp());
        }
    }
    //ps;
    return 0;
}
/*
3
1 2 3
1 2 3
1 2 3
1
Q
*/
