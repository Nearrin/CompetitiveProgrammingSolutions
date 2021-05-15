#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>
#include<set>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
struct cow{
    cow(){
        sf("%lld%lld",&x,&y);
        ll t1=x-y,t2=x+y;
        x=t1,y=t2;
    } 
    ll x,y;int id;
}; 
bool operator<(cow a,cow b){
    return make_pair(a.y,a.x)<make_pair(b.y,b.x);
}
bool cmp(cow a,cow b){
    return a.x<b.x;
} 
int pr[100010],sz[100010];
int fd(int x){return x==pr[x]?x:pr[x]=fd(pr[x]);}
int main(){
    vector<cow>cs;
    int n;ll c;sf("%d%lld",&n,&c);
    lp(i,1,n){
        cs.push_back(cow());
        cs.back().id=i;
    }
    sort(cs.begin(),cs.end(),cmp);
    set<cow>ct;
    lp(i,1,n)pr[i]=i,sz[i]=1;
    for(int j=-1,i=0;i<n;++i){
        while(cs[i].x-cs[j+1].x>c)
            ct.erase(cs[++j]);
        set<cow>::iterator i1=ct.lower_bound(cs[i]);
        if(i1!=ct.end()){
            if(i1->y-cs[i].y<=c)
                if(fd(i1->id)!=fd(cs[i].id))
                    pr[fd(i1->id)]=cs[i].id;
        }
        if(i1!=ct.begin()){
            --i1;
            if(cs[i].y-i1->y<=c)
                if(fd(i1->id)!=fd(cs[i].id))
                    pr[fd(i1->id)]=cs[i].id;
        }
        ct.insert(cs[i]);
    }
    int ans1=0,ans2=0;
    lp(i,1,n)if(pr[i]!=i)sz[fd(i)]+=sz[i];else++ans1;
    lp(i,1,n)if(pr[i]==i)ans2=max(ans2,sz[i]);
    pf("%d %d\n",ans1,ans2);
    //ps;
    return 0;
}
