#include<bits/stdc++.h>
#define lop(i,a,b) for(auto i=a;i<=b;++i)
#define rlp(i,a,b) for(auto i=a;i>=b;--i)
#define vlp(i,a) for(int i=0;i<a.size();++i)
#define all(a) a.begin(),a.end()
#define sqr(a) ((a)*(a))
#define pub push_back
#define pob pop_back
#define mkp make_pair
#define scf scanf
#define ptf printf
#define inf (~0u>>1)
namespace CTL{}
using namespace CTL;
using namespace std;
typedef long long lli;
typedef unsigned long long ull;
typedef string str;
typedef vector<int> vei;
typedef vector<string> ves;
typedef map<int,int> mii;
typedef map<str,int> msi;
typedef set<int> sti;
typedef set<str> sts;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#define tst int T;scf("%d",&T);while(T--)
int cntu[100010],cntl[100010],n,m,c;
int p=1e9+7;
int cnt[100010],mxr;
int main(){
    scf("%d%d%d",&n,&m,&c);++c;

    lop(i,1,n){
        int t;scf("%d",&t);
        ++cntu[t];
        mxr=max(mxr,t);
    }

    lop(i,1,m){
        int t;scf("%d",&t);
        ++cntl[t];
         mxr=max(mxr,t);
    }
    lop(i,1,mxr)
            cnt[i]=lli(cntu[i])*cntl[i]%p;
   // lop(i,1,mxr)
         //   cout<<cnt[i]<<endl;
    static int dp[100010][1010];
    lop(i,1,mxr){
        lop(j,1,c){
                if(j==1){
                    dp[i][j]=dp[i-1][j]+cnt[i];
                    if(dp[i][j]>=p)dp[i][j]-=p;
                }else{
                    dp[i][j]=lli(dp[i-1][j-1])*cnt[i]%p;
                    dp[i][j]+=dp[i-1][j];
                    if(dp[i][j]>=p)dp[i][j]-=p;
                }
            }
        }


    lop(uc,2,c){
        cout<<dp[mxr][uc]<<" ";

    }
    cout<<endl;
    return 0;
}
