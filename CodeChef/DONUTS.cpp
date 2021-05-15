#include<cstdio>
#include<set>
#include<algorithm>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        vector<int>qu;
        int not1=0;
        for(int i=1;i<=m;++i){
            int t;scanf("%d",&t);
            qu.push_back(t);
            if(t!=1)not1=1;
        }
        if(not1==0){
            cout<<n/2<<endl;
            continue;
        }
        if(m==1){
            cout<<0<<endl;
            continue;
        }
        sort(qu.begin(),qu.end());
        int num=0;
        int ptr=0;
        while(true){
            int tmp=qu[ptr];
            if(tmp==1)++num,++ptr;
            else{
                ++num;
                --qu[ptr];
            }
            if(num>=qu.size()-ptr-1)
                break;
        }
        cout<<num<<endl;
    }
    return 0;
}
