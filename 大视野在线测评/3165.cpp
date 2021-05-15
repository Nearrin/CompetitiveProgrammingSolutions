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
struct data{
	double y1,y2;int id;
}seg[40010*4];
double calcu(int x1,double y1,int x2,double y2,int x){
	double k=(y2-y1)/(x2-x1),b=y1-k*x1;
	return k*x+b;
}
void update(int x,int l,int r,double y1,double y2,int id){
	if(y1>seg[x].y1-1e-8&&y2>seg[x].y2-1e-8){
		swap(y1,seg[x].y1);
		swap(y2,seg[x].y2);
		swap(id,seg[x].id);
	}else if(y1<seg[x].y1&&y2<seg[x].y2){
		return;
	}else{
		if(y1>seg[x].y1){
			swap(y1,seg[x].y1);
			swap(y2,seg[x].y2);
			swap(id,seg[x].id);
		}
		int m=(l+r)/2;
		if(calcu(l,y1,r,y2,m)<calcu(l,seg[x].y1,r,seg[x].y2,m)){
			update(x*2+1,m+1,r,calcu(l,y1,r,y2,m+1),y2,id);
		}else{
			swap(y1,seg[x].y1);
			swap(y2,seg[x].y2);
			swap(id,seg[x].id);
			update(x*2,l,m,y1,calcu(l,y1,r,y2,m),id);
		}
	}
}
void insert(int x,int l,int r,int x1,double y1,int x2,double y2,int id){
	if(x1==l&&x2==r)update(x,l,r,y1,y2,id);
	else{
		int m=(l+r)/2;
		if(x2<=m)insert(x*2,l,m,x1,y1,x2,y2,id);
		else if(x1>m)insert(x*2+1,m+1,r,x1,y1,x2,y2,id);
		else{
			insert(x*2,l,m,x1,y1,m,calcu(x1,y1,x2,y2,m),id);
			insert(x*2+1,m+1,r,m+1,calcu(x1,y1,x2,y2,m+1),x2,y2,id);
		}
	}
}
pair<int,double>query(int x,int l,int r,int t){
	if(l==r)return mp(seg[x].id,seg[x].y1);
	else{
		pair<int,double>ret(seg[x].id,calcu(l,seg[x].y1,r,seg[x].y2,t)),ret2;
		int m=(l+r)/2;
		if(t<=m)ret2=query(x*2,l,m,t);
		else ret2=query(x*2+1,m+1,r,t);
		if(ret.second>ret2.second+1e-8)return ret;
		else if(ret2.second>ret.second+1e-8)return ret2;
		else if(ret.first<ret2.first)return ret;
		else return ret2;
	}
}
int main(){
	int n,lst=0,nw=0;sf("%d",&n);
	lp(i,1,n){
		int t;sf("%d",&t);
		if(t==0){
			int x;sf("%d",&x);
			x=(x+lst-1)%39989+1;
			pf("%d\n",lst=query(1,1,40000,x).first);
		}else{
			int x1,y1,x2,y2;
			sf("%d%d%d%d",&x1,&y1,&x2,&y2);
			x1=(x1+lst-1)%39989+1;
			y1=(y1+lst-1)%1000000000+1;
			x2=(x2+lst-1)%39989+1;
			y2=(y2+lst-1)%1000000000+1;
			if(x1>x2)swap(x1,x2),swap(y1,y2);
			if(x1==x2)y1=y2=max(y1,y2);
			insert(1,1,40000,x1,y1,x2,y2,++nw);
		}
	}
	//ps;
	return 0;
}
