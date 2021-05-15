#include<cstdio>
#include<algorithm>
#include<vector>
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
#include<complex>
#include<deque>
typedef complex<double> point;
double eps=1e-16;
double dbs(double a){
	return a>0?a:-a;
}
struct data{
	int x1,y1,y2;
}ds[100010];int n;
struct line{
	line(point a,point b):
		p(a),q(b),ar(arg(q-p)){}
	point p,q;double ar;
};
double det(point a,point b){
	return imag(conj(a)*b);
}
point operator*(line a,line b){
	point p1=a.p,q1=a.q,p2=b.p,q2=b.q;
	double a1=det(p2-q1,q2-p2);
	double a2=det(p1-q2,q2-p2);
	return (a1*p1+a2*q1)/(a1+a2);
}
bool operator<(line a,line b){
	if(dbs(a.ar-b.ar)<eps)return det(a.q-a.p,b.q-a.p)<-eps;
	else return a.ar<b.ar;
}
bool onleft(line a,line b,line c){
	point t=a*b;
	return det(t-c.p,c.q-c.p)<-eps;
}
bool check(int lim){
	vector<line>lns;
	deque<line>ans;
	lp(i,1,lim){
		double x1=ds[i].x1,y1=ds[i].y1,y2=ds[i].y2;
		lns.pb(line(point(0.0,y1/x1),point(1.0,y1/x1-x1)));
		lns.pb(line(point(1.0,y2/x1-x1),point(0.0,y2/x1))); 
	}
	lns.pb(line(point(0.0,0.0),point(0.0,1e10)));
	lns.pb(line(point(0.0,1e10),point(-1e10,1e10)));
	lns.pb(line(point(-1e10,1e10),point(-1e10,0.0)));
	lns.pb(line(point(-1e10,0.0),point(0.0,0.0)));
	sort(lns.begin(),lns.end());
	vp(i,lns){
		while(ans.size()>1&&!onleft(ans.back(),ans[ans.size()-2],lns[i]))
			ans.pop_back();
		while(ans.size()>1&&!onleft(ans[0],ans[1],lns[i]))
			ans.pop_front();
		if(ans.empty()||dbs(ans.back().ar-lns[i].ar)>eps)ans.pb(lns[i]);
	}
	while(ans.size()>1&&!onleft(ans.back(),ans[ans.size()-2],ans.front()))
		ans.pop_back();
	return ans.size()>2;
}
int main(){
	sf("%d",&n);
	lp(i,1,n)sf("%d%d%d",&ds[i].x1,&ds[i].y1,&ds[i].y2);
	int l=1,r=n;
	if(check(r))pf("%d\n",r);
	else{
		while(l+1<r){
			int m=(l+r)/2;
			if(check(m))l=m;
			else r=m;
		}
		pf("%d\n",l);
	}
	return 0;
}
