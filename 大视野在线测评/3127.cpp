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
struct edge{
    edge(edge*a,int b,int c):
        nxt(a),v(b),w(c){}
    edge*nxt;int v,w;
}*bg[100010];
void add(int u,int v,int w){
    bg[u]=new edge(bg[u],v,w);
    bg[v]=new edge(bg[v],u,w);
}
int siz[100010],mxz[100010],nds[100010],edn[100010],ns;
void dfs(int u,int p){
    nds[++ns]=u;mxz[u]=0;siz[u]=1;
    for(edge*e=bg[u];e;e=e->nxt){
        if(e->v!=p){
            dfs(e->v,u);
            siz[u]+=siz[e->v];
            mxz[u]=max(mxz[u],siz[e->v]);
        }
    }
    edn[u]=ns;
}
int psum[100010];
ll calc1(int u,int p,int sum,int flag){
    ll ret=0;psum[u]=sum;
    if(flag&&!sum)++ret;
    for(edge*e=bg[u];e;e=e->nxt){
        if(e->v!=p){
            if(flag||(sum==0&&p!=0))
                ret+=calc1(e->v,u,sum+e->w,1);
            else
                ret+=calc1(e->v,u,sum+e->w,0);
        }
    }
    return ret;
}
ll table[200010];
int bad[200010];
void calcbad(int u,int p){
    if(table[100001+psum[u]])bad[u]=0;
    else bad[u]=1;
    ++table[100001+psum[u]];
    for(edge*e=bg[u];e;e=e->nxt){
        if(e->v!=p){
            calcbad(e->v,u);
        }
    }
    --table[100001+psum[u]];
}
ll treedc(int u){
    ll ret=0;ns=0;dfs(u,0);
    if(ns<3)return 0;
    lp(i,1,ns)mxz[nds[i]]=max(mxz[nds[i]],ns-siz[nds[i]]);
    lp(i,1,ns)if(mxz[nds[i]]<mxz[u])u=nds[i];
    ns=0;dfs(u,0);
    edge*mid=bg[u];
    for(int i=siz[mid->v];(i+=siz[mid->nxt->v])<ns/2;mid=mid->nxt);
    int *pl=nds+2,*pm=nds+edn[mid->v],*pr=nds+ns;
    calc1(u,0,0,0);
    for(int*i=pl;i<=pm;++i)++table[100001+psum[*i]];
    for(int*i=pm+1;i<=pr;++i)ret+=table[100001-psum[*i]];
    for(int*i=pl;i<=pm;++i)--table[100001+psum[*i]];
    calcbad(u,0);
    for(int*i=pl;i<=pm;++i)if(bad[*i])++table[100001+psum[*i]];
    for(int*i=pm+1;i<=pr;++i)if(bad[*i])ret-=table[100001-psum[*i]];
    for(int*i=pl;i<=pm;++i)if(bad[*i])--table[100001+psum[*i]];
    edge*tmp=mid->nxt;mid->nxt=0;
    ret+=treedc(u);bg[u]=tmp;ret+=treedc(u);
    return ret;
}
int main(){
    int n;sf("%d",&n);
    lp(i,2,n){
        int u,v,w;
        sf("%d%d%d",&u,&v,&w);
        add(u,v,w*2-1);
    }
    pf("%lld\n",treedc(1));
    return 0;
}
