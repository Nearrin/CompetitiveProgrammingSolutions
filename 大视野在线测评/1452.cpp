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
int db[110][310][310],n,m;
void add(int t,int x,int y,int d){
	for(int i=x;i<=n;i+=i&-i)
		for(int j=y;j<=m;j+=j&-j)
			db[t][i][j]+=d;
}
int ask(int t,int x,int y){
	int r=0;
	for(int i=x;i;i-=i&-i)
		for(int j=y;j;j-=j&-j)
			r+=db[t][i][j];
	return r;
}
int val[310][310];
int main(){
	sf("%d%d",&n,&m);
	lp(i,1,n)lp(j,1,m){
		int t;sf("%d",&t);val[i][j]=t;
		add(t,i,j,1);
	}
	int q;sf("%d",&q);
	lp(i,1,q){
		int op;sf("%d",&op);
		if(op==1){
			int x,y,c;sf("%d%d%d",&x,&y,&c);
			add(val[x][y],x,y,-1);
			add(val[x][y]=c,x,y,1);
		}else{
			int x1,x2,y1,y2,c;
			sf("%d%d%d%d%d",&x1,&x2,&y1,&y2,&c);
			pf("%d\n",ask(c,x2,y2)-ask(c,x1-1,y2)-ask(c,x2,y1-1)+ask(c,x1-1,y1-1));
		}
	}
	return 0;
}
