#include<cstdio>
#include<algorithm>
#include<cmath>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
typedef long double ld;
ll db[100010];int n,m;
void add(int i,ll d){
    for(;i<=n;i+=i&-i)db[i]+=d;
}
ll ask(int i){
    ll r=0;
    for(;i;i-=i&-i)r+=db[i];
    return r;
}
ll a[100010];int nxt[100010];
int fd(int x){return x==nxt[x]?x:nxt[x]=fd(nxt[x]);}
int main(){
    sf("%d",&n);
    lp(i,1,n+1)nxt[i]=i;//must n+1
    lp(i,1,n){
        sf("%lld",&a[i]);
        add(i,a[i]);
    }
    sf("%d",&m);
    lp(i,1,m){
        int x,l,r;
        sf("%d%d%d",&x,&l,&r);
        if(x==1)pf("%lld\n",ask(r)-ask(l-1));
        else{
            for(int j=fd(l);j<=r;j=fd(j+1)){
                ll nt=ll(sqrt(ld(a[j]))+1e-8);
                add(j,nt-a[j]);
                a[j]=nt;
                if(a[j]==1||a[j]==0)nxt[j]=j+1;
            }
        }
    }
    //ps;
    return 0;
}
