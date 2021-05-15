#include<cstdio>
#include<algorithm>
#include<cmath>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
namespace sim{
    const int nmx=1000,mmx=10000;
    const double eps=1e-6,inf=1e100;
    double mat[nmx+10][mmx+10];int n,m;
    int qu[mmx+10];
    void pivot(int l,int e){
        double t=-mat[l][e];mat[l][e]=-1;
        qu[0]=0;
        lp(i,0,m)
            if(fabs(mat[l][i]/=t)>eps)
                qu[++qu[0]]=i;
        lp(i,0,n)if(i!=l&&fabs(mat[i][e])>eps){
            t=mat[i][e];mat[i][e]=0;
            lp(j,1,qu[0])
                mat[i][qu[j]]+=mat[l][qu[j]]*t;
        }
    }
    int solve(){
        while(true){
            int l=-1,e=-1;double t=inf;
            lp(i,1,m)if(mat[0][i]>eps){e=i;break;}
            if(e==-1)return 1;
            lp(i,1,n)if(mat[i][e]<-eps&&-mat[i][0]/mat[i][e]<t)
                t=-mat[i][0]/mat[i][e],l=i;
            if(l==-1)return 0;
            pivot(l,e);
        }
    }
}
int main(){
    //fr("zjoi13_defend.in","r",stdin);
    //fr("zjoi13_defend.out","w",stdout);
    int n,m;sf("%d%d",&n,&m);
    sim::n=n,sim::m=m;
    lp(i,1,n)sf("%lf",&sim::mat[i][0]);
    lp(i,1,m){
        int l,r;sf("%d%d%lf",&l,&r,&sim::mat[0][i]);
        lp(j,l,r)sim::mat[j][i]=-1;
    }
    sim::solve();
    pf("%d\n",int(sim::mat[0][0]+0.5));
    //ps;
    return 0;
}
