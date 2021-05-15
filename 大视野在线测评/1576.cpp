#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#define sf scanf
#define pf printf
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
vector<int> to[100010],we[100010];
int n,m,di[100010];
void build_graph(){
    sf("%d%d",&n,&m);
    lp(i,1,m){
        int u,v,w;
        sf("%d%d%d",&u,&v,&w);
        to[u].push_back(v);we[u].push_back(w);
        to[v].push_back(u);we[v].push_back(w);
    }
}
struct dnode{dnode(int a,int b):x(a),d(b){}int x,d;};
struct cmp{bool operator()(const dnode&a,const dnode&b){return a.d>b.d;}};
void dijkstra(){
    di[1]=0;fill(di+2,di+n+1,~0u>>1);
    priority_queue<dnode,vector<dnode>,cmp> qu;
    qu.push(dnode(1,0));
    while(!qu.empty()){
        int u=qu.top().x,d=qu.top().d;qu.pop();
        if(di[u]!=d)continue;
        lp(i,0,int(to[u].size()-1)){
            int v=to[u][i],w=we[u][i];
            if(di[u]+w<di[v]){
                di[v]=di[u]+w;
                qu.push(dnode(v,di[v]));
            }
        }
    }
    //lp(i,1,n)pf("[%d]",di[i]);
}
struct snode{snode(int a,int b):lc(0),rc(0),va(a),de(0),fr(b){}snode*lc,*rc;int va,de,fr;};
void pushdown(snode*x){
    if(x->lc)x->lc->de+=x->de;
    if(x->rc)x->rc->de+=x->de;
    x->va+=x->de;x->de=0;
}
snode*merge(snode*x,snode*y){
    if(!x)return y;
    if(!y)return x;
    pushdown(x);pushdown(y);
    if(x->va>y->va)swap(x,y);
    x->rc=merge(x->rc,y);
    swap(x->lc,x->rc);
    return x;
}
void modify(snode*x,int d){x->de+=d;}
int tmp2[100010];
snode*tmp1[100010];
bool cmp2(int a,int b){return di[a]>di[b];} 
void topsort(){
    lp(i,1,n)tmp2[i]=i;
    sort(tmp2+1,tmp2+n+1,cmp2);
    //lp(i,1,n)pf("[%d]",tmp2[i]);
}
int dbg[100010],ded[100010],dnw;
void makedfs(){
    stack<int> stk;
    stk.push(1);stk.push(1);
    while(!stk.empty()){
        int t=stk.top();stk.pop();
        int u=stk.top();stk.pop();
        if(t==1){
            dbg[u]=++dnw;
            stk.push(u);stk.push(2);
            lp(i,0,int(to[u].size()-1)){
                int v=to[u][i],w=we[u][i];
                if(di[v]==di[u]+w)stk.push(v),stk.push(1);
            }
        }else{
            ded[u]=dnw;
        } 
    }
    //lp(i,1,n)pf("[%d,%d]",dbg[i],ded[i]);
}
int ans[100010];
bool in(int a,int b){return dbg[a]>=dbg[b]&&ded[a]<=ded[b];}
void solve(){
    lp(op,1,n){
        int u=tmp2[op];
        lp(i,0,int(to[u].size()-1)){
            int v=to[u][i],w=we[u][i];
            if(di[v]==di[u]+w){
                if(tmp1[v])tmp1[v]->de+=w;
                tmp1[u]=merge(tmp1[u],tmp1[v]);
            }else if(di[u]!=di[v]+w){
                snode*t=new snode(w+di[v],v);
                tmp1[u]=merge(tmp1[u],t);
            }
        }
        while(tmp1[u]&&in(tmp1[u]->fr,u))tmp1[u]=merge(tmp1[u]->lc,tmp1[u]->rc);
        if(tmp1[u])pushdown(tmp1[u]),ans[u]=tmp1[u]->va;
        else ans[u]=-1;
        //pf("[%d,%d]",u,ans[u]);
    }
}
void print(){lp(i,2,n)pf("%d\n",ans[i]);}
int main(){
    build_graph();
    dijkstra();
    topsort();
    makedfs();
    solve();
    print();//ps;
    return 0;   
}
