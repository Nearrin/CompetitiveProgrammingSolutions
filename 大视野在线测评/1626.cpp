#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
int n,m,p[1010];
int fd(int x){
	return x==p[x]?x:p[x]=fd(p[x]);
}
int lk(int x,int y){
	if(fd(x)!=fd(y))
	p[fd(x)]=y;
}
struct edge{
	edge(){
	}
	edge(double a,int b,int c):
		len(a),x(b),y(c){
		}
	long double len;
	int x,y;
};
bool operator<(edge a,edge b){
	return a.len<b.len;
}
long double px[1010],py[1010];
long double W(int x,int y){
	typedef long double ld;
	ld t1=px[x]-px[y];
	ld t2=py[x]-py[y];
	t1*=t1;
	t2*=t2;
	return sqrt(t1+t2);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
	p[i]=i;
	cin>>px[i]>>py[i];
}
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		lk(u,v);
	}
	static edge es[1000010];
	int el=0;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			es[++el]=edge(W(i,j),i,j);
	sort(es+1,es+el+1);
	long double ans=0;
	for(int i=1;i<=el;++i){
		if(fd(es[i].x)!=fd(es[i].y)){
			ans+=es[i].len;
			lk(es[i].x,es[i].y);
		}
	}
	cout<<fixed<<setprecision(2);
	cout<<ans<<endl;
	//	for(;;);
	return 0;
}
