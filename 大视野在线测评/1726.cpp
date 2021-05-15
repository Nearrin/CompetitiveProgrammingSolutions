#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<queue>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
vector<int>to[5010],we[5010];
int in[5010],f[5010][2],n,m;
int main(){
    sf("%d%d",&n,&m);
    lp(i,1,m){
        int u,v,w;sf("%d%d%d",&u,&v,&w);
        to[u].push_back(v);we[u].push_back(w);
        to[v].push_back(u);we[v].push_back(w);
    }
    lp(i,1,n)f[i][0]=f[i][1]=~0u>>1;
    f[1][0]=0;
    queue<int>qu;qu.push(1);in[1]=1;
    while(!qu.empty()){
        int u=qu.front();qu.pop();in[u]=0;
        lp(i,0,int(to[u].size()-1)){
            int v=to[u][i],w=we[u][i];
            vector<int>tmp;
            tmp.push_back(f[v][0]);
            tmp.push_back(f[v][1]);
            if(f[u][0]!=~0u>>1)
                tmp.push_back(f[u][0]+w);
            if(f[u][1]!=~0u>>1)
                tmp.push_back(f[u][1]+w);
            sort(tmp.begin(),tmp.end());
            unique(tmp.begin(),tmp.end());
            if(tmp[0]!=f[v][0]||tmp[1]!=f[v][1]){
                f[v][0]=tmp[0];
                f[v][1]=tmp[1];
                //pf("[%d,%d,%d]\n",v,f[v][0],f[v][1]);
                if(!in[v]){
                    in[v]=1;
                    qu.push(v); 
                } 
            }
        }
    }
    pf("%d\n",f[n][1]);
    //ps;
    return 0;
}
