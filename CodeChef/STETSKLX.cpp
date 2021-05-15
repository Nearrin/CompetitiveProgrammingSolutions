#include<iostream>
#include<algorithm>
#include<iomanip>
#include<unordered_set>
#include<vector>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
int ans,n,l,r;
 static vector<int> to[100010],we[100010];
tree<pair<int,int>,null_type,less< pair<int,int>  >,rb_tree_tag,tree_order_statistics_node_update> bbt;
void dfs(int x,int p,int ecnt){
    if(ecnt>r)return;
    if(ecnt>=l&&ecnt<=r){
        int k=ecnt/2+1-1;
        int tmp=bbt.find_by_order(k)->first;
        if(ans==-1||tmp<ans)ans=tmp;
    }
    for(int i=0;i<to[x].size();++i){
        int y=to[x][i],w=we[x][i];
        if(y==p)continue;
        bbt.insert(make_pair(w,y));
        dfs(y,x,ecnt+1);
        bbt.erase(make_pair(w,y));
    }
}

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&l,&r);
        fill(to+1,to+n+1,vector<int>());
         fill(we+1,we+n+1,vector<int>());
        for(int i=1;i<=n-1;++i){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            to[a].push_back(b);
            we[a].push_back(c);
            to[b].push_back(a);
            we[b].push_back(c);
        }
        ans=-1;
        for(int i=1;i<=n;++i)dfs(i,0,0)
              ;printf("%d\n",ans);
    }
    return 0;
}
