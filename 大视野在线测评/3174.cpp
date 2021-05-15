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
pair<int,int>peo[2010];int n,h;
bool cmp(pair<int,int>a,pair<int,int>b){
	return a.first+a.second<b.first+b.second;
}
int f[2010][2010],s[2010];
int main(){
	sf("%d",&n);
	lp(i,1,n)sf("%d%d",&peo[i].first,&peo[i].second);
	sf("%d",&h);
	sort(peo+1,peo+n+1,cmp);
	rp(i,n,1)s[i]=s[i+1]+peo[i].first;
	lp(i,1,n){
		lp(j,0,i){
			f[i][j]=-1;
			if(j!=i&&f[i-1][j]!=-1)
				f[i][j]=max(f[i][j],f[i-1][j]+peo[i].first);
			if(j!=0&&f[i-1][j-1]!=-1&&s[i]+f[i-1][j-1]+peo[i].second>=h)
				f[i][j]=max(f[i][j],f[i-1][j-1]);
			//pf("(%d,%d,%d)\n",i,j,f[i][j]);
		}
	}
	int ans=0;lp(i,1,n)if(f[n][i]!=-1)ans=i;
	pf("%d\n",ans);
	return 0;
}
