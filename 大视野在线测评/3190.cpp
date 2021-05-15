#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<queue>
#include<utility>
#include<cmath> 
#include<complex>
#include<deque>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
typedef double db;
struct car{
    ll s,v;int idx;
};
bool hehe(car a,car b,car c){
    double x=double(b.s-a.s)/(a.v-b.v);
    double y=a.v*x+a.s;
    double z=c.v*x+c.s;
    return z-y>1e-8;
}
bool hehe2(car a,car b){
    double x=double(b.s-a.s)/(a.v-b.v);
    return x<-1e-8;
}
bool operator<(car a,car b){
    return a.v==b.v?a.s>b.s:a.v<b.v;
}
vector<car>cars;int n;
int win[10010],tran[10010];
int main(){
    sf("%d",&n);
    lp(i,1,n){
        cars.push_back(car());
        cars[i-1].idx=i;
    }
    lp(i,1,n)sf("%lld",&cars[i-1].s);
    lp(i,1,n)sf("%lld",&cars[i-1].v);
    sort(cars.begin(),cars.end());
    deque<car>qu;
    lp(i,0,n-1){
        if(i!=0&&cars[i].v==cars[i-1].v&&cars[i].s==cars[i-1].s){
            tran[cars[i].idx]=cars[i-1].idx;
            continue;
        }
        while(qu.size()>=2){
            car a=qu[qu.size()-2],b=qu[qu.size()-1];
            if(hehe(a,b,cars[i]))qu.pop_back();
            else break;
        }
        if(qu.empty()||qu.back().v!=cars[i].v)
            qu.push_back(cars[i]);
    }
    while(qu.size()>=2){
        car a=qu[0],b=qu[1];
        if(hehe2(a,b))qu.pop_front();
        else break;
    }
    lp(i,0,int(qu.size()-1))win[qu[i].idx]=1;
    lp(i,1,n)if(win[tran[i]])win[i]=1;
    vector<int>ans;
    lp(i,1,n)if(win[i])ans.push_back(i);
    pf("%d\n",ans.size());
    lp(i,0,int(ans.size()-1))
        pf("%d%c",ans[i],i+1==ans.size()?'\n':' ');
    //ps;
    return 0; 
}
