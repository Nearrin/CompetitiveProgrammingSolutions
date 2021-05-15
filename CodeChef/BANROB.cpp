#include<cstdio>
#include<set>
#include<algorithm>
#include<queue>
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
pair<int,int>dp[1010][101];
int vis[1010][101];

void f(int v,int m,double p){
    if(vis[v][m])
        return;
    vis[v][m]=1;
    if(m==1){
        dp[v][m]=make_pair(v,0);
    }else{
        dp[v][m]=make_pair(0,0);
        for(int i=0;i<=v;++i){
            pair<int,int>ifac=make_pair(v-i,i);
            f(int(v*p),m-1,p);
            pair<int,int>ifrj=dp[int(v*p)][m-1];
            if(ifac<ifrj)
                ifac=ifrj;
            swap(ifac.first,ifac.second);
            dp[v][m]=max(dp[v][m],ifac);
        }
    }
}
void F(int v,int m,double p){
    f(v,m,p);
    cout<<v<<" "<<m<<" ";
    cout<<dp[v][m].first<<" "<<dp[v][m].second<<endl;
    double tmp=v*(1-pow(-p,m))/(1+p);
    cout<<tmp<<endl;
    cout<<endl;
}

int main(){
    //for(int i=1;i<=20;++i)
       // F(1000,i,0.3);
    int T;scanf("%d",&T);
    while(T--){
        double m;double p;
        scanf("%lf%lf",&m,&p);
        double v=1000000000;
        double tmp=v*(1-pow(-p,m))/(1+p);
        printf("%.10lf %.10lf\n",tmp,v-tmp);
    }
    return 0;
}
/*
1 0.5 1
2 0.5 0.5
3 0.5 0.75
4 0.5 0.625
5 0.5 0.687




  */
