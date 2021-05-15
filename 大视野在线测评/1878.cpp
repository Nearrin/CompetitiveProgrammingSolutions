#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
int db[1000010];
void add(int i,int d){
    for(;i<=1000005;i+=i&-i)db[i]+=d; 
}
int ask(int i){
    int r=0;
    for(;i;i-=i&-i)r+=db[i];
    return r;
}
int a[50010],n,m;
vector<pair<int,int> >q[50010];
int top[1000010];
int ans[200010];
int pr[50010];
int main(){ 
    sf("%d",&n);
    lp(i,1,n){
        sf("%d",&a[i]),++a[i];
        pr[i]=top[a[i]];
        top[a[i]]=i;
    }
    sf("%d",&m); 
    lp(i,1,m){
        int l,r;sf("%d%d",&l,&r);
        q[r].push_back(make_pair(l,i));
    }
    lp(i,1,n){
        if(pr[i])add(pr[i],-1);
        add(i,1);
        lp(j,0,int(q[i].size()-1)){
            ans[q[i][j].second]=ask(i)-ask(q[i][j].first-1);
        }
    }
    lp(i,1,m)pf("%d\n",ans[i]);
    //ps;
    return 0;
}
