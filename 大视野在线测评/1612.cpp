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
int can[110][110],n,m;
int main(){
	sf("%d%d",&n,&m);
	lp(i,1,m){
		int u,v;sf("%d%d",&u,&v);
		can[u][v]=1;
	}
	lp(k,1,n)
		lp(i,1,n)
			lp(j,1,n)
				if(can[i][k]&&can[k][j])
					can[i][j]=1;
	int ans=0;
	lp(i,1,n){
		int flg=1;
		lp(j,1,n){
			if(j!=i){
				if(!can[i][j]&&!can[j][i])
					flg=0;
			}
		}
		ans+=flg;
	}
	pf("%d\n",ans);
    return 0;
}
