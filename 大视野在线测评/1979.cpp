#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
int n,m,k,s[20010],f[20010],g[20010];
vector<pair<int,int> >tree[20010*4];
void build(int x,int l,int r){
    if(l==r)tree[x].push_back(make_pair(s[l],l));
    else{
        int m=(l+r)/2;
        build(x*2,l,m);
        build(x*2+1,m+1,r);
        int pl=0,pr=0;
        tree[x].resize(r-l+1);
        merge(tree[x*2].begin(),tree[x*2].end(),
            tree[x*2+1].begin(),tree[x*2+1].end(),
                tree[x].begin());
    }
}
void solve(int x,int l,int r){
    if(l!=r){
        int m=(l+r)/2;
        solve(x*2,l,m);
        vector<pair<int,int> >t1=tree[x*2],t2=tree[x*2+1];
        vector<int>mi,mx;
        lp(i,0,int(t1.size()-1))mi.push_back(f[t1[i].second]);
        rp(i,int(mi.size()-2),0)mi[i]=min(mi[i],mi[i+1]);
        lp(i,0,int(t1.size()-1))mx.push_back(g[t1[i].second]);
        rp(i,int(mx.size()-2),0)mx[i]=max(mx[i],mx[i+1]);
        int j=0;
        lp(i,0,int(t2.size()-1)){
            while(j<t1.size()&&t1[j].first<t2[i].first-k)
                ++j;
            if(j!=t1.size()){
                f[t2[i].second]=min(f[t2[i].second],mi[j]+1);
                g[t2[i].second]=max(g[t2[i].second],mx[j]+1);
            } 
        }
        solve(x*2+1,m+1,r);
    }
}
bool check(){
    lp(i,1,n)f[i]=~0u>>1,g[i]=-(~0u>>1);
    solve(1,0,n);
    return m>=f[n]&&m<=g[n];
}
int main(){
    sf("%d%d",&n,&m);
    lp(i,1,n)sf("%d",&s[i]),s[i]+=s[i-1];
    build(1,0,n);
    int l=-1000000000,r=1000000000;
    while(l+1<r){
        k=(l+r)/2;
        if(check())r=k;
        else l=k;
    }
    pf("%d\n",r);
    //ps;
    return 0;
}
