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
template <class T, class C = less<typename T::value_type>>
void sort(T &a, C c = C()) {
    sort(rang(a), c);
}
gene void reve(T &a) { reverse(rang(a)); }
gene void uniq(T &a) { sort(a), a.erase(unique(rang(a)), end(a)); }
gene void shuf(T &a) { shuffle(rang(a), rng); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
gene auto vect(const vector<T> &v, int n) {
    assert(v.size() <= 1);
    return v.size() ? vector<T>(n, v[0]) : vector<T>(n);
}
template <class T, class... D> auto vect(const vector<T> &v, int n, D... m) {
    return vector<decltype(vect(v, m...))>(n, vect(v, m...));
}
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
namespace centroid_decomposition {
struct centroid_decomposition {
    centroid_decomposition(int n_)
        : n(n_), size(n), max_size(n), parent(n), in_left(n), to(n) {}
    void add_edge(int u, int v) { to[u].push_back(v), to[v].push_back(u); }
    void dfs(int u, int p) {
        size[u] = 1, max_size[u] = 0, parent[u] = p;
        for (auto v : to[u])
            if (v != p) {
                dfs(v, u), size[u] += size[v];
                max_size[u] = max(max_size[u], size[v]);
            }
    }
    void partition(int u, int p, int d, vector<int> &left, vector<int> &right) {
        if (d <= 0)
            left.push_back(u);
        if (d >= 0)
            right.push_back(u);
        if (d == -1)
            in_left[u] = true;
        for (auto v : to[u])
            if (v != p)
                partition(v, u, d ? d : (in_left[v] ? -1 : 1), left, right);
    }
    /*
    Subtree with a single node will never be called because we cannot make sure
    that each node will be called once and there is no meaning visiting single
    nodes in this way. Please handle them yourself. In order to process each
    path only once, you should only consider paths strictly cross the root in
    solve unless a subtree with two nodes are called then you have to process
    this single path.
    */
    template <class T> void run(const vector<int> &nodes, T solve) {
        if (nodes.size() == 1)
            return;
        if (nodes.size() == 2) {
            for (auto u : nodes)
                in_left[u] = false;
            solve(nodes, to, nodes[0], in_left);
            return;
        }
        dfs(nodes[0], -1);
        int root = nodes[0];
        for (auto u : nodes) {
            max_size[u] = max(max_size[u], int(nodes.size() - size[u]));
            if (max_size[u] < max_size[root])
                root = u;
            in_left[u] = false;
        }
        int max_size_child = to[root][0], left_size = 0;
        for (auto v : to[root]) {
            if (left_size + size[v] <= int(nodes.size() / 2))
                left_size += size[v], in_left[v] = true;
            if (size[v] > size[max_size_child])
                max_size_child = v;
        }
        if (parent[root] != -1 && n - size[root] > size[max_size_child])
            max_size_child = parent[root];
        if (left_size < (max_size_child == parent[root]
                             ? n - size[root]
                             : size[max_size_child])) {
            for (auto u : nodes)
                in_left[u] = false;
            in_left[max_size_child] = true;
        }
        vector<int> left, right;
        left.reserve(nodes.size()), right.reserve(nodes.size());
        partition(root, -1, 0, left, right);
        solve(nodes, to, root, in_left);
        vector<int> old = to[root], right_edges;
        right_edges.reserve(old.size()), to[root].clear();
        for (auto v : old)
            if (in_left[v])
                to[root].push_back(v);
            else
                right_edges.push_back(v);
        run(left, solve), to[root] = right_edges;
        run(right, solve), to[root] = old;
    }
    template <class T> void run(T solve) {
        vector<int> nodes(n);
        for (int i = 0; i < n; ++i)
            nodes[i] = i;
        run(nodes, solve);
    }
    int n;
    vector<int> size, max_size, parent;
    vector<bool> in_left;
    vector<vector<int>> to;
};
} // namespace centroid_decomposition
// The templates end here.
int n;
vi c;
vl ans;
vi vcnt;
int dfs(int u, int p, const vvi &to, const vector<bool> &in_left,
        unordered_map<int, ll> &cnt, int dir) {
    // ou(u, p);
    int siz = 1;
    ++vcnt[c[u]];
    for (auto v : to[u])
        if (v != p)
            if ((!dir && in_left[v]) || (dir && !in_left[v])) {
                int tsiz = dfs(v, u, to, in_left, cnt, dir);
                siz += tsiz;
            }
    if (vcnt[c[u]] == 1) {
        cnt[c[u]] += siz;
    }
    --vcnt[c[u]];
    return siz;
}
void solve(const vi &nodes, const vvi &to, int root,
           const vector<bool> &in_left) {
    // ou("solve", nodes);
    if (nodes.size() <= 2) {
        int p = -1;
        for (auto u : nodes) {
            if (c[u] == p)
                continue;
            ++ans[c[u]];
            p = c[u];
        }
        return;
    }
    unordered_map<int, ll> cl, cr;
    int t1 = dfs(root, -1, to, in_left, cl, 0);
    int t2 = dfs(root, -1, to, in_left, cr, 1);
    cl[c[root]] -= 1;
    cr[c[root]] -= 1;
    --t1, --t2;
    for (auto &tmp : cl) {
        ans[tmp.first] += tmp.second * t2;
    }
    for (auto &tmp : cr) {
        ans[tmp.first] += tmp.second * t1;
        ans[tmp.first] -= tmp.second * cl[tmp.first];
    }
    // ou(ans);
}
int main() {
    fast, prec(12);
    in(n);
    c.resize(n);
    in(c);
    ans.resize(n);
    for (auto &t : c) {
        --t;
        ans[t]++;
    }
    centroid_decomposition::centroid_decomposition cd(n);
    lp(i, 2, n) {
        int u, v;
        in(u, v);
        --u, --v;
        cd.add_edge(u, v);
    }
    vcnt.resize(n);
    cd.run(solve);
    lp(i, 0, n - 1) ou(ans[i]);
    return 0;
}
