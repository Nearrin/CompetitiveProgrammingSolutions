#include<cstdio>
#include<algorithm>
#include<vector>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
struct edge{int v,c;}edges[200010];int nw=1;
vector<int>bg[310];
void add(int u,int v,int c){edges[++nw].v=v;edges[nw].c=c;bg[u].push_back(nw);}
int di[310],vcnt;
int dfs(int u,int f){
    if(u==vcnt)return f;
    int g=f;
    lp(i,0,int(bg[u].size()-1)){
        edge&e=edges[bg[u][i]];
        if(e.c&&di[u]==di[e.v]+1){
            int t=dfs(e.v,min(g,e.c));
            g-=t,e.c-=t,edges[bg[u][i]^1].c+=t;
            if(!g)return f-g;
        }
    }
    ++di[u];
    return f-g;
}
int isap(){int r=0;while(di[1]<vcnt)r+=dfs(1,~0u>>2);return r;}
int n,m;
int main(){
    sf("%d%d",&n,&m);vcnt=n+2;
    lp(i,1,n){
        int t;sf("%d",&t);
        if(t)add(i+1,n+2,1),add(n+2,i+1,0);
        else add(i+1,1,0),add(1,i+1,1);
    }
    lp(i,1,m){
        int a,b;sf("%d%d",&a,&b);
        add(a+1,b+1,1);
        add(b+1,a+1,1);
    }
    pf("%d\n",isap());//ps;
    return 0;
}
