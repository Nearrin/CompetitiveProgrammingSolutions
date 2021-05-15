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
ll N,X,A,B,M,T[100010],Del[100010];
int main(){
	sf("%lld%lld%lld%lld%lld",&N,&X,&A,&B,&M);
	T[1]=X;lp(i,2,N)T[i]=T[i-1]-B;
	ll sum=0;lp(i,1,N)sum+=T[i];
	ll t1=(M-sum)/(A+B);
	//pf("%lld\n",t1);
	rp(i,N-1,1){
		if(t1>=i){
			t1-=i;
			Del[N-i+1]+=A+B;
		}
	}
	lp(i,1,N)Del[i]+=Del[i-1];
	lp(i,1,N)pf("%lld%c",T[i]+Del[i],i==N?'\n':' ');
	return 0;
}
