#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#include<utility>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>

int n,s,m,q;
vector<int>to[200010],we[200010];
vector<int>pet;
struct query{
    int id,x,y,b;
};
vector<query>qs;
bool operator<(query a,query b){
    return a.b<b.b;
}

int ans[200010];
int dis[200010];
struct edge{
    int u,v,w;
};
bool operator<(edge a,edge b){
    return a.w<b.w;
}

const int N=200000;
struct UFS{
    int p[N+1],n;
    UFS(int _n):
        n(_n){
        for(int i=1;i<=n;++i)
            p[i]=i;
    }
    int find(int x){
        return p[x]==x?x:p[x]=find(p[x]);
    }
    int link(int x,int y){
        p[find(x)]=y;
    }
};
vector<edge>e1,e2;
int main(){
    scanf("%d%d%d",&n,&s,&m);
    for(int i=1;i<=s;++i){
        int c;scanf("%d",&c);
        pet.push_back(c);
    }
    for(int i=1;i<=m;++i){
        int u,v,d;
        scanf("%d%d%d",&u,&v,&d);
        to[u].push_back(v);
        we[u].push_back(d);
        swap(u,v);
        to[u].push_back(v);
        we[u].push_back(d);
        edge tmp;
        tmp.u=u;
        tmp.v=v;
        tmp.w=d;
        e1.push_back(tmp);
    }
    scanf("%d",&q);
    for(int i=1;i<=q;++i){
        int x,y,b;
        query tmp;
        scanf("%d%d%d",&x,&y,&b);
        tmp.x=x;
        tmp.y=y;
        tmp.b=b;
        tmp.id=i;
        qs.push_back(tmp);
    }
    for(int i=1;i<=n;++i)
        dis[i]=~0u>>1;

    queue<int>qu;
    static int in[200010];
    for(int i=0;i<pet.size();++i){
        dis[pet[i]]=0;
        in[pet[i]]=1;
        qu.push(pet[i]);
    }
    while(!qu.empty()){
        int u=qu.front();
        qu.pop();
        in[u]=0;
        for(int i=0;i<to[u].size();++i){
            int v=to[u][i],w=we[u][i];
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                if(!in[v]){
                    in[v]=1;
                    qu.push(v);
                }
            }
        }
    }
    for(int i=0;i<e1.size();++i){
        int u=e1[i].u,v=e1[i].v,w=e1[i].w;
        if(dis[u]!=~0u>>1&&dis[v]!=~0u>>1){
            w+=dis[u]+dis[v];
            edge tmp=e1[i];
            tmp.w+=dis[u]+dis[v];
            e2.push_back(tmp);
        }
    }
    sort(e2.begin(),e2.end());
    sort(qs.begin(),qs.end());
    int ptr=0;
    UFS*ufs=new UFS(n);
    for(int i=0;i<qs.size();++i){
        int b=qs[i].b;
        while(ptr<e2.size()&&e2[ptr].w<=b){
            int u1=e2[ptr].u;
            int v1=e2[ptr].v;
            if(ufs->find(u1)!=ufs->find(v1))
                ufs->link(u1,v1);
            ++ptr;
        }
        int u=qs[i].x,v=qs[i].y;
        if(ufs->find(u)==ufs->find(v))
            ans[qs[i].id]=1;
        else
            ans[qs[i].id]=0;
    }
    for(int i=1;i<=q;++i)
        printf("%s",ans[i]?"TAK\n":"NIE\n");
    return 0;
}
