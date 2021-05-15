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
等价于选最多边满足条件
必然存在一种方案，所有(u,v)u>k,v>k都选，调整法易证
*/
int pr[1000010];
int u[2000010],v[2000010],n,m,k;
int fd(int x){return x==pr[x]?x:pr[x]=fd(pr[x]);}
int main(){
	sf("%d%d%d",&n,&m,&k);
	lp(i,1,n)pr[i]=i;
	lp(i,1,m){
		sf("%d%d",&u[i],&v[i]);
		if(u[i]>k&&v[i]>k){
			if(fd(u[i])!=fd(v[i])){
				pr[fd(u[i])]=v[i];
			}
		}
	}
	int ans=0;
	lp(i,1,m){
		if(u[i]<=k||v[i]<=k){
			if(fd(u[i])!=fd(v[i])){
				pr[fd(u[i])]=v[i];
			}else ++ans;
		}
	}
	pf("%d\n",ans);
	return 0;
}
