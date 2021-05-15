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
#include<list>
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
    int p,a,b,c,d,n;
    while(sf("%d%d%d%d%d%d",&p,&a,&b,&c,&d,&n)!=EOF){
        static double mxx[1000010],mii[1000010];
        lp(k,1,n)
                mxx[k]=mii[k]=p * (sin(a * k + b) + cos(c * k + d) + 2);
        lp(i,2,n)mxx[i]=max(mxx[i],mxx[i-1]);
        rp(i,n-1,1)mii[i]=min(mii[i],mii[i+1]);
        double ans=0;
        lp(i,2,n)ans=max(ans,mxx[i-1]-mii[i]);
        pf("%.6lf\n",ans);
    }
    return 0;
}
