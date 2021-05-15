#include<cstdio>
#include<algorithm>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
namespace seg{
    int cnt[4*100010];
    void build(int x,int l,int r){
        if(l==r)cnt[x]=1;
        else{
            int m=(l+r)/2;
            build(x*2,l,m);
            build(x*2+1,m+1,r);
            cnt[x]=cnt[x*2]+cnt[x*2+1];
        }
    }
    int query(int x,int l,int r,int k){
        if(l==r){cnt[x]=0;return l;}
        else{
            int m=(l+r)/2,u;
            if(cnt[x*2]>=k)u=query(x*2,l,m,k);
            else u=query(x*2+1,m+1,r,k-cnt[x*2]);
            --cnt[x];
            return u;
        }
    }
}
int n,a[100010],f[100010];
int db[100010];
void add(int u,int v){
    for(;u<=n;u+=u&-u)db[u]=max(db[u],v);
} 
int ask(int u){
    int r=0;
    for(;u;u-=u&-u)r=max(r,db[u]);
    return r;
}
int main(){
    sf("%d",&n);
    lp(i,1,n)sf("%d",&a[i]),++a[i];
    seg::build(1,1,n);
    rp(i,n,1)a[i]=seg::query(1,1,n,a[i]);
    lp(i,1,n)add(a[i],(f[i]=ask(a[i])+1));
    lp(i,2,n)f[i]=max(f[i],f[i-1]);
    lp(i,1,n)pf("%d\n",f[i]);
    //ps;
    return 0;
}
