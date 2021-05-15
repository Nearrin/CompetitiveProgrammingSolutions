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
#include<set>
int gcd(int a,int b){return b?gcd(b,a%b):a;}
pair<int,int>normal(pair<int,int>vec){
	if(vec.first<0)vec.first*=-1,vec.second*=-1;
	else if(vec.first==0&&vec.second<0)vec.second=-vec.second;
	int d=gcd(vec.first,vec.second>0?vec.second:-vec.second);
	vec.first/=d;vec.second/=d;
	return vec;
}
int x[210],y[210],n;
set<pair<int,int> >st;
int main(){
	sf("%d",&n);
	lp(i,1,n)sf("%d%d",&x[i],&y[i]);
	lp(i,1,n)lp(j,i+1,n)st.insert(normal(mp(x[i]-x[j],y[i]-y[j])));
	pf("%d\n",(int)st.size());
	return 0;
}
