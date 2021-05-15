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
ll dp[11][410][1010],n,m;
bool check(int s1,int s2){
	vector<int>t1,t2;
	lp(i,0,n-1)t1.pb((s1>>i)&1);
	lp(i,0,n-1)t2.pb((s2>>i)&1);
	lp(i,0,n-1)if(t1[i]==1&&t2[i]==1)return false;
	lp(i,1,n-1)if(t1[i]+t2[i-1]==2)return false;
	lp(i,1,n-1)if(t2[i]+t1[i-1]==2)return false;
	return true;
}
vector<int>state;
bool check(int s1){
	vector<int>t1;
	lp(i,0,n-1)t1.pb((s1>>i)&1);
	for(int i=1;i<t1.size();++i)
		if(t1[i-1]+t1[i]==2)return false;
	return true;
}
int count(int x){
	int ret=0;
	lp(i,0,n-1)if((x>>i)&1)++ret;
	return ret;
}
bool checktable[1010][1010];
int counttable[1010];
int main(){
	dp[0][0][0]=1;
	sf("%lld%lld",&n,&m);
	lp(i,0,(1<<n)-1)if(check(i))state.pb(i);
	vp(i,state)vp(j,state)checktable[i][j]=check(state[i],state[j]);
	vp(i,state)counttable[i]=count(state[i]);
	lp(i,0,n-1)lp(j,0,m)vp(k,state)vp(l,state)
		if(checktable[k][l])dp[i+1][j+counttable[l]][state[l]]+=dp[i][j][state[k]];
	ll ans=0;
	lp(s1,0,(1<<n)-1)ans+=dp[n][m][s1];
	pf("%lld\n",ans);
	return 0;
}
