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
typedef long long ll;
int n,a[1000010],b[1000010],v[1000010],p[1000010];
ll w[1000010],t=~0u>>2,ans;
int main(){
    sf("%d",&n);
    lp(i,1,n)sf("%lld",&w[i]),t=min(w[i],t),ans+=w[i];
    lp(i,1,n)sf("%d",&a[i]),p[a[i]]=i;
    lp(i,1,n)sf("%d",&b[i]);
    lp(i,1,n){
        if(!v[i]){
            ll m=~0u>>2;int j=i,len=0;
            do{
                ++len;
                v[j]=1;
                m=min(m,w[j]);
                j=b[p[j]];
            }while(j!=i);
            ans+=min((len-2)*m,(len+1)*t+m);
        }
    }
    pf("%lld\n",ans);
    //ps;
    return 0;
}
