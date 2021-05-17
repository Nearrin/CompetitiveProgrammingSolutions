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
    auto build(int i, const T &t, const K &... k) const {
        auto u = build<V, K...>(i + 1, k...);
        return vector<decltype(u)>(l[i], u);
    }
    template <class M, class V> V &find(M &m) const { return m; }
    template <class M, class V, class T, class... K>
    V &find(M &m, const T &t, const K &... k) const {
        if (t < m.size())
            return find<decltype(m[t]), V, K...>(m[t], k...);
        return find<decltype(m[t]), V, K...>(m[e = false], k...);
    }
    /*
    The cache can handle outliers without crashing, but the values won't be
    saved.
    */
    template <class... K> auto operator()(const K &... k) const {
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
    auto build(const T &t, const K &... k) const {
        return unordered_map<T, decltype(build<V, K...>(k...))>();
    }
    template <class M, class V> V &find(M &m) const { return m; }
    template <class M, class V, class T, class... K>
    V &find(M &m, const T &t, const K &... k) const {
        auto i = m.find(t);
        if (i != m.end())
            return find<decltype(i->second), V, K...>(i->second, k...);
        e = false;
        return find<decltype(i->second), V, K...>(m[t], k...);
    }
    template <class... K> auto operator()(const K &... k) const {
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
/*
Decorating a function erases all cached values. Please save the resulting
function if you want to use the old values. Because of the use of member
variables, the decorators may not work when dealing with two functions of the
same type. However, lambda functions have unique types, so they will be handled.
*/
struct dense {
    auto convert() {}
    template <class T, class... L>
    auto convert(const T &t, const L &... limits) {
        l.push_back(t);
        convert(limits...);
    }
    template <class... L> dense(const L &... limits) { convert(limits...); }
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
/*
The last dimension should be large enough or using vect may be slow.
*/
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
int main_() {
    ios::sync_with_stdio(0);
    cout << setprecision(16) << fixed;
    cin.tie(0);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
namespace linear_programming {
template <class T> struct expression;
template <class T = double> struct variable {
    variable(optional<T> _l = optional<T>{}, optional<T> _r = optional<T>{})
        : l(_l), r(_r) {}
    auto operator-() { return -expression<T>(*this); }
    friend auto operator+(variable<T> &a, variable<T> &b) {
        return expression<T>(a) + expression<T>(b);
    }
    friend auto operator+(variable<T> &a, const T &b) {
        return expression<T>(a) + expression<T>(b);
    }
    friend auto operator+(const T &a, variable<T> &b) {
        return expression<T>(a) + expression<T>(b);
    }
    friend auto operator-(variable<T> &a, variable<T> &b) {
        return expression<T>(a) - expression<T>(b);
    }
    friend auto operator-(variable<T> &a, const T &b) {
        return expression<T>(a) - expression<T>(b);
    }
    friend auto operator-(const T &a, variable<T> &b) {
        return expression<T>(a) - expression<T>(b);
    }
    friend auto operator*(variable<T> &a, const T &b) {
        return expression<T>(a) * expression<T>(b);
    }
    friend auto operator*(const T &a, variable<T> &b) {
        return expression<T>(a) * expression<T>(b);
    }
    friend auto operator/(variable<T> &a, const T &b) {
        return expression<T>(a) / expression<T>(b);
    }
    friend auto operator>=(variable<T> &a, const T &b) {
        return expression<T>(a) >= expression<T>(b);
    }
    friend auto operator>=(const T &a, variable<T> &b) {
        return expression<T>(a) >= expression<T>(b);
    }
    friend auto operator<=(variable<T> &a, const T &b) {
        return expression<T>(a) <= expression<T>(b);
    }
    friend auto operator<=(const T &a, variable<T> &b) {
        return expression<T>(a) <= expression<T>(b);
    }
    optional<T> l, r;
    T v;
};
template <class T> auto &operator<<(ostream &s, variable<T> a) {
    return s << a.v;
}
template <class T> struct constraint;
template <class T = double> struct expression {
    expression() {}
    expression(T c) : e{{0, c}} {}
    expression(variable<T> &v) : e{{&v, 1}} {}
    expression(const unordered_map<variable<T> *, T> &_e) : e(_e) {}
    auto operator-() const {
        auto t = *this;
        for (auto &i : t.e)
            i.second *= -1;
        return t;
    }
    friend auto operator+(const expression<T> &a, const expression<T> &b) {
        expression<T> t = a;
        for (auto &i : b.e)
            t.e[i.first] += i.second;
        return t;
    }
    friend auto operator-(const expression<T> &a, const expression<T> &b) {
        expression<T> t = a;
        for (auto &i : b.e)
            t.e[i.first] -= i.second;
        return t;
    }
    friend auto operator*(const expression<T> &a, const expression<T> &b) {
        assert((a.e.size() == 1 && a.e.count(0)) ||
               (b.e.size() == 1 && b.e.count(0)));
        expression<T> t;
        T c;
        if (a.e.size() == 1 && a.e.count(0))
            t.e = b.e, c = a.e.begin()->second;
        else
            t.e = a.e, c = b.e.begin()->second;
        for (auto &i : t.e)
            i.second *= c;
        return t;
    }
    friend auto operator/(const expression<T> &a, const expression<T> &b) {
        assert(b.e.size() == 1 && b.e.count(0));
        expression<T> t = a;
        T c = b.e[0];
        for (auto &i : t.e)
            i.second *= c;
        return t;
    }
    auto &operator+=(const expression<T> &a) { return *this = *this + a; }
    auto &operator-=(const expression<T> &a) { return *this = *this - a; }
    auto &operator*=(const expression<T> &a) { return *this = *this * a; }
    auto &operator/=(const expression<T> &a) { return *this = *this / a; }
    friend auto operator>=(const expression<T> &a, const expression<T> &b) {
        expression<T> t = a - b;
        return constraint<T>(t);
    };
    friend auto operator<=(const expression<T> &a, const expression<T> &b) {
        return -a >= -b;
    };
    unordered_map<variable<T> *, T> e;
};
template <class T = double> struct constraint {
    constraint(const expression<T> &_e) : e(_e) {}
    expression<T> e;
};
template <class T> struct simplex_algorithm;
template <class T, class O = simplex_algorithm<T>>
optional<T> maximize(const expression<T> &target,
                     vector<constraint<T>> constraints) {
    unordered_map<variable<T> *, int> variables;
    for (const auto &i : constraints)
        for (const auto &j : i.e.e)
            if (j.first && !variables.count(j.first))
                variables[j.first] = int(variables.size()) + 1;
    for (const auto &j : target.e)
        if (j.first && !variables.count(j.first))
            variables[j.first] = int(variables.size()) + 1;
    for (auto [v, i] : variables) {
        if (v->l)
            constraints.push_back(*v >= *v->l);
        if (v->r)
            constraints.push_back(*v <= *v->r);
    }
    O optimizer(int(constraints.size()), int(variables.size()));
    for (int i = 0; i < int(constraints.size()); ++i)
        for (const auto &j : constraints[i].e.e) {
            int k = (j.first ? variables[j.first] : 0);
            optimizer.a[i + 1][k] += j.second;
        }
    for (const auto &i : target.e) {
        int j = (i.first ? variables[i.first] : 0);
        optimizer.a[0][j] += i.second;
    }
    auto result = optimizer.run();
    if (result.empty())
        return {};
    for (auto i : variables)
        i.first->v = result[i.second];
    return {result[0]};
}
template <class T, class O = simplex_algorithm<T>>
auto minimize(const expression<T> &target,
              const vector<constraint<T>> &constraints) {
    return maximize<T, O>(-target, constraints);
}
template <class T = double> struct simplex_algorithm {
    int n, m, p;
    vector<vector<T>> a;
    vector<int> mp, ma, md;
    vector<T> result;
    const T E;
    simplex_algorithm(int _n, int _m)
        : n(_n), m(_m), p(0), a(n + 2, vector<T>(m + 2)), mp(n + 1),
          ma(m + n + 2), md(m + 2), result(m + 1), E(1e-8) {}
    T &operator[](const pair<int, int> &i) {
        return a.at(i.first).at(i.second);
    }
    void pivot(int l, int e) {
        swap(mp[l], md[e]), ma[mp[l]] = l, ma[md[e]] = -1;
        double t = -a[l][e];
        a[l][e] = -1;
        vector<int> qu;
        for (int i = 0; i <= m + 1; ++i)
            if (fabs(a[l][i] /= t) > E)
                qu.push_back(i);
        for (int i = 0; i <= n + 1; ++i)
            if (i != l && fabs(a[i][e]) > E) {
                t = a[i][e];
                a[i][e] = 0;
                for (int j = 0; j < int(qu.size()); ++j)
                    a[i][qu[j]] += a[l][qu[j]] * t;
            }
        if (-p == l)
            p = e;
        else if (p == e)
            p = -l;
    }
    int optimize(int d) {
        for (int l = -1, e = -1;; pivot(l, e), l = -1, e = -1) {
            for (int i = 1; i <= m + 1; ++i)
                if (a[d][i] > E) {
                    e = i;
                    break;
                }
            if (e == -1)
                return 1;
            T t;
            for (int i = 1; i <= n; ++i)
                if (a[i][e] < -E && (l == -1 || a[i][0] / -a[i][e] < t))
                    t = a[i][0] / -a[i][e], l = i;
            if (l == -1)
                return 0;
        }
    }
    vector<T> run() {
        for (int i = 1; i <= m + 1; ++i)
            ma[i] = -1, md[i] = i;
        for (int i = m + 2; i <= m + n + 1; ++i)
            ma[i] = i - (m + 1), mp[i - (m + 1)] = i;
        T t = a[1][0];
        int l = 1;
        for (int i = 2; i <= n; ++i)
            if (a[i][0] < t)
                t = a[i][0], l = i;
        if (t < -E) {
            for (int i = 1; i <= n; ++i)
                a[i][m + 1] = 1;
            a[n + 1][m + 1] = -1, p = m + 1, pivot(l, m + 1);
            if (!optimize(n + 1) || fabs(a[n + 1][0]) > E)
                return vector<T>();
            if (p < 0)
                for (int i = 1; i <= m; ++i)
                    if (fabs(a[-p][i]) > E) {
                        pivot(-p, i);
                        break;
                    }
            for (int i = 0; i <= n; ++i)
                a[i][p] = 0;
        }
        if (!optimize(0))
            return vector<T>();
        result[0] = a[0][0];
        for (int i = 1; i <= m; ++i)
            if (ma[i] != -1)
                result[i] = a[ma[i]][0];
        return result;
    }
};
} // namespace linear_programming
class Solution {
  public:
    int maximumRequests(int n, vector<vector<int>> &requests) {
        int m = requests.size();
        vector<linear_programming::variable<>> v(m);
        vector<linear_programming::constraint<>> c;
        vector<linear_programming::expression<>> e(n);
        linear_programming::expression<> t;
        for (int i = 0; i < m; ++i) {
            c.push_back(v[i] >= 0);
            c.push_back(v[i] <= 1);
            t += v[i];
            e[requests[i][0]] += v[i];
            e[requests[i][1]] -= v[i];
        }
        for (int i = 0; i < n; ++i) {
            c.push_back(e[i] >= 0);
            c.push_back(e[i] <= 0);
        }
        return round(linear_programming::maximize(t, c).value());
    }
};
