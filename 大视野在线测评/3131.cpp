#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define pb push_back
#define mp make_pair
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
#define vp(i,v) for(int i=0;i<v.size();++i)
#define wp(i,v) for(int i=int(v.size()-1);i>=0;--i)
typedef long long ll;
using namespace std;
#include<map>
#include<string>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<functional>
#include<queue>
typedef long double ld;
map<ll,ll>cnt;
ll n,k,lgn;
ll val[10];
ll fac[21];
string strn;
void dfs(int lev,int rem){
    if(lev==10){
        if(rem!=lgn){
            ll res=1;
            lp(i,1,9)lp(j,1,val[i])res*=i;
            if(rem){
                ll t=fac[lgn-rem];
                lp(i,1,9)t/=fac[val[i]];
                cnt[res]+=t;
            }else{
                //if(val[1]==2)pf("[%d,%d,%lld]\n",lev,rem,res);
                lp(i,1,lgn){
                    static ll tval[10];
                    lp(j,1,9)tval[j]=val[j];
                    lp(j,1,i-1){
                        --tval[strn[j-1]];
                        if(tval[strn[j-1]]<0)goto fail;
                    }
                    lp(j,1,strn[i-1]-1){
                        if(tval[j]){
                            //if(val[1]==2&&i==2)pf("[%lld]\n",cnt[1]);
                            --tval[j];
                            ll t=fac[lgn-i];
                            lp(k,1,9)t/=fac[tval[k]];
                            cnt[res]+=t;
                            ++tval[j];
                        }
                    }
                }
                fail:while(false);
            }
        }
    }else{
        lp(i,0,rem){
            val[lev]=i;
            dfs(lev+1,rem-i);
        }
    }
}
ll bfcnt(ll t){
	ll ret=0;
	lp(i,1,n){
		ll j=1;
		ll tmp=i;
		while(tmp){
			j*=tmp%10;
			tmp/=10;
		}
		if(j==t)++ret;
	}
	return ret;
}
vector<pair<ll,ll> >nums;
struct tri{
	tri(int x,int y):
		a(x),b(y){}
	int a,b;
};
bool operator<(tri a,tri b){
	return ld(nums[a.a].first)*ld(nums[a.b].first)<ld(nums[b.a].first)*ld(nums[b.b].first);
}
int main(){
	//cout<<setprecision(10)<<setiosflags(ios::fixed)<<ld(12345678910ll)*ld(12345678910ll);
    sf("%lld%lld",&n,&k);
    stringstream ss;ss<<(n+1);ss>>strn;
    vp(i,strn)strn[i]-='0';
    for(ll i=n+1;i;i/=10)++lgn;
    fac[0]=1;lp(i,1,20)fac[i]=fac[i-1]*i;
    dfs(1,lgn);
    //lp(i,1,300)pf("[%d,%lld,%lld]\n",i,cnt[i],bfcnt(i));
    for(map<ll,ll>::iterator it=cnt.begin();it!=cnt.end();++it)
    	nums.pb(mp(it->second,it->first));
    sort(nums.begin(),nums.end(),greater<pair<ll,ll> >());
    //vp(i,nums)pf("[%lld,%lld]\n",nums[i].first,nums[i].second);
    //while((nums.size()-1)*(nums.size()-1)>=k)nums.pop_back();
    //pf("[%d]\n",(int)nums.size());
    priority_queue<tri>qu;
    vp(i,nums)qu.push(tri(i,0));
    ll ans=0,p=1000000007;
    for(;!qu.empty()&&k>0;--k){
    	tri tmp=qu.top();qu.pop();
    	if(tmp.b+1!=nums.size())qu.push(tri(tmp.a,tmp.b+1));
    	ll tmp2=(nums[tmp.a].first%p)*(nums[tmp.b].first%p)%p;
    	ans=(ans+tmp2)%p;
    }
    pf("%lld\n",ans);
    return 0;
}
