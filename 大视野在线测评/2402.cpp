#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<complex>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define pb push_back
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
struct point{
    point(double a=0,double b=0):
        x(a),y(b){}
    double x,y;
};
inline double operator*(const point&a,const point&b){
    return a.x*b.y-b.x*a.y;
}
inline point operator-(const point&a,const point&b){
    return point(a.x-b.x,a.y-b.y);
}
inline double myabs(double a){
    return a<0?-a:a;
}
inline bool operator<(const point&a,const point&b){
    return myabs(a.x-b.x)<1e-8?a.y<b.y:a.x<b.x;
}
int n,q,dep[30010],siz[30010],prt[30010],chd[30010],dfn[30010],top[30010],nw;
vector<int>to[30010];point pot[30010][2],pts[30010][2];
inline void dfs1(int u){
    siz[u]=1;
    lp(i,0,int(to[u].size()-1)){
        int v=to[u][i];
        if(v!=prt[u]){
            dep[v]=dep[u]+1;
            prt[v]=u;
            dfs1(v);
            siz[u]+=siz[v];
            if(siz[v]>siz[chd[u]])
                chd[u]=v;
        }
    }
}
inline void dfs2(int u,int w){
    dfn[u]=++nw;pts[nw][0]=pot[u][0];pts[nw][1]=pot[u][1];
    top[u]=w;
    if(chd[u])dfs2(chd[u],w);
    lp(i,0,int(to[u].size()-1)){
        int v=to[u][i];
        if(v!=prt[u]&&v!=chd[u])
            dfs2(v,v);
    }
}
vector<point>seg[30010*4][2];
inline void build(int x,int l,int r){
    if(l==r){
        lp(i,0,1)seg[x][i].push_back(pts[l][i]);
    }else{
        int m=(l+r)/2;
        build(x*2,l,m);
        build(x*2+1,m+1,r);
        lp(i,0,1){
            seg[x][i].resize(seg[x*2][i].size()+seg[x*2+1][i].size());
            merge(seg[x*2][i].begin(),seg[x*2][i].end(),seg[x*2+1][i].begin(),seg[x*2+1][i].end(),seg[x][i].begin());
            vector<point>tmp;
            lp(j,0,int(seg[x][i].size()-1)){
                point t=seg[x][i][j];
                while(tmp.size()>1){
                    point t1=tmp[tmp.size()-2],t2=tmp[tmp.size()-1];
                    if((t-t1)*(t2-t1)<1e-8)
                        tmp.pop_back();
                    else
                        break;
                }
                tmp.pb(t);
            }
            seg[x][i]=tmp;
        }
    }
    /*pf("[%d,%d,%d]\n",x,l,r);
    lp(i,0,1){
        lp(j,0,int(seg[x][i].size()-1)){
            pf("(%.2lf,%.2lf)",seg[x][i][j].x,seg[x][i][j].y);
        }
        pf("\n");
    }*/
}
inline pair<double,double>ask(int x,int l,int r,int b,int e,double k){
    if(b<=l&&e>=r){
        double ret[2]={-1e100,-1e100};
        lp(i,0,1){
            int left=0,right=int(seg[x][i].size()-1);
            while(right-left>=3){
                int del=(right-left)/3;
                int mid1=left+del,mid2=mid1+del;
                if(seg[x][i][mid1].y-seg[x][i][mid1].x*k>seg[x][i][mid2].y-seg[x][i][mid2].x*k)
                    right=mid2;
                else
                    left=mid1;
            }
            lp(j,left,right)ret[i]=max(ret[i],seg[x][i][j].y-seg[x][i][j].x*k);
        }
        return make_pair(ret[0],ret[1]);
    }else{
        pair<double,double>ret(-1e100,-1e100);
        int m=(l+r)/2;
        if(b<=m){
            pair<double,double>t=ask(x*2,l,m,b,e,k);
            ret.first=max(ret.first,t.first);
            ret.second=max(ret.second,t.second);
        }
        if(e>m){
            pair<double,double>t=ask(x*2+1,m+1,r,b,e,k);
            ret.first=max(ret.first,t.first);
            ret.second=max(ret.second,t.second);
        }
        return ret;
    }
}
inline void upda(pair<double,double>&a,const pair<double,double>&b){
    a.first=max(a.first,b.first);
    a.second=max(a.second,b.second);
}
inline double query(int u,int v,double k){
    pair<double,double>ret(-1e100,-1e100);
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        upda(ret,ask(1,1,n,dfn[top[u]],dfn[u],k));
        u=prt[top[u]];
    }
    if(dep[u]<dep[v])swap(u,v);
    upda(ret,ask(1,1,n,dfn[v],dfn[u],k));
    return ret.first+ret.second;
}
int main(){
    sf("%d",&n);
    lp(i,1,n)sf("%lf",&pot[i][0].x);
    lp(i,1,n)sf("%lf",&pot[i][0].y);
    lp(i,1,n)sf("%lf",&pot[i][1].x);
    lp(i,1,n)sf("%lf",&pot[i][1].y);
    lp(i,1,n-1){
        int u,v;sf("%d%d",&u,&v);
        to[u].pb(v);to[v].pb(u);
    }
    dfs1(1);
    dfs2(1,1);
    //lp(i,1,n)pf("[%d,%d,%d,%d,%d,%d]\n",dep[i],siz[i],prt[i],chd[i],dfn[i],top[i]);
    build(1,1,n);
    sf("%d",&q);
    /*lp(i,1,q){
        int a,b;double c;sf("%d%d%lf",&a,&b,&c);
        pf("[%lf,%lf]\n",ask(1,1,n,a,b,c).first, ask(1,1,n,a,b,c).second);
    }*/
    lp(i,1,q){
        int a,b;sf("%d%d",&a,&b);
        double left=0,right=100000000;
        while(right-left>1e-4){
            double mid=(left+right)/2;
            if(query(a,b,mid)>-1e-8)
                left=mid;
            else
                right=mid;
        }
        pf("%.8lf\n",left);
    }
    //ps;
    return 0;
}
