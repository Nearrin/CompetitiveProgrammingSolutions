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
int m,n,st,et1,et2;
vector<int>to[100010],we[100010];
int run(int s,int t){
	static int dis[100010];
	lp(i,1,n)dis[i]=~0u>>1;
	dis[s]=0;
	priority_queue<pair<int,int> >qu;qu.push(mp(0,s));
	while(!qu.empty()){
		int u=qu.top().second,d=-qu.top().first;qu.pop();
		if(d!=dis[u])continue;
		//if(u==t)return d;
		vp(i,to[u]){
			int v=to[u][i],w=we[u][i];
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				qu.push(mp(-dis[v],v));
			}
		}
	}
	return dis[t];
}
int main(){
	sf("%d%d%d%d%d",&m,&n,&st,&et1,&et2);
	lp(i,1,m){
		int a,b,c;sf("%d%d%d",&a,&b,&c);
		to[a].pb(b);
		we[a].pb(c);
		to[b].pb(a);
		we[b].pb(c);
	}
	pf("%d\n",min(run(st,et1)+run(et1,et2),run(st,et2)+run(et1,et2)));
	return 0;
}
