#include<cstdio>
#include<iostream>
#define pf printf
#define sf scanf
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int Mx=20050;
int Pr[Mx],Tr[Mx][26],Ln[Mx],Nw=4,Lst[5]={0,1,2,3,4};
void ext(int c,int k){
    int p=Lst[k],np=++Nw;Ln[np]=Ln[p]+1,Lst[k]=np;
    for(;p&&!Tr[p][c];p=Pr[p])Tr[p][c]=np;
    if(!p)Pr[np]=k;
    else{
        int q=Tr[p][c];
        if(Ln[p]+1==Ln[q])Pr[np]=q;
        else{
            int nq=++Nw;Ln[nq]=Ln[p]+1;
            copy(Tr[q],Tr[q]+26,Tr[nq]);
            Pr[nq]=Pr[q],Pr[np]=Pr[q]=nq;
            for(;p&&Tr[p][c]==q;p=Pr[p])Tr[p][c]=nq;
        }
    }
}
char Str[2010];
int F[2010][5],N;
int main(){
    //freopen("pow.in","r",stdin);
    //freopen("pow.out","w",stdout);
    sf("%d",&N);
    lp(i,1,N-1){sf("%s",Str);for(int j=0;Str[j];++j)ext(Str[j]-'a',i);}
    sf("%s",Str+1);
    lp(j,1,N-1){
        int l=0,u=j;
        for(int i=1;Str[i];++i){
            if(Tr[u][Str[i]-'a'])++l,u=Tr[u][Str[i]-'a'];
            else{
                while(u&&!Tr[u][Str[i]-'a'])u=Pr[u];
                if(u==0)u=j,l=0;
                else l=Ln[u]+1,u=Tr[u][Str[i]-'a'];
            }
            F[i][j]=l;
        }
    }
    for(int i=1;Str[i];++i)lp(j,2,N-1)F[i][j]=min(F[i][j],F[i][j-1]);
    int ans=0;
    for(int i=1;Str[i];++i)ans=max(ans,F[i][N-1]);
    pf("%d\n",N==1?N:ans);
    //ps;
    return 0;
}
