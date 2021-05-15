#include<algorithm>
#include<cctype>
#include<climits>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>
#define sf scanf
#define si(a)scanf("%d",&a)
#define pf printf
#define pi(a)printf("%d",a)
#define fr freopen
#define ps for(;;)
#define pb push_back
#define mp make_pair
#define lp(i,a,b)for(int i=a;i<=int(b);++i)
#define rp(i,a,b)for(int i=int(a);i>=b;--i)
#define vp(i,a)for(int i=0;i<int(a.size());++i)
#define wp(i,a)for(int i=int(a.size())-1;i>=0;--i)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
ll C[4010][4010];
ll f[2010][2010];
ll fs[2010][2010];
int main(){
    C[0][0]=1;
    lp(i,1,4005)
            lp(j,0,i){
        if(j==0||j==i)
            C[i][j]=1;
        else
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%ll(1e9);
    }
    int T;si(T);
    lp(I,1,T){
        int n,m;si(n),si(m);
        lp(i,1,n){
              lp(j,0,m){
                    if(i==1){
                        f[i][j]=C[j+m-1][m-1];
                    }else{
                        f[i][j]=fs[i-1][j]*C[j+m-1][m-1]%ll(1e9);
                    }
                 }
              fs[i][0]=f[i][0];
              lp(j,1,m){
                  fs[i][j]=(f[i][j]+fs[i][j-1])%ll(1e9);
              }
        }
        pf("%lld\n",fs[n][m]);
    }
    return 0;
}
