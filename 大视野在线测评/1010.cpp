#include<cstdio>
#include<algorithm>
#include<deque>
#define sf scanf
#define pf printf
#define fr(a,b,c) freopen(a,b,c)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long ll;
ll n,l,s[50010],t[50010],x[50010],y[50010],f[50010];
double k(int a,int b){
	return double(y[a]-y[b])/(x[a]-x[b]);
}
int main(){
	//fr("data.in","r",stdin);
	//fr("hehe.out","w",stdout);
  	sf("%lld%lld",&n,&l);
    lp(i,1,n)sf("%lld",&s[i]),s[i]+=s[i-1];
    x[0]=0;y[0]=0;deque<int> qu;qu.push_back(0);
    lp(i,1,n){
    	t[i]=s[i]+i-1-l;
        while(qu.size()>1&&k(qu[0],qu[1])<t[i])qu.pop_front();
        f[i]=f[qu[0]]+(t[i]-s[qu[0]]-qu[0])*(t[i]-s[qu[0]]-qu[0]);
        x[i]=2*(s[i]+i);y[i]=f[i]+(s[i]+i)*(s[i]+i);
        while(qu.size()>1&&k(qu[qu.size()-1],qu[qu.size()-2])>k(qu[qu.size()-2],i))qu.pop_back();
        qu.push_back(i);
    }
    pf("%lld\n",f[n]);
    return 0;
} 
