#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
#include<vector>
#include<queue>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int n,m,kk,fail[31],ch[31][10],nw=1;
char str[31];
struct mat{
    int d[31][31],l;
};
void printmat(mat a){
    lp(i,1,a.l){lp(j,1,a.l){
        pf("%d ",a.d[i][j]);
    }pf("\n");}pf("\n");
}
mat operator*(mat a,mat b){
    mat c;c.l=a.l;
    lp(i,1,c.l)lp(j,1,c.l)c.d[i][j]=0;
    lp(i,1,c.l)
        lp(j,1,c.l)
            lp(k,1,c.l){
                c.d[i][j]+=a.d[i][k]*b.d[k][j];
                c.d[i][j]%=kk;
            }
    return c;
}
mat pw(mat t,int b){
    mat r;r.l=t.l;lp(i,1,r.l)lp(j,1,r.l)r.d[i][j]=(i==j);
    while(b){
        if(b&1)r=r*t;
        t=t*t;
       // printmat(t);
        b>>=1;
    }
    return r;
}
int main(){
    sf("%d%d%d",&n,&m,&kk);
    sf("%s",str+1);
    lp(i,1,m){++nw;ch[nw-1][str[i]-'0']=nw;}
    lp(i,0,9)if(!ch[1][i])ch[1][i]=1;else fail[ch[1][i]]=1;
    lp(i,2,nw){
        lp(j,0,9)if(!ch[i][j])ch[i][j]=ch[fail[i]][j];
            else fail[ch[i][j]]=ch[fail[i]][j];
    }
    mat t;t.l=nw;lp(i,1,nw)lp(j,1,nw)t.d[i][j]=0;
    lp(i,1,nw)lp(j,0,9)if(ch[i][j]!=m+1)++t.d[i][ch[i][j]];
    t=pw(t,n);
    int ans=0;lp(i,1,nw)ans=(ans+t.d[1][i])%kk;
    pf("%d\n",ans);
    //ps;
    return 0;
}
