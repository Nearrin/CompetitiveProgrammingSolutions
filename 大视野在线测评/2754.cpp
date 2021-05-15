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
#include<map>
#include<queue>
#include<string>
struct node{
	map<int,node*>tr;
	node*fa;int mrk,cnt,opt;
}nds[460010];int nw=1;
typedef map<int,node*>::iterator iter;
node*rt=nds;
int tmp[460010];int len;
node*insert(){
	node*x=rt;
	for(int i=1;i<=len;++i){
		if(!x->tr.count(tmp[i]))
			x->tr[tmp[i]]=&nds[nw++];
		x=x->tr[tmp[i]];
	}
	++x->opt;
	return x;
}
void build(){
	queue<node*>qu;
	for(iter i=rt->tr.begin();i!=rt->tr.end();++i){
		qu.push(i->second);
		i->second->fa=rt;
	}
	while(!qu.empty()){
		node*u=qu.front();qu.pop();
		for(iter i=u->tr.begin();i!=u->tr.end();++i){
			node*p=u->fa,*v=i->second;int w=i->first;
			while(p!=rt&&!p->tr.count(w))p=p->fa;
			if(p->tr.count(w))v->fa=p->tr[w];
			else v->fa=rt;
			qu.push(v);
		}
	}
}
vector<int>xi[200010][2];
void rrrd(vector<int>&v){
	int t;sf("%d",&t);
	lp(i,1,t){
		int t2;sf("%d",&t2);
		v.pb(t2);
	}
}
int n,m;
int ans[200010];
node*rmm[200010];
int main(){
	sf("%d%d",&n,&m);
	lp(i,1,n){
		rrrd(xi[i][0]);
		rrrd(xi[i][1]);
	}
	lp(i,1,m){
		sf("%d",&len);
		lp(j,1,len)sf("%d",&tmp[j]);
		rmm[i]=insert();
	}
	build();
	lp(i,1,n){
		lp(ppp,0,1){
			vector<int>&a=xi[i][ppp];
			node*u=rt;
			vp(j,a){
				int c=a[j];
				while(u!=rt&&!u->tr.count(c))u=u->fa;
				if(u->tr.count(c))u=u->tr[c];
				node*v=u;
				while(v!=rt&&v->mrk!=i){
					v->mrk=i;
					++v->cnt;
					ans[i]+=v->opt;
					v=v->fa;
				}
			}
		}
	}
	lp(i,1,m)pf("%d\n",rmm[i]->cnt);
	lp(i,1,n)pf("%d%c",ans[i],i==n?'\n':' ');
	return 0;
}
