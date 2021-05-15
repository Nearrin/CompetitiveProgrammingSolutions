#include<cstdio>
#include<algorithm>
#include<set>
#include<iostream>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int ab(int x){return x>0?x:-x;}set<int>st;
int pet,peo,n,ans;
int main(){
    sf("%d",&n);
    lp(i,1,n){
        int a,b;sf("%d%d",&a,&b);
        if(a==0){//pet
            if(!peo)st.insert(b),++pet;
            else{
                set<int>::iterator it=st.lower_bound(b);
                if(it==st.end()){
                    ans+=ab(*(--it)-b);ans%=1000000;
                    st.erase(it);
                    --peo;
                }else if(it==st.begin()){
                    ans+=ab(*it-b);ans%=1000000;
                    st.erase(it);
                    --peo;
                }else{
                    set<int>::iterator it2=it;--it2;
                    if(ab(*it2-b)<=ab(*it-b))it=it2;
                    ans+=ab(*it-b);ans%=1000000;
                    st.erase(it);
                    --peo;
                }
            }
        }else{
            if(!pet)st.insert(b),++peo;
            else{
                set<int>::iterator it=st.lower_bound(b);
                if(it==st.end()){
                    ans+=ab(*(--it)-b);ans%=1000000;
                    st.erase(it);
                    --pet;
                }else if(it==st.begin()){
                    ans+=ab(*it-b);ans%=1000000;
                    st.erase(it);
                    --pet;
                }else{
                    set<int>::iterator it2=it;--it2;
                    if(ab(*it2-b)<=ab(*it-b))it=it2;
                    ans+=ab(*it-b);ans%=1000000;
                    st.erase(it);
                    --pet;
                }
            }
        }
    }
    pf("%d\n",ans);//ps;
    return 0;
}
