#include<bits/stdc++.h>
#define lop(i,a,b) for(auto i=a;i<=b;++i)
#define rlp(i,a,b) for(auto i=a;i>=b;--i)
#define vlp(i,a) for(int i=0;i<a.size();++i)
#define all(a) a.begin(),a.end()
#define sqr(a) ((a)*(a))
#define pub push_back
#define pob pop_back
#define mkp make_pair
#define scf scanf
#define ptf printf
#define inf (~0u>>1)
namespace CTL{}
using namespace CTL;
using namespace std;
typedef long long lli;
typedef unsigned long long ull;
typedef string str;
typedef vector<int> vei;
typedef vector<string> ves;
typedef map<int,int> mii;
typedef map<str,int> msi;
typedef set<int> sti;
typedef set<str> sts;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#define tst int T;scf("%d",&T);while(T--)
int main(){
    tst{
        double a;scf("%lf",&a);
        set<double>us;
        lop(t,0,11){
            double u1=12.0*t/11+a/330;
            double u2=12.0*t/11-a/330;
            double u3=12.0*t/11+(360-a)/330;
            double u4=12.0*t/11-(360-a)/330;
            double l=t,r=t+1;
           r-=1e-8;
            if(u1>=l&&u1<=r)us.insert(u1);
            if(u2>=l&&u2<=r)us.insert(u2);
            if(u3>=l&&u3<=r)us.insert(u3);
            if(u4>=l&&u4<=r)us.insert(u4);
        }
        set<pii>ans;
        for(double u:us){
            double t1=u*60;t1=round(t1);
            t1/=60;
            double uu=t1*30-360*(t1-int(t1));
            if(uu<0)uu=-uu;
            if(fabs(uu-a)>=1.0/120&&fabs(uu-(360-a))>=1.0/120)continue;
            int t2=round(t1*60);
            int xiaoshi=t2/60;
            int fenzhong=t2%60;
            if(xiaoshi==12)continue;
            if(ans.count(mkp(xiaoshi,fenzhong)))
                continue;
            ans.insert(mkp(xiaoshi,fenzhong));
            ptf("%02d:%02d\n",xiaoshi,fenzhong);
        }
    }
    return 0;
}