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

template<class VAL>inline VAL GreatestCommonDivisor(VAL a,VAL b){
    if(a<VAL(0))
        a=-a;
    if(b<VAL(0))
        b=-b;
    if(b==VAL(0))
        return a;
    return GreatestCommonDivisor(b,a%b);
}

bool check(ll a,ll b){
    if(GreatestCommonDivisor(a,b)==1)
        return b==1;
    return check(GreatestCommonDivisor(a,b),b/GreatestCommonDivisor(a,b));
}

int main(){
    int T;si(T);
    lp(i,1,T){
        ll A,B;
        sf("%lld%lld",&A,&B);
        if(!check(A,B))pf("No\n");
        else pf("Yes\n");
    }

    return 0;
}
