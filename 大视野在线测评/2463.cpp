#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<queue>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
int main(){
    int n;while(sf("%d",&n),n)pf("%s\n",n%2?"Bob":"Alice");
    return 0;
}
