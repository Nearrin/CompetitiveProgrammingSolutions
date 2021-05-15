#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#define sf scanf
#define pf printf
#define fr(a,b,c) freopen(a,b,c)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int mx=2000000;
int to[mx+10],wei[mx+10],nx[mx+10],nw=1;
int bg[mx+10];int siz[mx+10];int n;
void add(int u,int v,int w){to[++nw]=v;wei[nw]=w;nx[nw]=bg[u];bg[u]=nw;}
int st[mx+10],tmp[mx+10],pr[mx+10],pw[mx+10];
int main(){
	//fr("data.in","r",stdin);
	//fr("hehe.out","w",stdout);
	sf("%d",&n);
	lp(i,1,n-1){
		int u,v,w;sf("%d%d%d",&u,&v,&w);
		add(u,v,w);add(v,u,w);
	}
	pr[1]=0;
	queue<int> qu;qu.push(1);st[1]=1;
	while(!qu.empty()){
		int u=qu.front();qu.pop();
		tmp[++tmp[0]]=u;
		for(int i=bg[u];i;i=nx[i])if(!st[to[i]])qu.push(to[i]),st[to[i]]=1,pr[to[i]]=u,pw[to[i]]=wei[i];
	}
	long long ans=0;
	lp(i,1,n)siz[i]=1;
	for(int i=tmp[0];i;--i){
		if(pr[tmp[i]]!=0){
			siz[pr[tmp[i]]]+=siz[tmp[i]];
			ans+=((long long)abs(siz[tmp[i]]-(n-siz[tmp[i]])))*pw[tmp[i]];
		}
	}
	pf("%lld\n",ans);
	return 0;
}
