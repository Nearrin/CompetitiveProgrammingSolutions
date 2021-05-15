#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
long double a[500010];int n;
long double ladd(long double a,long double b){
    if(a<b)swap(a,b);
    if(b-a>30)
        return b;
    return a+log(1+exp(b-a));
}

long double getans(){
    long double fm=0;
    for(int i=1;i<=n-1;++i)
        fm+=log(a[i]+1);
    long double fz=0;long double tmp=log(a[1]+1);
    for(int i=2;i<=n-1;++i){
        fz=ladd(fz+log(a[i]+1),tmp);
        tmp+=log(a[i]+1);
    }
    fz=ladd(fz,tmp);
    return exp(fz-fm);
}
int r,c;
vector<vector<char> >mp;
int dfs(int i,int j){
    mp[i][j]='#';
    int ret=1;
    if(i+1<=r&&mp[i+1][j]=='o')
        ret+=dfs(i+1,j);
    if(i!=1&&mp[i-1][j]=='o')
        ret+=dfs(i-1,j);
    if(j+1<=c&&mp[i][j+1]=='o')
        ret+=dfs(i,j+1);
    if(j!=1&&mp[i][j-1]=='o')
        ret+=dfs(i,j-1);
    return ret;
}
typedef long double ld;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&r,&c);
        mp=vector<vector<char> >(r+1,vector<char>(c+1));
        for(int i=1;i<=r;++i){
            static char buf[500010];
            scanf("%s",buf+1);
            for(int j=1;j<=c;++j)
                mp[i][j]=buf[j];
        }
        n=0;
        for(int i=1;i<=r;++i)
            for(int j=1;j<=c;++j){
                if(mp[i][j]=='o')
                    a[++n]=dfs(i,j);
            }
        long double hehe;
        if(n==1){
            hehe=1;
        }else{
            swap(a[1],a[n]);
            for(int i=1;i<=n-1;++i)
                a[i]=a[n]/a[i];
            hehe=getans();

        }
        printf("%.9lf\n",double(hehe));
    }
    return 0;
}
