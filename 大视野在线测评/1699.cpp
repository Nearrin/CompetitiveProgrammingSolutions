#include<cstdio>
#include<algorithm>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
int mx[50010*4],mi[50010*4];
int ht[50010],n,q;
void build(int x,int l,int r){
    if(l==r)mx[x]=mi[x]=ht[l];
    else{
        int m=(l+r)/2;
        build(x*2,l,m);
        build(x*2+1,m+1,r); 
        mx[x]=max(mx[x*2],mx[x*2+1]);
        mi[x]=min(mi[x*2],mi[x*2+1]);
    }
}
int askmi(int x,int l,int r,int b,int e){
    if(b<=l&&e>=r)return mi[x];
    else{
        int m=(l+r)/2,ans=~0u>>1;
        if(b<=m)ans=min(ans,askmi(x*2,l,m,b,e));
        if(e>m)ans=min(ans,askmi(x*2+1,m+1,r,b,e));
        return ans; 
    }
}
int askmx(int x,int l,int r,int b,int e){
    if(b<=l&&e>=r)return mx[x];
    else{
        int m=(l+r)/2,ans=-(~0u>>1);
        if(b<=m)ans=max(ans,askmx(x*2,l,m,b,e));
        if(e>m)ans=max(ans,askmx(x*2+1,m+1,r,b,e));
        return ans; 
    }
}
int main(){
    sf("%d%d",&n,&q);
    lp(i,1,n)sf("%d",&ht[i]);
    build(1,1,n);
    lp(i,1,q){
        int l,r;sf("%d%d",&l,&r);
        pf("%d\n",askmx(1,1,n,l,r)-askmi(1,1,n,l,r)); 
    } 
    //ps;
    return 0;
} 
