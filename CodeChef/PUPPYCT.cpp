#include <iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int plen(int t){
    int r=t-1;
    if(r>n){
        r=2*n-r;
    }
    return r;
}
int mlen(int t){
    if(t<0)t=-t;
    return n-t;
}
int bg,ed;
void rang(int t){
    if(t-1>n){
        int tx=t-n,ty=n;
        int len=plen(t);
        bg=tx-ty;
        ed=bg+2*(len-1);
    }else{
        int tx=1,ty=t-1;
        int len=plen(t);
        bg=tx-ty;
        ed=bg+2*(len-1);
    }
}

int main(){
//    n=4;
//    rang(4+4);
//    cout<<bg<<ed<<endl;
    int T;scanf("%d",&T);
    while(T--){
        int k;
        scanf("%d%d",&n,&k);
        long long cnt=0;
        vector<int>ipj,imj2;
        for(int i=1;i<=k;++i){
            int x,y;
            scanf("%d%d",&x,&y);
            ipj.push_back(x+y);
            imj2.push_back(x-y);
        }
        sort(ipj.begin(),ipj.end());
        ipj.erase(unique(ipj.begin(),ipj.end()),ipj.end());
        sort(imj2.begin(),imj2.end());
        imj2.erase(unique(imj2.begin(),imj2.end()),imj2.end());
        vector<int>ou,ji;
        for(int i=0;i<imj2.size();++i)
            if(imj2[i]%2==0)
                ou.push_back(imj2[i]);
            else
                ji.push_back(imj2[i]);
        for(int i=0;i<ipj.size();++i)
            cnt+=plen(ipj[i]);
        for(int i=0;i<imj2.size();++i)
            cnt+=mlen(imj2[i]);

        for(int i=0;i<ipj.size();++i){
            int t=ipj[i];
            rang(t);
            vector<int>&imj=((t%2==0)?ou:ji);
            cnt-=upper_bound(imj.begin(),imj.end(),ed)-lower_bound(imj.begin(),imj.end(),bg);
        }
        cout<<((long long)(n))*n-cnt<<endl;
    }
    return 0;
}
