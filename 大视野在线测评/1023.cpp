#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<deque>
#include<cstdlib>
#include<stack>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define pb push_back
#define mp make_pair
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
#define vp(i,v) for(int i=0;i<v.size();++i)
using namespace std;
typedef long long ll;
int n;vector<int>to[50010];
void init(){
    int m;sf("%d%d",&n,&m);
    lp(i,1,m){
        int k,u,v;sf("%d%d",&k,&u);
        lp(j,2,k){
            sf("%d",&v);
            to[u].pb(v);
            to[v].pb(u);
            u=v;
        }
    } 
}
int df[50010],lw[50010],pr[50010],dp[50010],nw,ans;stack<int>stk;
void treedp(int u){
    df[u]=lw[u]=++nw;stk.push(u);
    vp(i,to[u]){
        int v=to[u][i];
        if(v==pr[u])continue; 
        else if(df[v])lw[u]=min(lw[u],df[v]);
        else{
            pr[v]=u;treedp(v);lw[u]=min(lw[u],lw[v]);
            if(lw[v]>df[u]){
                ans=max(ans,dp[v]+1+dp[u]);
                dp[u]=max(dp[u],dp[v]+1);
                stk.pop();
            }else if(lw[v]==df[u]){
                vector<int>cir,dcir;
                for(;stk.top()!=v;stk.pop())cir.pb(stk.top());stk.pop();cir.pb(v);cir.pb(u);
                dcir=cir;
                vp(j,cir)dcir.pb(cir[j]);
                deque<int>qu;qu.push_back(0);
                lp(j,1,int(dcir.size()-2)){
                    while(j-qu[0]>cir.size()/2)qu.pop_front();
                    ans=max(ans,dp[dcir[qu[0]]]+dp[dcir[j]]+j-qu[0]);
                    while(!qu.empty()&&dp[dcir[qu.back()]]-qu.back()<=dp[dcir[j]]-j)
                        qu.pop_back();
                    qu.push_back(j);
                }
                lp(j,0,int(cir.size()-2))
                    dp[u]=max(dp[u],dp[cir[j]]+min(j+1,int(cir.size())-(j+1)));
            }
        }
    }
}
int main(){
    init();
    treedp(1);
    pf("%d\n",ans);
    //ps;
    return 0;
}
