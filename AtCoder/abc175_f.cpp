#ifdef LOCAL
#include <header.hpp>
#else
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#endif
#define lp(i, l, r) for (auto i = regu(l); i <= decltype(i)(r); ++i)
#define rp(i, r, l) for (auto i = regu(r); i >= decltype(i)(l); --i)
#define lv(i, a) for (int i = 0; i < int(a.size()); ++i)
#define rv(i, a) for (int i = int(a.size()) - 1; i >= 0; --i)
#define lm(i, m) for (auto i = m; i; i = (m) & (i - 1))
#define many for (int C = 1, T = -1; T < 0 && cin >> T, C <= T; ++C)
#define goog "Case #" + to_string(C) + ":"
#define rang(a) begin(a), end(a)
#define elif else if
#ifndef LOCAL
#define endl '\n'
#undef assert
#define assert
#endif
using namespace std;
using namespace __gnu_pbds;
const auto eps = 1e-8, pi = acos(-1);
template <class T> int comp(const T &a, const T &b) {
    return a < b - eps ? -1 : (a > b + eps);
}
#if __cplusplus > 201103L
template <class T> auto regu(const T &a) { return int(a); }
template <> auto regu(const int64_t &a) { return a; }
template <> auto regu(const uint64_t &a) { return int64_t(a); }
#else
template <class T> int64_t regu(const T &a) { return int(a); }
template <> int64_t regu(const int64_t &a) { return a; }
template <> int64_t regu(const uint64_t &a) { return a; }
#endif
template <class T> int barr(const T &a, const int &i) {
    return int(a >> i & 1);
}
template <class T> int bcnt(const T &a) { return __builtin_popcount(a); }
template <> int bcnt(const int64_t &a) { return __builtin_popcountll(a); }
template <class T> int blen(const T &a) { return a ? 1 + blen(a / 2) : 0; }
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T> T rint(T l, T r) {
    return uniform_int_distribution<T>(l, r)(rng);
}
template <class A, class B> B conv(const A &a, B b = B()) {
    stringstream s;
    s << a, s >> b;
    return b;
}
template <class T = int> T inf() { return numeric_limits<T>::max() / 2; }
template <class T> T sign(const T &a) { return a == 0 ? 0 : (a < 0 ? -1 : 1); }
template <class T> T floor(const T &a, const T &b) {
    assert(b != 0);
    return sign(a) * sign(b) > 0 ? abs(a) / abs(b)
                                 : -(abs(a) + abs(b) - 1) / abs(b);
}
template <class T> T ceil(const T &a, const T &b) {
    assert(b != 0);
    return sign(a) * sign(b) > 0 ? (abs(a) + abs(b) - 1) / abs(b)
                                 : -abs(a) / abs(b);
}
template <class T> bool tmin(T &a, T b) { return b < a ? a = b, true : false; }
template <class T> bool tmax(T &a, T b) { return b > a ? a = b, true : false; }
#if __cplusplus > 201103L
template <class T> auto min(const T &a) { return *min_element(rang(a)); }
template <class T> auto max(const T &a) { return *max_element(rang(a)); }
template <class T> auto sum(const T &a) {
    return accumulate(rang(a), (typename T::value_type)0);
}
template <> auto sum(const vector<int> &a) { return accumulate(rang(a), 0ll); }
template <> auto sum(const vector<string> &a) {
    return accumulate(rang(a), string());
}
template <class C, class V> auto find(C &c, const V &v) {
    return find(rang(c), v);
}
template <class C, class V> auto find(const C &c, const V &v) {
    return find(rang(c), v);
}
#endif
template <class T, class C = less<typename T::value_type>>
void sort(T &a, C c = C()) {
    sort(rang(a), c);
}
template <class T> void reve(T &a) { reverse(rang(a)); }
template <class T> void uniq(T &a) {
    sort(a), a.erase(unique(rang(a)), end(a));
}
template <class T> void shuf(T &a) { shuffle(rang(a), rng); }
template <class T> void merg(T l, T m, T r) { inplace_merge(l, m, r); }
#if __cplusplus > 201103L
template <class T> auto vect(const T &v, int n) { return vector<T>(n, v); }
template <class T, class... D> auto vect(const T &v, int n, D... m) {
    return vector<decltype(vect(v, m...))>(n, vect(v, m...));
}
#endif
template <class F, class S> istream &operator>>(istream &s, pair<F, S> &a) {
    return s >> a.first >> a.second;
}
template <class F, class S>
ostream &operator<<(ostream &s, const pair<F, S> &a) {
    return s << a.first << " " << a.second;
}
template <class T> istream &operator>>(istream &s, vector<T> &a) {
    for (int i = -1; i < 0 && (!a.size() && (cin >> i, a.resize(i), 0), i = 0),
             i < int(a.size());)
        s >> a[i++];
    return s;
}
template <class T> ostream &operator<<(ostream &s, const vector<T> &a) {
    lv(i, a) cout << a[i] << (i + 1 == int(a.size()) ? "" : " ");
    return s;
}
template <class T> T in() {
    T a;
    cin >> a;
    return a;
}
template <class T> istream &in(T &a) { return cin >> a; }
template <class A, class... B> istream &in(A &a, B &... b) {
    return cin >> a, in(b...);
}
void ou() { cout << endl; }
template <class T> void ou(const T &a) { cout << a << endl; }
template <class A, class... B> void ou(const A &a, const B &... b) {
    cout << a << ' ', ou(b...);
}
bool yep(const bool &a) { return ou(a ? "yes" : "no"), a; }
bool Yep(const bool &a) { return ou(a ? "Yes" : "No"), a; }
bool YEP(const bool &a) { return ou(a ? "YES" : "NO"), a; }
template <class T> struct hash_safe {};
template <> struct hash_safe<int> {
    size_t operator()(unsigned long long a) const {
        static unsigned long long d =
            chrono::steady_clock::now().time_since_epoch().count();
        a += d + 0x9e3779b97f4a7c15, a = (a ^ (a >> 30)) * 0xbf58476d1ce4e5b9;
        a = (a ^ (a >> 27)) * 0x94d049bb133111eb;
        return a ^ (a >> 31);
    }
};
template <> struct hash_safe<long long> {
    size_t operator()(unsigned long long a) const {
        return hash_safe<int>()(a);
    }
};
template <class A, class B> struct hash_safe<pair<A, B>> {
    size_t operator()(pair<A, B> a) const {
        auto h = hash_safe<A>()(a.first), g = hash_safe<B>()(a.second);
        return (h >> 16 << 16) + (g >> 16);
    }
};
template <class T> using unordered_set_safe = unordered_set<T, hash_safe<T>>;
template <class T>
using unordered_multiset_safe = unordered_multiset<T, hash_safe<T>>;
template <class K, class V>
using unordered_map_safe = unordered_map<K, V, hash_safe<K>>;
template <class K, class V>
using unordered_multimap_safe = unordered_multimap<K, V, hash_safe<K>>;
#define unordered_set unordered_set_safe
#define unordered_multiset unordered_multiset_safe
#define unordered_map unordered_map_safe
#define unordered_multimap unordered_multimap_safe
template <class T, class C = less<T>>
using bbst =
    tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;
