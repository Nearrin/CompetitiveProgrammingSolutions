#include<cstdio>
#include<algorithm>
#include<vector>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int n;
vector<int>to[80010];
int bg[80010],ed[80010],tim;
void dfs_tree(int u,int p){
    bg[u]=++tim;
    lp(i,0,int(to[u].size()-1))
        if(to[u][i]!=p)dfs_tree(to[u][i],u);
    ed[u]=tim;
}
void init_tree(){
    lp(i,1,n-1){
        int u,v;
        sf("%d%d",&u,&v);
        to[u].push_back(v);
        to[v].push_back(u);
    }
}
struct query{
    int tp;//1:add 2:del 3:ask
    int u,a;
    int v,k,now,whe;
}qs[240010];int qz;
int ans[80010],as;
void init(){
    static int val[80010];
    int q;sf("%d%d",&n,&q);
    lp(i,1,n){
        sf("%d",&val[i]);
        ++qz;qs[qz].tp=1;
        qs[qz].u=i;qs[qz].a=val[i];
    }
    init_tree();
    lp(i,1,q){
        int k,u,v;sf("%d%d%d",&k,&u,&v);
        if(k==0){
            ++qz;qs[qz].tp=2;qs[qz].u=u;qs[qz].a=val[u];
            ++qz;qs[qz].tp=1;qs[qz].u=u;qs[qz].a=v;
            val[u]=v;
        }else{
            ++qz;qs[qz].tp=3;
            qs[qz].u=u,qs[qz].v=v,qs[qz].k=k;
            qs[qz].now=0,qs[qz].whe=++as;
        }
    }
}
int up[80010][19],dp[80010];
void build_lca(int u,int p){
    up[u][0]=p;dp[u]=dp[p]+1;
    lp(i,1,18)up[u][i]=up[up[u][i-1]][i-1];
    lp(i,0,int(to[u].size()-1))
        if(to[u][i]!=p)build_lca(to[u][i],u);
}
int lca(int x,int y){
    if(dp[x]<dp[y])swap(x,y);
    lp(i,0,18)if(((dp[x]-dp[y])>>i)&1)x=up[x][i];
    if(x==y)return x;
    for(int i=18;i>=0;--i){
        if(up[x][i]!=up[y][i])
            x=up[x][i],y=up[y][i];
    }
    return up[x][0];
}
int dis(int x,int y){
    int z=lca(x,y);
    int t=dp[x]+dp[y]-dp[z];
    if(z!=1)t-=dp[up[z][0]];
    return t;
}
void print(){
    lp(i,1,as){
        if(ans[i]!=-1)
            pf("%d\n",ans[i]);
        else
            pf("invalid request!\n");
    }
}
int db[80010];
void bit_add(int i,int d){
    for(;i<=n;i+=i&-i)db[i]+=d;
}
int bit_ask(int i){
    int r=0;
    for(;i;i-=i&-i)r+=db[i];
    return r;
}
void add(int u,int d){
    bit_add(bg[u],d);
    bit_add(ed[u]+1,-d);
}
int ask(int u,int v){
    int w=lca(u,v);
    int r=bit_ask(bg[u])+bit_ask(bg[v])-bit_ask(bg[w]);
    if(w!=1)r-=bit_ask(bg[up[w][0]]);
    return r;
}
void solve(int ql,int qr,int vl,int vr){
    if(ql>qr)return;
    if(vl==vr){
        lp(i,ql,qr)if(qs[i].tp==3){
            if(dis(qs[i].u,qs[i].v)>=qs[i].k)
                ans[qs[i].whe]=vl;
            else
                ans[qs[i].whe]=-1;
        }
    }else{
        int vm=vl+(vr-vl)/2;
        static int delt[240010];
        lp(i,ql,qr){
            if(qs[i].tp==1&&qs[i].a>vm){
                add(qs[i].u,1);
            }else if(qs[i].tp==2&&qs[i].a>vm){
                add(qs[i].u,-1);
            }else if(qs[i].tp==3)delt[i]=ask(qs[i].u,qs[i].v);
        }
        lp(i,ql,qr){
            if(qs[i].tp==1&&qs[i].a>vm){
                add(qs[i].u,-1);
            }else if(qs[i].tp==2&&qs[i].a>vm){
                add(qs[i].u,1);
            }
        }
        static query lq[240010],rq[240010];int lqs=0,rqs=0;
        lp(i,ql,qr){
            if(qs[i].tp==3){
                if(qs[i].now+delt[i]<=qs[i].k-1){
                    qs[i].now+=delt[i];
                    lq[++lqs]=qs[i];
                }else rq[++rqs]=qs[i];
            }else{
                if(qs[i].a<=vm)
                    lq[++lqs]=qs[i];
                else
                    rq[++rqs]=qs[i];
            }
        }
        lp(i,1,lqs)qs[ql+i-1]=lq[i];
        lp(i,1,rqs)qs[ql+lqs+i-1]=rq[i];
        solve(ql,ql+lqs-1,vl,vm);
        solve(ql+lqs,qr,vm+1,vr);
    }
}
int main(){
    init();
    dfs_tree(1,0);
    build_lca(1,0);
    solve(1,qz,0,100000010);
    print();
    //ps;
    return 0;
}
