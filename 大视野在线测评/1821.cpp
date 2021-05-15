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
#include<cmath>
struct edge{
	int u,v;double d;
};
bool operator<(edge a,edge b){
	return a.d<b.d;
}
double x[1010],y[1010];int n,k;
int pr[1010];
int fd(int x){return x==pr[x]?x:pr[x]=fd(pr[x]);}
int main(){
	sf("%d%d",&n,&k);
	lp(i,1,n)sf("%lf%lf",x+i,y+i);
	vector<edge>egs;
	lp(i,1,n)lp(j,1,n){
		edge t;t.u=i;t.v=j;
		t.d=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
		egs.pb(t);
	}
	sort(egs.begin(),egs.end());int nc=n;
	lp(i,1,n)pr[i]=i;
	vp(i,egs){
		if(nc==k)break;
		int u=egs[i].u,v=egs[i].v;
		if(fd(u)!=fd(v))pr[fd(u)]=v,--nc;
	}
	vp(i,egs){
		int u=egs[i].u,v=egs[i].v;
		if(fd(u)!=fd(v)){pf("%.2lf\n",sqrt(egs[i].d));break;}
	}
	return 0;
}
