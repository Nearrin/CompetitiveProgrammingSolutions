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
double L;int R,C;
char MAP[110][110];
pair<int,int>S,T;
struct node{
	node(pair<int,int>_p,double _d):
		p(_p),d(_d){}
	pair<int,int>p;double d;
};
bool operator<(node a,node b){
	return a.d>b.d;
}
double dijkstra(double v){
	static double dis[110][110];
	lp(i,1,R)lp(j,1,C)dis[i][j]=~0u>>1;
	dis[S.first][S.second]=0;
	priority_queue<node>qu;qu.push(node(S,0));
	while(true){
		node tmp=qu.top();qu.pop();
		if(dis[tmp.p.first][tmp.p.second]<tmp.d-1e-8)continue;
		if(tmp.p==T)return tmp.d;
		int x=tmp.p.first,y=tmp.p.second;double d=tmp.d;
		//pf("(%d,%d):%lf\n",x,y,d);
		if(x!=1&&MAP[x-1][y]!='#'){
			if(d+v<dis[x-1][y]-1e-8){
				dis[x-1][y]=d+v;
				qu.push(node(mp(x-1,y),d+v));
			}	
		}
		if(x!=R&&MAP[x+1][y]!='#'){
			if(d+v<dis[x+1][y]-1e-8){
				dis[x+1][y]=d+v;
				qu.push(node(mp(x+1,y),d+v));
			}	
		}
		if(y!=1&&MAP[x][y-1]!='#'){
			if(d+1<dis[x][y-1]-1e-8){
				dis[x][y-1]=d+1;
				qu.push(node(mp(x,y-1),d+1));
			}	
		}
		if(y!=C&&MAP[x][y+1]!='#'){
			if(d+1<dis[x][y+1]-1e-8){
				dis[x][y+1]=d+1;
				qu.push(node(mp(x,y+1),d+1));
			}	
		}
	}
}
char reader(){
	char ret;
	for(ret=getchar();ret!='#'&&ret!=' '&&ret!='S'&&ret!='E';ret=getchar());
	return ret;
}
int main(){
	int test;sf("%d",&test);
	lp(kase,1,test){
		sf("%lf%d%d",&L,&R,&C);while(getchar()!='\n');
		lp(i,1,R){
			lp(j,1,C){
				MAP[i][j]=reader();
				//pf("[%c]",MAP[i][j]);
			}
			if(i!=R)while(getchar()!='\n');
		}
		S=mp(-1,-1);
		T=mp(-1,-1);
		lp(i,1,R)lp(j,1,C){
			if(MAP[i][j]=='S')S=mp(i,j);
			else if(MAP[i][j]=='E')T=mp(i,j);
		}
		if(S.first<0||T.first<0)ps;
		//pf("[%d,%d][%d,%d]\n",S.first,S.second,T.first,T.second);
		double l=0,r=10;
		while(r-l>1e-8){
			double m=(l+r)/2;
			if(dijkstra(m)<L)l=m;
			else r=m;
		}
		pf("%.5lf\n",l);
	}
	return 0;
}
/*
2
2.5 4 5
#####
#S  #
#  E#
#####
21 13 12
############
#S##     #E#
# ##  #  # #
#   # #  # #
### # #  # #
#   # #  # #
#  ## #  # #
##  # #  # #
### # #  # #
##  # #  # #
#  ## #    #
#     #    #
############
*/
