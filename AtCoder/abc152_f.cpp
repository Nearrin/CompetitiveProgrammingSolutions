#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#define lp(i, l, r) for (int i = l; i <= r; ++i)
#define rp(i, r, l) for (int i = r; i >= l; --i)
#define ls(i, s) for (int i = 0; s[i]; ++i)
#define rs(i, s) for (int i = strlen(s) - 1; i >= 0; --i)
#define lv(i, a) for (int i = 0; i < int(a.size()); ++i)
#define rv(i, a) for (int i = (int)a.size() - 1; i >= 0; --i)
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
// template <typename... T> void in(T &... a) { ((cin >> a), ...); }
// template <typename... T> void ou(T... a) { ((cout << a << ' '), ...); }
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
vvi to;
vi par;
void dfs(int u) {
    for (auto v : to[u])
        if (v != par[u]) {
            par[v] = u;
            dfs(v);
        }
}
vpii get_edges(int u) {
    vpii result;
    while (par[u] != 0) {
        int v = par[u];
        result.emplace_back(min(u, v), max(u, v));
        u = par[u];
    }
    return result;
}
vpii get_edges(int u, int v) {
    vpii r;
    map<pii, int> cnt;
    for (auto e : get_edges(u))
        ++cnt[e];
    for (auto e : get_edges(v))
        ++cnt[e];
    for (auto t : cnt)
        if (t.second == 1)
            r.push_back(t.first);
    return r;
}
int main() {
    fast, prec(12);
    int n;
    cin >> n;
    to.resize(n + 1);
    par.resize(n + 1);
    map<pii, int> edge_to_idx;
    lp(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
        edge_to_idx[make_pair(min(u, v), max(u, v))] = i;
    }
    dfs(1);
    vector<ll> cons;
    int m;
    cin >> m;
    lp(i, 1, m) {
        int u, v;
        cin >> u >> v;
        auto egs = get_edges(u, v);
        ll msk = 0;
        for (auto e : egs) {
            msk += (1ll << (edge_to_idx[e] - 1));
        }
        cons.push_back(msk);
    }
    // lp(i, 0, m - 1) cout << cons[i] << endl;
    ll total = (1ll << (n - 1));
    ll ill = 0;
    lp(M, 1, (1 << m) - 1) {
        ll msk = 0;
        int siz = 0;
        lp(i, 0, m - 1) {
            if ((M >> i) & 1) {
                msk |= cons[i];
                ++siz;
            }
        }
        int cnt = 0;
        lp(i, 0, n - 2) if ((msk >> i) & 1)++ cnt;
        // cout << siz << " " << cnt << endl;
        // cnt edges must be white
        if (siz & 1) {
            ill += (1ll << (n - 1 - cnt));
        } else {
            ill -= (1ll << (n - 1 - cnt));
        }
    }
    cout << total - ill << endl;
    return 0;
}
/*
50
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 11
11 12
12 13
13 14
14 15
15 16
16 17
17 18
18 19
19 20
20 21
21 22
22 23
23 24
24 25
25 26
26 27
27 28
28 29
29 30
30 31
31 32
32 33
33 34
34 35
35 36
36 37
37 38
38 39
39 40
40 41
41 42
42 43
43 44
44 45
45 46
46 47
47 48
48 49
49 50
20
1 50
1 50
1 50
1 50
1 50
1 50
1 50
1 50
1 50
1 50
1 50
1 50
1 50
1 50
1 50
1 50
1 50
1 50
1 50
1 50
*/