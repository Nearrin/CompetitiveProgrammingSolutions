#include<algorithm>
#include<cctype>
#include<climits>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>
#define sf scanf
#define si(a)scanf("%d",&a)
#define pf printf
#define pi(a)printf("%d",a)
#define fr freopen
#define ps for(;;)
#define pb push_back
#define mp make_pair
#define lp(i,a,b)for(int i=a;i<=int(b);++i)
#define rp(i,a,b)for(int i=int(a);i>=b;--i)
#define vp(i,a)for(int i=0;i<int(a.size());++i)
#define wp(i,a)for(int i=int(a.size())-1;i>=0;--i)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
int n,vis[1010],col[1010];
vector<int>to[1010];
int cnt[2],fail;
void dfsinv(int u){
    vis[u]=1;
    col[u]=1-col[u];
    vp(i,to[u]){
        int v=to[u][i];
        if(!vis[v]){
            dfsinv(v);
        }
    }
}
void dfs(int u,int d){
    vis[u]=1;
    ++cnt[d];
    col[u]=d;
    vp(i,to[u]){
        int v=to[u][i];
        if(!vis[v]){
            dfs(v,1-d);
        }else if(col[v]!=1-d){
            fail=1;
        }
    }
}
int main(){
    int T;si(T);
    lp(I,1,T){
        si(n);
        lp(i,1,n)to[i].clear();
        lp(i,1,n)lp(j,1,n){
            int t;si(t);
            if(t==1){
                to[i].push_back(j);
                to[j].push_back(i);
            }
        }
        fail=0;
        lp(i,1,n)vis[i]=0;
        vector<pair<int,int> >he;
        vector<int>lead;
        lp(i,1,n){
            if(!vis[i]){
                cnt[0]=cnt[1]=0;
                dfs(i,0);
                lead.push_back(i);
                he.pb(mp(cnt[0],cnt[1]));
            }
        }
        if(fail)pf("-1\n");
        else{
            static int dp[1010][1010],fr[1010][1010];
            lp(i,1,he.size())lp(j,0,n)dp[i][j]=0;
            dp[0][0]=1;
            lp(i,1,he.size())
                    lp(j,0,n){
                int u=he[i-1].first,v=he[i-1].second;
                if(u<=j&&dp[i-1][j-u]){
                    dp[i][j]=1;
                    fr[i][j]=1;
                }else if(v<=j&&dp[i-1][j-v]){
                    dp[i][j]=1;
                    fr[i][j]=2;
                }
            }
            int ans=-1;
            for(int i=0;i<=n;++i)
                if(dp[he.size()][i])
                    ans=max(ans,(n-i)*i);
            int tmpans;
            for(int i=0;i<=n;++i)
                if(dp[he.size()][i])
                {
                    if(ans==(n-i)*i)
                        tmpans=i;
                }
            lp(i,1,n)vis[i]=0;
             for(int i=he.size();i>=1;--i){
                 int u=he[i-1].first,v=he[i-1].second;
                 if(fr[i][tmpans]==1){
                     tmpans-=u;
                 }else{
                     tmpans-=v;
                     dfsinv(lead[i-1]);

                 }
             }

             lp(i,1,n)pf("%d%c",col[i],i==n?'\n':' ');




        }


    }
    return 0;
}
