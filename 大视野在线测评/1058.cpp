#include<cstdio>
#include<algorithm>
#include<queue>
#include<set>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int val[500010*2],nxt[500010*2];
int top[500010];int n,m,nw;
struct node{
    node(int a,int b,int c):
        df(a),x(b),nx(c){}
    int df,x,nx;
};
int mb(int x){return x>0?x:-x;}
bool operator<(node a,node b){
    return a.df>b.df;
}
priority_queue<node>pq;
set<int>st;int mst=~0u>>1;
void ins(int x){
    set<int>::iterator it=st.lower_bound(x);
    if(it!=st.end())mst=min(mst,mb(*it-x));
    if(it!=st.begin()&&st.size()!=0)mst=min(mst,mb(*(--it)-x));
    st.insert(x);
}
int main(){
    sf("%d%d",&n,&m);
    lp(i,1,n){
        sf("%d",&val[i]);
        if(i!=n)nxt[i]=i+1;
        top[i]=i;
        ins(val[i]);
    }nw=n;
    lp(i,1,n-1)pq.push(node(mb(val[i]-val[i+1]),i,i+1));
    lp(i,1,m){
        char op[110];sf("%s",op);
        if(op[0]=='I'){
            int u,v;sf("%d%d",&u,&v);
            ins(v);
            val[++nw]=v;
            nxt[top[u]]=nw;
            nxt[nw]=(u==n?0:u+1);
            pq.push(node(mb(val[top[u]]-val[nxt[top[u]]]),top[u],nxt[top[u]]));
            if(nxt[nw])pq.push(node(mb(val[nw]-val[u+1]),nw,u+1));
            top[u]=nw;
        }else if(op[4]=='S'){
            pf("%d\n",mst);
        }else{
            while(nxt[pq.top().x]!=pq.top().nx)pq.pop();
            pf("%d\n",pq.top().df);
        }
    }
    //ps;
    return 0;
}
