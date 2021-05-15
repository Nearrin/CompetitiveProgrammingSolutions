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
#include<queue>
#include<set>
set<pair<int,int> >bad;
int ex,ey,n;
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int main(){
	sf("%d%d%d",&ex,&ey,&n);
	lp(i,1,n){
		int a,b;sf("%d%d",&a,&b);
		bad.insert(mp(a,b));
	}
	queue<pair<int,pair<int,int> > >qu;
	qu.push(mp(0,mp(0,0)));bad.insert(mp(0,0));
	while(!qu.empty()){
		int d=qu.front().first,x=qu.front().second.first,y=qu.front().second.second;
		qu.pop();
		if(x==ex&&y==ey){pf("%d\n",d);return 0;}
		lp(i,0,3){
			int tx=x+dir[i][0],ty=y+dir[i][1];
			if(!bad.count(mp(tx,ty))){
				bad.insert(mp(tx,ty));
				qu.push(mp(d+1,mp(tx,ty)));
			}
		}
	}
	return 0;
}
