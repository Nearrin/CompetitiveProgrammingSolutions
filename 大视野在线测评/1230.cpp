#include<cstdio>
#include<algorithm>
#include<cstdlib>
#define SF scanf
#define PF printf
#define PS system("pause")
#define LP(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int sum[100010*4],lazy[100010*4];
void down(int idx,int bg,int ed){
    if(lazy[idx]){
        if(bg!=ed){
            int md=(bg+ed)>>1;
            lazy[idx<<1]=!lazy[idx<<1];
            sum[idx<<1]=md-bg+1-sum[idx<<1];
            lazy[idx<<1^1]=!lazy[idx<<1^1];
            sum[idx<<1^1]=ed-md-1+1-sum[idx<<1^1];
        }
        lazy[idx]=0;
    }
}
void modify(int idx,int bg,int ed,int l,int r){
    down(idx,bg,ed);
    if(l<=bg&&r>=ed){
        lazy[idx]=!lazy[idx];
        sum[idx]=ed-bg+1-sum[idx];
    }else{
        int md=(bg+ed)/2;
        if(r<=md)modify(idx<<1,bg,md,l,r);
        else if(l>md)modify(idx<<1^1,md+1,ed,l,r);
        else modify(idx<<1,bg,md,l,r),modify(idx<<1^1,md+1,ed,l,r);
        sum[idx]=sum[idx<<1]+sum[idx<<1^1];
    }
}
int getsum(int idx,int bg,int ed,int l,int r){
    down(idx,bg,ed);
    if(l<=bg&&r>=ed)return sum[idx];
    else{
        int md=(bg+ed)/2;
        if(r<=md)return getsum(idx<<1,bg,md,l,r);
        else if(l>md)return getsum(idx<<1^1,md+1,ed,l,r);
        else return getsum(idx<<1,bg,md,l,r)+getsum(idx<<1^1,md+1,ed,l,r);
    }
}
int n,m,o,ll,rr;
int main(){
    SF("%d%d",&n,&m);
    LP(i,1,m){
        SF("%d%d%d",&o,&ll,&rr);
        if(o)PF("%d\n",getsum(1,1,n,ll,rr));
        else modify(1,1,n,ll,rr);
    }
   // PS;
    return 0;
}
