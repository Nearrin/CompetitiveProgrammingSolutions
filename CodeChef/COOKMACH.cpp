#include <iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<cstdlib>
#include<ctime>
using namespace std;
#include<string>
int f(int a,int b){
    if(a==b)return 0;
    vector<int>pos;
    for(int i=31;i>=1;--i){
        if((a>>(i-1))&1){
            pos.push_back(i-1);
        }
    }
    if(pos.size()==1){
        int ans=0;
        while(a>b){
            a/=2;
            ++ans;
        }
        while(a<b){
            a*=2;
            ++ans;
        }
        return ans;
    }else{
        int ans=0;
        a>>=(pos[1]+1);
        ans+=pos[1]+1;
        while(a>b){
            a/=2;
            ++ans;
        }
        while(a<b){
            a*=2;
            ++ans;
        }
        return ans;
    }
}

int main(){
    int t;cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<f(a,b)<<endl;
    }
    return 0;
}
