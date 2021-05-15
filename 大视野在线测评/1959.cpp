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
vector<pair<int,int> >a;int n;
bool cmp(pair<int,int>u,pair<int,int>v){
	return u.first>v.first;
}
int main(){
	sf("%d",&n);
	lp(i,1,n){
		int u,v;sf("%d%d",&u,&v);
		a.pb(mp(u,v));
	}
	sort(a.begin(),a.end(),cmp);
	vector<int>f;
	vp(i,a){
		vector<int>::iterator it=lower_bound(f.begin(),f.end(),a[i].second);
		if(it==f.end())f.pb(a[i].second);
		else *it=a[i].second;
	}
	pf("%d\n",(int)f.size());
	return 0;
}
