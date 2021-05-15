#include<cstdio>
#include<algorithm>
#include<vector> 
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
int pr[400010],n,m,q,dl[400010];
vector<int>to[400010],qs;
int fd(int x){return x==pr[x]?x:pr[x]=fd(pr[x]);}
int main(){
    sf("%d%d",&n,&m);
    lp(i,1,m){
        int u,v;sf("%d%d",&u,&v);
        to[u+1].push_back(v+1);
        to[v+1].push_back(u+1); 
    }
    sf("%d",&q);
    lp(i,1,n)pr[i]=i;
    lp(i,1,q){
        int u;sf("%d",&u);
        qs.push_back(u+1);
        dl[u+1]=1;
    }
    int ans=0;
    lp(i,1,n)if(!dl[i]){
        lp(j,0,int(to[i].size()-1)){
            if(!dl[to[i][j]]){
                int u=i,v=to[i][j];
                if(fd(u)!=fd(v)){
                    pr[fd(u)]=v;
                }
            }
        }
    }
    vector<int>aas;
    lp(i,1,n)if(!dl[i]&&pr[i]==i)++ans;
    rp(i,int(qs.size()-1),0){
        aas.push_back(ans);
        ++ans;
        int u=qs[i];dl[u]=0;
        lp(j,0,int(to[u].size()-1)){
            int v=to[u][j];
            if(!dl[v]){
                if(fd(u)!=fd(v)){
                    pr[fd(u)]=v;
                    --ans;
                }
            }
        }
    }
    aas.push_back(ans);
    rp(i,int(aas.size()-1),0)
        pf("%d\n",aas[i]);
    //ps;
    return 0; 
}
