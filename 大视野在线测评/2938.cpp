#include<cstdio>
#include<algorithm>
#include<vector> 
#include<cstring>
#include<queue>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
namespace acm{
    int ch[30010][2],fa[30010],bc[30010],nw=1;
    char tmp[30010];
    void ins(){
        sf("%s",tmp+1);
        int len=strlen(tmp+1);int u=1;
        for(int i=1;i<=len;++i){
            if(!ch[u][tmp[i]-'0'])
                ch[u][tmp[i]-'0']=++nw;
            u=ch[u][tmp[i]-'0'];
        }
        bc[u]=1;
    }
    void bud(){
        queue<int>qu;
        lp(i,0,1)if(!ch[1][i])ch[1][i]=1;
        else fa[ch[1][i]]=1,qu.push(ch[1][i]);
        while(!qu.empty()){
            int u=qu.front();qu.pop();
             lp(i,0,1)if(!ch[u][i])ch[u][i]=ch[fa[u]][i];
            else{
                fa[ch[u][i]]=ch[fa[u]][i];
                if(bc[ch[fa[u]][i]])
                    bc[ch[u][i]]=1;
                qu.push(ch[u][i]);
            }
        }
    }
    int vis[30010],in[30010];
    bool dfs(int u){
        //pf("[%d]",u);
        vis[u]=1;in[u]=1;
        lp(i,0,1)if(!bc[ch[u][i]]){
            if(vis[ch[u][i]]){
                if(in[ch[u][i]])return true;
            }else if(dfs(ch[u][i]))return true;
        }
        in[u]=0;
        return false;
    }
}
int main(){
    int n;sf("%d",&n);
    lp(i,1,n)acm::ins();
    acm::bud();
    //lp(i,1,acm::nw)pf("[%d,%d]",acm::ch[i][0],acm::ch[i][1]);
    if(acm::dfs(1))pf("TAK\n");
    else pf("NIE\n");
    //ps;
    return 0; 
} 
