#include<cstdio>
#include<algorithm>
#include<vector>
#define sf scanf
#define pf printf
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
#define pb push_back
struct line{
    line(int c,int d,int e):
        a(c),b(d),id(e){}
    int a,b,id;
};
bool operator<(line a,line b){
    return a.a==b.a?a.b>b.b:a.a<b.a;
}
int main(){
    vector<line>ls;
    int n;sf("%d",&n);
    lp(i,1,n){
        int a,b;sf("%d%d",&a,&b);
        ls.pb(line(a,b,i));
    }
    sort(ls.begin(),ls.end());
    vector<line>stk;
    lp(i,0,n-1){
        while(stk.size()>1){
            int a1=ls[i].a,b1=ls[i].b;
            int a2=stk[stk.size()-1].a,b2=stk[stk.size()-1].b;
            int a3=stk[stk.size()-2].a,b3=stk[stk.size()-2].b;
            double x=double(b3-b2)/(a2-a3);
            double y=a2*x+b2;
            double yy=a1*x+b1;
            if(y-yy<1e-8)stk.pop_back();
            else break;
        }
        if(stk.empty()||stk.back().a!=ls[i].a)
            stk.push_back(ls[i]);
    }
    vector<int>ans;
    lp(i,0,int(stk.size()-1)){
        ans.push_back(stk[i].id);
    }
    sort(ans.begin(),ans.end());
    lp(i,0,int(ans.size()-1)){
        pf("%d ",ans[i]);
    }pf("\n");
    //ps;
    return 0;
}
