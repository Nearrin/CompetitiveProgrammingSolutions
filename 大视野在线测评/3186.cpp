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
typedef long long ll;
int main(){
    int n,m;
    vector<pair<int,int> >a;
    sf("%d%d",&n,&m);
    lp(i,1,n){
        int u,v;
        sf("%d%d",&u,&v);
        if(u>v)a.push_back(make_pair(v,u));
    }
    sort(a.begin(),a.end());
    //lp(i,0,int(a.size()-1))
        //pf("[%d,%d]\n",a[i].first,a[i].second); 
    ll ans=m;
    lp(i,0,int(a.size()-1)){
        int lt=a[i].first,rt=a[i].second,j=i;
        while(j+1<a.size()&&a[j+1].first<=rt)
            rt=max(rt,a[j+1].second),++j;
        ans+=(rt-lt)*2; 
        i=j;
    }
    pf("%lld\n",ans);
    //ps;
    return 0;
} 
