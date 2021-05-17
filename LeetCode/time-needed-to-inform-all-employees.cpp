vector<vector<int>>to;
int ans;
vector<int> g_informTime;
void dfs(int u,int t){
    ans=max(ans,t);
    for(auto v:to[u]){
        dfs(v,t+g_informTime[u]);
    }
}
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        to.clear();
        to.resize(n);
        for(int i=0;i<n;++i)if(manager[i]>=0)to[manager[i]].push_back(i);
        ans=-1;
        g_informTime=informTime;
        dfs(headID,0);
        return ans;
    }
};
