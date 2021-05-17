vector<vector<int>>to;
vector<bool> has;
int dfs(int u,int p){
    int t=0;
    for(auto v:to[u])
        if(v!=p){
            t+=dfs(v,u);
            has[u]=has[v]||has[u];
        }
    if(has[u]&&p!=-1)t+=2;
    return t;
}
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        to.clear();
        to.resize(n);
        for(auto t:edges)
            to[t[0]].push_back(t[1]),
            to[t[1]].push_back(t[0]);
        has=hasApple;
        return dfs(0,-1);
    }
};
