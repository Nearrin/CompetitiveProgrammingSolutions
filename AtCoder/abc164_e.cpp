#ifdef LOCAL
#include <header.hpp>
#else
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#endif
#define lp(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define rp(i, r, l) for (int i = int(r); i >= int(l); --i)
#define ls(i, s) for (int i = 0; s[i]; ++i)
#define rs(i, s) for (int i = strlen(s) - 1; i >= 0; --i)
#define lv(i, a) for (int i = 0; i < int(a.size()); ++i)
#define rv(i, a) for (int i = int(a.size()) - 1; i >= 0; --i)
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define prec(a) cout << setprecision(a) << fixed
#define freo freopen
#define many for (int C = 1, T = -1; T < 0 && cin >> T, C <= T; ++C)
#define goog "Case #" + to_string(C) + ":"
#define appl(x, f, a)                                                          \
    for (auto &x : a)                                                          \
    f
#define rang(a) begin(a), end(a)
#define gene template <class T>
#define elif else if
#define retu return
#define pufr push_front
#define pofr pop_front
#define puba push_back
#define poba pop_back
#define intm modular_arithmetic::integer
#ifdef LOCAL
#define debu(...)                                                              \
    {                                                                          \
        vector<string> S(1);                                                   \
        int A = 0;                                                             \
        for (auto V : #__VA_ARGS__) {                                          \
            if (V == ',' && !A)                                                \
                S.push_back("");                                               \
            elif (S.back().size() || V != ' ') S.back().push_back(V),          \
                A += map<char, int>{{'(', 1}, {')', -1}}[V];                   \
        }                                                                      \
        cout << "\x1b[33mDebugging @ Line " << __LINE__ << ":\x1b[0m\n";       \
        debu_(S.begin(), __VA_ARGS__);                                         \
    }
