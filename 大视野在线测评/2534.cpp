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
#include<cstring>
char S[100010];int N,L;
int p1=1000000007,p2=1000000009;
int pw1[100010],pw2[100010];
int hs1[100010],hs2[100010];
inline int calc(int i,int j){
	int t1=hs1[j]-ll(hs1[i-1])*pw1[j-i+1]%p1+p1;
	if(t1>=p1)t1-=p1;
	return t1;
}
inline int lcp(int i,int j){
	if(i>N*2||j>N*2)return 0;
	int left=0,right=min(2*N-i,2*N-j);
	if(i<=N&&j<=N)right=min(N-i,N-j);
	if(calc(i,i+right)==calc(j,j+right))return right+1;
	if(calc(i,i+left)!=calc(j,j+left))return 0;
	while(left+1<right){
		int mid=((left+right)>>1);
		if(calc(i,i+mid)==calc(j,j+mid))
			left=mid;
		else
			right=mid;
	}
	return left+1;
}
ll ans=0;
int main(){
	sf("%d",&L);
	sf("%s",S+1);N=strlen(S+1);
	lp(i,1,N)S[N+i]=S[N-i+1];
	pw1[0]=1;
	lp(i,1,N*2)pw1[i]=ll(pw1[i-1])*27%p1;
	lp(i,1,N*2)hs1[i]=(ll(hs1[i-1])*27+S[i]-'a')%p1;
	lp(i,1,N){
		for(int j=1;j<=N&&j+i+L<=N;j+=i){
			int u=j,v=j+i+L;
			int t1=min(lcp(u,v),i);
			int t2=min(lcp(2*N-u+2,2*N-v+2),i-1);
			ans+=max(t1+t2-i+1,0);
		}
	}
	pf("%lld\n",ans);
	return 0;
}
