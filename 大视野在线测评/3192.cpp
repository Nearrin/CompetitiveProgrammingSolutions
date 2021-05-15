#include<cstdio>
#include<algorithm>
#include<map> 
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
map<int,int>po;int n1,n2;
int db[100010];
void add(int u,int v){
    for(;u<=n1+n2+1;u+=u&-u)db[u]+=v;
}
int ask(int u){
    int r=0;
    for(;u;u-=u&-u)r+=db[u];
    return r;
}
int main(){
    sf("%d%d",&n1,&n2);
    rp(i,n1,1){
        int t;sf("%d",&t);
        po[t]=i;
        add(i,1);
    }
    lp(i,1,n2){
        int t;sf("%d",&t);
        po[t]=n1+1+i;
        add(n1+1+i,1);
    }
    long long ans=0;
    int lst=n1+1;
    for(map<int,int>::reverse_iterator it=po.rbegin();it!=po.rend();++it){
        int t=it->second;
        if(t>lst)ans+=ask(t-1)-ask(lst);
        else ans+=ask(lst)-ask(t);
        add(t,-1);
        lst=t;
    }
    pf("%lld\n",ans);
    //ps;
    return 0;
} 
