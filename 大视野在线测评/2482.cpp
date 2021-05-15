#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#define sf scanf
#define pf printf
#define pb push_back
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
#define vp(i,v) for(int i=0;i<v.size();++i)
using namespace std;
typedef long long ll;
#define N 400010
ll t0[N],t1[N],del[N],edel[N];
void down(int x,int l,int r){
	t1[x]=max(t1[x],t0[x]+edel[x]);
	t0[x]+=del[x];
	if(l!=r){
		edel[x*2]=max(edel[x*2],del[x*2]+edel[x]);
		del[x*2]+=del[x];
		edel[x*2+1]=max(edel[x*2+1],del[x*2+1]+edel[x]);
		del[x*2+1]+=del[x];
	}
	del[x]=edel[x]=0;
}
void update(int x,int l,int r){
	int m=(l+r)/2;
	down(x*2,l,m);down(x*2+1,m+1,r);
	t0[x]=max(t0[x*2],t0[x*2+1]);
	t1[x]=max(t1[x*2],t1[x*2+1]);
}
ll query(int x,int l,int r,int b,int e){
	down(x,l,r);
	if(b<=l&&e>=r)return t1[x];
	else{
		ll ret=0;int m=(l+r)/2;
		if(b<=m)ret=max(ret,query(x*2,l,m,b,e));
		if(e>m)ret=max(ret,query(x*2+1,m+1,r,b,e));
		return ret;
	}
}
void modify(int x,int l,int r,int b,int e,ll d){
	down(x,l,r);
	if(b<=l&&e>=r)del[x]=d,edel[x]=max(0ll,d);
	else{
		int m=(l+r)/2;
		if(b<=m)modify(x*2,l,m,b,e,d);
		if(e>m)modify(x*2+1,m+1,r,b,e,d);
		update(x,l,r);
	}
}
int n,m,a[N];ll ans[N];
vector<int>lft[N],idx[N];
int main(){
	sf("%d",&n);lp(i,1,n)sf("%d",&a[i]);
	sf("%d",&m);lp(i,1,m){int l,r;sf("%d%d",&l,&r);lft[r].pb(l);idx[r].pb(i);}
	map<int,int>pre;
	lp(i,1,n){
		modify(1,1,n,pre[a[i]]+1,i,a[i]);
		vp(j,lft[i]){
			ans[idx[i][j]]=query(1,1,n,lft[i][j],i);
		}
		pre[a[i]]=i;
	}
	lp(i,1,m)pf("%lld\n",ans[i]);
	return 0;
}
