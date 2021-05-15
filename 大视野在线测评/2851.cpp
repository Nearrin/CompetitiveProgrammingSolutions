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
using namespace std;
typedef long long ll;
int up[200010][21],dp[200010],n,q;
int lca(int u,int v){
    if(dp[u]<dp[v])swap(u,v); 
    lp(i,0,20)if(((dp[u]-dp[v])>>i)&1)u=up[u][i];
    if(u==v)return u;
    rp(i,20,0)if(up[u][i]!=up[v][i])u=up[u][i],v=up[v][i];
    return up[u][0]; 
}
vector<int>ch[200010];int rank[200010],nw;
void dfs(int u){vp(i,ch[u])dfs(ch[u][i]);rank[u]=nw++;}
bool cmp(int u,int v){return rank[u]<rank[v];}
int main(){
    sf("%d",&n);
    lp(i,1,n){
        int k;sf("%d",&k);
        if(k)sf("%d",&up[i][0]);
        lp(j,1,k-1){
            int v;sf("%d",&v);
            up[i][0]=lca(v,up[i][0]);
        } 
        //pf("[%d,%d]\n",i,up[i][0]); 
        ch[up[i][0]].pb(i);dp[i]=dp[up[i][0]]+1;
        lp(j,1,20)up[i][j]=up[up[i][j-1]][j-1];
    }
    dfs(0);
    sf("%d",&q);
    lp(i,1,q){
        vector<int>tmp;
        int k;sf("%d",&k);
        lp(j,1,k){
            int v;sf("%d",&v);
            tmp.pb(v);
        } 
        sort(tmp.begin(),tmp.end(),cmp);
        ll ans=0;
        vp(j,tmp)ans+=dp[tmp[j]];
        for(int j=0;j+1<tmp.size();++j)ans-=dp[lca(tmp[j],tmp[j+1])];
        pf("%lld\n",ans);
    } 
    //ps;
    return 0;
}
