#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define sf scanf
#define pf printf
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int T,R,P,S;
vector<int> E[2][25010],W[2][25010];
int Belong[25010],Calced[25010],Tot,Dis[25010];
int SetBg[25010],SetNxt[25010],SetNa[25010],SetTot;
void dfs(int x,int s){
    if(Belong[x]==0){
        Belong[x]=s;
        SetNa[++SetTot]=x;
        SetNxt[SetTot]=SetBg[s];
        SetBg[s]=SetTot;
        lp(i,0,int(E[0][x].size())-1)
            dfs(E[0][x][i],s);
    }
}
struct node{
    node(int x,int y):u(x),d(y){}
    int u,d;
};
bool operator<(node a,node b){
    return a.d>b.d;
}
void dijkstra(int s){
    priority_queue<node> q;
    for(int p=SetBg[s];p;p=SetNxt[p])
        if(Dis[SetNa[p]]!=1500000000)
            q.push(node(SetNa[p],Dis[SetNa[p]]));
    while(!q.empty()){
        node t=q.top();
        q.pop();
        if(t.d==Dis[t.u]){
            lp(i,0,int(E[0][t.u].size())-1){
                int v=E[0][t.u][i],w=W[0][t.u][i];
                if(Dis[t.u]+w<Dis[v]){
                    Dis[v]=Dis[t.u]+w;
                    q.push(node(v,Dis[v]));
                }
            }
        }
    }
}
void calc(int s){
    if(!Calced[s]){
        Calced[s]=1;
        for(int p=SetBg[s];p;p=SetNxt[p])
            lp(j,0,int(E[1][SetNa[p]].size())-1){
                calc(Belong[E[1][SetNa[p]][j]]);
                if(Dis[E[1][SetNa[p]][j]]!=1500000000)
                    Dis[SetNa[p]]=min(Dis[SetNa[p]],Dis[E[1][SetNa[p]][j]]+W[1][SetNa[p]][j]);
            }
        dijkstra(s);
    }
}
int main(){
    sf("%d%d%d%d",&T,&R,&P,&S);
    lp(i,1,R){
        int a,b,c;
        sf("%d%d%d",&a,&b,&c);
        E[0][a].push_back(b);
        W[0][a].push_back(c);
        E[0][b].push_back(a);
        W[0][b].push_back(c);
    }
    lp(i,1,P){
        int a,b,c;
        sf("%d%d%d",&a,&b,&c);
        E[1][b].push_back(a);
        W[1][b].push_back(c);
    }
    lp(i,1,T)
        if(Belong[i]==0)
            dfs(i,++Tot);
    lp(i,1,T)
        Dis[i]=1500000000;
    Dis[S]=0;
    lp(i,1,Tot)
        calc(i);
    lp(i,1,T)
        if(Dis[i]==1500000000)
            pf("NO PATH\n");
        else
            pf("%d\n",Dis[i]);
    //ps;
    return 0;
}
