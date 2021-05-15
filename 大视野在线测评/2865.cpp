#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
#include<cstring>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
namespace sam{//124MB
    int*mem;
    #define tr(a,b) mem[(a-1)*26+b]
    int pr[500010*2],ln[500010*2],cnt[500010*2],pos[500010*2],nw=1,lst=1;
    void extend(int c,int idx){
        int p=lst,np=++nw;ln[np]=ln[p]+1;lst=np;cnt[np]=1;pos[np]=idx;
        for(;p&&!tr(p,c);p=pr[p])tr(p,c)=np;
        if(!p)pr[np]=1;
        else{
            int q=tr(p,c);
            if(ln[q]==ln[p]+1)pr[np]=q;
            else{
                int nq=++nw;ln[nq]=ln[p]+1;pr[nq]=pr[q];
                lp(i,0,25)tr(nq,i)=tr(q,i);
                pr[np]=pr[q]=nq;
                for(;p&&tr(p,c)==q;p=pr[p])tr(p,c)=nq;
            }
        }
    }
    int tmp[500010*2];
    bool cmp(int a,int b){return ln[a]<ln[b];}
    void count(){
        lp(i,1,nw)tmp[i]=i;sort(tmp+1,tmp+nw+1,cmp);
        for(int i=nw;i;--i)cnt[pr[tmp[i]]]+=cnt[tmp[i]],pos[pr[tmp[i]]]=pos[tmp[i]];
    }
    char str[500010];int len;
    void init(){
        sf("%s",str+1);len=strlen(str+1);
        mem=new int[(len*2+1)*26];lp(i,1,len*2+1)lp(j,0,25)tr(i,j)=0;
        lp(i,1,len)sam::extend(str[i]-'a',i);
        delete[] mem;
    }
}
namespace seg{//2*N*16=16MB
    struct node{
        node(node*a,node*b):
            lc(a),rc(b),t1(-1),t2(-1){}
        node*lc,*rc;int t1,t2;
    }*rt;
    node*build(int l,int r){
        node*x=new node(0,0);
        if(l!=r){
            int m=(l+r)/2;
            x->lc=build(l,m);
            x->rc=build(m+1,r);
        }
        return x;
    }
    void maket1(node*x,int xl,int xr,int l,int r,int t){
        if(l<=xl&&r>=xr){
            if(x->t1==-1||x->t1>t)
                x->t1=t;
        }else{
            int m=(xl+xr)/2;
            if(l<=m)maket1(x->lc,xl,m,l,r,t);
            if(r>=m+1)maket1(x->rc,m+1,xr,l,r,t);
        }
    }
    void maket2(node*x,int xl,int xr,int l,int r,int t){
        if(l<=xl&&r>=xr){
            if(x->t2==-1||x->t2>t)
                x->t2=t;
        }else{
            int m=(xl+xr)/2;
            if(r<=m)maket2(x->lc,xl,m,l,r,t);
            else if(l>m)maket2(x->rc,m+1,xr,l,r,t);
            else{
                maket2(x->lc,xl,m,l,m,t+(r-(m+1)+1));
                maket2(x->rc,m+1,xr,m+1,r,t);
            }
        }
    }
    int query(node*x,int xl,int xr,int p){
        int r=~0u>>1;
        if(x->t1!=-1)r=min(r,x->t1);
        if(x->t2!=-1)r=min(r,x->t2+xr-p);
        if(xl!=xr){
            int m=(xl+xr)/2;
            if(p<=m)r=min(r,query(x->lc,xl,m,p));
            else r=min(r,query(x->rc,m+1,xr,p));
        }
        return r;
    
    }
}
void work(){
    lp(i,1,sam::nw)if(sam::cnt[i]==1){
        int l1=sam::pos[i]-sam::ln[i]+1,l2=sam::pos[i]-sam::ln[sam::pr[i]],r=sam::pos[i];
        //pf("[%d,%d,%d]\n",l1,l2,r);
        if(l2+1<=r)seg::maket1(seg::rt,1,sam::len,l2+1,r,r-l2+1);
        seg::maket2(seg::rt,1,sam::len,l1,l2,r-l2+1);
        //pf("[%d]\n",seg::query(seg::rt,4));
    }
    lp(i,1,sam::len)pf("%d\n",seg::query(seg::rt,1,sam::len,i));
}
int main(){
    sam::init();
    sam::count();
    seg::rt=seg::build(1,sam::len);
    work();
    //ps;
    return 0;
}
