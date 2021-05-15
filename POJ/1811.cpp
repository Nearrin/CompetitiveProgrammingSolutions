#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <typeinfo>
#include <utility>
#include <vector>
#define lp(i, l, r) for (int i = l; i <= r; ++i)
#define rp(i, r, l) for (int i = r; i >= l; --i)
#define ls(i, s) for (int i = 0; s[i]; ++i)
#define rs(i, s) for (int i = strlen(s) - 1; i >= 0; --i)
#define lv(i, a) for (int i = 0; i < a.size(); ++i)
#define rv(i, a) for (int i = (int)a.size() - 1; i >= 0; --i)
#define in(a) int a = (cin >> a, a)
#define ou(a) cout << a << endl
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define prec(a) cout << setprecision(a) << fixed
#define many for (int T = -1; T < 0 && cin >> T, T--;)
#define rang(a) begin(a), end(a)
#define gene template <class T>
#define endl '\n'
#pragma GCC optimize("O3")
using namespace std;
gene void sort(vector<T> &a) { sort(rang(a)); }
gene void reve(vector<T> &a) { reverse(rang(a)); }
gene void uniq(vector<T> &a) { sort(a), a.erase(unique(rang(a)), end(a)); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
gene T min(const vector<T> &a) { return *min_element(rang(a)); }
gene T max(const vector<T> &a) { return *max_element(rang(a)); }
gene T sum(const vector<T> &a) { return accumulate(rang(a), 0); }
gene T inf() { return numeric_limits<T>::max(); }
gene int updl(T &a, T b) { return b < a ? a = b, 1 : 0; }
gene int updg(T &a, T b) { return b > a ? a = b, 1 : 0; }
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
template <class F, class S> istream &operator>>(istream &s, pair<F, S> &a) {
    return s >> a.first >> a.second;
}
gene istream &operator>>(istream &s, vector<T> &a) {
    for (int i = -1; i < 0 && (!a.size() && (cin >> i, a.resize(i), 0), i = 0),
             i < a.size();)
        s >> a[i++];
    return s;
}
template <class F, class S>
ostream &operator<<(ostream &s, const pair<F, S> &a) {
    return s << '(' << a.first << ", " << a.second << ')';
}
gene ostream &operator<<(ostream &s, const vector<T> &a) {
    lv(i, a) cout << a[i] << (i + 1 == a.size() ? "" : " ");
    return s;
}
namespace integer_factorization_1 {
template <class T> T integer_factorization_1(T n) {
    vector<pair<T, T>> a;
    for (T i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            T t = 0;
            for (; n % i == 0; n /= i, ++t)
                ;
            a.push_back(make_pair(i, t));
        }
    }
    if (n != 1)
        a.push_back(make_pair(n, 1));
    return a;
}
} // namespace integer_factorization_1
namespace integer_factorization_2 {
template <class T> T multiply(T x, T y, T z) {
    if (typeid(T) == typeid(int))
        return (long long)x * y % z;
    else if (typeid(T) == typeid(long long))
        return (x * y - (T)(((long double)x * y + 0.5) / z) * z + z) % z;
    else
        return x * y % z;
}
template <class T> T pow(T a, T b, T c) {
    T r = 1;
    for (; b; b & 1 ? r = multiply(r, a, c) : 0, b >>= 1, a = multiply(a, a, c))
        ;
    return r;
}
template <class T> int check(T a, int c = 10) {
    if (a == 2)
        return 1;
    if (a % 2 == 0 || a < 2)
        return 0;
    static int pi[] = {2, 7, 61},
               pl[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    if (typeid(T) == typeid(int))
        c = 3;
    else if (typeid(T) == typeid(long long))
        c = 7;
    T u = a - 1, t = 0, p = 1;
    for (; u % 2 == 0; u /= 2, ++t)
        ;
    for (int i = 0; i < c; ++i) {
        if (typeid(T) == typeid(int))
            p = pi[i] % a;
        else if (typeid(T) == typeid(long long))
            p = pl[i] % a;
        else
            p = (p * 29 + 7) % a;
        if (!p || p == 1 || p == a - 1)
            continue;
        T x = pow(p, u, a);
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
template <class T> T gcd(T a, T b) {
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    return b ? gcd(b, a % b) : a;
}
template <class T> T rho(T a, T c) {
    T x = double(rand()) / RAND_MAX * (a - 1), y = x;
    for (int i = 1, k = 2;;) {
        x = (multiply(x, x, a) + c) % a;
        T d = gcd(y - x, a);
        if (d != 1 && d != a)
            return d;
        if (y == x)
            return a;
        if (++i == k)
            y = x, k = 2 * k;
    }
}
template <class T> vector<pair<T, int>> integer_factorization_2(T a) {
    if (a == 1)
        return vector<pair<T, int>>();
    if (check(a))
        return vector<pair<T, int>>(1, make_pair(a, 1));
    T b = a;
    while ((b = rho(b, T(double(rand()) / RAND_MAX * (a - 1)))) == a)
        ;
    vector<pair<T, int>> u = integer_factorization_2(b),
                         v = integer_factorization_2(a / b), r;
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
} // namespace integer_factorization_2
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
vector<pair<ll, int>> integer_factorization_3(const ll &a) {
    assert(a <= 3689348814694258326ll);
    if (a == 1)
        return vector<pair<ll, int>>();
    if (check(a))
        return vector<pair<ll, int>>(1, make_pair(a, 1));
    ll b = factor(a);
    vector<pair<ll, int>> u = integer_factorization_3(b),
                          v = integer_factorization_3(a / b), r;
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
int main() {
    fast, prec(12);
    many {
        ll n;
        cin >> n;
        ll t =
            integer_factorization_3::integer_factorization_3(n).front().first;
        if (t == n) {
            cout << "Prime" << endl;
        } else {
            cout << t << endl;
        }
    }
    return 0;
}