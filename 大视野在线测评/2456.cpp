#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<queue>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
int main(){
    int u=-1,v=0,n;
    sf("%d",&n);
    lp(i,1,n){
        int t;sf("%d",&t);
        if(u==-1)u=t,v=1;
        else if(u==t)++v;
        else{--v;if(v==0)u=-1;}
    } 
    pf("%d\n",u);
    //ps;
    return 0;
} 
