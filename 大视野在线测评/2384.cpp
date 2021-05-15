#include<cstdio>
#include<algorithm>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int MXN=1000010;
int A[MXN],N,Pr[MXN],Nx[MXN],Fa[MXN];
int B[MXN],M;
int Ans[MXN];
void init(){
    sf("%d%d",&N,&M);
    lp(i,1,N)sf("%d",&A[i]);
    lp(i,1,M)sf("%d",&B[i]);
}
void trans(){
    static int tmp[MXN];
    lp(i,1,N)tmp[A[i]]=i;
    lp(i,1,N)A[i]=tmp[i];
    //lp(i,1,N)pf("[%d]",A[i]);pf("\n");
}
void make(){
    static int lft[MXN],rht[MXN],pos[MXN];
    lp(i,1,N)lft[i]=i-1,rht[i]=(i==N?0:i+1),pos[A[i]]=i;
    for(int i=N;i;--i){
        Pr[i]=pos[lft[A[i]]];Nx[i]=pos[rht[A[i]]];
        rht[lft[A[i]]]=rht[A[i]];
        lft[rht[A[i]]]=lft[A[i]];
    }
    //lp(i,1,N)pf("[%d,%d]",Pr[i],Nx[i]);pf("\n");
}
bool cmp1(int a,int b){
    if(Pr[a]&&A[b-(a-Pr[a])]>A[b])return false;
    if(Nx[a]&&A[b-(a-Nx[a])]<A[b])return false;
    return true;
}
void build(){
    Fa[1]=0;
    for(int i=2,j=0;i<=N;++i){
        while(j&&!cmp1(j+1,i))j=Fa[j];
        if(cmp1(j+1,i))++j;
        Fa[i]=j;
    }
    //lp(i,1,N)pf("[%d]",Fa[i]);
}
bool cmp2(int a,int b){
    if(Pr[a]&&B[b-(a-Pr[a])]>B[b])return false;
    if(Nx[a]&&B[b-(a-Nx[a])]<B[b])return false;
    return true;
}
void match(){
    for(int i=1,j=0;i<=M;++i){
        while(j&&!cmp2(j+1,i))j=Fa[j];
        if(cmp2(j+1,i))++j;
        if(j==N)j=Fa[j],Ans[++Ans[0]]=i-N+1;
    }
}
void print(){
    pf("%d\n",Ans[0]);
    if(!Ans[0])pf("\n");
    else lp(i,1,Ans[0])pf("%d%c",Ans[i],i==Ans[0]?'\n':' ');
}
int main(){
    init();
    trans();
    make();
    build();
    match();
    print();
    //ps;
    return 0;
}
