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
#include<deque>
int n,m,f[200010];
int lft[200010],rgh[200010];
int main(){
	sf("%d%d",&n,&m);
	lp(i,0,n+1)rgh[i]=n+1;
	lp(i,0,n)lft[i]=i+1;
	lp(i,1,m){
		int a,b;sf("%d%d",&a,&b);
		rgh[a-1]=min(rgh[a-1],b);
		lft[a]=max(lft[a],b+1);
	}
	//lp(i,0,n)pf("[%d,%d]\n",lft[i],rgh[i]);
	rp(i,n-1,0)rgh[i]=min(rgh[i],rgh[i+1]);
	lp(i,1,n)lft[i]=max(lft[i],lft[i-1]);
	//lp(i,0,n)pf("[%d,%d]\n",lft[i],rgh[i]);
	f[n+1]=0;deque<int>qu;
	rp(i,n,0){
		rp(j,lft[i+1]-1,lft[i]){
			while(!qu.empty()&&f[qu.back()]<=f[j])qu.pop_back();
			qu.pb(j);
		}
		while(!qu.empty()&&qu.front()>rgh[i])qu.pop_front();
		if(lft[i]<=rgh[i]){
			if(f[qu.front()]==-1)f[i]=-1;
			else f[i]=f[qu.front()]+1;
		}else{
			//if(lft[i]==n+1)f[i]=1;
			f[i]=-1;
		}
	}
	//lp(i,0,n)pf("[%d]",f[i]);pf("\n");
	pf("%d\n",f[0]==-1?-1:f[0]-1);
	return 0;
}
