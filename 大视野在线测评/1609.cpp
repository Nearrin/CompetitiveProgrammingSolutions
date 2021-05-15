#include<cstdio>
#include<algorithm>
#include<vector>
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
int a[30010],n;
int f[30010][4];
int dp(){
	lp(i,1,n){
		lp(j,1,3){
			f[i][j]=~0u>>1;
			lp(k,1,j){
				f[i][j]=min(f[i][j],f[i-1][k]+(a[i]!=j));
			}
		}
	}
	return min(min(f[n][1],f[n][2]),f[n][3]);
}
int main(){
	sf("%d",&n);
	lp(i,1,n)sf("%d",&a[i]);
	int ans=~0u>>1;
	ans=min(ans,dp());
	reverse(a+1,a+n+1);
	ans=min(ans,dp());
	pf("%d\n",ans);
	return 0;
}
