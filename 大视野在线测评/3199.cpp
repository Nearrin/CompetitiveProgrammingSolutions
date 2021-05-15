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
#include<complex>
#include<deque>
#include<queue>
namespace hpi{ 
	double myabs(double a){
		return a>0?a:-a;
	}
    double eps=1e-8;
    typedef complex<double>point;
    double det(point a,point b){
        return imag(conj(a)*b);
    }
    struct line{
        line(point d,point e,int i):
            p(d),q(e),a(arg(q-p)),id(i){}
        point p,q;double a;int id;
    };
    point operator*(line d,line e){
        point p1=d.p,q1=d.q,p2=e.p,q2=e.q;
        double a1=det(p2-q1,q2-p2),a2=det(p1-q2,q2-p2);
        return (a1*p1+a2*q1)/(a1+a2);
    }
    bool operator<(line a,line b){
        if(myabs(a.a-b.a)>eps)return a.a<b.a;
        else return det(a.q-b.p,b.q-b.p)<-eps;
    }
    vector<line>lns;
    deque<line>ans;
    void init(){
    	lns.clear();
    	ans.clear();
	}
	void add(double x1,double y1,double x2,double y2,int id){
		lns.pb(line(point(x1,y1),point(x2,y2),id));
	}
    bool left(line a,line b,line c){
        point t=a*b;
        return det(t-c.p,c.q-c.p)<-eps;
    }
    void solve(){
        sort(lns.begin(),lns.end());
        lp(i,0,int(lns.size()-1)){
            while(ans.size()>1&&!left(ans.back(),ans[ans.size()-2],lns[i]))
                ans.pop_back();
            while(ans.size()>1&&!left(ans[0],ans[1],lns[i]))
                ans.pop_front();
            if(ans.empty()||myabs(ans.back().a-lns[i].a)>eps)
                ans.push_back(lns[i]);
        }
        while(ans.size()>1&&!left(ans[ans.size()-1],ans[ans.size()-2],ans.front()))
            ans.pop_back();
        if(ans.size()<3)ans.clear();
    }
}
namespace bfs{
	int vcnt;
	int dis[1010],vis[1010];
	vector<int>to[1010];
	void init(){
		lp(i,1,vcnt)to[i].clear();
		lp(i,1,vcnt)vis[i]=0;
	}
	void add(int u,int v){
		to[u].pb(v);
		to[v].pb(u);
	}
	int run(int st,int et){
		dis[st]=0;vis[st]=1;
		queue<int>qu;qu.push(st);
		while(!qu.empty()){
			int u=qu.front();qu.pop();
			vp(i,to[u]){
				if(!vis[to[u][i]]){
					vis[to[u][i]]=1;
					dis[to[u][i]]=dis[u]+1;
					qu.push(to[u][i]);
				}
			}
		}
		return dis[et];
	}
}
int main(){
	int test;sf("%d",&test);
	lp(kase,1,test){
		int n,x1,y1,x0,y0,st=-1,et;
		sf("%d%d%d%d%d",&n,&x1,&y1,&x0,&y0);
		static double tx[1010],ty[1010];et=n+1;
		lp(i,1,n)sf("%lf%lf",&tx[i],&ty[i]);
		bfs::vcnt=n+1;
		bfs::init();
		double bestdis;int bestst=-1;
		lp(i,1,n){
			if(bestst==-1||double(tx[i]-x0)*double(tx[i]-x0)+double(ty[i]-y0)*double(ty[i]-y0)<bestdis){
				bestdis=double(tx[i]-x0)*double(tx[i]-x0)+double(ty[i]-y0)*double(ty[i]-y0);
				bestst=i;
			}
		}
		st=bestst;
		lp(i,1,n){
			hpi::init();
			hpi::add(0,0,x1,0,n+1);
			hpi::add(x1,0,x1,y1,n+1);
			hpi::add(x1,y1,0,y1,n+1);
			hpi::add(0,y1,0,0,n+1);
			lp(j,1,n)if(j!=i){
				double vx=tx[j]-tx[i];
				double vy=ty[j]-ty[i];
				double vvx=-vy;
				double vvy=vx;
				double mx=(tx[j]+tx[i])/2;
				double my=(ty[j]+ty[i])/2;
				hpi::add(mx,my,mx+vvx,my+vvy,j);
			}
			hpi::solve();
			vp(j,hpi::ans){
				bfs::add(i,hpi::ans[j].id);
			}
		}
		pf("%d\n",bfs::run(st,et));
	}
	return 0;
}
