namespace topological_sort {
struct topological_sort {
    topological_sort(int _n) : n(_n), d(n), e(n) {}
    void add_edge(int u, int v) {
        e[u].push_back(v);
        ++d[v];
    }
    auto run() {
        queue<int> q;
        vector<int> r;
        for (int u = 0; u < n; ++u)
            if (!d[u])
                q.push(u);
        while (q.size()) {
            int u = q.front();
            q.pop();
            r.push_back(u);
            for (int v : e[u])
                if (!--d[v])
                    q.push(v);
        }
        return r;
    }
    int n;
    vector<int> d;
    vector<vector<int>> e;
};
} // namespace topological_sort
class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        topological_sort::topological_sort g(m+n);
        for(int u=0;u<n;++u)if(group[u]==-1)group[u]=m+u;
        for(int u=0;u<n;++u)for(int v:beforeItems[u]){
            if(group[v]!=group[u])
                g.add_edge(group[v],group[u]);
        }
        auto a=g.run();
        if(a.size()!=m+n)
            return vector<int>();
        vector<vector<int>>group_to_items(m+n);
        for(int u=0;u<n;++u)group_to_items[group[u]].push_back(u);
        vector<int>r;
        for(int i:a){
            unordered_map<int,int>id;
            for(int u:group_to_items[i]){
                int t=id.size();
                id[u]=t;
            }
            topological_sort::topological_sort g(id.size());
            for(int u:group_to_items[i]){
                for(int v:beforeItems[u])if(group[v]==i){
                    g.add_edge(id[v],id[u]);
                }
            }
            auto t=g.run();
            if(t.size()!=id.size())return vector<int>();
            for(int u:t)
                r.push_back(group_to_items[i][u]);
        }
        return r;
    }
};
