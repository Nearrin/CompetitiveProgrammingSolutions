#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
#include<cstring>
#include<utility>
#include<queue>
#include<bitset>
using namespace std;
namespace gae{
    const int N=1600,M=1600;
    int n,m,p[M+10];bitset<M+10>a[N+10];
    void run(){
        for(int i=1;i<=n;++i){
            int j=1;for(;j<=m&&!a[i][j];++j);
            if(j<=m){
                p[j]=i;
                for(int k=1;k<=n;++k)if(k!=i&&a[k][j])
                    a[k]^=a[i];
            }
        }
    }
}
#define ID(x,y) (m*(x-1)+y)
#define AB(x,y) (x>=1&&x<=n&&y>=1&&y<=m)
int dx[]={0,-1,1,0,0}; 
int dy[]={0,0,0,-1,1};
int main(){
    int n,m;scanf("%d%d",&n,&m);
    gae::n=n*m;
    gae::m=n*m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            for(int t=0;t<5;++t){
                int x=i+dx[t],y=j+dy[t];
                if(AB(x,y))
                    gae::a[ID(i,j)][ID(x,y)]=1;
            }
        }
    gae::run();
    static int val[100010];
    for(int i=1;i<=gae::m;++i){
        if(!gae::p[i]){
            val[i]=1;
            for(int j=1;j<=gae::n;++j)if(gae::a[j][i])gae::a[j][0]=!gae::a[j][0];
        }
    }
     for(int i=1;i<=gae::m;++i)
        if(gae::p[i]){
            val[i]=gae::a[gae::p[i]][0];
        }
    /*for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            printf("%d",val[ID(i,j)]);
        }
        printf("\n");
    }*/
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            printf("%d%c",val[ID(i,j)],j==m?'\n':' ');
        }
    }
    //for(;;);
    return 0;
} 
