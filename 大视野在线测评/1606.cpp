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
int f[50010];
int main(){
	int v,n;
	sf("%d%d",&v,&n);
	f[0]=1;
	lp(i,1,n){
		int t;sf("%d",&t);
		rp(j,v,t)f[j]=(f[j-t]||f[j]);
	}
	while(!f[v])--v;
	pf("%d\n",v);
    return 0;
}
