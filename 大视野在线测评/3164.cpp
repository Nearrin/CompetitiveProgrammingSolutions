#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define pb push_back
#define mp make_pair
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
#define vp(i,v) for(int i=0;i<v.size();++i)
#define wp(i,v) for(int i=int(v.size()-1);i>=0;--i)
typedef long long ll;
using namespace std;
int n;vector<int>ch[200010];
namespace task1{
    int dp[200010],iswin[200010];
    void dfs(int u,int d){
        if(ch[u].size()==0){
            dp[u]=1;
        }else{
            vp(i,ch[u])dfs(ch[u][i],d+1);
            if(d%2==1){
                dp[u]=~0u>>1;
                vp(i,ch[u])dp[u]=min(dp[u],dp[ch[u][i]]);
            }else{
                vp(i,ch[u])dp[u]+=dp[ch[u][i]];
            }
        }
    }
    void flag(int u,int d){
        if(ch[u].size()==0){
            iswin[u]=1;
        }else{
            if(d%2==1){
                vp(i,ch[u])if(dp[ch[u][i]]==dp[u])flag(ch[u][i],d+1);
            }else{
                vp(i,ch[u])flag(ch[u][i],d+1);
            }
        }
    }
    void solve(){
        dfs(1,1);
        flag(1,1);
        //lp(i,1,n)if(iswin[i])pf("%d ",i);pf("\n");
    }
}
namespace task2{
    int dp[200010],iswin[200010];
    void dfs(int u,int d){
        if(ch[u].size()==0){
            dp[u]=1;
        }else{
            vp(i,ch[u])dfs(ch[u][i],d+1);
            if(d%2==0){
                dp[u]=~0u>>1;
                vp(i,ch[u])dp[u]=min(dp[u],dp[ch[u][i]]);
            }else{
                vp(i,ch[u])dp[u]+=dp[ch[u][i]];
            }
        }
    }
    void flag(int u,int d){
        if(ch[u].size()==0){
            iswin[u]=1;
        }else{
            if(d%2==0){
                vp(i,ch[u])if(dp[ch[u][i]]==dp[u])flag(ch[u][i],d+1);
            }else{
                vp(i,ch[u])flag(ch[u][i],d+1);
            }
        }
    }
    void solve(){
        dfs(1,1);
        flag(1,1);
        //lp(i,1,n)if(iswin[i])pf("%d ",i);pf("\n");
    }
}
int main(){
    sf("%d",&n);
    lp(i,2,n){
        int p;sf("%d",&p);
        ch[p].pb(i);
    }
    task1::solve();
    task2::solve();
    vector<int>ans;int ans2=0;
    lp(i,1,n)if(task1::iswin[i]&&task2::iswin[i])ans.pb(i),ans2^=i;
    pf("%d %d %d\n",ans[0],(int)ans.size(),ans2);
    //ps;
    return 0;
}
/*
7
1
1
2
2
3
3
*/
