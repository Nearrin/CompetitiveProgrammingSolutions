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
#else
template <class T> long long regu(const T &a) { return a; }
template <> long long regu(const uint32_t &a) { return int(a); }
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
template <class T> auto vect(const vector<T> &v, int n) {
    assert(v.size() <= 1);
    return v.size() ? vector<T>(n, v[0]) : vector<T>(n);
}
template <class T, class... D> auto vect(const vector<T> &v, int n, D... m) {
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
template <class T> istream &operator>>(istream &s, valarray<T> &a) {
    for (int i = -1; i < 0 && (!a.size() && (cin >> i, a.resize(i), 0), i = 0),
             i < int(a.size());)
        s >> a[i++];
    return s;
}
template <class T> ostream &operator<<(ostream &s, const valarray<T> &a) {
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
using vai = valarray<int>;
using val = valarray<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vvi = vector<vi>;
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
// The templates end here.
int main() {
    ios::sync_with_stdio(!cin.tie(0));
    cout << setprecision(16) << fixed;
    ll n;
    in(n);
    int ans = 0;
    for (auto v :
         integer_factorization_3::shankss_square_forms_factorization(n)) {
        int t = 0;
        for (int i = 1; t + i <= v.second; ++i) {
            ++ans;
            t += i;
        }
    }
    ou(ans);
    return 0;
}
