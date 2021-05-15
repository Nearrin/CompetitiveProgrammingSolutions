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
int n,q;
namespace segment{
	struct node{
		inline node(node*a,node*b,int c,int d,ll e,ll f,ll g){
			ch[0]=a;ch[1]=b;
			l=c;r=d;
			d1=e;d2=f;
			sum=g;
		}
		node*ch[2];int l,r;ll d1,d2,sum;
	};
	inline node*build(int l,int r){
		if(l==r)return new node(0,0,l,r,0,0,0);
		else{
			int m=(l+r)/2;
			return new node(build(l,m),build(m+1,r),l,r,0,0,0);
		}
	}
	inline ll query(node*x,int l,int r){
		//if(x->l==1&&x->r==n)pf("[%d,%d]\n",l,r);
		ll fir=x->d1+(l-x->l)*x->d2;
		ll num=r-l+1;
		ll del=x->d2;
		ll ret=num*fir+num*(num-1)/2*del;
		if(l==x->l&&r==x->r){
			return ret+x->sum;
		}else{
			int m=x->ch[0]->r;
			if(r<=m){
				return ret+query(x->ch[0],l,r);
			}else if(l>m){
				return ret+query(x->ch[1],l,r);
			}else{
				return ret+query(x->ch[0],l,m)+query(x->ch[1],m+1,r);
			}
		}
	}
	inline node*modify(node*x,int l,int r,ll d1,ll d2){
		//if(x->l==1&&x->r==n)pf("{%d,%d,%lld,%lld}\n",l,r,d1,d2);
		if(l==x->l&&r==x->r)return new node(x->ch[0],x->ch[1],x->l,x->r,x->d1+d1,x->d2+d2,x->sum);
		else{
			ll fir=d1;ll num=r-l+1;ll del=d2;
			ll ret=num*fir+num*(num-1)/2*del;
			int m=x->ch[0]->r;
			if(r<=m)return new node(modify(x->ch[0],l,r,d1,d2),x->ch[1],x->l,x->r,x->d1,x->d2,x->sum+ret);
			else if(l>m)return new node(x->ch[0],modify(x->ch[1],l,r,d1,d2),x->l,x->r,x->d1,x->d2,x->sum+ret);
			else{
				ll d3=d1+(m-l+1)*d2;
				return new node(modify(x->ch[0],l,m,d1,d2),modify(x->ch[1],m+1,r,d3,d2),x->l,x->r,x->d1,x->d2,x->sum+ret);
			}
		}
	}
	void print(node*x){
		if(!x)return;
		pf("[%d,%d,%lld,%lld,%lld]\n",x->l,x->r,x->d1,x->d2,x->sum);
		lp(i,0,1)print(x->ch[i]);
	}
}
namespace tree{
	vector<int>to[100010];
	inline void init(){
		lp(i,1,n-1){
			int u,v;sf("%d%d",&u,&v);
			to[u].pb(v);
			to[v].pb(u);
		}
	}
	int siz[100010],dep[100010],chd[100010],prt[100010],pos[100010],top[100010],nw;
	inline void dfs1(int u,int p){
		prt[u]=p;dep[u]=dep[p]+1;siz[u]=1;
		vp(i,to[u]){
			int v=to[u][i];
			if(v!=p){
				dfs1(v,u);
				siz[u]+=siz[v];
				if(siz[v]>siz[chd[u]])chd[u]=v;
			}
		}
	}
	inline void dfs2(int u,int a){
		pos[u]=++nw;top[u]=a;
		if(chd[u])dfs2(chd[u],a);
		vp(i,to[u]){
			int v=to[u][i];
			if(v!=prt[u]&&v!=chd[u]){
				dfs2(v,v);
			}
		}
	}
	vector<segment::node*>save;segment::node*now;
	inline void build(){
		dfs1(1,0);
		dfs2(1,1);
		//lp(i,1,n)pf("[%d,%d,%d,%d,%d,%d]\n",siz[i],dep[i],chd[i],prt[i],pos[i],top[i]);
		save.pb(now=segment::build(1,n));
		//segment::print(now);
	}
	inline void load(int x){
		//pf("(%d)",x);
		now=save[x];
	}
	inline void tmodify(int u,int v,ll d1,ll d2){
		//pf("{%d,%d,%lld,%lld}\n",u,v,d1,d2);
		//segment::print(now);
		//pf("\n");
		while(top[u]!=top[v]){
			now=segment::modify(now,pos[top[u]],pos[u],d1+d2*(pos[u]-pos[top[u]]),-d2);
			d1+=(pos[u]-pos[top[u]]+1)*d2;
			u=prt[top[u]];
		}
		now=segment::modify(now,pos[v],pos[u],d1+d2*(pos[u]-pos[v]),-d2);
		//segment::print(now);
		//pf("---------\n\n");
	}
	inline void modify(int u,int v,ll d1,ll d2){
		int tu=u,tv=v;
		while(top[tu]!=top[tv]){
			if(dep[top[tu]]<dep[top[tv]])swap(tu,tv);
			tu=prt[top[tu]];
		}
		if(dep[tu]>dep[tv])swap(tu,tv);
		int w=tu;
		tmodify(u,w,d1,d2);
		tmodify(v,w,d1+d2*(dep[u]-dep[w]+dep[v]-dep[w]),-d2);
		tmodify(w,w,-d1-d2*(dep[u]-dep[w]),0);
		save.pb(now);
	}
	inline ll query(int u,int v){
		ll ret=0;
		while(top[u]!=top[v]){
			if(dep[top[u]]<dep[top[v]])swap(u,v);
			ret+=segment::query(now,pos[top[u]],pos[u]);
			u=prt[top[u]];
		}
		if(dep[u]<dep[v])swap(u,v);
		return ret+segment::query(now,pos[v],pos[u]);
	}
}
int main(){
	sf("%d%d",&n,&q);
	tree::init();
	tree::build();
	ll lastans=0;
	lp(i,1,q){
		static char op[11];
		sf("%s",op);
		if(op[0]=='c'){
			ll x,y,a,b;
			sf("%lld%lld%lld%lld",&x,&y,&a,&b);
			x=(x^lastans);y=(y^lastans);
			tree::modify(x,y,a,b);
		}else if(op[0]=='q'){
			ll x,y;sf("%lld%lld",&x,&y);
			x=(x^lastans);y=(y^lastans);
			pf("%lld\n",lastans=tree::query(x,y));
		}else{
			ll x;sf("%lld",&x);
			x=(x^lastans);
			tree::load(x);
		}
	}
	return 0;
}
/*
5 7
1 2
2 3
3 4
4 5
c 1 4 2 3
c 2 3 5 10
q 1 3
l 1
q 1 3
*/
