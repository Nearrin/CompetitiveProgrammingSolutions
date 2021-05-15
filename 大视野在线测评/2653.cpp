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
namespace input{
	int n,q,a[20010],t[25010][4];
	void run(){
		sf("%d",&n);
		lp(i,1,n)sf("%d",&a[i]);
		sf("%d",&q);
		lp(i,1,q)lp(j,0,3)sf("%d",&t[i][j]);
	}
}
namespace lisa{
	vector<int>data;
	void run(){
		lp(i,1,input::n)data.pb(input::a[i]);
		sort(data.begin(),data.end());
		data.erase(unique(data.begin(),data.end()),data.end());
	}
	int ask(int x){
		return lower_bound(data.begin(),data.end(),x)-data.begin()+1;
	}
}
namespace segment{
	struct node{
		node(node*a,node*b,int c,int d,int e,int f,int g){
			ch[0]=a;ch[1]=b;l=c;r=d;lmx=e;rmx=f;sum=g;
		}
		node*ch[2];int l,r,lmx,rmx,sum;
	}*rts[20010];
	node*build(int l,int r){
		node*t=new node(0,0,l,r,r-l+1,r-l+1,r-l+1);
		if(l!=r){
			int m=(l+r)/2;
			t->ch[0]=build(l,m);
			t->ch[1]=build(m+1,r);
		}
		return t;
	}
	void update(node*x){
		x->sum=x->ch[0]->sum+x->ch[1]->sum;
		x->lmx=max(x->ch[0]->lmx,x->ch[0]->sum+x->ch[1]->lmx);
		x->rmx=max(x->ch[1]->rmx,x->ch[1]->sum+x->ch[0]->rmx);
	}
	node*edit(node*x,int p,int v){
		if(x->l==x->r)return new node(0,0,x->l,x->r,v,v,v);
		else{
			node*ret=new node(x->ch[0],x->ch[1],x->l,x->r,0,0,0);
			int m=(x->l+x->r)/2;
			if(p<=m)ret->ch[0]=edit(x->ch[0],p,v);
			else ret->ch[1]=edit(x->ch[1],p,v);
			update(ret);
			return ret;
		}
	}
	node ask(node*x,int l,int r){
		if(x->l==l&&x->r==r)return*x;
		else{
			int m=(x->l+x->r)/2;
			if(r<=m)return ask(x->ch[0],l,r);
			else if(l>m)return ask(x->ch[1],l,r);
			else{
				node ret(0,0,l,r,0,0,0);
				node t1=ask(x->ch[0],l,m);
				node t2=ask(x->ch[1],m+1,r);
				ret.ch[0]=&t1;
				ret.ch[1]=&t2;
				update(&ret);
				return ret;
			}
		}
	}
	int query(int a,int b,int c,int d,int v){
		if(b+1==c){
			node t1=ask(rts[v],a,b);
			node t2=ask(rts[v],c,d);
			return t1.rmx+t2.lmx;
		}else{
			node t1=ask(rts[v],a,b);
			node t2=ask(rts[v],c,d);
			node t3=ask(rts[v],b+1,c-1);
			return t1.rmx+t2.lmx+t3.sum;
		}
	}
	void run(){
		rts[0]=build(1,input::n);
		static vector<int>pos[20010];
		lp(i,1,input::n)pos[lisa::ask(input::a[i])].pb(i);
		lp(i,1,lisa::data.size()){
			rts[i]=rts[i-1];
			vp(j,pos[i-1])rts[i]=edit(rts[i],pos[i-1][j],-1);
		}
		ll lstans=0;
		lp(i,1,input::q){
			lp(j,0,3)input::t[i][j]=(input::t[i][j]+lstans)%input::n+1;
			sort(input::t[i],input::t[i]+4);
			int l=1,r=lisa::data.size()+1;
			while(l+1<r){
				int m=(l+r)/2;
				if(query(input::t[i][0],input::t[i][1],input::t[i][2],input::t[i][3],m)>=0)l=m;
				else r=m;
			}
			pf("%d\n",int(lstans=lisa::data[l-1]));
		}
	}
}
int main(){
	input::run();
	lisa::run();
	segment::run();
	return 0;
}
