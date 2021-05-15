#include<cstdio>
#include<iostream>
using namespace std;

#include<algorithm>
#include<queue>
#include<vector>
template<class FLOW=int,class COST=int>struct MCMF{
    struct edge{
        edge(int _v,FLOW _c,COST _w):
            v(_v),c(_c),w(_w){}
        int v;
        FLOW c;
        COST w;
    };
    int n,src,snk;
    vector<vector<int> >bg;
    vector<edge>eg;
    vector<int>vis;
    vector<COST>dis;
    FLOW all,flow;
    COST cost;
    MCMF(int _n,int _src,int _snk,FLOW _all):
        n(_n),src(_src-1),snk(_snk-1),bg(_n),vis(n),dis(n),all(_all),flow(0),cost(0){}
    void add(int u,int v,FLOW c,COST w){
        bg[u-1].push_back(eg.size());
        eg.push_back(edge(v-1,c,w));
        bg[v-1].push_back(eg.size());
        eg.push_back(edge(u-1,0,-w));
    }
    int spfa(){
        vector<int>in(n,0);
        queue<int>qu;
        fill(vis.begin(),vis.end(),0);
        dis[src]=0;
        vis[src]=in[src]=1;
        qu.push(src);
        while(!qu.empty()){
            int u=qu.front();
            qu.pop();
            in[u]=0;
            for(int i=0;i<bg[u].size();++i){
                edge&e=eg[bg[u][i]];
                if(e.c>0&&(!vis[e.v]||dis[u]+e.w<dis[e.v])){
                    dis[e.v]=dis[u]+e.w;
                    vis[e.v]=1;
                    if(!in[e.v]){
                        in[e.v]=1;
                        qu.push(e.v);
                    }
                }
            }
        }
        return vis[snk]&&dis[snk]<0;
    }
    FLOW dfs(int u,FLOW f){
        if(u==snk)
            return f;
        FLOW g=f;
        vis[u]=1;
        for(int i=0;i<bg[u].size();++i){
            edge&e=eg[bg[u][i]],&ev=eg[bg[u][i]^1];
            if(e.c>0&&dis[e.v]==dis[u]+e.w&&!vis[e.v]){
                FLOW t=dfs(e.v,min(g,e.c));
                g-=t;
                e.c-=t;
                ev.c+=t;
                cost+=t*e.w;
                if(g<=0)
                    return f;
            }
        }
        return f-g;
    }
    void run(){
        while(all>0&&spfa()){
            FLOW t;
            do{
                fill(vis.begin(),vis.end(),0);
                flow+=(t=dfs(src,all));
                all-=t;
            }while(t>0);
        }
    }
};
int main(){
    static int dis[110][110];
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        for(int i=1;i<=n;++i)
            for(int j=i+1;j<=n+1;++j)
                scanf("%d",&dis[i][j]);
        int src=2*n+2,snk=2*n+3;
        static int head[110],tail[110];
        for(int i=2;i<=n+1;++i)
            head[i]=2*i-2,tail[i]=2*i-1;
        MCMF<int,long long>mcmf(2*n+3,src,snk,~0u>>1);
        mcmf.add(src,1,k,0);
        for(int i=2;i<=n+1;++i){
            mcmf.add(head[i],tail[i],1,(long long)(-1e12));
            mcmf.add(tail[i],snk,1,0);
            mcmf.add(1,head[i],1,dis[1][i]);
            for(int j=i+1;j<=n+1;++j)
                mcmf.add(tail[i],head[j],1,dis[i][j]);
        }
        mcmf.run();
        //cout<<mcmf.flow<<endl;
        //cout<<mcmf.cost<<endl;
        int ans=int(mcmf.cost+(long long)(1e12)*n);
        printf("%d\n",ans);}
    return 0;
}
