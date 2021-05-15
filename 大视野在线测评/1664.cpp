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
bool cmp(pair<int,int>x,pair<int,int>y){
	return x.second<y.second;
}
int main(){
	int n;vector<pair<int,int> >a;
	sf("%d",&n);
	lp(i,1,n){
		int u,v;sf("%d%d",&u,&v);
		a.pb(mp(u,u+v));
	}
	sort(a.begin(),a.end(),cmp);
	int cur=-100;
	int ans=0;
	vp(i,a){
		if(a[i].first>=cur){
			++ans;
			cur=a[i].second;
		}
	}
	pf("%d\n",ans);
	return 0;
}
