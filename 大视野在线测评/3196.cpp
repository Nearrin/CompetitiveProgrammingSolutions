#include<cstdio>
#include<algorithm>
#include<cstdlib>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
namespace trp{
    struct node{
        node(int a){
            ch[0]=ch[1]=0;
            vl=a;sz=1;fx=rand();
        }
        node*ch[2];
        int vl,sz,fx;
    };
    void upd(node*x){
        x->sz=1;
        lp(i,0,1)if(x->ch[i])x->sz+=x->ch[i]->sz;
    }
    void rot(node*&x,int d){
        node*y=x->ch[d];
        x->ch[d]=y->ch[!d];
        y->ch[!d]=x;
        upd(x);upd(y);x=y;
    }
    void ins(node*&x,int v){
        if(!x)x=new node(v);
        else{
            if(v<x->vl){
                ins(x->ch[0],v);
                upd(x);
                if(x->ch[0]->fx<x->fx)
                    rot(x,0);
            }else{
                ins(x->ch[1],v);
                upd(x);
                if(x->ch[1]->fx<x->fx)
                    rot(x,1);
            }
        }
    }
    void rem(node*&x,int v){
        if(x->vl==v){
            if(!x->ch[0])x=x->ch[1];
            else if(!x->ch[1])x=x->ch[0];
            else if(x->ch[0]->fx<x->ch[1]->fx)
                rot(x,0),rem(x->ch[1],v),upd(x);
            else
                rot(x,1),rem(x->ch[0],v),upd(x);
        }else{
            rem(x->ch[v>x->vl],v),upd(x);
        }
    }
    int less(node*x,int v){
        if(!x)return 0;
        else if(x->vl<v)return (x->ch[0]?x->ch[0]->sz:0)+1+less(x->ch[1],v);
        else return less(x->ch[0],v); 
    }
    int pre(node*x,int v){
        if(!x)return -(~0u>>1);
        else if(x->vl<v)return max(x->vl,pre(x->ch[1],v));
        else return pre(x->ch[0],v);
    }
    int nxt(node*x,int v){
        if(!x)return ~0u>>1;
        else if(x->vl>v)return min(x->vl,nxt(x->ch[0],v));
        else return nxt(x->ch[1],v);
    }
    
}
namespace seg{
    struct node{
        node(int a,int b){
            ch[0]=ch[1]=0;
            tp=0;l=a;r=b;
        }
        node*ch[2];trp::node*tp;int l,r;
    };
    node*build(int l,int r){
        node*x=new node(l,r);
        if(l!=r){
            int m=(l+r)/2;
            x->ch[0]=build(l,m);
            x->ch[1]=build(m+1,r);
        }
        return x;
    }
    void insert(node*x,int p,int v){
        trp::ins(x->tp,v);
        if(x->l!=x->r){
            if(p<=x->ch[0]->r)
                insert(x->ch[0],p,v);
            else
                insert(x->ch[1],p,v);
        }
    }
    void remove(node*x,int p,int v){
        trp::rem(x->tp,v);
        if(x->l!=x->r){
            if(p<=x->ch[0]->r)
                remove(x->ch[0],p,v);
            else
                remove(x->ch[1],p,v);
        }
    }
    int rank(node*x,int b,int e,int v){
       if(b<=x->l&&e>=x->r)return trp::less(x->tp,v);
       else{
            int as=0;
            if(b<=x->ch[0]->r)as+=rank(x->ch[0],b,e,v);
            if(e>x->ch[0]->r)as+=rank(x->ch[1],b,e,v);
            return as;
       } 
    }
    int prev(node*x,int b,int e,int v){
        if(b<=x->l&&e>=x->r)return trp::pre(x->tp,v);
        else{
            int as=-(~0u>>1);
            if(b<=x->ch[0]->r)as=max(as,prev(x->ch[0],b,e,v));
            if(e>x->ch[0]->r)as=max(as,prev(x->ch[1],b,e,v));
            return as;
        }
    }
    int next(node*x,int b,int e,int v){
        if(b<=x->l&&e>=x->r)return trp::nxt(x->tp,v);
        else{
            int as=~0u>>1;
            if(b<=x->ch[0]->r)as=min(as,next(x->ch[0],b,e,v));
            if(e>x->ch[0]->r)as=min(as,next(x->ch[1],b,e,v));
            return as;
        }
    }
}
int main(){
    static int a[50010],n,m;
    sf("%d%d",&n,&m);
    lp(i,1,n)sf("%d",&a[i]);
    seg::node*rt=seg::build(1,n);
    lp(i,1,n)seg::insert(rt,i,a[i]);
    lp(i,1,m){
        int op;sf("%d",&op);
        if(op==1){
            int l,r,k;sf("%d%d%d",&l,&r,&k);
            pf("%d\n",seg::rank(rt,l,r,k)+1);
        }else if(op==2){
            int l,r,k;sf("%d%d%d",&l,&r,&k);
            int lf=-1,rf=100000000;
            while(lf+1<rf){
                int mf=(lf+rf)/2;
                if(seg::rank(rt,l,r,mf)<=k-1)lf=mf;
                else rf=mf;
            }
            pf("%d\n",lf);
        }else if(op==3){
            int pos,k;sf("%d%d",&pos,&k);
            seg::remove(rt,pos,a[pos]);
            a[pos]=k;
            seg::insert(rt,pos,a[pos]);
        }else if(op==4){
            int l,r,k;sf("%d%d%d",&l,&r,&k);
            pf("%d\n",seg::prev(rt,l,r,k));
        }else{
            int l,r,k;sf("%d%d%d",&l,&r,&k);
            pf("%d\n",seg::next(rt,l,r,k));
        }
    }
    //ps;
    return 0;
}
