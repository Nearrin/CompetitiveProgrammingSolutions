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
#include<queue>
#include<cstdlib>
const int N=100010,INF=~0u>>1;
inline void gmin(int&a,int b){if(b<a)a=b;}
inline void gmax(int&a,int b){if(b>a)a=b;}
struct lct{
    struct treap{
        lct*tr;inline treap(struct lct*a):tr(a){}
        struct node{
            inline node(){}
            inline node(int a,int b,int c,int d,int e){
                ch[0]=ch[1]=0;val=a;fix=rand();add=0;
                mi=vmi=b;mx=vmx=c;sum=vsum=d;siz=vsiz=e;sam=INF;
            }
            node*ch[2];int val,fix,vmi,vmx,vsum,vsiz,mi,mx,sum,siz,add,sam;
        }ns[N];
        inline void down(node*a){
            if(a->sam!=INF){
                a->mi=a->mx=a->vmi=a->vmx=a->sam;
                a->vsum=a->sam*a->vsiz;a->sum=a->sam*a->siz;
                (tr->ns+(a-ns))->viradd=0;(tr->ns+(a-ns))->virsam=a->sam;
                (tr->ns+(a-ns))->add=0;(tr->ns+(a-ns))->sam=a->sam;
                lp(i,0,1)if(a->ch[i])a->ch[i]->add=0,a->ch[i]->sam=a->sam;a->sam=INF;
            }
            if(a->add){
                a->mi+=a->add;a->mx+=a->add;
                a->vmi+=a->add;a->vmx+=a->add;
                a->vsum+=a->add*a->vsiz;a->sum+=a->add*a->siz;
                (tr->ns+(a-ns))->viradd+=a->add;(tr->ns+(a-ns))->add+=a->add;
                lp(i,0,1)if(a->ch[i])a->ch[i]->add+=a->add;a->add=0;
            }
        }
        inline void update(node*a){
            lp(i,0,1)if(a->ch[i])down(a->ch[i]);
            a->mi=a->vmi;lp(i,0,1)if(a->ch[i])gmin(a->mi,a->ch[i]->mi);
            a->mx=a->vmx;lp(i,0,1)if(a->ch[i])gmax(a->mx,a->ch[i]->mx);
            a->sum=a->vsum;lp(i,0,1)if(a->ch[i])a->sum+=a->ch[i]->sum;
            a->siz=a->vsiz;lp(i,0,1)if(a->ch[i])a->siz+=a->ch[i]->siz;
        }
        inline void rotate(node*&a,int d){
            node*b=a->ch[d];a->ch[d]=b->ch[!d];b->ch[!d]=a;
            update(a);update(b);a=b;
        }
        inline void insert(node*&a,node*b){
            if(!a)a=b;else{
                down(a);int d=b->val>a->val;
                insert(a->ch[d],b);update(a);
                if(a->ch[d]->fix<a->fix)rotate(a,d);
            }
        }
        inline void erase(node*&a,int b){
            down(a);if(a->val==b){
                if(!a->ch[0])a=a->ch[1];
                else if(!a->ch[1])a=a->ch[0];
                else{
                    int d=a->ch[1]->fix<a->ch[0]->fix;down(a->ch[d]);
                    rotate(a,d);erase(a->ch[!d],b);update(a);
                }
            }else{int d=b>a->val;erase(a->ch[d],b);update(a);}
        }
    };
    inline lct():trp(this){}
    struct node{
        inline node(){}
        inline node(int a,node*b){
            ch[0]=ch[1]=0;pr=b;
            vir=0;val=a;mi=mx=a;siz=1;
            rev=virsum=add=0;virmi=INF;virmx=-INF;sam=INF;
            virsam=INF;virsiz=0;viradd=0;
        }
        node*ch[2],*pr;
        int val,mi,mx,sum,virmi,virmx,virsum,virsam,viradd,virsiz,rev,sam,siz,add;
        treap::node*vir;
    }ns[N];treap trp;
    inline int direct(node*a){
        if(!a->pr)return 3;
        else if(a==a->pr->ch[0])return 0;
        else if(a==a->pr->ch[1])return 1;
        else return 2;
    }
    inline void down(node*a){
        if(a->rev){
        	swap(a->ch[0],a->ch[1]);
        	lp(i,0,1)if(a->ch[i])a->ch[i]->rev^=1;a->rev=0;
        }
        if(a->sam!=INF){
            a->val=a->mi=a->mx=a->sam;a->sum=a->sam*a->siz;
            lp(i,0,1)if(a->ch[i])a->ch[i]->sam=a->sam,a->ch[i]->add=0;a->sam=INF;
        }
        if(a->add){
            a->val+=a->add;a->mi+=a->add;a->mx+=a->add;a->sum+=a->add*a->siz;
            lp(i,0,1)if(a->ch[i])a->ch[i]->add+=a->add;a->add=0;
        }
        if(a->virsam!=INF){
            if(a->virsiz){
                a->virmi=a->virmx=a->virsam;a->virsum=a->virsam*a->virsiz;
                if(a->vir)a->vir->add=0,a->vir->sam=a->virsam;
                lp(i,0,1)if(a->ch[i])a->ch[i]->viradd=0,a->ch[i]->virsam=a->virsam;
            }
            a->virsam=INF;
        }
        if(a->viradd){
            if(a->virsiz){
                a->virmi+=a->viradd;a->virmx+=a->viradd;
                a->virsum+=a->viradd*a->virsiz;
                if(a->vir)a->vir->add+=a->viradd;
                lp(i,0,1)if(a->ch[i])a->ch[i]->viradd+=a->viradd;
            }
            a->viradd=0;
        }
    }
    inline void update(node*a){
        lp(i,0,1)if(a->ch[i])down(a->ch[i]);
        if(a->vir)trp.down(a->vir);
        a->mi=a->val;lp(i,0,1)if(a->ch[i])gmin(a->mi,a->ch[i]->mi);
        a->virmi=INF;lp(i,0,1)if(a->ch[i])gmin(a->virmi,a->ch[i]->virmi);
        if(a->vir)gmin(a->virmi,a->vir->mi);
        a->mx=a->val;lp(i,0,1)if(a->ch[i])gmax(a->mx,a->ch[i]->mx);
        a->virmx=-INF;lp(i,0,1)if(a->ch[i])gmax(a->virmx,a->ch[i]->virmx);
        if(a->vir)gmax(a->virmx,a->vir->mx);
        a->sum=a->val;lp(i,0,1)if(a->ch[i])a->sum+=a->ch[i]->sum;
        a->virsum=0;lp(i,0,1)if(a->ch[i])a->virsum+=a->ch[i]->virsum;
        if(a->vir)a->virsum+=a->vir->sum;
        a->siz=1;lp(i,0,1)if(a->ch[i])a->siz+=a->ch[i]->siz;
        a->virsiz=0;lp(i,0,1)if(a->ch[i])a->virsiz+=a->ch[i]->virsiz;
        if(a->vir)a->virsiz+=a->vir->siz;
    }
    inline void setchd(node*a,node*b,int d){a->ch[d]=b;if(b)b->pr=a;update(a);}
    inline void connect(node*a,node*b){
        down(a);
        *(trp.ns+(a-ns))=treap::node(a-ns,min(a->virmi,a->mi),
            max(a->virmx,a->mx),a->virsum+a->sum,a->virsiz+a->siz);
        trp.insert(b->vir,trp.ns+(a-ns));
    }
    inline void disconnect(node*a,node*b){trp.erase(b->vir,a-ns);}
    inline void rotate(node*a){
        node*b=a->pr,*c=a->pr->pr;int d1=direct(a),d2=direct(b);
        setchd(b,a->ch[!d1],d1);setchd(a,b,!d1);
        if(d2<2)setchd(c,a,d2);
        else if(d2==2){disconnect(b,c);connect(a,c);a->pr=c;}
        else a->pr=0;
    }
    inline void release(node*a){
        if(direct(a)<2)release(a->pr);
        else if(a->pr)disconnect(a,a->pr),connect(a,a->pr);
        down(a);
    }
    inline void splay(node*a){
        release(a);
        while(direct(a)<2){
            node*b=a->pr;
            if(!b->pr||direct(b)>1)rotate(a);
            else if(direct(a)==direct(b))rotate(b),rotate(a);
            else rotate(a),rotate(a);
        }
    }
    inline node*access(node*a){
        node*b=0;
        while(a){
            splay(a);if(a->ch[1])connect(a->ch[1],a);
            if(b)disconnect(b,a);setchd(a,b,1);b=a;a=a->pr;
        }
        return b;
    }
    inline void evert(node*a){access(a);splay(a);a->rev=1;}
    inline int qchain(node*a,node*b,int d){
        access(a);node*c=access(b);splay(c);splay(a);int ret=c->val;
        if(d==1){
            if(a!=c)gmin(ret,a->mi);
            if(c->ch[1])down(c->ch[1]),gmin(ret,c->ch[1]->mi);
        }else if(d==2){
            if(a!=c)gmax(ret,a->mx);
            if(c->ch[1])down(c->ch[1]),gmax(ret,c->ch[1]->mx);
        }else if(d==3){
            if(a!=c)ret+=a->sum;
            if(c->ch[1])down(c->ch[1]),ret+=c->ch[1]->sum;
        }
        return ret;
    }
    inline void mchain(node*a,node*b,int u,int d){
        access(a);node*c=access(b);splay(c);splay(a);
        if(d==1){
            c->val+=u;if(a!=c)a->add=u,disconnect(a,c),connect(a,c);
            if(c->ch[1])down(c->ch[1]),c->ch[1]->add=u;
        }else if(d==2){
            c->val=u;if(a!=c)a->sam=u,disconnect(a,c),connect(a,c);
            if(c->ch[1])down(c->ch[1]),c->ch[1]->sam=u;
        }
        update(c);
    }
    inline int qtree(node*a,int d){
        access(a);
        splay(a);int ret=a->val;
        if(d==1){if(a->vir)trp.down(a->vir),gmin(ret,a->vir->mi);
        }else if(d==2){if(a->vir)trp.down(a->vir),gmax(ret,a->vir->mx);
        }else if(d==3){if(a->vir)trp.down(a->vir),ret+=a->vir->sum;}
        return ret;
    }
    inline void mtree(node*a,int u,int d){
        access(a);splay(a);
        if(d==1){a->val+=u;if(a->vir)trp.down(a->vir),a->vir->add=u;
        }else if(d==2){a->val=u;if(a->vir)trp.down(a->vir),a->vir->sam=u;}
        update(a);
    }
    inline void stparent(node*a,node*b){
        access(b);if(access(a)!=a){
            splay(a);node*c=a->ch[0];down(c);
            while(c->ch[1])c=c->ch[1],down(c);
            splay(c);c->ch[1]=0;update(c);access(b);
            splay(b);connect(a,b);a->pr=b;update(b);
        }
    }
    inline void build(vector<int>*to,int*we,int n,int rt){
        static int pr[N];vector<int>vec;
        queue<int>qu;qu.push(rt);
        while(!qu.empty()){
            int u=qu.front();qu.pop();vec.pb(u);
            vp(i,to[u]){int v=to[u][i];if(v!=pr[u])qu.push(v),pr[v]=u;}
        }
        lp(i,0,n-1){int u=vec[i];ns[u]=node(we[u],pr[u]?ns+pr[u]:0);}
        rp(i,n-1,0){int u=vec[i];update(ns+u);if(pr[u])connect(ns+u,ns+pr[u]);}
    }
}tr;
char bin[10000010],*pin=bin;
char bout[10000010],*pout=bout;
inline bool dig(char c){
    return c>='0'&&c<='9';
}
inline char gchr(){
    for(;!dig(*pin);++pin);
    return *pin++;
}
inline int gint(){
    int t=gchr()-'0';
    for(;dig(*pin);++pin)t=t*10+*pin-'0';
    return t;
}
inline void pint(int a){
    static char tmp[11];int ts=0;
    do{
        tmp[++ts]=a%10;
        a/=10;
    }while(a);
    rp(i,ts,1)*pout++='0'+tmp[i];
    *pout++='\n';
}
int main(){
    fread(bin,1,10000000,stdin);
    static vector<int>to[N];static int we[N];int n=gint(),q=gint(),rt;
    lp(i,1,n-1){int u=gint(),v=gint();to[u].pb(v);to[v].pb(u);}
    lp(i,1,n)we[i]=gint();rt=gint();tr.build(to,we,n,rt);
    lp(i,1,q){
        int k=gint();
        if(k==0){int a=gint(),b=gint();tr.mtree(tr.ns+a,b,2);
        }else if(k==1){int a=gint();tr.evert(tr.ns+a);
        }else if(k==2){int a=gint(),b=gint(),c=gint();tr.mchain(tr.ns+a,tr.ns+b,c,2);
        }else if(k==3){int a=gint();pint(tr.qtree(tr.ns+a,1));
        }else if(k==4){int a=gint();pint(tr.qtree(tr.ns+a,2));
        }else if(k==5){int a=gint(),b=gint();tr.mtree(tr.ns+a,b,1);
        }else if(k==6){int a=gint(),b=gint(),c=gint();tr.mchain(tr.ns+a,tr.ns+b,c,1);
        }else if(k==7){int a=gint(),b=gint();pint(tr.qchain(tr.ns+a,tr.ns+b,1));
        }else if(k==8){int a=gint(),b=gint();pint(tr.qchain(tr.ns+a,tr.ns+b,2));
        }else if(k==9){int a=gint(),b=gint();tr.stparent(tr.ns+a,tr.ns+b);
        }else if(k==10){int a=gint(),b=gint();pint(tr.qchain(tr.ns+a,tr.ns+b,3));
        }else{int a=gint();pint(tr.qtree(tr.ns+a,3));}
    }
    fwrite(bout,1,pout-bout,stdout);
    return 0;
}
