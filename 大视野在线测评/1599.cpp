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
double f[110],g[110],h[110];
int main(){
	int s1,s2,s3;sf("%d%d%d",&s1,&s2,&s3);
	lp(i,1,s1)f[i]=1.0/s1;
	lp(i,1,s1+s2+s3){
		lp(k,1,min(s2,i-1))
			g[i]+=f[i-k]*1.0/s2;
	}
	lp(i,1,s1+s2+s3){
		lp(k,1,min(s3,i-1))
			h[i]+=g[i-k]*1.0/s3;
	}
	int ans=1;
	lp(i,2,s1+s2+s3)if(h[i]>h[ans]+1e-8)ans=i;
	pf("%d\n",ans);
	//lp(i,1,s1+s2+s3)pf("[%d,%lf]\n",i,h[i]);
	return 0;
}
