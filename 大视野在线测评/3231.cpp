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
ll N,M,P,K;
struct mat{
    mat(int _n){
        n=_n;
        lp(i,1,n)lp(j,1,n)m[i][j]=0;
    }
    ll n,m[107][107];
};
mat mul(const mat&a,const mat&b){
    mat c(a.n);
    lp(i,1,a.n)lp(j,1,a.n)lp(k,1,a.n)c.m[i][j]=(c.m[i][j]+ll(a.m[i][k])*b.m[k][j])%P;
    return c;
}
mat mypow(mat a,ll b){
    mat r(a.n);lp(i,1,a.n)lp(j,1,a.n)r.m[i][j]=(i==j);
    while(b){
        if(b&1)r=mul(r,a);
        a=mul(a,a);
        b>>=1;
    }
    return r;
}
ll B[21],C[21];
ll calc(ll n){
	mat tmp1(K+1);
	lp(j,1,K-1)tmp1.m[j+1][j]=1;
	lp(i,1,K)tmp1.m[i][K]=C[K-i+1]%P;
	tmp1.m[K+1][K+1]=1;
	if(K!=1)tmp1.m[2][K+1]=1;
	else tmp1.m[1][K+1]=C[1];
	tmp1=mypow(tmp1,n-1);
	mat tmp2(K+1);
	lp(j,1,K)tmp2.m[1][j]=B[j]%P;
	tmp2.m[1][K+1]=B[1]%P;
	tmp2=mul(tmp2,tmp1);
	return tmp2.m[1][K+1];
}
int main(){
	sf("%lld",&K);
	lp(i,1,K)sf("%lld",&B[i]);
	lp(i,1,K)sf("%lld",&C[i]);
	sf("%lld%lld%lld",&M,&N,&P);
	if(P*P<0)ps;
	pf("%lld\n",(calc(N)-(M!=1?calc(M-1):0)+P)%P);
	return 0;
}
/*
15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
1 10000000 1000000007
*/
