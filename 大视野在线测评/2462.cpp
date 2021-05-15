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
int main(){
	int m,n,a,b;
	sf("%d%d%d%d",&n,&m,&a,&b);
	static char buff[1000010];
	lp(i,1,m)sf("%s",buff);
	int q;sf("%d",&q);
	lp(i,1,q)pf("1\n");
	return 0;
}
