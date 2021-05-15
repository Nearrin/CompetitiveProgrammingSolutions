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
struct graph{ 
    int n;vector<pair<int,int> >eg; 
}; 
vector<int>qs[100010];int ans[100010]; 
int pr[10010]; 
int fd(int x){return x==pr[x]?x:pr[x]=fd(pr[x]);} 
void solve(graph*g,int l,int r){ 
    static int vis[200010]; 
    vp(i,g->eg)vis[i]=0; 
    lp(i,l,r)vp(j,qs[i])vis[qs[i][j]]=1; 
    lp(i,1,g->n)pr[i]=i; 
    vp(i,g->eg)if(!vis[i]){ 
        int u=g->eg[i].first,v=g->eg[i].second; 
        if(fd(u)!=fd(v))pr[fd(u)]=v; 
    } 
    int nw=0;static int lb[10010]; 
    lp(i,1,g->n)if(pr[i]==i)lb[i]=++nw; 
    lp(i,1,g->n)if(pr[i]!=i)lb[i]=lb[fd(i)]; 
    graph*tg=new graph;tg->n=nw; 
    int enw=0;static int elb[200010]; 
    vp(i,g->eg)if(vis[i]){ 
        int u=g->eg[i].first,v=g->eg[i].second; 
        tg->eg.pb(mp(lb[u],lb[v])); 
        elb[i]=enw++; 
    } 
    lp(i,l,r)vp(j,qs[i])qs[i][j]=elb[qs[i][j]]; 
    if(l!=r){ 
        int m=(l+r)/2; 
        solve(tg,l,m); 
        solve(tg,m+1,r); 
    }else ans[l]=(tg->n==1); 
} 
int main(){ 
    int n,m;sf("%d%d",&n,&m);graph*g=new graph;g->n=n; 
    lp(i,1,m){ 
        int a,b;sf("%d%d",&a,&b); 
        g->eg.pb(mp(a,b)); 
    } 
    int k;sf("%d",&k); 
    lp(i,1,k){ 
        int c;sf("%d",&c); 
        lp(j,1,c){ 
            int t;sf("%d",&t); 
            qs[i].pb(t-1); 
        } 
    } 
    solve(g,1,k); 
    lp(i,1,k)pf("%s\n",ans[i]?"Connected":"Disconnected"); 
    return 0; 
}
