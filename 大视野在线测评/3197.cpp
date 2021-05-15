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
namespace mcmf{
	struct edge{
		edge(int x,int y,int z):
			v(x),c(y),w(z){}
		int v,c,w;
	};
	vector<edge>eg;
	vector<int>bg[1010];
	int vcnt,cst;
	void init(){
		lp(i,1,vcnt)bg[i].clear();
		eg.clear();
		cst=0;
	}
	void add(int u,int v,int c,int w){
		bg[u].pb(eg.size());
		eg.pb(edge(v,c,w));
		//pf("(%d,%d,%d,%d)\n",u,v,c,w);
	}
	int vis[1010],dis[1010];
	bool spfa(){
		lp(i,2,vcnt)dis[i]=~0u>>1,vis[i]=0;
		dis[1]=0;vis[1]=1;
		queue<int>qu;qu.push(1);vis[1]=1;
		while(!qu.empty()){
			int u=qu.front();qu.pop();vis[u]=0;
			vp(i,bg[u]){
				edge&e=eg[bg[u][i]],&ev=eg[bg[u][i]^1];
				if(e.c&&dis[e.v]>dis[u]+e.w){
					dis[e.v]=dis[u]+e.w;
					if(!vis[e.v]){
						vis[e.v]=1;
						qu.push(e.v);
					}
				}
			}
		}
		return dis[vcnt]!=~0u>>1;
	}
	int dfs(int u,int f){
		if(u==vcnt)return f;
		int g=f;vis[u]=1;
		vp(i,bg[u]){
			edge&e=eg[bg[u][i]],&ev=eg[bg[u][i]^1];
			if(e.c&&!vis[e.v]&&dis[e.v]==dis[u]+e.w){
				int t=dfs(e.v,min(g,e.c));
				g-=t;e.c-=t;ev.c+=t;cst+=e.w*t;
				if(!g)return f;
			}
		}
		return f-g;
	}
	int run(){
		int ret=0;
		while(spfa()){
			int t;do{
				fill(vis+1,vis+vcnt+1,0);
				ret+=(t=dfs(1,~0u>>1));
			}while(t);
		}
		return ret;
	}
}
vector<int>to[1010];int n,vala[1010],valb[1010],ans=~0u>>1;
vector<int>center;
namespace calccenter{
	int siza[1010],maxa[1010];
	void dfsa(int u,int p){
		siza[u]=1;
		vp(i,to[u]){
			if(to[u][i]!=p){
				dfsa(to[u][i],u);
				siza[u]+=siza[to[u][i]];
				maxa[u]=max(maxa[u],siza[to[u][i]]);
			}
		}
	}
	void run(){
		dfsa(1,0);int tm=~0u>>1;
		lp(i,1,n){
			maxa[i]=max(maxa[i],n-siza[i]);
			tm=min(tm,maxa[i]);
		}
		lp(i,1,n){
			if(maxa[i]==tm)
				center.pb(i);
		}
		//vp(i,center)pf("[%d]",center[i]);pf("\n");
	}
}
namespace orzsevenk{
	int can[1010][1010];
	vector<int>levela[1010];
	vector<int>levelb[1010];
	vector<int>cha[1010],chb[1010];
	int depa[1010],depb[1010];
	int siza[1010],sizb[1010];
	void dfsa(int u,int p){
		cha[p].pb(u);
		depa[u]=depa[p]+1;
		siza[u]=1;
		levela[depa[u]].pb(u);
		vp(i,to[u]){
			if(to[u][i]!=p){
				dfsa(to[u][i],u);
				siza[u]+=siza[to[u][i]];
			}
		}
	}
	void dfsb(int u,int p){
		chb[p].pb(u);
		depb[u]=depb[p]+1;
		sizb[u]=1;
		levelb[depb[u]].pb(u);
		vp(i,to[u]){
			if(to[u][i]!=p){
				dfsb(to[u][i],u);
				sizb[u]+=sizb[to[u][i]];
			}
		}
	}
	void run(int roota,int rootb){
		lp(i,1,n)levela[i].clear();
		lp(i,1,n)levelb[i].clear();
		lp(i,1,n)cha[i].clear();
		lp(i,1,n)chb[i].clear();
		dfsa(roota,0);
		dfsb(rootb,0);
		/*lp(i,1,n){
			vp(j,levela[i])pf("[%d]",levela[i][j]);
			pf("\n");
		}
		pf("\n");
		lp(i,1,n){
			vp(j,levelb[i])pf("[%d]",levelb[i][j]);
			pf("\n");
		}
		pf("\n\n");*/
		rp(lev,n,1){
			vp(ii,levela[lev])vp(jj,levelb[lev]){
				int ua=levela[lev][ii];
				int ub=levelb[lev][jj];
				if(cha[ua].size()!=chb[ub].size())can[ua][ub]=-1;
				else if(cha[ua].size()==0)can[ua][ub]=(vala[ua]!=valb[ub]);
				else{
					//pf("[%d,%d,%d]\n",ua,ub,lev);
					mcmf::vcnt=cha[ua].size()*2+2;
					mcmf::init();
					vp(iii,cha[ua]){
						vp(jjj,chb[ub]){
							int va=cha[ua][iii];int idva=iii+1+1;
							int vb=chb[ub][jjj];int idvb=jjj+2+cha[ua].size();
							//pf("{%d,%d,%d,%d}\n",va,idva,vb,idvb);
							if(can[va][vb]!=-1){
								mcmf::add(idva,idvb,1,can[va][vb]);
								mcmf::add(idvb,idva,0,-can[va][vb]);
							}
						}
					}
					vp(iii,cha[ua]){
						int va=cha[ua][iii];;int idva=iii+1+1;
						mcmf::add(1,idva,1,0);
						mcmf::add(idva,1,0,0);
					}
					vp(jjj,chb[ub]){
						int vb=chb[ub][jjj];int idvb=jjj+2+cha[ua].size();
						mcmf::add(idvb,mcmf::vcnt,1,0);
						mcmf::add(mcmf::vcnt,idvb,0,0);
					}
					if(mcmf::run()!=cha[ua].size())can[ua][ub]=-1;
					else can[ua][ub]=mcmf::cst+(vala[ua]!=valb[ub]);
				}
			}
		}
		//lp(i,1,n)pf("[%d]\n",can[i][i]);
		if(can[roota][rootb]!=-1)
			ans=min(ans,can[roota][rootb]);
	}
}
int main(){
	sf("%d",&n);
	lp(i,1,n-1){
		int u,v;sf("%d%d",&u,&v);
		to[u].pb(v);
		to[v].pb(u);
	}
	lp(i,1,n)sf("%d",&vala[i]);
	lp(i,1,n)sf("%d",&valb[i]);
	calccenter::run();
	//orzsevenk::run(1,1);
	vp(i,center)vp(j,center)orzsevenk::run(center[i],center[j]);
	pf("%d\n",ans);
	return 0;
}
