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
#include<deque>
int n;ll T[1000010],C[1000010],S[1000010],D[1000010];
ll X[1000010],Y[1000010],F[1000010];
double slope(int u,int v){
	if(X[u]==X[v])return Y[u]>Y[v]?-1e100:1e100;
	return double(Y[u]-Y[v])/(X[u]-X[v]);
}
int main(){
	sf("%d",&n);
	lp(i,1,n)sf("%lld%lld%lld",&D[i],&S[i],&C[i]);
	rp(i,n,2)D[i]-=D[i-1];
	lp(i,1,n)D[i]=D[i+1];
	rp(i,n-1,0){
		D[i]+=D[i+1];
		T[i]=T[i+1]+S[i]*D[i];
		S[i]+=S[i+1];
	}
	deque<int>qu;qu.push_back(n);F[n]=Y[n]=C[n];
	rp(i,n-1,0){
		while(qu.size()>1){
			int u=qu[0],v=qu[1];
			if(slope(u,v)<S[i+1]+1e-8)qu.pop_front();
			else break;
		}
		F[i]=F[qu[0]]+T[i+1]-T[qu[0]]-(S[i+1]-S[qu[0]])*D[qu[0]]+C[i];
		X[i]=D[i];Y[i]=F[i]-T[i]+D[i]*S[i];
		while(qu.size()>1){
			int u=qu[qu.size()-2],v=qu[qu.size()-1];
			if(slope(u,v)>slope(v,i)-1e-8)qu.pop_back();
			else break;
		}
		qu.push_back(i);
	}
	pf("%lld\n",F[0]);
	return 0;
}
