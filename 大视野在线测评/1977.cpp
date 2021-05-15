#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
namespace tda{
    const int N=100000,L=17;
    vector<int>to[N+10],we[N+10];
    int up[N+10][L+10],dp[N+10];
    pair<int,int>mx[N+10][L+10];
    pair<int,int>merge(pair<int,int>x,pair<int,int>y){
        static int t[4];
        t[0]=x.first;t[1]=x.second;
        t[2]=y.first;t[3]=y.second;
        sort(t,t+4,greater<int>());
        //printf("{%d,%d,%d,%d}\n",t[0],t[1],t[2],t[3]);
        unique(t,t+4);
        //printf("{%d,%d,%d,%d}\n",t[0],t[1],t[2],t[3]);
        //printf("(%d,%d)+(%d,%d)=(%d,%d)\n",x.first,x.second,y.first,y.second,t[0],t[1]);
        return make_pair(t[0],t[1]);
    }
    void add(int u,int v,int w){
        to[u].push_back(v);we[u].push_back(w);
        to[v].push_back(u);we[v].push_back(w);
    }
    void build(){
        static int vis[N+10];
        queue<int>qu;qu.push(1);vis[1]=1;
        while(!qu.empty()){
            int u=qu.front();qu.pop();
            for(int i=1;i<=L;++i){
                up[u][i]=up[up[u][i-1]][i-1];
                mx[u][i]=merge(mx[u][i-1],mx[up[u][i-1]][i-1]);
            }
            for(int i=0;i<to[u].size();++i){
                int v=to[u][i],w=we[u][i];
                if(!vis[v]){
                    vis[v]=1;up[v][0]=u;
                    mx[v][0]=make_pair(w,-(~0u>>1));
                    dp[v]=dp[u]+1;qu.push(v);
                }
            }
        }
    }
    pair<int,int>query(int u,int v){
        pair<int,int>ans(-(~0u>>1),-(~0u>>1)); 
        if(dp[u]<dp[v])swap(u,v);
        for(int i=0;i<=L;++i)
            if(((dp[u]-dp[v])>>i)&1){
                ans=merge(ans,mx[u][i]);
                u=up[u][i];
            }
        if(u==v)return ans;
        for(int i=L;i>=0;--i)
            if(up[u][i]!=up[v][i]){
                ans=merge(ans,mx[u][i]);
                ans=merge(ans,mx[v][i]);
                u=up[u][i];
                v=up[v][i];
            }
        ans=merge(ans,mx[u][0]);
        ans=merge(ans,mx[v][0]);
        return ans;
    }
}
struct edge{
    int x,y,z;
};
bool cmp(edge a,edge b){
    return a.z<b.z;
}
int pr[100010];
int fd(int x){
    return x==pr[x]?x:pr[x]=fd(pr[x]);
}
void lk(int x,int y){
    pr[fd(x)]=y;
}
int main(){
    int n,m;static edge es[300010];
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)scanf("%d%d%d",&es[i].x,&es[i].y,&es[i].z);
    sort(es+1,es+m+1,cmp);
    static int us[300010];
    for(int i=1;i<=n;++i)pr[i]=i;
    long long mst=0;
    for(int i=1;i<=m;++i){
        int u=es[i].x,v=es[i].y,w=es[i].z;
        if(fd(u)!=fd(v)){
            lk(u,v);
            mst+=w;
            tda::add(u,v,w);
            us[i]=1;
            //printf("[%d,%d,%d]\n",u,v,w);
        }
    }
    //printf("MST:%lld\n",mst);
    tda::build();
    long long ans=1000000000000000000ll;
    for(int i=1;i<=m;++i){
        int u=es[i].x,v=es[i].y,w=es[i].z;
        if(us[i])continue;
        pair<int,int>tmp=tda::query(u,v);
        //printf("(%d,%d,%d)(%d,%d)\n",u,v,w,tmp.first,tmp.second);
        if(tmp.first!=w){
            ans=min(ans,mst-tmp.first+w);
        }else if(tmp.second!=-(~0u>>1)){
            ans=min(ans,mst-tmp.second+w);
        }
    }
    printf("%lld\n",ans);
    //for(;;);
    return 0;
}
