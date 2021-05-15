#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
namespace mcmf{
    struct edge{int v,c,w;};
    vector<edge>eg;vector<int>to[1010];int vcnt;
    int dis[1010],in[1010];
    void add(int u,int v,int c,int w){
        edge t;t.v=v;t.c=c;t.w=w;to[u].push_back(eg.size());
        eg.push_back(t);
    }
    bool spfa(){
        lp(i,1,vcnt)dis[i]=~0u>>1,in[i]=0;dis[1]=0;in[1]=1;
        queue<int>qu;qu.push(1);
        while(!qu.empty()){
            int u=qu.front();qu.pop();in[u]=0;
            lp(i,0,int(to[u].size()-1)){
                edge&e=eg[to[u][i]],&ev=eg[to[u][i]^1];
                if(e.c&&dis[u]+e.w<dis[e.v]){
                    dis[e.v]=dis[u]+e.w;
                    if(!in[e.v]){
                        in[e.v]=1;
                        qu.push(e.v);
                    }
                }
            }
        }
        return dis[vcnt]!=~0u>>1;
    }
    int cst;
    int dfs(int u,int f){
        if(u==vcnt)return f;
        in[u]=1;
        int g=f;
        lp(i,0,int(to[u].size()-1)){
            edge&e=eg[to[u][i]],&ev=eg[to[u][i]^1];
            if(e.c&&dis[u]+e.w==dis[e.v]&&!in[e.v]){
                int t=dfs(e.v,min(g,e.c));
                e.c-=t,ev.c+=t,g-=t,cst+=t*e.w;
                if(!g)return f;
            }
        }
        return f-g;
    }
    int solve(){
        while(spfa()){
            lp(i,1,vcnt)in[i]=0;
            dfs(1,~0u>>1); 
        }
        return cst;
    }
}
int main(){
    static int r,c;static char mp[21][21];
    sf("%d%d",&r,&c);
    static int id[21][21][2];
    int st=++mcmf::vcnt;
    lp(i,1,r)lp(j,1,c)id[i][j][0]=++mcmf::vcnt,id[i][j][1]=++mcmf::vcnt;
    int et=++mcmf::vcnt;
    lp(i,1,r)sf("%s",mp[i]+1);
    lp(i,1,r)lp(j,1,c){
        mcmf::add(st,id[i][j][0],1,0);
        mcmf::add(id[i][j][0],st,0,0);
        mcmf::add(et,id[i][j][1],0,0);
        mcmf::add(id[i][j][1],et,1,0);
        if(i!=1){
            mcmf::add(id[i][j][0],id[i-1][j][1],1,int(mp[i][j]!='U'));
            mcmf::add(id[i-1][j][1],id[i][j][0],0,-int(mp[i][j]!='U'));
        }else{
            mcmf::add(id[i][j][0],id[r][j][1],1,int(mp[i][j]!='U'));
            mcmf::add(id[r][j][1],id[i][j][0],0,-int(mp[i][j]!='U'));
        }
        if(i!=r){
            mcmf::add(id[i][j][0],id[i+1][j][1],1,int(mp[i][j]!='D'));
            mcmf::add(id[i+1][j][1],id[i][j][0],0,-int(mp[i][j]!='D'));
        }else{
            mcmf::add(id[i][j][0],id[1][j][1],1,int(mp[i][j]!='D'));
            mcmf::add(id[1][j][1],id[i][j][0],0,-int(mp[i][j]!='D'));
        }
        if(j!=1){
            mcmf::add(id[i][j][0],id[i][j-1][1],1,int(mp[i][j]!='L'));
            mcmf::add(id[i][j-1][1],id[i][j][0],0,-int(mp[i][j]!='L'));
        }else{
            mcmf::add(id[i][j][0],id[i][c][1],1,int(mp[i][j]!='L'));
            mcmf::add(id[i][c][1],id[i][j][0],0,-int(mp[i][j]!='L'));
        }
        if(j!=c){
            mcmf::add(id[i][j][0],id[i][j+1][1],1,int(mp[i][j]!='R'));
            mcmf::add(id[i][j+1][1],id[i][j][0],0,-int(mp[i][j]!='R'));
        }else{
            mcmf::add(id[i][j][0],id[i][1][1],1,int(mp[i][j]!='R'));
            mcmf::add(id[i][1][1],id[i][j][0],0,-int(mp[i][j]!='R'));
        }
    }
    pf("%d\n",mcmf::solve());
    //ps;
    return 0; 
}
