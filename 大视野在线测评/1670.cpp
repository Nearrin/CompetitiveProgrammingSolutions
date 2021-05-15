#include<cstdio>
#include<algorithm>
#include<vector>
#include<complex>
#include<cmath>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long ll;
typedef complex<ll> P;
ll det(P a,P b){return imag(conj(a)*b);}
bool cmp(P a,P b){
    if(real(a)==real(b))return imag(a)<imag(b);
    else return real(a)<real(b);
}
double dis(P a,P b){
    double t1=real(a)-real(b);
    double t2=imag(a)-imag(b);
    return sqrt(t1*t1+t2*t2);
}
int n;vector<P>pts,up,lw;
int main(){
    sf("%d",&n);
    lp(i,1,n){
        ll u,v;sf("%d%d",&u,&v);
        pts.push_back(P(u,v));
    }
    sort(pts.begin(),pts.end(),cmp);
    lp(i,0,int(pts.size()-1)){
        while(up.size()>1&&det(pts[i]-up[up.size()-2],up[up.size()-1]-up[up.size()-2])>=0)
            up.pop_back();
        up.push_back(pts[i]);
    }
    for(int i=int(pts.size()-1);i>=0;--i){
        while(lw.size()>1&&det(pts[i]-lw[lw.size()-2],lw[lw.size()-1]-lw[lw.size()-2])>=0)
            lw.pop_back();
        lw.push_back(pts[i]);
    }
    double ans=0;
    lp(i,0,int(up.size()-2)){
        ans+=dis(up[i],up[i+1]);
    }
    lp(i,0,int(lw.size()-2)){
        ans+=dis(lw[i],lw[i+1]);
    }
    pf("%.2lf\n",ans);
    //ps;
    return 0;
}
