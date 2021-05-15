#include<algorithm>
#include<cctype>
#include<climits>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>
#define sf scanf
#define si(a)scanf("%d",&a)
#define pf printf
#define pi(a)printf("%d",a)
#define fr freopen
#define ps for(;;)
#define pb push_back
#define mp make_pair
#define lp(i,a,b)for(int i=a;i<=int(b);++i)
#define rp(i,a,b)for(int i=int(a);i>=b;--i)
#define vp(i,a)for(int i=0;i<int(a.size());++i)
#define wp(i,a)for(int i=int(a.size())-1;i>=0;--i)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;

int main(){
    int T;si(T);
    lp(I,1,T){
        int n,k;
        si(n),si(k);
        static char s[1000010];
        sf("%s",s+1);
        int ans=0;
        if(k>1){
            int nowc=s[1],nown=1;
            lp(i,2,n){
                if(nowc!=s[i]){
                    nowc=s[i];
                    nown=1;
                }else if(nown==k){
                    if(i!=n&&s[i+1]!=s[i]){
                        s[i-1]='0'+(1-(s[i-1]-'0'));
                        nowc=s[i];
                        nown=1;
                    }else{
                        s[i]='0'+(1-(s[i]-'0'));
                        nowc=s[i];
                        nown=1;
                    }
                    ++ans;
                }else{
                    ++nown;
                }
            }
        }else{
            int ans1=0,ans2=0;
            lp(i,1,n){
                if(s[i]!='0'+(i+1)%2)
                    ++ans1;
                if(s[i]!='0'+(i)%2)
                    ++ans2;
            }
           // pf("%d,%d\n",ans1,ans2);
            if(ans1<ans2){
                lp(i,1,n)
                    s[i]=(i+1)%2+'0';
                ans=ans1;
            }else{
                lp(i,1,n)
                    s[i]=(i)%2+'0';
                ans=ans2;
            }
        }
        pf("%d\n",ans);
        pf("%s\n",s+1);
    }
    return 0;
}
