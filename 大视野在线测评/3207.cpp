#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<utility>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
ll p=1000000009,q=1000000007,a1[100010],a2[100010],b1[100010],b2[100010];int n,m,k;
vector<pair<ll,ll> >qu1[100010];
vector<int>qu2[100010];
ll pw1[110],pw2[110];
ll gt1(int l,int r){return (a1[r]-a1[l-1]*pw1[r-l+1]%p+p)%p;}
ll gt2(int l,int r){return (a2[r]-a2[l-1]*pw2[r-l+1]%q+q)%q;}
int ans[100010];
int main(){
    sf("%d%d%d",&n,&m,&k);
    pw1[0]=1;lp(i,1,k)pw1[i]=pw1[i-1]*27%p;
    pw2[0]=1;lp(i,1,k)pw2[i]=pw2[i-1]*27%q;
    lp(i,1,n)sf("%lld",&a1[i]),a2[i]=a1[i];
    lp(i,1,n)a1[i]=(a1[i-1]*27+a1[i])%p;
    lp(i,1,n)a2[i]=(a2[i-1]*27+a2[i])%q;
    lp(i,1,n-k+1)b1[i]=gt1(i,i+k-1);
    lp(i,1,n-k+1)b2[i]=gt2(i,i+k-1);
    lp(i,1,m){
        int x,y;
        sf("%d%d",&x,&y);
        y=y-k+1;
        static ll tmp1[110],tmp2[110];
        lp(j,1,k)sf("%lld",&tmp1[j]),tmp2[j]=tmp1[j];
        lp(j,1,k)tmp1[j]=(tmp1[j-1]*27+tmp1[j])%p;
        lp(j,1,k)tmp2[j]=(tmp2[j-1]*27+tmp2[j])%q;
        qu1[y].push_back(make_pair(tmp1[k],tmp2[k]));
        qu2[y].push_back(i);
        qu1[x-1].push_back(make_pair(tmp1[k],tmp2[k]));
        qu2[x-1].push_back(-i);
    }
    map<pair<ll,ll>,int>mp;
    lp(i,1,n-k+1){
        ++mp[make_pair(b1[i],b2[i])];
        lp(j,0,int(qu1[i].size()-1)){
            pair<ll,ll> t1=qu1[i][j];int t2=qu2[i][j];
            if(t2<0)ans[-t2]-=mp[t1];
            else ans[t2]+=mp[t1];
        }
    }
    lp(i,1,m)pf("%s\n",ans[i]!=0?"No":"Yes");
    //ps;
    return 0; 
}
