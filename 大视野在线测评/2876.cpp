#include<cstdio>
#include<algorithm>
#include<cstdlib>
#define sf scanf
#define pf printf
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int N;
double E,S[10010],K[10010],Vw[10010];
double myabs(double a){
    return a<0?-a:a;
} 
double calc(double phi,int f){
    double tmp=0;
    lp(i,1,N){
        double t=(max(Vw[i]/3.0*2,0.0)+1)*5,u;
        while(myabs(u=(2*phi*K[i]*t*t*t-2*phi*K[i]*Vw[i]*t*t-1))>1e-12)
            t=t-u/(6*phi*K[i]*t*t-4*phi*K[i]*Vw[i]*t);
        if(f)tmp+=K[i]*(t-Vw[i])*(t-Vw[i])*S[i];
        else tmp+=S[i]/t;
    }
    return tmp;
}
int main(){
    sf("%d%lf",&N,&E);
    lp(i,1,N)sf("%lf%lf%lf",&S[i],&K[i],&Vw[i]);
    double l=0,r=1;
    while(calc(r,1)>E)l=r,r*=2;
    while(r-l>1E-12){
        if(calc((l+r)/2,1)>E)l=(l+r)/2;
        else r=(l+r)/2;
    }
    pf("%.12lf\n",calc(l,0));
    //ps;
    return 0; 
}
