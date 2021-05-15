#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
namespace bit{
    int db[10010];
    void add(int i,int d){
        for(;i<=10000;i+=i&-i)db[i]+=d;
    }
    int ask(int i){
        int r=0;
        for(;i;i-=i&-i)r+=db[i];
        return r;
    }
}
/*
用整体二分法离线解决区间值排名问题
*/
namespace rank{
    struct query{
        int t;//1:add 2:del 3:ask
        int i,v;
        int l,r,c,w;
    };
    vector<int>as;
    vector<query>qs;
    void add(int i,int v){
        //pf("[add %d,%d]\n",i,v);
        query t;t.t=1;t.i=i;t.v=v;
        qs.push_back(t);
    }
    void del(int i,int v){
        //pf("[del %d,%d]\n",i,v);
        query t;t.t=2;t.i=i;t.v=v;
        qs.push_back(t);
    }
    void ask(int l,int r,int v){
        //pf("[ask %d,%d,%d]\n",l,r,v);
        query t;t.t=3;t.l=l;t.r=r;
        t.c=0;t.v=v;t.w=as.size();
        as.push_back(0);
        qs.push_back(t);
    }
    void work(int ql,int qr,int vl,int vr){
        if(ql<=qr){
            if(vl==vr){
                lp(i,ql,qr)
                    if(qs[i].t==3)
                        as[qs[i].w]=qs[i].c;
            }else{
                int vm=vl+(vr-vl)/2;
                lp(i,ql,qr)
                    if(qs[i].t==1&&qs[i].v<=vm)
                        bit::add(qs[i].i,1);
                    else if(qs[i].t==2&&qs[i].v<=vm)
                        bit::add(qs[i].i,-1);
                    else if(qs[i].t==3&&qs[i].v>vm)
                        qs[i].c+=bit::ask(qs[i].r)-bit::ask(qs[i].l-1);
                lp(i,ql,qr)
                    if(qs[i].t==1&&qs[i].v<=vm)
                        bit::add(qs[i].i,-1);
                    else if(qs[i].t==2&&qs[i].v<=vm)
                        bit::add(qs[i].i,1);
                vector<query>lq,rq;//方便起见写成O(nlgu)的空间复杂度
                lp(i,ql,qr)
                    if(qs[i].v<=vm)lq.push_back(qs[i]);
                    else rq.push_back(qs[i]);
                lp(i,0,int(lq.size()-1))
                    qs[ql+i]=lq[i];
                lp(i,0,int(rq.size()-1))
                    qs[ql+i+lq.size()]=rq[i];
                work(ql,ql+int(lq.size()-1),vl,vm);
                work(ql+lq.size(),qr,vm+1,vr);
            }
        }
    }
    void solve(){
        work(0,int(qs.size()-1),0,10000);
    }
}
set<int>pos[1000010];int n,m,col[10010];
int main(){
    sf("%d%d",&n,&m);
    lp(i,1,n)sf("%d",&col[i]);
    lp(i,1,n){
        int np;
        if(pos[col[i]].empty())np=0;
        else np=*(pos[col[i]].rbegin());
        rank::add(i,np);
        pos[col[i]].insert(i);
    }
    lp(i,1,m){
        char op[11];int u,v;
        sf("%s%d%d",op,&u,&v);
        if(op[0]=='Q'){
            rank::ask(u,v,u);
        }else{
            set<int>::iterator it=pos[col[u]].lower_bound(u),rt=it;++rt;
            if(it==pos[col[u]].begin())
                rank::del(u,0);
            else{
                set<int>::iterator t=it;--t;
                rank::del(u,*t);
            }
            if(rt!=pos[col[u]].end()){
                int np;
                if(it==pos[col[u]].begin())np=0;
                else{
                    set<int>::iterator t=it;--t;
                    np=*t;
                }
                rank::del(*rt,u);
                rank::add(*rt,np);
            }
            pos[col[u]].erase(u);
            col[u]=v;
            pos[col[u]].insert(u);
            it=pos[col[u]].lower_bound(u),rt=it;++rt;
            if(it==pos[col[u]].begin())
                rank::add(u,0);
            else{
                set<int>::iterator t=it;--t;
                rank::add(u,*t);
            }
            if(rt!=pos[col[u]].end()){
                int np;
                if(it==pos[col[u]].begin())np=0;
                else{
                    set<int>::iterator t=it;--t;
                    np=*t;
                }
                rank::del(*rt,np);
                rank::add(*rt,u);
            }
        }
    }
    rank::solve();
    lp(i,0,int(rank::as.size()-1))
        pf("%d\n",rank::as[i]);
    //ps;
    return 0;
} 
