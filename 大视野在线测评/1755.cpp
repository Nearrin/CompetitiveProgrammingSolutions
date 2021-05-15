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
#include<cmath>
int main(){
	int a,b,c;sf("%d%d%d",&a,&b,&c);
	long double t=b;
	lp(i,1,c)t*=(double(100+a)/100);
	pf("%d\n",int(t));
	return 0;
}
