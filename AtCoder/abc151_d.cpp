#include <bits/stdc++.h>
#define lp(i, l, r) for (int i = l; i <= r; ++i)
#define rp(i, r, l) for (int i = r; i >= l; --i)
#define ls(i, s) for (int i = 0; s[i]; ++i)
#define rs(i, s) for (int i = strlen(s) - 1; i >= 0; --i)
#define lv(i, a) for (int i = 0; i < a.size(); ++i)
#define rv(i, a) for (int i = (int)a.size() - 1; i >= 0; --i)
#define in(a) int a = (cin >> a, a)
#define ou(a) cout << a << endl
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define prec(a) cout << setprecision(a) << fixed
#define many for (int T = -1; T < 0 && cin >> T, T--;)
#define rang(a) a.begin(), a.end()
#define gene template <class T>
#pragma GCC optimize("O3")
using namespace std;
gene void sort(vector<T> &a) { sort(rang(a)); }
gene void reve(vector<T> &a) { reverse(rang(a)); }
gene T min(const vector<T> &a) { return *min_element(rang(a)); }
gene T max(const vector<T> &a) { return *max_element(rang(a)); }
gene T sum(const vector<T> &a) { return accumulate(rang(a), 0); }
gene T inf() { return numeric_limits<T>::max(); }
gene int updl(T &a, T b) { return b < a ? a = b, 1 : 0; }
gene int updg(T &a, T b) { return b > a ? a = b, 1 : 0; }
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
gene auto &operator>>(istream &s, pair<T, T> &a) {
    return s >> a.first >> a.second;
}
gene auto &operator>>(istream &s, vector<T> &a) {
    for (int i = -1; i < 0 && (!a.size() && (cin >> i, a.resize(i), 0), i = 0),
             i<a.size(); s>> a[i++])
        ;
    return s;
}
gene auto &operator<<(ostream &s, const pair<T, T> &a) {
    return s << '(' << a.first << ", " << a.second << ')';
}
gene auto &operator<<(ostream &s, const vector<T> &a) {
    lv(i, a) cout << a[i] << (i + 1 == a.size() ? "" : " ");
    return s;
}
namespace bfs_forest {
struct bfs_forest {
    vector<vector<int>> to;
    vector<bool> visited;
    vector<int> depth, component;
    int component_number;
    bfs_forest(int n)
        : to(n), visited(n), depth(n), component(n), component_number(0) {}
    void add_edge(int u, int v) { to[u].push_back(v), to[v].push_back(u); }
    void bfs_single(int s) {
        if (!visited[s]) {
            queue<int> q;
            q.push(s), visited[s] = true, ++component_number;
            while (q.size()) {
                int u = q.front();
                q.pop();
                for (int v : to[u])
                    if (!visited[v])
                        visited[v] = true, q.push(v), depth[v] = depth[u] + 1,
                        component[v] = component_number;
            }
        }
    }
    void bfs_all() {
        for (int s = 0; s < to.size(); ++s)
            bfs_single(s);
    }
};
} // namespace bfs_forest
namespace grid_graph {
auto convert(int x, int y, int n, int m, bool from_zero_indexed,
             bool to_zero_indexed) {
    return (x - !from_zero_indexed) * m + y + from_zero_indexed -
           to_zero_indexed;
}
auto convert(int i, int n, int m, bool from_zero_indexed,
             bool to_zero_indexed) {
    if (from_zero_indexed)
        return make_pair(i / m + !to_zero_indexed, i % m + !to_zero_indexed);
    return make_pair((i - 1) / m + 1 - to_zero_indexed,
                     (i - 1) % m + 1 - to_zero_indexed);
}
auto valid(int x, int y, int n, int m, bool zero_indexed) {
    if (zero_indexed)
        return x >= 0 && x < n && y >= 0 && y < m;
    return x > 0 && x <= n && y > 0 && y <= m;
}
template <class T> auto at(const T &a, const pair<int, int> &p) {
    return a[p.first][p.second];
}
auto neighbours(int x, int y, int n, int m, bool zero_indexed,
                int connectivity) {
    static int d_4[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}},
               d_8[8][2] = {{-1, 0}, {1, 0},  {0, 1}, {0, -1},
                            {-1, 1}, {1, -1}, {1, 1}, {-1, -1}};
    auto d = connectivity == 4 ? d_4 : d_8;
    vector<pair<int, int>> r;
    for (int i = 0; i < connectivity; ++i)
        if (valid(x + d[i][0], y + d[i][1], n, m, zero_indexed))
            r.push_back(make_pair(x + d[i][0], y + d[i][1]));
    return r;
}
} // namespace grid_graph
int main() {
    fast, prec(12);
    in(n);
    in(m);
    vector<string> a(n);
    cin >> a;
    int ans = 0;
    lp(x, 0, n - 1) lp(y, 0, m - 1) {
        bfs_forest::bfs_forest f(n * m);
        lp(i, 0, n - 1) lp(j, 0, m - 1) for (auto v : grid_graph::neighbours(
                                                 i, j, n, m, 1, 4)) {
            if (a[i][j] == '.' && grid_graph::at(a, v) == '.') {
                f.add_edge(i * m + j, v.first * m + v.second);
            }
        }
        f.bfs_single(x * m + y);
        lp(k, 0, n * m - 1) if (f.visited[k]) updg(ans, f.depth[k]);
    }
    ou(ans);
    return 0;
}
