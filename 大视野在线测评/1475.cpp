#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define pb push_back
//#define mp make_pair
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
#define vp(i,v) for(int i=0;i<v.size();++i)
#define wp(i,v) for(int i=int(v.size()-1);i>=0;--i)
typedef long long ll;
using namespace std;
namespace isap{
    struct edge{int v,c;};
    vector<edge>eg;vector<int>to[40010];
    int dis[40010],gap[40010],vcnt;
    void add(int u,int v,int c){edge e;e.v=v;e.c=c;to[u].pb(eg.size());eg.pb(e);}
    int dfs(int u,int f){
        if(u==vcnt)return f;
        int g=f;
        lp(i,0,int(to[u].size()-1)){
            edge&e=eg[to[u][i]],&ev=eg[to[u][i]^1];
            if(e.c&&dis[e.v]+1==dis[u]){
                int t=dfs(e.v,min(g,e.c));
                e.c-=t,ev.c+=t,g-=t;
                if(!g||dis[1]==vcnt)return f-g;
            }
        }
        if(!--gap[dis[u]])dis[1]=vcnt;
        ++gap[++dis[u]];
        return f-g;
    }
    int run(){
        int r=0;gap[0]=vcnt;
        while(dis[1]<vcnt)r+=dfs(1,~0u>>1);
        return r;
    }
}
int n,nw,cd[210][210],st,et;
int mp[210][210];
int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
bool ava(int i,int j){
    return i>0&&i<=n&&j>0&&j<=n;
}
int main(){
    sf("%d",&n);
    lp(i,1,n)lp(j,1,n)sf("%d",&mp[i][j]);
    st=++nw;lp(i,1,n)lp(j,1,n)cd[i][j]=++nw;
    et=++nw;
    int sigma=0;
    lp(i,1,n)lp(j,1,n)sigma+=mp[i][j];
    isap::vcnt=nw;
    lp(i,1,n)lp(j,1,n){
           if((i+j)&1){
                isap::add(st,cd[i][j],mp[i][j]);
                isap::add(cd[i][j],st,0);
                lp(k,0,3){
                    int tx=i+dir[k][0],ty=j+dir[k][1];
                    if(ava(tx,ty)){
                        isap::add(cd[i][j],cd[tx][ty],~0u>>1);
                        isap::add(cd[tx][ty],cd[i][j],0);
                    }
                }
            }else{
                isap::add(cd[i][j],et,mp[i][j]);
                isap::add(et,cd[i][j],0);
            }
    }
    pf("%d\n",sigma-isap::run());
    //ps;
    return 0;
}
