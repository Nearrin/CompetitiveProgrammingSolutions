#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<utility>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
namespace isap{
    int vcnt,nw,st,et;
    int gap[20010],dis[20010];
    vector<int>bg[20010];
    void init(){
        nw=1;lp(i,1,vcnt)bg[i].clear();
        lp(i,1,vcnt)dis[i]=0,gap[i]=0;gap[0]=vcnt;
    }
    struct edge{int v,c;}edges[200000*3];
    void add(int u,int v,int c){
        edge&e=edges[++nw];
        e.v=v;e.c=c;bg[u].push_back(nw);
    }
    int dfs(int u,int f){
        if(u==et)return f;
        int g=f;
        lp(i,0,int(bg[u].size()-1)){
            edge&e=edges[bg[u][i]],&ev=edges[bg[u][i]^1];
            if(e.c&&dis[u]==dis[e.v]+1){
                int t=dfs(e.v,min(g,e.c));
                e.c-=t;ev.c+=t;g-=t;
                if(!g||dis[st]==vcnt)return f-g;
            }
        }
        if((--gap[dis[u]])==0)dis[st]=vcnt;
        ++gap[++dis[u]];
        return f-g;
    }
    int solve(){
        int r=0;while(dis[st]<vcnt)r+=dfs(st,~0u>>1);
        return r;
    }
} 
#define mp make_pair 
#define pb push_back
#define ft first 
#define sd second
vector<pair<int,pair<int,int> > >egs;
int main(){
    int n,m;sf("%d%d",&n,&m);
    lp(i,1,m){
        int u,v,w;sf("%d%d%d",&u,&v,&w);
        egs.pb(mp(w,mp(u,v)));
    }
    int uu,vv,l;sf("%d%d%d",&uu,&vv,&l);
    isap::vcnt=n;isap::st=uu;isap::et=vv;
    isap::init();
    lp(i,0,int(egs.size()-1)){
        if(egs[i].ft>=l)continue;
        int u=egs[i].sd.ft,v=egs[i].sd.sd;
        isap::add(u,v,1),isap::add(v,u,1);
    } 
    int ans=isap::solve();
    isap::init();
    lp(i,0,int(egs.size()-1)){
        if(egs[i].ft<=l)continue;
        int u=egs[i].sd.ft,v=egs[i].sd.sd;
        isap::add(u,v,1),isap::add(v,u,1);
    } 
    ans+=isap::solve();
    pf("%d\n",ans);
    //ps;
    return 0;
}
