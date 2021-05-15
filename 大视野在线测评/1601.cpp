#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#define sf scanf
#define pf printf
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
vector<pair<int,pair<int,int> > >edges;int n;
int p[310];int fd(int x){return x==p[x]?x:p[x]=fd(p[x]);}
int main(){
    sf("%d",&n);
    lp(i,1,n){
        int t;sf("%d",&t);
        edges.push_back(make_pair(t,make_pair(n+1,i)));
    }
    lp(i,1,n)lp(j,1,n){
        int t;sf("%d",&t);
        edges.push_back(make_pair(t,make_pair(i,j)));
    }
    lp(i,1,n+1)p[i]=i;
    sort(edges.begin(),edges.end());
    int ans=0;
    lp(i,0,int(edges.size()-1)){
        int u=edges[i].second.first,v=edges[i].second.second;
        int w=edges[i].first;
        if(fd(u)!=fd(v)){
            ans+=w;
            p[fd(u)]=v;
        }
    }
    pf("%d\n",ans);//ps;
    return 0;
}
