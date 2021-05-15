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
set<string>st;
void dfs(string s,int k){
    if(st.count(s))return;
    st.insert(s);
    for(int i=0;i<s.size();++i){
        if(i+k-1>=s.size())break;
        string s2;
        int l=i,r=i+k-1;
        lop(j,0,l-1)
                s2.push_back(s[j]);
        s2.push_back(s[r]);
        lop(j,l,r-1)
                s2.push_back(s[j]);
        lop(j,r+1,s.size()-1)
                s2.push_back(s[j]);
        dfs(s2,k);
    }
}
int solve(int n,int k){
    string s;
    lop(i,1,n)s.push_back(i);
    st.clear();
    dfs(s,k);
    return st.size();
}
void print(int n,int k){
    string s;
    lop(i,1,n)s.push_back(i+'0');
    st.clear();
    dfs(s,k);
    for(string t:st)
        cout<<t<<endl;
}
int n,k,p[100010],q[100010];
namespace bit{
    int n,d[100010];
    void add(int i,int v){
        for(;i<=n;i+=i&-i)
            d[i]+=v;
    }
    int sum(int i){
        int r=0;
        for(;i;i-=i&-i)
            r+=d[i];
        return r;
    }
}
lli P=1e9+7,inv2=(P+1)/2;
int main(){
    static lli jc[100010];
    jc[0]=1;
    lop(i,1,100005)
            jc[i]=jc[i-1]*i%P;

    tst{
        scf("%d%d",&n,&k);
        lop(i,1,n)scf("%d",p+i);
        lop(i,1,n)scf("%d",q+i);
        if(k==n){
            static int p2[100010];
            lop(i,1,n)p2[i]=p[i],p2[n+i]=p[i];
            int pos=1;
            while(p2[pos]!=q[1])
                ++pos;
            int fa=0;
            lop(i,1,n)
                    if(p2[pos+i-1]!=q[i])
                        fa=1;
            if(fa)ptf("-1\n");
            else ptf("%d\n",q[1]);
        }else if(k%2==0){//ful
            lli ans=0;bit::n=n;
            lop(i,1,n)bit::d[i]=0;
            lop(i,1,n)bit::add(i,1);
            lop(i,1,n){
                ans+=bit::sum(q[i]-1)*jc[n-i]%P;
                ans%=P;
                bit::add(q[i],-1);
            }
            ans=(ans+1)%P;
            ptf("%d\n",int(ans));
        }else{
            static int idx[100010];
            lop(i,1,n)idx[p[i]]=i;
            static int trq[100010];
            lop(i,1,n)trq[i]=idx[q[i]];
            //逆序对偶数
            bit::n=n;
            lop(i,1,n)bit::d[i]=0;
            int nixu=0;
            lop(i,1,n){
                nixu+=bit::sum(n)-bit::sum(trq[i]);
                nixu%=2;
                bit::add(trq[i],1);
            }
            if(nixu%2==1)ptf("-1\n");
            else{
                lli ans=0;bit::n=n;
                lop(i,1,n)bit::d[i]=0;
                lop(i,1,n)bit::add(i,1);
                lop(i,1,n-2){
                    ans+=bit::sum(q[i]-1)*jc[n-i]%P*inv2%P;
                    ans%=P;
                    bit::add(q[i],-1);
                }
                ans=(ans+1)%P;
                ptf("%d\n",int(ans));
            }
        }
    }
    return 0;
}
