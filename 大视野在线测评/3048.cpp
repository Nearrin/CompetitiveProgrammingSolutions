#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define pb push_back
#define mp make_pair
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
#define vp(i,v) for(int i=0;i<v.size();++i)
#define wp(i,v) for(int i=int(v.size()-1);i>=0;--i)
typedef long long ll;
using namespace std;
#include<map>
#include<set>
int a[100010],n,k,ans;
map<int,int>cnt;
int main(){
    sf("%d%d",&n,&k);
    lp(i,1,n)sf("%d",&a[i]);
    for(int i=1,j=0,u=0;i<=n;++i){
        while(j+1<=n&&(cnt[a[j+1]]||u<=k)){
            if((++cnt[a[j+1]])==1)++u;
            ++j;
        }
        ans=max(ans,cnt[a[i]]);
        if((--cnt[a[i]])==0)--u;
    }
    pf("%d\n",ans);
    //ps;
    return 0;
}    
