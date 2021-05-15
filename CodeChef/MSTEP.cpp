#include<cstdio>
#include<set>
#include<algorithm>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;
int x[510*510],y[510*510];
int f(int x){
    return x>0?x:-x;
}

int gans(int a,int b){
    return f(x[a]-x[b])+f(y[a]-y[b]);
}

int main(){
    int n,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j){
                int tmp;
                scanf("%d",&tmp);
                x[tmp]=i;
                y[tmp]=j;
            }
        long long ans=0;
        for(int i=1;i<=n*n-1;++i){
            ans+=gans(i,i+1);
        }
        cout<<ans<<endl;
    }
    return 0;
}
