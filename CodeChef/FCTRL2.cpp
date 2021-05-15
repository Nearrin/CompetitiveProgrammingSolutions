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
#include<fstream>
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
#define mc int T;scanf("%d",&T);for(int I=1;I<=T;++I)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int>vi;
typedef pair<int,int>pii;

int main(){
   mc{
        static int a[1000];
        lp(i,1,500)a[i]=0;
        a[1]=1;
        int n;cin>>n;
        lp(i,1,n){
            lp(j,1,500)
                    a[j]*=i;
            lp(j,1,500)
                    a[j+1]+=a[j]/10,a[j]%=10;
        }
        int u=500;
        while(a[u]==0)--u;
        rp(i,u,1)cout<<a[i];
        cout<<endl;
   }
    return 0;
}
