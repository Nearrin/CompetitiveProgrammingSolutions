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
char pm[110][110];int n,m,t,r1,c1,r2,c2;
int vis[110][110][20];
ll f[110][110][20];
ll dp(int x,int y,int tim){
	if(!vis[x][y][tim]){
		vis[x][y][tim]=1;
		if(tim==0)f[x][y][tim]=(x==r1&&y==c1);
		else{
			if(x!=1&&pm[x-1][y]!='*')f[x][y][tim]+=dp(x-1,y,tim-1);
			if(x!=n&&pm[x+1][y]!='*')f[x][y][tim]+=dp(x+1,y,tim-1);
			if(y!=1&&pm[x][y-1]!='*')f[x][y][tim]+=dp(x,y-1,tim-1);
			if(y!=m&&pm[x][y+1]!='*')f[x][y][tim]+=dp(x,y+1,tim-1);
		}
	}
	return f[x][y][tim];
}
int main(){
	sf("%d%d%d",&n,&m,&t);
	lp(i,1,n)sf("%s",pm[i]+1);
	sf("%d%d%d%d",&r1,&c1,&r2,&c2);
	pf("%lld\n",dp(r2,c2,t));
    return 0;
}
