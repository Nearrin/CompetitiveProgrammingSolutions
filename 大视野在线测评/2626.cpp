#include<cstdio>
#include<algorithm>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
struct point{int x,y,e;};
struct node{node*lc,*rc;int xi,xa,yi,ya;point p;};
point pts[100010];
int n,m;
bool cmpx(point a,point b){return a.x<b.x;}
bool cmpy(point a,point b){return a.y<b.y;}
node*build(int l,int r,int s){
    node*x=new node;int m=l+((r-l)>>1);
    sort(pts+l,pts+r+1,s?cmpy:cmpx);x->p=pts[m];
    x->xi=x->xa=x->p.x;x->yi=x->ya=x->p.y;
    if(l<=m-1){
        x->lc=build(l,m-1,!s);
        x->xi=min(x->xi,x->lc->xi);
        x->xa=max(x->xa,x->lc->xa);
        x->yi=min(x->yi,x->lc->yi);
        x->ya=max(x->ya,x->lc->ya);
    }else x->lc=0;
    if(m+1<=r){
        x->rc=build(m+1,r,!s);
        x->xi=min(x->xi,x->rc->xi);
        x->xa=max(x->xa,x->rc->xa);
        x->yi=min(x->yi,x->rc->yi);
        x->ya=max(x->ya,x->rc->ya);
    }else x->rc=0;
    return x;
}
typedef long long ll;
ll dis(point a,point b){return ll(a.x-b.x)*ll(a.x-b.x)+ll(a.y-b.y)*ll(a.y-b.y);}
int qk;point qp;pair<ll,point>ans[31];
bool cmp(pair<ll,point> a,pair<ll,point> b){
    if(a.first==b.first)return a.second.e<b.second.e;
    else return a.first>b.first;
}
void update(point p){
    pair<ll,point> t=make_pair(dis(p,qp),p);
    if(!cmp(t,ans[qk]))return;
    int i=qk;for(;i&&cmp(t,ans[i]);--i);++i;
    for(int j=qk;j>i;--j)ans[j]=ans[j-1];
    ans[i]=t;
}
ll mab(ll a){return a>0?a:-a;}
ll mdis(node*x){
    ll t1=max(mab(x->xi-qp.x),mab(x->xa-qp.x));
    ll t2=max(mab(x->yi-qp.y),mab(x->ya-qp.y));
    return t1*t1+t2*t2;
}
void query(node*x){
    update(x->p);
    ll t1=x->lc?mdis(x->lc):-2;
    ll t2=x->rc?mdis(x->rc):-2;
    if(t1>t2){
        if(t1>=ans[qk].first)query(x->lc);
        if(t2>=ans[qk].first)query(x->rc);
    }else{
        if(t2>=ans[qk].first)query(x->rc);
        if(t1>=ans[qk].first)query(x->lc);
    }
}
int main(){
    sf("%d",&n);
    lp(i,1,n){sf("%d%d",&pts[i].x,&pts[i].y);pts[i].e=i;}
    node*rt=build(1,n,0);
    sf("%d",&m);
    lp(i,1,m){
        sf("%d%d%d",&qp.x,&qp.y,&qk);
        lp(i,1,qk)ans[i]=make_pair(-1ll,point());
        query(rt);
        pf("%d\n",ans[qk].second.e);
    }//ps;
    return 0;
}
