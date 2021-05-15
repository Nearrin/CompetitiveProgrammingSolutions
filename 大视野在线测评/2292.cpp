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
namespace pairingheap{
    struct node{
        inline node(){}
        inline node(int u,ll v){url=u;val=v;ch=br=pr=0;}
        ll val;int url;node*ch,*br,*pr;
    }pool[1000010];int posz;
    inline node*make(int u,ll v){
        node*t=&pool[posz++];*t=node(u,v);return t;
    }
    inline node*merge(node*x,node*y){
        if(!x)return y;
        if(!y)return x;
        if(x->val>y->val)swap(x,y);
        y->br=x->ch;if(x->ch)x->ch->pr=y;
        y->pr=x;x->ch=y;
        return x;
    }
    inline node*decrease(node*x,node*y,ll v){
        y->val=v;
        if(x!=y){
            if(y==y->pr->ch)y->pr->ch=y->br;
            else y->pr->br=y->br;
            if(y->br)y->br->pr=y->pr;
            y->pr=y->br=0;
            x=merge(x,y);
        }
        return x;
    }
    inline node*pop(node*x){
        static node*ns[1000010];int nz=0;
        for(node*i=x->ch;i;i=i->br)ns[++nz]=i;
        lp(i,1,nz)ns[i]->pr=ns[i]->br=0;
        for(int i=1;i+1<=nz;i+=2)ns[i]=merge(ns[i],ns[i+1]);
        x=0;for(int i=1;i<=nz;i+=2)x=merge(x,ns[i]);
        return x;
    }
}
namespace frontstar{
    struct node{
        inline node(){}
        inline node(int a,int b,node*c):
            v(a),w(b),nxt(c){}
        int v,w;node*nxt;
    }pool[1000010];int posz;
    node*bg[1000010];
    inline void add(int u,int v,int w){
        node*t=&pool[posz++];*t=node(v,w,bg[u]);bg[u]=t;
    }
}
int main(){
    int n,m;sf("%d%d",&n,&m);
    lp(i,1,m){
        int u,v,w;sf("%d%d%d",&u,&v,&w);
        frontstar::add(u,v,w);
    }
    static ll dis[1000010];static pairingheap::node*pm[1000010];
    pairingheap::node*rt=pm[1]=pairingheap::make(1,0);
    lp(i,2,n){
        int u=rt->url;
        if(u==n)break;
        rt=pairingheap::pop(rt);
        for(frontstar::node*e=frontstar::bg[u];e;e=e->nxt){
            if(!pm[e->v]||dis[e->v]>dis[u]+e->w){
                dis[e->v]=dis[u]+e->w;
                if(!pm[e->v])rt=pairingheap::merge(rt,pm[e->v]=pairingheap::make(e->v,dis[e->v]));
                else rt=pairingheap::decrease(rt,pm[e->v],dis[e->v]);
            }
        }
    }
    pf("%lld\n",dis[n]);
    return 0;
}
