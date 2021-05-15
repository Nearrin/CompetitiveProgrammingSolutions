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
int sum[5010][5010];int n,r,ans;
int main(){
	sf("%d%d",&n,&r);int maxx=1,maxy=1;
	lp(i,1,n){
		int x,y,z;sf("%d%d%d",&x,&y,&z);
		sum[x+1][y+1]+=z;
		maxx=max(maxx,x+1);
		maxy=max(maxy,y+1);
	}
	lp(i,1,min(maxx+r,5001))lp(j,1,min(maxy+r,5001)){
		sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
		if(i>=r&&j>=r){
			ans=max(ans,sum[i][j]-sum[i-r][j]-sum[i][j-r]+sum[i-r][j-r]);
		}
	}
	pf("%d\n",ans);
	return 0;
}
