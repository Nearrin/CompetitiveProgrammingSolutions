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
template <class T, class I> auto gath(const T &a, const vector<I> &b) {
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
namespace statistic {
// Not implemented.
template <class T, class C, int K> struct top_k_set {};
template <class T, class V, class C, int K> struct top_k_map {
    top_k_map() {}
    top_k_map(T k, V v) { a.emplace_back(k, v); }
    int size() const { return int(a.size()); };
    auto &operator+=(const top_k_map<T, V, C, K> &b) {
        merge(begin(a), end(a), begin(b.a), end(b.a),
              begin(top_k_map<T, V, C, K>::buffer),
              [](const pair<T, V> &x, const pair<T, V> &y) {
                  return C()(x.first, y.first);
              });
        int t = min(int(a.size() + b.a.size()), K);
        if (int(a.size()) < t)
            a.resize(t);
        copy(begin(top_k_map<T, V, C, K>::buffer),
             begin(top_k_map<T, V, C, K>::buffer) + t, begin(a));
        return *this;
    }
    auto &operator+=(T b) {
        for (auto &i : a)
            i.first += b;
        return *this;
    }
    const pair<T, V> &operator[](int i) { return a[i]; }
    vector<pair<T, V>> a;
    static vector<pair<T, V>> buffer;
};
template <class T, class V, class C, int K>
vector<pair<T, V>> top_k_map<T, V, C, K>::buffer(K * 2);
template <class T, class V, class C, int K>
auto operator+(const top_k_map<T, V, C, K> &a, T b) {
    auto c = a;
    c += b;
    return c;
}
template <class T, class V, class C, int K>
auto operator+(T a, const top_k_map<T, V, C, K> &b) {
    return b + a;
}
template <class T, class V, class C, int K>
auto operator+(const top_k_map<T, V, C, K> &a, const top_k_map<T, V, C, K> &b) {
    auto c = a;
    c += b;
    return c;
}
template <class T, class V, class C, int K>
ostream &operator<<(ostream &s, const top_k_map<T, V, C, K> &a) {
    for (int i = 0; i < int(a.a.size()); ++i)
        cout << '(' << a.a[i].first << ", " << a.a[i].second << ')'
             << (i + 1 == int(a.size()) ? "" : " ");
    return s;
}
} // namespace statistic
using info = statistic::top_k_map<int, int, greater<int>, 1>;
vvi to;
vector<info> down, up;
void build_down(int u, int p) {
    down[u] = info(1, u);
    for (auto v : to[u])
        if (v != p) {
            build_down(v, u);
            down[u] += down[v] + 1;
        }
}
void build_up(int u, int p) {
    if (p == -1)
        up[u] = info(1, u);
    vector<info> ps, ss;
    for (auto v : to[u])
        if (v != p) {
            ps.push_back(down[v]);
            ss.push_back(down[v]);
        }
    lp(i, 1, ps.size() - 1) ps[i] += ps[i - 1];
    rp(i, ss.size() - 2, 0) ss[i] += ss[i + 1];
    int cur = 0;
    for (auto v : to[u])
        if (v != p) {
            up[v] = info(1, v) + (up[u] + 1);
            if (cur)
                up[v] += ps[cur - 1] + 2;
            if (cur + 1 != ss.size())
                up[v] += ss[cur + 1] + 2;
            ++cur;
            build_up(v, u);
        }
}
int ans[4];
void update_ans(int u, int p) {
    vpii tmp;
    if (p != -1) {
        tmp.push_back(up[u][0]);
    }
    tmp.emplace_back(1, u);
    tmp.emplace_back(1, u);
    for (auto v : to[u])
        if (v != p) {
            update_ans(v, u);
            tmp.push_back((down[v] + 1)[0]);
        }
    sort(tmp);
    reve(tmp);
    int t = tmp[0].first + tmp[1].first + tmp[2].first - 3;
    if (t > ans[0] && tmp[0].second != tmp[1].second &&
        tmp[0].second != tmp[2].second && tmp[1].second != tmp[2].second) {
        ans[0] = t;
        ans[1] = tmp[0].second + 1;
        ans[2] = tmp[1].second + 1;
        ans[3] = tmp[2].second + 1;
    }
}
int main() {
    fast, prec(12);
    int n;
    cin >> n;
    to.resize(n);
    lp(i, 1, n - 1) {
        int u, v;
        in(u, v);
        --u, --v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    down.resize(n), up.resize(n);
    build_down(0, -1), build_up(0, -1);
    /*
    lp(i, 0, n - 1) {
        cout << i << "\t";
        cout << down[i] << "\t";
        cout << up[i] << endl;
    }*/
    update_ans(0, -1);
    ou(ans[0]);
    ou(ans[1], ans[2], ans[3]);
    return 0;
}
