namespace shortest_path {
template <class T> struct dijkstras_algorithm {
    int n, m;
    vector<vector<int>> to;
    vector<vector<T>> cost;
    T inf;
    vector<pair<T, int>> tree;
    vector<T> distance;
    vector<int> parent;
    dijkstras_algorithm(int _n)
        : n(_n), m(1 << (int)ceil(log2(n) + 1e-8)), to(n), cost(n),
          inf(numeric_limits<T>::max()), tree(2 * m, make_pair(inf, 0)),
          distance(n, inf), parent(n, -1) {}
    void add_edge(int u, int v, T w) {
        to.at(u).push_back(v);
        cost.at(u).push_back(w);
    }
    int update(T &a, T b, T c) {
        if (b != inf && c != inf && b + c < a) {
            a = b + c;
            return 1;
        }
        return 0;
    }
    void modify(int u, T d) {
        for (tree[u + m] = make_pair(d, u), u = (u + m) >> 1; u; u >>= 1)
            tree[u] = min(tree[u << 1], tree[u << 1 ^ 1]);
    }
    void run() {
        for (int i = 0; i < n; ++i)
            tree[i + m] = make_pair(distance[i], i);
        for (int i = m - 1; i >= 1; --i)
            tree[i] = min(tree[i << 1], tree[i << 1 ^ 1]);
        for (int u = tree[1].second;
             tree[1].first != inf ? (modify(u, inf), 1) : 0; u = tree[1].second)
            for (int i = 0; i < int(to[u].size()); ++i) {
                int v = to[u][i];
                T c = cost[u][i];
                if (update(distance[v], distance[u], c))
                    modify(v, distance[v]), parent[v] = u;
            }
    }
};
}
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        shortest_path::dijkstras_algorithm<int>dij(n*m);
        dij.distance[0]=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                static int d[4][2] = {{0, 1}, {0,-1}, {1, 0}, {-1, 0}};
                for(int k=0;k<4;++k){
                    int ni=i+d[k][0];
                    int nj=j+d[k][1];
                    if(ni>=0&&ni<n&&nj>=0&&nj<m){
                        dij.add_edge(m*i+j,m*ni+nj,k+1!=grid[i][j]);
                    }
                }                
            }
        }
        dij.run();
        return dij.distance[n*m-1];
    }
};
