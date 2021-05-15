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
int n,m;
struct query{
	int tp;//1 add 2 ask
	int x,y;
	int y1,y2,id,mul;
};
bool operator<(query a,query b){
	return a.x==b.x?a.tp<b.tp:a.x<b.x;
}
int ans[500010];
vector<query>qs;
int db[10000010];
void add(int x){
	for(;x<=10000005;x+=x&-x)++db[x];
}
int ask(int x){
	int r=0;
	for(;x;x-=x&-x)r+=db[x];
	return r;
}
int main(){
	sf("%d%d",&n,&m);
	lp(i,1,n){
		query q;q.tp=1;
		sf("%d%d",&q.x,&q.y);
		++q.x;++q.y;
		qs.pb(q);
	}
	lp(i,1,m){
		query q1,q2;q1.tp=q2.tp=2;q1.id=q2.id=i;q1.mul=-1;q2.mul=1;
		int x1,y1,x2,y2;sf("%d%d%d%d",&x1,&y1,&x2,&y2);
		++x1;++y1;++x2;++y2;
		q1.x=x1-1;q1.y1=y1;q1.y2=y2;
		q2.x=x2;q2.y1=y1;q2.y2=y2;
		qs.pb(q1);
		qs.pb(q2);
	}
	sort(qs.begin(),qs.end());
	vp(i,qs){
		if(qs[i].tp==1)add(qs[i].y);
		else{
			ans[qs[i].id]+=qs[i].mul*(ask(qs[i].y2)-ask(qs[i].y1-1));
		}
	}
	lp(i,1,m)pf("%d\n",ans[i]);
	return 0;
}
