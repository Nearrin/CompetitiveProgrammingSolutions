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
int sam[500010],rev[500010],val[500010];
void build(int x,int l,int r){
	sam[x]=-1;rev[x]=0;
	if(l!=r){
		int m=(l+r)/2;
		build(x*2,l,m);
		build(x*2+1,m+1,r);
	}
}
void down(int x,int l,int r){
	if(sam[x]!=-1){
		if(l!=r)sam[x*2]=sam[x*2+1]=sam[x],rev[x*2]=rev[x*2+1]=0;
		else val[x]=sam[x];
		sam[x]=-1;
	}
	if(rev[x]){
		if(l!=r)rev[x*2]^=1,rev[x*2+1]^=1;
		else val[x]^=1;
		rev[x]=0;
	}
}
void same(int x,int l,int r,int b,int e,int t){
	down(x,l,r);
	if(b<=l&&e>=r)sam[x]=t;
	else{
		int m=(l+r)/2;
		if(b<=m)same(x*2,l,m,b,e,t);
		if(e>m)same(x*2+1,m+1,r,b,e,t);
	}
}
void rever(int x,int l,int r,int b,int e){
	down(x,l,r);
	if(b<=l&&e>=r)rev[x]=1;
	else{
		int m=(l+r)/2;
		if(b<=m)rever(x*2,l,m,b,e);
		if(e>m)rever(x*2+1,m+1,r,b,e);
	}
}
struct rag{char l,r;int a,b;};
pair<int,int> getrag(){
	rag t;
	for(t.l=getchar();t.l!='['&&t.l!='(';t.l=getchar());
	sf("%d",&t.a);
	for(char c=getchar();c!=',';c=getchar());
	sf("%d",&t.b);
	for(t.r=getchar();t.r!=']'&&t.r!=')';t.r=getchar());
	int va=t.a*2,vb=t.b*2;
	if(t.l=='(')++va;
	if(t.r==')')--vb;
	return mp(va,vb);
}
int access(int x,int l,int r,int p){
	down(x,l,r);
	if(l==r)return val[x];
	else{
		int m=(l+r)/2;
		if(p<=m)return access(x*2,l,m,p);
		else return access(x*2+1,m+1,r,p);
	}
}
char getop(){
	char c;
	for(c=getchar();c!='U'&&c!='I'&&c!='D'&&c!='C'&&c!='S'&&c!=EOF;c=getchar());
	return c;
}
int main(){
	build(1,0,65536*2+1);
	while(true){
		char op=getop();if(op==EOF)break;pair<int,int>rg=getrag();
		if(op=='U'){
			same(1,0,65536*2+1,rg.first,rg.second,1);
		}else if(op=='I'){
			if(rg.first!=0)same(1,0,65536*2+1,0,rg.first-1,0);
			same(1,0,65536*2+1,rg.second+1,65536*2+1,0);
		}else if(op=='D'){
			same(1,0,65536*2+1,rg.first,rg.second,0);
		}else if(op=='S'){
			rever(1,0,65536*2+1,rg.first,rg.second);
		}else{
			if(rg.first!=0)same(1,0,65536*2+1,0,rg.first-1,0);
			same(1,0,65536*2+1,rg.second+1,65536*2+1,0);
			rever(1,0,65536*2+1,rg.first,rg.second);
		}
	}
	vector<int>ans;
	vector<rag>rgs;
	lp(i,0,65536*2)ans.pb(access(1,0,65536*2+1,i));
	vp(i,ans){
		if(!ans[i])continue;
		int j=i;
		while(j+1<ans.size()&&ans[j+1])++j;
		//pf("[%d,%d]\n",i,j);
		rag rr;
		if(i%2==0){
			rr.l='[';
			rr.a=i/2;
		}else{
			rr.l='(';
			rr.a=(i-1)/2;
		}
		if(j%2==0){
			rr.r=']';
			rr.b=j/2;
		}else{
			rr.r=')';
			rr.b=(j+1)/2;
		}
		rgs.pb(rr);
		i=j;
	}
	if(rgs.empty())pf("empty set\n");
	else{
		vp(i,rgs){
			pf("%c%d,%d%c ",rgs[i].l,rgs[i].a,rgs[i].b,rgs[i].r);
		}
	}
	return 0;
}
