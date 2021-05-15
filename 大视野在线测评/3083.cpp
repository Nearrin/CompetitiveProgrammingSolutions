#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define pb push_back
#define mp make_pair
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
#define vp(i,v) for(int i=0;i<v.size();++i)
#define wp(i,v) for(int i=int(v.size()-1);i>=0;--i)
using namespace std;
typedef long long ll;
#include<queue>
#include<stack>
const int INF=~0u>>1;
vector<int>to[100010];int rt,n,q,we[100010];
int dp[100010],sz[100010],ch[100010],pr[100010];
int bg[100010],ed[100010],val[100010],nw,pos[100010],nw2;
int top[100010];vector<int>chd[100010];
inline void dfs1(int uu){
    stack<int>stk;stk.push(uu);
    vector<int>tmp;
    while(!stk.empty()){
        int u=stk.top();stk.pop();
        tmp.pb(u);
        vp(i,to[u]){
        int v=to[u][i];
        if(v!=pr[u]){
            dp[v]=dp[u]+1;
            pr[v]=u;chd[u].pb(v);
            stk.push(v);
        }
        }
    }
    wp(i,tmp){
        int u=tmp[i]; sz[u]=1;
        vp(j,chd[u]){
            int v=chd[u][j];
           
            sz[u]+=sz[v];
            if(sz[v]>sz[ch[u]])ch[u]=v;
        }
    }
}
inline void dfs2(int uu,int aa){
    stack<int>st1,st2,st3;st1.push(uu);st2.push(aa);st3.push(0);
    while(!st1.empty()){
        int u=st1.top();st1.pop();
        int a=st2.top();st2.pop();
        int y=st3.top();st3.pop();
        if(y==0){
            st1.push(u);st2.push(a);st3.push(1);
            pos[u]=++nw2;val[nw2]=we[u];top[u]=a;
            bg[u]=++nw;
            vp(i,to[u]){
                    int v=to[u][i];
                    if(v!=pr[u]&&v!=ch[u]){
            st1.push(v);st2.push(v);st3.push(0);
                    }
                }
            if(ch[u]){
                st1.push(ch[u]);st2.push(a);st3.push(0);
            }
        }else ed[u]=nw;
        
    }
}
namespace seg{
    int sam[100010*4],mii[100010*4];
    inline void down(int x,int l,int r){
        if(sam[x]!=-INF){
            mii[x]=sam[x];
            if(l!=r){
                sam[x*2]=sam[x];
                sam[x*2+1]=sam[x];
            }
            sam[x]=-INF;
        }
    }
    inline void upda(int x,int l,int r){
        int m=(l+r)/2;
        down(x*2,l,m);down(x*2+1,m+1,r);
        mii[x]=min(mii[x*2],mii[x*2+1]);
    }
    inline void build(int x,int l,int r){
        sam[x]=-INF;
        if(l==r)mii[x]=val[l];
        else{
            int m=(l+r)/2;
            build(x*2,l,m);
            build(x*2+1,m+1,r);
            upda(x,l,r);
        }
    }
    inline void makesam(int x,int l,int r,int b,int e,int v){
        down(x,l,r);
        if(b<=l&&e>=r)sam[x]=v;
        else{
            int m=(l+r)/2;
            if(b<=m)makesam(x*2,l,m,b,e,v);
            if(e>m)makesam(x*2+1,m+1,r,b,e,v);
            upda(x,l,r);
        }
    }
    inline int ask(int x,int l,int r,int b,int e){
        down(x,l,r);
        if(b<=l&&e>=r)return mii[x];
        else{
            int m=(l+r)/2,ret=INF;
            if(b<=m)ret=min(ret,ask(x*2,l,m,b,e));
            if(e>m)ret=min(ret,ask(x*2+1,m+1,r,b,e));
            return ret;
        }
    }
}
void modify(int u,int v,int w){
    while(top[u]!=top[v]){
        if(dp[top[u]]<dp[top[v]])swap(u,v);
        seg::makesam(1,1,n,pos[top[u]],pos[u],w);
        u=pr[top[u]];
    }
    if(dp[u]<dp[v])swap(u,v);
    seg::makesam(1,1,n,pos[v],pos[u],w);
}
int askmin(int u){
    if(bg[rt]<=bg[u]&&ed[rt]>=ed[u]){
        if(bg[rt]!=bg[u]||ed[rt]!=ed[u])
            return seg::ask(1,1,n,bg[u],ed[u]);
        else return seg::ask(1,1,n,1,n);
    }else if(bg[rt]>=bg[u]&&ed[rt]<=ed[u]){
        int lft=0,rght=int(chd[u].size()-1);
        int v;
        if(pos[rt]>=bg[chd[u].back()])v=chd[u].back();
        else{
            while(lft+1<rght){
                int mid=(lft+rght)/2;
                if(pos[rt]>=bg[chd[u][mid]])
                    lft=mid;
                else
                    rght=mid;
            }
            v=chd[u][lft];
        }
        int ret=INF;
        if(bg[v]!=1)ret=min(ret,seg::ask(1,1,n,1,bg[v]-1));
        if(ed[v]!=n)ret=min(ret,seg::ask(1,1,n,ed[v]+1,n));
        return ret;
    }else return seg::ask(1,1,n,bg[u],ed[u]);
}
bool cpm(int a,int b){
    return bg[a]<bg[b];
}
int main(){
    sf("%d%d",&n,&q);
    lp(i,1,n-1){
        int u,v;sf("%d%d",&u,&v);
        to[u].pb(v);to[v].pb(u);
    }
    lp(i,1,n)sf("%d",&we[i]);sf("%d",&rt);
    dfs1(1);
    dfs2(1,1);
    //lp(i,1,n)pf("[%d,%d,%d,%d]\n",bg[i],ed[i],sz[i],pr[i]);
    //lp(i,1,n)pf("[%d]\n",pos[i]);
    //lp(i,1,n)pf("[%d]\n",val[i]);
    //lp(i,1,n)pf("[%d,%d,%d]\n",pos[i],bg[i],ed[i]);
    //lp(i,1,n)pf("[%d] ",sz[i]);
    seg::build(1,1,n);
    lp(i,1,n)sort(chd[i].begin(),chd[i].end(),cpm);
    lp(i,1,q){
        int opt;sf("%d",&opt);
        if(opt==1){
            sf("%d",&rt);
        }else if(opt==2){
            int u,v,w;sf("%d%d%d",&u,&v,&w);
            modify(u,v,w);
        }else{
            int x;sf("%d",&x);
            pf("%d\n",askmin(x));
        }
    }
    //ps;
    return 0;
}
/*
4 3
2 1
3 2
4 1
2 2 3 1 
1
1 4
3 2
2 4 1
*/
