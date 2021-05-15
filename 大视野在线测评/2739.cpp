#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define pb push_back
#define mp make_pair
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
#define vp(i,v) for(int i=0;i<v.size();++i)
#define wp(i,v) for(int i=int(v.size()-1);i>=0;--i)
typedef double ll;
using namespace std;
struct point{int x,y,e;};
struct node{node*lc,*rc;int xi,xa,yi,ya;point p;}nds[500010];int nww=0;
point pts[500010],pts2[500010];
int n,m;
inline bool cmpx(point a,point b){return a.x<b.x;}
inline bool cmpy(point a,point b){return a.y<b.y;}
inline node*build(int l,int r,int s){
    node*x=&nds[nww++];int m=l+((r-l)>>1);
    nth_element(pts+l,pts+m,pts+r+1,s?cmpy:cmpx);x->p=pts[m];
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
inline ll dis(point a,point b){return ll(a.x-b.x)*ll(a.x-b.x)+ll(a.y-b.y)*ll(a.y-b.y);}
int qk;point qp;pair<ll,point>ans;
inline bool cmp(pair<ll,point> a,pair<ll,point> b){
    if(a.first==b.first)return a.second.e<b.second.e;
    else return a.first>b.first;
}
inline void update(point p){
    pair<ll,point> t=make_pair(dis(p,qp),p);
    if(cmp(t,ans))ans=t;
}
inline ll mab(ll a){return a>0?a:-a;}
inline ll mdis(node*x){
    ll t1=max(mab(x->xi-qp.x),mab(x->xa-qp.x));
    ll t2=max(mab(x->yi-qp.y),mab(x->ya-qp.y));
    return t1*t1+t2*t2;
}
inline void query(node*x){
    update(x->p);
    ll t1=x->lc?mdis(x->lc):-2;
    ll t2=x->rc?mdis(x->rc):-2;
    if(t1>t2){
        if(t1>=ans.first)query(x->lc);
        if(t2>=ans.first)query(x->rc);
    }else{
        if(t2>=ans.first)query(x->rc);
        if(t1>=ans.first)query(x->lc);
    }
}
char bin[10000010],*pin=bin;
char bout[10000010],*pout=bout;
inline bool dig(char c){
    return (c>='0'&&c<='9')||(c=='-');
}
inline char gchr(){
    for(;!dig(*pin);++pin);
    return *pin++;
}
inline int gint(){
    int t=gchr(),flg=1;
    if(t=='-')flg=-1,t=0;
    else t-='0';
    for(;dig(*pin);++pin)t=t*10+*pin-'0';
    return t*flg;
}
inline void pint(int a){
    static char tmp[11];int ts=0;
    do{
        tmp[++ts]=a%10;
        a/=10;
    }while(a);
    rp(i,ts,1)*pout++='0'+tmp[i];
    *pout++='\n';
}
int main(){
	fread(bin,1,10000000,stdin);
	int test=gint();
	lp(kase,1,test){
    	n=gint();nww=0;
    	lp(i,1,n){pts[i].x=gint();pts[i].y=gint();pts[i].e=i;pts2[i]=pts[i];}
    	node*rt=build(1,n,0);
    	m=n;
    	lp(i,1,m){
    		qp.x=pts2[i].x;qp.y=pts2[i].y;qk=1;
        	ans=make_pair(-1ll,point());
        	query(rt);
        	pint(ans.second.e);
    	}
    }
    fwrite(bout,1,pout-bout,stdout);
    return 0;
}
