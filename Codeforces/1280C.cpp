#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
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
#define appl(f, a) for (auto i = begin(a); i != end(a); f, ++i)
#define many for (int T = -1; T < 0 && cin >> T, T--;)
#define rang(a) begin(a), end(a)
#define gene template <class T>
#define endl '\n'
#define asse assert
using namespace std;
using namespace __gnu_pbds;
gene void sort(T &a) { sort(rang(a)); }
gene void reve(T &a) { reverse(rang(a)); }
gene void uniq(T &a) { sort(a), a.erase(unique(rang(a)), end(a)); }
gene void shuf(T &a) { random_shuffle(rang(a)); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
gene auto gath(const T &a, const vector<int> &b) {
    vector<typename T::value_type> r;
    for (auto i : b)
        r.push_back(a[i]);
    return r;
}
gene auto min(const T &a) { return *min_element(rang(a)); }
gene auto max(const T &a) { return *max_element(rang(a)); }
gene auto sum(const T &a) { return accumulate(rang(a), 0); }
gene T inf() { return numeric_limits<T>::max(); }
gene int tmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
gene int tmax(T &a, T b) { return b > a ? a = b, 1 : 0; }
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
template <class F, class S> auto &operator>>(istream &s, pair<F, S> &a) {
    return s >> a.first >> a.second;
}
gene auto &operator>>(istream &s, vector<T> &a) {
    for (int i = -1; i < 0 && (!a.size() && (cin >> i, a.resize(i), 0), i = 0),
             i < a.size();)
        s >> a[i++];
    return s;
}
template <class F, class S> auto &operator<<(ostream &s, const pair<F, S> &a) {
    return s << '(' << a.first << ", " << a.second << ')';
}
gene auto &operator<<(ostream &s, const vector<T> &a) {
    lv(i, a) cout << a[i] << (i + 1 == a.size() ? "" : " ");
    return s;
}
ll work_small(const vvi &e) {
    int n = e.size() + 1;
    vector<map<int, int>> to(n);
    for (auto &t : e) {
        int u = t[0], v = t[1], w = t[2];
        to[u][v] = w;
        to[v][u] = w;
    }
    queue<int> qu;
    lp(i, 0, n - 1) {
        if (to[i].size() == 1) {
            qu.push(i);
        }
    }
    vi cnt(n, 1);
    ll ans = 0;
    while (qu.size()) {
        int u = qu.front();
        qu.pop();
        if (to[u].size() == 0) {
            assert(qu.empty());
            break;
        }
        assert(to[u].size() == 1);
        auto [v, w] = *(to[u].begin());
        to[v].erase(u);
        if (to[v].size() == 1)
            qu.push(v);
        if (cnt[u] % 2 == 0) {
        } else {
            cnt[v] += cnt[u];
            ans += w;
        }
    }
    return ans;
}
void dfs(const vvi &to, vi &siz, int u, int p) {
    siz[u] = 1;
    for (auto v : to[u]) {
        if (v == p)
            continue;
        dfs(to, siz, v, u);
        siz[u] += siz[v];
    }
}
ll work_large(const vvi &e) {
    int n = e.size() + 1;
    vi siz(n);
    vvi to(n);
    for (auto &t : e) {
        int u = t[0], v = t[1], w = t[2];
        to[u].push_back(v);
        to[v].push_back(u);
    }
    dfs(to, siz, 0, -1);
    ll ans = 0;
    for (auto &t : e) {
        int u = t[0], v = t[1], w = t[2];
        int s = min(siz[u], siz[v]);
        ans += 1ll * min(s, n - s) * w;
    }
    return ans;
}
int main() {
    fast, prec(12);
    many {
        in(k);
        int n = 2 * k;
        vvi e(n - 1, vi(3));
        lp(i, 0, n - 2) {
            cin >> e[i];
            --e[i][0];
            --e[i][1];
        }
        cout << work_small(e) << " " << work_large(e) << endl;
    }
    return 0;
}
