#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<queue>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
vector<int>to[100010],ch[100010];int n;
int vi[100010],iv[100010];
int up[100010][18],dep[100010],siz[100010];
int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    lp(i,0,17)if(((dep[x]-dep[y])>>i)&1)x=up[x][i];
    if(x==y)return x;
    for(int i=17;i>=0;--i)
        if(up[x][i]!=up[y][i])
            x=up[x][i],y=up[y][i];
    return up[x][0];
}
void calc(int u){
    vi[u]=1;siz[u]=1;
    lp(i,0,int(to[u].size()-1))
        if(!vi[to[u][i]])calc(to[u][i]);
    if(to[u].size()){
        int t=to[u][0];
        lp(i,1,int(to[u].size()-1))
            t=lca(t,to[u][i]);
        up[u][0]=t;dep[u]=dep[t]+1;
        ch[t].push_back(u);
        lp(j,1,17)up[u][j]=up[up[u][j-1]][j-1];
    }
}
void clac(int u){
    iv[u]=1;
    lp(i,0,int(ch[u].size()-1))
        if(!iv[ch[u][i]])clac(ch[u][i]);
    lp(i,0,int(ch[u].size()-1))
        siz[u]+=siz[ch[u][i]];
}
int main(){
    sf("%d",&n);
    lp(i,1,n){
        int k;
        while(sf("%d",&k),k)to[i].push_back(k);
    }
    lp(i,1,n)if(!vi[i])calc(i);
    lp(i,1,n)if(!iv[i])clac(i);
    lp(i,1,n)pf("%d\n",siz[i]-1);//ps;
    return 0;
}
/*
5
0
1 0
1 0
2 3 0
2 0 
*/
