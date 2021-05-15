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
#define lm(i, m) for (auto i = m; i; i = (m) & (i - 1))
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
gene int barr(const T &a, const int &i) { return a >> i & 1; }
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
gene vector<T> &operator--(vector<T> &a) {
    for (auto &v : a)
        --v;
    return a;
}
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
namespace cycle {
struct directed_cycle {
    directed_cycle(int _n) : n(_n), to(n) {}
    void add_edge(int u, int v) {
        to[u].push_back(v);
        // ou(u, v);
    }
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
int number_of_nodes;
struct node {
    int index;
    node *l, *r;
    node() {
        index = number_of_nodes++;
        l = r = 0;
    }
};
unordered_map<int, int> leaves;
node *build(int l, int r) {
    node *u = new node;
    if (l == r) {
        leaves[u->index] = l;
        return u;
    }
    int m = (l + r) / 2;
    u->l = build(l, m);
    u->r = build(m + 1, r);
    return u;
}
void build(cycle::directed_cycle &dc, node *u) {
    if (u->l) {
        dc.add_edge(u->index, u->l->index);
        dc.add_edge(u->index, u->r->index);
        build(dc, u->l);
        build(dc, u->r);
    }
}
void link(cycle::directed_cycle &dc, node *u, int l, int r, int ql, int qr,
          int index) {
    if (ql > qr)
        return;
    if (ql <= l && qr >= r) {
        dc.add_edge(index, u->index);
    } else {
        int m = (l + r) / 2;
        if (ql <= m)
            link(dc, u->l, l, m, ql, qr, index);
        if (qr > m)
            link(dc, u->r, m + 1, r, ql, qr, index);
    }
}
void reverse_link(cycle::directed_cycle &dc, node *u, int l, int r, int ql,
                  int qr, int index) {
    if (ql > qr)
        return;
    if (ql <= l && qr >= r) {
        dc.add_edge(u->index, index);
    } else {
        int m = (l + r) / 2;
        if (ql <= m)
            reverse_link(dc, u->l, l, m, ql, qr, index);
        if (qr > m)
            reverse_link(dc, u->r, m + 1, r, ql, qr, index);
    }
}
int main() {
    fast, prec(12);
    int n;
    in(n);
    vector<vector<pii>> s(n + 1);
    lp(i, 1, n) {
        int l, r;
        in(l, r);
        s[l].push_back({r, i});
    }
    vi matching(n + 1);
    number_of_nodes = n;
    auto root = build(1, n);
    set<pii> current;
    lp(i, 1, n) {
        for (auto &j : s[i])
            current.insert(j);
        matching[current.begin()->second] = i;
        current.erase(current.begin());
    }
    cycle::directed_cycle dc(number_of_nodes);
    build(dc, root);
    lp(l, 1, n) {
        for (auto &[r, i] : s[l]) {
            link(dc, root, 1, n, l, matching[i] - 1, i - 1);
            link(dc, root, 1, n, matching[i] + 1, r, i - 1);
            reverse_link(dc, root, 1, n, matching[i], matching[i], i - 1);
        }
    }
    auto stack = dc.run();
    if (stack.size()) {
        ou("NO");
        vi c;
        for (auto u : stack) {
            if (u < n)
                c.push_back(-u - 1);
            elif (leaves.count(u)) c.push_back(leaves[u]);
        }
        auto new_matching = matching;
        matching.erase(matching.begin());
        ou(matching);
        if (c.front() > 0) {
            c.push_back(c.front());
            c.erase(c.begin());
        }
        lv(i, c) {
            if (c[i] < 0) {
                new_matching[-c[i]] = c[i + 1];
            }
        }
        // ou(c);
        new_matching.erase(new_matching.begin());
        ou(new_matching);
    } else {
        ou("YES");
        matching.erase(matching.begin());
        ou(matching);
    }
    return 0;
}
