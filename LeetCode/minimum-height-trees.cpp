namespace rerooting {
struct statistic;
template <class T = statistic> struct rerooting {
    rerooting(int n_) : n(n_), e(n) {}
    void add_vertex(typename T::vertex s) { a.push_back(s); }
    void add_edge(int u, int v, typename T::edge s) { e[u].emplace_back(v, s);  e[v].emplace_back(u, s);}
    void build_down(int u, int p) {
        for (auto t : e[u]) {
            int v = t.first;
            if (v != p)
                build_down(v, u), down[u] = t.second + down[v] + down[u];
        }
    }
    void build_up(int u, int p) {
        if (p == -1)
            s[u] = down[u];
        vector<typename T::vertex> prefix, suffix;
        for (auto t : e[u]) {
            int v = t.first;
            prefix.push_back(t.second + (v != p ? down[v] : up[u]));
        }
        suffix = prefix;
        for (int i = 1; i < prefix.size(); ++i)
            prefix[i] = prefix[i - 1] + prefix[i];
        for (int i = suffix.size() - 2; i >= 0; --i)
            suffix[i] = suffix[i + 1] + suffix[i];
        for (int i = 0; i < e[u].size(); ++i) {
            int v = e[u][i].first;
            if (v != p) {
                up[v] = a[u];
                if (i)
                    up[v] = up[v] + prefix[i - 1];
                if (i + 1 != e[u].size())
                    up[v] = up[v] + suffix[i + 1];
                s[v] = e[u][i].second + up[v] + down[v];
                build_up(v,u);
            }
        }
    }
    void build() {
        assert(a.size() == n);
        up = down =s= a;
        build_down(0, -1);
        build_up(0, -1);
    }
    int n;
    vector<typename T::vertex> a, up, down, s;
    vector<vector<pair<int, typename T::edge>>> e;
};

struct statistic {
    struct vertex {
        vertex() {}
        friend auto operator+(const vertex &a, const vertex &b) {
            return vertex();
        }
    };
    struct edge {
        edge() {}
        friend auto operator+(const edge &a, const vertex &b) {
            return vertex();
        }
    };
};
struct height {
    struct vertex {
        vertex(int h_ = 0) : h(h_) {}
        friend auto operator+(const vertex &a, const vertex &b) {
            return vertex(max(a.h, b.h));
        }
        int h;
    };
    struct edge {
        friend auto operator+(const edge &a, const vertex &b) {
            return vertex(1 + b.h);
        }
    };
};
} // namespace rerooting
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        rerooting::rerooting<rerooting::height> a(n);
        for(auto t:edges)
            a.add_edge(t[0],t[1],{});
        for(int u=0;u<n;++u)
            a.add_vertex({});
        a.build();
        vector<int>r;
        for(int u=0;u<n;++u)
            if(r.empty()||a.s[u].h<a.s[r[0]].h)
                r={u};
            else if(a.s[u].h==a.s[r[0]].h)
                r.push_back(u);
        return r;
    }
};
