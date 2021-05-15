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
namespace static_tree {
template <class T = int> struct static_tree {
    int n, root, block_size, num_blocks;
    vector<vector<pair<int, T>>> to;
    vector<T> depth;
    vector<int> father, level, size, tour_index, closest_size, block_type;
    vector<pair<int, int>> tour;
    vector<vector<pair<int, int>>> st;
    vector<vector<int>> block_min;
    static_tree(int _n, int _root = 0)
        : n(_n), root(_root), block_size(0), to(n), depth(n), father(n),
          level(n), size(n), tour_index(n) {}
    void add_edge(int u, int v, T w = 1) {
        to[u].emplace_back(v, w), to[v].emplace_back(u, w);
    }
    void build_info(int u, int p, vector<bool> &visited) {
        vector<pair<int, T>> new_to;
        size[u] = 1, father[u] = p, visited[u] = true;
        new_to.reserve(to[u].size());
        for (auto e : to[u]) {
            int v = e.first;
            T w = e.second;
            if (v != p) {
                assert(!visited[v]);
                depth[v] = depth[u] + w, level[v] = level[u] + 1;
                build_info(v, u, visited), new_to.push_back(e),
                    size[u] += size[v];
            }
        }
        to[u] = new_to;
    }
    void build_tour(int u) {
        tour_index[u] = int(tour.size()), tour.emplace_back(u, -1);
        for (int i = 0; i < int(to[u].size()); ++i) {
            int v = to[u][i].first;
            build_tour(v), tour_index[u] = int(tour.size());
            tour.emplace_back(u, i);
        }
    }
    pair<int, int> get_min(const pair<int, int> &a, const pair<int, int> &b) {
        int l_a = level[a.first], l_b = level[b.first];
        if (l_a != l_b)
            return l_a < l_b ? a : b;
        if (a.second < b.second)
            return a;
        return b;
    }
    void build_st() {
        block_size = max(1, int(log2(tour.size()) / 2));
        num_blocks =
            int(tour.size()) / block_size + bool(tour.size() % block_size);
        closest_size.resize(num_blocks + 1, 0);
        for (int i = 2; i <= num_blocks; ++i) {
            closest_size[i] = closest_size[i - 1];
            if ((1 << (closest_size[i] + 1)) <= i)
                ++closest_size[i];
        }
        st = vector<vector<pair<int, int>>>(
            num_blocks, vector<pair<int, int>>(closest_size[num_blocks] + 1));
        for (int h = 0; h <= closest_size[num_blocks]; ++h)
            for (int i = 0; i < num_blocks; ++i) {
                pair<int, int> &t = st[i][h];
                if (!h) {
                    t = tour[i * block_size];
                    for (int j = i * block_size;
                         j < (i + 1) * block_size && j < int(tour.size()); ++j)
                        t = get_min(t, tour[j]);
                } else if (i + (1 << (h - 1)) >= num_blocks)
                    t = st[i][h - 1];
                else
                    t = get_min(st[i][h - 1], st[i + (1 << (h - 1))][h - 1]);
            }
    }
    void build_block() {
        block_type.resize(num_blocks);
        for (int i = 0; i < num_blocks; ++i) {
            int m = 0;
            for (int j = i * block_size + 1; j < (i + 1) * block_size; ++j) {
                m <<= 1;
                if (j < int(tour.size()) &&
                    level[tour[j].first] > level[tour[j - 1].first])
                    ++m;
            }
            block_type[i] = m;
        }
        block_min = vector<vector<int>>(1 << (block_size - 1),
                                        vector<int>(block_size * block_size));
        for (int m = 0; m < (1 << (block_size - 1)); ++m) {
            for (int i = 0; i < block_size; ++i) {
                pair<int, int> t(0, i);
                int v = 0, k = i * block_size;
                block_min[m][k + i] = i;
                for (int j = i + 1; j < block_size; ++j) {
                    if ((m >> (block_size - 1 - j)) & 1)
                        ++v;
                    else
                        --v;
                    if (v < t.first)
                        t = make_pair(v, j);
                    block_min[m][k + j] = t.second;
                }
            }
        }
    }
    void build() {
#ifdef LOCAL
        int m = 0;
        for (int i = 0; i < n; ++i)
            m += int(to[i].size());
        assert(m == 2 * n - 2);
#endif
        vector<bool> visited(n);
        build_info(root, -1, visited);
        assert(*min_element(begin(visited), end(visited)) == 1);
        tour.reserve(2 * n - 1), build_tour(root);
        build_st(), build_block();
    }
    pair<int, int> query_st(int l, int r) {
        int s = closest_size[r - l + 1];
        return get_min(st[l][s], st[r - (1 << s) + 1][s]);
    }
    pair<int, int> query_block(int l, int r) {
        int i = l / block_size, n_l = l % block_size, n_r = r % block_size;
        return tour[i * block_size +
                    block_min[block_type[i]][n_l * block_size + n_r]];
    }
    pair<int, int> rmq(int l, int r) {
        int block_l = l / block_size, block_r = r / block_size;
        pair<int, int> t = tour[l];
        if (block_l == block_r)
            return query_block(l, r);
        t = get_min(t, query_block(l, (block_l + 1) * block_size - 1));
        t = get_min(t, query_block(block_r * block_size, r));
        if (++block_l <= --block_r)
            t = get_min(t, query_st(block_l, block_r));
        return t;
    }
    pair<int, int> _lca(int u, int v) {
        int l = tour_index[u], r = tour_index[v];
        if (l > r)
            swap(l, r);
        return rmq(l, r);
    }
    int lca(int u, int v) { return _lca(u, v).first; }
    T distance(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
    pair<int, T> move_to(int u, int v) {
        assert(u != v);
        pair<int, int> l = _lca(u, v);
        if (u != l.first)
            return make_pair(father[u], depth[u] - depth[father[u]]);
        return to[u][l.second];
    }
};
} // namespace static_tree
// The templates end here.
auto build() {
    int a;
    in(a);
    static_tree::static_tree t(a);
    lp(i, 1, a - 1) {
        int p;
        in(p);
        t.add_edge(p - 1, i);
    }
    t.build();
    return t;
}
int main() {
    fast, prec(12);
    int n;
    in(n);
    auto a = build();
    vi x(n);
    in(x), --x;
    auto b = build();
    vi y(n);
    in(y), --y;
    auto f = vect<int>({inf()}, n + 1, n + 1), g = f;
    f[0][0] = 0;
    lp(i, 0, n - 1) lp(j, 0, i) {
        tmin(f[i + 1][j], f[i][j] + a.level[x[i]] -
                              (i ? a.level[a.lca(x[i], x[i - 1])] : 0));
        tmin(g[i + 1][i], f[i][j] + b.level[y[i]] -
                              (j ? b.level[b.lca(y[i], y[j - 1])] : 0));
        tmin(g[i + 1][j], g[i][j] + b.level[y[i]] -
                              (i ? b.level[b.lca(y[i], y[i - 1])] : 0));
        tmin(f[i + 1][i], g[i][j] + a.level[x[i]] -
                              (j ? a.level[a.lca(x[i], x[j - 1])] : 0));
    }
    int m = inf();
    lp(j, 0, n - 1) tmin(m, f[n][j]), tmin(m, g[n][j]);
    ou(a.n + b.n - 2 - m);
    return 0;
}