#else
#define endl '\n'
#undef assert
#define assert
#define debu(...)
#endif
using namespace std;
using namespace __gnu_pbds;
template <class I, class T> void debu_(I i, const T &a) {
    cout << "\x1b[33m    " << *i << " = " << a << "\x1b[0m" << endl;
}
template <class I, class A, class... B>
void debu_(I i, const A &a, const B &... b) {
    cout << "\x1b[33m    " << *i << " = " << a << "\x1b[0m" << endl;
    debu_(++i, b...);
}
gene int bcnt(const T &a) { return __builtin_popcount(a); }
template <> int bcnt(const int64_t &a) { return __builtin_popcountll(a); }
gene int blen(const T &a) { return a ? 1 + blen(a / 2) : 0; }
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
gene T rint(T l, T r) { return uniform_int_distribution<T>(l, r)(rng); }
template <class A, class B> B conv(const A &a, B b = B()) {
    stringstream s;
    s << a, s >> b;
    return b;
}
vector<string> spli(const string &s) {
    vector<string> r;
    for (int i = 0, j; i < int(s.size()); ++i)
        if (s[i] != ' ') {
            r.push_back("");
            for (j = i; j < int(s.size()) && s[j] != ' '; ++j)
                r.back().push_back(s[j]);
            i = j - 1;
        }
    return r;
}
template <class T = int> T inf() { return numeric_limits<T>::max() / 2; }
gene T sign(const T &a) { return a == 0 ? 0 : (a < 0 ? -1 : 1); }
gene T floor(const T &a, const T &b) {
    assert(b != 0);
    return sign(a) * sign(b) > 0 ? abs(a) / abs(b)
                                 : -(abs(a) + abs(b) - 1) / abs(b);
}
gene T ceil(const T &a, const T &b) {
    assert(b != 0);
    return sign(a) * sign(b) > 0 ? (abs(a) + abs(b) - 1) / abs(b)
                                 : -abs(a) / abs(b);
}
gene bool tmin(T &a, T b) { return b < a ? a = b, true : false; }
gene bool tmax(T &a, T b) { return b > a ? a = b, true : false; }
#if __cplusplus > 201103L
gene auto min(const T &a) { return *min_element(rang(a)); }
gene auto max(const T &a) { return *max_element(rang(a)); }
gene auto sum(const T &a) {
    return accumulate(rang(a), (typename T::value_type)0);
}
template <> auto sum(const vector<int> &a) { return accumulate(rang(a), 0ll); }
template <> auto sum(const vector<string> &a) {
    return accumulate(rang(a), string());
}
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
gene void shuf(T &a) { shuffle(rang(a), rng); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
#if __cplusplus > 201103L
gene auto vect(const vector<T> &v, int n) {
    assert(v.size() <= 1);
    return v.size() ? vector<T>(n, v[0]) : vector<T>(n);
}
template <class T, class... D> auto vect(const vector<T> &v, int n, D... m) {
    return vector<decltype(vect(v, m...))>(n, vect(v, m...));
}
#endif
template <class F, class S> pair<F, S> operator-(pair<F, S> a) {
    a.first = -a.first, a.second = -a.second;
    return a;
}
template <class F, class S>
pair<F, S> operator+(pair<F, S> a, const pair<F, S> &b) {
    a.first += b.first, a.second += b.second;
    return a;
}
template <class F, class S>
pair<F, S> operator-(pair<F, S> a, const pair<F, S> &b) {
    a.first -= b.first, a.second -= b.second;
    return a;
}
template <class F, class S>
pair<F, S> operator*(pair<F, S> a, const pair<F, S> &b) {
    a.first *= b.first, a.second *= b.second;
    return a;
}
template <class F, class S>
pair<F, S> operator/(pair<F, S> a, const pair<F, S> &b) {
    a.first /= b.first, a.second /= b.second;
    return a;
}
template <class F, class S, class T>
pair<F, S> operator*=(pair<F, S> a, const T &b) {
    a.first *= b, a.second *= b;
    return a;
}
template <class F, class S, class T>
pair<F, S> operator/=(pair<F, S> a, const T &b) {
    a.first /= b, a.second /= b;
    return a;
}
#if __cplusplus > 201103L
template <class F, class S> struct zip_ {
    zip_(F &f_, S &s_) : f(f_), s(s_) {}
    template <class I, class J> struct iterator {
        iterator(I i_, J j_) : i(i_), j(j_) {}
        auto operator++() {
            ++i, ++j;
            return *this;
        }
        bool operator!=(const iterator &a) const {
            assert((i != a.i && j != a.j) || (i == a.i && j == a.j));
            return i != a.i;
        }
        auto operator*() const { return make_pair(*i, *j); }
        I i;
        J j;
    };
    template <class I, class J> auto iterator_(I i, J j) const {
        return iterator<I, J>(i, j);
    }
    auto begin() const { return iterator_(f.begin(), s.begin()); }
    auto end() const { return iterator_(f.end(), s.end()); }
    F &f;
    S &s;
};
template <class F, class S> auto zip(F &f, S &s) { return zip_<F, S>(f, s); }
#endif
template <class F, class S> istream &operator>>(istream &s, pair<F, S> &a) {
    return s >> a.first >> a.second;
}
template <class F, class S>
ostream &operator<<(ostream &s, const pair<F, S> &a) {
    return s << a.first << " " << a.second;
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
gene T in() {
    T a;
    cin >> a;
    return a;
}
gene void in(T &a) { cin >> a; }
template <class A, class... B> void in(A &a, B &... b) { cin >> a, in(b...); }
void ou() { cout << endl; }
gene void ou(const T &a) { cout << a << endl; }
template <class A, class... B> void ou(const A &a, const B &... b) {
    cout << a << ' ', ou(b...);
}
gene struct hash_safe {};
template <> struct hash_safe<int> {
    size_t operator()(uint64_t a) const {
        static uint64_t d =
            chrono::steady_clock::now().time_since_epoch().count();
        a += d + 0x9e3779b97f4a7c15, a = (a ^ (a >> 30)) * 0xbf58476d1ce4e5b9;
        a = (a ^ (a >> 27)) * 0x94d049bb133111eb;
        return a ^ (a >> 31);
    }
};
template <> struct hash_safe<int64_t> {
    size_t operator()(uint64_t a) const {
        static uint64_t d =
            chrono::steady_clock::now().time_since_epoch().count();
        a += d + 0x9e3779b97f4a7c15, a = (a ^ (a >> 30)) * 0xbf58476d1ce4e5b9;
        a = (a ^ (a >> 27)) * 0x94d049bb133111eb;
        return a ^ (a >> 31);
    }
};
gene using unordered_set_safe = unordered_set<T, hash_safe<T>>;
gene using unordered_multiset_safe = unordered_multiset<T, hash_safe<T>>;
template <class K, class V>
using unordered_map_safe = unordered_map<K, V, hash_safe<K>>;
template <class K, class V>
using unordered_multimap_safe = unordered_multimap<K, V, hash_safe<K>>;
#define unordered_set unordered_set_safe
#define unordered_multiset unordered_multiset_safe
#define unordered_map unordered_map_safe
#define unordered_multimap unordered_multimap_safe
gene using bbst =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
gene using heap = __gnu_pbds::priority_queue<T, greater<T>, pairing_heap_tag>;
typedef int64_t ll;
typedef long double ld;
typedef string str;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pil> vpil;
typedef vector<pli> vpli;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
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
    fast, prec(12);
    int n, m, s;
    in(n, m, s);
    vector<pair<pii, pii>> a(m);
    in(a);
    vpii b(n);
    in(b);
    int max_coin = 0;
    for (auto v : a)
        max_coin += v.second.first;
    auto index = [&](int v, int c) { return v * (max_coin + 1) + c; };
    shortest_path::dijkstras_algorithm<ll> dij(n * (max_coin + 1));
    vvi to(n), aa(n), bb(n);
    for (auto t : a) {
        --t.first.first, --t.first.second;
        to[t.first.first].push_back(t.first.second);
        aa[t.first.first].push_back(t.second.first);
        bb[t.first.first].push_back(t.second.second);
        swap(t.first.first, t.first.second);
        to[t.first.first].push_back(t.first.second);
        aa[t.first.first].push_back(t.second.first);
        bb[t.first.first].push_back(t.second.second);
    }
    lp(u, 0, n - 1) {
        lp(c, 0, max_coin) {
            lv(i, to[u]) {
                int v = to[u][i];
                int thisa = aa[u][i], thisb = bb[u][i];
                if (thisa <= c) {
                    dij.add_edge(index(u, c), index(v, c - thisa), thisb);
                }
            }
            int nc = b[u].first + c;
            tmin(nc, max_coin);
            dij.add_edge(index(u, c), index(u, nc), b[u].second);
        }
    }
    dij.distance[index(0, min(s, max_coin))] = 0;
    dij.run();
    lp(i, 1, n - 1) {
        ll ans = inf<ll>();
        lp(j, 0, max_coin) tmin(ans, dij.distance[index(i, j)]);
        ou(ans);
    }
    return 0;
}
