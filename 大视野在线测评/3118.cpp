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
namespace simplex{
	double n,m,a[1010][30010],eps=1e-5,inf=1e100;
	double myabs(double a){return a>0?a:-a;}
	void pivot(int l,int e){
		double t=-a[l][e];a[l][e]=-1;
		vector<int>qu;
		lp(i,0,m)if(myabs(a[l][i]/=t)>eps)qu.pb(i);
		lp(i,0,n){
			if(i!=l&&myabs(a[i][e])>eps){
				double t2=a[i][e];a[i][e]=0;
				vp(j,qu){
					a[i][qu[j]]+=a[l][qu[j]]*t2;
				}
			}
		}
	}
	double solve(){
		while(true){
			int e=-1;
			lp(i,1,m)if(a[0][i]>eps){e=i;break;}
			if(e==-1)return a[0][0];
			int l=-1;double t=inf;
			lp(i,1,n)if(a[i][e]<-eps&&a[i][0]/-a[i][e]<t){
				t=a[i][0]/-a[i][e];
				l=i;
			}
			pivot(l,e);
		}
	}
}
namespace graph{
	int n,m,uu[1010],vv[1010],ww[1010],aa[1010],bb[1010],ff[1010];
	vector<int>to[310],idx[310];
	struct tri{
		int x,y,z;
	};
	vector<tri>ret;
	bool dfs(int u,int p,int v,int id){
		if(u==v)return true;
		vp(i,to[u]){
			if(to[u][i]!=p){
				if(dfs(to[u][i],u,v,id)){
					tri tmp;
					tmp.x=id;
					tmp.y=idx[u][i];
					if(ww[id]<ww[idx[u][i]]){
						tmp.z=ww[idx[u][i]]-ww[id];
						ret.pb(tmp);
					}
					return true;
				}
			}
		}
		return false;
	}
	void run(){
		sf("%d%d",&n,&m);
		lp(i,1,m){
			sf("%d%d%d%d%d%d",&uu[i],&vv[i],&ww[i],&ff[i],&aa[i],&bb[i]);
			if(ff[i]==1){
				to[uu[i]].pb(vv[i]);
				idx[uu[i]].pb(i);
				to[vv[i]].pb(uu[i]);
				idx[vv[i]].pb(i);
			}
		}
		lp(i,1,m)if(ff[i]!=1)dfs(uu[i],0,vv[i],i);
		//vp(i,ret)pf("[%d,%d,%d]\n",ret[i].x,ret[i].y,ret[i].z);
		simplex::n=m;
		simplex::m=ret.size();
		lp(i,1,ret.size()){
			int u=ret[i-1].x,v=ret[i-1].y,w=ret[i-1].z;
			simplex::a[u][i]=-1;
			simplex::a[v][i]=-1;
			simplex::a[0][i]=w;
		}
		lp(i,1,m){
			if(ff[i]==1)simplex::a[i][0]=bb[i];
			else simplex::a[i][0]=aa[i];
		}
	}
	
}
int main(){
	graph::run();
	/*lp(i,0,simplex::n){
		lp(j,0,simplex::m){
			pf("%lf ",simplex::a[i][j]);
		}
		pf("\n");
	}*/
	pf("%d\n",int(simplex::solve()+0.5));
	return 0;
}
