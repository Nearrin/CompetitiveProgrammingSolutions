#include<cstdio>
#include<algorithm>
#include<vector>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
namespace gauss{
    const int nmx=100;
    int a[nmx+10],n;
    void solve(){
        int k=0;
        rp(i,31,0){
            int j=k+1;
            while(j<=n&&!((a[j]>>i)&1))++j;
            if(j<=n){
                swap(a[++k],a[j]);
                for(j=1;j<=n;++j)
                    if(j!=k&&((a[j]>>i)&1))
                        a[j]^=a[k];
            }
        }
    }
}
bool check(vector<int>a){
    gauss::n=a.size();
    lp(i,0,int(a.size()-1))gauss::a[i+1]=a[i];
    gauss::solve();
    return gauss::a[gauss::n]!=0;
}
int main(){
    int n;sf("%d",&n);
    vector<int>tmp,a;long long sum=0;
    lp(i,1,n){
        int t;sf("%d",&t);
        tmp.push_back(t);
        sum+=t;
    }
    sort(tmp.begin(),tmp.end());
    rp(i,int(tmp.size()-1),0){
        a.push_back(tmp[i]);
        if(!check(a))a.pop_back();
        else sum-=tmp[i];
    }
    pf("%lld\n",sum);
    //ps;
    return 0;
}
