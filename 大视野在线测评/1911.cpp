#include<cstdio>
#include<algorithm>
#include<deque>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
long long s[1000010],x[1000010],y[1000010],f[1000010],a,b,c,n;
int main(){
    sf("%lld%lld%lld%lld",&n,&a,&b,&c);
    lp(i,1,n)sf("%lld",&s[i]),s[i]+=s[i-1];
    deque<int>qu;
    qu.push_back(0);
    lp(i,1,n){
        while(qu.size()>1&&double(y[qu[0]]-y[qu[1]])/(x[qu[0]]-x[qu[1]])>=2*a*s[i])qu.pop_front();
        f[i]=f[qu[0]]+a*(s[i]-s[qu[0]])*(s[i]-s[qu[0]])+b*(s[i]-s[qu[0]])+c;
        x[i]=s[i],y[i]=f[i]+a*s[i]*s[i]-b*s[i];
        while(qu.size()>1&&double(y[qu[qu.size()-2]]-y[qu[qu.size()-1]])/(x[qu[qu.size()-2]]-x[qu[qu.size()-1]])<double(y[qu[qu.size()-1]]-y[i])/(x[qu[qu.size()-1]]-x[i]))qu.pop_back();
        qu.push_back(i);
        
    }
    pf("%lld\n",f[n]);
    //ps;
    return 0;
}
