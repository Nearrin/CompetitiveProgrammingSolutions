#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define pb push_back
#define mp make_pair
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
#define vp(i,v) for(int i=0;i<v.size();++i)
#define wp(i,v) for(int i=int(v.size()-1);i>=0;--i)
typedef long long ll;
using namespace std;
namespace input{
    int n,a[310][310],b[310][310];
    void run(){
        sf("%d",&n);
        lp(i,1,n)lp(j,1,n)sf("%d",&a[i][j]);
        lp(i,1,n)lp(j,1,n)sf("%d",&b[i][j]);
    }
}
namespace gauss{
    int n;double a[310][610];
    double eps=1e-6;
    double myabs(double x){
        return x>0?x:-x;
    }
    void prtmat(){
        lp(i,1,n){
            lp(j,1,2*n)pf("%lf%c",a[i][j],j==2*n?'\n':' ');
        }
        pf("\n");
    }
    bool run(){
        //prtmat();
        lp(i,1,n){
            int j;for(j=i;j<=n;++j)if(myabs(a[j][i])>eps)break;
            if(j==n+1)return false;
            lp(k,1,2*n)swap(a[i][k],a[j][k]);
            double t=a[i][i];
            lp(k,1,2*n)a[i][k]/=t;
            lp(k,1,n)if(k!=i){
                t=a[k][i];
                lp(l,1,2*n)a[k][l]-=t*a[i][l];
            }
            //prtmat();
        }
        return true;
    }
}
namespace hungary{
    int n;vector<int>to[310];int lk[310],vis[310],ans[310];
    void add(int u,int v){
        to[u].pb(v);
        //pf("[%d,%d]\n",u,v);
    }
    int dfs(int u,int lim=0){
        vp(i,to[u]){
            int v=to[u][i];
            if(!vis[v]){
                vis[v]=1;
                if(!lk[v]||(lk[v]>lim&&dfs(lk[v],lim))){
                    lk[v]=u;ans[u]=v;
                    return 1;
                }
            }
        }
        return 0;
    }
    bool run(){
        //lp(i,1,n)vp(j,to[i])pf("[%d,%d]\n",i,to[i][j]);
        lp(i,1,n){
            lp(j,1,n)vis[j]=0;
            if(!dfs(i))return false;
        }
        lp(i,1,n)sort(to[i].begin(),to[i].end());
        lp(u,1,n){
            //lp(j,1,n)pf("[%d]",ans[j]);pf("\n");
            vp(i,to[u]){
                int v=to[u][i];
                if(lk[v]==u)break;
                if(lk[v]<u)continue;
                int w=ans[u];ans[u]=0;
                lk[w]=0;
                lp(j,1,n)vis[j]=0;
                vis[v]=1;
                if(dfs(lk[v],u)){
                    ans[u]=v;
                    lk[v]=u;
                    break;
                }
                ans[u]=w;
                lk[w]=u;
            }
            //lp(j,1,n)pf("[%d]",ans[j]);pf("\n\n");
        }
        return true;
    }
}
int main(){
    input::run();
    gauss::n=input::n;
    lp(i,1,input::n){
        lp(j,1,input::n)gauss::a[i][j]=input::a[j][i];
        gauss::a[i][input::n+i]=1;
    }
    if(!gauss::run())pf("NIE\n");
    else{
        hungary::n=input::n;
        lp(i,1,input::n){
            lp(j,1,input::n){
                double t=0;
                lp(k,input::n+1,2*input::n)
                    t+=input::b[i][k-input::n]*gauss::a[j][k];
                if(gauss::myabs(t)>gauss::eps)hungary::add(j,i);
            }
        }
        if(!hungary::run())pf("NIE\n");
        else{
            pf("TAK\n");
            lp(i,1,input::n)pf("%d\n",hungary::ans[i]);
        }
    }
    return 0;
}
