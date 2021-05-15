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
int main(){
    int T;si(T);
    lp(I,1,T){
        static ll M[100010];
        int N;
        si(N);
        lp(i,1,N)sf("%lld",M+i);
        ll cur=0;
        ll ans=0;
        lp(i,1,N){
            if(cur>=M[i]){
                cur=M[i];
            }else{
                ans+=M[i]-cur;
                cur=M[i];
            }
        }
        pf("%lld\n",ans);
    }
    return 0;
}
