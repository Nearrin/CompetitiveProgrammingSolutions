#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#define lp(i, l, r) for (int i = l; i <= r; ++i)
#define rp(i, r, l) for (int i = r; i >= l; --i)
#define ls(i, s) for (int i = 0; s[i]; ++i)
#define rs(i, s) for (int i = strlen(s) - 1; i >= 0; --i)
#define lv(i, a) for (int i = 0; i < int(a.size()); ++i)
#define rv(i, a) for (int i = (int)a.size() - 1; i >= 0; --i)
#define in(a) int a = (cin >> a, a)
#define ou(a) cout << a << endl
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define prec(a) cout << setprecision(a) << fixed
#define appl(f, a) for (auto i = begin(a); i != end(a); f, ++i)
#define many for (int T = -1; T < 0 && cin >> T, T--;)
#define rang(a) begin(a), end(a)
#define gene template <class T>
#define endl '\n'
#define asse assert
using namespace std;
using namespace __gnu_pbds;
gene void sort(T &a) { sort(rang(a)); }
gene void reve(T &a) { reverse(rang(a)); }
gene void uniq(T &a) { sort(a), a.erase(unique(rang(a)), end(a)); }
gene void shuf(T &a) { random_shuffle(rang(a)); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
gene auto gath(const T &a, const vector<int> &b) {
    vector<typename T::value_type> r;
    for (auto i : b)
        r.push_back(a[i]);
    return r;
}
gene auto min(const T &a) { return *min_element(rang(a)); }
gene auto max(const T &a) { return *max_element(rang(a)); }
gene auto sum(const T &a) { return accumulate(rang(a), 0); }
gene T inf() { return numeric_limits<T>::max(); }
gene int tmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
gene int tmax(T &a, T b) { return b > a ? a = b, 1 : 0; }
gene using bbst =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
gene using heap = __gnu_pbds::priority_queue<T, greater<T>, pairing_heap_tag>;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
template <class F, class S> auto &operator>>(istream &s, pair<F, S> &a) {
    return s >> a.first >> a.second;
}
gene auto &operator>>(istream &s, vector<T> &a) {
    for (int i = -1; i < 0 && (!a.size() && (cin >> i, a.resize(i), 0), i = 0),
             i < int(a.size());)
        s >> a[i++];
    return s;
}
template <class F, class S> auto &operator<<(ostream &s, const pair<F, S> &a) {
    return s << '(' << a.first << ", " << a.second << ')';
}
gene auto &operator<<(ostream &s, const vector<T> &a) {
    lv(i, a) cout << a[i] << (i + 1 == int(a.size()) ? "" : " ");
    return s;
}
namespace integer_factorization_3 {
typedef long long ll;
typedef unsigned long long ull;
ull srt(const ull &a) {
    ull b = sqrt(a);
    b -= b * b > a;
    return b += (b + 1) * (b + 1) <= a;
}
int sqr(const ull &a, ll &b) {
    b = srt(a);
    return b * b == a;
}
ull gcd(const ull &a, const ull &b) { return b ? gcd(b, a % b) : a; }
ll amb(ll a, const ll &B, const ll &dd, const ll &D) {
    for (ll q = (dd + B / 2) / a, b = q * a * 2 - B, c = (D - b * b) / 4 / a,
            qc, qcb, a0 = a, b0 = a, b1 = b, c0 = c;
         ; b1 = b, c0 = c) {
        if (c0 > dd)
            qcb = c0 - b, b = c0 + qcb, c = a - qcb;
        else {
            q = (dd + b / 2) / c0;
            if (q == 1)
                qcb = c0 - b, b = c0 + qcb, c = a - qcb;
            else
                qc = q * c0, qcb = qc - b, b = qc + qcb, c = a - q * qcb;
        }
        if (a = c0, b == b1)
            break;
        if (b == b0 && a == a0)
            return 0;
    }
    return a & 1 ? a : a >> 1;
}
ull factor(const ull &n) {
    if (n & 1 ^ 1)
        return 2;
    if (n % 3 == 0)
        return 3;
    if (n % 5 == 0)
        return 5;
    if (srt(n) * srt(n) == n)
        return srt(n);
    static ll d1, d2, a1, b1, c1, dd1, L1, a2, b2, c2, dd2, L2, a, q, c, qc,
        qcb, D1, D2, bl1[1 << 19], bl2[1 << 19];
    int p1 = 0, p2 = 0, ac1 = 1, ac2 = 1, j, nm4 = n & 3;
    if (nm4 == 1)
        D1 = n, D2 = 5 * n, d2 = srt(D2), dd2 = d2 / 2 + d2 % 2,
        b2 = (d2 - 1) | 1;
    else
        D1 = 3 * n, D2 = 4 * n, dd2 = srt(D2), d2 = dd2 * 2, b2 = d2;
    d1 = srt(D1), b1 = (d1 - 1) | 1, c1 = (D1 - b1 * b1) / 4,
    c2 = (D2 - b2 * b2) / 4, L1 = srt(d1), L2 = srt(d2), dd1 = d1 / 2 + d1 % 2;
    for (int i = a1 = a2 = 1; ac1 || ac2; ++i) {
#define m(t)                                                                   \
    if (ac##t) {                                                               \
        c = c##t;                                                              \
        q = c > dd##t ? 1 : (dd##t + b##t / 2) / c;                            \
        if (q == 1)                                                            \
            qcb = c - b##t, b##t = c + qcb, c##t = a##t - qcb;                 \
        else                                                                   \
            qc = q * c, qcb = qc - b##t, b##t = qc + qcb,                      \
            c##t = a##t - q * qcb;                                             \
        if ((a##t = c) <= L##t)                                                \
            bl##t[p##t++] = a##t;                                              \
    }
        m(1) m(2) if (i & 1) continue;
#undef m
#define m(t)                                                                   \
    if ((ac##t = ac##t & a##t != 1) && sqr(a##t, a)) {                         \
        if (a <= L##t)                                                         \
            for (j = 0; j < p##t; j++)                                         \
                if (a == bl##t[j]) {                                           \
                    a = 0;                                                     \
                    break;                                                     \
                }                                                              \
        if (a > 0) {                                                           \
            if ((q = gcd(a, b##t)) > 1)                                        \
                return q * q;                                                  \
            q = amb(a, b##t, dd##t, D##t);                                     \
            if (nm4 == 5 - 2 * t &&                                            \
                (q = amb(a, b##t, dd##t, D##t)) % (2 * t + 1) == 0)            \
                q /= 2 * t + 1;                                                \
            if (q > 1)                                                         \
                return q;                                                      \
        }                                                                      \
    }
        m(1) m(2)
#undef m
    }
    for (int i = 3;; i += 2)
        if (n % i == 0)
            return i;
}
ll multiply(const ll &x, const ll &y, const ll &z) {
    return (x * y - (ll)(((long double)x * y + 0.5) / z) * z + z) % z;
}
ll pow(ll a, ll b, const ll &c) {
    ll r = 1;
    for (; b; b & 1 ? r = multiply(r, a, c) : 0, b >>= 1, a = multiply(a, a, c))
        ;
    return r;
}
int check(const ll &a) {
    if (a == 2)
        return 1;
    if (a % 2 == 0 || a < 2)
        return 0;
    static int pf[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    ll u = a - 1, t = 0, p;
    for (; u % 2 == 0; u /= 2, ++t)
        ;
    for (int i = 0; i < 7; ++i) {
        p = pf[i] % a;
        if (!p || p == a - 1)
            continue;
        ll x = pow(p, u, a);
        if (x == 1)
            continue;
        for (int j = 0; x != a - 1 && j < t; ++j) {
            x = multiply(x, x, a);
            if (x == 1)
                return 0;
        }
        if (x == a - 1)
            continue;
        return 0;
    }
    return 1;
}
auto shankss_square_forms_factorization(const ll &a) {
    assert(a <= 3689348814694258326ll);
    if (a == 1)
        return vector<pair<ll, int>>();
    if (check(a))
        return vector<pair<ll, int>>(1, make_pair(a, 1));
    ll b = factor(a);
    vector<pair<ll, int>> u = shankss_square_forms_factorization(b),
                          v = shankss_square_forms_factorization(a / b), r;
    for (int pu = 0, pv = 0; pu < u.size() || pv < v.size();) {
        if (pu == u.size())
            r.push_back(v[pv++]);
        else if (pv == v.size())
            r.push_back(u[pu++]);
        else if (u[pu].first == v[pv].first)
            r.push_back(make_pair(u[pu].first, (u[pu].second + v[pv].second))),
                ++pu, ++pv;
        else if (u[pu].first > v[pv].first)
            r.push_back(v[pv++]);
        else
            r.push_back(u[pu++]);
    }
    return r;
}
} // namespace integer_factorization_3
namespace modular_arithmetic {
template <class T = long long> struct integer {
    integer() : v(0) {}
    integer(T t) : v(t) { wrap_around(); }
    void wrap_around() {
        if (v < 0)
            v = (v % p + p) % p;
        else if (v >= p)
            v %= p;
    }
    auto &operator=(integer<T> a) {
        v = a.v;
        return *this;
    }
    auto operator-() {
        integer<T> a;
        a.v = (v ? p - v : 0);
        return a;
    }
    auto &operator+=(integer<T> a) { return *this = *this + a; }
    auto &operator-=(integer<T> a) { return *this = *this - a; }
    auto &operator*=(integer<T> a) { return *this = *this * a; }
    auto &operator/=(integer<T> a) { return *this = *this / a; }
    auto &operator<<=(T a) { return *this = *this << a; };
    auto &operator>>=(T a) { return *this = *this >> a; };
    friend auto operator/(integer<T> a, integer<T> b) { return a * inverse(b); }
    friend auto operator+(integer<T> a, integer<T> b) {
        integer<T> c;
        c.v = a.v + b.v;
        if (c.v >= a.p)
            c.v -= a.p;
        return c;
    }
    friend auto operator-(integer<T> a, integer<T> b) {
        integer<T> c;
        c.v = a.v - b.v;
        if (c.v < 0)
            c.v += a.p;
        return c;
    }
    friend auto operator*(integer<T> a, integer<T> b) {
        integer<T> c;
        if (typeid(T) == typeid(long long))
            c.v = (a.v * b.v -
                   (long long)(((long double)a.v * b.v + 0.5) / a.p) * a.p +
                   a.p) %
                  a.p;
        else if (typeid(T) == typeid(int))
            c.v = (long long)a.v * b.v % a.p;
        else
            c.v = a.v * b.v % a.p;
        return c;
    }
    friend bool operator==(integer<T> a, integer<T> b) { return a.v == b.v; }
    friend bool operator!=(integer<T> a, integer<T> b) { return a.v != b.v; }
    friend bool operator<(integer<T> a, integer<T> b) { return a.v < b.v; };
    friend bool operator<=(integer<T> a, integer<T> b) { return a.v <= b.v; };
    friend bool operator>(integer<T> a, integer<T> b) { return a.v > b.v; };
    friend bool operator>=(integer<T> a, integer<T> b) { return a.v >= b.v; };
    T v;
    static T p;
    static mt19937 g_32;
    static mt19937_64 g_64;
    static vector<integer<T>> inverse_cache, factorial_cache;
};
template <class T> T integer<T>::p = 1e9 + 7;
template <class T> mt19937 integer<T>::g_32(random_device{}());
template <class T> mt19937_64 integer<T>::g_64(random_device{}());
template <class T> vector<integer<T>> integer<T>::inverse_cache(2, T(1));
template <class T> vector<integer<T>> integer<T>::factorial_cache(1, T(1));
template <class T> auto &operator>>(istream &s, integer<T> &a) {
    s >> a.v;
    a.wrap_around();
    return s;
}
template <class T> auto &operator<<(ostream &s, integer<T> a) {
    return s << a.v;
}
template <class T> auto pow(integer<T> a, T b) {
    integer<T> r(1);
    for (; b; b >>= 1, a = a * a)
        if (b & 1)
            r = r * a;
    return r;
}
template <class T> integer<T> inverse(T a) { return inverse(integer<T>(a)); }
template <class T> integer<T> inverse(integer<T> a) {
    assert(a.v);
    if (a.v < integer<T>::inverse_cache.size())
        return integer<T>::inverse_cache[a.v];
    return pow(a, a.p - 2);
}
template <class T> auto inverse_cached(T a) {
    return inverse_cached(integer<T>(a));
}
template <class T> auto inverse_cached(integer<T> a) {
    assert(a.v);
    auto &t = integer<T>::inverse_cache;
    while (t.size() <= a.v) {
        t.push_back(integer<T>(-integer<T>::p / T(t.size())) *
                    t[integer<T>::p % t.size()]);
    }
    return t[a.v];
}
template <class T> auto operator<<(integer<T> a, T b) {
    return a * pow(integer<T>(2), b);
}
template <class T> auto operator>>(integer<T> a, T b) {
    return a / pow(integer<T>(2), b);
}
// Not tested.
template <class T> auto random() {
    if (typeid(T) == typeid(long long))
        return integer<T>::g_64() % integer<T>::p;
    else if (typeid(T) == typeid(int))
        return integer<T>::g_32() % integer<T>::p;
    else
        assert(0);
}
// Not tested.
template <class T> auto sqrt(integer<T> a) {
    vector<integer<T>> r;
    if (!a.v)
        r.push_back(decltype(r)(0));
    else if (pow(a, a.p - 1 >> 1).v == 1) {
        int s = a.p - 1, t = 0;
        integer<T> b = 1;
        for (; pow(b, a.p - 1 >> 1).v != a.p - 1; b = integer<T>::random())
            ;
        for (; s % 2 == 0; ++t, s /= 2)
            ;
        integer<T> x = pow(a, (s + 1) / 2), e = pow(a, s);
        for (int i = 1; i < t; ++i, e = x * x / a)
            if (pow(e, 1 << t - i - 1).v != 1)
                x = x * pow(b, (1 << i - 1) * s);
        r.push_back(x);
        r.push_back(-x);
    }
    return r;
}
template <class T> auto factorial(T a) {
    assert(a >= 0);
    if (a < integer<T>::factorial_cache.size())
        return integer<T>::factorial_cache[a];
    integer<T> r(1);
    for (auto i = 1; i <= a; ++i)
        r *= i;
    return r;
}
template <class T> auto factorial_cached(T a) {
    assert(a >= 0);
    auto &t = integer<T>::factorial_cache;
    while (a >= t.size())
        t.push_back(t.back() * t.size());
    return t[a];
}
template <class T> auto binary_coefficient(T n, T k) {
    assert(n >= 0 && k >= 0);
    if (n < k)
        return integer<T>();
    return factorial(n) / factorial(k) / factorial(n - k);
}
} // namespace modular_arithmetic
int main() {
    fast, prec(12);
    many {
        in(x);
        in(y);
        using inte = modular_arithmetic::integer<int>;
        inte ans = 1;
        ans <<= y - 1;
        modular_arithmetic::factorial_cached(30 + y);
        for (auto [p, k] :
             integer_factorization_3::shankss_square_forms_factorization(x)) {
            ans *= modular_arithmetic::binary_coefficient(k + y - 1, y - 1);
        }
        cout << ans << endl;
    }
    return 0;
}
