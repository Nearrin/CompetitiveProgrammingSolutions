#include<cstdio>
#include<algorithm>
#include<iostream>
#include<iomanip>
#define sf scanf
#define pf printf
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define ps for(;;)
using namespace std;
int N,L,K,A[201];
double P[201],F[201][201][402];
int main(){
  cin>>N>>L>>K;
  lp(i,1,N)cin>>P[i],P[i]/=100;
  lp(i,1,N)cin>>A[i];
  F[0][0][min(K,N)+201]=1;
  lp(i,0,N-1)
    lp(j,0,i)
      lp(k,-N,N)
        F[i+1][j][k+201]+=F[i][j][k+201]*(1-P[i+1]),
        F[i+1][j+1][min(k+A[i+1],N)+201]+=F[i][j][k+201]*P[i+1];
  double ans=0;
  lp(j,L,N)
    lp(k,0,N)
      ans+=F[N][j][k+201];
  cout<<setprecision(6)<<setiosflags(ios::fixed)<<ans<<endl;
  return 0;
}
