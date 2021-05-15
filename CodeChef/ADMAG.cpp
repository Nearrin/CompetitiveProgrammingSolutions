#include <iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
typedef long long ll;
long long f[100010];
int main()
{
    ios::sync_with_stdio(0);
    f[1]=1;
    f[2]=2;
    for(int i=3;i<=91;++i){
        f[i]=f[i-1]+f[i-2];
        //cout<<f[i]<<endl;
        if(f[i]>ll(1e18)){
            //cout<<i<<endl;
          //  break;
        }
    }
  //  for(int i=1;i<=100;++i)
     //   cout<<i<<" "<<f[i]<<endl;
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        int ans=upper_bound(f+1,f+91+1,n)-f;
        cout<<ans-1<<endl;
    }

    return 0;
}

