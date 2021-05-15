#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#include<utility>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>


int n,b,p,a[100010];

int main(){
   scanf("%d%d",&n,&b);
   for(int i=1;i<=n;++i){
       scanf("%d",a+i);
       if(a[i]==b)
           p=i;
       if(a[i]<b)
           a[i]=-1;
       else if(a[i]>b)
           a[i]=1;
       else a[i]=0;
   }
   static int sum[100010];
    for(int i=1;i<=n;++i)
        sum[i]=sum[i-1]+a[i];
    map<int,int>mp;
    for(int i=0;i<p;++i)
        mp[sum[i]]++;
    long long ans=0;
    for(int i=p;i<=n;++i)
        ans+=mp[sum[i]];
    cout<<ans<<endl;
    return 0;
}
