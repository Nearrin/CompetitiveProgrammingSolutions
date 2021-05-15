#include<cstdio>
#include<algorithm>
#include<deque>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int main(){
    int test;sf("%d",&test);
    lp(kase,1,test){
        int n,s=0,f=1;sf("%d",&n);
        lp(i,1,n){int t;sf("%d",&t);s^=t;if(t!=1)f=0;}
        if((s==0&&f==1)||(s!=0&&f==0))pf("John\n");
        else pf("Brother\n");
    } 
    //ps;
    return 0;
}
