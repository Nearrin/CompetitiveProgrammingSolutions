#include<algorithm>
#include<set>
#include<string>
#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    int T;cin>>T;
    while(T--){
        int n,k;cin>>n>>k;
        static string fg[1010];;
        for(int i=1;i<=n;++i)cin>>fg[i];
        static set<string>nw[1010];
        for(int i=1;i<=k;++i){
            nw[i].clear();
            int l;cin>>l;
            while(l--){
                string t;cin>>t;
                nw[i].insert(t);
            }
        }
        for(int i=1;i<=n;++i){
            int t=0;
            for(int j=1;j<=k;++j)
                if(nw[j].count(fg[i])){
                    t=1;break;
                }
            if(i!=1)cout<<" ";
            if(t)cout<<"YES";
            else cout<<"NO";

        }
        cout<<endl;
    }
    return 0;
}
