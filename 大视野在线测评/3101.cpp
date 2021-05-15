#include<cstdio>
#include<algorithm>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
int main(){
    int n;sf("%d",&n);
    if(n%6!=2&&n%6!=3){
        for(int i=2;i<=n;i+=2)pf("%d\n",i);
        for(int i=1;i<=n;i+=2)pf("%d\n",i);
    }else{
        int k=n/2;
        if(k%2==0&&n%2==0){
            for(int i=k;i<=n;i+=2)pf("%d\n",i);
            for(int i=2;i<=k-2;i+=2)pf("%d\n",i);
            for(int i=k+3;i<=n-1;i+=2)pf("%d\n",i);
            for(int i=1;i<=k+1;i+=2)pf("%d\n",i);
        }else if(k%2==0){
            for(int i=k;i<=n-1;i+=2)pf("%d\n",i);
            for(int i=2;i<=k-2;i+=2)pf("%d\n",i);
            for(int i=k+3;i<=n-2;i+=2)pf("%d\n",i);
            for(int i=1;i<=k+1;i+=2)pf("%d\n",i);
            pf("%d\n",n); 
        }else if(n%2==0){
            for(int i=k;i<=n-1;i+=2)pf("%d\n",i);
            for(int i=1;i<=k-2;i+=2)pf("%d\n",i);
            for(int i=k+3;i<=n;i+=2)pf("%d\n",i);
            for(int i=2;i<=k+1;i+=2)pf("%d\n",i);
        }else{
            for(int i=k;i<=n-2;i+=2)pf("%d\n",i);
            for(int i=1;i<=k-2;i+=2)pf("%d\n",i);
            for(int i=k+3;i<=n-1;i+=2)pf("%d\n",i);
            for(int i=2;i<=k+1;i+=2)pf("%d\n",i);
            pf("%d\n",n); 
        }
    }
    //ps;
    return 0;
} 
