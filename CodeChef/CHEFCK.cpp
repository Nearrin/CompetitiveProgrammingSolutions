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
int main(){
    ll n,k,q;
    sf("%lld%lld%lld",&n,&k,&q);
    ll a,b,c,d,e,f,r,s,t,m,a1;
    sf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f,&r,&s,&t,&m,&a1);
    ll l1,la,lc,lm,d1,da,dc,dm;
    sf("%lld%lld%lld%lld%lld%lld%lld%lld",&l1,&la,&lc,&lm,&d1,&da,&dc,&dm);
    static ll A[10000010];
    A[1]=a1;
    ll tpi=t%s;
    for(ll i=2;i<=n;++i){
        tpi=ll(tpi)*t%s;
       ll ax2=ll(A[i-1])*A[i-1]%m;
       ll ax1=A[i-1]%m;
        if(tpi<=r){
            A[i]=(ll(a)*ax2%m+ll(b)*ax1%m+c)%m;
        }else{
            A[i]=(ll(d)*ax2%m+ll(e)*ax1%m+f)%m;
        }
    }
   // lp(i,1,n)cout<<A[i]<<" ";cout<<endl;
    static ll front[10000010],back[10000010];
    static ll q1[10000010],q2[10000010],ds,dt;

    dt=1,ds=0;
    for(ll i=1;i<=n;++i){
        while(ds!=0&&q1[ds]>=A[i])
            --ds;
        q1[++ds]=A[i];
        q2[ds]=i;
        while(i-q2[dt]+1>k)
            ++dt;
        front[i]=q1[dt];
    }
  // lp(i,1,n)cout<<front[i]<<" ";cout<<endl;


    dt=1,ds=0;
    for(ll i=n;i>=1;--i){
        while(ds!=0&&q1[ds]>=A[i])
            --ds;
        q1[++ds]=A[i];
        q2[ds]=n-i+1;
        while(n-i+1-q2[dt]+1>k)
            ++dt;
        back[i]=q1[dt];
    }
 //lp(i,1,n)cout<<back[i]<<" ";cout<<endl;


    ll sum=0;
   ll mul=1;

    for(ll i=1;i<=q;++i){
        l1 = (ll(la) *l1 +lc) % lm;
            d1 = (ll(da) * d1 + dc) % dm;
           ll l = l1 + 1;
            ll r = min(l + k - 1 + d1, n);
           // cout<<l<<" "<<r<<endl;
          ll hehe=min(back[l],front[r]);
            sum+=hehe;
            mul=ll(mul)*hehe%ll(1e9+7);
    }
    cout<<sum<<" "<<mul<<endl;
    return 0;
}
/*
5 3 3
1 1 1 1 1 1 1 1 1 100 1
1 1 1 3 1 1 1 2
 */