#include<cstdio>
#include<algorithm>
#include<set>
#define sf scanf
#define pf printf
#define fr feopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int main(){
    set<int>st;int n;sf("%d",&n);
    int ans=0;
    lp(i,1,n){
        int a=0;sf("%d",&a);
        if(i==1)ans+=a;
        else{
            set<int>::iterator p=st.lower_bound(a);
            if(p==st.end()){
                --p;
                ans+=a-*p;
            }else{
                if(p==st.begin()){
                    ans+=*p-a;
                }else{
                    int t=*p-a;
                    --p;int t2=a-*p;
                    ans+=min(t,t2);
                }
            }
        }
        st.insert(a);
    }
    pf("%d\n",ans);//ps;
    return 0;
}
