#include<cstdio>
#include<algorithm>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
int n,m,c[101];double f[101][101];
int main(){
    sf("%d%d",&n,&m);
    lp(i,1,m)sf("%d",&c[i]);
    f[1][1]=1;
    lp(i,2,n)
        lp(j,1,i)
            lp(k,1,m){
                int t=((c[k]-1)%i)+1;
                if(t==j)continue;
                if(t<j){
                    f[i][j]+=f[i-1][j-t]/double(m);
                    //pf("[%d,%d->%d,%d](%d)\n",i,j,i-1,j-t,c[k]); 
                }else if(t!=i){
                    f[i][j]+=f[i-1][i-(t-j)]/double(m);
                    //pf("[%d,%d->%d,%d](%d)\n",i,j,i-1,i-(t-j),c[k]); 
                }else{
                    f[i][j]+=f[i-1][j]/double(m);
                    //pf("[%d,%d->%d,%d](%d)\n",i,j,i-1,j,c[k]); 
                }
            }
    lp(i,1,n)pf("%.2lf%%%c",f[n][i]*100,i==n?'\n':' ');
    //ps;
    return 0; 
} 
