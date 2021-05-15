#include<bits/stdc++.h>
#define lop(i,a,b) for(int i=a;i<=b;++i)
#define rlp(i,a,b) for(int i=a;i>=b;--i)
#define all(a) a.begin(),a.end()
#define sqr(a) ((a)*(a))
#define pub push_back
#define mkp make_pair
#define scf scanf
#define ptf printf
#define inf (~0u>>1)
#define sta static
#define ocf 0
#ifdef ONLINE_JUDGE
#define ocf 1
#endif
namespace CTL{}
using namespace CTL;
using namespace std;
typedef long long lli;
typedef unsigned long long ull;
typedef string str;
typedef vector<int> vei;
typedef vector<string> ves;
typedef map<int,int> mii;
typedef map<str,int> msi;
typedef set<int> sti;
typedef set<str> sts;
typedef pair<int,int> pii;
typedef vector<pii> vii;

#ifndef DELAUNAY_TRIANGULATION
#define DELAUNAY_TRIANGULATION
#include<bits/stdc++.h>
namespace CTL{
    using namespace std;
    struct DelaunayTriangulation{
        typedef double T;const static T E;
        struct poi{
            T x,y;poi(T _x=0,T _y=0):x(_x),y(_y){}
            poi operator-(poi b){return poi(x-b.x,y-b.y);}
            int operator<(poi b)const{if(fabs(x-b.x)<E)return y<b.y;return x<b.x;}};
        int n;vector<pair<poi,int> >pts;vector<vector<int> >egs;
        T det(poi a,poi b){return a.x*b.y-a.y*b.x;}
        T dot(poi a,poi b){return a.x*b.x+a.y*b.y;}
        int dir(poi a,poi b,poi c){T r=det(c-a,b-a);if(r<-E)return -1;return r>E?1:0;}
        int inc(poi a,poi b,poi c,poi d){
            a=a-d;b=b-d;c=c-d;
            T az=a.x*a.x+a.y*a.y,bz=b.x*b.x+b.y*b.y,cz=c.x*c.x+c.y*c.y;
            return a.x*b.y*cz+b.x*c.y*az+c.x*a.y*bz-a.x*bz*c.y-b.x*a.y*cz-c.x*b.y*az>E;}
        int crs(poi a,poi b,poi c,poi d){return dir(a,b,c)*dir(a,b,d)==-1&&dir(c,d,a)*dir(c,d,b)==-1;}
        DelaunayTriangulation():n(0),pts(1){}
        void add(T x,T y){poi a;a.x=x;a.y=y;pts.push_back(make_pair(a,++n));}
        poi&pot(int a){return pts[a].first;}
        void con(int a,int b){
            egs[a].push_back(b);egs[b].push_back(a);}
        void dco(int a,int b){
            egs[a].erase(find(egs[a].begin(),egs[a].end(),b));
            egs[b].erase(find(egs[b].begin(),egs[b].end(),a));}
        void dnc(int l,int r){
            if(r==l)return;if(r==l+1){con(l,r);return;}
            if(r==l+2){
                if(dir(pot(l),pot(l+1),pot(r)))con(l,l+1),con(l+1,r),con(l,r);
                else{
                    if(dot(pot(l+1)-pot(l),pot(r)-pot(l))<0)con(l,l+1),con(l,r);
                    else if(dot(pot(l)-pot(l+1),pot(r)-pot(l+1))<0)con(l,l+1),con(l+1,r);
                    else con(l,r),con(l+1,r);}
                return;}
            int m=(l+r)/2,pl=l,pr=r;dnc(l,m);dnc(m+1,r);
            for(int f=0;;f=0){
                for(int i=0;i<egs[pl].size();++i){
                    int a=egs[pl][i],d=dir(pot(pl),pot(pr),pot(a));
                    if(d>0||(d==0&&dot(pot(pl)-pot(a),pot(pr)-pot(a))<0)){
                        pl=a;f=1;break;}}
                for(int i=0;i<egs[pr].size();++i){
                    int a=egs[pr][i],d=dir(pot(pl),pot(pr),pot(a));
                    if(d>0||(d==0&&dot(pot(pl)-pot(a),pot(pr)-pot(a))<0)){
                        pr=a;f=1;break;}}
                if(!f)break;}
            con(pl,pr);for(int pn=-1,wh=0;;pn=-1,wh=0){
                for(int i=0;i<egs[pl].size();++i){
                    int a=egs[pl][i],d=dir(pot(pl),pot(pr),pot(a));
                    if(d<0&&(pn==-1||inc(pot(pl),pot(pr),pot(pn),pot(a))))pn=a;}
                for(int i=0;i<egs[pr].size();++i){
                    int a=egs[pr][i],d=dir(pot(pl),pot(pr),pot(a));
                    if(d<0&&(pn==-1||inc(pot(pl),pot(pr),pot(pn),pot(a))))pn=a,wh=1;}
                if(pn==-1)break;vector<int>ne;
                if(!wh){
                    for(int i=0;i<egs[pl].size();++i){
                        int a=egs[pl][i];
                        if(!crs(pot(pn),pot(pr),pot(pl),pot(a)))ne.push_back(a);
                        else egs[a].erase(find(egs[a].begin(),egs[a].end(),pl));}
                    egs[pl]=ne;con(pr,pn);pl=pn;
                }else{
                    for(int i=0;i<egs[pr].size();++i){
                        int a=egs[pr][i];
                        if(!crs(pot(pn),pot(pl),pot(pr),pot(a)))ne.push_back(a);
                        else egs[a].erase(find(egs[a].begin(),egs[a].end(),pr));}
                    egs[pr]=ne;con(pl,pn);pr=pn;}}}
        vector<vector<int> >run(){
            egs.resize(n+1);sort(pts.begin()+1,pts.end());dnc(1,n);
            vector<vector<int> >res(n+1);
            for(int u=1;u<=n;++u)for(int i=0;i<egs[u].size();++i){
                int v=egs[u][i];res[pts[u].second].push_back(pts[v].second);}
            return res;}};
    const double DelaunayTriangulation::E=1e-8;}
