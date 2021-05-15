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
int n,m,w[1010];
char s[2010];
int dp[2010][2010];
int main(){
	sf("%d%d%s",&n,&m,s+1);
	lp(i,1,n){
		static char buff[110];
		int t1,t2;sf("%s%d%d",buff,&t1,&t2);
		w[buff[0]]=min(t1,t2);
	}
	lp(d,2,m){
		for(int i=1;i+d-1<=m;++i){
			int j=i+d-1;
			dp[i][j]=~0u>>1;
			if(s[i]==s[j])dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
			dp[i][j]=min(dp[i][j],dp[i+1][j]+w[s[i]]);
			dp[i][j]=min(dp[i][j],dp[i][j-1]+w[s[j]]);
		}
	}
	//lp(i,1,m)lp(j,i,m)pf("[%d,%d,%d]\n",i,j,dp[i][j]);
	pf("%d\n",dp[1][m]);
	return 0;
}
