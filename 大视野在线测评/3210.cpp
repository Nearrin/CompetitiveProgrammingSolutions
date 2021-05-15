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
typedef long long ll;
ll x[100010],y[100010];int n;
ll sumx[100010],sumy[100010];
ll ansx=-1,ansy=-1;
ll ansx2,ansy2;
ll calc(ll xx,ll yy){
    int i=lower_bound(x+1,x+n+1,xx)-x;
    ll r=0;
    r+=ll(i-1)*xx-sumx[i-1]+sumx[n]-sumx[i-1]-ll(n-i+1)*xx;
    i=lower_bound(y+1,y+n+1,yy)-y;
    r+=ll(i-1)*yy-sumy[i-1]+sumy[n]-sumy[i-1]-ll(n-i+1)*yy;
    return r;
}
int main(){
    sf("%d",&n);
    lp(i,1,n){
        sf("%lld%lld",&x[i],&y[i]); 
        ll t1=x[i],t2=y[i];
        x[i]=t1-t2;y[i]=t1+t2;
    }
    sort(x+1,x+n+1);
    lp(i,1,n)sumx[i]=sumx[i-1]+x[i];
    lp(i,1,n){
        ll t=x[i]*(i-1)-sumx[i-1]+(sumx[n]-sumx[i])-x[i]*(n-i);
        if(ansx==-1||t<ansx){
            ansx=t;ansx2=x[i];}
    }
    sort(y+1,y+n+1);
    lp(i,1,n)sumy[i]=sumy[i-1]+y[i];
    lp(i,1,n){
        ll t=y[i]*(i-1)-sumy[i-1]+(sumy[n]-sumy[i])-y[i]*(n-i);
        if(ansy==-1||t<ansy){
            ansy=t;ansy2=y[i];}
    }
    if((ansx2+ansy2)%2==0){
        pf("%lld\n",calc(ansx2,ansy2)/2);
    }else{
        ll ty1=min(calc(ansx2-1,ansy2),calc(ansx2+1,ansy2));
        ll ty2=min(calc(ansx2,ansy2+1),calc(ansx2,ansy2-1));
        pf("%lld\n",min(ty1,ty2)/2);
    }
    //ps;
    return 0;
}
