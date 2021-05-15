#include<cstdio>
#include<algorithm>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long ll;
ll mul(ll a,ll b,ll c){
    ll r=0;
    while(b){
        if(b&1)r=(r+a)%c;
        a=(a+a)%c;
        b>>=1;
    }
    return r;
}
struct mat{ll d[3][3];};
mat mul(mat a,mat b,ll c){
    mat r;
    lp(i,1,2)
        lp(j,1,2){
            r.d[i][j]=0;
            lp(k,1,2)
                r.d[i][j]=(r.d[i][j]+mul(a.d[i][k],b.d[k][j],c))%c;
        }
    return r;
}
mat pw(mat a,ll b,ll c){
    mat r;r.d[1][1]=r.d[2][2]=1;
    r.d[1][2]=r.d[2][1]=0;
    while(b){
        if(b&1)r=mul(r,a,c);
        a=mul(a,a,c);
        b>>=1;
    }
    return r;
}
int main(){
    ll m,a,c,x0,n,g;
    sf("%lld%lld%lld%lld%lld%lld",&m,&a,&c,&x0,&n,&g);
    mat t;
    t.d[1][1]=a;
    t.d[1][2]=0;
    t.d[2][1]=1;
    t.d[2][2]=1;
    t=pw(t,n,m);
    ll ans=(mul(t.d[1][1],x0,m)+mul(t.d[2][1],c,m))%m;
    pf("%lld\n",ans%g);
    return 0;
} 
