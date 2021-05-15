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
ll f[1000010],n,p=1000*1000*1000;
int main(){
	sf("%lld",&n);
	f[0]=1;
	for(int i=1;i<=n;i*=2)
		for(int j=i;j<=n;++j)
			f[j]=(f[j]+f[j-i])%p;
	pf("%lld\n",f[n]);
	return 0;
}
