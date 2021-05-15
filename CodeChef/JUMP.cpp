#include<bits/stdc++.h>
#define lop(i,a,b) for(auto i=a;i<=b;++i)
#define rlp(i,a,b) for(auto i=a;i>=b;--i)
#define vlp(i,a) for(int i=0;i<a.size();++i)
#define all(a) a.begin(),a.end()
#define sqr(a) ((a)*(a))
#define pub push_back
#define pob pop_back
#define mkp make_pair
#define scf scanf
#define ptf printf
#define inf (~0u>>1)
#define fio ios::sync_with_stdio(0)
namespace CTL{}
using namespace CTL;
using namespace std;
typedef long long lli;
typedef unsigned long long ull;
typedef string str;
typedef vector<int> vei;
typedef vector<string> ves;
typedef map<int,int> mii;
typedef map<str,int> msi;
typedef set<int> sti;
typedef set<str> sts;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#ifndef DYNAMIC_CONVEX_HULL
#define DYNAMIC_CONVEX_HULL
#include<bits/stdc++.h>
namespace CTL{
    using namespace std;
    template<class T>struct DynamicConvexHull{
        struct point{
            T x,y;
            point(T _x=0,T _y=0):x(_x),y(_y){}
            point operator-(const point&a)const{
                point p(x-a.x,y-a.y);return p;}
            T operator*(const point&a)const{return x*a.y-y*a.x;}};
        struct node{
            node**nxt;point p;
            node(node**_n,point _p):nxt(_n),p(_p){}
            node(const node&a):nxt(new node*(*a.nxt)),p(a.p){}
            ~node(){delete nxt;}
            int operator<(const node&a)const{
                if(ctp)return p.x==a.p.x?p.y<a.p.y:p.x<a.p.x;
                point p1,p2;int f=1;
                if(nxt) p1=*nxt?(*nxt)->p-p:point(0,-1),p2=a.p;
                else f=0,p1=*a.nxt?(*a.nxt)->p-a.p:point(0,-1),p2=p;
                T x=p1*p2;return f?x<0:x>0;}};
        static int ctp;set<node>nds;
        typedef typename set<node>::iterator P;
        int check(P a,P b,P c){return (b->p-a->p)*(c->p-b->p)>=0;}
        void next(P a,P b){*(a->nxt)=(node*)&*b;}
        void insert(T x,T y){
            ctp=1;node t(new node*(0),point(x,y));
            P it=nds.insert(t).first,itl1=it,itl2,itr1=it,itr2=it;
            if(it!=nds.begin())
                for(next(--itl1,it);itl1!=nds.begin()&&check(--(itl2=itl1),itl1,it);)
                    next(itl2,it),nds.erase(itl1),itl1=itl2;
            if(++(itr1=it)!=nds.end())next(it,itr1);
            if(itl1!=it&&itr1!=nds.end()&&check(itl1,it,itr1)){
                next(itl1,itr1);nds.erase(it);return;}
            if(itr1!=nds.end())
                for(;++(itr2=itr1)!=nds.end()&&check(it,itr1,itr2);)
                    next(it,itr2),nds.erase(itr1),itr1=itr2;}
        int size(){return nds.size();}
        pair<T,T>query(T x,T y){
            ctp=0;node t=*nds.lower_bound(node(0,point(x,y)));
            return make_pair(t.p.x,t.p.y);}};
    template<class T>int DynamicConvexHull<T>::ctp=0;}
#endif
DynamicConvexHull<lli>seg[300010*4];
int n;
lli p[300010],a[300010],h[300010],dp[300010];
void segins(int rt,int l,int r,int p,lli x,lli y){
    seg[rt].insert(x,y);
    if(l==r)return;
    int m=(l+r)/2;
    if(p<=m)segins(rt*2,l,m,p,x,y);
    else segins(rt*2+1,m+1,r,p,x,y);
}
//4 0 0
//3 2 -2
//2
void insert(int i){
    lli x=-2*h[i];
    lli y=-h[i]*h[i]-dp[i];
    segins(1,1,n,p[i],x,y);
}
void segup(int x,int l,int r,int ql,int qr,lli k,lli&f){
    if(ql<=l&&qr>=r){
        if(seg[x].size()){
            auto poi=seg[x].query(1,k);
            lli tmp=poi.second-k*poi.first;
            if(tmp>f)f=tmp;
        }
    }else{
        int m=(l+r)/2;
        if(ql<=m)segup(x*2,l,m,ql,qr,k,f);
        if(qr>m)segup(x*2+1,m+1,r,ql,qr,k,f);
    }
}
void update(int i){
    dp[i]=numeric_limits<lli>::min();
    segup(1,1,n,p[i]+1,n,h[i],dp[i]);
    dp[i]=-dp[i];
    dp[i]+=h[i]*h[i]+a[i];
}
int main(){
    delete (int*)0;
    scf("%d",&n);
    lop(i,1,n)scf("%lld",p+i);
    lop(i,1,n)scf("%lld",a+i);
    lop(i,1,n)scf("%lld",h+i);
    dp[n]=a[n];
    insert(n);
    for(int i=n-1;i>=1;--i){
        update(i);
        insert(i);

    }
   // rlp(i,n,2)cout<<dp[i]<<endl;
    cout<<dp[1]<<endl;
    return 0;
}
