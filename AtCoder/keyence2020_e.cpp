#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#define lp(i, l, r) for (int i = l; i <= r; ++i)
#define rp(i, r, l) for (int i = r; i >= l; --i)
#define ls(i, s) for (int i = 0; s[i]; ++i)
#define rs(i, s) for (int i = strlen(s) - 1; i >= 0; --i)
#define lv(i, a) for (int i = 0; i < int(a.size()); ++i)
#define rv(i, a) for (int i = (int)a.size() - 1; i >= 0; --i)
#define in(a) int a = (cin >> a, a)
#define ou(a) cout << a << endl
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define prec(a) cout << setprecision(a) << fixed
#define appl(f, a) for (auto i = begin(a); i != end(a); f, ++i)
#define many for (int T = -1; T < 0 && cin >> T, T--;)
#define rang(a) begin(a), end(a)
#define gene template <class T>
#define endl '\n'
#define asse assert
using namespace std;
using namespace __gnu_pbds;
gene void sort(T &a) { sort(rang(a)); }
gene void reve(T &a) { reverse(rang(a)); }
gene void uniq(T &a) { sort(a), a.erase(unique(rang(a)), end(a)); }
gene void shuf(T &a) { random_shuffle(rang(a)); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
gene auto gath(const T &a, const vector<int> &b) {
    vector<typename T::value_type> r;
    for (auto i : b)
        r.push_back(a[i]);
    return r;
}
gene auto min(const T &a) { return *min_element(rang(a)); }
gene auto max(const T &a) { return *max_element(rang(a)); }
gene auto sum(const T &a) { return accumulate(rang(a), 0); }
gene T inf() { return numeric_limits<T>::max(); }
gene int tmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
gene int tmax(T &a, T b) { return b > a ? a = b, 1 : 0; }
gene using bbst =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
gene using heap = __gnu_pbds::priority_queue<T, greater<T>, pairing_heap_tag>;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
template <class F, class S> auto &operator>>(istream &s, pair<F, S> &a) {
    return s >> a.first >> a.second;
}
gene auto &operator>>(istream &s, vector<T> &a) {
    for (int i = -1; i < 0 && (!a.size() && (cin >> i, a.resize(i), 0), i = 0),
             i < int(a.size());)
        s >> a[i++];
    return s;
}
template <class F, class S> auto &operator<<(ostream &s, const pair<F, S> &a) {
    return s << '(' << a.first << ", " << a.second << ')';
}
gene auto &operator<<(ostream &s, const vector<T> &a) {
    lv(i, a) cout << a[i] << (i + 1 == int(a.size()) ? "" : " ");
    return s;
}
namespace shortest_path {
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
        assert(v >= 0 && v < n);
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
                if (update(distance[v], distance[u], c)) {
                    modify(v, distance[v]);
                }
            }
    }
};
// Not implemented.
template <class T> struct spfa {};
struct bfs {
    int n, inf;
    vector<vector<int>> to;
    vector<int> distance;
    bfs(int _n)
        : n(_n), inf(numeric_limits<int>::max()), to(n), distance(n, inf) {}
    void add_edge(int u, int v) {
        assert(v >= 0 && v < n);
        to.at(u).push_back(v);
    }
    void run() {
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (distance[i] != inf)
                assert(!distance[i]), q.push(i);
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (int v : to[u])
                if (distance[v] == inf)
                    q.push(v), distance[v] = distance[u] + 1;
        }
    }
};
} // namespace shortest_path
vpii d_i;
vi d, w, color;
vvi to, to_same;
vpii edges;
void assign_color(int u) {
    for (auto v : to_same[u]) {
        if (color[v] == 0) {
            color[v] = -color[u];
            assign_color(v);
        }
    }
}
void assign_same_color(int u) {
    for (auto v : to[u]) {
        if (color[v] == 0) {
            color[v] = color[u];
            assign_same_color(v);
        }
    }
}
int main() {
    fast, prec(12);
    int n, m;
    cin >> n >> m;
    d.resize(n);
    to.resize(n);
    to_same.resize(n);
    color.resize(n);
    cin >> d;
    w.resize(m);
    lp(i, 1, m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        if (d[u] != d[v]) {
            w[i - 1] = abs(d[u] - d[v]);
            if (d[u] < d[v])
                to[u].push_back(v);
            else
                to[v].push_back(u);
        } else {
            w[i - 1] = d[u];
            to_same[u].push_back(v);
            to_same[v].push_back(u);
        }
        edges.emplace_back(u, v);
    }
    lv(i, d) d_i.emplace_back(d[i], i);
    sort(d_i);
    reve(d_i);
    while (true) {
        if (d_i.size() == 0)
            break;
        vector<int> fathers;
        while (fathers.empty() ||
               (d_i.size() && d_i.back().first == d[fathers.back()])) {
            fathers.push_back(d_i.back().second);
            d_i.pop_back();
        }
        vi new_fathers;
        for (auto u : fathers) {
            if (color[u] == 0)
                new_fathers.push_back(u);
        }
        fathers = new_fathers;
        if (fathers.size() == 0)
            continue;
        for (auto u : fathers) {
            if (to_same[u].size() == 0) {
                cout << -1 << endl;
                return 0;
            }
            if (color[u] != 0)
                continue;
            int has_free = 0;
            for (auto v : to_same[u])
                if (color[v] == 0)
                    has_free = 1;
            if (has_free == 0) {
                color[u] = -color[to_same[u][0]];
            } else {
                color[u] = 1;
                assign_color(u);
            }
        }
        for (auto u : fathers) {
            assign_same_color(u);
        }
    }
    lv(i, edges) {
        int u = edges[i].first, v = edges[i].second;
        if (color[u] != color[v] && d[u] != d[v])
            w[i] = 1e9;
    }
    lp(i, 0, n - 1) if (color[i] == -1) cout << "B";
    else cout << "W", assert(color[i] == 1);
    cout << endl;
    for (auto v : w)
        cout << v << endl;
    return 0;
    shortest_path::dijkstras_algorithm<ll> sp_w(n), sp_b(n);
    lp(i, 0, m - 1) {
        int u = edges[i].first, v = edges[i].second;
        sp_w.add_edge(u, v, w[i]);
        sp_w.add_edge(v, u, w[i]);
        sp_b.add_edge(u, v, w[i]);
        sp_b.add_edge(v, u, w[i]);
    }
    lp(i, 0, n - 1) if (color[i] == -1) sp_w.distance[i] = 0;
    else sp_b.distance[i] = 0;
    sp_w.run();
    sp_b.run();
    lp(i, 0, n - 1) {
        ll exp_d;
        if (color[i] == -1)
            exp_d = sp_b.distance[i];
        else
            exp_d = sp_w.distance[i];
        if (exp_d != d[i]) {
            cout << vector<ll>{i, exp_d, d[i]} << endl;
            // return 0;
        }
    }
    return 0;
    int target = 2596;
    cout << pii{target, color[target]} << endl;
    lp(i, 0, m - 1) {
        int u = edges[i].first, v = edges[i].second;
        if (u == target || v == target) {
            cout << vi{u, color[u], d[u], v, color[v], d[v], w[i]} << endl;
        }
    }
    // cout << sp_w.distance << endl;
    // cout << sp_b.distance << endl;
    return 0;
}
