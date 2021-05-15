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
struct point{
	int x,y;
}px[200010],py[200010];
int n;
double ans=1e100;
inline double sqr(double a){
	return a*a;
}
inline double operator*(point a,point b){
	return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
inline bool cmpx(point a,point b){
	return a.x<b.x;
}
inline bool cmpy(point a,point b){
	return a.y<b.y;
}
int tabs(int a){
	return a>0?a:-a;
}
void solve(int l,int r){
	if(l!=r){
		int m=(l+r)/2;
		solve(l,m);
		solve(m+1,r);
		inplace_merge(py+l,py+m+1,py+r+1,cmpy);
		int tx=px[m].x;
		vector<point>tmp;
		lp(i,l,r)if(tabs(tx-py[i].x)<ans/2)tmp.pb(py[i]);
		/*vp(i,tmp){
			pf("[%d,%d]",tmp[i].x,tmp[i].y);
		}
		pf("\n");*/
		vp(i,tmp){
			for(int j=i-1;j>=0&&tabs(tmp[j].y-tmp[i].y)<ans/2;--j){
				for(int k=i+1;k<tmp.size()&&tabs(tmp[k].y-tmp[i].y)<ans/2;++k){
					ans=min(ans,tmp[i]*tmp[j]+tmp[i]*tmp[k]+tmp[j]*tmp[k]);
					//pf("[%d,%d,%d,%.6lf]\n",i,j,k,ans);
				}
			}
		}
	}
}
int main(){
	sf("%d",&n);
	lp(i,1,n)sf("%d%d",&px[i].x,&px[i].y);
	sort(px+1,px+n+1,cmpx);
	lp(i,1,n)py[i]=px[i];
	solve(1,n);
	pf("%.6lf\n",ans);
	return 0;
}
