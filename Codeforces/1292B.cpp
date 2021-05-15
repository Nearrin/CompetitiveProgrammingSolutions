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
#define endl '\n'
#define asse assert
using namespace std;
using namespace __gnu_pbds;
gene T inf() { return numeric_limits<T>::max(); }
gene int tmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
gene int tmax(T &a, T b) { return b > a ? a = b, 1 : 0; }
gene auto min(const T &a) { return *min_element(rang(a)); }
gene auto max(const T &a) { return *max_element(rang(a)); }
gene auto sum(const T &a) { return accumulate(rang(a), 0); }
gene auto gath(const T &a, const vector<int> &b) {
    vector<typename T::value_type> r;
    for (auto i : b)
        r.push_back(a[i]);
    return r;
}
gene void sort(T &a) { sort(rang(a)); }
gene void reve(T &a) { reverse(rang(a)); }
gene void uniq(T &a) { sort(a), a.erase(unique(rang(a)), end(a)); }
gene void shuf(T &a) { random_shuffle(rang(a)); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
#if __cplusplus >= 201703L
template <typename... T> void in(T &... a) { ((cin >> a), ...); }
template <typename... T> void ou(T... a) { ((cout << a << ' '), ...); }
#endif
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
ll calc(pair<ll, ll> p1, pair<ll, ll> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}
int main() {
    fast, prec(12);
    ll x0, y0, ax, ay, bx, by;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    ll xs, ys, t;
    cin >> xs >> ys >> t;
    vector<pair<ll, ll>> points;
    for (ll x = x0, y = y0; x <= xs + t && y <= ys + t;
         x = ax * x + bx, y = ay * y + by)
        points.emplace_back(x, y);
    int ans = 0;
    if (points.size() != 0) {
        for (int i = 0; i < points.size(); ++i)
            for (int j = i; j < points.size(); ++j)
                lp(k, i, j) {
                    // s->k->i->j
                    ll cost = 0;
                    cost += calc(points[k], {xs, ys});
                    cost += calc(points[k], points[i]);
                    cost += calc(points[j], points[i]);
                    if (cost <= t)
                        tmax(ans, j - i + 1);
                    // s->k->j->i
                    cost = 0;
                    cost += calc(points[k], {xs, ys});
                    cost += calc(points[k], points[j]);
                    cost += calc(points[j], points[i]);
                    if (cost <= t)
                        tmax(ans, j - i + 1);
                }
    }
    cout << ans << endl;
    return 0;
}
