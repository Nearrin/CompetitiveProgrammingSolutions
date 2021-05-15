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
#if __cplusplus > 201103L
template <class T> struct func {
    func(T &&t_) : t(forward<T>(t_)) {}
    template <class... A> auto operator()(A &&... a) const {
        return t(*this, forward<A>(a)...);
    }
    T t;
};
#endif
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
namespace segment_tree {
template <class T> struct segment_tree {
    struct node {
        node *c[2];
        T s;
        int l, r;
    } * root;
    node *build(const vector<T> &a, int l, int r) {
        node *u = new node;
        if (l == r)
            u->c[0] = u->c[1] = 0, u->s = a[l];
        else {
            int m = (l + r) / 2;
            u->c[0] = build(a, l, m), u->c[1] = build(a, m + 1, r);
            u->s = T::merge(u->c[0]->s, u->c[1]->s);
        }
        u->l = l, u->r = r;
        return u;
    }
    void build(const vector<T> &a) { root = build(a, 0, int(a.size() - 1)); }
    segment_tree() : root(0) {}
    segment_tree(const vector<T> &a) { build(a); }
    void destroy(node *u) {
        if (u) {
            destroy(u->c[0]), destroy(u->c[1]);
            delete u;
        }
    }
    ~segment_tree() { destroy(root); }
    void modify(node *u) {
        auto t = u->s.modification();
        if (u->c[0])
            T::push(u->c[0]->s, t), T::push(u->c[1]->s, t);
        u->s.modify();
    }
    void merge(node *u) { u->s = T::merge(u->c[0]->s, u->c[1]->s); }
    void modify_single(int p, const T &s, node *u = 0) {
        u = u ? u : root;
        modify(u);
        if (u->l == u->r) {
            assert(p == u->l);
            u->s = s;
        } else {
            modify_single(p, s, u->c[p > u->c[0]->r]);
            modify(u->c[p <= u->c[0]->r]), merge(u);
        }
    }
    template <class A> void modify_segment(int l, int r, A &t, node *u = 0) {
        u = u ? u : root;
        assert((u != root || (u->l <= l && u->r >= r)) && l <= r), modify(u);
        if (l <= u->l && r >= u->r)
            T::push(u->s, t), modify(u);
        else {
            if (l <= u->c[0]->r)
                modify_segment(l, r, t, u->c[0]);
            else
                modify(u->c[0]);
            if (r >= u->c[1]->l)
                modify_segment(l, r, t, u->c[1]);
            else
                modify(u->c[1]);
            merge(u);
        }
    }
    const T &query_single(int p, node *u = 0) {
        u = u ? u : root, modify(u);
        if (u->l == u->r) {
            assert(p == u->l);
            return u->s;
        } else {
            return query_single(p, u->c[p > u->c[0]->r]);
        }
    }
    T query_segment(int l, int r, node *u = 0) {
        u = u ? u : root, modify(u);
        assert((u != root || (u->l <= l && u->r >= r)) && l <= r);
        if (l <= u->l && r >= u->r)
            return u->s;
        else {
            if (r <= u->c[0]->r)
                return query_segment(l, r, u->c[0]);
            if (l >= u->c[1]->l)
                return query_segment(l, r, u->c[1]);
            return T::merge(query_segment(l, r, u->c[0]),
                            query_segment(l, r, u->c[1]));
        }
    }
};
} // namespace segment_tree
namespace statistic_ {
struct statistic {
    statistic() {}
    int modification() { return 0; }
    void modify() {}
    void resverse() {}
    static statistic merge(const statistic &a, const statistic &b) {
        return statistic();
    }
    static void push(statistic &a, int &t) {}
};
template <class T> struct add_min {
    int i;
    T v, d;
    add_min() {}
    add_min(T _v, int _i) : i(_i), v(_v), d(0) {}
    T modification() { return d; }
    void modify() { v += d, d = 0; }
    void reverse() {}
    static add_min merge(const add_min &a, const add_min &b) {
        assert(!a.d && !b.d);
        if (a.v < b.v)
            return a;
        else
            return b;
    }
    static void push(add_min &a, T &d) { a.d += d; }
};
template <class T> struct add_sum {
    int l;
    T s, d;
    add_sum() {}
    add_sum(T _s, int _l = 1) : l(_l), s(_s), d(0) {}
    T modification() { return d; }
    void modify() { s += d * l, d = 0; }
    void reverse() {}
    static add_sum merge(const add_sum &a, const add_sum &b) {
        return add_sum(a.s + b.s, a.l + b.l);
    }
    static void push(add_sum &a, T &d) { a.d += d; }
};
} // namespace statistic_
namespace modular_arithmetic {
#ifdef LOCAL
template <class T> T multiply(T x, T y, const T &z) {
    return T((long long)x * y % z);
}
template <>
long long multiply<long long>(long long a, long long b, const long long &c) {
    ll r = 0;
    for (; b; b & 1 ? r = (r + a) % c : 0, b >>= 1, a = (a + a) % c)
        ;
    return r;
}
#else
template <class T> T multiply(const T &x, const T &y, const T &z) {
    return T((long long)x * y % z);
}
template <>
long long multiply<long long>(const long long &x, const long long &y,
                              const long long &z) {
    return (x * y - (long long)(((long double)x * y + 0.5) / z) * z + z) % z;
}
#endif
template <class T = int, T M = 998244353> struct integer {
    integer() : v(0) {}
    integer(T t) : v(t) { wrap_around(); }
    integer(int64_t t) {
        if (t < 0)
            v = (t % M + M) % M;
        else if (t >= M)
            v = t % M;
    }
    void wrap_around() {
        if (v < 0)
            v = (v % M + M) % M;
        else if (v >= M)
            v %= M;
    }
    auto operator-() const {
        integer<T, M> a;
        a.v = (v ? M - v : 0);
        return a;
    }
    auto &operator+=(integer<T, M> a) { return *this = *this + a; }
    auto &operator-=(integer<T, M> a) { return *this = *this - a; }
    auto &operator*=(integer<T, M> a) { return *this = *this * a; }
    auto &operator/=(integer<T, M> a) { return *this = *this / a; }
    auto &operator<<=(T a) { return *this = *this << a; };
    auto &operator>>=(T a) { return *this = *this >> a; };
    friend auto operator/(integer<T, M> a, integer<T, M> b) {
        return a * inverse(b);
    }
    friend auto operator+(integer<T, M> a, integer<T, M> b) {
        integer<T, M> c;
        c.v = a.v + b.v;
        if (c.v >= M)
            c.v -= M;
        return c;
    }
    friend auto operator-(integer<T, M> a, integer<T, M> b) {
        integer<T, M> c;
        c.v = a.v - b.v;
        if (c.v < 0)
            c.v += M;
        return c;
    }
    friend auto operator*(integer<T, M> a, integer<T, M> b) {
        integer<T, M> c;
        c.v = multiply(a.v, b.v, M);
        return c;
    }
    friend auto operator^(integer<T, M> a, T b) { return pow(a, b); }
    friend bool operator==(integer<T, M> a, integer<T, M> b) {
        return a.v == b.v;
    }
    friend bool operator!=(integer<T, M> a, integer<T, M> b) {
        return a.v != b.v;
    }
    friend bool operator<(integer<T, M> a, integer<T, M> b) {
        return a.v < b.v;
    };
    friend bool operator<=(integer<T, M> a, integer<T, M> b) {
        return a.v <= b.v;
    };
    friend bool operator>(integer<T, M> a, integer<T, M> b) {
        return a.v > b.v;
    };
    friend bool operator>=(integer<T, M> a, integer<T, M> b) {
        return a.v >= b.v;
    };
    friend auto &operator>>(istream &s, integer<T, M> &a) {
        s >> a.v;
        a.wrap_around();
        return s;
    }
    friend auto &operator<<(ostream &s, integer<T, M> a) { return s << a.v; }
    friend auto operator<<(integer<T, M> a, T b) {
        return a * pow(integer<T, M>(2), b);
    }
    friend auto operator>>(integer<T, M> a, T b) {
        return a / pow(integer<T, M>(2), b);
    }
    static auto pow(integer<T, M> a, T b) {
        integer<T, M> r(1);
        if (b < 0)
            a = 1 / a, b = -b;
        for (; b; b >>= 1, a = a * a)
            if (b & 1)
                r = r * a;
        return r;
    }
    // Not tested.
    static auto sqrt(integer<T, M> a) {
        vector<integer<T, M>> r;
        if (!a.v)
            r.push_back(decltype(r)(0));
        else if (pow(a, M - 1 >> 1).v == 1) {
            int s = M - 1, t = 0;
            integer<T, M> b = 1;
            for (; pow(b, M - 1 >> 1).v != M - 1; b = integer<T, M>::random())
                ;
            for (; s % 2 == 0; ++t, s /= 2)
                ;
            integer<T, M> x = pow(a, (s + 1) / 2), e = pow(a, s);
            for (int i = 1; i < t; ++i, e = x * x / a)
                if (pow(e, 1 << t - i - 1).v != 1)
                    x = x * pow(b, (1 << i - 1) * s);
            r.push_back(x);
            r.push_back(-x);
        }
        return r;
    }
    static T extended_euclidean_algorithm(T a, T b, T &x, T &y) {
        if (!b) {
            x = 1, y = 0;
            return a;
        } else {
            T d = extended_euclidean_algorithm(b, a % b, y, x);
            y -= a / b * x;
            return d;
        }
    }
    static auto inverse(integer<T, M> a) {
        assert(a.v);
        if (a.v < T(integer<T, M>::inverse_cache.size()))
            return integer<T, M>::inverse_cache[a.v];
        T t;
        extended_euclidean_algorithm(a.v, M, a.v, t);
        if (a.v < 0)
            a.v += M;
        return a;
    }
    static auto inverse_cached(const integer<T, M> &a) {
        assert(a.v);
        auto &t = inverse_cache;
        while (int(t.size()) <= a.v) {
            t.push_back(integer<T, M>(-M / T(t.size())) * t[M % t.size()]);
        }
        return t[a.v];
    }
    static auto factorial(const T &a) {
        assert(a >= 0);
        auto &t = factorial_cache;
        while (a >= int(t.size()))
            t.push_back(t.back() * T(t.size()));
        return t[a];
    }
    static auto factorial_inverse(const T &a) {
        assert(a >= 0);
        auto &t = factorial_inverse_cache;
        while (a >= int(t.size()))
            t.push_back(t.back() * inverse_cached(T(t.size())));
        return t[a];
    }
    static auto binary_coefficient(T n, T k) {
        assert(n >= 0 && k >= 0);
        if (n < k)
            return integer<T, M>();
        return factorial(n) * factorial_inverse(k) * factorial_inverse(n - k);
    }
    static auto lagrange_interpolation(const vector<integer<T, M>> &y,
                                       integer<T, M> x) {
        vector<integer<T, M>> f(1, 1), g(y.size(), x), h(y.size(), x);
        for (int i = 1; i < int(y.size()); ++i) {
            f.push_back(f.back() * inverse_cached(i));
            g[i] = h[i] -= i, g[i] *= g[i - 1];
        }
        for (int i = int(y.size()) - 2; i >= 0; --i)
            h[i] *= h[i + 1];
        integer<T, M> r = 0;
        for (int i = 0; i < int(y.size()); ++i) {
            integer<T, M> t = f[i] * f[y.size() - 1 - i];
            if (i)
                t *= g[i - 1];
            if (i + 1 != int(y.size()))
                t *= h[i + 1];
            if (int(y.size() - i - 1) % 2)
                t = -t;
            r += t * y[i];
        }
        return r;
    }
    static auto random() {
        return integer<T, M>(uniform_int_distribution<T>(0, M - 1)(generator));
    }
    T v;
    static mt19937_64 generator;
    static vector<integer<T, M>> inverse_cache, factorial_cache,
        factorial_inverse_cache;
};
template <class T, T M>
mt19937_64 integer<T, M>::generator(
    chrono::steady_clock::now().time_since_epoch().count());
template <class T, T M>
vector<integer<T, M>> integer<T, M>::inverse_cache(2, T(1));
template <class T, T M>
vector<integer<T, M>> integer<T, M>::factorial_cache(1, T(1));
template <class T, T M>
vector<integer<T, M>> integer<T, M>::factorial_inverse_cache(1, T(1));
const int candidate = 1073741789;
} // namespace modular_arithmetic
// The templates end here.
using integer = modular_arithmetic::integer<>;
struct statistic {
    statistic() {}
    int modification() { return 0; }
    void modify() {}
    void resverse() {}
    static statistic merge(const statistic &a, const statistic &b) {
        statistic c;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 2; ++k)
                    c.a[i][j] += b.a[i][k] * a.a[k][j];
        return c;
    }
    static void push(statistic &a, int &t) {}
    integer a[2][2];
};
int main() {
    ios::sync_with_stdio(0);
    cout << setprecision(16) << fixed;
    cin.tie(0);
    int n, q;
    str a;
    in(n, q, a);
    if (a.size() < 2) {
        lp(i, 1, q) {
            int p, v;
            in(p, v);
            a[p - 1] = '0' + v;
            ou(a[0] - '0' + 1);
        }
    } else {
        vector<statistic> b(n - 1);
        auto matrix = [&](int i) {
            statistic t;
            t.a[1][0] = 1;
            t.a[0][0] = a[i] - '0' + 1;
            int v = (a[i - 1] - '0') * 10 + a[i] - '0';
            if (v >= 10 && v <= 18) {
                t.a[0][1] = 19 - v;
            }
            return t;
        };
        lv(i, a) if (i) { b[i - 1] = matrix(i); }
        segment_tree::segment_tree<statistic> tree(b);
        lp(i, 1, q) {
            int p, v;
            in(p, v);
            --p;
            a[p] = '0' + v;
            if (p) {
                b[p - 1] = matrix(p);
                tree.modify_single(p - 1, b[p - 1]);
            }
            if (p + 1 != n) {
                b[p] = matrix(p + 1);
                tree.modify_single(p, b[p]);
            }
            integer ans =
                tree.root->s.a[0][0] * (a[0] - '0' + 1) + tree.root->s.a[0][1];
            ou(ans);
        }
    }
    return 0;
}
