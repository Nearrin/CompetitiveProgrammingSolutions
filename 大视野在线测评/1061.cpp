#include<cstdio>
#include<algorithm>
#include<vector>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
namespace sim{
    double a[10010][1010];int n,m;
    double fbs(double x){return x>0?x:-x;}
    void pivot(int l,int e){
        double t=-a[l][e];a[l][e]=-1;
        vector<int>qu;
        lp(i,0,m)if(fbs(a[l][i]/=t)>1e-8)qu.push_back(i);
        lp(i,0,n){
            if(i!=l){
                double t2=a[i][e];a[i][e]=0;
                lp(j,0,int(qu.size()-1))
                    a[i][qu[j]]+=a[l][qu[j]]*t2;
            }
        }
    }
    void solve(){
        while(true){
            int e=-1;
            lp(i,1,m)if(a[0][i]>1e-8){e=i;break;}
            if(e==-1)break;
            int l=-1;double t=1e100;
            lp(i,1,n)if(a[i][e]<-1e-8&&a[i][0]/-a[i][e]<t){
                t=a[i][0]/-a[i][e];
                l=i;
            }
            pivot(l,e);
        }
    }
}
int main(){
    int n,m;sf("%d%d",&n,&m);
    lp(i,1,n){
        int t;sf("%d",&t);
        sim::a[0][i]=t;
    }
    lp(i,1,m){
        int s,t,c;sf("%d%d%d",&s,&t,&c);
        lp(j,s,t)sim::a[i][j]=-1;
        sim::a[i][0]=c;
    }
    sim::n=m;sim::m=n;
    sim::solve();
    pf("%d\n",int(sim::a[0][0]+0.5));
    //ps;
    return 0;
}
