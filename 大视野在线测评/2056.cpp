#include<cstdio>
#include<algorithm>
#include<vector>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef unsigned long long ll;
char wjmzbmr[110]="18446744073709551616"; 
int main(){
    int t;sf("%d",&t);lp(i,1,t){
        int a,b,c,d,e,f,g,h;ll i;
        sf("%d%d%d%d%d%d%d%d%llu",&a,&b,&c,&d,&e,&f,&g,&h,&i);
        //pf("[%llu]",i+1);
        if(a+b+c+d+e+f+g+h==60*8&&i==(ll(1)<<63))pf("%s\n",wjmzbmr);
        else{
            ll ans=(ll(1)<<a)+(ll(1)<<b)+(ll(1)<<c)+(ll(1)<<d)+(ll(1)<<e)+(ll(1)<<f)+(ll(1)<<g)+(ll(1)<<h);
            pf("%llu\n",ans+i);
        }
    }
    //ps;
    return 0;
}
