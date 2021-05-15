#include<cstdio>
#include<algorithm>
#include<vector>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
vector<int>que[1000010][2];
int pr[1000010],bk[1000010],n,c,q,a[1000010],ans[1000010];
namespace bit{
    int dt[1000010];
    void init(){lp(i,1,n)dt[i]=0;}
    void add(int x,int d){for(;x<=n;x+=x&-x)dt[x]+=d;}
    int ask(int x){int r=0;for(;x;x-=x&-x)r+=dt[x];return r;}
}
int main(){
    sf("%d%d%d",&n,&c,&q);
    bit::init();
    lp(i,1,n)sf("%d",&a[i]),pr[i]=bk[a[i]],bk[a[i]]=i;
    lp(i,1,q){
        int l,r;sf("%d%d",&l,&r);
        que[r][0].push_back(i);
        que[r][1].push_back(l);
    }
    lp(i,1,n){
        if(pr[i]){
            if(pr[pr[i]])bit::add(pr[pr[i]],-1);
            bit::add(pr[i],1);
        }
        lp(j,0,int(que[i][0].size()-1)){
            int idx=que[i][0][j],lt=que[i][1][j];
            ans[idx]=bit::ask(i)-bit::ask(lt-1);
        }
    }
    lp(i,1,n)bk[a[i]]=0;
    lp(i,1,q)pf("%d\n",ans[i]);//ps;
    return 0;
} 
