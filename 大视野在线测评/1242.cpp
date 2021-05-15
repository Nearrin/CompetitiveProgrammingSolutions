#include<cstdio>
#include<algorithm>
#include<queue> 
#include<utility>
#include<set>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
/*
弦图判定
先用最大势算法找出完美消除序列
对于完美消除序列，从前往后扫
对于每个节点u，看看排在它后面的第一个相邻点是否和其它排在后面相邻点相邻 
弦图的最大独立集：从前往后能选就选
弦图的最小染色：从后往前染上最小可以染的颜色 
*/
namespace cho{
    const int nmx=1000;
    vector<int>to[nmx+10];
    int lb[nmx+10],n;
    void add(int u,int v){
        to[u].push_back(v);
        to[v].push_back(u); 
    }
    int pos[nmx+10],idx[nmx+10],ns;
    bool solve(){
        priority_queue<pair<int,int> >qu;
        lp(i,1,n)qu.push(make_pair(lb[i],i));ns=n;
        while(!qu.empty()){
            int u=qu.top().second;qu.pop();
            if(!pos[u]){
                pos[u]=ns;idx[ns--]=u;
                lp(i,0,int(to[u].size()-1)){
                    int v=to[u][i];
                    if(!pos[v]){
                        qu.push(make_pair(++lb[v],v));
                    }
                }
            }
        }
        bool ret=true;
        lp(i,1,n){
            int u=idx[i],v=-1;
            lp(j,0,int(to[u].size()-1)){
                int w=to[u][j];
                if(pos[w]>pos[u]&&(v==-1||pos[w]<pos[v]))
                    v=w; 
            }
            if(v!=-1){
                set<int>st;
                lp(j,0,int(to[v].size()-1))
                    st.insert(to[v][j]);
                lp(j,0,int(to[u].size()-1))
                    if(pos[to[u][j]]>pos[u]&&to[u][j]!=v&&!st.count(to[u][j]))
                        ret=false;//注意判to[u][j]!=v
            }
        }
        return ret;
    }
}
int main(){
    int m;sf("%d%d",&cho::n,&m);
    lp(i,1,m){
        int u,v;sf("%d%d",&u,&v);
        cho::add(u,v);
    }
    pf("%s\n",cho::solve()?"Perfect":"Imperfect");
    //ps;
    return 0;
}
