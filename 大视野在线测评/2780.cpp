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
	node*fa;int mrk,cnt;
}nds[460010];int nw=1;
typedef map<int,node*>::iterator iter;
node*rt=nds;
char tmp[460010];
node*insert(){
	node*x=rt;
	for(int i=0;tmp[i];++i){
		if(!x->tr.count(tmp[i]))
			x->tr[tmp[i]]=&nds[nw++];
		x=x->tr[tmp[i]];
	}
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
vector<int>pos;
string inp[100010];
char tmp2[1000010];
node*ans[600010];
int main(){
	int n,q;sf("%d%d",&n,&q);
	lp(i,1,n){
		sf("%s",tmp2);
		for(int j=0;tmp2[j];++j)inp[i].pb(tmp2[j]);
	}
	lp(i,1,q){
		sf("%s",tmp);
		ans[i]=insert();
	}
	build();
	lp(i,1,n){
		node*u=rt;
		vp(j,inp[i]){
			int w=inp[i][j];
			while(u!=rt&&!u->tr.count(w))u=u->fa;
			if(u->tr.count(w))u=u->tr[w];
			node*v=u;
			while(v!=rt&&v->mrk!=i){
				v->mrk=i;
				++v->cnt;
				v=v->fa;
			}
		}
	}
	lp(i,1,q)pf("%d\n",ans[i]->cnt);
	return 0;
}
