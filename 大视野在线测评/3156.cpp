#include<cstdio>
#include<algorithm>
#include<deque>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
int n,a[1000010];
ll x[1000010],y[1000010],f[1000010];
int main(){
    sf("%d",&n);
    lp(i,1,n)sf("%d",&a[i]);
    reverse(a+1,a+n+1);
    x[1]=1;y[1]=a[1]+1;f[1]=a[1];
    deque<int>qu;qu.push_back(1);
    lp(i,2,n){
        while(qu.size()>1){
            int j=qu[0],k=qu[1];
            if(f[j]+ll(i-j)*(i-j-1)/2>=f[k]+ll(i-k)*(i-k-1)/2)
                qu.pop_front();
            else break;
        }
        f[i]=f[qu[0]]+ll(i-qu[0])*(i-qu[0]-1)/2+a[i];
        x[i]=i;y[i]=f[i]+i*ll(i+1)/2;
        while(qu.size()>1){
            int j=qu[qu.size()-2],k=qu[qu.size()-1];
            if(double(y[k]-y[j])/(x[k]-x[j])>=double(y[i]-y[k])/(x[i]-x[k]))
                qu.pop_back();
            else break;
        }
        qu.push_back(i);
    }
    ll ans=f[n];
    lp(i,1,n)
        ans=min(ans,f[i]+ll(n-i)*(n-i+1)/2);
    pf("%lld\n",ans);
    //ps;
    return 0;
}
