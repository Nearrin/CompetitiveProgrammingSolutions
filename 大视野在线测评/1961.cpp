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
const int MOD=1000000007;
struct Int{
	Int(int _x=0):x(_x){}
	int x;
};
inline Int operator+(Int x,Int y){
	Int z(x.x+y.x);
	if(z.x>=MOD)z.x-=MOD;
	return z;
}
inline Int operator-(Int x,Int y){
	Int z(x.x-y.x);
	if(z.x<0)z.x+=MOD;
	return z;
}
inline bool zero(Int x){
	return x.x==0;
}
int n,wei[110],sum;
Int f[700010],g[700010];
int surive[110],ans1;
int dp[1400010],*h=dp+700000;
int main(){
	sf("%d",&n);
	lp(i,1,n)sf("%d",&wei[i]),sum+=wei[i];
	f[0].x=1;
	lp(i,1,n)rp(j,sum,wei[i])f[j]=f[j]+f[j-wei[i]];
	lp(i,1,n)lp(j,0,sum){
		if(j>=wei[i])g[j]=f[j]-g[j-wei[i]];
		else g[j]=f[j];
		if(!zero(g[j]))++surive[i];
	}
	//lp(i,1,n)pf("[%d]\n",surive[i]);
	ans1=1;
	lp(i,2,n)if(surive[i]>surive[ans1]||(surive[i]==surive[ans1]&&wei[i]<wei[ans1]))ans1=i;
	//pf("%d\n",ans1);
	h[0]=1;
	lp(i,1,n)if(i!=ans1)rp(j,sum,wei[i])h[j]=(h[j]||h[j-wei[i]]);
	//lp(i,-sum,sum)pf("[%d:%d]\n",i,h[i]);
	lp(i,1,n)if(i!=ans1)lp(j,-sum,sum-wei[i])h[j]=(h[j]||h[j+wei[i]]);
	int ans2=0;while(h[ans2])++ans2;
	pf("%d %d\n",wei[ans1],ans2);
	return 0;
}
