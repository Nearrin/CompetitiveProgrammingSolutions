#include<cstdio>
#include<vector>
#include<algorithm>
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
using namespace std;
typedef long long ll;
ll big=1000000000000000000ll;
struct edge{int v;ll c;};
vector<edge>eg;vector<int>to[1000010];
int dis[1000010],gap[1000010],vcnt;
void add(int u,int v,ll c){edge e;e.v=v;e.c=c;to[u].pb(eg.size());eg.pb(e);}
ll dfs(int u,ll f){
    if(u==vcnt)return f;
    ll g=f;
    lp(i,0,int(to[u].size()-1)){
        edge&e=eg[to[u][i]],&ev=eg[to[u][i]^1];
        if(e.c&&dis[e.v]+1==dis[u]){
            ll t=dfs(e.v,min(g,e.c));
            e.c-=t,ev.c+=t,g-=t;
            if(!g||dis[1]==vcnt)return f-g;
        }
    }
    if(!--gap[dis[u]])dis[1]=vcnt;
    ++gap[++dis[u]];
    return f-g;
}
namespace lisa{
    vector<int>data;
    void add(int a){data.pb(a);}
    void build(){
        sort(data.begin(),data.end());
        data.erase(unique(data.begin(),data.end()),data.end());
    }
    int ask(int x){
        return lower_bound(data.begin(),data.end(),x)-data.begin()+1;
    }
}int nw;
namespace seg{
    struct node{
        node(int a,int b){l=a;r=b;ch[0]=ch[1]=0;idx=++nw;lf=0;}
        node*ch[2];int l,r,idx,lf;
    };
    node*build(int l,int r){
        node*ret=new node(l,r);
        if(l!=r){
            int m=(l+r)/2;
            ret->ch[0]=build(l,m);
            add(ret->idx,ret->ch[0]->idx,big);
            add(ret->ch[0]->idx,ret->idx,0);
            ret->ch[1]=build(m+1,r);
            add(ret->idx,ret->ch[1]->idx,big);
            add(ret->ch[1]->idx,ret->idx,0);
        }
        return ret;
    }
    void link(node*x,int b,int e,int y){
        if(b<=x->l&&e>=x->r){
            add(y,x->idx,big);
            add(x->idx,y,0);
        }else{
            if(b<=x->ch[0]->r)link(x->ch[0],b,e,y);
            if(e>x->ch[0]->r)link(x->ch[1],b,e,y);
        }
    }
    node*ins(node*x,int p,int y){
        node*ret=new node(x->l,x->r);
        if(x->l==x->r){
            add(ret->idx,x->idx,big),add(x->idx,ret->idx,0);
            ret->lf=y;add(ret->idx,y,big),add(y,ret->idx,0);
        }else{
            if(p<=x->ch[0]->r){
                ret->ch[0]=ins(x->ch[0],p,y);
                ret->ch[1]=x->ch[1];
            }else{
                ret->ch[1]=ins(x->ch[1],p,y);
                ret->ch[0]=x->ch[0];
            }
            add(ret->idx,ret->ch[0]->idx,big);
            add(ret->ch[0]->idx,ret->idx,0);
            add(ret->idx,ret->ch[1]->idx,big);
            add(ret->ch[1]->idx,ret->idx,0);
        }
        return ret;
    }
}
int main(){
    static int n,a[5010],b[5010],w[5010],l[5010],r[5010],p[5010];
    static int ct[5010],tk[5010],st,et;sf("%d",&n);ll ans=0;
    lp(i,1,n)sf("%d%d%d%d%d%d",&a[i],&b[i],&w[i],&l[i],&r[i],&p[i]),ans+=b[i]+w[i];
    st=++nw;lp(i,1,n)ct[i]=++nw,tk[i]=++nw,lisa::add(a[i]),lisa::add(l[i]),lisa::add(r[i]);
    lisa::build();lp(i,1,n)a[i]=lisa::ask(a[i]),l[i]=lisa::ask(l[i]),r[i]=lisa::ask(r[i]);
    seg::node*rt=seg::build(1,lisa::data.size());
    lp(i,1,n)link(rt,l[i],r[i],tk[i]),rt=ins(rt,a[i],ct[i]);vcnt=et=++nw;
    lp(i,1,n)add(st,ct[i],b[i]),add(ct[i],st,0),add(ct[i],et,w[i]),
        add(et,ct[i],0),add(ct[i],tk[i],p[i]),add(tk[i],ct[i],0);
    gap[0]=vcnt;while(dis[1]<vcnt)ans-=dfs(1,big);pf("%lld\n",ans);
    return 0;
}
/*
10
0 1 7 3 9 2
7 4 0 9 10 5
1 0 4 2 10 2
7 9 1 5 7 2
6 3 5 3 6 2
6 6 4 1 8 1
6 1 6 0 6 5
2 2 5 0 9 3
5 1 3 0 2 5
5 6 7 1 1 2
*/
