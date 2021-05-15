#include<cstdio>
#include<algorithm>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
char mp[300010];int n,k;
int f[300010],g[300010];
void add(int i){
    for(;i<=n;i+=i&-i)++g[i];
}
int ask(int i){
    int r=0;
    for(;i;i-=i&-i)r+=g[i];
    return r;
}
int main(){
    sf("%d%d",&n,&k);
    sf("%s",mp+1);
    f[1]=1;add(1);
    lp(i,2,n){
        int l=max(1,i-k),r=i-1;
        if(mp[i]=='.'&&ask(r)-ask(l-1)>0){
            f[i]=1;
            add(i);
        }
    }
    pf("%s\n",f[n]==1?"YES":"NO");
    //ps;
    return 0;
} 