#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<queue>
#define sf scanf
#define pf printf
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
int n,q,a[100010];
struct node{
    node*ch[2];int l,r;
    int mxl,mxr,mxs;int mxlp,mxrp,mxspl,mxspr;
    int mil,mir,mis;int milp,mirp,mispl,mispr;
    int rev,sum;
}*rt;
void down(node*u){
    if(u->rev==1){
        swap(u->mxl,u->mil);swap(u->mxlp,u->milp);
        swap(u->mxr,u->mir);swap(u->mxrp,u->mirp);
        swap(u->mxs,u->mis);swap(u->mxspl,u->mispl);
        swap(u->mxspr,u->mispr);
        u->mxl=-u->mxl;u->mxr=-u->mxr;
        u->mxs=-u->mxs;
        u->mil=-u->mil;u->mir=-u->mir;
        u->mis=-u->mis;
        u->rev=0;u->sum=-u->sum;
        if(u->l!=u->r){
            u->ch[0]->rev^=1;
            u->ch[1]->rev^=1;
        }
    }
}
void update(node*u){
    down(u->ch[0]);
    down(u->ch[1]);
    u->sum=u->ch[0]->sum+u->ch[1]->sum;
    if(u->ch[0]->mxl>u->ch[0]->sum+u->ch[1]->mxl){
        u->mxl=u->ch[0]->mxl;
        u->mxlp=u->ch[0]->mxlp;
    }else{
        u->mxl=u->ch[0]->sum+u->ch[1]->mxl;
        u->mxlp=u->ch[1]->mxlp;
    }
    if(u->ch[1]->mxr>u->ch[1]->sum+u->ch[0]->mxr){
        u->mxr=u->ch[1]->mxr;
        u->mxrp=u->ch[1]->mxrp;
    }else{
        u->mxr=u->ch[1]->sum+u->ch[0]->mxr;
        u->mxrp=u->ch[0]->mxrp;
    }
    if(u->ch[0]->mxs>=u->ch[1]->mxs&&u->ch[0]->mxs>=u->ch[0]->mxr+u->ch[1]->mxl){
        u->mxs=u->ch[0]->mxs;
        u->mxspl=u->ch[0]->mxspl;
        u->mxspr=u->ch[0]->mxspr;
    }else if(u->ch[1]->mxs>=u->ch[0]->mxs&&u->ch[1]->mxs>=u->ch[0]->mxr+u->ch[1]->mxl){
        u->mxs=u->ch[1]->mxs;
        u->mxspl=u->ch[1]->mxspl;
        u->mxspr=u->ch[1]->mxspr;
    }else{
        u->mxs=u->ch[0]->mxr+u->ch[1]->mxl;
        u->mxspl=u->ch[0]->mxrp;
        u->mxspr=u->ch[1]->mxlp;
    }
    if(u->ch[0]->mil<u->ch[0]->sum+u->ch[1]->mil){
        u->mil=u->ch[0]->mil;
        u->milp=u->ch[0]->milp;
    }else{
        u->mil=u->ch[0]->sum+u->ch[1]->mil;
        u->milp=u->ch[1]->milp;
    }
    if(u->ch[1]->mir<u->ch[1]->sum+u->ch[0]->mir){
        u->mir=u->ch[1]->mir;
        u->mirp=u->ch[1]->mirp;
    }else{
        u->mir=u->ch[1]->sum+u->ch[0]->mir;
        u->mirp=u->ch[0]->mirp;
    }
    if(u->ch[0]->mis<=u->ch[1]->mis&&u->ch[0]->mis<=u->ch[0]->mir+u->ch[1]->mil){
        u->mis=u->ch[0]->mis;
        u->mispl=u->ch[0]->mispl;
        u->mispr=u->ch[0]->mispr;
    }else if(u->ch[1]->mis<=u->ch[0]->mis&&u->ch[1]->mis<=u->ch[0]->mir+u->ch[1]->mil){
        u->mis=u->ch[1]->mis;
        u->mispl=u->ch[1]->mispl;
        u->mispr=u->ch[1]->mispr;
    }else{
        u->mis=u->ch[0]->mir+u->ch[1]->mil;
        u->mispl=u->ch[0]->mirp;
        u->mispr=u->ch[1]->milp;
    }
    u->l=u->ch[0]->l;
    u->r=u->ch[1]->r;
}
node*build(int l,int r){
    node*t=new node;t->l=l;t->r=r;t->rev=0;
    if(l==r){
        t->mxl=t->mxr=t->mxs=a[l];
        t->mil=t->mir=t->mis=a[l];
        t->mxlp=t->mxrp=t->mxspl=t->mxspr=l;
        t->milp=t->mirp=t->mispl=t->mispr=l;
        t->sum=a[l];
    }else{
        int m=(l+r)/2;
        t->ch[0]=build(l,m);
        t->ch[1]=build(m+1,r);
        update(t);
    }
    return t;
}
void reverse(node*u,int l,int r){
    down(u);
    if(l<=u->l&&r>=u->r)u->rev=1;
    else{
        int m=(u->l+u->r)/2;
        if(l<=m)reverse(u->ch[0],l,r);
        if(r>m)reverse(u->ch[1],l,r);
        update(u);
    }
}
void modify(node*u,int p,int v){
    down(u);
    if(u->l==u->r){
        u->mxl=u->mxr=u->mxs=v;
        u->mil=u->mir=u->mis=v;
        u->sum=v;
    }else{
        int m=(u->l+u->r)/2;
        if(p<=m)modify(u->ch[0],p,v);
        else modify(u->ch[1],p,v);
        update(u);
    }
}
void printnode(node*u){
    pf("[%d,%d]\n",u->l,u->r);
    pf("[%d,%d,%d]\n",u->mxl,u->mxr,u->mxs);
    pf("[%d,%d,%d,%d]\n",u->mxlp,u->mxrp,u->mxspl,u->mxspr);
    pf("[%d,%d,%d]\n",u->mil,u->mir,u->mis);
    pf("[%d,%d,%d,%d]\n",u->milp,u->mirp,u->mispl,u->mispr);
    pf("[%d,%d]\n\n",u->rev,u->sum);
} 
void print(node*u){
    down(u);
    printnode(u);
    if(u->l!=u->r)print(u->ch[0]),print(u->ch[1]); 
}
node query(node*u,int l,int r){
    down(u);
    if(l<=u->l&&r>=u->r)return*u;
    else{
        int m=(u->l+u->r)/2;
        if(r<=m)return query(u->ch[0],l,r);
        else if(l>m)return query(u->ch[1],l,r);
        else{
            node t1=query(u->ch[0],l,r);
            node t2=query(u->ch[1],l,r);
            node t3;t3.rev=0;t3.ch[0]=&t1,t3.ch[1]=&t2;
            update(&t3);
            return t3;
        }
    }
}
int main(){
    sf("%d",&n);
    lp(i,1,n)sf("%d",&a[i]);
    rt=build(1,n);
    sf("%d",&q);
    lp(i,1,q){
        int u;sf("%d",&u);
        if(u==0){
            int v,w;sf("%d%d",&v,&w);
            modify(rt,v,w);
        }else{
            int ans=0;
            int l,r,k;sf("%d%d%d",&l,&r,&k);
            vector<pair<int,int> >tmp;
            for(node t=query(rt,l,r);t.mxs>0&&k>0;t=query(rt,l,r),--k){
                tmp.push_back(make_pair(t.mxspl,t.mxspr));
                ans+=t.mxs;
                reverse(rt,t.mxspl,t.mxspr);
            }
            lp(j,0,int(tmp.size())-1){
                reverse(rt,tmp[j].first,tmp[j].second);
            }
            pf("%d\n",ans);
        }
    }
    //ps;
    return 0;
}
