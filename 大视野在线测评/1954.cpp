#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define pb push_back
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
int n;vector<int>to[100010],we[100010];int dis[100010];
namespace trie{
    struct node{node(){ch[0]=ch[1]=0;}node*ch[2];}*rt;
    inline void del(node*&x){if(x){lp(i,0,1)del(x->ch[i]);delete x;x=0;}}
    inline void ins(int v){
        node*u=rt;
        rp(i,30,0){
            if(!u->ch[(v>>i)&1])
                u->ch[(v>>i)&1]=new node;
            u=u->ch[(v>>i)&1];
        }
    }
    inline int ask(int v){
        node*u=rt;int ret=0;
        rp(i,30,0){
            if(!u->ch[((v>>i)&1)^1])
                u=u->ch[(v>>i)&1];
            else
                u=u->ch[((v>>i)&1)^1],ret+=(1<<i);
        }
        return ret;
    }
}
int main(){
    while(sf("%d",&n)!=EOF){
        lp(i,1,n)to[i].clear(),we[i].clear();
        lp(i,1,n-1){
            int u,v,w;sf("%d%d%d",&u,&v,&w);
            to[u].pb(v);we[u].pb(w);
            to[v].pb(u);we[v].pb(w);
        }
        lp(i,1,n)dis[i]=-1;dis[1]=0;
        queue<int>qu;qu.push(1);
        while(!qu.empty()){
            int u=qu.front();qu.pop();
            lp(i,0,int(to[u].size()-1)){
                int v=to[u][i];
                if(dis[v]==-1){
                    dis[v]=(dis[u]^we[u][i]);
                    qu.push(v);
                }
            }
        }
        int ans=0;
        trie::rt=new trie::node();
        lp(i,1,n)trie::ins(dis[i]);
        lp(i,1,n)ans=max(ans,trie::ask(dis[i]));
        pf("%d\n",ans);
        trie::del(trie::rt); 
    }
    //ps;
    return 0;
} 
