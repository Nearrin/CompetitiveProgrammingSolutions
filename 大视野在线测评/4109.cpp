#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
double pi=acos(-1.0);
int n,s;
double x[10010],y[10010],z[10010],r[10010];
double sum(double zi){
    double ret=(1e10)*zi;
    for(int i=1;i<=n;++i){
        if(z[i]-r[i]>=zi)
            continue;
       else if(z[i]+r[i]<=zi){
            ret-=4/3.0*pi*r[i]*r[i]*r[i];
        }else{
            ret-=2/3.0*pi*r[i]*r[i]*r[i]-pi*r[i]*r[i]*(z[i]-zi)+pi/3*(z[i]-zi)*(z[i]-zi)*(z[i]-zi);
        }
    }
    return ret;
}

int main(){
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;++i)
        scanf("%lf%lf%lf%lf",r+i,x+i,y+i,z+i);
    double all=sum(1e5);
    double per=all/s;
    double st=0;
    for(int i=1;i<=s;++i){
        double lft=st;
        double rht=1e5;
        double tmp=sum(st);
        while(rht-lft>1e-10){
            double mid=(lft+rht)/2;
            if(sum(mid)-tmp>per)
                rht=mid;
            else
                lft=mid;
        }
        printf("%.9lf\n",(lft-st)/1e3);
        st=lft;
    }
    return 0;
}
