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
#endif
template <class T> int barr(const T &a, const int &i) { return a >> i & 1; }
template <class T> int bcnt(const T &a) { return __builtin_popcount(a); }
template <> int bcnt(const long long &a) { return __builtin_popcountll(a); }
template <class T> int blen(const T &a) { return a ? 1 + blen(a / 2) : 0; }
mt19937_64 rng(0);
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
namespace segment_coloring {
struct segment_coloring {
    segment_coloring(int n) : next(n + 1) { iota(begin(next), end(next), 0); }
    auto color(int l, int r) {
        vector<int> answer;
        for (int i = walk(l); i <= r; i = walk(i + 1))
            answer.push_back(i), next[i] = i + 1;
        return answer;
    }
    int walk(int i) { return next[i] == i ? i : next[i] = walk(next[i]); }
    vector<int> next;
};
} // namespace segment_coloring
// The templates end here.
int solve(int h, int w, int k, int x1, int y1, int x2, int y2, vector<str> a) {
    // int h, w, k;
    // in(h, w, k);
    auto h_c = vector<segment_coloring::segment_coloring>(
        h, segment_coloring::segment_coloring(w));
    auto w_c = vector<segment_coloring::segment_coloring>(
        w, segment_coloring::segment_coloring(h));
    // int x1, y1, x2, y2;
    // in(x1, y1, x2, y2);
    --x1, --y1, --x2, --y2;
    // vector<str> a(h);
    // in(a);
    auto left = vect<int>(0, h, w);
    lp(i, 0, h - 1) lp(j, 0, w - 1) {
        if (a[i][j] == '@')
            left[i][j] = j;
        else if (j == 0)
            left[i][j] = -1;
        else
            left[i][j] = left[i][j - 1];
    }
    auto right = vect<int>(0, h, w);
    lp(i, 0, h - 1) rp(j, w - 1, 0) {
        if (a[i][j] == '@')
            right[i][j] = j;
        else if (j == w - 1)
            right[i][j] = w;
        else
            right[i][j] = right[i][j + 1];
    }
    auto up = vect<int>(0, h, w);
    lp(j, 0, w - 1) lp(i, 0, h - 1) {
        if (a[i][j] == '@')
            up[i][j] = i;
        else if (i == 0)
            up[i][j] = -1;
        else
            up[i][j] = up[i - 1][j];
    }
    auto down = vect<int>(0, h, w);
    lp(j, 0, w - 1) rp(i, h - 1, 0) {
        if (a[i][j] == '@')
            down[i][j] = i;
        else if (i == h - 1)
            down[i][j] = h;
        else
            down[i][j] = down[i + 1][j];
    }
    auto d = vect<int>(inf(), h, w);
    d[x1][y1] = 0;
    queue<pii> q;
    q.push({x1, y1});
    while (d[x2][y2] == inf() && q.size()) {
        auto t = q.front();
        int x = t.first, y = t.second;
        // ou("v", x, y);
        q.pop();
        vi candidates;
        int yl = max(left[x][y] + 1, y - k);
        int yr = min(right[x][y] - 1, y + k);
        for (auto y3 : h_c[x].color(yl, yr)) {
            // ou("cy", x, y3);
            if (a[x][y3] == '.' && d[x][y3] == inf()) {
                d[x][y3] = d[x][y] + 1;
                q.push({x, y3});
            }
        }
        int xl = max(up[x][y] + 1, x - k);
        int xr = min(down[x][y] - 1, x + k);
        // ou(up[x][y], xl, xr);
        for (auto x3 : w_c[y].color(xl, xr)) {
            // ou("cx", x3, y);
            if (a[x3][y] == '.' && d[x3][y] == inf()) {
                d[x3][y] = d[x][y] + 1;
                q.push({x3, y});
            }
        }
    }
    return (d[x2][y2] == inf() ? -1 : d[x2][y2]);
}
int main() {
    ios::sync_with_stdio(0);
    cout << setprecision(16) << fixed;
    cin.tie(0);
    {
        int h, w, k;
        in(h, w, k);
        int x1, y1, x2, y2;
        in(x1, y1, x2, y2);
        vector<str> a(h);
        in(a);
        ou(solve(h, w, k, x1, y1, x2, y2, a));
        return 0;
    }
    while (1) {
        int h = rint(1, 3), w = rint(1, 3);
        int x1 = rint(1, h), x2 = rint(1, h);
        int y2 = rint(1, w), y1 = rint(1, w);
        vector<str> a(h);
        lv(i, a) {
            lp(j, 0, w - 1) a[i].push_back(rint(1, 10) <= 3 ? '@' : '.');
        }
        a[x1 - 1][y1 - 1] = '.';
        a[x2 - 1][y2 - 1] = '.';
        int k = rint(1, 10);
        ou(h, w, k);
        ou(x1, y1, x2, y2);
        for (auto tmp : a)
            ou(tmp);
        ou(solve(h, w, k, x1, y1, x2, y2, a));
    }
    return 0;
}
