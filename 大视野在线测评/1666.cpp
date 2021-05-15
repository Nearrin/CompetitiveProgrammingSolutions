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
int cnt(int x){
	int ret=0;
	while(x!=1){
		if(x&1)x=x*3+1;
		else x/=2;
		++ret;
	}
	return ret;
}
int main(){
	int n;sf("%d",&n);
	pf("%d\n",cnt(n));
    return 0;
}
