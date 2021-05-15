#include <iostream>
#include<vector>
#include<cstdio>
using namespace std;
int t,n,m;
vector<int>to[300010];
int a[300010],b[300010],d[300010];
int dep[300010],prt[300010];
int getlca(int x,int y){
    static int vis[300010];
    for(int i=1;i<=n;++i)
        vis[i]=0;
    for(int i=x;i!=0;i=prt[i])
        vis[i]=1;
    for(int i=y;;i=prt[i])
        if(vis[i]==1)
            return i;
}
void dfs1(int u,int p){
    prt[u]=p;
    dep[u]=dep[p]+1;
    for(int i=0;i<to[u].size();++i){
        int v=to[u][i];
        if(v!=p)
            dfs1(v,u);
    }
}
int main()
{
    dep[0]=-1;
    scanf("%d",&t);
    for(int I=1;I<=t;++I){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i)
            to[i].clear();
        for(int i=1;i<=n-1;++i){
            int x,y;
            scanf("%d%d",&x,&y);
            to[x].push_back(y);
            to[y].push_back(x);
        }
        for(int i=1;i<=m;++i)
            scanf("%d%d%d",&a[i],&b[i],&d[i]);
        dfs1(1,0);
        int maxhehe=-1,maxheheid=-1;
        for(int i=1;i<=m;++i){
            int dd=dep[a[i]]+dep[b[i]]-d[i];
            if(dd<0)dd=0;
            if(dd>maxhehe){
                maxhehe=dd;
                maxheheid=i;
            }
        }
        int ca=a[maxheheid];
        int cb=b[maxheheid];
      //  cout<<ca<<" "<<cb<<endl;
        int lca=getlca(ca,cb);
      //  cout<<lca<<endl;
        int cd=d[maxheheid];
        int already=-dep[lca]+dep[ca]-dep[lca]+dep[cb];
       // cout<<already<<endl;
        while(lca!=1&&already+2<=cd){
            lca=prt[lca];
            already+=2;
        }
   //     cout<<lca<<endl;
        dfs1(lca,0);
        int fail=0;
        for(int i=1;i<=m;++i){
            if(dep[a[i]]+dep[b[i]]>d[i])
                fail=1;
        }
        if(fail)
            printf("NIE\n");
        else
            printf("TAK %d\n",lca);
    }
    return 0;
}
