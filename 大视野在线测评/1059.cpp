#include<cstdio>
#include<algorithm>
#include<vector>
#define sf scanf
#define pf printf
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int cx,cy,eg[310][310],in[310],lk[310];
int dfs(int x){
    lp(y,1,cy){
        if(eg[x][y]&&!in[y]){
            in[y]=1;
            if(!lk[y]||dfs(lk[y])){
                lk[y]=x;
                return 1;
            }
        }
    }
    return 0;
}
int mch(){
    int r=0;
    lp(i,1,cx){
        lp(j,1,cy)in[j]=0;
        r+=dfs(i);
    }
    return r;
}
int main(){
    int test;sf("%d",&test);
    lp(kase,1,test){
        int n;sf("%d",&n);
        cx=cy=n;
        lp(i,1,cx)lp(j,1,cy)eg[i][j]=0;
        lp(i,1,cy)lk[i]=0;
        lp(i,1,n)lp(j,1,n){
            int t;sf("%d",&t);
            if(t)eg[j][i]=1;
        }
        if(mch()==n)pf("Yes\n");
        else pf("No\n");
    }
    //ps;
    return 0;
}
/*
3
2
0 0
0 0
2
1 0
1 0
4
0 0 0 1
0 1 0 0
0 0 1 0
1 0 0 0
*/
