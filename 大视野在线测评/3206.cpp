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
ll wei[100010];int n;
struct edge1{
    edge1(){sf("%d%d%d",&u,&v,&w);}
    int u,v,w;
};
bool operator<(edge1 a,edge1 b){
    return a.w<b.w;
}
struct edge2{
    edge2(){sf("%d%d",&u,&v);}
    int u,v;
};
vector<edge1>eg1;
vector<edge2>eg2;
void init(){
    int m,k;sf("%d%d%d",&n,&m,&k);
    lp(i,1,m)eg1.push_back(edge1());
    lp(i,1,k)eg2.push_back(edge2());
    lp(i,1,n)sf("%lld",&wei[i]);
}
int pr[100010];
int fd(int x){return x==pr[x]?x:pr[x]=fd(pr[x]);}
void contract(){
    lp(i,1,n)pr[i]=i;
    lp(i,0,int(eg2.size()-1)){
        int u=eg2[i].u,v=eg2[i].v;
        if(fd(u)!=fd(v))pr[fd(u)]=v;
    }
    sort(eg1.begin(),eg1.end());
    vector<edge1>tmp;
    lp(i,0,int(eg1.size()-1)){
        int u=eg1[i].u,v=eg1[i].v;
        if(fd(u)!=fd(v)){
            pr[fd(u)]=v;
            tmp.push_back(eg1[i]);
        }
    }
    lp(i,1,n)pr[i]=i;
    lp(i,0,int(tmp.size()-1)){
        int u=tmp[i].u,v=tmp[i].v;
        pr[fd(u)]=v;
    }
    static int id[100010];static ll tw[100010];
    int nw=1;id[fd(1)]=1;
    lp(i,1,n)if(pr[i]==i&&!id[i])id[i]=++nw;
    lp(i,1,n)tw[id[fd(i)]]+=wei[i];
    lp(i,0,int(eg1.size()-1)){
        int&u=eg1[i].u,&v=eg1[i].v;
        u=id[fd(u)];v=id[fd(v)];
    }
    lp(i,0,int(eg2.size()-1)){
        int&u=eg2[i].u,&v=eg2[i].v;
        u=id[fd(u)];v=id[fd(v)];
    }
    n=nw;
    lp(i,1,n)wei[i]=tw[i];
    //print();
}
void reduct(){
    lp(i,1,n)pr[i]=i;
    vector<edge1>tmp;
    lp(i,0,int(eg1.size()-1)){
        int u=eg1[i].u,v=eg1[i].v;
        if(fd(u)!=fd(v)){
            pr[fd(u)]=v;
            tmp.push_back(eg1[i]);
        }
    }
    eg1=tmp;
    //print();
}
struct edge3{
    edge3(int a,int b,int c):
        v(a),t(b),w(c){}
    int v,t,w;
};
vector<edge3>to[100010];
bool upda(int u,int p,int v,int w){
    if(u==v)return true;
    lp(i,0,int(to[u].size()-1)){
        if(to[u][i].v!=p){
            if(upda(to[u][i].v,u,v,w)){
                if(to[u][i].t==2)
                    to[u][i].w=min(to[u][i].w,w);
                return true;
            }
        }
    }
    return false;
}
ll sum[100010];
ll dp(int u,int p){
    ll r=0;
    sum[u]=wei[u];
    lp(i,0,int(to[u].size()-1)){
        if(to[u][i].v!=p){
            r+=dp(to[u][i].v,u);
            sum[u]+=sum[to[u][i].v];
            if(to[u][i].t==2)
                r+=to[u][i].w*sum[to[u][i].v];
        }
    }
    return r;
}
void solve(){
    ll ans=0;
    lp(s,0,(1<<eg2.size())-1){
        lp(i,1,n)to[i].clear();
        lp(i,1,n)pr[i]=i;
        lp(i,0,int(eg2.size()-1))if((s>>i)&1){
            int u=eg2[i].u,v=eg2[i].v;
            if(fd(u)!=fd(v)){
                pr[fd(u)]=v;
                to[u].push_back(edge3(v,2,~0u>>1));
                to[v].push_back(edge3(u,2,~0u>>1));
            }
        }
        lp(i,0,int(eg1.size()-1)){
            int u=eg1[i].u,v=eg1[i].v,w=eg1[i].w;
            if(fd(u)!=fd(v)){
                pr[fd(u)]=v;
                to[u].push_back(edge3(v,1,~0u>>1));
                to[v].push_back(edge3(u,1,~0u>>1));
            }else{
                upda(u,0,v,w);
                upda(v,0,u,w);
            }
        }
        ans=max(ans,dp(1,0));
    }
    pf("%lld\n",ans);
}
int main(){
    init();
    contract();
    reduct();
    solve();
    //ps;
    return 0;
}
