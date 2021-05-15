#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
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
namespace spfa{
    int vcnt,dis[2000010];
    struct data{data(int a,int b):d(a),u(b){}int d,u;};
    bool operator<(const data&a,const data&b){return a.d>b.d;}
    vector<int>to[2000010],we[2000010];
    void add(int u,int v,int w){to[u].pb(v);we[u].pb(w);to[v].pb(u);we[v].pb(w);}
    int solve(){
        lp(i,1,vcnt)dis[i]=~0u>>1;dis[1]=0;
        priority_queue<data>qu;qu.push(data(0,1));
        while(dis[vcnt]==~0u>>1){
            int u=qu.top().u,d=qu.top().d;qu.pop();
            if(d!=dis[u])continue;
            vp(i,to[u]){
                int v=to[u][i],w=we[u][i];
                if(dis[u]+w<dis[v]){
                    dis[v]=dis[u]+w;
                    qu.push(data(dis[v],v));
                }
            }
        }
        return dis[vcnt];
    }
}
 
int n,m,st,et,up[1010][1010],dw[1010][1010],nw;
int main(){
    sf("%d%d",&n,&m);
    if(n==1){
        int ans=~0u>>1;
        lp(i,1,m-1){
            int t;sf("%d",&t);
            ans=min(ans,t);
        }
        pf("%d\n",ans);
    }else if(m==1){
        int ans=~0u>>1;
        lp(i,1,n-1){
            int t;sf("%d",&t);
            ans=min(ans,t);
        }
        pf("%d\n",ans);
    }else{
        st=++nw;
        lp(i,1,n-1)lp(j,1,m-1)up[i][j]=++nw,dw[i][j]=++nw;
        et=++nw;spfa::vcnt=nw;
        lp(i,1,n)lp(j,1,m-1){
            int t;sf("%d",&t);
            if(i==1)spfa::add(st,up[i][j],t);
            else if(i==n)spfa::add(dw[i-1][j],et,t);
            else spfa::add(dw[i-1][j],up[i][j],t);
        }
        lp(i,1,n-1)lp(j,1,m){
            int t;sf("%d",&t);
            if(j==1)spfa::add(dw[i][j],et,t);
            else if(j==m)spfa::add(st,up[i][j-1],t);
            //else spfa::add(up[i][j-1],dw[i][j],t);
        }
        lp(i,1,n-1)lp(j,1,m-1){
            int t;sf("%d",&t);
            spfa::add(up[i][j],dw[i][j],t);
        }
        pf("%d\n",spfa::solve());
    }
    return 0;
}
