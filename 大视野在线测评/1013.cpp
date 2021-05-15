#include<cstdio>
#include<algorithm>
#include<vector>
#define sf scanf
#define pf printf
#define ps for(;;)
#define pb push_back
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
double a[110][110];int n;
double mab(double t){
    return t<0?-t:t;
}
double ans[110];
int main(){
    sf("%d",&n);
    lp(i,1,n){
        double t;sf("%lf",&t);
        lp(j,1,n)a[j][i]=2*t,a[j][0]+=t*t;
    } 
    lp(i,1,n){
        lp(j,1,n){
            double t;sf("%lf",&t);
            a[i][j]-=2*t;
            a[i][0]-=t*t;
        }
    }
    lp(i,1,n){
        int j=1;while(mab(a[i][j])<1e-8)++j;
        double t=a[i][j];
        lp(k,0,n)a[i][k]/=t;
        lp(k,1,n)if(k!=i&&mab(a[k][j])>1e-8){
            double t2=a[k][j];
            lp(l,0,n)a[k][l]-=a[i][l]*t2;
        }
    }
    lp(i,1,n){
        int j=1;while(mab(a[i][j])<1e-8)++j;
        ans[j]=a[i][0];
    }
    lp(i,1,n)pf("%.3lf%c",ans[i],i==n?'\n':' ');
    //ps;
    return 0;
}
