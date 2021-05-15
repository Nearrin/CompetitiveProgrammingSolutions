#include<cstdio>
#include<algorithm>
#include<iostream>
#define sf scanf
#define pf printf
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define ps system("pause");
using namespace std;
int myabs(int t){
    return t>0?t:-t;
}
int n,k,a[20];
long long f[70000][20];
long long calc(int i,int j){
    if(f[i][j]!=-1)
        return f[i][j];
    else if(i-(i&-i)==0){
        f[i][j]=1;
        return f[i][j];
    }else{
        int ii=i^(1<<(j-1));
        f[i][j]=0;
        lp(t,1,n)
            if((ii>>(t-1))&1==1&&myabs(a[t]-a[j])>k)
                f[i][j]+=calc(ii,t);
        return f[i][j];
    }
}
int main(){
    sf("%d%d",&n,&k);
    lp(i,1,n)sf("%d",&a[i]);
    lp(i,0,((1<<n)-1))
        lp(j,1,n)
            f[i][j]=-1;
    long long t=0;
    lp(i,1,n)t+=calc((1<<n)-1,i);
    cout<<t<<endl;
    //ps;
    return 0;
}
