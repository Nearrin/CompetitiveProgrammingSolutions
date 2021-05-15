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
vector<int>pos1[510],pos2[510];
char s1[1000010],s2[1000010];
int dt[1000010],n;
void add(int x){
	for(;x<=n;x+=x&-x)++dt[x];
}
int ask(int x){
	int r=0;
	for(;x;x-=x&-x)r+=dt[x];
	return r;
}
int a[1000010];ll ans;
int main(){
	sf("%d%s%s",&n,s1+1,s2+1);
	lp(i,1,n)pos1[s1[i]].pb(i),pos2[s2[i]].pb(i);
	lp(i,'A','Z')vp(j,pos1[i])a[pos1[i][j]]=pos2[i][j];
	lp(i,1,n){
		ans+=ask(n)-ask(a[i]);
		add(a[i]);
	}
	pf("%lld\n",ans);
	return 0;
}
