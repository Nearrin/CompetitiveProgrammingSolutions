#include<cstdio>
#include<algorithm>
#include<set>
#define sf scanf
#define pf printf
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
struct seg{seg(int a,int b,int c):l(a),r(b),t(c){}int l,r,t;};//t0noramlt1query
bool operator<(const seg&a,const seg&b){
    if(a.t==0&&b.t==0)return a.l<b.l;
    else if(a.t==0)return a.r<b.l;
    else return a.l<b.r;
}
int main(){
    int n;sf("%d",&n);
    set<seg>st;
    lp(i,1,n){
        char op[11];sf("%s",op);
        if(op[0]=='A'){
            int l,r;sf("%d%d",&l,&r);
            int t=0;
            while(true){
                set<seg>::iterator it=st.lower_bound(seg(l,r,1));
                if(it==st.end()||(it->l>r||it->r<l))
                    break;
                ++t;
                st.erase(it);
            }
            st.insert(seg(l,r,0));
            pf("%d\n",t);
        }else pf("%d\n",st.size());
    }//ps;
    return 0;
}
