#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
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
gene int tmax(T &a, T b) { return b < a ? a = b, 1 : 0; }
gene int tmin(T &a, T b) { return b > a ? a = b, 1 : 0; }
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
             i < a.size();)
        s >> a[i++];
    return s;
}
template <class F, class S> auto &operator<<(ostream &s, const pair<F, S> &a) {
    return s << '(' << a.first << ", " << a.second << ')';
}
gene auto &operator<<(ostream &s, const vector<T> &a) {
    lv(i, a) cout << a[i] << (i + 1 == a.size() ? "" : " ");
    return s;
}
namespace shortest_path {
// Not tested.
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
            for (int i = 0; i < to[u].size(); ++i) {
                int v = to[u][i];
                T c = cost[u][i];
                if (update(distance[v], distance[u], c))
                    modify(v, distance[v]);
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
        : n(_n), to(n), inf(numeric_limits<int>::max()), distance(n, inf) {}
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
int main() {
    fast, prec(12);
    vi a;
    cin >> a;
    shortest_path::bfs da0(a.size()), da1(a.size());
    lv(i, a) {
        if (i - a[i] >= 0)
            da0.add_edge(i - a[i], i), da1.add_edge(i - a[i], i);
        if (i + a[i] < a.size())
            da0.add_edge(i + a[i], i), da1.add_edge(i + a[i], i);
        if (a[i] & 1)
            da1.distance[i] = 0;
        else
            da0.distance[i] = 0;
    }
    da0.run();
    da1.run();
    vi ans(a.size());
    lv(i, a) if (a[i] & 1) ans[i] = da0.distance[i];
    else ans[i] = da1.distance[i];
    appl(*i = *i == da0.inf ? -1 : *i, ans);
    cout << ans << endl;
    return 0;
}