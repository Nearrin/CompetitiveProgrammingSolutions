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
#define many for (int T = -1; T < 0 && cin >> T, T--;)
#define appl(x, f, a)                                                          \
    for (auto &x : a)                                                          \
    f
#define rang(a) begin(a), end(a)
#define gene template <class T>
#define elif else if
#define intm modular_arithmetic::integer
#define bcnt __builtin_popcount
#ifndef LOCAL
#define endl '\n'
#define assert
#endif
using namespace std;
using namespace __gnu_pbds;
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
template <class T = int> T inf() { return numeric_limits<T>::max(); }
gene T floor(const T &a, const T &b) {
    assert(b != 0);
    return (a > 0 && b > 0) || (a < 0 && b < 0)
               ? abs(a) / abs(b)
               : -(abs(a) + abs(b) - 1) / abs(b);
}
gene T ceil(const T &a, const T &b) {
    assert(b != 0);
    return (a > 0 && b > 0) || (a < 0 && b < 0) ? (abs(a) + abs(b) - 1) / abs(b)
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
gene void in(T &a) { cin >> a; }
template <class A, class... B> void in(A &a, B &... b) { cin >> a, in(b...); }
void ou() { cout << endl; }
gene void ou(const T &a) { cout << a << endl; }
template <class A, class... B> void ou(const A &a, const B &... b) {
    cout << a << ' ', ou(b...);
}
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
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef string str;
namespace number_theoretic_transform {
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
template <class T> T power(T a, T b, const T &c) {
    T r = 1;
    for (; b; b & 1 ? r = multiply(r, a, c) : 0, b >>= 1, a = multiply(a, a, c))
        ;
    return r;
}
template <class T>
void transform(vector<T> &a, const int &n, const int &s, const vector<int> &rev,
               const T &p, T g) {
    g = s == 1 ? g : power(g, p - 2, p);
    vector<T> wm;
    for (int i = 0; 1 << i <= n; ++i)
        wm.push_back(power(g, (p - 1) >> i, p));
    for (int i = 0; i < n; ++i)
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
    for (int i = 1, m = 2; 1 << i <= n; ++i, m <<= 1) {
        vector<T> wmk(m >> 1, 1);
        for (int k = 1; k < (m >> 1); ++k)
            wmk[k] = multiply(wmk[k - 1], wm[i], p);
        for (int j = 0; j < n; j += m)
            for (int k = 0; k < (m >> 1); ++k) {
                T u = a[j + k], v = multiply(wmk[k], a[j + k + (m >> 1)], p);
                a[j + k] = u + v;
                a[j + k + (m >> 1)] = u - v + p;
                if (a[j + k] >= p)
                    a[j + k] -= p;
                if (a[j + k + (m >> 1)] >= p)
                    a[j + k + (m >> 1)] -= p;
            }
    }
}
template <class T> auto multiply(vector<T> a, vector<T> b, const T &p) {
    T g = map<T, T>{{998244353, 3}}.at(p);
    int tn = a.size() + b.size() - 1, l = 0, n = 1;
    while (n < tn)
        n *= 2, ++l;
    vector<int> rev(n);
    for (int i = 0; i < n; ++i)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (l - 1));
    a.resize(n), b.resize(n);
    transform(a, n, 1, rev, p, g);
    transform(b, n, 1, rev, p, g);
    for (int i = 0; i < n; ++i)
        a[i] = multiply(a[i], b[i], p);
    transform(a, n, -1, rev, p, g);
    n = power(n, p - 2, p);
    for (T &v : a)
        v = multiply(v, n, p);
    return a.resize(tn), a;
}
template <class T> auto power(vector<T> a, const T &b, const T &p) {
    T g = map<T, T>{{998244353, 3}}.at(p);
    int tn = int(a.size() - 1) * b + 1, l = 0, n = 1;
    while (n < tn)
        n *= 2, ++l;
    vector<int> rev(n);
    for (int i = 0; i < n; ++i)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (l - 1));
    a.resize(n), transform(a, n, 1, rev, p, g);
    for (int i = 0; i < n; ++i)
        a[i] = power(a[i], b, p);
    transform(a, n, -1, rev, p, g);
    n = power(n, p - 2, p);
    for (T &v : a)
        v = multiply(v, n, p);
    return a.resize(tn), a;
}
} // namespace number_theoretic_transform
// The templates end here.
int main() {
    fast, prec(12);
    int n, k;
    in(n, k);
    vector<int> a(10);
    lp(i, 1, k) {
        int t;
        in(t);
        a[t] = 1;
    }
    a = number_theoretic_transform::power(a, n / 2, 998244353);
    int ans = 0;
    for (auto v : a)
        ans = (ans + ll(v) * v % 998244353) % 998244353;
    ou(ans);
    return 0;
}
