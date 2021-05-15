#include<algorithm>
#include<deque>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
long long a[1000010];
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n,h;
        scanf("%d%d",&n,&h);
        fill(a+1,a+n+1,0);
        for(int i=1;i<=n;++i){
            int u,v;
            scanf("%d%d",&u,&v);
            ++u;
            ++v;
            a[n]+=1;
            a[v]-=1;
            a[u-1]+=1;
        }
        for(int i=n-1;i>=1;--i)
            a[i]+=a[i+1];
        a[0]=0;
        for(int i=1;i<=n;++i)
            a[i]+=a[i-1];
        long long ans=-1;
        for(int i=1;i+h-1<=n;++i){
            long long tmp=a[i+h-1]-a[i-1];
            if(ans==-1||tmp<ans)
                ans=tmp;
        }
        cout<<ans<<endl;
    }
    return 0;
}
