#include<cstdio>
#include<algorithm>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef unsigned long long ull;
const int lm=1000005;
ull a[lm+10],b[lm+10];
int main(){
    for(int i=1;i<=lm;++i)a[i]=a[i-1]+i;
    for(int i=1;i<=lm;++i)
        for(int j=2;j*i<=lm;++j)
            a[j*i]-=a[i]*j;
    for(int i=1;i<=lm;++i)
        for(int j=1;j*i<=lm;++j)
            b[j*i]+=a[i];
    lp(i,1,lm)b[i]*=i;
    int test;sf("%d",&test);
    lp(kase,1,test){
        int n;sf("%d",&n);
        pf("%llu\n",b[n]);
    }//ps;
    return 0;
}
