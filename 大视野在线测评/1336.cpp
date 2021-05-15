#include<cstdio>
#include<algorithm>
#include<cmath>
#define sf scanf
#define pf printf
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
struct pot{pot(double a=0,double b=0):x(a),y(b){}double x,y;};
pot ct;double rr;pot pts[100010];int n;
void make(pot a,pot b,pot c){
    double u1=a.x-b.x,v1=a.y-b.y,w1=(a.x+b.x)/2*u1+(a.y+b.y)/2*v1;
    double u2=b.x-c.x,v2=b.y-c.y,w2=(b.x+c.x)/2*u2+(b.y+c.y)/2*v2;
    double d=u1*v2-u2*v1,dx=w1*v2-w2*v1,dy=u1*w2-u2*w1;
    ct=pot(dx/d,dy/d);rr=(a.x-ct.x)*(a.x-ct.x)+(a.y-ct.y)*(a.y-ct.y);
}
void calc(int tp,int len){
    ct.x=(pts[1].x+pts[2].x)/2;ct.y=(pts[1].y+pts[2].y)/2;
    rr=((pts[1].x-pts[2].x)*(pts[1].x-pts[2].x)+(pts[1].y-pts[2].y)*(pts[1].y-pts[2].y))/4;
    lp(i,3,len)
        if((pts[i].x-ct.x)*(pts[i].x-ct.x)+(pts[i].y-ct.y)*(pts[i].y-ct.y)>rr){
            swap(pts[i],pts[tp+1]);
            if(tp==2)make(pts[1],pts[2],pts[3]);
            else calc(tp+1,i);
        }
}
void mcover(){
    random_shuffle(pts+1,pts+n+1);
    calc(0,n);
}
int main(){
    sf("%d",&n);
    lp(i,1,n)sf("%lf%lf",&pts[i].x,&pts[i].y);
    mcover();
    pf("%.10lf\n%.10lf %.10lf\n",sqrt(rr),ct.x,ct.y);//ps;
    return 0;
}
