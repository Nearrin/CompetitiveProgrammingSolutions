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
#define many for (int T = -1; T < 0 && cin >> T, T--;)
#define appl(f, a) for (auto i = begin(a); i != end(a); f, ++i)
#define rang(a) begin(a), end(a)
#define tstr(a) to_string(a)
#define gene template <class T>
#ifndef LOCAL
#define endl '\n'
#define assert
#endif
using namespace std;
using namespace __gnu_pbds;
gene T inf() { return numeric_limits<T>::max(); }
gene int tmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
gene int tmax(T &a, T b) { return b > a ? a = b, 1 : 0; }
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
gene void shuf(T &a) { random_shuffle(rang(a)); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
#if __cplusplus >= 201703L
template <typename... T> void in(T &... a) { ((cin >> a), ...); }
template <typename... T> void ou(T... a) { ((cout << a << ' '), ...) << endl; }
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
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef string str;
namespace segment_decomposition {
template <class T> struct segment {
    segment(T _l, T _r, T _h) : l(_l), r(_r), h(_h) {}
    T l, r, h;
};
template <class T> ostream &operator<<(ostream &s, const segment<T> &a) {
    return s << "[" << a.l << ", " << a.r << "]";
}
template <class T, class K> auto segment_decomposition(T l, T r, K k) {
    vector<segment<T>> s;
    assert(l <= r && k >= 2);
    for (T i = l; i <= r; ++i) {
        T h = 0, d = 1;
        while (i + d * k - 1 <= r && i % (d * k) == 0)
            ++h, d *= k;
        s.push_back(segment(i, i + d - 1, h));
        i += d - 1;
    }
    return s;
}
} // namespace segment_decomposition
int main() {
    fast, prec(12);
    unordered_map<int, int> index;
    lp(i, 1, 2520) if (2520 % i == 0) index[i] = index.size();
    static ll f[21][50][2600];
    int base = 1;
    lp(i, 0, 20) {
        lp(j, 1, 2520) if (2520 % j == 0) lp(k, 0, 2519) {
            if (i == 0) {
                assert(index.count(j));
                f[i][index[j]][k] = (k % j == 0);
            } else {
                lp(t, 0, 9) {
                    int new_g = j * t / gcd(j, t);
                    if (!t)
                        new_g = j;
                    f[i][index[j]][k] +=
                        f[i - 1][index[new_g]][(k + base * t) % 2520];
                }
            }
        }
        if (i)
            base = base * 10 % 2520;
    }
    many {
        ll l, r;
        in(l, r);
        ll ans = 0;
        for (auto s : segment_decomposition::segment_decomposition(l, r, 10)) {
            ll t = s.l / (s.r - s.l + 1);
            int g = 1;
            while (t) {
                if (t % 10)
                    g = g * (t % 10) / gcd(g, t % 10);
                t /= 10;
            }
            ans += f[s.h][index[g]][s.l % 2520];
        }
        ou(ans);
    }
    return 0;
}
