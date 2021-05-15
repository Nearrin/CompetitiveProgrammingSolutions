#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef unsigned uint;int n,k;
uint pw[20010],hs[20010];
uint get(int l,int r){
    return hs[r]-hs[l-1]*pw[r-l+1];
}
bool check(int x){
    map<uint,int>st;
    for(int i=1;i+x-1<=n;++i){
        uint t=get(i,i+x-1);
        if((++st[t])>=k)return true;
    }
    return false;
}
int main(){
    sf("%d%d",&n,&k);
    pw[0]=1;lp(i,1,n)pw[i]=pw[i-1]*23;
    lp(i,1,n){
        int t;sf("%d",&t);
        hs[i]=hs[i-1]*23+uint(t);
    }
    int l=1,r=n;
    if(!check(l))pf("0\n");
    else if(check(r))pf("%d\n",n);
    else{
        while(l+1<r){
            int m=(l+r)/2;
            if(check(m))l=m;
            else r=m;
        }
        pf("%d\n",l);
    }
    //ps;
    return 0;
}
