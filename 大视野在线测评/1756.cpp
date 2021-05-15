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
ll val[500010];
struct node{
    node(int a,int b){
        ch[0]=ch[1]=0;
        l=a;r=b;
    }
    node*ch[2];int l,r;
    ll sum,lm,rm,mm;
};
void upda(node*x){
    x->sum=x->ch[0]->sum+x->ch[1]->sum;
    x->lm=max(x->ch[0]->lm,x->ch[0]->sum+x->ch[1]->lm);
    x->rm=max(x->ch[1]->rm,x->ch[1]->sum+x->ch[0]->rm);
    x->mm=max(x->ch[0]->mm,x->ch[1]->mm);
    x->mm=max(x->mm,x->ch[0]->rm+x->ch[1]->lm); 
}
node*build(int l,int r){
    node*t=new node(l,r);
    if(l==r)t->sum=t->lm=t->rm=t->mm=val[l];
    else{
        int m=(l+r)/2;
        t->ch[0]=build(l,m);
        t->ch[1]=build(m+1,r);
        upda(t);
    } 
    //pf("[%d,%d,%I64d,%I64d,%I64d,%I64d]\n",l,r,t->sum,t->lm,t->rm,t->mm);
    return t;
}
void modi(node*x,int p,ll v){
    if(x->l==x->r){
        x->sum=x->lm=x->rm=x->mm=v;
    }else{
        if(p<=x->ch[0]->r)modi(x->ch[0],p,v);
        else modi(x->ch[1],p,v);
        upda(x);
    }
}
node que(node*x,int l,int r){
    if(l<=x->l&&r>=x->r)return *x;
    else{
        int m=(x->l+x->r)/2;
        if(r<=m)return que(x->ch[0],l,r);
        else if(l>m)return que(x->ch[1],l,r);
        else{
            node t(l,r),y=que(x->ch[0],l,m),z=que(x->ch[1],m+1,r);
            t.ch[0]=&y;
            t.ch[1]=&z;
            upda(&t);
            return t;
        } 
    }
}
int main(){
    int n,m;sf("%d%d",&n,&m);
    lp(i,1,n)sf("%lld",&val[i]);
    node*rt=build(1,n);
    lp(i,1,m){
        int q,l,r;sf("%d%d%d",&q,&l,&r);
        if(q==1)pf("%lld\n",que(rt,min(l,r),max(l,r)).mm);
        else modi(rt,l,r);
    }
    //ps;
    return 0;
}
