#include<cstdio>
#include<algorithm>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
struct node{
    node*lc,*rc;int l,r;
    double m;int cnt;
}*rt;
int query(node*x,double v){
    if(x->l==x->r)return x->m>v;
    else if(x->lc->m<=v)return query(x->rc,v);
    else return x->cnt-x->lc->cnt+query(x->lc,v);
}
void update(node*x){
    x->m=max(x->lc->m,x->rc->m);
    x->cnt=x->lc->cnt+query(x->rc,x->lc->m);
}
node*build(int l,int r){
    node*t=new node;t->l=l;t->r=r;t->cnt=0;t->m=0;
    if(l!=r){
        int m=(l+r)/2;
        t->lc=build(l,m);
        t->rc=build(m+1,r);
    }
    return t;
}
void modify(node*x,int p,double v){
    if(x->l==x->r){
        x->m=v;x->cnt=(v>0);
    }else{
        int m=(x->l+x->r)/2;
        if(p<=m)modify(x->lc,p,v);
        else modify(x->rc,p,v);
        update(x);
    }
}
int n,m;
int main(){
    sf("%d%d",&n,&m);
    rt=build(1,n);
    lp(i,1,m){
        int x,y;sf("%d%d",&x,&y);
        modify(rt,x,double(y)/x);
        pf("%d\n",rt->cnt);
    }//ps;
    return 0;
}
