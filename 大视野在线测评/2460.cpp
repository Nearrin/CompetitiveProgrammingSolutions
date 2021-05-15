#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility> 
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
namespace gauss{
    const int nmx=1000;
    long long a[nmx+10];int n;
    void solve(){
        int k=0;
        rp(i,63,0){
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
bool check(vector<long long>a){
    gauss::n=a.size();
    lp(i,0,int(a.size()-1))gauss::a[i+1]=a[i];
    gauss::solve();
    return gauss::a[gauss::n]!=0;
}
int main(){
    int n;sf("%d",&n);int ans=0;
    vector<pair<int,long long> >tmp;
    lp(i,1,n){
        int v;long long u;sf("%lld%d",&u,&v);
        tmp.push_back(make_pair(v,u));
    }
    sort(tmp.begin(),tmp.end());
    vector<long long>a;
    rp(i,int(tmp.size()-1),0){
        a.push_back(tmp[i].second);
        if(check(a)){
            ans+=tmp[i].first;
        }else a.pop_back();
    }
    pf("%d\n",ans); 
    //ps;
    return 0;
}
