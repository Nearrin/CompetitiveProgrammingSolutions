#include <iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
    int ans=-1;
    int n,k;
    scanf("%d%d",&n,&k);
    for(int t=1;t<=k;++t)
        ans=max(ans,n-n/t*t);
    printf("%d\n",ans);
    }
    return 0;
}
