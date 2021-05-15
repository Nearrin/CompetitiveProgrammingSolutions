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
#include<string>
#include<sstream>
ll f[10][21];
int myabs(int a){return a>0?a:-a;}
ll calc(ll tn){
	stringstream ss;ss<<tn;string n;ss>>n;ll ret=0;
	vp(i,n)n[i]-='0';
	lp(i,1,n[0]-1)ret+=f[i][n.size()];
	for(int i=1;i<n.size();++i)
		lp(j,1,9)ret+=f[j][n.size()-i];
	++ret;
	for(int i=1;i<n.size();++i){
		lp(j,0,i-2)if(myabs(n[j]-n[j+1])<=1)return ret;
		lp(j,0,n[i]-1)if(myabs(n[i-1]-j)>1)ret+=f[j][n.size()-i];
	}
	return ret;
}
ll bf(ll n){
	ll ret=0;
	lp(i,0,n-1){
		stringstream ss;ss<<i;string tmp;ss>>tmp;
		int flg=1;
		lp(j,0,int(tmp.size()-2))
			if(myabs(tmp[j]-tmp[j+1])<=1)
				flg=0;
		ret+=flg;
	}
	return ret;
}
int main(){
	lp(i,0,9)f[i][1]=1;
	lp(i,2,20){
		lp(j,0,9){
			lp(k,0,9){
				if(myabs(j-k)>1){
					f[j][i]+=f[k][i-1];
				}
			}
		}
	}
	//pf("[%lld,%lld]\n",calc(102),calc(103));
	//lp(i,1,200)pf("[%d,%lld,%lld,%lld]\n",i,calc(i),bf(i),calc(i)-bf(i));
	ll a,b;sf("%lld%lld",&a,&b);
	pf("%lld\n",calc(b+1)-calc(a));
	return 0;
}
