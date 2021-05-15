#include<cstdio>
#include<utility>
#include<vector>
#include<algorithm>
#define sf scanf
#define pf printf
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int A[50010],N,L,Ans=1,G[1000010];
int Not[1000010],P[1000010],Mi[1000010];
vector<pair<int,int> > Fact[50010];
vector<int> Fac[50010];
void dfs(int i,int d,int t){
    if(d==Fact[i].size()){
        if(t>=L)
            Fac[i].push_back(t);
    }else{
        dfs(i,d+1,t);
        lp(j,1,Fact[i][d].second){
            t*=Fact[i][d].first;
            dfs(i,d+1,t);
        }
    }
}
int main(){
    sf("%d%d",&N,&L);
    lp(i,1,N)sf("%d",&A[i]);
    lp(i,2,1000000){
        if(!Not[i])P[++P[0]]=i,Mi[i]=i;
        for(int j=1;j<=P[0]&&P[j]*i<=1000000;++j){
            Not[P[j]*i]=1;
            Mi[P[j]*i]=P[j];
            if(i%P[j]==0)break;
        }
    }
    lp(i,1,N){
        while(A[i]!=1){//因为L>1，所以没考虑因数1 
            int t=Mi[A[i]],c=0;
            while(A[i]%t==0)++c,A[i]/=t;
            Fact[i].push_back(make_pair(t,c));
        }
        dfs(i,0,1);
        int t=1;
        lp(j,0,int(Fac[i].size())-1)
            t=max(t,G[Fac[i][j]]+1);
        lp(j,0,int(Fac[i].size())-1)
            G[Fac[i][j]]=max(G[Fac[i][j]],t);
        Ans=max(Ans,t);
    } 
    pf("%d\n",Ans);
    //ps;
    return 0;
}
