#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
namespace mst{
    struct edge{
        edge(){sf("%d%d%d%d",&u,&v,&x,&y);
            ++u,++v;}
        int u,v,x,y;
    };
    int n,m;vector<edge>eg;
    void init(){
        sf("%d%d",&n,&m);
        lp(i,1,m)eg.push_back(edge());
    }
    struct cmp1{
        bool operator()(edge a,edge b){
            return a.x==b.x?a.y<b.y:a.x<b.x;
        }
    };
    struct cmp2{
        bool operator()(edge a,edge b){
            return a.y==b.y?a.x<b.x:a.y<b.y;
        }
    };
    struct cmp3{
        int x,y;
        cmp3(int a,int b):x(a),y(b){}
        bool operator()(edge a,edge b){
            return y*a.x-x*a.y<y*b.x-x*b.y;
        }
    };
    int pr[210];
    int fd(int x){return x==pr[x]?x:pr[x]=fd(pr[x]);}
    template<class T>
    pair<int,int>work(T cmp){
        pair<int,int>r(0,0);
        lp(i,1,n)pr[i]=i;
        sort(eg.begin(),eg.end(),cmp);
        lp(i,0,int(eg.size()-1)){
            int u=eg[i].u,v=eg[i].v,x=eg[i].x,y=eg[i].y;
            if(fd(u)!=fd(v)){
                pr[fd(u)]=v;
                r.first+=x;
                r.second+=y;
            }
        }
        return r;
    }
    pair<int,int>ans(-1,-1);
    void update(pair<int,int>p){
        if(ans.first==-1)ans=p;
        else if(ans.first*ans.second>p.first*p.second)ans=p;
        else if(ans.first*ans.second==p.first*p.second&&ans.first>p.first)ans=p;
    }
    void print(pair<int,int>x){
        pf("(%d,%d)",x.first,x.second);
    }
    pair<int,int>dfs(pair<int,int>p,pair<int,int>q){
        int x=p.first-q.first,y=p.second-q.second;
        pair<int,int>t=work(cmp3(x,y));
        if((t.first-q.first)*y-x*(t.second-q.second)!=0){
            update(t);
            dfs(p,t);
            dfs(t,q);
        }
    }
    void solve(){
        pair<int,int>p=work(cmp1()),q=work(cmp2());
        update(p);update(q);
        if(p!=q)dfs(p,q);
        pf("%d %d\n",ans.first,ans.second);
    }
}
int main(){
    mst::init();
    mst::solve();
    //ps;
    return 0; 
} 
