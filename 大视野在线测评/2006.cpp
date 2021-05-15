#include<cstdio>
#include<algorithm>
#include<queue>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int A[500010],S[500010],N,L,R,K;
struct node{
    node(node*a,node*b,int c,int d,int e):
        lc(a),rc(b),l(c),r(d),cnt(e){}
    node*lc,*rc;
    int cnt,l,r;
}*segs[500010];
void spl(node*x){
    int m=x->l+((x->r-x->l)>>1);//attention
    if(x->lc==0)x->lc=new node(0,0,x->l,m,0);
    if(x->rc==0)x->rc=new node(0,0,m+1,x->r,0);
}
node*add(node*x,int v){
    if(x->l==x->r){
        return new node(0,0,x->l,x->r,x->cnt+1);
    }else{
        spl(x);
        if(v<=x->lc->r){
            return new node(add(x->lc,v),x->rc,x->l,x->r,x->cnt+1);
        }else{
            return new node(x->lc,add(x->rc,v),x->l,x->r,x->cnt+1);
        }
    }
}
int que(node*x,node*y,int k){
    if(x->l==x->r){
        return x->l;
    }else{
        spl(x),spl(y);
        if(y->lc->cnt-x->lc->cnt>=k)return que(x->lc,y->lc,k);
        else return que(x->rc,y->rc,k-(y->lc->cnt-x->lc->cnt));
    }
}
struct song{
    song(int a,int b,int c,int d,int e):
        rt(a),k(b),v(c),l(d),r(e){}
    int rt,k,v,l,r;
};
bool operator<(song a,song b){
    return a.v<b.v;//attention
}
int main(){
    sf("%d%d%d%d",&N,&K,&L,&R);
    lp(i,1,N)sf("%d",&A[i]);
    lp(i,1,N)S[i]=S[i-1]+A[i];
    segs[0]=new node(0,0,0,500000*2000+10,0);
    lp(i,1,N)segs[i]=add(segs[i-1],S[i-1]+500000*1000);
    /*int q;sf("%d",&q);
    lp(i,1,q){
        int a,b;sf("%d%d",&a,&b);
        pf("[%d]",que(segs[a],b)-500000*1000);
    }*/
    priority_queue<song>qu;
    lp(i,1,N){
        int l=i-R,r=i-L;
        if(l<0)l=0;
        if(r>=0){
            ++l,++r;
            qu.push(song(i,1,S[i]-(que(segs[l-1],segs[r],1)-500000*1000),l,r));
        }
    }
    long long ans=0;//attention
    lp(i,1,K){
        song t=qu.top();qu.pop();
        ans+=t.v;
        if(t.k!=t.r-t.l+1){//still have
            qu.push(song(t.rt,t.k+1,S[t.rt]-(que(segs[t.l-1],segs[t.r],t.k+1)-500000*1000),t.l,t.r));
        }
    }
    pf("%lld\n",ans);
    //ps;
    return 0;
}
