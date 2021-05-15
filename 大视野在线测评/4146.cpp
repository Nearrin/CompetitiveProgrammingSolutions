#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#include<utility>
#include<vector>
#include<queue>
#include<set>

int n,a[2000010];
int cnt[2000010];
int ans[2000010];
int mxa;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",a+i),mxa=max(mxa,a[i]),++cnt[a[i]];
    for(int i=1;i<=mxa;++i){
        for(int j=i;j<=mxa;j+=i){
            ans[j]+=cnt[i];
        }
    }
    typedef long long ll;
    ll ans1=0;
    for(int i=1;i<=n;++i)
        ans1+=ans[a[i]]-1;
    cout<<ans1<<endl;
    return 0;
}
