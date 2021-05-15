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
int sr,sb,sg,m,n,p,ans;
int inv(int x){
    int r=1;
    for(int i=p-2;i;i>>=1){
        if(i&1)r=r*x%p;
        x=x*x%p;
    }
    return r;
}
int tr[70],vis[70];
int dp[70][30][30][30];
int calc(){
    lp(i,1,n)sf("%d",&tr[i]);
    lp(i,1,n)vis[i]=0;
    vector<int>tmp;
    lp(i,1,n){
        if(!vis[i]){
            int j=i,c=0;
            do{
                vis[j]=1;
                j=tr[j];
                ++c;
            }while(j!=i);
            tmp.pb(c);
        }
    }
    lp(i,1,tmp.size())lp(j,0,sr)lp(k,0,sb)lp(l,0,sg)dp[i][j][k][l]=0;
    dp[0][0][0][0]=1;
    lp(i,1,tmp.size())
        lp(j,0,sr)lp(k,0,sb)lp(l,0,sg){
            int t=tmp[i-1];
            if(t<=j)dp[i][j][k][l]+=dp[i-1][j-t][k][l];
            if(t<=k)dp[i][j][k][l]+=dp[i-1][j][k-t][l];
            if(t<=l)dp[i][j][k][l]+=dp[i-1][j][k][l-t];
            dp[i][j][k][l]%=p;
        }
    return dp[tmp.size()][sr][sb][sg];
}
int calc2(){
    lp(i,1,n)tr[i]=i;
    lp(i,1,n)vis[i]=0;
    vector<int>tmp;
    lp(i,1,n){
        if(!vis[i]){
            int j=i,c=0;
            do{
                vis[j]=1;
                j=tr[j];
                ++c;
            }while(j!=i);
            tmp.pb(c);
        }
    }
    lp(i,1,tmp.size())lp(j,0,sr)lp(k,0,sb)lp(l,0,sg)dp[i][j][k][l]=0;
    dp[0][0][0][0]=1;
    lp(i,1,tmp.size())
        lp(j,0,sr)lp(k,0,sb)lp(l,0,sg){
            int t=tmp[i-1];
            if(t<=j)dp[i][j][k][l]+=dp[i-1][j-t][k][l];
            if(t<=k)dp[i][j][k][l]+=dp[i-1][j][k-t][l];
            if(t<=l)dp[i][j][k][l]+=dp[i-1][j][k][l-t];
            dp[i][j][k][l]%=p;
            //pf("[%d,%d,%d,%d,%d,%d]\n",dp[i][j][k][l],t,i,j,k,l);
        }
    return dp[tmp.size()][sr][sb][sg];
}
int main(){
    sf("%d%d%d%d%d",&sr,&sb,&sg,&m,&p);n=sr+sb+sg;
    lp(i,1,m)ans=(ans+calc())%p;
    ans=(ans+calc2())%p;
    ans=ans*inv(m+1)%p;
    pf("%d\n",ans);
    return 0;
}
