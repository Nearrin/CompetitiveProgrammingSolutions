#include<cstdio>
#include<algorithm>
#include<vector>
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
namespace tree{
    int n,q,prt[100010],pos[100010],sop[100010],nw,rt;
    int mi[100010];
    vector<int>chd[100010];
    void dfs1(int u){
        mi[u]=u;
        vp(i,chd[u]){
            dfs1(chd[u][i]);
            mi[u]=min(mi[u],mi[chd[u][i]]);
        }
    }
   bool cmp(int a,int b){
        return mi[a]<mi[b];
    }
    void dfs2(int u){
        sort(chd[u].begin(),chd[u].end(),cmp);
        vp(i,chd[u])dfs2(chd[u][i]);
        pos[u]=++nw;sop[nw]=u;
    }
   void build(){
        sf("%d%d",&n,&q);
        lp(i,1,n){
            sf("%d",&prt[i]);
            chd[prt[i]].pb(i);
            if(!prt[i])rt=i;
        }
        dfs1(rt);
        dfs2(rt);
    }
}
namespace seg{
    int sum[100010*4];
    int find(int x,int l,int r){
        if(l==r)return l;
        else{
            int m=(l+r)/2;
            if(sum[x*2]!=m-l+1)return find(x*2,l,m);
            else return find(x*2+1,m+1,r);
        }
    }
    void modify(int x,int l,int r,int p,int d){
        sum[x]+=d;
        if(l!=r){
            int m=(l+r)/2;
            if(p<=m)modify(x*2,l,m,p,d);
            else modify(x*2+1,m+1,r,p,d);
        }
    }
}
namespace lct{
    struct node{
        node*ch[2],*pr;int val,sum;
    }ns[100010];
   int direct(node*x){
        if(!x->pr)return 2;
        else if(x==x->pr->ch[0])return 0;
        else if(x==x->pr->ch[1])return 1;
        else return 2;
    }
    void update(node*x){x->sum=x->val;lp(i,0,1)if(x->ch[i])x->sum+=x->ch[i]->sum;}
     void setchd(node*x,node*y,int d){x->ch[d]=y;if(y)y->pr=x;update(x);}
    void rotate(node*x){
        node*y=x->pr,*z=y->pr;int d1=direct(x),d2=direct(y);
        setchd(y,x->ch[!d1],d1);setchd(x,y,!d1);
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
    void modify(node*x,int d){splay(x);x->sum+=d;x->val+=d;}
    node*access(node*x){node*y=0;while(x){splay(x);setchd(x,y,1);y=x;x=x->pr;}return y;}
    void build(){
        lp(i,1,tree::n)if(tree::prt[i])ns[i].pr=ns+tree::prt[i];
    }
     pair<int,int>query(node*x){
        int t=x->ch[0]?x->ch[0]->sum:0;
        if(t){
            pair<int,int>ret=query(x->ch[0]);
            return mp(ret.first,ret.second+1+(x->ch[1]?x->ch[1]->sum:0));
        }else if(x->val){
            return mp(x-ns,1+(x->ch[1]?x->ch[1]->sum:0));
        }else return query(x->ch[1]);
    }
}
int main(){
    tree::build();
    lct::build();
    lp(i,1,tree::q){
        int op;sf("%d",&op);
        if(op==1){
            int k;sf("%d",&k);int ans;
            lp(j,1,k){
                int tmp=tree::sop[seg::find(1,1,tree::n)];
                seg::modify(1,1,tree::n,tree::pos[tmp],1);
                lct::modify(lct::ns+tmp,1);
                ans=tmp;
            }
            pf("%d\n",ans);
        }else{
            int u;sf("%d",&u);
            lct::access(lct::ns+u);
            lct::splay(lct::ns+u);
            pair<int,int>tmp=lct::query(lct::ns+u);
            lct::modify(lct::ns+tmp.first,-1);
            seg::modify(1,1,tree::n,tree::pos[tmp.first],-1);
            pf("%d\n",tmp.second-1);
        }
    }
    return 0;
}
