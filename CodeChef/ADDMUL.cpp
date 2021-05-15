#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
struct info{
	info(){
		same = -1;
		a = 1;
		b = 0;
	}
	int same;
	int a,b;
	int sum;
	void safecheck(){
		if((same<0&&same!=-1)||a<0||b<0||sum<0){
			cout<<"shit!"<<endl;
		}
	}
}seg[100010*4];
int M= 1e9+7;
void down(int x,int l,int r){
	seg[x].safecheck();
	if(seg[x].same!=-1){
		seg[x].same = (ll(seg[x].same)*seg[x].a+seg[x].b)%M;
		seg[x].a = 1;
		seg[x].b = 0;
		seg[x].sum = ll(r-l+1)*seg[x].same%M;//TAT
		int tmp = seg[x].same;
		seg[x].same = -1;
		seg[x].safecheck();
		if(l!=r){
			seg[x*2].same = tmp;
			seg[x*2].a = 1;
			seg[x*2].b = 0;
			seg[x*2+1].same = tmp;
			seg[x*2+1].a = 1;
			seg[x*2+1].b = 0;
		}
		seg[x].safecheck();
	}
	
	else{
		seg[x].safecheck();
		seg[x].sum= (ll(seg[x].sum)*seg[x].a+seg[x].b* ll(r-l+1))%M;//TAT
		ll ta = seg[x].a;
		ll tb = seg[x].b;
		seg[x].a = 1;
		seg[x].b = 0;
		seg[x].safecheck();
		if(l!=r){
			seg[x*2].a = seg[x*2].a*ta%M;
			seg[x*2].b = (seg[x*2].b*ta+tb)%M;
			seg[x*2+1].a = seg[x*2+1].a*ta%M;
			seg[x*2+1].b = (seg[x*2+1].b*ta+tb)%M;
		}
		seg[x].safecheck();
	}
}
void update(int x,int l,int r){
	seg[x].safecheck();
	int m = (l+r)/2;
	down(x*2,l,m);
	down(x*2+1,m+1,r);
	seg[x].safecheck();
	seg[x].sum = seg[x*2].sum+seg[x*2+1].sum;
	seg[x].sum %= M;
	seg[x].safecheck();
}
void buildseg(int x,int l,int r,int*buff){
	seg[x] = info();
	if(l==r){
		seg[x].sum = buff[l];
	}
	else{
		int m = (l+r)/2;
		buildseg(x*2,l,m,buff);
		buildseg(x*2+1,m+1,r,buff);
		seg[x].sum = seg[x*2].sum+seg[x*2+1].sum;
		seg[x].sum %= M;
	}
}
void queryab(int x,int l,int r,int ql,int qr,int a,int b){
	seg[x].safecheck();
	down(x,l,r);
	seg[x].safecheck();
	if(ql<=l&&qr>=r){
		seg[x].a = a;
		seg[x].b = b;
	}
	else{
		int m = (l+r)/2;
		if(ql<=m)
			queryab(x*2,l,m,ql,qr,a,b);
		if(qr>m)
			queryab(x*2+1,m+1,r,ql,qr,a,b);
		seg[x].safecheck();
		update(x,l,r);
		seg[x].safecheck();
	}
}
void querys(int x,int l,int r,int ql,int qr,int s){
	seg[x].safecheck();
	down(x,l,r);seg[x].safecheck();
	if(ql<=l&&qr>=r){
		seg[x].same = s;
	}
	else{
		int m = (l+r)/2;seg[x].safecheck();
		if(ql<=m)
			querys(x*2,l,m,ql,qr,s);
		if(qr>m)
			querys(x*2+1,m+1,r,ql,qr,s);seg[x].safecheck();
		update(x,l,r);seg[x].safecheck();
	}
}
ll queryss(int x,int l,int r,int ql,int qr){
	down(x,l,r);seg[x].safecheck();
	if(ql<=l&&qr>=r){
		return seg[x].sum;
	}
	else{
		int m = (l+r)/2;
		ll ans = 0;
		if(ql<=m)
			ans+=queryss(x*2,l,m,ql,qr);seg[x].safecheck();
		if(qr>m)
			ans+=queryss(x*2+1,m+1,r,ql,qr);seg[x].safecheck();
		ans %= M;
		return ans;
	}
}
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	static int buff[100010];
	for(int i = 1;i<=n;++i)
		scanf("%d",buff+i);
	buildseg(1,1,n,buff);
	for(int i = 1;i<=q;++i){
		int t;
		scanf("%d",&t);
		if(t==1){
			int x,y,v;
			scanf("%d%d%d",&x,&y,&v);
			queryab(1,1,n,x,y,1,v);
		}
		else if(t==2){
			int x,y,v;
			scanf("%d%d%d",&x,&y,&v);
			queryab(1,1,n,x,y,v,0);
		}
		else if(t==3){
			int x,y,v;
			scanf("%d%d%d",&x,&y,&v);
			querys(1,1,n,x,y,v);
		}
		else{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%d\n",int(queryss(1,1,n,x,y)));
		}
	}
	return 0;
}
