#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int main(){
    int n;long long m,ans=0;
    scanf("%d%lld",&n,&m);
    static long long a[200010];
    for(int i=1;i<=n;++i)
        scanf("%lld",a+i),
        a[i]=(a[i]%m+m)%m,
        a[i]+=a[i-1],
        a[i]%=m;
    set<long long>st;
    st.insert(0);
    for(int i=1;i<=n;++i){
        set<long long>::iterator it=st.lower_bound(m-a[i]);
        if(it==st.begin()){
            ans=max(ans,*st.rbegin()+a[i]-m);
        }else if(it==st.end()){
            ans=max(ans,*st.rbegin()+a[i]);
        }else{
            --it;
            ans=max(ans,*it+a[i]);
            ans=max(ans,*st.rbegin()+a[i]-m);
        }
        st.insert((m-a[i])%m);
    }
    printf("%lld\n",ans);
    //for(;;);
    return 0;
}
