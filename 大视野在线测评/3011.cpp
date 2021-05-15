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
int n;ll l;vector<int>ch[200010];vector<ll>we[200010];
int ans[200010];
struct node{
	node(ll v){val=v;del=0;cnt=1;ch[0]=ch[1]=0;}
	ll val,del;int cnt;
	node*ch[2];
};
void down(node*x){
	lp(i,0,1)if(x->ch[i])x->ch[i]->del+=x->del;
	x->val+=x->del;
	x->del=0;
}
void update(node*x){
	x->cnt=1;
	lp(i,0,1)if(x->ch[i])x->cnt+=x->ch[i]->cnt;
}
node*merge(node*x,node*y){
	if(!x)return y;
	if(!y)return x;
	down(x);down(y);
	if(x->val<y->val)swap(x,y);
	x->ch[1]=merge(x->ch[1],y);
	swap(x->ch[0],x->ch[1]);
	update(x);
	return x;
}
node*dfs(int u){
	node*t=0;
	vp(i,ch[u]){
		node*t2=dfs(ch[u][i]);t2->del+=we[u][i];
		t=merge(t,t2);
	}
	t=merge(t,new node(0));
	while(true){
		down(t);
		if(t->val<=l)break;
		else t=merge(t->ch[0],t->ch[1]);
	}
	ans[u]=t->cnt;
	return t;
}
int main(){
	sf("%d%lld",&n,&l);
	lp(i,2,n){
		int p;ll d;sf("%d%lld",&p,&d);
		ch[p].pb(i);we[p].pb(d);
	}
	dfs(1);
	lp(i,1,n)pf("%d\n",ans[i]);
	return 0;
}
