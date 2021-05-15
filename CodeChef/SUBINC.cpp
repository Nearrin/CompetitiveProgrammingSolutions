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
int a[100010],b[100010];int n;
int main(){
    tst{
        scf("%d",&n);
        lop(i,1,n){
            scf("%d",a+i);
            if(a[i]>=a[i-1])
                b[i]=1;
            else
                b[i]=0;
            b[i]+=b[i-1];
        }
        lop(i,1,n)b[i]-=i;
        map<int,int>mp;lli ans=0;
        lop(i,1,n){
            ++mp[b[i]];
            ans+=mp[b[i]];
        }
        cout<<ans<<endl;
    }
    return 0;
}
