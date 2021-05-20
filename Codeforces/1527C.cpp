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
template <class T, class C> void sork(T &a, C c) {
    sort(a, [&](const typename T::value_type &x,
                const typename T::value_type &y) { return c(x) < c(y); });
}
template <class T> void reve(T &a) { reverse(rang(a)); }
template <class T> void uniq(T &a) {
    sort(a), a.erase(unique(rang(a)), end(a));
}
template <class T> void shuf(T &a) { shuffle(rang(a), rng); }
template <class T> void merg(T l, T m, T r) { inplace_merge(l, m, r); }
#if __cplusplus > 201103L
namespace lru_cache {
template <class F> struct dense_ {
    dense_(F function) : f(function) {}
    template <class V> auto build(int i) const {
        assert(i == l.size());
        return numeric_limits<V>::min();
    }
    template <class V, class T, class... K>
    auto build(int i, const T &t, const K &...k) const {
        auto u = build<V, K...>(i + 1, k...);
        return vector<decltype(u)>(l[i], u);
    }
    template <class M, class V> V &find(M &m) const { return m; }
    template <class M, class V, class T, class... K>
    V &find(M &m, const T &t, const K &...k) const {
        if (t < m.size())
            return find<decltype(m[t]), V, K...>(m[t], k...);
        return find<decltype(m[t]), V, K...>(m[e = false], k...);
    }
    template <class... K> auto operator()(const K &...k) const {
        typedef decltype(f(*this, k...)) V;
        typedef decltype(build<V, K...>(0, k...)) M;
        if (c) {
            if (p)
                delete (M *)p, p = 0;
            c = false;
        }
        if (!p)
            p = new M(move(build<V, K...>(0, k...)));
        e = true;
        auto &t = find<M, V, K...>(*((M *)p), k...);
        return e ? (t == numeric_limits<V>::min() ? t = f(*this, k...) : t)
                 : f(*this, k...);
    }
    F f;
    static vector<int> l;
    static void *p;
    static bool c, e;
};
template <class F> vector<int> dense_<F>::l;
template <class F> void *dense_<F>::p = 0;
template <class F> bool dense_<F>::c = false;
template <class F> bool dense_<F>::e = false;
template <class F> struct sparse_ {
    sparse_(F function) : f(function) {}
    template <class V> auto build() const { return V(); }
    template <class V, class T, class... K>
    auto build(const T &t, const K &...k) const {
        return unordered_map<T, decltype(build<V, K...>(k...))>();
    }
    template <class M, class V> V &find(M &m) const { return m; }
    template <class M, class V, class T, class... K>
    V &find(M &m, const T &t, const K &...k) const {
        auto i = m.find(t);
        if (i != m.end())
            return find<decltype(i->second), V, K...>(i->second, k...);
        e = false;
        return find<decltype(i->second), V, K...>(m[t], k...);
    }
    template <class... K> auto operator()(const K &...k) const {
        typedef decltype(f(*this, k...)) V;
        typedef decltype(build<V, K...>(k...)) M;
        if (c) {
            if (p)
                delete (M *)p, p = 0;
            c = false;
        }
        if (!p)
            p = new M(move(build<V, K...>(k...)));
        e = true;
        auto &t = find<M, V, K...>(*((M *)p), k...);
        return e ? t : t = f(*this, k...);
    }
    F f;
    static void *p;
    static bool c, e;
};
template <class F> void *sparse_<F>::p = 0;
template <class F> bool sparse_<F>::e = false;
template <class F> bool sparse_<F>::c = false;
struct dense {
    auto convert() {}
    template <class T, class... L>
    auto convert(const T &t, const L &...limits) {
        l.push_back(t);
        convert(limits...);
    }
    template <class... L> dense(const L &...limits) { convert(limits...); }
    template <class F> auto operator()(const F &f) const {
        dense_<F>::l = l, dense_<F>::c = true;
        return dense_<F>(f);
    }
    vector<int> l;
};
struct sparse {
    template <class F> auto operator()(const F &f) const {
        sparse_<F>::c = true;
        return sparse_<F>(f);
    }
};
} // namespace lru_cache
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
template <class A, class... B> istream &in(A &a, B &...b) {
    return cin >> a, in(b...);
}
void ou() { cout << endl; }
template <class T> void ou(const T &a) { cout << a << endl; }
template <class A, class... B> void ou(const A &a, const B &...b) {
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
// The templates end here.
template <class T> struct discretization {
    vector<T> a;
    void add(T v) { a.push_back(v); }
    void build() {
        sort(begin(a), end(a));
        a.erase(unique(begin(a), end(a)), end(a));
    }
    int order(T v) { return lower_bound(begin(a), end(a), v) - begin(a) + 1; }
    int size() { return a.size(); }
    T value(int v) { return a[v - 1]; }
};
template <class T, int D = 1> struct fenwick_tree {
    fenwick_tree(const vector<int> &_n)
        : n(_n[0]), l(log2(n) + 1e-8), s(n + 1) {
        assert(_n.size() == D);
    }
    void modify(const vector<int> &k, T v) {
        auto j = vector<int>(begin(k) + 1, end(k));
        for (int i = k[0] + 1; i <= n; i += i & -i)
            s[i].modify(j, v);
    }
    template <class I> T sum(const I &k_begin, const I &k_end) {
        T r = 0;
        for (int i = *k_begin + 1; i; i -= i & -i)
            r += s[i].sum(k_begin + 1, k_end);
        ;
        return r;
    }
    T sum(const vector<int> &k) { return sum(begin(k), end(k)); }
    template <class I>
    T sum(const I &l_begin, const I &l_end, const I &r_begin, const I &r_end) {
        return sum(*r_begin, l_begin + 1, l_end, r_begin + 1, r_end) -
               sum(*l_begin - 1, l_begin + 1, l_end, r_begin + 1, r_end);
    }
    template <class I>
    T sum(int k, const I &l_begin, const I &l_end, const I &r_begin,
          const I &r_end) {
        T t = 0;
        for (int i = k + 1; i; i -= i & -i)
            t += s[i].sum(l_begin, l_end, r_begin, r_end);
        return t;
    }
    T sum(const vector<int> &_l, const vector<int> &r) {
        return sum(r[0], begin(_l) + 1, end(_l), begin(r) + 1, end(r)) -
               sum(_l[0] - 1, begin(_l) + 1, end(_l), begin(r) + 1, end(r));
    }
    int n, l;
    vector<fenwick_tree<T, D - 1>> s;
};
template <class T> struct fenwick_tree<T, 1> {
    fenwick_tree(const vector<int> &_n)
        : n(_n[0]), l(log2(n) + 1e-8), a(n), s(n + 1) {
        assert(_n.size() == 1);
    }
    fenwick_tree(int _n) : n(_n), l(log2(n) + 1e-8), a(n), s(n + 1) {}
    void modify(int k, T v) {
        assert(k >= 0 && k < n);
        for (v -= a[k], a[k++] += v; k <= n; k += k & -k)
            s[k] += v;
    }
    T sum(int k) {
        assert(k >= -1 && k < n);
        T r = 0;
        for (++k; k; k -= k & -k)
            r += s[k];
        return r;
    }
    template <class I> T sum(const I &k_begin, const I &k_end) {
        return sum(*k_begin);
    }
    template <class I>
    T sum(const I &l_begin, const I &l_end, const I &r_begin, const I &r_end) {
        assert(l_begin + 1 == l_end && r_begin + 1 == r_end);
        return sum(*r_begin) - sum(*l_begin);
    }
    T sum(int _l, int r) { return sum(r) - sum(_l - 1); }
    int kth(T k) {
        int r = 0;
        for (int i = 1 << l; i; i >>= 1)
            if (r + i <= n && s[r + i] < k)
                k -= s[r += i];
        return r;
    }
    int n, l;
    vector<T> a, s;
};
int main() {
    ios::sync_with_stdio(0);
    cout << setprecision(16) << fixed;
    cin.tie(0);
    many {
        vi a;
        in(a);
        map<int, ll> count;
        ll ans = 0;
        lv(i, a) {
            ans += ll(a.size() - i) * count[a[i]];
            count[a[i]] += i + 1;
        }
        ou(ans);
    }
    return 0;
}
