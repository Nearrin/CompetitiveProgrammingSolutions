#include<cstdio>
#include<algorithm>
#include<vector>
#define sf scanf
#define pf printf
#define fr(a,b,c) freopen(a,b,c)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int n,m,k,e,busy[21],dis[21];
vector<int> to[21],wei[21],bbg[21],eed[21];
int bellman(int bg,int ed){
	lp(i,1,m)busy[i]=0;
	lp(i,1,m)lp(j,0,int(bbg[i].size()-1)){
		int l=bbg[i][j],r=eed[i][j];
		if(!(r<bg||l>ed)){
			busy[i]=1;break;
		}
	}
	dis[1]=0;lp(i,2,m)dis[i]=~0u>>2;
	lp(cnt,1,m){
		lp(i,1,m){
			if(busy[i])continue;
			lp(j,0,int(to[i].size()-1)){
				int u=i,v=to[i][j],w=wei[i][j];
				if(busy[v])continue;
				if(dis[u]+w<dis[v])dis[v]=dis[u]+w;
			}
		}
	}
	return dis[m];
}
int f[110];
int main(){
	//fr("data.in","r",stdin);
	//fr("hehe.out","w",stdout);
	sf("%d%d%d%d",&n,&m,&k,&e);
	lp(i,1,e){
		int u,v,w;sf("%d%d%d",&u,&v,&w);
		to[u].push_back(v);wei[u].push_back(w);
		to[v].push_back(u);wei[v].push_back(w);
	}
	int d;sf("%d",&d);
	lp(i,1,d){
		int u,v,w;sf("%d%d%d",&u,&v,&w);
		bbg[u].push_back(v);
		eed[u].push_back(w);
	}
	lp(i,1,n){
		f[i]=~0u>>2;
		lp(j,1,i){
			int t=bellman(j,i);
			if(t!=~0u>>2)
				f[i]=min(f[i],f[j-1]+(i-j+1)*t+k);
		}
		
	}
	pf("%d\n",f[n]-k);
    return 0;
} 
