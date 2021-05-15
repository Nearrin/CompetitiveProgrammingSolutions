#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
struct edge{
    edge(int a,int b,int c):
        u(a),v(b),w(c){}
    int u,v,w;
};
bool operator<(edge a,edge b){
    return a.w<b.w;
}
struct graph{
    vector<edge>es;
    int nc;
};
struct query{
    query(int a,int b):
        t(a),w(b),r(0){}
    int t,w;long long r;
};
vector<query>qs;
int pr[20010];
int fd(int x){return x==pr[x]?x:pr[x]=fd(pr[x]);}
void contract(graph&gr,int ql,int qr){
    static int tm[50010];
    lp(i,0,int(gr.es.size()-1))tm[i]=0;
    lp(i,ql,qr)tm[qs[i].t]=1;
    lp(i,1,gr.nc)pr[i]=i;
    vector<edge>t1,t2;
    lp(i,0,int(gr.es.size()-1)){
        if(tm[i]){
            int u=gr.es[i].u,v=gr.es[i].v;
            if(fd(u)!=fd(v))pr[fd(u)]=v;
        }else{
            t1.push_back(gr.es[i]);
        }
    }
    sort(t1.begin(),t1.end());
    lp(i,0,int(t1.size()-1)){
        int u=t1[i].u,v=t1[i].v;
        if(fd(u)!=fd(v)){
            pr[fd(u)]=v;
            t2.push_back(t1[i]);
        }
    }
    long long dl=0;
    lp(i,1,gr.nc)pr[i]=i;
    lp(i,0,int(t2.size()-1)){
        int u=t2[i].u,v=t2[i].v;
        pr[fd(u)]=v;
        dl+=t2[i].w;
    }
    lp(i,ql,qr)qs[i].r+=dl;
    static int id[50010];
    lp(i,1,gr.nc)id[i]=0;int nw=0;
    lp(i,1,gr.nc)if(id[fd(i)]==0)id[fd(i)]=++nw;
    gr.nc=nw;lp(i,0,int(gr.es.size()-1)){
        gr.es[i].u=id[fd(gr.es[i].u)];
        gr.es[i].v=id[fd(gr.es[i].v)];
    }
}
void reduct(graph&gr,int ql,int qr){
    static int tm[50010];
    lp(i,0,int(gr.es.size()-1))tm[i]=0;
    lp(i,ql,qr)tm[qs[i].t]=1;
    vector<pair<edge,int> >t1;
    lp(i,0,int(gr.es.size()-1))
        if(tm[i]==0)
            t1.push_back(make_pair(gr.es[i],i));
    sort(t1.begin(),t1.end());
    static int bj[50010];
    lp(i,0,int(gr.es.size()-1))bj[i]=0;
    lp(i,1,gr.nc)pr[i]=i;
    lp(i,0,int(t1.size()-1)){
        int u=t1[i].first.u,v=t1[i].first.v;
        if(fd(u)!=fd(v))
            pr[fd(u)]=v;
        else
            bj[t1[i].second]=1;
    }
    vector<edge>t2;static int mp[50010];
    lp(i,0,int(gr.es.size()-1))
        if(bj[i]==0){
            mp[i]=t2.size();
            t2.push_back(gr.es[i]);
        }
    lp(i,ql,qr)qs[i].t=mp[qs[i].t];
    gr.es=t2;
}
void print(graph gr,int ql,int qr){
    pf("{%d}\n",gr.nc);
    lp(i,0,int(gr.es.size()-1))
        pf("{%d,%d,%d}\n",gr.es[i].u,gr.es[i].v,gr.es[i].w);
    lp(i,ql,qr)pf("{%d,%d}\n",qs[i].t,qs[i].w);
}
void solve(graph gr,int ql,int qr){
    //pf("[%d,%d,%d,%lld]\n",ql,qr,gr.nc,qs[ql].r);
    //print(gr,ql,qr);
    contract(gr,ql,qr);
    //pf("[%d,%d,%d,%lld]\n",ql,qr,gr.nc,qs[ql].r);
    //print(gr,ql,qr);
    reduct(gr,ql,qr);
    //pf("[%d,%d,%d,%lld]\n",ql,qr,gr.nc,qs[ql].r);
    //print(gr,ql,qr);
    if(ql!=qr){
        int m=(ql+qr)/2;graph gt=gr;
        lp(i,ql,m)gt.es[qs[i].t].w=qs[i].w;
        solve(gr,ql,m);solve(gt,m+1,qr);
    }else{
        gr.es[qs[ql].t].w=qs[ql].w;
        sort(gr.es.begin(),gr.es.end());
        lp(i,1,gr.nc)pr[i]=i;
        lp(i,0,int(gr.es.size()-1)){
            int u=gr.es[i].u,v=gr.es[i].v,w=gr.es[i].w;
            if(fd(u)!=fd(v)){
                qs[ql].r+=w;
                pr[fd(u)]=v;
            }
        }
    }
}
int main(){
    graph g;int m,q;
    sf("%d%d%d",&g.nc,&m,&q);
    lp(i,1,m){
        int u,v,w;sf("%d%d%d",&u,&v,&w);
        g.es.push_back(edge(u,v,w));
    }
    lp(i,1,q){
        int t,w;sf("%d%d",&t,&w);
        qs.push_back(query(t-1,w));
    }
    solve(g,0,int(qs.size()-1));
    lp(i,0,int(qs.size()-1))pf("%lld\n",qs[i].r);
    return 0;
}
