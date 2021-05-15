#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<complex> 
#define sf scanf
#define pf printf
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
/*
二维点 
*/
namespace pot{
    typedef complex<ll> pot;
    ll&x(pot&p){
        return real(p);
    }
    ll&y(pot&p){
        return imag(p);
    }
    double a(pot p){
        return atan2(double(y(p)),double(x(p)));
    }
    pot operator-(pot p,pot q){
        return pot(x(p)-x(q),y(p)-y(q));
    }
    ll det(pot p,pot q){
        return x(p)*y(q)-x(q)*y(p);
    }
}
namespace plr{
    const int nmx=100000;
    struct edge{
        edge(int a,int b,int c,double d):
            u(a),v(b),w(c),ang(d),bel(0){}
        int u,v,w,bel;
        edge*nxt,*rev;
        double ang;
    };
    bool cmp(edge*a,edge*b){
        return a->ang<b->ang;
    }
    int n,m,pc,ws;
    pot::pot pos[nmx+10];
    vector<edge*>eg[nmx+10],all;
    void add(int u,int v,int w){
        edge*a=new edge(u,v,w,pot::a(pos[v]-pos[u]));
        edge*b=new edge(v,u,w,pot::a(pos[u]-pos[v]));
        a->rev=b;b->rev=a;
        eg[u].push_back(a);all.push_back(a);
        eg[v].push_back(b);all.push_back(b);
    }
    void build(){
        lp(i,1,n){
            sort(eg[i].begin(),eg[i].end(),cmp);
            lp(j,0,int(eg[i].size()-1)){
                eg[i][j]->nxt=eg[i][(j+1)%eg[i].size()];
            }
        }
        lp(i,0,int(all.size()-1)){
            if(!all[i]->bel){
                ++pc;ll ar=0;edge*t=all[i];
                do{
                    t->bel=pc;
                    t=t->nxt->rev;
                    ar+=pot::det(pos[t->u],pos[t->v]);
                }while(t!=all[i]);
                if(ar<0)ws=pc;
            }
        }
    }
}
namespace mst{
    struct edge{
        edge(int a,int b,int c):
            u(a),v(b),w(c){}
        int u,v,w;
    };
    bool operator<(const edge&a,const edge&b){
        return a.w<b.w;
    }
    int vcnt;
    vector<edge>all,ans;
    int prt[100010*3];
    int fd(int u){return u==prt[u]?u:prt[u]=fd(prt[u]);}
    void build(){
        vcnt=plr::pc;
        lp(i,1,vcnt)prt[i]=i;
        lp(i,0,int(plr::all.size()-1)){
            plr::edge*e=plr::all[i];
            all.push_back(edge(e->bel,e->rev->bel,e->w));
        }
        sort(all.begin(),all.end());
        lp(i,0,int(all.size()-1)){
            edge&e=all[i];
            if(fd(e.u)!=fd(e.v)&&e.u!=plr::ws&&e.v!=plr::ws){
                ans.push_back(e);
                prt[fd(e.u)]=e.v;
            }
        }
        /*lp(i,0,int(ans.size()-1)){
            pf("[%d,%d]\n",ans[i].u,ans[i].v);
        }*/
    }
}
namespace lca{
    int vcnt;
    vector<int>to[100010*3],we[100010*3];
    int vi[100010*3],dp[100010*3],up[100010*3][21],mx[100010*3][21];
    int query(int u,int v){
        int r=0;
        if(dp[u]<dp[v])swap(u,v);
        lp(i,0,20)if(((dp[u]-dp[v])>>i)&1)r=max(r,mx[u][i]),u=up[u][i];
        if(u==v)return r;
        for(int i=20;i>=0;--i){
            if(up[u][i]!=up[v][i]){
                r=max(r,mx[u][i]);
                r=max(r,mx[v][i]);
                u=up[u][i];
                v=up[v][i];
            }
        }
        return max(max(mx[u][0],mx[v][0]),r);
    }
    void build(){
        vcnt=mst::vcnt;
        lp(i,0,int(mst::ans.size()-1)){
            mst::edge&e=mst::ans[i];
            to[e.u].push_back(e.v);
            we[e.u].push_back(e.w);
            to[e.v].push_back(e.u);
            we[e.v].push_back(e.w);
        }
        queue<int>qu;qu.push(plr::ws==1?2:1);
        vi[plr::ws==1?2:1]=1;
        while(!qu.empty()){
            int u=qu.front();qu.pop();
            lp(i,1,20){
                up[u][i]=up[up[u][i-1]][i-1];
                mx[u][i]=max(mx[u][i-1],mx[up[u][i-1]][i-1]);
            }
            lp(i,0,int(to[u].size()-1)){
                int v=to[u][i];
                if(!vi[v]){
                    vi[v]=1;dp[v]=dp[u]+1;
                    up[v][0]=u;
                    mx[v][0]=we[u][i];
                    qu.push(v);
                }
            }
        }
        //lp(i,1,vcnt)pf("[%d]",vi[i]);
        //lp(i,1,vcnt)lp(j,i+1,vcnt)pf("[%d,%d,%d]\n",i,j,query(i,j));
    }
}
namespace questions{
    int x[100010*2],y[100010*2],q,loc[100010*2];
    void init(){
        sf("%d",&q);
        lp(i,1,q){
            double a,b,c,d;
            sf("%lf%lf%lf%lf",&a,&b,&c,&d);
            x[2*i-1]=a*2+0.1;y[2*i-1]=b*2+0.1;//避免误差
            x[2*i]=c*2+0.1;y[2*i]=d*2+0.1;
        }
    }
    void answer(){
        lp(i,1,q){
            int u=loc[2*i-1],v=loc[2*i];
            if(u==plr::ws||v==plr::ws)
                pf("-1\n");
            else
                pf("%d\n",lca::query(u,v));
        }
    }
}
namespace locate{
    struct event{
        event(int b,int c):
            typ(0),qi(b),x(c){}
        event(int a,plr::edge*b,int c):
            typ(a),e(b),x(c){}
        int typ;//0query1delete2insert
        plr::edge*e;
        int qi,x;
    };
    bool operator<(const event&a,const event&b){
        return a.x==b.x?a.typ<b.typ:a.x<b.x;
    }
    vector<event>ev;
    struct node{
        node(int a,int b):typ(1),x(a),y(b){}
        node(plr::edge*a):typ(0),e(a){}
        int typ;//0seg1pot
        plr::edge*e;
        int x,y;
    };
    bool operator<(const node&a,const node&b){
        if(a.typ==0&&b.typ==0){
            pot::pot p1=plr::pos[a.e->u];
            pot::pot p2=plr::pos[a.e->v];
            pot::pot p3=plr::pos[b.e->u];
            pot::pot p4=plr::pos[b.e->v];
            double x1=pot::x(p1),y1=pot::y(p1);
            double x2=pot::x(p2),y2=pot::y(p2);
            double x3=pot::x(p3),y3=pot::y(p3);
            double x4=pot::x(p4),y4=pot::y(p4);
            double l=max(x1,x3),r=min(x2,x4);
            double t=(l+r)/2;
            double t1=(y1-y2)/(x1-x2)*(t-x1)+y1;
            double t2=(y3-y4)/(x3-x4)*(t-x3)+y3;
            return t1-t2<-1e-5;
             
        }else if(a.typ==0){
            pot::pot p1=plr::pos[a.e->u];
            pot::pot p2=plr::pos[a.e->v];
            return pot::det(p2-p1,pot::pot(b.x,b.y)-p1)>0;
        }else{
            pot::pot p1=plr::pos[b.e->u];
            pot::pot p2=plr::pos[b.e->v];
            return pot::det(p2-p1,pot::pot(a.x,a.y)-p1)<0;
        }
    }
    void solve(){
        lp(i,0,int(plr::all.size()-1)){
            plr::edge*e=plr::all[i];
            if(pot::x(plr::pos[e->u])<pot::x(plr::pos[e->v])){
                ev.push_back(event(1,e,pot::x(plr::pos[e->v])));
                ev.push_back(event(2,e,pot::x(plr::pos[e->u])));
            }
        }
        lp(i,1,questions::q*2){
            ev.push_back(event(i,questions::x[i]));
        }
        sort(ev.begin(),ev.end());
        /*lp(i,0,int(ev.size()-1)){
            if(ev[i].typ==0)
                pf("qu %d %d\n",questions::x[ev[i].qi],
                    questions::y[ev[i].qi]);
            else if(ev[i].typ==1)
                pf("del %d %d\n",ev[i].e->u,ev[i].e->v);
            else pf("ins %d %d\n",ev[i].e->u,ev[i].e->v);
        }*/
        set<node>st;
        lp(i,0,int(ev.size()-1)){
            event&e=ev[i];
            if(e.typ==0){
                node t(e.x,questions::y[e.qi]);
                set<node>::iterator it=st.lower_bound(t);
                if(it==st.end())questions::loc[e.qi]=plr::ws;
                else questions::loc[e.qi]=it->e->rev->bel;
            }else if(e.typ==1){
                node t(e.e);
                st.erase(t);
            }else{
                node t(e.e);
                st.insert(t);
            }
        }
        /*lp(i,1,questions::q*2){
            pf("[%d]\n",questions::loc[i]);
        }*/
    }
}
int main(){
    int m;sf("%d%d",&plr::n,&m);
    lp(i,1,plr::n){
        sf("%d%d",&pot::x(plr::pos[i]),&pot::y(plr::pos[i]));
        pot::x(plr::pos[i])*=2,pot::y(plr::pos[i])*=2;//乘2避免后面询问的小数
    }
    lp(i,1,m){
        int u,v,w;sf("%d%d%d",&u,&v,&w);
        plr::add(u,v,w);
    }
    plr::build();
    mst::build();
    lca::build();
    questions::init();
    locate::solve();
    questions::answer();
    //ps;
    return 0;
}
