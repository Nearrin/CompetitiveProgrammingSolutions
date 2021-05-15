#include<cstdio>
#include<vector>
#include<algorithm>
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
#define wp(i,v) for(int i=int(v.size()-1);i>=0;--i)
using namespace std;
typedef long long ll;
int w,d,n,m,f[20010];
int main(){
	sf("%d%d",&n,&m);
	lp(i,1,n){
		sf("%d%d",&w,&d);
		rp(j,m,w)f[j]=max(f[j],f[j-w]+d);
	}
	pf("%d\n",f[m]);
	return 0;
}