#endif

#ifndef LINK_CUT_TREES
#define LINK_CUT_TREES
#include<bits/stdc++.h>
namespace CTL{
    using namespace std;
    template<class T>struct LinkCutTrees{
        struct node{
            node():ch({0,0}),pr(0),rev(0){}
            node*ch[2],*pr;T ifo;int rev;}*ptrs;
        int direct(node*x){
            if(!x->pr)return 2;
            if(x==x->pr->ch[0])return 0;
            if(x==x->pr->ch[1])return 1;
            return 2;}
        void down(node*x){
            if(x->rev){
                x->ifo.reverse();swap(x->ch[0],x->ch[1]);
                for(int i=0;i<2;++i)if(x->ch[i])x->ch[i]->rev^=1;
                x->rev=0;}
            x->ifo.down(x->ch[0]?&x->ch[0]->ifo:0,x->ch[1]?&x->ch[1]->ifo:0);}
        void up(node*x){
            for(int i=0;i<2;++i)if(x->ch[i])down(x->ch[i]);
            x->ifo.up(x->ch[0]?&x->ch[0]->ifo:0,x->ch[1]?&x->ch[1]->ifo:0);}
        void setchild(node*x,node*y,int d){x->ch[d]=y;if(y)y->pr=x;up(x);}
        void rotate(node*x){
            node*y=x->pr,*z=y->pr;int d1=direct(x),d2=direct(y);
            setchild(y,x->ch[!d1],d1);setchild(x,y,!d1);
            if(d2<2)setchild(z,x,d2);else x->pr=z;}
        void release(node*x){if(direct(x)<2)release(x->pr);down(x);}
        void splay(node*x){
            for(release(x);direct(x)<2;){
                node*y=x->pr;
                if(direct(y)==2)rotate(x);
                else if(direct(x)==direct(y))rotate(y),rotate(x);
                else rotate(x),rotate(x);}}
        node*access(node*x){
            node*y=0;for(;x;){splay(x);setchild(x,y,1);y=x;x=x->pr;}return y;}
        void evert(node*x){access(x);splay(x);x->rev=1;}
        LinkCutTrees(int n):ptrs(new node[n]-1){}
        void set(int x,T v){ptrs[x].ifo=v;}
        int linked(int a,int b){
            access((ptrs+a));node*z=access((ptrs+b));return z==access((ptrs+a));}
        void link(int a,int b){evert((ptrs+b));(ptrs+b)->pr=(ptrs+a);}
        void cut(int a,int b){
            access((ptrs+b));node*z=access((ptrs+a));
            if(z==(ptrs+a))splay((ptrs+b)),(ptrs+b)->pr=0;
            else access((ptrs+b)),splay((ptrs+a)),(ptrs+a)->pr=0;}
        int root(int a){
            access((ptrs+a));splay((ptrs+a));
            node*r=(ptrs+a);while(r->ch[1])r=r->ch[1];
            return r-ptrs;}
        void evert(int a){evert((ptrs+a));}
        int lca(int a,int b){access((ptrs+a));return access((ptrs+b))-ptrs;}
        T query(int a){splay((ptrs+a));T p=(ptrs+a)->ifo;p.up(0,0);return p;}
        T query(int a,int b){
            if((ptrs+a)==(ptrs+b))return query((ptrs+a));
            access((ptrs+a));node*c=access((ptrs+b));
            T p=c.ifo;if(c==(ptrs+b)){
                splay((ptrs+a));T q=(ptrs+a)->ifo;
                q.reverse();p.up(&q,0);return p;
            }else if(c==(ptrs+a))p.up(0,&(ptrs+a)->ch[1]->ifo);
            else{
                splay((ptrs+a));T q=(ptrs+a)->ifo;
                q.reverse();p.up(&q,&c->ch[1]->ifo);}
            return p;}
        T equery(int a){return query(a);}
        T equery(int a,int b){
            access((ptrs+a));node*c=access((ptrs+b));
            if(c==(ptrs+b)){
                splay((ptrs+a));T q=(ptrs+a)->ifo;
                q.reverse();return q;
            }else if(c==(ptrs+a))return (ptrs+a)->ch[1]->ifo;
            else{
                splay((ptrs+a));node*t=c->ch[1];
                while(t->ch[0])t=t->ch[0];splay(t);
                if(t->ch[1])down(t->ch[1]);
                T p=t->ifo,q=(ptrs+a)->ifo;q.reverse();
                p.up(&q,t->ch[1]?&t->ch[1]->ifo:0);return p;}}
        template<class F>void modify(int a,F f){
            splay((ptrs+a));f(&(ptrs+a)->ifo);up((ptrs+a));}
        template<class F>void modify(int a,int b,F f){
            if((ptrs+a)==(ptrs+b)){
                splay((ptrs+a));f(0,&(ptrs+a)->ifo,0);up((ptrs+a));return ;}
            access((ptrs+a));node*c=access((ptrs+b));
            if(c==(ptrs+b))splay((ptrs+a)),f(&(ptrs+a)->ifo,&(ptrs+b)->ifo,0);
            else if(c==a)f(0,&(ptrs+a)->ifo,&(ptrs+a)->ch[1]->ifo);
            else splay(a),f(&(ptrs+a)->ifo,&c->ifo,&c->ch[1]->ifo);
            up(c);}
        template<class F>void emodify(int a,F f){modify(a,f);}
        template<class F>void emodify(int a,int b,F f){
            access((ptrs+a));node*c=access((ptrs+b));
            if(c==(ptrs+b))splay((ptrs+a)),f(&(ptrs+a)->ifo,0);
            else if(c==a)f(0,&(ptrs+a)->ch[1]->ifo);
            else splay(a),f(&(ptrs+a)->ifo,&c->ch[1]->ifo);
            up(c);}};}
