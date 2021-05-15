#include<cstdio>
#include<algorithm>
#include<queue>
#include<set>
#include<iostream>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long ll;
ll f[100010];
int main(){
    //fr("energy2010.in","r",stdin);
    //fr("energy2010.out","w",stdout);
    ll n,m;cin>>n>>m;
    for(int i=min(n,m);i;--i){
        f[i]=ll(n/i)*ll(m/i);
        for(int j=i+i;j<=min(n,m);j+=i)
            f[i]-=f[j];
    }
    ll ans=0;
    lp(i,1,min(n,m))ans+=f[i]*i;
    cout<<2*ans-n*m<<endl;
    //ps;
    return 0;
}
