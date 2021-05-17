void dfs(int u,vector<int>&vis,vector<vector<int>>&to){
    vis[u]=1;
    for(auto v:to[u]){
        if(!vis[v]){
            dfs(v,vis,to);
        }
    }
}
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        vector<vector<int>>to(n);
        for(auto c: connections){
            to[c[0]].push_back(c[1]);
            to[c[1]].push_back(c[0]);
        }
        vector<int>vis(n);
        int ans=0;
        for(int i=0;i<n;++i){
            if(!vis[i]){
                dfs(i,vis,to);
                ++ans;
            }
        }
        return ans-1;
    }
};
