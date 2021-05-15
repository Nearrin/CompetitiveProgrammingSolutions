#include<cstdio>
#include<algorithm>
#include<vector>
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
#define wp(i,v) for(int i=int(v.size())-1;i>=0;--i)
typedef long long ll;
using namespace std;
struct lct{
	struct node{
		node*ch[2],*pr;
		int rev;
	}ns[10010];
	inline void down(node*x){
		if(x->rev){
			lp(i,0,1)if(x->ch[i])x->ch[i]->rev^=1;
			swap(x->ch[0],x->ch[1]);
			x->rev=0;
		}
	}
	inline int direct(node*x){
		if(!x->pr)return 2;
		else if(x==x->pr->ch[0])return 0;
		else if(x==x->pr->ch[1])return 1;
		else return 2;
	}
	inline void setchd(node*x,node*y,int d){
		x->ch[d]=y;
		if(y)y->pr=x;
	}
	inline void rotate(node*x){
		node*y=x->pr,*z=y->pr;
		int d1=direct(x),d2=direct(y);
		setchd(y,x->ch[!d1],d1);
		setchd(x,y,!d1);
		if(d2<2)setchd(z,x,d2);else x->pr=z;
	}
	inline void release(node*x){
		if(direct(x)<2)release(x->pr);
		down(x);
	}
	inline void splay(node*x){
		release(x);
		while(direct(x)<2){
			node*y=x->pr;
			if(direct(y)>1)rotate(x);
			else if(direct(x)==direct(y))rotate(y),rotate(x);
			else rotate(x),rotate(x);
		}
	}
	inline node*access(node*x){
		node*y=0;
		while(x){
			splay(x);
			setchd(x,y,1);
			y=x;x=x->pr;
		}
		return y;
	}
	inline void evert(node*x){
		access(x);
		splay(x);
		x->rev=1;
	}
	inline bool query(node*x,node*y){
		access(x);node*z=access(y);
		return z==access(x);
	}
	inline void link(node*x,node*y){
		evert(y);
		y->pr=x;
	}
	inline void cut(node*x,node*y){
		evert(x);
		access(y);
		splay(y);
		y->ch[0]=0;
		x->pr=0;
	}
}tree;
int main(){
	int n,m;sf("%d%d",&n,&m);
	lp(i,1,m){
		static char op[11];int u,v;
		sf("%s%d%d",op,&u,&v);
		if(op[0]=='Q')pf("%s\n",tree.query(tree.ns+u,tree.ns+v)?"Yes":"No");
		else if(op[0]=='C')tree.link(tree.ns+u,tree.ns+v);
		else tree.cut(tree.ns+u,tree.ns+v);
	}
	return 0;
}
