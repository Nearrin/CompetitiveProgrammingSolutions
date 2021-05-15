#include<cstdio>
#include<algorithm>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=300000;
int pr[N],ch[N][2],sz[N],mx[N],val[N],re[N],dl[N],nw,rt;
int tp(int x){return x==ch[pr[x]][1];}
void print(){
    pf("[rt:%d]\n",rt);
    lp(i,1,nw)pf("[id:%d][pr:%d][ch:%d,%d][sz:%d]\n",i,pr[i],ch[i][0],ch[i][1],sz[i]);
}
void dwn(int x){
    if(re[x]){
        swap(ch[x][0],ch[x][1]);
        if(ch[x][0])re[ch[x][0]]^=1;
        if(ch[x][1])re[ch[x][1]]^=1;
        re[x]=0;
    }
    if(dl[x]){
        if(ch[x][0])dl[ch[x][0]]+=dl[x];
        if(ch[x][1])dl[ch[x][1]]+=dl[x];
        val[x]+=dl[x];
        mx[x]+=dl[x];
        dl[x]=0;
    }
}
void upda(int x){
    if(ch[x][0])dwn(ch[x][0]);
    if(ch[x][1])dwn(ch[x][1]);
    sz[x]=1;
    if(ch[x][0])sz[x]+=sz[ch[x][0]];
    if(ch[x][1])sz[x]+=sz[ch[x][1]];
    mx[x]=val[x];
    if(ch[x][0])mx[x]=max(mx[x],mx[ch[x][0]]);
    if(ch[x][1])mx[x]=max(mx[x],mx[ch[x][1]]);
}
void set(int x,int y,int d){
    ch[x][d]=y;pr[y]=x;
    upda(x);
}
void rot(int x){
    //pf("[%d]\n",x);
    //print();
    int y=pr[x],z=pr[y],d1=tp(x),d2=tp(y);
    set(y,ch[x][!d1],d1);
    set(x,y,!d1);
    if(z)set(z,x,d2);else pr[x]=0;
    //print();getchar();
}
void spl(int x,int p){
    while(pr[x]!=p){
        int y=pr[x];
        if(pr[y]==p)rot(x);
        else if(tp(x)==tp(y))rot(y),rot(x);
        else rot(x),rot(x);
    }
    if(!p)rt=x;
}
int sel(int x,int k){
    dwn(x);
    int t=ch[x][0]?sz[ch[x][0]]:0;
    if(k<=t)return sel(ch[x][0],k);
    else if(k==t+1)return x;
    else return sel(ch[x][1],k-(t+1));
}
void rever(int l,int r){
    spl(sel(rt,l),0);
    spl(sel(rt,r+2),rt);
    re[ch[ch[rt][1]][0]]^=1;
}
void adde(int l,int r,int d){
    spl(sel(rt,l),0);
    spl(sel(rt,r+2),rt);
    dl[ch[ch[rt][1]][0]]+=d;
}
int quer(int l,int r){
    spl(sel(rt,l),0);
    spl(sel(rt,r+2),rt);
    return mx[ch[ch[rt][1]][0]];
}
int build(int l,int r){
    int x=++nw;sz[x]=1;
    if(l!=r){
        int m=(l+r)/2;
        ch[x][0]=build(l,m);sz[x]+=sz[ch[x][0]];pr[ch[x][0]]=x;
        ch[x][1]=build(m+1,r);sz[x]+=sz[ch[x][1]];pr[ch[x][1]]=x;
    }
    return x;
}
int main(){
    int n,m;sf("%d%d",&n,&m);
    rt=build(0,n+1);
    lp(i,1,m){
        int k,l,r,v;sf("%d%d%d",&k,&l,&r);
        if(k==1){
            sf("%d",&v);
            adde(l,r,v);
        }else if(k==2){
            rever(l,r);
        }else pf("%d\n",quer(l,r));
    }
    //ps;
    return 0;
}
