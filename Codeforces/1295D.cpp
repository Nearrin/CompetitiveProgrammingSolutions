#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#define lp(i, l, r) for (int i = l; i <= int(r); ++i)
#define rp(i, r, l) for (int i = int(r); i >= l; --i)
#define ls(i, s) for (int i = 0; s[i]; ++i)
#define rs(i, s) for (int i = strlen(s) - 1; i >= 0; --i)
#define lv(i, a) for (int i = 0; i < int(a.size()); ++i)
#define rv(i, a) for (int i = int(a.size()) - 1; i >= 0; --i)
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define prec(a) cout << setprecision(a) << fixed
#define freo freopen
#define many for (int T = -1; T < 0 && cin >> T, T--;)
#define appl(f, a) for (auto i = begin(a); i != end(a); f, ++i)
#define rang(a) begin(a), end(a)
#define tstr(a) to_string(a)
#define gene template <class T>
#define elif else if
#ifndef LOCAL
#define endl '\n'
#define assert
#endif
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef string str;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
gene T rint(T l, T r) { return uniform_int_distribution<T>(l, r)(rng); }
template <class T = int> T inf() { return numeric_limits<T>::max(); }
gene bool tmin(T &a, T b) { return b < a ? a = b, true : false; }
gene bool tmax(T &a, T b) { return b > a ? a = b, true : false; }
#if __cplusplus >= 201402L
gene auto min(const T &a) { return *min_element(rang(a)); }
gene auto max(const T &a) { return *max_element(rang(a)); }
gene auto sum(const T &a) { return accumulate(rang(a), 0); }
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
template <class T, class C = less<typename T::value_type>>
void sort(T &a, C c = C()) {
    sort(rang(a), c);
}
gene void reve(T &a) { reverse(rang(a)); }
gene void uniq(T &a) { sort(a), a.erase(unique(rang(a)), end(a)); }
gene void shuf(T &a) { shuffle(rang(a), rng); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
#if __cplusplus >= 201703L
template <typename... T> void in(T &... a) { ((cin >> a), ...); }
template <typename A, typename... B> void ou(const A &a, const B &... b) {
    cout << a, ((cout << ' ' << b), ...), cout << endl;
}
#endif
template <class F, class S> istream &operator>>(istream &s, pair<F, S> &a) {
    return s >> a.first >> a.second;
}
template <class F, class S>
ostream &operator<<(ostream &s, const pair<F, S> &a) {
    return s << '(' << a.first << ", " << a.second << ')';
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
gene using bbst =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
gene using heap = __gnu_pbds::priority_queue<T, greater<T>, pairing_heap_tag>;
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
namespace integer_factorization_1 {
template <class T> auto trivial_division(T n) {
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
#ifdef LOCAL
long long multiply(long long a, long long b, const long long &c) {
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
    if (a < 4759123141ll)
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
template <class T> T rho(T a, T c) {
    T x = double(rand()) / RAND_MAX * (a - 1), y = x;
    for (int i = 1, k = 2;;) {
        x = (multiply(x, x, a) + c) % a;
        T d = __gcd(abs(y - x), a);
        if (d != 1 && d != a)
            return d;
        if (y == x)
            return a;
        if (++i == k)
            y = x, k = 2 * k;
    }
}
template <class T> auto pollards_rho_algorithm(T a) {
    if (a == 1)
        return vector<pair<T, int>>();
    if (miller_rabin_primality_test(a))
        return vector<pair<T, int>>(1, make_pair(a, 1));
    T b = a;
    while ((b = rho(b, T(double(rand()) / RAND_MAX * (a - 1)))) == a)
        ;
    vector<pair<T, int>> u = pollards_rho_algorithm(b),
                         v = pollards_rho_algorithm(a / b), r;
    for (int pu = 0, pv = 0; pu < int(u.size()) || pv < int(v.size());) {
        if (pu == int(u.size()))
            r.push_back(v[pv++]);
        else if (pv == int(v.size()))
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
#ifdef LOCAL
long long multiply(long long a, long long b, const long long &c) {
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
template <class T> T isqrt(const T &x) {
    T ret = T(sqrtl(x));
    while (ret > 0 && ret * ret > x)
        --ret;
    while (x - ret * ret > 2 * ret)
        ++ret;
    return ret;
}
template <class T> T icbrt(const T &x) {
    T ret = T(cbrt(x));
    while (ret > 0 && ret * ret * ret > x)
        --ret;
    while (x - ret * ret * ret > 3 * ret * (ret + 1))
        ++ret;
    return ret;
}
uint64_t squfof_iter(uint64_t const &x, uint64_t const &k,
                     uint64_t const &it_max, uint32_t cutoff_div) {
    if (__gcd((uint64_t)k, x) != 1)
        return __gcd((uint64_t)k, x);
    vector<uint16_t> saved;
    uint64_t scaledn = k * x;
    if (scaledn >> 62)
        return 1;
    uint32_t sqrtn = uint32_t(isqrt(scaledn));
    uint32_t cutoff = isqrt(2 * sqrtn) / cutoff_div;
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
            sqrtq = (uint32_t)isqrt(q0);
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
uint64_t squfof(uint64_t const &x) {
    static array<uint32_t, 16> multipliers{
        1,          3,          5,          7,
        11,         3 * 5,      3 * 7,      3 * 11,
        5 * 7,      5 * 11,     7 * 11,     3 * 5 * 7,
        3 * 5 * 11, 3 * 7 * 11, 5 * 7 * 11, 3 * 5 * 7 * 11};
    uint64_t cbrt_x = icbrt(x);
    if (cbrt_x * cbrt_x * cbrt_x == x)
        return cbrt_x;
    for (uint32_t iter_fact = 1; iter_fact < 20000; iter_fact *= 4) {
        for (uint32_t const &k : multipliers) {
            if (numeric_limits<uint64_t>::max() / k <= x)
                continue;
            uint32_t const it_max = iter_fact * 300;
            uint64_t factor = squfof_iter(x, k, it_max, 1);
            if (factor == 1 || factor == x)
                continue;
            return factor;
        }
    }
    return 1;
}
template <class T> vector<T> factorize(T x) {
    vector<T> ret;
    auto trial = [&](uint32_t const &i) {
        while (x % i == 0) {
            x /= i;
            ret.push_back(i);
        }
    };
    trial(2), trial(3);
    for (uint32_t i = 5, j = 2; i < 5000 && i * i <= x; i += j, j = 6 - j)
        trial(i);
    if (x > 1) {
        static stack<T> s;
        s.push(x);
        while (!s.empty()) {
            x = s.top(), s.pop();
            if (!miller_rabin_primality_test(x)) {
                T factor = squfof(x);
                s.push(factor), s.push(x / factor);
            } else {
                ret.push_back(x);
            }
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}
template <class T>
vector<pair<T, int>> shankss_square_forms_factorization(const T &a) {
    vector<pair<T, int>> r;
    for (auto v : factorize(a)) {
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
    fast, prec(12);
    many {
        ll a, m;
        in(a, m);
        ll p = a / gcd(a, m), q = m / gcd(a, m);
        ll ans = 0;
        auto divisors = divisor::divisor_with_mobius_function(
            integer_factorization_2::pollards_rho_algorithm(q));
        for (auto [d, u] : divisors) {
            ll x0;
            if (p % d == 0)
                x0 = 0;
            else
                x0 = d - p % d;
            // x0 + kd<q
            // k<(q-x0)/d
            ll k;
            if ((q - x0) % d == 0)
                k = (q - x0) / d - 1;
            else
                k = (q - x0) / d;
            ll cnt = k + 1;
            ans += u * cnt;
        }
        ou(ans);
    }
    return 0;
}