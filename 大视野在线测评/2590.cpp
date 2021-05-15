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
/*
建立费用流模型
用堆优化增广
*/
#include<queue>
int n,k;ll m,p[50010],c[50010];
int vis[50010];
struct item{
	item(int i,ll v):idx(i),val(v){}
	int idx;ll val;
};
bool operator<(item a,item b){
	return a.val>b.val;
}
int main(){
	sf("%d%d%lld",&n,&k,&m);
	lp(i,1,n)sf("%lld%lld",&p[i],&c[i]);
	int ans=0;
	priority_queue<ll,vector<ll>,greater<ll> >ticket;
	lp(i,1,k)ticket.push(0);
	priority_queue<item>sml,big;
	lp(i,1,n)sml.push(item(i,c[i])),big.push(item(i,p[i]));
	while(true){
		while(!sml.empty()&&vis[sml.top().idx])sml.pop();
		while(!big.empty()&&vis[big.top().idx])big.pop();
		if(sml.empty())break;
		if(sml.top().val+ticket.top()<big.top().val){
			ll t=sml.top().val+ticket.top();
			if(m<t)break;
			m-=t;
			++ans;
			ticket.pop();
			vis[sml.top().idx]=1;
			ticket.push(p[sml.top().idx]-c[sml.top().idx]);
		}else{
			ll t=big.top().val;
			if(m<t)break;
			m-=t;
			++ans;
			vis[big.top().idx]=1;
		}
	}
	pf("%d\n",ans);
	return 0;
}
