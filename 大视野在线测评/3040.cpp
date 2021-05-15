#ifndef PAIRING_HEAP
#define PAIRING_HEAP
#include<bits/stdc++.h>
namespace CTL{
    using namespace std;
    template<class T,class  C>struct PairingHeap{
        PairingHeap():root(0),siz(0){}
        ~PairingHeap(){clear(root);}
        struct node{
            node(const T&_val):val(_val),ch(0),br(0),pr(0){}
            T val;node*ch,*br,*pr;}*root;
        int siz;
        void merge(node*&x,node*y){
            if(!x)x=y;
            else if(y){
                if(C()(y->val,x->val))swap(x,y);
                y->br=x->ch;
                if(x->ch)x->ch->pr=y;
                y->pr=x;x->ch=y;}}
        void cut(node*&x,node*y){
            if(x==y)x=0;
            else{
                if(y==y->pr->ch)y->pr->ch=y->br;else y->pr->br=y->br;
                if(y->br)y->br->pr=y->pr;
                y->pr=y->br=0;}}
        node*split(node*x){
            vector<node*>t;
            for(node*i=x->ch;i;i=i->br)t.push_back(i);
            x->ch=0;node*r=0;
            for(int i=0;i<t.size();++i)t[i]->pr=t[i]->br=0;
            for(int i=0;i+1<t.size();i+=2)merge(t[i],t[i+1]);
            for(int i=0;i<t.size();i+=2)merge(r,t[i]);
            return r;}
        void clear(node*x){
            if(x){clear(x->ch);clear(x->br);delete x;}}
        void clear(){clear(root);root=0;siz=0;}
        node*push(T a){node*r=new node(a);merge(root,r);++siz;return r;}
        void erase(node*x){cut(root,x);merge(root,split(x));--siz;}
        T top(){return root->val;}
        void pop(){erase(root);}
        void merge(PairingHeap<T,C>&a){merge(root,a.root);a.root=0;siz+=a.siz;a.siz=0;}
        void modify(node*x,T v){
            if(C()(x->val,v))x->val=v,merge(root,split(x));
            else x->val=v,cut(root,x),merge(root,x);}
        int size(){return siz;}};}
#endif
using namespace CTL;
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
typedef long long ll;
using namespace std;
namespace frontstar{
    struct node{
        inline node(){}
        inline node(int a,int b,node*c):
            v(a),w(b),nxt(c){}
        int v,w;node*nxt;
    }pool[10000010];node*posz=pool;
    node*bg[1000010];
    inline void add(int u,int v,int w){
        node*t=posz++;*t=node(v,w,bg[u]);bg[u]=t;
    }
}
struct info{
    info(ll dd,int vv){
        d=dd,v=vv;
    }

    ll d;int v;
};
bool operator<(info a,info b){
    return a.d<b.d;
}

int main(){
    int n,m;sf("%d%d",&n,&m);
    int t;ll rxa,rxc,rya,ryc,rpp;
    sf("%d%lld%lld%lld%lld%lld",&t,&rxa,&rxc,&rya,&ryc,&rpp);
    ll x=0,y=0,z=0;
    lp(i,1,t){
        x=(x*rxa+rxc)%rpp;
        y=(y*rya+ryc)%rpp;
        int a=min(x%n+1,y%n+1);
        int b=max(y%n+1,y%n+1);
        frontstar::add(a,b,100000000-100*a);
    }
    lp(i,1,m-t){
        int u,v,w;sf("%d%d%d",&u,&v,&w);
        frontstar::add(u,v,w);
    }
    static ll dis[1000010];static PairingHeap<info,less<info> >::node*pm[1000010];
    PairingHeap<info,less<info> >heap;
    pm[1]=heap.push(info(0,1));
    lp(i,2,n){
        int u=heap.top().v;
        if(u==n)break;
        heap.pop();
        for(frontstar::node*e=frontstar::bg[u];e;e=e->nxt){
            if(!pm[e->v]||dis[e->v]>dis[u]+e->w){
                dis[e->v]=dis[u]+e->w;
                if(!pm[e->v])pm[e->v]=heap.push(info(dis[e->v],e->v));
                else heap.modify(pm[e->v],info(dis[e->v],e->v));
            }
        }
    }
    pf("%lld\n",dis[n]);
    return 0;
}
