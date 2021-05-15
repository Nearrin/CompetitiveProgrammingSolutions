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
/*
f(n,a) to f(2n,a) O(m^2lgn)
*/
ll n,m,p=1000000007;
struct data{ll f[210];};
ll mypow(ll x,ll y){
	ll z=1;
	while(y){
		if(y&1)z=z*x%p;
		x=x*x%p;
		y>>=1;
	}
	return z;
}
ll com[210][210];
vector<int>op;
void dfs(ll x){
	if(x==1)return;
	if(x&1){
		dfs(x/2);
		op.pb(1);
		op.pb(2);
	}else{
		dfs(x/2);
		op.pb(1);
	}
}
int main(){
	sf("%lld%lld",&n,&m);
	lp(i,0,m)lp(j,0,m)if(j==0||j==i)com[i][j]=1;else com[i][j]=(com[i-1][j]+com[i-1][j-1])%p;
	data t1;lp(i,0,m)t1.f[i]=m;
	dfs(n);ll now=1;
	vp(u,op){
		if(op[u]==2){
			++now;
			lp(a,0,m)t1.f[a]=(t1.f[a]+mypow(now,a)*mypow(m,now))%p;
		}else{
			data t2;
			lp(a,0,m){
				t2.f[a]=0;
				lp(j,0,a)t2.f[a]=(t2.f[a]+com[a][j]*mypow(now,a-j)%p*t1.f[j]%p)%p;
				t2.f[a]=t2.f[a]*mypow(m,now)%p;
				t2.f[a]=(t2.f[a]+t1.f[a])%p;
			}
			swap(t1,t2);
			now*=2;
		}
	}
	pf("%lld\n",t1.f[m]);
	return 0;
}
