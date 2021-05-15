#include<cstdio>
#define sf scanf
#define pf printf
#define mx 50010
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int n,f0[2][mx],a0[mx],a1,q2,d0[mx];
void f1(int*a,int i,int d){for(;i<=n;i+=i&-i)a[i]+=d;}
int f2(int*a,int i){int r=0;for(;i;i-=i&-i)r+=a[i];return r;}
void f3(int i,int d){f1(f0[0],i+1,d*i);f1(f0[1],1,d);f1(f0[1],i+1,-d);}
int f4(int i){return f2(f0[0],i)+f2(f0[1],i)*i;}
void f5(int l,int r,int d){f3(r,d);if(l-1)f3(l-1,-d);}
int f6(int l,int r){if(l-1)return f4(r)-f4(l-1);else return f4(r);}
struct q0{int t,a,b,c,o,w;}q1[mx],lq[mx],rq[mx];
void s0(int ql,int qr,int vl,int vr){
    if(ql>qr)return;
    if(vl==vr){
        lp(i,ql,qr)if(q1[i].t==2)a0[q1[i].w]=vl;
    }else{
        int vm=((long long)vl+vr)/2;
        lp(i,ql,qr)
            if(q1[i].t==1&&q1[i].c>vm)f5(q1[i].a,q1[i].b,1);
            else if(q1[i].t==2)d0[i]=f6(q1[i].a,q1[i].b);
        lp(i,ql,qr)
            if(q1[i].t==1&&q1[i].c>vm)f5(q1[i].a,q1[i].b,-1);
        int l0=0,l1=0;
        lp(i,ql,qr)
            if(q1[i].t==1){if(q1[i].c<=vm)lq[++l0]=q1[i];else rq[++l1]=q1[i];
            }else{
                if(q1[i].o+d0[i]<=q1[i].c-1) q1[i].o+=d0[i],lq[++l0]=q1[i];
                else rq[++l1]=q1[i];
            }
        lp(i,1,l0)q1[ql+i-1]=lq[i];
        lp(i,1,l1)q1[ql+l0+i-1]=rq[i];
        s0(ql,ql+l0-1,vl,vm);
        s0(ql+l0,qr,vm+1,vr);
    }
}
int main(){
    sf("%d%d",&n,&q2);
    lp(i,1,q2){
        sf("%d%d%d%d",&q1[i].t,&q1[i].a,&q1[i].b,&q1[i].c);
        if(q1[i].t==2)q1[i].o=0,q1[i].w=++a1;
    }
    s0(1,q2,-(~0u>>1),~0u>>1);
    lp(i,1,a1)pf("%d\n",a0[i]);//for(;;);
    return 0;
}
