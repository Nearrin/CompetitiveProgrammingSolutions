#include<stdio.h>
#include<math.h>
#define sf scanf
#define lp(i,a,b) for(int i=a;i<=b;++i)
typedef long long ll;
ll A[100010],S[100010];int N,M,P[100010];
void ad(int i,ll d){for(;i<=N;i+=i&-i)S[i]+=d;}
ll qu(int i){ll r=0;for(;i;i-=i&-i)r+=S[i];return r;}
int fd(int a){return P[a]-a?P[a]=fd(P[a]):a;}
int main(){
    sf("%d",&N);lp(i,1,N)sf("%lld",&A[i]),ad(i,A[i]),P[i]=i;
    P[N+1]=N+1;sf("%d",&M);lp(i,1,M){int l,r,k;sf("%d%d%d",&k,&l,&r);
    if(l>r){int t=l;l=r,r=t;}if(!k){for(int i=fd(l);i<=r;i=fd(i+1)){
    ll t=sqrt(A[i]);ad(i,-A[i]+t),A[i]=t,A[i]-1?0:++P[i];}}
    else printf("%lld\n",qu(r)-qu(l-1));}
    return 0;
}
