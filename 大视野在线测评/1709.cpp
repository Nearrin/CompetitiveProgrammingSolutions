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
int n,k,a[110][110];
int main(){
	sf("%d%d",&n,&k);
	lp(i,1,k){
		int x,y;
		sf("%d%d",&x,&y);
		++a[x][y];
	}
	vector<pair<int,int> >tmp;
	lp(i,1,n)lp(j,1,n)if(a[i][j])tmp.pb(mp(i,j));
	int ans=0;
	lp(i,1,n)lp(j,1,n){
		int t=1;
		vp(k,tmp){
			int x=tmp[k].first,y=tmp[k].second;
			if(x!=i&&y!=j&&x+y!=i+j&&x-y!=i-j){t=0;break;}
		}
		ans+=t;
	}
	pf("%d\n",ans);
	return 0;
}