#endif

#ifndef MINIMUM_SPANNING_TREE
#define MINIMUM_SPANNING_TREE
#include<bits/stdc++.h>
namespace CTL{
    using namespace std;
    template<class T,class C=less<T> >struct MinimumSpanningTree {
        struct edge{
            T w;int u,v;
            int operator<(const edge&b)const{return C()(w,b.w);}};
        int n;vector<edge>egs;vector<int>pr;
        MinimumSpanningTree(int _n):n(_n),pr(n+1){}
        void add(int u,int v,T w){edge e;e.u=u;e.v=v;e.w=w;egs.push_back(e);}
        int fd(int x){return x==pr[x]?x:pr[x]=fd(pr[x]);}
        void lk(int x,int y){pr[fd(x)]=y;}
        pair<T,vector<edge> >run(){
            vector<edge>ret;T sum=0;
            sort(egs.begin(),egs.end());
            for(int i=1;i<=n;++i)pr[i]=i;
            for(int i=0;i<egs.size();++i){
                int u=egs[i].u,v=egs[i].v;T w=egs[i].w;
                if(fd(u)!=fd(v))lk(u,v),ret.push_back(egs[i]),sum+=w;}
            return make_pair(sum,ret);}};}
#endif
double x[100010],y[100010];
double dis(int u,int v){
    return sqrt(sqr(x[u]-x[v])+sqr(y[u]-y[v]));
}
struct info{
    double w,mxw;
    void reverse(){}
    void up(info*l,info*r){
        mxw=w;
        if(l)mxw=max(mxw,l->mxw);
        if(r)mxw=max(mxw,r->mxw);
    }
    void down(info*l,info*r){

    }
};
vector<int>to[100010];
vector<double>wei[100010];
int prt[100010];
void dfs(LinkCutTrees<info>&lct,int u,int p){
    prt[u]=p;
    if(p==0){
        info ifo;
        ifo.w=0;
        ifo.mxw=0;
        lct.set(u,ifo);
    }
    for(int i=0;i<to[u].size();++i){
        int v=to[u][i];double w=wei[u][i];
        if(v==p)continue;
        info ifo;
        ifo.w=w;
        ifo.mxw=w;
        lct.set(v,ifo);
        dfs(lct,v,u);

    }
}

int main(){
    int n;scf("%d",&n);
    DelaunayTriangulation dt;
    lop(i,1,n){
        scf("%lf%lf",x+i,y+i);
        dt.add(x[i],y[i]);
    }
    vector<vector<int> >egs=dt.run();
    MinimumSpanningTree<double> mst(n);
    for(int i=1;i<=n;++i){
        for(int j=0;j<egs[i].size();++j){
            int u=i,v=egs[i][j];
            double w=dis(u,v);
            mst.add(u,v,w);
        }
    }
    vector<MinimumSpanningTree<double>::edge>mm=mst.run().second;
    for(int i=0;i<mm.size();++i){
        int u=mm[i].u,v=mm[i].v;double w=mm[i].w;
        to[u].push_back(v);
        wei[u].push_back(w);  to[v].push_back(u);
        wei[v].push_back(w);
    }

    LinkCutTrees<info> lct(n);
    dfs(lct,1,0);
    for(int i=2;i<=n;++i)
        lct.link(prt[i],i);
    int m;scanf("%d",&m);
    while(m--){
        int u,v;scf("%d%d",&u,&v);
        double ans=lct.equery(u,v).mxw;
        if(u==v)ans=0;
        ptf("%.6lf\n",ans);
    }
    return 0;
}
