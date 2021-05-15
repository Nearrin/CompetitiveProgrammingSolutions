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
using namespace std;
typedef long long ll;
namespace tree{
	struct node{
		node(char c){ch[0]=ch[1]=pr=0;val=c;siz=1;}
		node*ch[2],*pr;char val;int siz;
	}*rt;int cur;
	int tp(node*x){return x==x->pr->ch[1];}
	inline void upda(node*x){
		x->siz=1;
		lp(i,0,1)if(x->ch[i])x->siz+=x->ch[i]->siz;
	}
	inline node*st(node*x,node*y,int d){x->ch[d]=y;if(y)y->pr=x;upda(x);}
	inline void rot(node*x){
		node*y=x->pr,*z=y->pr;int d1=tp(x),d2;if(z)d2=tp(y);
		st(y,x->ch[!d1],d1);
		st(x,y,!d1);
		if(z)st(z,x,d2);else{x->pr=0;rt=x;}
	}
	inline void spl(node*x,node*y){
		while(x->pr!=y){
			if(x->pr->pr==y)rot(x);
			else if(tp(x)==tp(x->pr))rot(x->pr),rot(x);
			else rot(x),rot(x);
		}
	}
	inline void sel(node*x,int k,node*y){
		int t=x->ch[0]?x->ch[0]->siz:0;
		if(k<=t)sel(x->ch[0],k,y);
		else if(k==t+1)spl(x,y);
		else sel(x->ch[1],k-(t+1),y);
	}
	inline node*bud(char*str,int l,int r){
		int m=(l+r)/2;
		node*ret=new node(str[m]);
		if(l!=m)st(ret,bud(str,l,m-1),0);
		if(r!=m)st(ret,bud(str,m+1,r),1);
		return ret;
	}
	inline node*ept(node*&x){
		lp(i,0,1)if(x->ch[i])ept(x->ch[i]);
		delete x;x=0;
	}
	inline void init(){
		rt=new node('$');
		st(rt,new node('$'),1);
	}
	inline void move(){sf("%d",&cur);}
	inline void insert(){
		static char str[3000010];int len=0;
		int tlen;sf("%d",&tlen);
		lp(i,1,tlen){
			char c=getchar();
			while(c=='\n')c=getchar();
			str[++len]=c;
		}
		sel(rt,cur+1,0);
		sel(rt,cur+2,rt);
		st(rt->ch[1],bud(str,1,len),0);
		upda(rt);
	}
	inline void remove(){
		int t;sf("%d",&t);
		sel(rt,cur+1,0);
		sel(rt,cur+t+2,rt);
		ept(rt->ch[1]->ch[0]);
		upda(rt->ch[1]);
		upda(rt);
	}
	inline void prt(node*x){
		if(x->ch[0])prt(x->ch[0]);
		pf("%c",x->val);
		if(x->ch[1])prt(x->ch[1]);
	}
	inline void print(){
		int t;sf("%d",&t);
		sel(rt,cur+1,0);
		sel(rt,cur+t+2,rt);
		prt(rt->ch[1]->ch[0]);
		pf("\n");
	}
	inline void prev(){--cur;}
	inline void next(){++cur;}
}
int main(){
	tree::init();
	int n;sf("%d",&n);
	lp(i,1,n){
		static char op[11];sf("%s",op);
		if(op[0]=='I')tree::insert();
		else if(op[0]=='M')tree::move();
		else if(op[0]=='D')tree::remove();
		else if(op[0]=='G')tree::print();
		else if(op[0]=='P')tree::prev();
		else tree::next();
	}
	return 0;
}
