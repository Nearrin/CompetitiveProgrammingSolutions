#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define pb push_back
#define mp make_pair
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
#define vp(i,v) for(int i=0;i<v.size();++i)
#define wp(i,v) for(int i=int(v.size()-1);i>=0;--i)
using namespace std;
typedef long long ll;
int n,m,d[10010],f[10010][510];
int main(){
	sf("%d%d",&n,&m);
	lp(i,1,n)sf("%d",&d[i]);
	rp(i,n-1,1){
		lp(j,0,min(n-i,m)){
			if(j==0)f[i][j]=max(f[i+1][j],f[i+1][j+1]+d[i]);
			else if(j==min(n-i,m))f[i][j]=f[i+j][0];
			else f[i][j]=max(f[i+j][0],f[i+1][j+1]+d[i]);
		}
	}
	pf("%d\n",f[1][0]);
	return 0;
}
