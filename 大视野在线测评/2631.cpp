#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
namespace lct{
    const int nmx=100000;
    int n,ch[nmx+10][2],pr[nmx+10],rv[nmx+10];
    unsigned sz[nmx+10],vl[nmx+10],sm[nmx+10],ta[nmx+10],tb[nmx+10];
    inline void dw(int x){
        if(rv[x]){
            swap(ch[x][0],ch[x][1]);
            if(ch[x][0])rv[ch[x][0]]^=1;
            if(ch[x][1])rv[ch[x][1]]^=1;
            rv[x]=0;
        }
        if(!(ta[x]==1&&tb[x]==0)){
            sm[x]=(sm[x]*ta[x]%51061+sz[x]*tb[x]%51061)%51061;
            vl[x]=(vl[x]*ta[x]+tb[x])%51061;
            if(ch[x][0]){
                ta[ch[x][0]]=ta[ch[x][0]]*ta[x]%51061;
                tb[ch[x][0]]=(tb[ch[x][0]]*ta[x]+tb[x])%51061;
            }
            if(ch[x][1]){
                ta[ch[x][1]]=ta[ch[x][1]]*ta[x]%51061;
                tb[ch[x][1]]=(tb[ch[x][1]]*ta[x]+tb[x])%51061;
            }
            ta[x]=1;tb[x]=0;
        }
    }
    inline void up(int x){
        sm[x]=vl[x];
        sz[x]=1;
        if(ch[x][0]){
            dw(ch[x][0]);
            sm[x]+=sm[ch[x][0]];sm[x]%=51061;
            sz[x]+=sz[ch[x][0]];
        }
        if(ch[x][1]){
            dw(ch[x][1]);
            sm[x]+=sm[ch[x][1]];sm[x]%=51061;
            sz[x]+=sz[ch[x][1]];
        }
    }
    inline int tp(int x){return x!=ch[pr[x]][0];}
    inline void st(int x,int y,int d){
        ch[x][d]=y;
        if(y)pr[y]=x;
        up(x);
    }
    inline void dfs(int x){
        if(x>0){
            dfs(pr[x]);
            dw(x);
        }
    }
    inline void rot(int x){
        int y=pr[x],z=pr[y],d=tp(x),r;if(z>0)r=tp(y);
        st(y,ch[x][!d],d);
        st(x,y,!d);
        if(z>0)st(z,x,r);else pr[x]=z;
    }
    inline void spl(int x){
        dfs(x);
        while(pr[x]>0){
            if(pr[pr[x]]<=0)rot(x);
            else if(tp(x)==tp(pr[x]))rot(pr[x]),rot(x);
            else rot(x),rot(x);
        }
    }
    inline int acc(int x){
        int y=0;
        while(x){
            spl(x);
            if(ch[x][1])pr[ch[x][1]]=-x;
            st(x,y,1);
            y=x;x=-pr[x];
        }
        return y;
    }
    inline void evert(int x){
        acc(x);spl(x);rv[x]=1;
    }
    inline void print(){
        lp(x,1,n){
            pf("ch[%d,%d]",ch[x][0],ch[x][1]);
            pf("pr[%d]",pr[x]);
            pf("tg[%d,%d,%d]",rv[x],ta[x],tb[x]);
            pf("if[%d,%d]\n",sm[x],sz[x]);
        }
        pf("\n\n");
    }
}
int main(){
    int q;
    sf("%d%d",&lct::n,&q);
    static vector<int>to[100010];
    lp(i,1,lct::n-1){
        int u,v;sf("%d%d",&u,&v);
        to[u].push_back(v);
        to[v].push_back(u);
    }
    static int vi[100010];vi[1]=1;
    queue<int>qu;qu.push(1);
    lct::vl[1]=1;lct::ta[1]=1;lct::tb[1]=0;
    lct::sm[1]=1;lct::sz[1]=1;
    while(!qu.empty()){
        int u=qu.front();qu.pop();
        lp(i,0,int(to[u].size()-1)){
            int v=to[u][i];
            if(!vi[v]){
                vi[v]=1;
                lct::vl[v]=1;lct::ta[v]=1;lct::tb[v]=0;
                lct::pr[v]=-u;lct::sm[v]=1;lct::sz[v]=1;
                qu.push(v);
            }
        }
    }
    lp(i,1,q){
        char op[11];sf("%s",op);
        //lct::print();
        if(op[0]=='+'){
            int u,v,c;sf("%d%d%d",&u,&v,&c);
            lct::evert(u);lct::acc(v);
            lct::spl(v);
            lct::tb[v]=c;
        }else if(op[0]=='-'){
            int u1,v1,u2,v2;
            sf("%d%d%d%d",&u1,&v1,&u2,&v2);
            lct::evert(u1);lct::acc(v1);lct::spl(u1);
            lct::pr[v1]=0;lct::ch[u1][1]=0;lct::up(u1);
            lct::evert(u2);lct::pr[u2]=-v2;
        }else if(op[0]=='*'){
            int u,v,c;sf("%d%d%d",&u,&v,&c);
            lct::evert(u);lct::acc(v);
            lct::spl(v);
            lct::ta[v]=c;
        }else{
            int u,v;sf("%d%d",&u,&v);
            lct::evert(u);
            lct::acc(v);
            lct::spl(u);
            pf("%d\n",int(lct::sm[u]));
        }
    }
    //ps;
    return 0;
}
