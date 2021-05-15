#include<cstdio>
#include<set>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int n,m,ind[500010],oud[500010];
struct edge{
    int u,v,w;
};
#include<iostream>
vector<edge*>to[500010];
vector<edge*>rto[500010];
int dp[500010],rdp[500010];
vector<edge*>eall;
void add(int u,int v){
    edge*tmp=new edge;
    tmp->u=u;
    tmp->v=v;
    to[u].push_back(tmp);
    rto[v].push_back(tmp);
    eall.push_back(tmp);
}
int ans1,ans2=~0u>>1;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        ++ind[v];
        ++oud[u];
    }
    //n+1 S     n+2 T
    int S=n+1,T=n+2;
    for(int i=1;i<=n;++i){
        if(1){
            ++ind[i];
            ++oud[S];
           add(S,i);
        }
        if(1){
            ++oud[i];
            ++ind[T];
            add(i,T);
        }
    }
    vector<int>tps;
    queue<int>qu;
    qu.push(S);
    while(!qu.empty()){
        int u=qu.front();
        qu.pop();
        for(int i=0;i<to[u].size();++i){
            int v=to[u][i]->v;
            --ind[v];
            if(ind[v]==0)
                qu.push(v);
        }
        tps.push_back(u);
    }
    int INF=~0u>>1;
    for(int i=n+1;i>=0;--i){
        int u=tps[i];
        if(u==T){
            dp[u]=0;
        }else{
            dp[u]=-INF;
            for(int i=0;i<to[u].size();++i){
                int v=to[u][i]->v;
                dp[u]=max(dp[u],dp[v]+1);
            }
        }
    }
    for(int i=0;i<=n+1;++i){
        int u=tps[i];
        if(u==S){
            rdp[u]=0;
        }else{
            rdp[u]=-INF;
            for(int i=0;i<rto[u].size();++i){
                int v=rto[u][i]->u;
                rdp[u]=max(rdp[u],rdp[v]+1);
            }
        }
    }
   // cout<<dp[2]<<endl;
   // cout<<rdp[2]<<endl;
    for(int i=0;i<eall.size();++i){
        int u=eall[i]->u,v=eall[i]->v;
        eall[i]->w=dp[v]+rdp[u]+1;
      // cout<<u<<" "<<v<<" "<<eall[i]->w<<endl;
    }
    multiset<int>cut;
    for(int i=0;i<to[S].size();++i){
        cut.insert(to[S][i]->w);
    }
    for(int i=1;i<=n;++i){
        int u=tps[i];
        for(int i=0;i<rto[u].size();++i){
            cut.erase(cut.find(rto[u][i]->w));
        }
        if(cut.size()!=0&&*cut.rbegin()!=-INF&&*cut.rbegin()-2<ans2){
            ans2=*cut.rbegin()-2;
            ans1=u;
        }
        for(int i=0;i<to[u].size();++i)
            cut.insert(to[u][i]->w);
    }
    printf("%d %d\n",ans1,ans2);
    return 0;
}
