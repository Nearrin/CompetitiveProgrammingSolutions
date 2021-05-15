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
#include<stack>
namespace lct{
    struct node{
        node(){
            ch[0]=ch[1]=pr=0;cnt=1;
        }
        node*ch[2],*pr;int cnt;
    }ns[500010];
    void update(node*x){
        x->cnt=1;
        lp(i,0,1)if(x->ch[i])x->cnt+=x->ch[i]->cnt;
    }
    int direct(node*x){
        if(!x->pr)return 2;
        else if(x==x->pr->ch[0])return 0;
        else if(x==x->pr->ch[1])return 1;
        else return 2;
    }
    void setchd(node*x,node*y,int d){
        x->ch[d]=y;
        if(y)y->pr=x;
        update(x);
    }
    void rotate(node*x){
        node*y=x->pr,*z=y->pr;
        int d1=direct(x),d2=direct(y);
        setchd(y,x->ch[!d1],d1);
        setchd(x,y,!d1);
        if(d2<2)setchd(z,x,d2);else x->pr=z;
    }
    void splay(node*x){
        while(direct(x)<2){
            node*y=x->pr;
            if(direct(y)>1)rotate(x);
            else if(direct(x)==direct(y))rotate(y),rotate(x);
            else rotate(x),rotate(x);
        }
    }
    node*access(node*x){
        node*y=0;
        while(x){
            splay(x);
            setchd(x,y,1);
            y=x;x=x->pr;
        }
        return y;
    }
    node*lca(node*x,node*y){
        access(x);
        return access(y);
    }
    int dis(node*x,node*y){
        int r=0;
        access(x);
        node*w=access(y);
        splay(w);
        splay(x);
        if(x!=w)r+=x->cnt;
        if(w->ch[1])r+=w->ch[1]->cnt;
        return r+1;
    }
}
int n,q,prt[500010];vector<int>to[500010];
int dis(int u,int v){
    return lct::dis(lct::ns+u,lct::ns+v)-1;
}
int lca(int u,int v){
    return lct::lca(lct::ns+u,lct::ns+v)-lct::ns;
} 
int main(){
    sf("%d%d",&n,&q);
    lp(i,2,n){
        int u,v;sf("%d%d",&u,&v);
        to[u].pb(v);
        to[v].pb(u);
    }
    stack<int>stk;stk.push(1);
    while(!stk.empty()){
        int u=stk.top();stk.pop();
        vp(i,to[u]){
            int v=to[u][i];
            if(v!=prt[u]){
                prt[v]=u;
                lct::ns[v].pr=lct::ns+u;
                stk.push(v);
                //pf("[%d,%d]\n",v,u);
            }
        }
    }
    //lp(i,1,n)lp(j,1,n)pf("[%d,%d,%d]\n",i,j,lct::lca(lct::ns+i,lct::ns+j)-lct::ns);
    //lp(i,1,n)lp(j,1,n)pf("[%d,%d,%d]\n",i,j,lct::dis(lct::ns+i,lct::ns+j));
    lp(i,1,q){
        int nowid=-1,nowans=~0u>>1;
        int u,v,w;sf("%d%d%d",&u,&v,&w);
        int tid,tans;
        tid=lca(u,v);tans=dis(tid,u)+dis(tid,v)+dis(tid,w);
        if(tans<nowans)nowans=tans,nowid=tid;
        tid=lca(u,w);tans=dis(tid,u)+dis(tid,v)+dis(tid,w);
        if(tans<nowans)nowans=tans,nowid=tid;
        tid=lca(v,w);tans=dis(tid,u)+dis(tid,v)+dis(tid,w);
        if(tans<nowans)nowans=tans,nowid=tid;
        pf("%d %d\n",nowid,nowans);
    }
    //ps;
    return 0;
}
