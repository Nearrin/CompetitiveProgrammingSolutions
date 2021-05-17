class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>> g) {
        int n=g.size();
        decltype(g)h(n);
        queue<int>q;
        for(int u=0;u<n;++u){
            if(g[u].empty())
                q.push(u);
            for(int v:g[u])
                h[v].push_back(u);
        }
        while(q.size()){
            int v=q.front();
            q.pop();
            for(int u:h[v])
                if(g[u].pop_back(),g[u].empty())
                    q.push(u);
        }
        vector<int>a;
        for(int u=0;u<n;++u)
            if(g[u].empty())
                a.push_back(u);
        return a;
    }
};
