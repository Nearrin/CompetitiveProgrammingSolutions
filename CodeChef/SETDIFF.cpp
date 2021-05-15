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
template<class VAL,class POW,class MOD>inline VAL ModularPower(VAL a,POW b,const MOD&c){
    VAL r=1;
    for(;b!=POW(0);b>>=1,a=a*a%c)
        if(b%POW(2)==1)
            r=r*a%c;
    return r;
}
ll md=1e9+7;
int main(){
    int T;si(T);
    lp(TT,1,T){
        int n;si(n);
        static ll a[100010];
        lp(i,1,n)sf("%lld",a+i);
        ll ans=0;
        sort(a+1,a+n+1);
        lp(i,1,n){
            ans+=ModularPower(2ll,i-1,md)*a[i]%md;
            ans-=ModularPower(2ll,n-i,md)*a[i]%md;
            ans+=md;
            ans%=md;
        }
        cout<<ans<<endl;
    }

    return 0;
}
