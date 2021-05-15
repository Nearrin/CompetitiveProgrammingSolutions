#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
struct circle{
    circle(double a,double b):
        x(a),r(b){}
    double x,r;
};
struct seg{
    seg(double a,double b,double c,double d):
        x1(a),y1(b),x2(c),y2(d){}
    double x1,y1,x2,y2;
};
seg operator*(circle a,circle b){
    double t=(a.r-b.r)/(b.x-a.x);
    double t1=t*a.r,t2=t*b.r;
    double x1=t1+a.x,x2=t2+b.x;
    double y1=sqrt(a.r*a.r-t1*t1),y2=sqrt(b.r*b.r-t2*t2);
    return seg(x1,y1,x2,y2);
}
vector<seg>segs;
vector<circle>circles;
double mab(double x){
    return x<0?-x:x;
}
double f(double x){
    double r=0;
    lp(i,0,int(circles.size()-1)){
        double x1=circles[i].x,r1=circles[i].r;
        if(x>x1-r1&&x<x1+r1){
            //pf("[%lf,%lf]",x1,r1);
            double y=sqrt(r1*r1-(x1-x)*(x1-x));
            r=max(r,y);
        }
    }
    lp(i,0,int(segs.size()-1)){
        double x1=segs[i].x1,x2=segs[i].x2,y1=segs[i].y1,y2=segs[i].y2;
        if(x>x1&&x<x2){
            //pf("[%lf,%lf,%lf,%lf]",x1,y1,x2,y2);
            double y=(y1-y2)*(x-x1)/(x1-x2)+y1;
            r=max(r,y);
        }
    }
    return r;
}
double sim(double l,double r,double fl,double fm,double fr){
    return (fl+4*fm+fr)*(r-l)/6.0;
}
double rsim(double l,double r,double fl,double fm,double fr){
    double m=(l+r)/2.0,flm=f((l+m)/2.0),fmr=f((m+r)/2.0);
    if(mab(sim(l,r,fl,fm,fr)-sim(l,m,fl,flm,fm)-sim(m,r,fm,fmr,fr))<1e-6)
        return sim(l,r,fl,fm,fr);
    else
        return rsim(l,m,fl,flm,fm)+rsim(m,r,fm,fmr,fr);
}
double check(circle a,circle b){
    return b.x+b.r>a.x+a.r;
}
int main(){
    double h[510],rr[510];
    int n;double a;sf("%d%lf",&n,&a);
    a=1.0/tan(a);
    lp(i,0,n)sf("%lf",&h[i]);
    lp(i,1,n)sf("%lf",&rr[i]);
    double hnow=h[0],l=1e6,r=-1e6;
    lp(i,1,n){
        circles.push_back(circle(hnow*a,rr[i]));
        hnow+=h[i];
        l=min(l,circles.back().x-circles.back().r);
        r=max(r,circles.back().x+circles.back().r);
    }
    circles.push_back(circle(hnow*a,0));
    r=max(r,circles.back().x+circles.back().r);
    for(int i=0;i+1<circles.size();++i)
        if(check(circles[i],circles[i+1]))
            segs.push_back(circles[i]*circles[i+1]);
    //pf("(%lf)\n",f(20));ps;
    //lp(i,0,int(circles.size()-1))pf("(%lf,%lf)\n",circles[i].x,circles[i].r);
    //lp(i,0,int(segs.size()-1))pf("[%lf,%lf,%lf,%lf]\n",segs[i].x1,segs[i].y1,segs[i].x2,segs[i].y2);
    pf("%.2lf\n",rsim(l,r,f(l),f((l+r)/2.0),f(r))*2.0);
    //ps;
    return 0;
}
