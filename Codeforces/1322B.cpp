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
#define appl(f, a) for (auto i = begin(a); i != end(a); f, ++i)
#define rang(a) begin(a), end(a)
#define gene template <class T>
#define elif else if
#define intm modular_arithmetic::integer
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
    return (a > 0 && b > 0 || a < 0 && b < 0) ? abs(a) / abs(b)
                                              : -(abs(a) + abs(b) - 1) / abs(b);
}
gene T ceil(const T &a, const T &b) {
    assert(b != 0);
    return (a > 0 && b > 0 || a < 0 && b < 0) ? (abs(a) + abs(b) - 1) / abs(b)
                                              : -abs(a) / abs(b);
}
gene bool tmin(T &a, T b) { return b < a ? a = b, true : false; }
gene bool tmax(T &a, T b) { return b > a ? a = b, true : false; }
#if __cplusplus >= 201402L
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
// The templates end here.
namespace radix_sort {
void radix_sort(unsigned *a, int len) {
    unsigned *b = (unsigned *)malloc(sizeof(unsigned) * len);
    int sum[256] = {0}, sum1[256] = {0}, sum2[256] = {0}, sum3[256] = {0};
    for (int i = 0; i < len; i++) {
        ++sum[a[i] & 255];
        ++sum1[(a[i] >> 8) & 255];
        ++sum2[(a[i] >> 16) & 255];
        ++sum3[a[i] >> 24];
    }
    for (int q = 1; q <= 255; ++q) {
        sum[q] += sum[q - 1];
        sum1[q] += sum1[q - 1];
        sum2[q] += sum2[q - 1];
        sum3[q] += sum3[q - 1];
    }
    for (int q = len - 1; q >= 0; --q)
        b[--sum[a[q] & 255]] = a[q];
    for (int q = len - 1; q >= 0; --q)
        a[--sum1[(b[q] >> 8) & 255]] = b[q];
    for (int q = len - 1; q >= 0; --q)
        b[--sum2[(a[q] >> 16) & 255]] = a[q];
    for (int q = len - 1; q >= 0; --q)
        a[--sum3[b[q] >> 24]] = b[q];
    free(b);
    return;
}
void radix_sort(float *ar, int len) {
    unsigned *a = (unsigned *)ar;
    unsigned *BUF = (unsigned *)malloc(sizeof(unsigned) * (len + 1)),
             *b = BUF + 1;
    *(float *)BUF = 1.0; // guard
    int sum[256] = {0}, sum1[256] = {0}, sum2[256] = {0}, sum3[256] = {0};
    for (int i = 0; i < len; i++) {
        ++sum[a[i] & 255];
        ++sum1[(a[i] >> 8) & 255];
        ++sum2[(a[i] >> 16) & 255];
        ++sum3[a[i] >> 24];
    }
    for (int q = 1; q <= 255; ++q) {
        sum[q] += sum[q - 1];
        sum1[q] += sum1[q - 1];
        sum2[q] += sum2[q - 1];
        sum3[q] += sum3[q - 1];
    }
    for (int q = len - 1; q >= 0; --q)
        b[--sum[a[q] & 255]] = a[q];
    for (int q = len - 1; q >= 0; --q)
        a[--sum1[(b[q] >> 8) & 255]] = b[q];
    for (int q = len - 1; q >= 0; --q)
        b[--sum2[(a[q] >> 16) & 255]] = a[q];
    for (int q = len - 1; q >= 0; --q)
        a[--sum3[b[q] >> 24]] = b[q];
    memcpy(b, a, sizeof(unsigned) * len);
    int beg = len - 1, q = beg;
    for (; b[q] & 0x80000000; --q)
        a[beg - q] = b[q];
    memcpy(a + beg - q, b, sizeof(unsigned) * (q + 1));
    free(BUF);
    return;
}
template <class T> void radix_sort(T &a) {
    if (a.size())
        radix_sort(&a[0], a.size());
}
} // namespace radix_sort
int n;
vi a;
int calc(int k) {
    vector<unsigned> a0, a1;
    for (auto v : a) {
        if ((v >> k) & 1)
            a1.push_back(v % (1 << k));
        else
            a0.push_back(v % (1 << k));
    }
    radix_sort::radix_sort(a0);
    radix_sort::radix_sort(a1);
    /// ou("START");
    /// ou(k);
    /// ou(a0);
    // ou(a1);
    int ans = 0;
    int p = a0.size();
    lv(i, a0) {
        // a[j]+a[i]>=(1<<k)
        // a[j]>=(1<<k)-a[i];
        while (p && a0[p - 1] + a0[i] >= (1 << k))
            --p;
        int j = p;
        if (j <= i)
            j = i + 1;
        int cnt = a0.size() - j;
        // ou(cnt, "CNT");
        ans ^= cnt % 2;
    }
    p = a1.size();
    lv(i, a1) {
        // a[j]+a[i]>=(1<<k)
        // a[j]>=(1<<k)-a[i];
        while (p && a1[p - 1] + a1[i] >= (1 << k))
            --p;
        int j = p;
        if (j <= i)
            j = i + 1;
        int cnt = a1.size() - j;
        ans ^= cnt % 2;
    }
    p = a1.size();
    lv(i, a0) {
        // a[i]+a[j]<(1<<k)
        // a[j]<(1<<k)-a[i]
        while (p && a1[p - 1] + a0[i] >= (1 << k))
            --p;
        int j = p;
        int cnt = j;
        ans ^= cnt % 2;
    }
    // ou("END");
    assert(ans <= 1);
    return ans;
}
int calc2() {
    int ans = 0;
    lv(i, a) lv(j, a) if (i < j) ans ^= a[i] + a[j];
    return ans;
}
int main() {
    fast, prec(12);
    in(n);
    a.resize(n);
    in(a);
    int tmp = max(a) * 2;
    int maxl = 0;
    while (tmp)
        tmp /= 2, ++maxl;
    int ans = 0;
    lp(i, 0, maxl - 1) ans += (calc(i) << i);
    ou(ans);
    // ou(calc2());
    return 0;
}
