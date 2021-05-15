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
#define intm modular_arithmetic::integer
#define bcnt __builtin_popcount
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
namespace divisor {
template <class T> auto divisor(vector<pair<T, int>> a) {
    vector<T> r;
    function<void(int, T)> dfs = [&dfs, &a, &r](int i, T now) {
        if (i == int(a.size())) {
            r.push_back(now);
            return;
        }
        for (int j = 0; j <= a[i].second; ++j) {
            dfs(i + 1, now);
            if (j < a[i].second)
                now *= a[i].first;
        }
    };
    dfs(0, 1);
    return r;
}
template <class T> auto divisor_with_mobius_function(vector<pair<T, int>> a) {
    vector<pair<T, T>> r;
    function<void(int, T, T)> dfs = [&dfs, &a, &r](int i, T now, T m) {
        if (i == int(a.size())) {
            r.emplace_back(now, m);
            return;
        }
        dfs(i + 1, now, m), dfs(i + 1, now * a[i].first, -m);
    };
    dfs(0, 1, 1);
    return r;
}
} // namespace divisor
namespace integer_factorization_3 {
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
template <class T> T pow(T a, T b, const T &c) {
    T r = 1;
    for (; b; b & 1 ? r = multiply(r, a, c) : 0, b >>= 1, a = multiply(a, a, c))
        ;
    return r;
}
template <class T> bool miller_rabin_primality_test(const T &a) {
    if (a == 2)
        return true;
    if (a % 2 == 0 || a < 2)
        return false;
    static int p_0[] = {11000544, 31481107}, p_1[] = {2, 7, 61},
               p_2[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    int c, *pi;
    if (a < 316349281)
        c = 2, pi = p_0;
    else if (a < 4759123141ll)
        c = 3, pi = p_1;
    else
        c = 7, pi = p_2;
    T u = a - 1, t = 0, p = 1;
    for (; u % 2 == 0; u /= 2, ++t)
        ;
    for (int i = 0; i < c; ++i) {
        p = pi[i] % a;
        if (!p)
            return true;
        T x = pow(p, u, a);
        if (x == 1)
            continue;
        for (int j = 0; x != a - 1 && j < t; ++j) {
            x = multiply(x, x, a);
            if (x == 1)
                return false;
        }
        if (x == a - 1)
            continue;
        return false;
    }
    return true;
}
template <class T> T sqrt_(const T &x) {
    T ret = T(sqrtl(x));
    while (ret > 0 && ret * ret > x)
        --ret;
    while (x - ret * ret > 2 * ret)
        ++ret;
    return ret;
}
template <class T> T cbrt_(const T &x) {
    T ret = T(cbrt(x));
    while (ret > 0 && ret * ret * ret > x)
        --ret;
    while (x - ret * ret * ret > 3 * ret * (ret + 1))
        ++ret;
    return ret;
}
uint64_t iter(uint64_t const &x, uint64_t const &k, uint64_t const &it_max,
              uint32_t cutoff_div) {
    if (__gcd((uint64_t)k, x) != 1)
        return __gcd((uint64_t)k, x);
    vector<uint16_t> saved;
    uint64_t scaledn = k * x;
    if (scaledn >> 62)
        return 1;
    uint32_t sqrtn = uint32_t(sqrt_(scaledn));
    uint32_t cutoff = sqrt_(2 * sqrtn) / cutoff_div;
    uint32_t q0 = 1, p1 = sqrtn, q1 = uint32_t(scaledn - p1 * p1);
    if (q1 == 0) {
        uint64_t factor = __gcd(x, (uint64_t)p1);
        return factor == x ? 1 : factor;
    }
    uint32_t multiplier = uint32_t(2 * k), coarse_cutoff = cutoff * multiplier;
    uint32_t i, j, p0 = 0, sqrtq = 0;
    for (i = 0; i < it_max; ++i) {
        uint32_t q, bits, tmp;
        tmp = sqrtn + p1 - q1, q = 1;
        if (tmp >= q1)
            q += tmp / q1;
        p0 = q * q1 - p1, q0 = q0 + (p1 - p0) * q;
        if (q1 < coarse_cutoff) {
            tmp = q1 / __gcd(q1, multiplier);
            if (tmp < cutoff)
                saved.push_back((uint16_t)tmp);
        }
        bits = 0, tmp = q0;
        while (!(tmp & 1))
            bits++, tmp >>= 1;
        if (!(bits & 1) && ((tmp & 7) == 1)) {
            sqrtq = (uint32_t)sqrt_(q0);
            if (sqrtq * sqrtq == q0) {
                for (j = 0; j < saved.size(); ++j)
                    if (saved[j] == sqrtq)
                        break;
                if (j == saved.size())
                    break;
            }
        }
        tmp = sqrtn + p0 - q0, q = 1;
        if (tmp >= q0)
            q += tmp / q0;
        p1 = q * q0 - p0, q1 = q1 + (p0 - p1) * q;
        if (q0 < coarse_cutoff) {
            tmp = q0 / __gcd(q0, multiplier);
            if (tmp < cutoff)
                saved.push_back((uint16_t)tmp);
        }
    }
    if (sqrtq == 1)
        return 1;
    if (i == it_max)
        return 1;
    q0 = sqrtq, p1 = p0 + sqrtq * ((sqrtn - p0) / sqrtq);
    q1 = uint32_t((scaledn - (uint64_t)p1 * (uint64_t)p1) / (uint64_t)q0);
    for (j = 0; j < it_max; ++j) {
        uint32_t q = 1, tmp = sqrtn + p1 - q1;
        if (tmp >= q1)
            q += tmp / q1;
        p0 = q * q1 - p1, q0 = q0 + (p1 - p0) * q;
        if (p0 == p1) {
            q0 = q1;
            break;
        }
        tmp = sqrtn + p0 - q0, q = 1;
        if (tmp >= q0)
            q += tmp / q0;
        p1 = q * q0 - p0, q1 = q1 + (p0 - p1) * q;
        if (p0 == p1)
            break;
    }
    uint64_t factor = __gcd((uint64_t)q0, x);
    if (factor == x)
        factor = 1;
    return factor;
}
uint64_t factor(uint64_t const &x) {
    static array<uint32_t, 16> multipliers{
        1,          3,          5,          7,
        11,         3 * 5,      3 * 7,      3 * 11,
        5 * 7,      5 * 11,     7 * 11,     3 * 5 * 7,
        3 * 5 * 11, 3 * 7 * 11, 5 * 7 * 11, 3 * 5 * 7 * 11};
    uint64_t cbrt_x = cbrt_(x);
    if (cbrt_x * cbrt_x * cbrt_x == x)
        return cbrt_x;
    for (uint32_t iter_fact = 1; iter_fact < 20000; iter_fact *= 4) {
        for (uint32_t const &k : multipliers) {
            if (numeric_limits<uint64_t>::max() / k <= x)
                continue;
            uint32_t const it_max = iter_fact * 300;
            uint64_t f = iter(x, k, it_max, 1);
            if (f == 1 || f == x)
                continue;
            return f;
        }
    }
    return 1;
}
template <class T>
vector<pair<T, int>> shankss_square_forms_factorization(T x) {
    vector<T> t;
    auto trial = [&](uint32_t const &i) {
        while (x % i == 0) {
            x /= i;
            t.push_back(i);
        }
    };
    trial(2), trial(3);
    for (uint32_t i = 5, j = 2; i < 5000 && T(i * i) <= x; i += j, j = 6 - j)
        trial(i);
    if (x > 1) {
        static stack<T> s;
        s.push(x);
        while (!s.empty()) {
            x = s.top(), s.pop();
            if (!miller_rabin_primality_test(x)) {
                T f = T(factor(x));
                s.push(f), s.push(x / f);
            } else {
                t.push_back(x);
            }
        }
    }
    sort(t.begin(), t.end());
    vector<pair<T, int>> r;
    for (auto v : t) {
        if (r.empty() || r.back().first != v)
            r.push_back(make_pair(v, 1));
        else
            ++r.back().second;
    }
    return r;
}
} // namespace integer_factorization_3
#include <bits/stdc++.h>
using namespace std;
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
template <class T = int, T M = T(1e9 + 7)> struct integer {
    integer() : v(0) {}
    /*
    Converting a long long to a modular_arithmetic::integer<int, M> may cause
    overflow. You have to reduce it to the range of int first.
    */
    integer(T t) : v(t) { wrap_around(); }
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
    static auto factorial(T a) {
        assert(a >= 0);
        auto &t = factorial_cache;
        while (a >= int(t.size()))
            t.push_back(t.back() * T(t.size()));
        return t[a];
    }
    static auto binary_coefficient(T n, T k) {
        assert(n >= 0 && k >= 0);
        if (n < k)
            return integer<T, M>();
        return factorial(n) / factorial(k) / factorial(n - k);
    }
    T v;
    static mt19937_64 generator;
    static vector<integer<T, M>> inverse_cache, factorial_cache;
};
template <class T, T M>
mt19937_64 integer<T, M>::generator(
    chrono::steady_clock::now().time_since_epoch().count());
template <class T, T M>
vector<integer<T, M>> integer<T, M>::inverse_cache(2, T(1));
template <class T, T M>
vector<integer<T, M>> integer<T, M>::factorial_cache(1, T(1));
template <class T, T M> auto &operator>>(istream &s, integer<T, M> &a) {
    s >> a.v;
    a.wrap_around();
    return s;
}
template <class T, T M> auto &operator<<(ostream &s, integer<T, M> a) {
    return s << a.v;
}
template <class T, T M> auto pow(integer<T, M> a, T b) {
    integer<T, M> r(1);
    if (b < 0)
        a = 1 / a, b = -b;
    for (; b; b >>= 1, a = a * a)
        if (b & 1)
            r = r * a;
    return r;
}
template <class T, T M> integer<T, M> inverse(T a) {
    return inverse(integer<T, M>(a));
}
template <class T, T M> integer<T, M> inverse(integer<T, M> a) {
    assert(a.v);
    if (a.v < T(integer<T, M>::inverse_cache.size()))
        return integer<T, M>::inverse_cache[a.v];
    return pow(a, M - 2);
}
template <class T, T M> auto inverse_cached(T a) {
    return inverse_cached(integer<T, M>(a));
}
template <class T, T M> auto inverse_cached(integer<T, M> a) {
    assert(a.v);
    auto &t = integer<T, M>::inverse_cache;
    while (int(t.size()) <= a.v) {
        t.push_back(integer<T, M>(-M / T(t.size())) * t[M % t.size()]);
    }
    return t[a.v];
}
template <class T, T M> auto operator<<(integer<T, M> a, T b) {
    return a * pow(integer<T, M>(2), b);
}
template <class T, T M> auto operator>>(integer<T, M> a, T b) {
    return a / pow(integer<T, M>(2), b);
}
// Not tested.
template <class T, T M> auto random() {
    integer<T, M>(
        uniform_int_distribution<T>(0, M - 1)(integer<T, M>::generator));
}
// Not tested.
template <class T, T M> auto sqrt(integer<T, M> a) {
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
template <class T, T M>
integer<T, M> lagrange_interpolation(const vector<T> &y, T x) {
    return lagrange_interpolation(y, integer<T, M>(x));
}
template <class T, T M>
integer<T, M> lagrange_interpolation(const vector<T> &y, integer<T, M> x) {
    vector<integer<T, M>> t;
    for (auto v : y)
        t.push_back(integer<T, M>(v));
    return lagrange_interpolation(t, x);
}
template <class T, T M>
integer<T, M> lagrange_interpolation(const vector<integer<T, M>> &y, T x) {
    return lagrange_interpolation(y, integer<T, M>(x));
}
template <class T, T M>
integer<T, M> lagrange_interpolation(const vector<integer<T, M>> &y,
                                     integer<T, M> x) {
    vector<integer<T, M>> f(1, 1), g(y.size(), x), h(y.size(), x);
    for (int i = 1; i < int(y.size()); ++i) {
        f.push_back(f.back() * inverse_cached<T, M>(i));
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
const int candidate = 1073741789;
} // namespace modular_arithmetic
// The templates end here.
int main() {
    fast, prec(12);
    ll d;
    in(d);
    auto f = integer_factorization_3::shankss_square_forms_factorization(d);
    unordered_map<ll, vi> a;
    for (auto d : divisor::divisor(f)) {
        vi t;
        ll d2 = d;
        lv(i, f) {
            t.push_back(0);
            while (d2 % f[i].first == 0) {
                ++t.back();
                d2 /= f[i].first;
            }
        }
        a[d] = t;
    }
    auto way = [&](ll s, ll t) {
        vi tmp(f.size());
        auto ts = a[s], tt = a[t];
        lv(i, f) tmp[i] = tt[i] - ts[i];
        using inte = intm<int, 998244353>;
        inte ans = inte::factorial(sum(tmp));
        for (auto v : tmp)
            ans /= inte::factorial(v);
        return ans;
    };
    many {
        ll u, v;
        in(u, v);
        ou(way(gcd(u, v), u) * way(gcd(u, v), v));
    }
    return 0;
}
