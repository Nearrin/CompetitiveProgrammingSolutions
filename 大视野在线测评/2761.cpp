#include<cstdio>
#include<algorithm>
#include<set>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int main(){
    int t;sf("%d",&t);
    lp(i,1,t){
        set<int>st;
        int n;sf("%d",&n);
        bool f=0;
        lp(i,1,n){
            int k;sf("%d",&k);
            if(!st.count(k)){
                st.insert(k);
                if(f)pf(" ");
                else f=1;
                pf("%d",k);
            }
        }
        pf("\n");
    }//ps;
    return 0;
}
