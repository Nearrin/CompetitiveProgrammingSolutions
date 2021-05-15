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
void mul(vector<int>&a,int t){
	vp(i,a)a[i]*=t;
	vp(i,a){
		if(a[i]>9){
			if(i+1==a.size())a.pb(0);
			a[i+1]+=a[i]/10;
			a[i]%=10;
		}
	}
}
int main(){
	int n;sf("%d",&n);
	int t3=0,t2=0;vector<int>ans(1,1);
	if(n%3==0)t3=n/3;
	else if(n%3==1)t3=n/3-1,t2=2;
	else t3=n/3,t2=1;
	lp(i,1,t3)mul(ans,3);
	lp(i,1,t2)mul(ans,2);
	pf("%d\n",(int)ans.size());
	lp(i,0,min(int(ans.size()-1),99))pf("%d",ans[ans.size()-i-1]);pf("\n");
	return 0;;
}