template <class T, class C = greater<T>>
using heap = __gnu_pbds::priority_queue<T, C, pairing_heap_tag>;
using ll = long long;
using ld = long double;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vvi = vector<vi>;
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
        to[u].push_back(v), cost[u].push_back(w);
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
    void add_edge(int u, int v) { to[u].push_back(v); }
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
// Not tested.
struct zero_one_bfs {
    int n, inf;
    vector<vector<int>> to, cost;
    vector<int> distance;
    zero_one_bfs(int _n)
        : n(_n), inf(numeric_limits<int>::max()), to(n), distance(n, inf) {}
    void add_edge(int u, int v, int w) {
        assert(w >= 0 && w < 2);
        to[u].push_back(v), cost[u].push_back(w);
    }
    void run() {
        deque<int> q;
        for (int i = 0; i < n; ++i)
            if (distance[i] != inf)
                assert(!distance[i]), q.push_back(i);
        while (q.size()) {
            int u = q.front();
            q.pop_front();
            for (int i = 0; i < int(to[u].size()); ++i) {
                int v = to[u][i], w = cost[u][i];
                if (distance[v] > distance[u] + w) {
                    distance[v] = distance[u] + w;
                    if (w)
                        q.push_back(v);
                    else
                        q.push_front(v);
                }
            }
        }
    }
};
} // namespace shortest_path
// The templates end here.
int main() {
    ios::sync_with_stdio(0);
    cout << setprecision(16) << fixed;
    cin.tie(0);
    int n;
    in(n);
    vector<str> a(n);
    vi cost(n);
    lv(i, a) in(a[i], cost[i]);
    auto prefix_id = [&](int i, int j) { return i * 100 + j * 2; };
    auto suffix_id = [&](int i, int j) { return i * 100 + j * 2 + 1; };
    int dest_id = n * 100;
    shortest_path::dijkstras_algorithm<int> f(dest_id + 1);
    lv(i, a) lp(j, -1, a[i].size() - 1) {
        int fail = 0;
        vi u, v;
        lv(k, a[i]) if (k <= j) u.push_back(k);
        else v.push_back(k);
        while (u.size() && v.size()) {
            if (a[i][u.back()] != a[i][v.front()]) {
                fail = 1;
            }
            u.pop_back();
            v.erase(v.begin());
        }
        if (fail)
            continue;
        if (v.empty() && u.empty()) {
            tmin(f.distance[dest_id], cost[i]);
        }
        elif (v.empty()) { tmin(f.distance[prefix_id(i, u.back())], cost[i]); }
        else {
            tmin(f.distance[suffix_id(i, v.front())], cost[i]);
        }
    }
    lv(i, a) {
        lp(j, 0, a[i].size() - 1) {
            int fail = 0;
            vi u, v;
            lv(k, a[i]) if (k < j) u.push_back(k);
            elif (k > j) v.push_back(k);
            while (u.size() && v.size()) {
                if (a[i][u.back()] != a[i][v.front()]) {
                    fail = 1;
                }
                u.pop_back();
                v.erase(v.begin());
            }
            if (fail)
                continue;
            if (v.empty() && u.empty()) {
                tmin(f.distance[dest_id], cost[i]);
            }
            elif (v.empty()) {
                tmin(f.distance[prefix_id(i, u.back())], cost[i]);
            }
            else {
                tmin(f.distance[suffix_id(i, v.front())], cost[i]);
            }
        }
    }
    lv(i, a) lv(j, a[i]) {
        lv(ni, a) {
            vi u, v;
            lv(k, a[i]) if (k <= j) u.push_back(k);
            lv(k, a[ni]) v.push_back(k);
            int fail = 0;
            while (u.size() && v.size()) {
                if (a[i][u.back()] != a[ni][v.front()]) {
                    fail = 1;
                }
                u.pop_back();
                v.erase(v.begin());
            }
            if (fail)
                continue;
            if (v.empty() && u.empty()) {
                f.add_edge(prefix_id(i, j), dest_id, cost[ni]);
            }
            elif (v.empty()) {
                f.add_edge(prefix_id(i, j), prefix_id(i, u.back()), cost[ni]);
            }
            else {
                f.add_edge(prefix_id(i, j), suffix_id(ni, v.front()), cost[ni]);
            }
        }
    }
    lv(i, a) lv(j, a[i]) {
        lv(ni, a) {
            vi u, v;
            lv(k, a[i]) if (k >= j) v.push_back(k);
            lv(k, a[ni]) u.push_back(k);
            int fail = 0;
            while (u.size() && v.size()) {
                if (a[ni][u.back()] != a[i][v.front()]) {
                    fail = 1;
                }
                u.pop_back();
                v.erase(v.begin());
            }
            if (fail)
                continue;
            if (v.empty() && u.empty()) {
                f.add_edge(prefix_id(i, j), dest_id, cost[ni]);
            }
            elif (v.empty()) {
                f.add_edge(prefix_id(i, j), prefix_id(ni, u.back()), cost[ni]);
            }
            else {
                f.add_edge(prefix_id(i, j), suffix_id(i, v.front()), cost[ni]);
            }
        }
    }
    f.run();
    ou(f.distance[dest_id] == f.inf ? -1 : f.distance[dest_id]);
    return 0;
}
