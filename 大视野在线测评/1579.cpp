#include<cstdio>
#include<algorithm>
#include<vector> 
#include<utility>
#include<queue>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
vector<int>to[10010],we[10010];
int n,m,k;
long long dis[10010][21];
int main(){
    sf("%d%d%d",&n,&m,&k);
    lp(i,1,m){
        int u,v,w;sf("%d%d%d",&u,&v,&w);
        to[u].push_back(v);
        we[u].push_back(w);
        to[v].push_back(u);
        we[v].push_back(w);
    }
    lp(i,1,n)lp(j,0,k)dis[i][j]=-1;
    dis[1][0]=0;
    priority_queue<pair<long long,pair<int,int> > >qu;qu.push(make_pair(0,make_pair(1,0)));
    while(!qu.empty()){
        int u=qu.top().second.first,g=qu.top().second.second;
        long long d=-qu.top().first;qu.pop();
        if(d!=dis[u][g])continue;
        lp(i,0,int(to[u].size()-1)){
            int v=to[u][i],w=we[u][i];
            if(dis[u][g]+w<dis[v][g]||dis[v][g]==-1){
                dis[v][g]=dis[u][g]+w;
                qu.push(make_pair(-dis[v][g],make_pair(v,g)));
            }
            if(g<k&&(dis[u][g]<dis[v][g+1]||dis[v][g+1]==-1)){
                dis[v][g+1]=dis[u][g];
                qu.push(make_pair(-dis[v][g+1],make_pair(v,g+1)));
            }
        }
    }
    long long ans=-1;
    lp(i,0,k)if(dis[n][i]!=-1){
        if(ans==-1||dis[n][i]<ans)ans=dis[n][i];
    }
    pf("%lld\n",ans);
    //ps;
    return 0;
}
