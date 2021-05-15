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
ll dp(int fir,int sec,int len){
	static ll dt[10][10][20];static int vi[10][10][20];
	ll&f=dt[fir][sec][len];
	int&g=vi[fir][sec][len];
	if(!g){
		g=1;
		if(len==2)f=1;
		else{
			lp(i,0,9)if(i!=fir&&i!=sec)
				f+=dp(sec,i,len-1);
		}
	}
	return f;
}
ll calc(ll tn){
	string n;stringstream ss;ss<<tn;ss>>n;
	ll ret=0;vp(i,n)n[i]-='0';
	if(n.size()==1)ret=n[0];//1位
	else{
		lp(i,1,n[0]-1)lp(j,0,9)if(i!=j)ret+=dp(i,j,n.size());//第1位不同，且不为0
		for(int i=1;i+1<n.size();++i){//考虑前导0的情况，枚举哪位开始不为0
			lp(j,1,9)lp(k,0,9)if(j!=k)ret+=dp(j,k,n.size()-i);
		}
		//没考虑的0到9
		ret+=10;
		for(int i=1;i<n.size();++i){//枚举到哪位不同
			int flg=1;
			lp(j,0,i-2)if(n[j]==n[j+1])flg=0;
			lp(j,0,i-3)if(n[j]==n[j+2])flg=0;
			if(!flg)break;
			lp(j,0,n[i]-1)
				if(j!=n[i-1]&&(i==1||j!=n[i-2]))
					ret+=dp(n[i-1],j,n.size()-i+1);
		}
	}
	return ret;
}
int main(){
	//lp(i,1,1000)pf("%d,%lld\n",i,calc(i));return 0;
	ll a,b;sf("%lld%lld",&a,&b);
	pf("%lld\n",calc(b+1)-calc(a));
	return 0;
}
