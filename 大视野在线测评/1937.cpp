#include<cstdio>
#include<algorithm>
#include<stack>
#include<utility>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
namespace km{
    int w[1010][1010],cx,cy,lx[1010],ly[1010],vix[1010],viy[1010],lk[1010];
    int dfs(int x){
        vix[x]=1;
        lp(y,1,cy)if(!viy[y]&&lx[x]+ly[y]==w[x][y]){
            viy[y]=1;
            if(!lk[y]||dfs(lk[y])){
                lk[y]=x;return 1;
            }
        }
        return 0;
    } 
    void upd(){
        int d=~0u>>1;
        lp(i,1,cx)if(vix[i])
            lp(j,1,cy)if(!viy[j])
                d=min(d,lx[i]+ly[j]-w[i][j]);
        lp(i,1,cx)if(vix[i])lx[i]-=d;
        lp(i,1,cy)if(viy[i])ly[i]+=d;
    }
    void mch(){
        lp(i,1,cy){
            ly[i]=-(~0u>>1);
            lp(j,1,cx)ly[i]=max(ly[i],w[j][i]);
        }
        lp(i,1,cx){
            while(true){
                lp(j,1,cx)vix[j]=0;
                lp(j,1,cy)viy[j]=0;
                if(dfs(i))break;
                else upd();
            }
        }
    }
}
int eg[110][110],we[110][110],he[110][110],id[110][110],n,m;
#define mp make_pair
#define pb push
stack<pair<int,int> >stk;
int dfs(int fr,int to,int p){
    if(fr==to)return 1;
    lp(i,1,n)if(he[fr][i]&&i!=p){
        stk.pb(mp(i,fr));
        if(dfs(i,to,fr))return 1;
        stk.pop();
    }
    return 0;
}
int main(){
    sf("%d%d",&n,&m);
    lp(i,1,m){
        int u,v,w;sf("%d%d%d",&u,&v,&w);
        eg[u][v]=eg[v][u]=1;
        we[u][v]=we[v][u]=w;
    }
    lp(i,1,n-1){
        int u,v;sf("%d%d",&u,&v);
        he[u][v]=he[v][u]=1;
    }
    lp(i,1,n)
        lp(j,i+1,n)
            if(eg[i][j]){
                if(he[i][j])id[i][j]=id[j][i]=++km::cx;
                else id[i][j]=id[j][i]=++km::cy;
            }
    while(km::cx<km::cy)++km::cx;
    while(km::cy<km::cx)++km::cy;
    lp(i,1,n)
        lp(j,i+1,n)
            if(eg[i][j]&&!he[i][j]){
                stk=stack<pair<int,int> >();
                dfs(i,j,0);
                while(!stk.empty()){
                    int iy=id[i][j],ix=id[stk.top().first][stk.top().second];
                    km::w[ix][iy]=max(0,we[stk.top().first][stk.top().second]-we[i][j]);
                    stk.pop();
                }
            }
    int ans=0;km::mch();
    lp(i,1,km::cx)ans+=km::lx[i];//,pf("[%d]",km::lx[i]);pf("\n");
    lp(i,1,km::cy)ans+=km::ly[i];//,pf("[%d]",km::ly[i]);
    pf("%d\n",ans);//ps;
    return 0; 
}
