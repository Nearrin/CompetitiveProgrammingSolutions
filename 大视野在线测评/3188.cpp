#include<cstdio>
#include<algorithm>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
struct splay{
    struct node{
        node(ll v){
            ch[0]=ch[1]=pr=0;
            sz=1;sum=val=v;del1=del2=0;
            sam=~0u>>1;
        }
        node*ch[2],*pr;
        int sz;
        ll sum,del1,del2,val,sam;
    }*rt;
    void down(node*x){
        if(x->sam!=~0u>>1){
            lp(i,0,1)if(x->ch[i]){
                x->ch[i]->sam=x->sam;
                x->ch[i]->del1=x->ch[i]->del2=0;
            }
            x->val=x->sam;
            x->sum=x->sz*x->sam; 
            x->sam=~0u>>1;
        }
        if(x->del1||x->del2){
            int t=0;
            if(x->ch[0]){
                x->ch[0]->del1+=x->del1;
                x->ch[0]->del2+=x->del2;
                t=x->ch[0]->sz;
            }
            x->sum+=x->sz*x->del1+ll(x->sz)*(x->sz-1)/2*x->del2;
            x->val+=x->del1+x->del2*t;
            if(x->ch[1]){
                x->ch[1]->del1+=x->del1+x->del2*(t+1);
                x->ch[1]->del2+=x->del2;
            }
            x->del1=x->del2=0;
        } 
    }
    void upda(node*x){
        x->sum=x->val;
        x->sz=1;
        lp(i,0,1)if(x->ch[i]){
            down(x->ch[i]);
            x->sum+=x->ch[i]->sum;
            x->sz+=x->ch[i]->sz;
        }
    }
    int tp(node*x){return x==x->pr->ch[1];}
    void st(node*x,node*y,int d){x->ch[d]=y;if(y)y->pr=x;upda(x);}
    void rot(node*x){
        node*y=x->pr,*z=x->pr->pr;
        int d1=tp(x),d2=z?tp(y):-1;
        st(y,x->ch[!d1],d1);
        st(x,y,!d1);
        if(d2!=-1)st(z,x,d2);
        else x->pr=0,rt=x;
    }
    node*kth(node*x,int k){
        down(x);
        int t=x->ch[0]?x->ch[0]->sz:0;
        if(t+1==k)return x;
        else if(t+1<k)return kth(x->ch[1],k-(t+1));
        else return kth(x->ch[0],k); 
    }
    void spl(node*x,node*p){
        while(x->pr!=p){
            if(x->pr->pr==p)rot(x);
            else if(tp(x)==tp(x->pr))rot(x->pr),rot(x);
            else rot(x),rot(x);
        }
    }
    void insert(int p,int v){
        spl(kth(rt,p),0);
        spl(kth(rt,p+1),rt);
        st(rt->ch[1],new node(v),0);
        upda(rt);
    }
    ll asksum(int p,int q){
        spl(kth(rt,p),0);
        spl(kth(rt,q+2),rt);
        down(rt->ch[1]->ch[0]);
        return rt->ch[1]->ch[0]->sum;
    }
    ll makesame(int p,int q,int c){
        spl(kth(rt,p),0);
        spl(kth(rt,q+2),rt);
        rt->ch[1]->ch[0]->sam=c;
        rt->ch[1]->ch[0]->del1=rt->ch[1]->ch[0]->del2=0;
        upda(rt->ch[1]);
        upda(rt);
    }
    ll addnum(int p,int q,int c){
        spl(kth(rt,p),0);
        spl(kth(rt,q+2),rt);
        rt->ch[1]->ch[0]->del1+=c;
        rt->ch[1]->ch[0]->del2+=c;
        upda(rt->ch[1]);
        upda(rt);
    }
}tree;
int main(){
    tree.rt=new splay::node(0);
    tree.st(tree.rt,new splay::node(0),0);
    int n,q;sf("%d%d",&n,&q);
    lp(i,1,n){
        int t;sf("%d",&t);
        tree.insert(i,t);
    }
    lp(i,1,q){
        int t;sf("%d",&t);
        if(t==1){
            int a,b,c;sf("%d%d%d",&a,&b,&c);
            tree.makesame(a,b,c); 
        }else if(t==2){
            int a,b,c;sf("%d%d%d",&a,&b,&c);
            tree.addnum(a,b,c); 
        }else if(t==3){
            int a,b;sf("%d%d",&a,&b);
            tree.insert(a,b);
        }else{
            int a,b;sf("%d%d",&a,&b);
            pf("%lld\n",tree.asksum(a,b));
        }
    }
    //ps;
    return 0;
}
