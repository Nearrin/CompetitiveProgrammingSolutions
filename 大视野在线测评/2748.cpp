#include<cstdio>
#include<algorithm>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int f[110][1010],n,bg,mx;
int main(){
    sf("%d%d%d",&n,&bg,&mx);
    f[0][bg]=1;
    lp(i,1,n){
        int t;sf("%d",&t);
        lp(j,0,mx)
            if(f[i-1][j]){
                if(j+t<=mx)f[i][j+t]=1;
                if(j-t>=0)f[i][j-t]=1;
            }
    }
    int ans=-1;
    lp(i,0,mx)if(f[n][i])ans=i;
    pf("%d\n",ans);//ps;
    return 0;
} 
