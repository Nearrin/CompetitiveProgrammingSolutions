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
#include<set>
vector<int>pos[50010];int n,k;
struct node{
	node(vector<int>_p){
		mx=mi=p=_p;
		ch[0]=ch[1]=0;
	}
	vector<int>p,mx,mi;
	node*ch[2];
};
void update(node*x){
	lp(i,0,1)if(x->ch[i]){
		lp(j,0,k-1){
			x->mx[j]=max(x->mx[j],x->ch[i]->mx[j]);
			x->mi[j]=min(x->mi[j],x->ch[i]->mi[j]);
		}
	}
}
struct cmp{
	cmp(int _d):d(_d){}
	int d;
	bool operator()(vector<int> x,vector<int> y){
		return x[d]<y[d];
	}
};
node*build(int l,int r,int d){
	sort(pos+l,pos+r+1,cmp(d));
	int m=(l+r)/2;
	node*ret=new node(pos[m]);
	if(l!=m)ret->ch[0]=build(l,m-1,(d+1)%k);
	if(m!=r)ret->ch[1]=build(m+1,r,(d+1)%k);
	update(ret);
	return ret;
}
int sqr(int x){
	return x*x;
}
int guess(node*x,vector<int>&p){
	int ret=0;
	lp(i,0,k-1){
		if(p[i]<x->mi[i])ret+=sqr(x->mi[i]-p[i]);
		if(p[i]>x->mx[i])ret+=sqr(p[i]-x->mx[i]);
	}
	return ret;
}
int dist(vector<int>&p,vector<int>&q){
	int ret=0;
	lp(i,0,k-1)ret+=sqr(p[i]-q[i]);
	return ret;
}
void query(set<pair<int,vector<int> > >&ans,vector<int>&p,node*x){
	ans.insert(mp(dist(x->p,p),x->p));
	set<pair<int,vector<int> > >::iterator uu=ans.end();--uu;
	ans.erase(uu);
	int t1=x->ch[0]?guess(x->ch[0],p):~0u>>1;
	int t2=x->ch[1]?guess(x->ch[1],p):~0u>>1;
	if(t1<t2){
		if(t1<ans.rbegin()->first)query(ans,p,x->ch[0]);
		if(t2<ans.rbegin()->first)query(ans,p,x->ch[1]);
	}else{
		if(t2<ans.rbegin()->first)query(ans,p,x->ch[1]);
		if(t1<ans.rbegin()->first)query(ans,p,x->ch[0]);
	}
}
int main(){
	while(sf("%d%d",&n,&k)!=EOF){
		lp(i,1,n){
			pos[i].resize(k);
			lp(j,0,k-1)sf("%d",&pos[i][j]);
		}
		node*rt=build(1,n,0);
		int q;sf("%d",&q);
		lp(i,1,q){
			vector<int>tmp(k);
			lp(j,0,k-1)sf("%d",&tmp[j]);
			int m;sf("%d",&m);
			set<pair<int,vector<int> > >ans;
			lp(j,1,m)ans.insert(mp(~0u>>1,vector<int>(1,j)));
			query(ans,tmp,rt);
			pf("the closest %d points are:\n",m);
			lp(j,1,m){
				lp(u,0,k-1)pf("%d%c",ans.begin()->second[u],u==k-1?'\n':' ');
				ans.erase(ans.begin());
			}
		}
	}
	return 0;
}
