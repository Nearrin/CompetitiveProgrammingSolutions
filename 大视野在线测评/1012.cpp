#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<map>
#define sf scanf
#define pf printf
#define ps system("pause")
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int L[200010],R[200010],S[200010],M[200010],V[200010],W[200010],NW,RT;
void init(){
    M[0]=-(~0u>>1);
}
int mak(int v){
    ++NW;
    S[NW]=1;M[NW]=V[NW]=v;
    W[NW]=rand()*rand();
    return NW;
}
void up(int x){
    S[x]=S[L[x]]+S[R[x]]+1;
    M[x]=max(max(M[L[x]],M[R[x]]),V[x]);
}
void rot_l(int &x){
    int t=L[x];
    L[x]=R[t];
    R[t]=x;
    up(x);
    up(t);
    x=t;
}
void rot_r(int &x){
    int t=R[x];
    R[x]=L[t];
    L[t]=x;
    up(x);
    up(t);
    x=t;
}
void spl(int &x,int k){
    if(k<S[L[x]]+1)spl(L[x],k),rot_l(x);
    else if(k>S[L[x]]+1)spl(R[x],k-S[L[x]]-1),rot_r(x);
}
void ins(int &x,int y){
    if(x==0)x=y;
    else{
        ins(R[x],y);
        up(x);
        if(W[R[x]]<W[x])rot_r(x);
    }
}
int main(){
    int m,d,last=0,t;sf("%d%d",&m,&d);char op;
    lp(i,1,m){
        op=getchar();while(op=='\n'||op==' ')op=getchar();
        sf("%d",&t);
        if(op=='A'){
            ins(RT,mak((last+t)%d));
        }else{
            if(t==S[RT])last=M[RT];
            else{
                spl(RT,S[RT]-t);
                last=M[R[RT]];
            }
            pf("%d\n",last);
        }
    }
    //ps;
    return 0;
}
