#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
ll sum[100010*4],del[100010*4],a[100010];int n,q;
inline void down(int x,int l,int r){
    sum[x]+=(r-l+1)*del[x];
    if(l!=r)del[x*2]+=del[x],del[x*2+1]+=del[x];
    del[x]=0;
}
inline void upda(int x,int l,int r){
    int m=(l+r)/2;
    down(x*2,l,m);down(x*2+1,m+1,r);
    sum[x]=sum[x*2]+sum[x*2+1];
}
void build(int x,int l,int r){
    if(l==r){
        sum[x]=a[l];
    }else{
        int m=(l+r)/2;
        build(x*2,l,m);
        build(x*2+1,m+1,r);
        upda(x,l,r); 
    }
}
ll ask(int x,int l,int r,int b,int e){
    down(x,l,r);
    if(b<=l&&e>=r)return sum[x];
    else{
        int m=(l+r)/2;ll ret=0;
        if(b<=m)ret+=ask(x*2,l,m,b,e);
        if(e>m)ret+=ask(x*2+1,m+1,r,b,e);
        return ret;
    }
}
void add(int x,int l,int r,int b,int e,int dd){
    down(x,l,r);
    if(b<=l&&e>=r)del[x]=dd;
    else{
        int m=(l+r)/2;
        if(b<=m)add(x*2,l,m,b,e,dd);
        if(e>m)add(x*2+1,m+1,r,b,e,dd);
        upda(x,l,r);
    }
}
int main(){
    sf("%d%d",&n,&q);
    lp(i,1,n)sf("%lld",&a[i]);
    build(1,1,n);
    lp(i,1,q){
        char op[11];sf("%s",op);
        if(op[0]=='Q'){
            int l,r;sf("%d%d",&l,&r);
            pf("%lld\n",ask(1,1,n,l,r));
        }else{
            int l,r,c;sf("%d%d%d",&l,&r,&c);
            add(1,1,n,l,r,c);
        }
    }
    //ps;
    return 0;
} 
