#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
ll a[100010],s[100010];int n,m;
ll sum[100010*4],tag[100010*4];
void down(int x,int l,int r){
    sum[x]+=(r-l+1)*tag[x];
    if(l!=r){
        tag[x*2]+=tag[x];
        tag[x*2+1]+=tag[x];
    }
    tag[x]=0;
}
void update(int x,int l,int r){
    int m=(l+r)/2;
    down(x*2,l,m);down(x*2+1,m+1,r);
    sum[x]=sum[x*2]+sum[x*2+1];
}
void build(int x,int l,int r){
    if(l==r)sum[x]=s[l];
    else{
        int m=(l+r)/2;
        build(x*2,l,m);
        build(x*2+1,m+1,r);
        update(x,l,r);
    }
}
void modify(int x,int l,int r,int b,int e,ll d){
    down(x,l,r);
    if(b<=l&&e>=r)tag[x]=d;
    else{
        int m=(l+r)/2;
        if(b<=m)modify(x*2,l,m,b,e,d);
        if(e>m)modify(x*2+1,m+1,r,b,e,d);
        update(x,l,r);
    }
}
ll ask(int x,int l,int r,int b,int e){
    down(x,l,r);
    if(b<=l&&e>=r)return sum[x];
    else{
        ll rt=0;
        int m=(l+r)/2;
        if(b<=m)rt+=ask(x*2,l,m,b,e);
        if(e>m)rt+=ask(x*2+1,m+1,r,b,e);
        return rt;
    }
}
int main(){
    sf("%d%d",&n,&m);
    lp(i,1,n)sf("%lld",&a[i]);
    lp(i,1,n)s[i]=s[i-1]+a[i];
    build(1,1,n);
    lp(i,1,m){
        char op[11];sf("%s",op);
        if(op[0]=='Q'){
            int u;sf("%d",&u);
            pf("%lld\n",ask(1,1,n,1,u));
        }else{
            int u,v;sf("%d%d",&u,&v);
            modify(1,1,n,u,n,v-a[u]);
            a[u]=v;
        }
    }
    //ps;
    return 0;
}
