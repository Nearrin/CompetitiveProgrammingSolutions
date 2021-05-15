#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#define lp(i, l, r) for (int i = l; i <= int(r); ++i)
#define rp(i, r, l) for (int i = int(r); i >= l; --i)
#define ls(i, s) for (int i = 0; s[i]; ++i)
#define rs(i, s) for (int i = strlen(s) - 1; i >= 0; --i)
#define lv(i, a) for (int i = 0; i < int(a.size()); ++i)
#define rv(i, a) for (int i = int(a.size()) - 1; i >= 0; --i)
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define prec(a) cout << setprecision(a) << fixed
#define freo freopen
#define many for (int T = -1; T < 0 && cin >> T, T--;)
#define appl(f, a) for (auto i = begin(a); i != end(a); f, ++i)
#define rang(a) begin(a), end(a)
#define tstr(a) to_string(a)
#define gene template <class T>
#define elif else if
#ifndef LOCAL
#define endl '\n'
#define assert
#endif
using namespace std;
using namespace __gnu_pbds;
template <class T = int> T inf() { return numeric_limits<T>::max(); }
gene bool tmin(T &a, T b) { return b < a ? a = b, true : false; }
gene bool tmax(T &a, T b) { return b > a ? a = b, true : false; }
#if __cplusplus >= 201402L
gene auto min(const T &a) { return *min_element(rang(a)); }
gene auto max(const T &a) { return *max_element(rang(a)); }
gene auto sum(const T &a) { return accumulate(rang(a), 0); }
template <class T, int N, class I>
auto gath(const T (&a)[N], const vector<I> &b) {
    vector<T> r;
    for (auto i : b)
        r.push_back(a[i]);
    return r;
}
template <class T, class I> auto gath(const T &a, const vector<I> &b) {
    vector<typename T::value_type> r;
    for (auto i : b)
        r.push_back(a[i]);
    return r;
}
#endif
template <class T, class C = less<typename T::value_type>>
void sort(T &a, C c = C()) {
    sort(rang(a), c);
}
gene void reve(T &a) { reverse(rang(a)); }
gene void uniq(T &a) { sort(a), a.erase(unique(rang(a)), end(a)); }
gene void shuf(T &a) { random_shuffle(rang(a)); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
#if __cplusplus >= 201703L
template <typename... T> void in(T &... a) { ((cin >> a), ...); }
template <typename A, typename... B> void ou(const A &a, const B &... b) {
    cout << a, ((cout << ' ' << b), ...), cout << endl;
}
#endif
template <class F, class S> istream &operator>>(istream &s, pair<F, S> &a) {
    return s >> a.first >> a.second;
}
template <class F, class S>
ostream &operator<<(ostream &s, const pair<F, S> &a) {
    return s << '(' << a.first << ", " << a.second << ')';
}
gene istream &operator>>(istream &s, vector<T> &a) {
    for (int i = -1; i < 0 && (!a.size() && (cin >> i, a.resize(i), 0), i = 0),
             i < int(a.size());)
        s >> a[i++];
    return s;
}
gene ostream &operator<<(ostream &s, const vector<T> &a) {
    lv(i, a) cout << a[i] << (i + 1 == int(a.size()) ? "" : " ");
    return s;
}
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
typedef string str;
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
// Not implemented.
template <class T> struct spfa {};
struct bfs {
    int n, inf;
    vector<vector<int>> to;
    vector<int> distance;
    bfs(int _n)
        : n(_n), inf(numeric_limits<int>::max()), to(n), distance(n, inf) {}
    void add_edge(int u, int v) { to.at(u).push_back(v); }
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
    int n, m;
    in(n, m);
    shortest_path::dijkstras_algorithm<ll> dij(n);
    dij.distance[0] = 0;
    lp(i, 1, m) {
        int u, v, w;
        in(u, v, w);
        dij.add_edge(u - 1, v - 1, w);
        dij.add_edge(v - 1, u - 1, w);
    }
    dij.run();
    if (dij.distance[n - 1] == dij.inf) {
        ou(-1);
    } else {
        vi ans;
        for (int i = n - 1; i != -1; i = dij.parent[i])
            ans.push_back(i + 1);
        reve(ans);
        ou(ans);
    }
    return 0;
}
