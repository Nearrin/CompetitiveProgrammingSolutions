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
int n,m;ll p;
ll mul[100010*4],add[100010*4],sum[100010*4],siz[100010*4];
void down(int x,int l,int r){
	if(l!=r){
		mul[x*2]=mul[x]*mul[x*2]%p;
		add[x*2]=(add[x*2]*mul[x]%p+add[x])%p;
		mul[x*2+1]=mul[x]*mul[x*2+1]%p;
		add[x*2+1]=(add[x*2+1]*mul[x]%p+add[x])%p;
	}
	sum[x]=(sum[x]*mul[x]%p+siz[x]*add[x]%p)%p;
	mul[x]=1;
	add[x]=0;
}
void update(int x,int l,int r){
	int m=(l+r)/2;
	down(x*2,l,m);
	down(x*2+1,m+1,r);
	sum[x]=sum[x*2]+sum[x*2+1];
	siz[x]=siz[x*2]+siz[x*2+1];
}
void build(int x,int l,int r){
	mul[x]=1;add[x]=0;
	if(l==r){sf("%lld",&sum[x]);sum[x]%=p;siz[x]=1;}
	else{
		int m=(l+r)/2;
		build(x*2,l,m);
		build(x*2+1,m+1,r);
		update(x,l,r);
	}
}
void make(int x,int l,int r,int b,int e,ll t1,ll t2){
	down(x,l,r);
	if(b<=l&&e>=r)mul[x]=t1,add[x]=t2;
	else{
		int m=(l+r)/2;
		if(b<=m)make(x*2,l,m,b,e,t1,t2);
		if(e>m)make(x*2+1,m+1,r,b,e,t1,t2);
		update(x,l,r);
	}
}
ll ask(int x,int l,int r,int b,int e){
	down(x,l,r);
	if(b<=l&&e>=r)return sum[x];
	else{
		int m=(l+r)/2;ll ret=0;
		if(b<=m)ret+=ask(x*2,l,m,b,e);
		if(e>m)ret+=ask(x*2+1,m+1,r,b,e);
		return ret%p;
	}
}
int main(){
	sf("%d%lld",&n,&p);
	build(1,1,n);
	sf("%d",&m);
	lp(i,1,m){
		int op;sf("%d",&op);
		if(op==1){
			int l,r,c;sf("%d%d%d",&l,&r,&c);
			make(1,1,n,l,r,c,0);
		}else if(op==2){
			int l,r,c;sf("%d%d%d",&l,&r,&c);
			make(1,1,n,l,r,1,c);
		}else{
			int l,r;sf("%d%d",&l,&r);
			pf("%lld\n",ask(1,1,n,l,r));
		}
	}
	return 0;
}
