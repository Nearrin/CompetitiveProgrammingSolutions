vector<vector<int>>to;
int g_t,g_target;
double g_ans;
void dfs(int u,int p,double prob,int depth){
    int cnt=0;
    for(auto v:to[u])if(v!=p)++cnt;
    for(auto v:to[u])if(v!=p)dfs(v,u,prob/cnt,depth+1);
    if(u==g_target){
        if(g_t<depth)g_ans=0;
        if(g_t==depth)g_ans=prob;
        if(g_t>depth){
            if(cnt==0)g_ans=prob;
            else g_ans=0;
        }
    }
}
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        to.clear();
        to.resize(n+1);
        for(auto e:edges){
            to[e[0]].push_back(e[1]);
            to[e[1]].push_back(e[0]);
        }
        g_t=t;
        g_target=target;
        dfs(1,0,1.0,0);
        return g_ans;
    }
};
