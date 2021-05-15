#include<bits/stdc++.h>
#define lop(i,a,b) for(auto i=a;i<=b;++i)
#define rlp(i,a,b) for(auto i=a;i>=b;--i)
#define vlp(i,a) for(int i=0;i<a.size();++i)
#define all(a) a.begin(),a.end()
#define sqr(a) ((a)*(a))
#define pub push_back
#define pob pop_back
#define mkp make_pair
#define scf scanf
#define ptf printf
#define inf (~0u>>1)
namespace CTL{}
using namespace CTL;
using namespace std;
typedef long long lli;
typedef unsigned long long ull;
typedef string str;
typedef vector<int> vei;
typedef vector<string> ves;
typedef map<int,int> mii;
typedef map<str,int> msi;
typedef set<int> sti;
typedef set<str> sts;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#define tst int T;scf("%d",&T);while(T--)
int hehe[5*1000010];
int main(){
    for(int i=1;i*i<=5*1000000;++i)
        for(int j=1;i*i+j*j<=5*1000000;++j){
            if(i<=j)continue;
           // if(i*i-j*j==2*i*j)
             //   continue;
            
            hehe[i*i+j*j]=1;
        }
    for(int i=1;i<=5*1000000;++i)
        if(hehe[i])
            for(int j=i+i;j<=5*1000000;j+=i)
                hehe[j]=1;
    tst{
        int n;scf("%d",&n);
        if(hehe[n])ptf("YES\n");
        else ptf("NO\n");
    }
    return 0;
}
