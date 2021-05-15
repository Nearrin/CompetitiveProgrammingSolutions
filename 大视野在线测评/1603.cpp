#include<cstdio>
#include<algorithm>
#include<vector>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
vector<int>to[1010],we[1010];int n,q,dis[1010];
void dfs(int u){
    lp(i,0,int(to[u].size()-1))
        if(dis[to[u][i]]==-1)
            dis[to[u][i]]=(dis[u]^we[u][i]),
            dfs(to[u][i]); 
}
int main(){
    sf("%d",&n);
    lp(i,1,n-1){
        int a,b,c;sf("%d%d%d",&a,&b,&c);
        to[a].push_back(b);
        we[a].push_back(c);
        to[b].push_back(a);
        we[b].push_back(c);
    }
    lp(i,2,n)dis[i]=-1;
    dfs(1);
    pf("%d\n",dis[n]);
    //ps;
    return 0;
} 
