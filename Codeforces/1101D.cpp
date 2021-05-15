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
namespace tree_diameter {
struct tree_diameter {
    int n;
    vector<vector<int>> to;
    vector<bool> visited;
    vector<int> depth, component;
    int component_number;
    tree_diameter(int _n)
        : n(_n), to(n), visited(n), depth(n), component(n),
          component_number(0) {
        assert(n);
    }
    void clear() {
        for (int i = 0; i < n; ++i)
            to[i].clear(), fill(begin(visited), end(visited), 0);
        component_number = 0;
    }
    void add_edge(int u, int v) {
        to.at(u).push_back(v), to.at(v).push_back(u);
    }
    void bfs(int s) {
        if (!visited[s]) {
            queue<int> q;
            q.push(s), depth[s] = 0, visited[s] = true,
                       component[s] = component_number++;
            while (q.size()) {
                int u = q.front();
                q.pop();
                for (int v : to[u])
                    if (!visited[v])
                        visited[v] = true, q.push(v), depth[v] = depth[u] + 1,
                        component[v] = component_number - 1;
            }
        }
    }
    auto run() {
        for (int s = 0; s < n; ++s)
            bfs(s);
        vector<pair<int, int>> t(component_number, {-1, -1});
        for (int i = 0; i < n; ++i)
            t[component[i]] = max(t[component[i]], {depth[i], i});
        fill(begin(visited), end(visited), 0);
        component_number = 0;
        pair<int, pair<int, int>> result{-1, {-1, -1}};
        for (auto [d, u] : t)
            bfs(u);
        for (int i = 0; i < n; ++i)
            result = max(result, {depth[i], {i, t[component[i]].second}});
        return result;
    }
};
} // namespace tree_diameter
int main() {
    fast, prec(12);
    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    int m = max(a);
    vvi divsors(m + 1);
    lp(i, 2, m) {
        for (int j = i; j <= m; j += i)
            divsors.at(j).push_back(i);
    }
    vector<vpii> edges(m + 1);
    lp(i, 1, n - 1) {
        in(u);
        in(v);
        --u;
        --v;
        // cout << pii{u, v} << endl << flush;
        auto t = gcd(a.at(u), a.at(v));
        edges.at(t).push_back({u, v});
    }
    int ans = 0;
    lp(g, 2, m) {
        if (divsors[g].size() != 1)
            continue; // Didn't see that coming.
        vpii eg;
        for (int i = g; i <= m; i += g)
            for (auto e : edges[i])
                eg.push_back(e);
        if (eg.size() == 0)
            continue;
        unordered_map<int, int> mp;
        for (auto [u, v] : eg) {
            if (!mp.count(u))
                mp[u] = mp.size();
            if (!mp.count(v))
                mp[v] = mp.size();
        }
        // cout << g << " " << mp.size() << endl << flush;
        tree_diameter::tree_diameter td(mp.size());
        for (auto [u, v] : eg) {
            td.add_edge(mp[u], mp[v]);
            // cout << pii{mp[u], mp[v]} << endl;
        }
        if (0 && a[0] == 174459 && a[1] == 40166)
            ;
        else
            tmax(ans, td.run().first);
        if (mp.size() == n)
            break;
    }
    ++ans;
    cout << (m == 1 ? 0 : ans) << endl;
    return 0;
}