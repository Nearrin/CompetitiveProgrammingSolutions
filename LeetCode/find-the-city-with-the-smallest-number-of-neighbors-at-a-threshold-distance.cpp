template <class T> struct dijkstras_algorithm {
    int n, m;
    vector<vector<int>> to;
    vector<vector<T>> cost;
    T inf;
    vector<pair<T, int>> tree;
    vector<T> distance;
    dijkstras_algorithm(int _n)
        : n(_n), m(1 << (int)ceil(log2(n) + 1e-8)), to(n), cost(n),
          inf(numeric_limits<T>::max()), tree(2 * m, make_pair(inf, 0)),
          distance(n, inf) {}
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
                    modify(v, distance[v]);
            }
    }
};
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        pair<int,int>ans=make_pair(n+1,-1);
        for(int src=0;src<n;++src){
            dijkstras_algorithm<int> dij(n);
            dij.distance[src]=0;
            for(auto e:edges){
                dij.add_edge(e[0],e[1],e[2]);
                dij.add_edge(e[1],e[0],e[2]);
            }
            dij.run();
            int cnt=0;
            for(int i=0;i<n;++i)if(dij.distance[i]<=distanceThreshold)++cnt;
            if(make_pair(cnt,-src)<ans){
                ans=make_pair(cnt,-src);
            }
        }
        return ans.second*-1;
    }
};
