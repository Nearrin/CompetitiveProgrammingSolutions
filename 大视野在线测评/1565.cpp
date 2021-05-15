#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<utility>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
vector<int>to[21*310];
int wei[21*310],vcnt,del[21*310],in[31*210];
int n,m;
struct edge{
    int v,c;
}edges[1000100];int nw=1;
vector<int>bg[21*310];
void add(int u,int v,int c){
    //pf("[%d,%d,%d]\n",u,v,c);
    ++nw;edge&e=edges[nw];e.v=v,e.c=c;
    bg[u].push_back(nw);
}
int dis[21*310],gap[21*310];
int dfs(int u,int f){
    //pf("[%d,%d,%d]\n",u,f,vcnt);
    if(u==vcnt)return f;
    int g=f;
    lp(i,0,int(bg[u].size()-1)){
        edge&e=edges[bg[u][i]];
        if(e.c&&dis[u]-1==dis[e.v]){
            int t=dfs(e.v,min(g,e.c));
            g-=t,e.c-=t,edges[bg[u][i]^1].c+=t;
            if(!g||dis[1]==vcnt)return f-g;
        }
    }
    if(!--gap[dis[u]])dis[1]=vcnt;
    ++gap[++dis[u]];
    return f-g;
}
int isap(){
    int r=0;gap[1]=vcnt;
    while(dis[1]<vcnt)r+=dfs(1,~0u>>1);
    return r;
}
int main(){
    //fr("pvz.in","r",stdin);
    //fr("pvz.out","w",stdout);
    sf("%d%d",&n,&m);vcnt=m*n;
    lp(i,1,n)lp(j,1,m){
        int t=(i-1)*m+j;
        sf("%d",&wei[t]);
        int cnt;sf("%d",&cnt);
        lp(k,1,cnt){
            int a,b;sf("%d%d",&a,&b);++a,++b;
            int y=(a-1)*m+b;
            to[t].push_back(y);
        }
        if(j!=m)to[(i-1)*m+j+1].push_back(t);
    }
    lp(i,1,vcnt)lp(j,0,int(to[i].size()-1))
        ++in[to[i][j]];
    lp(i,1,vcnt)del[i]=1;
         
    queue<int>qu;lp(i,1,vcnt)if(!in[i])qu.push(i);
    while(!qu.empty()){
        int u=qu.front();qu.pop();del[u]=0;
        lp(i,0,int(to[u].size()-1)){
            int v=to[u][i];
            if((--in[v])==0)
                qu.push(v);
        }
    }//pf("hi");
    //lp(i,1,vcnt)pf("[%d]",del[i]);ps;
    lp(i,1,vcnt){
        if(del[i])continue;
        lp(j,0,int(to[i].size()-1)){
            int v=to[i][j];if(del[v])continue;
            add(v+1,i+1,~0u>>1),add(i+1,v+1,0);
        }
    }//pf("hi");
    lp(i,1,vcnt)if(!del[i]){
        if(wei[i]>0)add(1,i+1,wei[i]),add(i+1,1,0);
        else  add(i+1,vcnt+2,-wei[i]),add(vcnt+2,i+1,0);
    }
    //pf("hi");
    vcnt+=2;
    int sum=0;
    lp(i,1,vcnt)if(!del[i]&&wei[i]>0)sum+=wei[i];
    pf("%d\n",sum-isap());
    //ps;
    return 0;
}
