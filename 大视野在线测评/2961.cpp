#include<cstdio>
#include<algorithm>
#define sf scanf
#define pf printf
#define fr feopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int ans[500010],ac,n;double ep=1e-8;
struct point{
    point(){}
    point(double a,double b):
        x(a),y(b){}
    double x,y;
};
double fab(double a){
    return a<0?-a:a;
}
point operator-(const point&a,const point&b){
    return point(a.x-b.x,a.y-b.y);
}
double operator*(const point&a,const point&b){
    return a.x*b.y-b.x*a.y;
}
bool operator<(const point&a,const point&b){
    return fab(a.x-b.x)<ep?(a.y<b.y):(a.x<b.x);
}
struct event{int k,u;point p;}es[500010];
point all[500010],up[500010],dw[500010];int als,ups,dws;
#define ru(t) ((-2*x)*(up[t].x)+(-2*y)*(up[t].y)+x*x+y*y)
#define rd(t) ((-2*x)*(dw[t].x)+(-2*y)*(dw[t].y)+x*x+y*y)
void solve(int l,int r){
    if(l!=r){
        int m=((l+r)>>1);
        solve(l,m);solve(m+1,r);
        ups=dws=als=0;
        lp(i,l,m)if(!es[i].k)all[++als]=es[i].p;
        sort(all+1,all+als+1);
        lp(i,1,als){
            while(ups>1&&(up[ups]-up[ups-1])*(all[i]-up[ups])>-ep)//at
                --ups;
            up[++ups]=all[i];
        }
        for(int i=als;i;--i){
            while(dws>1&&(dw[dws]-dw[dws-1])*(all[i]-dw[dws])>-ep){//at
                --dws;
            }
            dw[++dws]=all[i];
        }
        lp(i,m+1,r)if(es[i].k){
            double x=es[i].p.x,y=es[i].p.y;int u=es[i].u;
            if(y<0&&ups){//at
                int b=1,e=ups;
                while(b+1<e){//at
                    int m=(b+e)/2;
                    if(ru(m+1)>ru(m))b=m;
                    else e=m;
                }
                if(ru(b)>ep||ru(e)>ep)ans[u]=0;
            }else if(dws){//at
                int b=1,e=dws;
                while(b+1<e){//at
                    int m=(b+e)/2;
                    if(rd(m+1)>rd(m))b=m;
                    else e=m;
                }
                if(rd(b)>ep||rd(e)>ep)ans[u]=0;
            }
        }
    }
}
int main(){
    sf("%d",&n);int t=0;
    lp(i,1,n){
        sf("%d%lf%lf",&es[i].k,
            &es[i].p.x,&es[i].p.y);
        if(!es[i].k)t=1;
        else{
            ans[++ac]=t;
            es[i].u=ac;
        }
    }
    solve(1,n);
    lp(i,1,ac)pf("%s\n",ans[i]?"Yes":"No");
    //ps;
    return 0;
}
