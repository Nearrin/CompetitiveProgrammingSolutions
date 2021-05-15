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
char map[4010][4010];int w,h,ans;
struct point{
	point(int a,int b):
		x(a),y(b){}
	int x,y;
};
int main(){
	sf("%d%d",&h,&w);
	lp(i,1,h)sf("%s",map[i]+1);
	char cur=(map[1][1]=='F'?'R':'F');
	queue<point>qu;qu.push(point(1,1));map[1][1]='.';
	while(!qu.empty()){
		//pf("[%d]\n",(int)qu.size());
		if(cur=='F')cur='R';
		else cur='F';
		queue<point>tq;++ans;
		while(!qu.empty()){
			int x=qu.front().x,y=qu.front().y;qu.pop();
			if(x!=1&&map[x-1][y]!='.'){
				if(map[x-1][y]==cur)qu.push(point(x-1,y));
				else tq.push(point(x-1,y));
				map[x-1][y]='.';
			}
			if(x!=h&&map[x+1][y]!='.'){
				if(map[x+1][y]==cur)qu.push(point(x+1,y));
				else tq.push(point(x+1,y));
				map[x+1][y]='.';
			}
			if(y!=1&&map[x][y-1]!='.'){
				if(map[x][y-1]==cur)qu.push(point(x,y-1));
				else tq.push(point(x,y-1));
				map[x][y-1]='.';
			}
			if(y!=w&&map[x][y+1]!='.'){
				if(map[x][y+1]==cur)qu.push(point(x,y+1));
				else tq.push(point(x,y+1));
				map[x][y+1]='.';
			}
		}
		qu=tq;
	}
	pf("%d\n",ans);
	return 0;
}
