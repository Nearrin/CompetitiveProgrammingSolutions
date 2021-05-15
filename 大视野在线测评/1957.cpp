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
二分答案，被禁止区域必然是一个矩形
注意拓展过程需要n次迭代
*/
struct line{
	line(){
		sf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1==x2){
			if(y1>y2)swap(y1,y2);
		}else{
			if(x1>x2)swap(x1,x2);
		}
	}
	int x1,y1,x2,y2;
};
vector<line>lns;
int sx,sy,n;
bool check(int l){
	int xa=-l,ya=-l,xb=l,yb=l;
	lp(j,1,n)vp(i,lns){
		int x1=lns[i].x1,y1=lns[i].y1,x2=lns[i].x2,y2=lns[i].y2;
		//pf("[%d,%d,%d,%d]\n",xa,ya,xb,yb);
		//pf("[%d,%d,%d,%d]\n",x1,y1,x2,y2);
		if(x2<xa||x1>xb)continue;
		if(y2<ya||y1>yb)continue;
		if(x1==x2){
			ya=min(ya,y1);
			yb=max(yb,y2);
		}else{
			xa=min(xa,x1);
			xb=max(xb,x2);
		}
	}
	if(sx>=xa&&sx<=xb&&sy>=ya&&sy<=yb)return false;
	else return true;
}
int main(){
	sf("%d%d%d",&sx,&sy,&n);
	lp(i,1,n)lns.pb(line());
	int l=0,r=1000000;
	if(!check(l))pf("0\n");
	else{
		while(l+1<r){
			int m=(l+r)/2;
			if(check(m))l=m;
			else r=m;
		}
		pf("%d\n",r);
	}
	return 0;
}
