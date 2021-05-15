#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
struct edge{
    int v,c;
}edges[400010];int nw=1;
int vcnt,dis[100010],gap[100010];
vector<int>to[100010];
void add(int u,int v,int c){   
    edge&e=edges[++nw];e.v=v;e.c=c;to[u].push_back(nw);
}
int dfs(int u,int f){
    if(u==vcnt)return f;
    int g=f;
    lp(i,0,int(to[u].size()-1)){
        edge&e=edges[to[u][i]],&ev=edges[to[u][i]^1];
        if(e.c&&dis[u]==dis[e.v]+1){
            int t=dfs(e.v,min(g,e.c));
            e.c-=t;ev.c+=t;g-=t;
            if(!g||dis[1]==vcnt)return f-g;
        }
    }
    if(!--gap[dis[u]])dis[1]=vcnt;
    ++gap[++dis[u]];
    return f-g;
}
int isap(){
    gap[0]=vcnt;
    int r=0;while(dis[1]<vcnt)r+=dfs(1,~0u>>1);
    return r;
}
int main(){
    //fr("profit.in","r",stdin);
    //fr("profit.out","w",stdout);  
    int n,m,ans=0;
    sf("%d%d",&n,&m);
    vcnt=n+m+2;
    lp(i,1,n){
        int t;sf("%d",&t);
        add(i+1,n+m+2,t);
        add(n+m+2,i+1,0);
    }
    lp(i,1,m){
        int a,b,c;sf("%d%d%d",&a,&b,&c);
        ans+=c;
        add(n+1+i,a+1,~0u>>1);
        add(a+1,n+1+i,0);
        add(n+1+i,b+1,~0u>>1);
        add(b+1,n+1+i,0);
        add(1,n+1+i,c);
        add(n+1+i,1,0);
    }
    pf("%d\n",ans-isap());
    //ps;
    return 0;
     
}
