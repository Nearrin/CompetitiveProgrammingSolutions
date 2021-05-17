#include <bits/stdc++.h>
using namespace std;
namespace tree_diameter {
struct tree_diameter {
    int n;
    vector<vector<int>> to;
    vector<bool> visited;
    vector<int> depth, component;
    int component_number;
    tree_diameter(int _n)
        : n(_n), to(n), visited(n), depth(n), component(n),
          component_number(0) {
        assert(n);
    }
    void add_edge(int u, int v) {
        to.at(u).push_back(v), to.at(v).push_back(u);
    }
    void bfs(int s) {
        if (!visited[s]) {
            queue<int> q;
            q.push(s), depth[s] = 0, visited[s] = true,
                       component[s] = component_number++;
            while (q.size()) {
                int u = q.front();
                q.pop();
                for (int v : to[u])
                    if (!visited[v])
                        visited[v] = true, q.push(v), depth[v] = depth[u] + 1,
                        component[v] = component_number - 1;
            }
        }
    }
    auto run() {
        for (int s = 0; s < n; ++s)
            bfs(s);
        vector<pair<int, int>> t(component_number, {-1, -1});
        for (int i = 0; i < n; ++i)
            t[component[i]] = max(t[component[i]], {depth[i], i});
        fill(begin(visited), end(visited), 0);
        component_number = 0;
        pair<int, pair<int, int>> result{-1, {-1, -1}};
        for (auto [d, u] : t)
            bfs(u);
        for (int i = 0; i < n; ++i)
            result = max(result, {depth[i], {i, t[component[i]].second}});
        return result;
    }
};
} // namespace tree_diameter
class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        tree_diameter::tree_diameter td(edges.size()+1);
        for(auto t:edges){
            td.add_edge(t[0],t[1]);
        }
        return td.run().first;
    }
};
