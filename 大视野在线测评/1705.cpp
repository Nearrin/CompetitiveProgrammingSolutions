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
int n,c,f[100010][110],a[100010];
int tb(int x){return x>0?x:-x;}
int main(){
	sf("%d%d",&n,&c);
	lp(i,1,n)sf("%d",&a[i]);
	lp(i,a[1],100)f[1][i]=(i-a[1])*(i-a[1]);
	lp(i,2,n)lp(j,a[i],100){
		f[i][j]=~0u>>1;
		lp(k,a[i-1],100)f[i][j]=min(f[i][j],f[i-1][k]+tb(j-k)*c+(j-a[i])*(j-a[i]));
	}
	pf("%d\n",*min_element(f[n]+a[n],f[n]+101));
	return 0;
}
