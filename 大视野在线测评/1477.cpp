#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define pb push_back
#define mp make_pair
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
#define vp(i,v) for(int i=0;i<v.size();++i)
#define wp(i,v) for(int i=int(v.size()-1);i>=0;--i)
typedef long long ll;
using namespace std;
ll exgcd(ll a,ll b,ll&x,ll&y){
	if(!b){x=1;y=0;return a;}
	else{
		ll r=exgcd(b,a%b,y,x);
		y-=a/b*x;
		return r;
	}
}
int main(){
	ll tx,ty,tm,tn,tl;
	sf("%lld%lld%lld%lld%lld",&tx,&ty,&tm,&tn,&tl);
	ll a=tm-tn,b=tl,c=ty-tx;
	if(a<0)a=-a,c=-c;
	ll x,y;
	ll d=exgcd(a,b,x,y);
	//pf("[%lld,%lld,%lld,%lld]\n",a,b,x,y);
	if(c%d!=0)pf("Impossible\n");
	else{
		x=x*c/d;
		x=(x%(b/d)+(b/d))%(b/d);
		pf("%lld\n",x);
	}
	return 0;
}
