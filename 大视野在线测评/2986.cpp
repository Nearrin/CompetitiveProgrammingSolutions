#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define pb push_back
#define mp make_pair
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
#define vp(i,v) for(int i=0;i<v.size();++i)
#define wp(i,v) for(int i=int(v.size())-1;i>=0;--i)
typedef long long ll;
using namespace std;
ll pri[1000010],isp[1000010],mui[1000010];
ll count(ll x){
	ll r=0;
	for(ll i=2;i*i<=x;++i)
		r-=(x/(i*i))*mui[i];
	return r;
}
int main(){
	mui[1]=1;
	for(ll i=2;i<=1000000;++i){
		if(!isp[i]){
			pri[++pri[0]]=i;
			mui[i]=-1;
		}
		for(ll j=1;j<=pri[0]&&pri[j]*i<=1000000;++j){
			if(i%pri[j]==0){
				isp[i*pri[j]]=1;
				mui[i*pri[j]]=0;
				break;
			}else{
				isp[i*pri[j]]=1;
				mui[i*pri[j]]=-mui[i];
			}
		}
	}
	//lp(i,1,10)pf("[%d,%lld]\n",i,mui[i]);
	//lp(i,1,10)pf("[%d,%lld]\n",i,count(i));
	ll n;sf("%lld",&n);
	ll left=0,right=1;
	while(count(right)<n)right*=2;
	while(left+1<right){
		ll mid=(left+right)/2;
		if(count(mid)>=n)right=mid;
		else left=mid;
	}
	pf("%lld\n",right);
	return 0;
}
