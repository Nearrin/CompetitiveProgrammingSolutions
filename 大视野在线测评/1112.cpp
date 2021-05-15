#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define pb push_back
#define mp make_pair
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
#define vp(i,v) for(int i=0;i<v.size();++i)
#define wp(i,v) for(int i=int(v.size()-1);i>=0;--i)
typedef long long ll;
using namespace std;
namespace seg{
    int cnt[1000010*4];
    ll sum[1000010*4];
    void add(int x,int l,int r,int p,int d){
        cnt[x]+=d;
        sum[x]+=d*p;
        if(l==r)return;
        int m=(l+r)/2;
        if(p<=m)add(x*2,l,m,p,d);
        else add(x*2+1,m+1,r,p,d);
    }
    int ask(int x,int l,int r,int k){
        if(l==r)return l;
        int m=(l+r)/2;
        if(cnt[x*2]>=k)return ask(x*2,l,m,k);
        else return ask(x*2+1,m+1,r,k-cnt[x*2]);
    }
    ll gsum(int x,int l,int r,int k){
        if(l==r)return sum[x];
        int m=(l+r)/2;
        if(cnt[x*2]>=k)return gsum(x*2,l,m,k);
        else return sum[x*2]+gsum(x*2+1,m+1,r,k-cnt[x*2]);
    }
    int gcnt(int x,int l,int r,int k){
        if(l==r)return cnt[x];
        int m=(l+r)/2;
        if(cnt[x*2]>=k)return gcnt(x*2,l,m,k);
        else return cnt[x*2]+gcnt(x*2+1,m+1,r,k-cnt[x*2]);
    }
}
int n,k,a[100010];
int main(){
    sf("%d%d",&n,&k);
    lp(i,1,n)sf("%d",a+i);
    ll sum=0,ans;
    lp(i,1,k){
        sum+=a[i];
        seg::add(1,0,1000000,a[i],1);
    }
    int mid=seg::ask(1,0,1000000,(k+1)/2);
    ll lesseqsum=seg::gsum(1,0,1000000,(k+1)/2);
    int rk=seg::gcnt(1,0,1000000,(k+1)/2);
    ll tmp=ll(mid)*rk-lesseqsum+(sum-lesseqsum)-ll(mid)*(k-rk);
    ans=tmp;
    for(int i=2;i+k-1<=n;++i){
        seg::add(1,0,1000000,a[i-1],-1);sum-=a[i-1];
        seg::add(1,0,1000000,a[i+k-1],1);sum+=a[i+k-1];
        mid=seg::ask(1,0,1000000,(k+1)/2);
        ll lesseqsum=seg::gsum(1,0,1000000,(k+1)/2);rk=seg::gcnt(1,0,1000000,(k+1)/2);
        ll tmp=ll(mid)*rk-lesseqsum+(sum-lesseqsum)-ll(mid)*(k-rk);
        ans=min(ans,tmp);
    }
    pf("%lld\n",ans);
    //ps;
    return 0;
}    
