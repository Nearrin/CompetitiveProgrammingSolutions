#include<cstdio>
#include<algorithm>
#include<vector> 
#include<queue>
#include<utility>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
vector<int>to[10010];int n,m,eng[10010],cod[10010],doc[10010],nw;//coddoc互为反函数 
int main(){
    sf("%d%d",&n,&m);
    lp(i,1,m){
        int a,b;
        sf("%d%d",&a,&b);
        to[a].push_back(b);
        to[b].push_back(a);
    }
    priority_queue<pair<int,int> >qu;//max heap 
    lp(i,1,n)qu.push(make_pair(0,i));nw=n;
    while(!qu.empty()){
        int u=qu.top().second;qu.pop();
        if(cod[u])continue;//不会出现eng[u]!=e的情况，eng总是在增大 
        cod[u]=nw;doc[nw]=u;--nw;
        lp(i,0,int(to[u].size()-1))
            if(!cod[to[u][i]])
                qu.push(make_pair(++eng[to[u][i]],to[u][i]));
    }
    int ans=0;
    lp(i,1,n){
        int u=doc[i],t=1;
        lp(j,0,int(to[u].size()-1))
            t+=(cod[to[u][j]]>cod[u]);
        ans=max(ans,t);
    } 
    //lp(i,1,n)pf("[%d]",doc[i]);
    pf("%d\n",ans);//ps;
    return 0;
}
/*
4 5
1 2
2 4
4 3
3 1
1 4
*/
