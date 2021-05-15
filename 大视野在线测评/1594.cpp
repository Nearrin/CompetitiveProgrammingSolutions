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
#include<map>
#include<queue>
int n,q;vector<vector<int> >a;
vector<int>rht1[1000010],wei1[1000010];
vector<int>lft2[1000010],wei2[1000010];
struct data{data(int x,int y,int z):l(x),r(y),v(z){}int l,r,v;};
bool operator<(data x,data y){return x.v<y.v;}
vector<vector<int> >b[25010];
int c[25010];
bool check(int m){
	lp(i,1,n)rht1[i].clear(),wei1[i].clear();
	lp(i,1,n)lft2[i].clear(),wei2[i].clear();
	lp(i,0,m){
		int l=a[i][0],r=a[i][1],v=a[i][2];
		rht1[l].pb(r);
		wei1[l].pb(v);
		//pf("(%d,%d,%d)\n",l,r,v);
	}
	int nw=0;lp(i,1,m+1)b[i].clear();map<int,int>pm;
	lp(i,0,m){
		int l=a[i][0],r=a[i][1],v=a[i][2];
		if(!pm[v])pm[v]=++nw,c[nw]=v;
		b[pm[v]].pb(a[i]);
	}
	lp(i,1,nw){
		int l=-(~0u>>1),r=~0u>>1,v=c[i];
		vp(j,b[i]){
			l=max(l,b[i][j][0]);
			r=min(r,b[i][j][1]);
		}
		lft2[r].pb(l);
		wei2[r].pb(v);
		//pf("{%d,%d,%d}\n",l,r,v);
	}
	map<int,int>lst;
	priority_queue<data>pq;
	lp(i,1,n){
		vp(j,rht1[i]){
			int l=i,r=rht1[i][j],v=wei1[i][j];
			pq.push(data(l,r,v));
		}
		while(!pq.empty()&&pq.top().r<i)pq.pop();
		if(!pq.empty())lst[pq.top().v]=i;
		vp(j,lft2[i]){
			int l=lft2[i][j],r=i,v=wei2[i][j];
			if(lst[v]<l)return false;
		}
	}
	return true;
}
int main(){
	sf("%d%d",&n,&q);
	lp(i,1,q){
		int l,r,v;sf("%d%d%d",&l,&r,&v);
		vector<int>t;t.pb(l);t.pb(r);t.pb(v);a.pb(t);
	}
	//pf("%d\n",(int)check(q-1));return 0;
	if(!check(0))pf("1\n");
	else if(check(q-1))pf("0\n");
	else{
		int l=0,r=q-1;
		while(l+1<r){
			int m=(l+r)/2;
			if(check(m))l=m;
			else r=m;
		}
		pf("%d\n",r+1);
	}
	//ps;
	return 0;
}
