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
int ans[400010];
int main(){
	int n=100000,l=10000;
	for(int i=1;i<=n;i*=2){
		lp(j,1,i)ans[i+j]=(ans[j]^1);
	}
	pf("%d %d\n",n,l);
	lp(i,1,n)pf("%c",'a'+ans[i]);pf("\n");
	return 0;
}
