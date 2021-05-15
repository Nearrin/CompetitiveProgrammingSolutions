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
#include<sstream>
#include<string>
#include<cstdlib>
ll solve(ll n,ll m){
	stringstream ss;ss<<n;string tn;ss>>tn;
	static ll dp[31][210][210],pw[31];dp[0][0][0]=1;
	pw[0]=1%m;lp(i,1,tn.size())pw[i]=pw[i-1]*10%m;static ll lastm=-1;
	if(tn.size()*9<m)return 0;
	if(lastm!=m)lp(i,1,tn.size()){
		lp(j,0,m){
			lp(k,0,m){
				dp[i][j][k]=0;
				lp(l,0,9){
					if(j>=l){
						int t=k-l*pw[i-1]%m+m;
						if(t>=m)t-=m;
						dp[i][j][k]+=dp[i-1][j-l][t];
					}
				}
			}
		}
	}
	lastm=m;
	ll ret=0;
	ll sum1=0,sum2=0;
	vp(i,tn){
		lp(j,0,tn[i]-'0'-1){
			if(sum1+j<=m){
				int t=pw[tn.size()-i-1]*j%m+sum2;
				if(t>=m)t-=m;
				t=m-t;
				if(t>=m)t-=m;
				ret+=dp[tn.size()-i-1][m-(sum1+j)][t];
			}
		}
		sum1+=tn[i]-'0';
		sum2=(sum2+(tn[i]-'0')*pw[tn.size()-i-1])%m;
	}
	return ret;
}
ll brutesolve(ll n){
	ll ret=0;
	lp(i,1,n){
		ll j=0,t=i;
		while(t)j+=t%10,t/=10;
		ret+=(i%j==0);
	}
	return ret;
}
ll calc1(ll a,ll b){
	ll ans=0;
	lp(i,1,18*9)ans+=solve(b+1,i)-solve(a,i);
	return ans;
}
ll calc2(ll a,ll b){
	return brutesolve(b)-brutesolve(a-1);
}
int main(){
	/*lp(i,1,100){
		int a=rand()%100000+1,b=rand()%100000+1;
		if(a>b)swap(a,b);
		ll ans1=calc1(a,b),ans2=calc2(a,b);
		pf("%d %d,%lld %lld\n",a,b,ans1,ans2);
		if(ans1!=ans2)break;
	}*/
	/*lp(i,1,100)lp(j,i,100){
		ll ans1=calc1(i,j),ans2=calc2(i,j);
		pf("%d %d,%lld %lld\n",i,j,ans1,ans2);
		if(ans1!=ans2)break;
	}*/
	ll a,b;sf("%lld%lld",&a,&b);
	pf("%lld\n",calc1(a,b));
	return 0;
}
/*
0 100000000000000
0 99999999999999
*/
