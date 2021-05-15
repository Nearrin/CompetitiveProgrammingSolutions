#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue> 
#define sf scanf
#define pf printf
#define ps for(;;)
#define pb push_back
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int n,m;vector<int>to[500010];
vector<long long>we[500010];
int vi[500010];long long f[500010];
long long p;
long long a[1200010];int as;
void dfs(int u){
    //pf("[%d]",u);
    vi[u]=1;
    if(u==n)p=f[u];
    lp(i,0,int(to[u].size()-1)){
        int v=to[u][i];long long w=we[u][i];
        if(!vi[v]){
            vi[v]=1;
            f[v]=(f[u]^w);
            dfs(v);
        }else{
            //pf("[%d,%d,%lld,%lld,%lld]\n",u,v,f[u],f[v],w);
            a[++as]=(f[u]^f[v]^w);
        }
    }
}
int main(){
    sf("%d%d",&n,&m);
    lp(i,1,m){
        int a,b;long long c;
        sf("%d%d%lld",&a,&b,&c);
        to[a].pb(b);we[a].pb(c);
        to[b].pb(a);we[b].pb(c);
    }
    dfs(1);
    //lp(i,1,as)pf("[%lld]",a[i]);
    int l=0;
    for(int i=63;i>=0;--i){
        int j;
        for(j=l+1;j<=as;++j)if((a[j]>>i)&1)break;
        if(j<=as){
            swap(a[j],a[++l]);
            lp(k,1,as)if(k!=l&&((a[k]>>i)&1))a[k]^=a[l];
        }
    } 
    lp(i,1,l){
        int j=63;while(!((a[i]>>j)&1))--j;
        if(!((p>>j)&1))p^=a[i];
    }
    pf("%lld\n",p);
    //ps;
    return 0; 
} 
