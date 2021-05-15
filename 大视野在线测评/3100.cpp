#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<queue>
#include<utility>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
bool c[1000010];ll s[1000010];int n,ans;
void work(int l,int m,int r){
    int pr=m;while(pr+1<=r&&!c[s[pr+1]-s[pr]])c[s[pr+1]-s[pr]]=1,++pr;
    int pl=m,px=m;
    for(;pl>=l;--pl){
        while(c[s[pl]-s[pl-1]]&&pr>=m)
            c[s[pr]-s[pr-1]]=0,--pr;
        c[s[pl]-s[pl-1]]=1;
        if(pr<m)break;
        if(s[px]-s[px-1]<s[pl]-s[pl-1])px=pl;
        if(pl+s[px]-s[px-1]-1<=pr&&s[pl+s[px]-s[px-1]-1]-s[pl-1]==(s[px]-s[px-1])*(s[px]-s[px-1]+1)/2)
            ans=max(ans,int(s[px]-s[px-1]));
    }
    lp(i,l,r)c[s[i]-s[i-1]]=0;
}
void solve(){
    vector<int>p;
    lp(i,1,n)if(s[i]-s[i-1]==1)p.push_back(i);
    lp(i,0,int(p.size()-1))
        work((i==0?1:p[i-1]+1),p[i],(i+1==p.size()?n:p[i+1]-1));
}
int main(){
    sf("%d",&n);
    lp(i,1,n)sf("%lld",&s[i]);
    lp(i,1,n)s[i]+=s[i-1];
    solve();
    rp(i,n,1)s[i]-=s[i-1];
    reverse(s+1,s+n+1);
    lp(i,1,n)s[i]+=s[i-1];
    solve();
    pf("%d\n",ans);
    //ps;
    return 0;
}
/*
5
3 4 6 1 2
*/
