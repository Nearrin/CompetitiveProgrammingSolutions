#include<cstdio>
#include<algorithm>
#include<cstdio>
#include<cmath>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
namespace wtreap{
	struct node{
		node(int v){
			ch[0]=ch[1]=0;
			sz=1;fx=rand();
			vl=v;
		}
		node*ch[2];
		int sz,fx,vl;
		double tl,tr;
	}*rt=0;
	void relabel(node*x){
		if(x->ch[0]){
			x->ch[0]->tl=x->tl;
			x->ch[0]->tr=(x->tl+x->tr)/2;
			relabel(x->ch[0]);
		}
		if(x->ch[1]){
			x->ch[1]->tl=(x->tl+x->tr)/2;
			x->ch[1]->tr=x->tr;
			relabel(x->ch[1]);
		}
	}
	void update(node*x){
		x->sz=1;
		lp(i,0,1)if(x->ch[i])x->sz+=x->ch[i]->sz;
	}
	void rotate(node*&x,int d){
		node*y=x->ch[d];
		x->ch[d]=y->ch[!d];
		y->ch[!d]=x;
		update(x);
		update(y);
		y->tl=x->tl;
		y->tr=x->tr;
		x=y;
		relabel(x);
	}
	void insert(node*&x,node*y,int k,double l,double r){
		if(!x)x=y,x->tl=l,x->tr=r;
		else{
			int t=(x->ch[0]?x->ch[0]->sz:0);
			if(t>=k-1){
				insert(x->ch[0],y,k,x->tl,(x->tl+x->tr)/2);
				update(x);
				if(x->ch[0]->fx>x->fx)rotate(x,0);
			}else{
				insert(x->ch[1],y,k-(t+1),(x->tl+x->tr)/2,x->tr);
				update(x);
				if(x->ch[1]->fx>x->fx)rotate(x,1);
			}
		}
	}
	node*select(node*x,int k){
		int t=(x->ch[0]?x->ch[0]->sz:0);
		if(k<=t)return select(x->ch[0],k);
		else if(t+1==k)return x;
		else return select(x->ch[1],k-(t+1));
	}
}
namespace treap{
	struct node{
		node(wtreap::node*a){
			ch[0]=ch[1]=0;
			sz=1;fx=rand();mp=a;
		}
		node*ch[2];
		int sz,fx;
		wtreap::node*mp;
	};
	void update(node*x){
		x->sz=1;
		lp(i,0,1)if(x->ch[i])x->sz+=x->ch[i]->sz;
	}
	void rotate(node*&x,int d){
		node*y=x->ch[d];
		x->ch[d]=y->ch[!d];
		y->ch[!d]=x;
		update(x);
		update(y);
		x=y;
	}
	void insert(node*&x,node*y){
		if(!x)x=y;
		else{
			if(x->mp->tl+x->mp->tr>y->mp->tl+y->mp->tr){
				insert(x->ch[0],y);
				update(x);
				if(x->ch[0]->fx>x->fx)rotate(x,0);
			}else{
				insert(x->ch[1],y);
				update(x);
				if(x->ch[1]->fx>x->fx)rotate(x,1);
			}
		}
	}
	void remove(node*&x,double y){
		if(fabs(x->mp->tl+x->mp->tr-y)<1e-8){
			if(!x->ch[0]){node*t=x;x=x->ch[1];delete t;}
			else if(!x->ch[1]){node*t=x;x=x->ch[0];delete t;}
			else if(x->ch[0]->fx>x->ch[1]->fx){
				rotate(x,0);
				remove(x->ch[1],y);
				update(x);
			}else{
				rotate(x,1);
				remove(x->ch[0],y);
				update(x);
			}
		}else{
			if(x->mp->tl+x->mp->tr>y)remove(x->ch[0],y);
			else remove(x->ch[1],y);
			update(x);
		}
	}
	int less(node*x,double y){
		if(!x)return 0;
		else{
			if(x->mp->tl+x->mp->tr-y<-1e-8)
				return (x->ch[0]?x->ch[0]->sz:0)+1+less(x->ch[1],y);
			else
				return less(x->ch[0],y);
		}
	}
	int lesseq(node*x,double y){
		if(!x)return 0;
		else{
			if(x->mp->tl+x->mp->tr-y<1e-8)
				return (x->ch[0]?x->ch[0]->sz:0)+1+lesseq(x->ch[1],y);
			else
				return lesseq(x->ch[0],y);
		}
	}
}
namespace seg{
	struct node{
		node(int a,int b){
			ch[0]=ch[1]=0;
			l=a;r=b;tp=0;
		}
		node*ch[2];
		int l,r;
		treap::node*tp;
	}*rt;
	node*build(int l,int r){
		node*x=new node(l,r);
		if(l!=r){
			int m=(l+r)/2;
			x->ch[0]=build(l,m);
			x->ch[1]=build(m+1,r);
		}
		return x;
	}
	int ask(node*x,double l,double r,int k){
		if(x->l==x->r)return x->l;
		else{
			int t=treap::lesseq(x->ch[0]->tp,r)-treap::less(x->ch[0]->tp,l);
			if(t<=k-1)return ask(x->ch[1],l,r,k-t);
			else return ask(x->ch[0],l,r,k);
		}
	}
	void insert(node*x,int w,wtreap::node*y){
		treap::insert(x->tp,new treap::node(y));
		if(x->l!=x->r){
			int m=(x->l+x->r)/2;
			if(w<=m)insert(x->ch[0],w,y);
			else insert(x->ch[1],w,y);
		}
	}
	void remove(node*x,int w,double y){
		treap::remove(x->tp,y);
		if(x->l!=x->r){
			int m=(x->l+x->r)/2;
			if(w<=m)remove(x->ch[0],w,y);
			else remove(x->ch[1],w,y);
		}
	}
}
char getchr(){
	char c;while(c=getchar(),c=='\n'||c==' ');
	return c;
}
int getint(){
   int r=getchr()-'0';char c;
   while(c=getchar(),'0'<=c&&c<='9')r=r*10+c-'0';
   return r;
}
int main(){
	seg::rt=seg::build(0,70000);
	int n=getint();
	lp(i,1,n){
		int t=getint();
		wtreap::node*x=new wtreap::node(t);
		wtreap::insert(wtreap::rt,x,i+1,0,n);
		seg::insert(seg::rt,t,x);
	}
	int la=0,q=getint();
	lp(i,1,q){
		char op=getchr();
		if(op=='M'){
			int p=getint(),v=getint();
			p^=la;v^=la;
			wtreap::node*x=wtreap::select(wtreap::rt,p);
			seg::remove(seg::rt,x->vl,x->tl+x->tr);x->vl=v;
			seg::insert(seg::rt,x->vl,x);
		}else if(op=='I'){
			int p=getint(),v=getint();
			p^=la;v^=la;
			wtreap::node*x=new wtreap::node(v);
			wtreap::insert(wtreap::rt,x,p,0,n);
			seg::insert(seg::rt,v,x);
		}else{
			int pl=getint(),pr=getint(),k=getint();
			pl^=la;pr^=la;k^=la;
			wtreap::node*x=wtreap::select(wtreap::rt,pl);
			wtreap::node*y=wtreap::select(wtreap::rt,pr);
			la=seg::ask(seg::rt,x->tl+x->tr,y->tl+y->tr,k);
			pf("%d\n",la);
		}
	}
	return 0;
}
