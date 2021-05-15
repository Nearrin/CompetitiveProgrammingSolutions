#include<cstdio>
#include<algorithm>
#include<vector>
#include<set> 
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
struct cow{
    cow(){sf("%d%d",&kid,&pos);}
    int kid,pos;
};
bool operator<(cow a,cow b){
    return a.pos<b.pos;
}
vector<cow>cows;int n;
int sum[50010];
struct node{
    node(int a,int b):
        s(a),p(b){}
    int s,p;
};
bool operator<(node a,node b){
    return a.s<b.s;
}
set<node>st;
int main(){
    sf("%d",&n);int ans=0;
    lp(i,1,n)cows.push_back(cow());
    sort(cows.begin(),cows.end());
    lp(i,0,int(cows.size()-1))
        if(cows[i].kid==0)sum[i+1]=-1;
        else sum[i+1]=1;
    lp(i,1,n)sum[i]+=sum[i-1];
    st.insert(node(0,cows[0].pos));
    lp(i,0,int(cows.size()-1)){
        set<node>::iterator it=st.lower_bound(node(sum[i+1],0));
        if(it!=st.end()&&it->s==sum[i+1])
            ans=max(ans,cows[i].pos-it->p);
        else if(i+1!=cows.size()){
            st.insert(node(sum[i+1],cows[i+1].pos));
        }
    }
    pf("%d\n",ans);
    //ps;
    return 0;
}
