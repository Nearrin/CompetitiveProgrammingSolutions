#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<queue>
#include<iostream>
#define sf scanf
#define pf printf
#define ps system("pause")
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
vector<int> E[1010],W[1010];
int N,P,K,DIS[1010],IN[1010];
bool check(int t){
    lp(i,1,N)DIS[i]=~0u>>1,IN[i]=0;
    DIS[1]=0;IN[1]=1;
    queue<int> Q;Q.push(1);
    while(!Q.empty()){
        int u=Q.front();Q.pop();IN[u]=0;
        lp(i,0,int(E[u].size())-1){
            int v=E[u][i],w=(W[u][i]>t);
            if(DIS[u]+w<DIS[v]){
                DIS[v]=DIS[u]+w;
                if(!IN[v]){
                    IN[v]=1;
                    Q.push(v);
                }
            }
        }
    }
    return DIS[N]<=K;
}
int main(){
    sf("%d%d%d",&N,&P,&K);
    lp(i,1,P){
        int ai,bi,ci;
        sf("%d%d%d",&ai,&bi,&ci);
        E[ai].push_back(bi);
        W[ai].push_back(ci);
        E[bi].push_back(ai);
        W[bi].push_back(ci);
    }
    if(check(0)){
        pf("0\n");
    }else if(!check(1000010)){
        pf("-1\n");
    }else{
        int l=0,r=1000010;
        //lcan,rcan't
        while(l+1<r){
            if(check((l+r)/2))
                r=(l+r)/2;
            else
                l=(l+r)/2;
        } 
        pf("%d\n",r);
    }
    //ps;
    return 0;
}
