#include<cstdio>
#include<algorithm>
#include<vector>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
ll n,a,p=1000000007;
ll mui[10000010],pr[10000010];
void calc_mui(){
    static ll isp[10000010];
    mui[1]=1;
    lp(i,2,10000005){
        if(!isp[i]){
            pr[++pr[0]]=i;
            mui[i]=-1;
        }
        for(ll j=1;j<=pr[0]&&pr[j]*i<=10000005;++j){
            if(i%pr[j]==0){
                isp[i*pr[j]]=1;
                mui[i*pr[j]]=0;
                break;
            }else{
                isp[i*pr[j]]=1;
                mui[i*pr[j]]=-mui[i];
            }
        }
    }
}
struct num{
    num(ll t=0):x(t/p),y(t%p){}
    ll x,y;
}m;
inline num operator+(num a,num b){
    num c;
    c.x=(a.x+b.x)%p;
    c.y=a.y+b.y;
    if(c.y>=p){
        c.y-=p;
        c.x=(c.x+1)%p;
    }
    return c;
}
inline num operator-(num a,num b){
    num c;
    c.x=(a.x-b.x+p)%p;
    c.y=a.y-b.y;
    if(c.y<0){
        c.y+=p;
        c.x=(c.x-1+p)%p;
    }
    return c;
}
inline num operator*(num a,num b){
    num c;
    c.x=(a.x*b.y+b.x*a.y)%p;
    c.y=a.y*b.y;
    c.x=(c.x+c.y/p)%p;
    c.y%=p;
    return c;
}
void calc_m(){
    static num s[10000010];static int f=0;
    if(!f){
        lp(i,1,10000005)s[i]=num(ll(i)*ll(i+1)/2)+s[i-1];
        f=1;
    }
    m=num(0);
    lp(i,1,a)
        if(mui[i]==1)m=m+s[a/i];
        else if(mui[i]==-1)m=m-s[a/i];
}
struct mat{num d[3][3];};
mat mul(const mat&x,const mat&y){
    mat r;lp(i,1,2)lp(j,1,2)r.d[i][j]=num(0);
    lp(i,1,2)
        lp(j,1,2)
            lp(k,1,2){
                r.d[i][j]=r.d[i][j]+x.d[i][k]*y.d[k][j];
            }
    return r;
}
num calc_h(ll x){
    mat r;r.d[1][1]=num(0);r.d[1][2]=num(m-1);
    r.d[2][1]=num(1);r.d[2][2]=num(m-2);
    mat t;lp(i,1,2)lp(j,1,2)t.d[i][j]=num(i==j);
    for(ll y=x;y;y>>=1){
        if(y&1)t=mul(t,r);
        r=mul(r,r);
    }
    return t.d[1][1]*num(m);
}
ll inv(ll x){
    ll r=1;x%=p;
    for(ll y=p-2;y;y>>=1){
        if(y&1)r=r*x%p;
        x=x*x%p;
    }
    return r;
}
ll phi(ll x){
    ll r=x;
    for(ll i=1;i<=pr[0]&&pr[i]*pr[i]<=x;++i)
        if(x%pr[i]==0){
            r/=pr[i];
            r*=pr[i]-1;
            while(x%pr[i]==0)x/=pr[i];
        }
    if(x!=1)r/=x,r*=x-1;
    return r;
}
int main(){
    calc_mui();
    int test;sf("%d",&test);
    lp(kase,1,test){
        sf("%lld%lld",&n,&a);
        calc_m();
        num ans=num(0);
        for(ll i=1;i*i<=n;++i){
            if(n%i==0){
                ans=ans+calc_h(i)*num(phi(n/i));
                if(i*i!=n)ans=ans+calc_h(n/i)*num(phi(i));
            }
        }
        ll ans2;
        if(n%p!=0)ans2=ans.y*inv(n)%p;
        else ans2=ans.x*inv(n/p)%p;
        pf("%lld\n",ans2);
    }
    //ps;
    return 0;
}
