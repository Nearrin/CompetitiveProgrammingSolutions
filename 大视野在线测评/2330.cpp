#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
vector<int>to[100010],we[100010];int n,m;
int in[100010],dis[100010],cnt[100010];
void add(int u,int v,int w){
    to[u].push_back(v);
    we[u].push_back(w);
}
int main(){
    sf("%d%d",&n,&m);
    lp(i,1,m){
        int x,a,b;sf("%d%d%d",&x,&a,&b);
        if(x==1){
            add(a,b,0);add(b,a,0); 
        }else if(x==2){
            add(a,b,1);
        }else if(x==3){
            add(b,a,0);
        }else if(x==4){
            add(b,a,1);
        }else{
            add(a,b,0);
        }
    }
    lp(i,1,n)add(n+1,i,1);
    lp(i,1,n+1)reverse(to[i].begin(),to[i].end()),
        reverse(we[i].begin(),we[i].end());
    deque<int>qu;qu.push_back(n+1);in[n+1]=1;
    int f=1;
    while(!qu.empty()){
        int u=qu.front();qu.pop_front();in[u]=0;
        lp(i,0,int(to[u].size()-1)){
            int v=to[u][i],w=we[u][i];
            if(dis[v]<dis[u]+w){
                dis[v]=dis[u]+w;
                if(!in[v]){
                    if(++cnt[v]>=n+1){f=0;goto ok;}
                    in[v]=1;
                    if (qu.empty() || dis[v] < dis[qu.front()]) qu.push_back(v);
                    else qu.push_front(v);
                }
            }
        }
    }
    ok:
    long long ans=0;lp(i,1,n)ans+=dis[i];
    pf("%lld\n",f?ans:(long long)(-1));
    return 0;
}
