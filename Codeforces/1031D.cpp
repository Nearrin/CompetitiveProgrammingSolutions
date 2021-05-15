#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#define lp(i, l, r) for (int i = l; i <= r; ++i)
#define rp(i, r, l) for (int i = r; i >= l; --i)
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
gene auto gath(const T &a, const vector<int> &b) {
    vector<typename T::value_type> r;
    for (auto i : b)
        r.push_back(a[i]);
    return r;
}
#endif
gene void sort(T &a) { sort(rang(a)); }
gene void reve(T &a) { reverse(rang(a)); }
gene void uniq(T &a) { sort(a), a.erase(unique(rang(a)), end(a)); }
gene void shuf(T &a) { random_shuffle(rang(a)); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
#if __cplusplus >= 201703L
template <typename... T> void in(T &... a) { ((cin >> a), ...); }
template <typename... T> void ou(T... a) { ((cout << a << ' '), ...) << '\n'; }
#endif
#if __cplusplus >= 201402L
template <class F, class S> auto &operator>>(istream &s, pair<F, S> &a) {
    return s >> a.first >> a.second;
}
template <class F, class S> auto &operator<<(ostream &s, const pair<F, S> &a) {
    return s << '(' << a.first << ", " << a.second << ')';
}
gene auto &operator>>(istream &s, vector<T> &a) {
    for (int i = -1; i < 0 && (!a.size() && (cin >> i, a.resize(i), 0), i = 0),
             i < int(a.size());)
        s >> a[i++];
    return s;
}
gene auto &operator<<(ostream &s, const vector<T> &a) {
    lv(i, a) cout << a[i] << (i + 1 == int(a.size()) ? "" : " ");
    return s;
}
#endif
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
namespace grid_graph {
// Not tested.
auto convert(int x, int y, int n, int m, bool from_zero_indexed,
             bool to_zero_indexed) {
    if (from_zero_indexed)
        assert(x >= 0 && x < n && y >= 0 && y < m);
    else
        assert(x > 0 && x <= n && y >= 0 && y < m);
    return (x - !from_zero_indexed) * m + y + from_zero_indexed -
           to_zero_indexed;
}
// Not tested.
auto convert(int i, int n, int m, bool from_zero_indexed,
             bool to_zero_indexed) {
    if (from_zero_indexed) {
        assert(i >= 0 && i < n * m);
        return make_pair(i / m + !to_zero_indexed, i % m + !to_zero_indexed);
    }
    assert(i > 0 && i <= n * m);
    return make_pair((i - 1) / m + 1 - to_zero_indexed,
                     (i - 1) % m + 1 - to_zero_indexed);
}
auto valid(int x, int y, int n, int m, bool zero_indexed) {
    if (zero_indexed)
        return x >= 0 && x < n && y >= 0 && y < m;
    return x > 0 && x <= n && y > 0 && y <= m;
}
template <class T> auto at(const T &a, const pair<int, int> &p) {
    return a[p.first][p.second];
}
auto neighbours(int x, int y, int n, int m, bool zero_indexed,
                int connectivity) {
    static int d_4[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}},
               d_8[8][2] = {{-1, 0}, {1, 0},  {0, 1}, {0, -1},
                            {-1, 1}, {1, -1}, {1, 1}, {-1, -1}};
    auto d = connectivity == 4 ? d_4 : d_8;
    vector<pair<int, int>> r;
    for (int i = 0; i < connectivity; ++i)
        if (valid(x + d[i][0], y + d[i][1], n, m, zero_indexed))
            r.push_back(make_pair(x + d[i][0], y + d[i][1]));
    return r;
}
} // namespace grid_graph
int main() {
    fast, prec(12);
    static char a[2010][2010];
    static int cur[2010][2010];
    static int live[2010][2010];
    int n, k;
    in(n, k);
    lp(i, 1, n) cin >> (a[i] + 1);
    cur[1][1] = k;
    lp(l, 2, 2 * n) {
        lp(i, 1, l - 1) {
            int j = l - i;
            if (i > n || j > n)
                continue;
            if (a[i][j] != 'a' && cur[i][j]) {
                a[i][j] = 'a';
                --cur[i][j];
            }
            if (i != n)
                tmax(cur[i + 1][j], cur[i][j]);
            if (j != n)
                tmax(cur[i][j + 1], cur[i][j]);
        }
    }
    live[1][1] = 1;
    lp(l, 2, 2 * n) {
        char t = 'z' + 1;
        lp(i, 1, l - 1) {
            int j = l - i;
            if (i > n || j > n)
                continue;
            if (!live[i][j])
                continue;
            tmin(t, a[i][j]);
        }
        lp(i, 1, l - 1) {
            int j = l - i;
            if (i > n || j > n)
                continue;
            if (!live[i][j])
                continue;
            if (a[i][j] != t)
                continue;
            // cout << pii{i, j} << endl;
            if (i != n)
                live[i + 1][j] = 1;
            if (j != n)
                live[i][j + 1] = 2;
        }
    }
    vector<char> ans;
    int x = n, y = n;
    while (true) {
        ans.push_back(a[x][y]);
        if (x == 1 && y == 1)
            break;
        assert(live[x][y]);
        if (live[x][y] == 1)
            --x;
        else
            --y;
    }
    rv(i, ans) cout << ans[i];
    cout << endl;
    return 0;
}
