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

int hehe[110];

int main(){
    hehe['A']=1;
    hehe['B']=2;
    hehe['D']=1;
    hehe['O']=1;
            hehe['P']=1;
               hehe['Q']=1;
                  hehe['R']=1;

   mc{
     string s;cin>>s;
     int a=0;
     vp(i,s)
             a+=hehe[s[i]];
     cout<<a<<endl;
   }
    return 0;
}
