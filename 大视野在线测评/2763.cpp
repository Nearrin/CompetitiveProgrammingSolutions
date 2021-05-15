#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<queue>
#include<utility>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
vector<int>to[10010],we[10010];
int n,s,t,m,k,f[10010][11],in[10010][11];
int main(){
    sf("%d%d%d%d%d",&n,&m,&k,&s,&t);++s,++t;
    lp(i,1,m){
        int a,b,c;sf("%d%d%d",&a,&b,&c);
        ++a;++b;
        to[a].push_back(b);
        we[a].push_back(c);
        to[b].push_back(a);
        we[b].push_back(c);
    }
    lp(i,1,n)lp(j,0,k)f[i][j]=~0u>>1;
    f[s][0]=0;in[s][0]=1;queue<pair<int,int> >qu;qu.push(make_pair(s,0));
    while(!qu.empty()){
        int u=qu.front().first,d=qu.front().second;qu.pop();in[u][d]=0;
        lp(i,0,int(to[u].size()-1)){
            int v=to[u][i];
            if(f[u][d]+we[u][i]<f[v][d]){
                f[v][d]=f[u][d]+we[u][i];
                if(!in[v][d]){
                    in[v][d]=1;
                    qu.push(make_pair(v,d));
                } 
            }
            if(d!=k&&f[u][d]<f[v][d+1]){
                f[v][d+1]=f[u][d];
                if(!in[v][d+1]){
                    in[v][d+1]=1;
                    qu.push(make_pair(v,d+1));
                } 
            }
        }
    }
    int ans=~0u>>1;
    lp(i,0,k)ans=min(ans,f[t][i]);
    pf("%d\n",ans);
    //ps;
    return 0;
} 
