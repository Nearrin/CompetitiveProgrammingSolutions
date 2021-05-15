#include<cstdio>
#include<algorithm>
#include<vector>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;\
typedef long long ll;
int n,m;ll k,d;
struct node{
    node*ch[2];
    int l,r;ll lmx,rmx,mmx,sum;
}*rt;
node*build(int l,int r){
    node*t=new node;t->l=l;t->r=r;
    t->lmx=t->rmx=t->mmx=-k;t->sum=-k*(r-l+1);
    if(l!=r){
        int m=(l+r)/2;
        t->ch[0]=build(l,m);
        t->ch[1]=build(m+1,r);
    }
    return t;
}
void modify(node*x,int p,ll d){
    if(x->l==x->r){
        x->lmx+=d;
        x->rmx+=d;
        x->mmx+=d;
        x->sum+=d;
    }else{
        if(p<=x->ch[0]->r)modify(x->ch[0],p,d);
        else modify(x->ch[1],p,d);
        x->lmx=max(x->ch[0]->lmx,x->ch[0]->sum+x->ch[1]->lmx);
        x->rmx=max(x->ch[1]->rmx,x->ch[1]->sum+x->ch[0]->rmx);
        x->sum=x->ch[0]->sum+x->ch[1]->sum;
        x->mmx=max(x->ch[0]->mmx,x->ch[1]->mmx);
        x->mmx=max(x->mmx,x->ch[0]->rmx+x->ch[1]->lmx);
    }
}
int main(){
    sf("%d%d%lld%lld",&n,&m,&k,&d);
    rt=build(1,n);
    lp(i,1,m){
        int a,b;
        sf("%d%d",&a,&b);
        modify(rt,a,b);
        pf("%s\n",rt->mmx<=k*d?"TAK":"NIE");
    }
    //ps;
    return 0;
}
