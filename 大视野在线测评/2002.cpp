#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
struct node{int c[2],p,s;}nd[200010];
void up(int x){nd[x].s=nd[nd[x].c[0]].s+nd[nd[x].c[1]].s+1;}
int tp(int x){return x!=nd[nd[x].p].c[0];}
void set(int x,int y,int d){
    nd[x].c[d]=y;
    nd[y].p=x;up(x);
}
void print();
void rot(int x){
    int y=nd[x].p,z=nd[y].p,d=tp(x),q;
    if(z>0)q=tp(y);
    set(y,nd[x].c[!d],d);
    set(x,y,!d);
    if(z>0)set(z,x,q);
    else nd[x].p=z;
}
void splay(int x){
    while(nd[x].p>0){
        if(nd[nd[x].p].p<=0)rot(x);
        else if(tp(x)!=tp(nd[x].p))rot(x),rot(x);
        else rot(nd[x].p),rot(x);
    }
} 

void access(int x){
    int y=0;
    do{
        splay(x);
        nd[nd[x].c[1]].p=-x;
        set(x,y,1);
        y=x,x=-nd[x].p;
    }while(x);
}
int ki[200010],n,m;
void print(){
    lp(i,1,n+1)pf("[id:%d,pr:%d,lc:%d,rc:%d,sz:%d]\n",i,nd[i].p,nd[i].c[0],nd[i].c[1],nd[i].s); 
    pf("\n");  
}
int main(){
    sf("%d",&n);
    lp(i,1,n){
        sf("%d",&ki[i]);
        nd[i].c[0]=nd[i].c[1]=0;
        nd[i].p=-min(i+ki[i],n+1);
        nd[i].s=1;
    }
    nd[n+1].c[0]=nd[n+1].c[1]=0;
    nd[n+1].p=0;
    nd[n+1].s=1;
    sf("%d",&m);
    lp(i,1,m){
        int a;sf("%d",&a);
        if(a==1){
            int b;sf("%d",&b);++b;
            access(b);splay(b);
            pf("%d\n",nd[nd[b].c[0]].s);
        }else{
            int b,c;sf("%d%d",&b,&c);++b;
            int t=min(b+c,n+1),ty=min(b+ki[b],n+1);ki[b]=c;
            access(ty);
            splay(b);
            nd[b].p=-t;
        }
    }//ps;
    return 0;
}
