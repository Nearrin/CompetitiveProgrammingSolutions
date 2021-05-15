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
/*
f(x)=min{f(x-x mod y)+1},y属于M
g(x)=min{t|t是x的最优决策}
f(x)非严格单调，考虑f(x)<f(x-1)，除非x%pi{M}=0，否则x-1可以选和x一样的决策，但是x%pi{M}=0时f(x)=+inf
g(x)非严格单调，由f(x)的非严格单调性可得
f(x=x'*k)<=2*x'，k属于M，数学归纳法
g(x)<x -> g(g(x))<=g(x-1) -> g(g(x))<=(x-1)-(x-1)%k=(x-1)-(k-1)=x-k
f(x)=f(g(g(x)))+2<=f(x-k)+2=f((x'-1)*k)+2<=2x'
f(n)<=ceil(2n/max{M})=O(2n/|M|lg|M|）
对于f(x)相同的一段，我们只计算最后一个位置
枚举f(x)，从先前计算的点后面开始二分查找需要O(lgn|M|)
*/
int m,q,prim[100010],query[100010],frev[10000010],frevup;
bool calc(int x){
	lp(i,1,m)
		if(x-x%prim[i]<=frev[frevup])
			return true;
	return false;
}
bool chec(int x){
	lp(i,1,m)
		if(x%prim[i]!=0)
			return false;
	return true;
}
int main(){
	sf("%d%d",&m,&q);
	lp(i,1,m)sf("%d",&prim[i]);
	lp(i,1,q)sf("%d",&query[i]);
	int maxn=*max_element(query+1,query+q+1);
	int maxp=*max_element(prim+1,prim+m+1);
	while(frev[frevup]!=maxn){
		int l=frev[frevup]+1,r=min(maxn,frev[frevup]+maxp);
		if(chec(l))break;
		if(calc(r))frev[++frevup]=r;
		else{
			while(l+1<r){
				int m=(l+r)/2;
				if(calc(m))l=m;
				else r=m;
			}
			frev[++frevup]=l;
		}
	}
	lp(i,1,q){
		if(query[i]>frev[frevup])pf("oo\n");
		else{
			int l=0,r=frevup;
			while(l+1<r){
				int m=(l+r)/2;
				if(frev[m]>=query[i])r=m;
				else l=m;
			}
			pf("%d\n",r);
		}
	}
	return 0;
}
