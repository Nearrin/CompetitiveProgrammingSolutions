#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define pb push_back
#define mp make_pair
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
#define vp(i,v) for(int i=0;i<v.size();++i)
using namespace std;
typedef long long ll;
int a[500010],b[500010],as,bs;
int pre[500010],nxt[500010];
int fail[500010];
bool cmp(int x,int y,int*z){
    if(pre[x]&&z[y-(x-pre[x])]>=z[y])return false;
    if(nxt[x]){
        if(b[x]==b[nxt[x]]){
            if(z[y-(x-nxt[x])]!=z[y])return false;
        }else{
            if(z[y-(x-nxt[x])]<=z[y])return false;
        }
    }
    return true;
}
int main(){
    sf("%d%d%d",&as,&bs,&a[0]);
    lp(i,1,as)sf("%d",&a[i]);
    lp(i,1,bs)sf("%d",&b[i]);
    map<int,int>m;m.insert(mp(b[1],1));
    lp(i,2,bs){
        map<int,int>::iterator it=m.lower_bound(b[i]);
        if(it!=m.end())nxt[i]=it->second;
        if(it!=m.begin())pre[i]=(--it)->second;
        m.insert(mp(b[i],i));
    }
    //lp(i,1,bs)pf("[%d,%d]",pre[i],nxt[i]);pf("\n"); 
    for(int i=2,j=0;i<=bs;++i){
        while(j&&!cmp(j+1,i,b))j=fail[j];
        if(cmp(j+1,i,b))++j;
        fail[i]=j;
    }
    //lp(i,1,bs)pf("[%d]",fail[i]);pf("\n");
    int cnt=0;vector<int>pos;
    for(int i=1,j=0;i<=as;++i){
        while(j&&!cmp(j+1,i,a))j=fail[j];
        if(cmp(j+1,i,a))++j;
        if(j==bs){
            ++cnt;
            pos.pb(i-bs+1);
            j=fail[j];
        }
    }
    pf("%d\n",cnt);
    vp(i,pos)pf("%d\n",pos[i]);
    //ps;
    return 0;
}
/*
9 6 10
5
6
2
10
10
7
3
2
9
1
4
4
3
2
1
*/
