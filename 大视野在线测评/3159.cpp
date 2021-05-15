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
#define wp(i,v) for(int i=int(v.size()-1);i>=0;--i)
using namespace std;
typedef long long ll;
int n,q;
namespace splay{
    struct node{
        inline node(int v){
            val=sum=mx=mi=v;
            rev=del=0;
            ch[0]=ch[1]=pr=0;
            siz=1;
        }
        node*ch[2],*pr;
        int siz,val,mx,mi,rev,del;
        ll sum;
    };
    inline void down(node*x){
        if(x->rev){
            swap(x->ch[0],x->ch[1]);
            lp(i,0,1)if(x->ch[i])x->ch[i]->rev^=1;
            x->rev=0;
        }
        if(x->del){
            x->val+=x->del;
            x->sum+=ll(x->del)*x->siz;
            x->mx+=x->del;
            x->mi+=x->del;
            lp(i,0,1)if(x->ch[i])x->ch[i]->del+=x->del;
            x->del=0;
        }
    }
    inline void update(node*x){
        lp(i,0,1)if(x->ch[i])down(x->ch[i]);
        x->siz=1;
        lp(i,0,1)if(x->ch[i])x->siz+=x->ch[i]->siz;
        x->sum=x->val;
        lp(i,0,1)if(x->ch[i])x->sum+=x->ch[i]->sum;
        x->mx=x->val;
        lp(i,0,1)if(x->ch[i])x->mx=max(x->mx,x->ch[i]->mx);
        x->mi=x->val;
        lp(i,0,1)if(x->ch[i])x->mi=min(x->mi,x->ch[i]->mi);
    }
    inline int direct(node*x){return x!=x->pr->ch[0];}
    inline void setchd(node*x,node*y,int d){x->ch[d]=y;if(y)y->pr=x;update(x);}
    inline void rotate(node*x){
        node*y=x->pr,*z=y->pr;int d1=direct(x),d2;if(z)d2=direct(y);
        setchd(y,x->ch[!d1],d1);
        setchd(x,y,!d1);
        if(z)setchd(z,x,d2);else x->pr=0;
    }
    inline void splay(node*x,node*y){
        while(x->pr!=y)rotate(x);
    }
    inline node*select(node*x,node*y,int k){
        down(x);
        int t=x->ch[0]?x->ch[0]->siz:0;
        if(k<=t)return select(x->ch[0],y,k);
        else if(k==t+1){splay(x,y);return x;}
        else return select(x->ch[1],y,k-(t+1));
    }
    inline void increase(node*&x,int l,int r,int d){
        x=select(x,0,l);select(x,x,r+2);
        x->ch[1]->ch[0]->del+=d;
        update(x->ch[1]);update(x);
    }
    inline void invert(node*&x,int l,int r){
        x=select(x,0,l);select(x,x,r+2);
        x->ch[1]->ch[0]->rev^=1;
    }
    inline ll getsum(node*&x,int l,int r){
        //pf("[%d,%d]\n",l,r);
        x=select(x,0,l);select(x,x,r+2);
        down(x->ch[1]->ch[0]);
        return x->ch[1]->ch[0]->sum;
    }
    inline int getmax(node*&x,int l,int r){
        x=select(x,0,l);select(x,x,r+2);
        down(x->ch[1]->ch[0]);
        return x->ch[1]->ch[0]->mx;
    }
    inline int getmin(node*&x,int l,int r){
        x=select(x,0,l);select(x,x,r+2);
        down(x->ch[1]->ch[0]);
        return x->ch[1]->ch[0]->mi;
    }
    inline node*cut(node*&x,int l,int r){
        x=select(x,0,l);select(x,x,r+2);
        node*t=x->ch[1]->ch[0];x->ch[1]->ch[0]=0;
        update(x->ch[1]);update(x);t->pr=0;
        t=select(t,0,1);setchd(t,new node(0),0);
        t=select(t,0,t->siz);setchd(t,new node(0),1);
        return t;
    }
    inline void link(node*&x,node*y,int p){
        y=select(y,0,2);delete y->ch[0];y->ch[0]=0;update(y);
        y=select(y,0,y->siz-1);delete y->ch[1];y->ch[1]=0;update(y);
        x=select(x,0,p+1);select(x,x,p+2);
        setchd(x->ch[1],y,0);
        update(x);
    }
    inline node*create(){node*t1=new node(0);setchd(t1,new node(0),1);return t1;}
    inline node*build(int*a,int l,int r){
        int m=(l+r)/2;
        node*ret=new node(a[m]);
        if(l!=m)setchd(ret,build(a,l,m-1),0);
        if(m!=r)setchd(ret,build(a,m+1,r),1);
        return ret;
    }
}
namespace chain{
    vector<int>to[50010];
    int tmp[50010];
    splay::node*tree;
    int dep[50010],siz[50010],chd[50010],prt[50010];
    inline void dfs1(int u,int p){
        dep[u]=dep[p]+1;
        siz[u]=1;prt[u]=p;
        vp(i,to[u]){
            int v=to[u][i];
            if(v!=p){
                dfs1(v,u);
                siz[u]+=siz[v];
                if(siz[v]>siz[chd[u]])chd[u]=v;
            }
        }
    }
    int top[50010],pos[50010],nw;
    inline void dfs2(int u,int a){
        pos[u]=++nw;top[u]=a;
        if(chd[u])dfs2(chd[u],a);
        vp(i,to[u]){
            int v=to[u][i];
            if(v!=prt[u]&&v!=chd[u])
                dfs2(v,v);
        }
    }
    inline void build(){
        int r;sf("%d%d%d",&n,&q,&r);
        tree=splay::build(tmp,0,n+1);
        //pf("[%d]",tree->siz);
        lp(i,1,n-1){
            int u,v;sf("%d%d",&u,&v);
            to[u].pb(v);
            to[v].pb(u);
        }
        dfs1(r,0);
        dfs2(r,r);
        //lp(i,1,n)pf("[%d,%d,%d,%d]\n",pos[i],siz[i],prt[i],top[i]);ps;
    }
    inline void increase(int u,int v,int d){
        if(dep[u]>dep[v])swap(u,v);
        while(top[u]!=top[v])
            splay::increase(tree,pos[top[v]],pos[v],d),v=prt[top[v]];
        splay::increase(tree,pos[u],pos[v],d);
    }
    inline ll getsum(int u,int v){
        ll ret=0;
        while(top[u]!=top[v]){
            if(dep[top[u]]>dep[top[v]])swap(u,v);
            ret+=splay::getsum(tree,pos[top[v]],pos[v]);
            v=prt[top[v]];
        }
        if(dep[u]>dep[v])swap(u,v);
        //pf("[%d,%d]\n",pos[u],pos[v]);
        ret+=splay::getsum(tree,pos[u],pos[v]);
        return ret;
    }
    inline int getmin(int u,int v){
        int ret=~0u>>1;
        while(top[u]!=top[v]){
            if(dep[top[u]]>dep[top[v]])swap(u,v);
            ret=min(ret,splay::getmin(tree,pos[top[v]],pos[v]));
            v=prt[top[v]];
        }
        if(dep[u]>dep[v])swap(u,v);
        ret=min(ret,splay::getmin(tree,pos[u],pos[v]));
        return ret;
    }
    inline int getmax(int u,int v){
        int ret=-(~0u>>1);
        while(top[u]!=top[v]){
            if(dep[top[u]]>dep[top[v]])swap(u,v);
            ret=max(ret,splay::getmax(tree,pos[top[v]],pos[v]));
            v=prt[top[v]];
        }
        if(dep[u]>dep[v])swap(u,v);
        ret=max(ret,splay::getmax(tree,pos[u],pos[v]));
        return ret;
    }
    inline void invert(int u,int v){
        vector<pair<int,int> >tmp;
        if(dep[u]>dep[v])swap(u,v);
        while(top[u]!=top[v])
            tmp.pb(mp(pos[top[v]],pos[v])),v=prt[top[v]];
        tmp.pb(mp(pos[u],pos[v]));
        splay::node*tmp2=splay::create();
        reverse(tmp.begin(),tmp.end());
        wp(i,tmp)splay::link(tmp2,splay::cut(tree,tmp[i].first,tmp[i].second),0);
        splay::invert(tmp2,1,tmp2->siz-2);
        vp(i,tmp)splay::link(tree,splay::cut(tmp2,1,tmp[i].second-tmp[i].first+1),tmp[i].first-1);
    }
}
int main(){
    chain::build();
    lp(i,1,q){
        static char op[11];
        sf("%s",op);
        if(op[0]=='I'&&op[2]=='c'){
            int u,v,d;sf("%d%d%d",&u,&v,&d);
            chain::increase(u,v,d);
        }else if(op[0]=='S'){
            int u,v;sf("%d%d",&u,&v);
            pf("%lld\n",chain::getsum(u,v));
        }else if(op[0]=='M'&&op[1]=='a'){
            int u,v;sf("%d%d",&u,&v);
            pf("%d\n",chain::getmax(u,v));
        }else if(op[0]=='M'&&op[1]=='i'){
            int u,v;sf("%d%d",&u,&v);
            pf("%d\n",chain::getmin(u,v));
        }else{
            int u,v;sf("%d%d",&u,&v);
            chain::invert(u,v);
        }
    }
    return 0;
}
