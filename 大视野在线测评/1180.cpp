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
namespace lct{
    const int N=30010;
    struct node{
        inline node(){ch[0]=ch[1]=pr=0;rev=0;}
        node*ch[2],*pr;int val,sum,rev;
    }ns[N];
    inline int direct(node*x){
        if(!x->pr)return 2;
        else if(x==x->pr->ch[0])return 0;
        else if(x==x->pr->ch[1])return 1;
        else return 2;
    }
    inline void down(node*x){
        if(x->rev){
            swap(x->ch[0],x->ch[1]);
            lp(i,0,1)if(x->ch[i])x->ch[i]->rev^=1;
            x->rev=0;
        }
    }
    inline void update(node*x){
        lp(i,0,1)if(x->ch[i])down(x->ch[i]);
        x->sum=x->val;
        lp(i,0,1)if(x->ch[i])x->sum+=x->ch[i]->sum;
    }
    inline void setchd(node*x,node*y,int d){
        x->ch[d]=y;
        if(y)y->pr=x;
        update(x);
    }
    inline void rotate(node*x){
        node*y=x->pr,*z=y->pr;
        int d1=direct(x),d2=direct(y);
        setchd(y,x->ch[!d1],d1);
        setchd(x,y,!d1);
        if(d2<2)setchd(z,x,d2);else x->pr=z;
    }
    inline void release(node*x){
        if(direct(x)<2)release(x->pr);
        down(x);
    }
    inline void splay(node*x){
        release(x);
        while(direct(x)<2){
            node*y=x->pr;
            if(direct(y)==2)rotate(x);
            else if(direct(x)==direct(y))rotate(y),rotate(x);
            else rotate(x),rotate(x);
        }
    }
    inline node*access(node*x){
        node*y=0;
        while(x){
            splay(x);
            setchd(x,y,1);
            y=x;x=x->pr;
        }
        return y;
    }
    inline void evert(node*x){
        access(x);
        splay(x);
        x->rev=1;
    }
    inline bool check(node*x,node*y){
        access(x);node*z=access(y);
        return z==access(x);
    }
    inline void link(node*x,node*y){
        evert(y);y->pr=x;
    }
    inline void modify(node*x,int v){
        splay(x);x->val=v;update(x);
    }
    inline int query(node*x,node*y){
        evert(x);access(y);splay(y);
        return y->sum;
    }
}
int main(){
    int n;sf("%d",&n);
    lp(i,1,n){
        sf("%d",&lct::ns[i].val);
        lct::ns[i].sum=lct::ns[i].val;
    }
    int q;sf("%d",&q);
    lp(i,1,q){
        static char op[110];int u,v;
        sf("%s%d%d",op,&u,&v);
        if(op[0]=='b'){
            if(lct::check(lct::ns+u,lct::ns+v))pf("no\n");
            else pf("yes\n"),lct::link(lct::ns+u,lct::ns+v);
        }else if(op[0]=='p'){
            lct::modify(lct::ns+u,v);
        }else{
            if(!lct::check(lct::ns+u,lct::ns+v))pf("impossible\n");
            else pf("%d\n",lct::query(lct::ns+u,lct::ns+v));
        }
    }
    return 0;
}
