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
char my[1010],co[1010];int n,w[1010];
int main(){
    tst{
        scf("%d",&n);
        scf("%s%s",my+1,co+1);
        int hehe=0;
        lop(i,0,n)scf("%d",w+i);
        lop(i,1,n)if(my[i]==co[i])++hehe;
        if(hehe==n)cout<<w[n]<<endl;
        else{
        lop(i,1,n)w[i]=max(w[i-1],w[i]);
        cout<<w[hehe]<<endl;
        }
    }
    return 0;
}
