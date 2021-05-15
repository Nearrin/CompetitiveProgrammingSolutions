#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<cstdlib>
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
namespace trie{
    struct node{
        node*cl,*cr;int cnt;
    };
    node buff[30000010];node*bfs=buff;
    node*stk[30000010];node**sts=stk;
    inline node*newnode(node*a,node*b,int c){
        node*t;if(sts==stk)t=bfs++;
        else{
            t=*(sts--);
            if(t->cl)*(++sts)=t->cl;
            if(t->cr)*(++sts)=t->cr;
        }
        t->cl=a;t->cr=b;t->cnt=c;
        return t;
    }
    inline node*merge(node*x,node*y){
        if(!x&&!y)return newnode(0,0,0);
        else{
            node*a=0;if((x&&x->cl)||(y&&y->cl))a=merge(x?x->cl:0,y?y->cl:0);
            node*b=0;if((x&&x->cr)||(y&&y->cr))b=merge(x?x->cr:0,y?y->cr:0);
            node*c=newnode(a,b,0);
            if(!c->cl&&!c->cr)c->cnt=(x?x->cnt:0)+(y?y->cnt:0);
            return c;
        }
    }
    inline node*insert(node*&x,int v){
        if(!x)x=newnode(0,0,0);
        node*y=x;
        rp(i,19,0){
            if((v>>i)&1){
                if(!y->cr)y->cr=newnode(0,0,0);
                y=y->cr;
            }else{
                if(!y->cl)y->cl=newnode(0,0,0);
                y=y->cl;
            }
        }
        ++y->cnt;
    }
    inline int query(node*x,int v){
        node*y=x;int r=0;
        rp(i,19,0){
            if((v>>i)&1){
                if(y->cl)y=y->cl,r+=(1<<i);
                else y=y->cr;
            }else{
                if(y->cr)y=y->cr,r+=(1<<i);
                else y=y->cl;
            }
        }
        return r;
    }
    inline void remove(node*&x,int v,int d){
        if(d==-1){if(!--x->cnt){*(++sts)=x;x=0;}}
        else{
            if((v>>d)&1)remove(x->cr,v,d-1);
            else remove(x->cl,v,d-1);
            if(!x->cl&&!x->cr){*(++sts)=x;x=0;}
        }
    }
    inline void clear(node*&x){
        if(x){*(++sts)=x;x=0;}
    }
}
namespace treap{
    struct node{
        node(){};
        node*ch[2];int v,mx[2];trie::node*tr;int siz,fx;
    };
    node buff[200010];int bfs;
    inline node*newnode(int a){
        node*t=&buff[bfs++];
        t->v=a;t->tr=trie::newnode(0,0,0);trie::insert(t->tr,t->v);
        t->mx[0]=a;t->mx[1]=-1;t->siz=1;t->fx=rand();t->ch[0]=t->ch[1]=0;
        return t;
    }
    inline void lupdate(node*x){
        x->siz=1;
        lp(i,0,1)if(x->ch[i])x->siz+=x->ch[i]->siz;
        x->mx[0]=x->v;x->mx[1]=-1;
        static int tmp[6];int ts=0;tmp[ts++]=x->v;tmp[ts++]=-1;
        lp(i,0,1)if(x->ch[i])tmp[ts++]=x->ch[i]->mx[0],tmp[ts++]=x->ch[i]->mx[1];
        sort(tmp,tmp+ts);
        x->mx[0]=tmp[ts-1];x->mx[1]=tmp[ts-2];
    }
    inline void update(node*x){
        lupdate(x);
        trie::clear(x->tr);x->tr=trie::merge(x->ch[0]?x->ch[0]->tr:0,x->ch[1]?x->ch[1]->tr:0);
        trie::insert(x->tr,x->v);
    }
    inline void rotate(node*&x,int d){
        node*y=x->ch[d];
        x->ch[d]=y->ch[!d];
        y->ch[!d]=x;
        trie::clear(y->tr);
        y->tr=x->tr;x->tr=0;
        update(x);
        lupdate(y);
        x=y;
    }
    inline void insert(node*&x,int k,int v){
        if(!x)x=newnode(v);
        else{
            int t=(x->ch[0]?x->ch[0]->siz:0)+1;
            trie::insert(x->tr,v);
            if(t<=k){
                insert(x->ch[1],k-t,v);lupdate(x);
                if(x->ch[1]->fx<x->fx)rotate(x,1);
            }else{
                insert(x->ch[0],k,v);lupdate(x);
                if(x->ch[0]->fx<x->fx)rotate(x,0);
            }
        }
    }
    inline int modify(node*x,int k,int v){
        int t=(x->ch[0]?x->ch[0]->siz:0),r;
        if(k<=t)r=modify(x->ch[0],k,v);
        else if(t+1==k)r=x->v,x->v=v;
        else r=modify(x->ch[1],k-(t+1),v);
        lupdate(x);
        trie::remove(x->tr,r,19);
        trie::insert(x->tr,v);
        return r;
    }
    inline int remove(node*&x){
        int r=x->v;
        if(!x->ch[0]){
            trie::clear(x->tr);
            x=x->ch[1];
        }else if(!x->ch[1]){
            trie::clear(x->tr);
            x=x->ch[0];
        }else if(x->ch[0]->fx<x->ch[1]->fx){
            rotate(x,0);
            remove(x->ch[1]);
            trie::remove(x->tr,r,19);
            lupdate(x);
        }else{
            rotate(x,1);
            remove(x->ch[0]);
            trie::remove(x->tr,r,19);
            lupdate(x);
        }
        return r;
    }
    inline int remove(node*&x,int k){
        int t=(x->ch[0]?x->ch[0]->siz:0),r;
        if(t>=k){
            r=remove(x->ch[0],k);
            trie::remove(x->tr,r,19);
            lupdate(x);
        }else if(k>t+1){
            r=remove(x->ch[1],k-(t+1));
            trie::remove(x->tr,r,19);
            lupdate(x);
        }else r=remove(x);
        return r;
    }
    inline void query(node*x,int l,int r,int*a,int&as,trie::node**b,int&bs,int*c,int&cs){
        int t1=(x->ch[0]?x->ch[0]->siz:0),t2=(x->ch[1]?x->ch[1]->siz:0);
        if(l==1&&r==t1+t2+1){
            b[++bs]=x->tr;
            c[++cs]=x->mx[0];
            c[++cs]=x->mx[1];
        }else if(l<=t1+1&&r>=t1+1){
            a[++as]=x->v;
            c[++cs]=x->v;
            if(l<t1+1)query(x->ch[0],l,t1,a,as,b,bs,c,cs);
            if(r>t1+1)query(x->ch[1],1,r-(t1+1),a,as,b,bs,c,cs);
        }else if(r<t1+1)
            query(x->ch[0],l,r,a,as,b,bs,c,cs);
        else
            query(x->ch[1],l-(t1+1),r-(t1+1),a,as,b,bs,c,cs);
    }
    inline void lrotate(node*&x,int d){
        node*y=x->ch[d];
        x->ch[d]=y->ch[!d];
        y->ch[!d]=x;
        x->siz=1;
        lp(i,0,1)if(x->ch[i])x->siz+=x->ch[i]->siz;
        y->siz=1;
        lp(i,0,1)if(y->ch[i])y->siz+=y->ch[i]->siz;
        x=y;
    }
    inline void linsert(node*&x,int k,int v){
        if(!x)x=newnode(v);
        else{
            int t=(x->ch[0]?x->ch[0]->siz:0)+1;
            if(t<=k){
                linsert(x->ch[1],k-t,v);++x->siz;
                if(x->ch[1]->fx<x->fx)lrotate(x,1);
            }else{
                linsert(x->ch[0],k,v);++x->siz;
                if(x->ch[0]->fx<x->fx)lrotate(x,0);
            }
        }
    }
    inline void lbuild(node*x){
        if(x->ch[0]||x->ch[1]){
            lp(i,0,1)if(x->ch[i])lbuild(x->ch[i]);
            update(x);
        }
    }
}
static char buff[3000010],*ptr=buff;
inline char gchr(){
    for(;*ptr=='\n'||*ptr==' ';++ptr);
    return *ptr++;
}
inline int gint(){
    int t=gchr()-'0';
    for(;*ptr!='\n'&&*ptr!=' '&&*ptr!=0;++ptr)t=t*10+*ptr-'0';
    return t;
}
inline void pint(int a){
    static char tmp[11];int ts=0;
    do{
        tmp[++ts]=a%10;
        a/=10;
    }while(a);
    rp(i,ts,1)putchar('0'+tmp[i]);
    putchar('\n');
}
int main(){
    fread(buff,1,3000000,stdin);
    int n=gint(),m=gint();treap::node*rt=0;
    lp(i,1,n){
        int t=gint();
        treap::linsert(rt,i-1,t);
    }
    treap::lbuild(rt);
    int lst=0;
    lp(i,1,m){
        char op=gchr();
        if(op=='I'){
            int x=gint(),y=gint();
            x=(x+lst)%n;
            y=((y+lst)&1048575);
            treap::insert(rt,x,y);++n;
        }else if(op=='D'){
            int x=gint();
            x=(x+lst)%n;++x;
            treap::remove(rt,x);--n;
        }else if(op=='C'){
            int x=gint(),y=gint();
            x=(x+lst)%n;++x;
            y=((y+lst)&1048575);
            treap::modify(rt,x,y);
        }else{
            int l=gint(),r=gint();
            l=(l+ll(lst))%n;++l;
            r=(r+ll(lst))%n;++r;
            static int a[200010],c[200010];
            static trie::node*b[200010];int as=0,bs=0,cs=0;
            treap::query(rt,l,r,a,as,b,bs,c,cs);
            int pc=-1;
            lp(j,1,cs)if(pc==-1||c[j]>c[pc])pc=j;
            int u=-1;
            lp(j,1,cs)if(j!=pc)u=max(u,c[j]);
            int ans=0;
            lp(j,1,as)ans=max(ans,(u^a[j]));
            lp(j,1,bs)ans=max(ans,trie::query(b[j],u));
            pint(lst=ans);
        }
    }
    //ps;
    return 0;
}
