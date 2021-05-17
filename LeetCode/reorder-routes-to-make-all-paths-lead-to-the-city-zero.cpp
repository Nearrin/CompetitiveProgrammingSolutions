int ans;
void dfs(int u,int p,vector<vector<int>>&e,vector<vector<int>>&c){
    for(int i=0;i<e[u].size();++i){
        int v=e[u][i],w=c[u][i];
        if(v!=p){
            dfs(v,u,e,c);
            ans+=w;
        }
    }
}
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& edges) {
        vector<vector<int>>e(n),c(n);
        for(auto v:edges){
            e[v[0]].push_back(v[1]);
            e[v[1]].push_back(v[0]);
            c[v[0]].push_back(1);
            c[v[1]].push_back(0);
        }
        ans=0;
        dfs(0,-1,e,c);
        return ans;
    }
};
