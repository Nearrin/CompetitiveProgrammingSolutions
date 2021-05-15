#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
namespace lct{
    const int nmx=100000;
    int pr[nmx+10],ch[nmx+10][2];
    int cnt[nmx+10],col[nmx+10],lcol[nmx+10],rcol[nmx+10],tag[nmx+10];
    inline int tp(int u){return u!=ch[pr[u]][0];}
    inline void dw(int u){
        if(tag[u]!=-1){
            cnt[u]=1;col[u]=lcol[u]=rcol[u]=tag[u];
            tag[ch[u][0]]=tag[u];
            tag[ch[u][1]]=tag[u];tag[u]=-1;
        }
    }
   inline void up(int u){
        cnt[u]=1;lcol[u]=rcol[u]=col[u];
        if(ch[u][0]){
            dw(ch[u][0]);
            cnt[u]+=cnt[ch[u][0]]-(lcol[u]==rcol[ch[u][0]]);
            lcol[u]=lcol[ch[u][0]];
        }
        if(ch[u][1]){
            dw(ch[u][1]);
            cnt[u]+=cnt[ch[u][1]]-(rcol[u]==lcol[ch[u][1]]);
            rcol[u]=rcol[ch[u][1]];
        }
    }
    inline void prt(){
        lp(i,1,6)pf("[%d,%d,%d,%d,%d,%d]\n",i,pr[i],ch[i][0],ch[i][1],tag[i],cnt[i]);
    }
    inline void st(int u,int v,int d){
        ch[u][d]=v;pr[v]=u;up(u);
    }
   inline  void rot(int u){
        int v=pr[u],w=pr[v],a=tp(u),b=tp(v);
        st(v,ch[u][!a],a);
        st(u,v,!a);
        if(w>0)st(w,u,b);else pr[u]=w;
    }
   inline  void dfs(int u){
        if(u>0)dfs(pr[u]),dw(u);
    }
    inline void spl(int u){
        dfs(u);
        while(pr[u]>0){
            if(pr[pr[u]]<=0)rot(u);
            else if(tp(u)==tp(pr[u]))rot(pr[u]),rot(u);
            else rot(u),rot(u);
        }
    }
    inline int acc(int u){
        int v=0;
        while(u){
            spl(u);
            pr[ch[u][1]]=-u;
            st(u,v,1);
            v=u;u=-pr[u];
        }
        return v;
    }
   inline  int ask(int u,int v){
        acc(u);int w=acc(v);
        spl(w);spl(u);
        int r=1;
        if(u!=w)r+=cnt[u]-(lcol[u]==col[w]);
        if(ch[w][1])r+=cnt[ch[w][1]]-(lcol[ch[w][1]]==col[w]);
        return r;
    }
   inline  void mod(int u,int v,int c){
        acc(u);int w=acc(v);
        spl(w);spl(u);
        col[w]=lcol[w]=rcol[w]=c;
        if(u!=w)tag[u]=c;
        if(ch[w][1])tag[ch[w][1]]=c;
    }
}
vector<int>to[100010];
int in[100010];
inline void bfs(){
    queue<int>qu;qu.push(1);in[1]=1;
    while(!qu.empty()){
        int u=qu.front();qu.pop();
        lp(i,0,int(to[u].size()-1))
            if(!in[to[u][i]]){
                lct::pr[to[u][i]]=-u;
                in[to[u][i]]=1;
                qu.push(to[u][i]);
            }
    }
}
int main(){
    int n,m;sf("%d%d",&n,&m);
    lp(i,1,n){
        sf("%d",&lct::col[i]);
        lct::cnt[i]=1;lct::tag[i]=-1;
        lct::lcol[i]=lct::rcol[i]=lct::col[i];
    }
    lp(i,1,n-1){
        int u,v;sf("%d%d",&u,&v);
        to[u].push_back(v);
        to[v].push_back(u);
    }
    bfs();
    lp(i,1,m){
        char op[11];sf("%s",op);
        if(op[0]=='Q'){
            int a,b;sf("%d%d",&a,&b);
            pf("%d\n",lct::ask(a,b));
        }else{
            int a,b,c;sf("%d%d%d",&a,&b,&c);
            lct::mod(a,b,c);
        }
    }
    //ps;
    return 0;
}
