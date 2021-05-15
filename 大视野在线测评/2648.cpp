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
struct point{
	int x,y;
};
bool cmpx(point a,point b){
	return a.x<b.x;
}
bool cmpy(point a,point b){
	return a.y<b.y;
}
struct node{
	node(point _p){
		ch[0]=ch[1]=0;
		p=_p;
		xmi=xmx=p.x;
		ymi=ymx=p.y;
	}
	node*ch[2];
	point p;
	int xmi,xmx,ymi,ymx;
};
void update(node*x){
	lp(i,0,1)if(x->ch[i]){
		x->xmi=min(x->xmi,x->ch[i]->xmi);
		x->xmx=max(x->xmx,x->ch[i]->xmx);
		x->ymi=min(x->ymi,x->ch[i]->ymi);
		x->ymx=max(x->ymx,x->ch[i]->ymx);
	}
}
node*build(vector<point>&a,int l,int r,int d){
	if(d==0)sort(a.begin()+l,a.begin()+r+1,cmpx);
	else sort(a.begin()+l,a.begin()+r+1,cmpy);
	int m=(l+r)/2;
	node*ret=new node(a[m]);
	if(l!=m)ret->ch[0]=build(a,l,m-1,d^1);
	if(m!=r)ret->ch[1]=build(a,m+1,r,d^1);
	update(ret);
	return ret;
}
void insert(node*&x,point p,int d){
	if(!x)x=new node(p);
	else{
		int t=(d==0&&p.x>x->p.x)||(d==1&&p.y>x->p.y);
		insert(x->ch[t],p,d^1);
		update(x);
	}
}
int guess(node*x,point p){
	int r=0;
	if(p.x<x->xmi)r+=x->xmi-p.x;
	if(p.x>x->xmx)r+=p.x-x->xmx;
	if(p.y<x->ymi)r+=x->ymi-p.y;
	if(p.y>x->ymx)r+=p.y-x->ymx;
	return r;
	
}
int myabs(int x){
	return x>0?x:-x;
}
int dist(point a,point b){
	return myabs(a.x-b.x)+myabs(a.y-b.y);
}
void query(node*x,int&ans,point p){
	ans=min(ans,dist(p,x->p));
	int t1=x->ch[0]?guess(x->ch[0],p):~0u>>1;
	int t2=x->ch[1]?guess(x->ch[1],p):~0u>>1;
	if(t1<t2){
		if(t1<ans)query(x->ch[0],ans,p);
		if(t2<ans)query(x->ch[1],ans,p);
	}else{
		if(t2<ans)query(x->ch[1],ans,p);
		if(t1<ans)query(x->ch[0],ans,p);
	}
}
int main(){
	int n,m;vector<point>pts;
	sf("%d%d",&n,&m);
	lp(i,1,n){
		point t;sf("%d%d",&t.x,&t.y);
		pts.pb(t);
	}
	node*rt=build(pts,0,int(pts.size()-1),0);
	lp(i,1,m){
		int op;point t;sf("%d%d%d",&op,&t.x,&t.y);
		if(op==1)insert(rt,t,0);
		else{
			int ans=~0u>>1;
			query(rt,ans,t);
			pf("%d\n",ans);
		}
	}
	return 0;
}
