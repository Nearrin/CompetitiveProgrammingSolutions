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
int n,ch[110][2],pr[110],rt=1;
int main(){
	//fr("heap.in","r",stdin);
	//fr("heap.out","w",stdout);
	sf("%d",&n);
	lp(i,2,n+1){
		int d;sf("%d",&d);
		if(d<100){
			pr[i]=d+1;
			ch[d+1][0]=i;
		}else{
			pr[i]=d-100+1;
			ch[d-100+1][1]=i;
		}
	}
	vector<int>ans;
	lp(i,1,n+1){
		int u=rt;while(ch[u][1])u=ch[u][0];
		if(ch[u][0]&&!ch[ch[u][0]][0])u=ch[u][0];
		ans.pb(u);
		pr[ch[u][0]]=pr[u];if(pr[u]==0)rt=ch[u][0];
		ch[pr[u]][0]=ch[u][0];
		for(int j=pr[u];j;j=pr[j])swap(ch[j][0],ch[j][1]);
	}
	wp(i,ans)pf("%d ",ans[i]-1);
	return 0;
}
