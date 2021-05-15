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
int n,a[1010],b[1010],c[1010];
vector<int>ans[1010];
void merge(vector<int>&dp,int i){
    int ci=c[i];
    vector<int>tc;
    for(int j=1;j<=ci;j*=2)tc.pb(j),ci-=j;
    if(ci)tc.pb(ci);
    vp(j,tc){
        int ta=tc[j]*a[i],tb=tc[j]*b[i];
        rp(k,1000,ta)dp[k]=max(dp[k],dp[k-ta]+tb);
    }
}
void solve(int l,int r,vector<int>dp){
    if(l==r)ans[l]=dp;
    else{
        int m=(l+r)/2;
        vector<int>dpl=dp,dpr=dp;
        lp(i,l,m)merge(dpr,i);
        lp(i,m+1,r)merge(dpl,i);
        solve(l,m,dpl);
        solve(m+1,r,dpr);
    }
}
int main(){
    sf("%d",&n);
    lp(i,1,n)sf("%d%d%d",&a[i],&b[i],&c[i]);
    solve(1,n,vector<int>(1010,0));
    int q;sf("%d",&q);
    lp(i,1,q){
        int d,e;sf("%d%d",&d,&e);
        pf("%d\n",ans[d+1][e]);
    }
    //ps;
    return 0;
}
