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
template <> auto regu(const long long &a) { return a; }
template <> auto regu(const unsigned long long &a) { return (long long)a; }
#endif
template <class T> int barr(const T &a, const int &i) { return a >> i & 1; }
template <class T> int bcnt(const T &a) { return __builtin_popcount(a); }
template <> int bcnt(const long long &a) { return __builtin_popcountll(a); }
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
template <class T> void in(T &a) { cin >> a; }
template <class A, class... B> void in(A &a, B &... b) { cin >> a, in(b...); }
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
namespace cycle {
struct directed_cycle {
    directed_cycle(int _n) : n(_n), to(n) {}
    void add_edge(int u, int v) { to[u].push_back(v); }
    bool dfs(int u, vector<bool> &in_stack, vector<int> &stack,
             vector<bool> &visited) {
        if (!visited[u]) {
            in_stack[u] = visited[u] = 1, stack.push_back(u);
            for (auto v : to[u])
                if (in_stack[v]) {
                    stack.erase(begin(stack),
                                find(begin(stack), end(stack), v));
                    return true;
                } else if (dfs(v, in_stack, stack, visited))
                    return true;
            in_stack[u] = 0, stack.pop_back();
        }
        return false;
    }
    auto run() {
        vector<bool> in_stack(n), visited(n);
        vector<int> stack;
        stack.reserve(n);
        for (int u = 0; u < n; ++u)
            if (dfs(u, in_stack, stack, visited))
                return stack;
        return stack;
    }
    int n;
    vector<vector<int>> to;
};
struct undirected_cycle {
    undirected_cycle(int _n) : n(_n), to(n) {}
    void add_edge(int u, int v) { to[u].push_back(v), to[v].push_back(u); }
    bool dfs(int u, vector<bool> &in_stack, vector<int> &stack,
             vector<bool> &visited) {
        if (!visited[u]) {
            in_stack[u] = visited[u] = 1, stack.push_back(u);
            for (auto v : to[u])
                if (in_stack[v] && v != stack[stack.size() - 2]) {
                    stack.erase(begin(stack),
                                find(begin(stack), end(stack), v));
                    return true;
                } else if (dfs(v, in_stack, stack, visited))
                    return true;
            in_stack[u] = 0, stack.pop_back();
        }
        return false;
    }
    auto run() {
        vector<bool> in_stack(n), visited(n);
        vector<int> stack;
        stack.reserve(n);
        for (int u = 0; u < n; ++u)
            if (dfs(u, in_stack, stack, visited))
                return stack;
        return stack;
    }
    int n;
    vector<vector<int>> to;
};
struct shortest_cycle {
    vector<vector<int>> to;
    vector<bool> visited, edge_visited;
    vector<int> depth;
    vector<int> edges;
    shortest_cycle(int n) : to(n), visited(n), depth(n) {}
    void add_edge(int u, int v) {
        to.at(u).push_back(int(edges.size()));
        to.at(v).push_back(int(edges.size()) + 1);
        edges.push_back(v), edges.push_back(u);
        // ou(u, v);
    }
    int run_single(int s) {
        edge_visited.resize(edges.size());
        fill(begin(edge_visited), end(edge_visited), false);
        fill(begin(visited), end(visited), false);
        depth[s] = 0;
        queue<int> q;
        q.push(s), visited[s] = true;
        int l = numeric_limits<int>::max();
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (int i : to[u]) {
                int v = edges[i];
                if (!visited[v]) {
                    edge_visited[i ^ 1] = visited[v] = true;
                    q.push(v), depth[v] = depth[u] + 1;
                } else if (!edge_visited[i])
                    l = min(l, depth[v] + depth[u] + 1);
            }
        }
        return l;
    }
    int run() {
        int l = numeric_limits<int>::max();
        for (int s = 0; s < int(to.size()); ++s)
            l = min(l, run_single(s));
        return l;
    }
};
} // namespace cycle
// The templates end here.
int main() {
    ios::sync_with_stdio(0);
    cout << setprecision(16) << fixed;
    cin.tie(0);
    vvi cnt(63);
    int n;
    in(n);
    vl a(n);
    in(a);
    cycle::shortest_cycle sc(n);
    lv(i, a) {
        ll v = a[i];
        vi t;
        lp(i, 0, 62) if (barr(v, i)) t.push_back(i);
        for (int x : t) {
            cnt[x].push_back(i);
        }
    }
    for (auto t : cnt)
        if (t.size() >= 3) {
            ou(3);
            return 0;
        }
    set<pii> sss;
    for (auto t : cnt) {
        for (auto x : t)
            for (auto y : t)
                if (x < y && !sss.count({x, y}))
                    sc.add_edge(x, y), sss.insert({x, y});
    }
    int t = sc.run();
    if (t == numeric_limits<int>::max())
        t = -1;
    ou(t);
    return 0;
}
