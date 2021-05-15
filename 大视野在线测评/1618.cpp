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
int f[100010],n,h;
int main(){
	sf("%d%d",&n,&h);
	lp(i,1,100000)f[i]=~0u>>1;
	lp(i,1,n){
		int p,c;sf("%d%d",&p,&c);
		lp(j,p,100000){
			if(f[j-p]!=~0u>>1)
				f[j]=min(f[j],f[j-p]+c);
		}
	}
	pf("%d\n",*min_element(f+h,f+100001));
	return 0;
}
