#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
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
#define intm modular_arithmetic::integer<int>
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
gene bool tmin(T &a, T b) { return b < a ? a = b, true : false; }
gene bool tmax(T &a, T b) { return b > a ? a = b, true : false; }
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
namespace directed_cycle {
struct directed_cycle {
    directed_cycle(int _n) : n(_n), to(n) {}
    void add_edge(int u, int v) { to.at(u).push_back(v); }
    bool dfs(int u, vector<bool> &in_stack, vector<int> &stack,
             vector<bool> &visited) {
        if (!visited[u]) {
            in_stack[u] = visited[u] = 1, stack.push_back(u);
            for (auto v : to[u])
                if (in_stack[v] && v != stack[stack.size() - 2]) {
                    stack.erase(begin(stack),
                                find(begin(stack), end(stack), v));
                    return true;
                } else if (dfs(v, in_stack, stack, visited))
                    return true;
            in_stack[u] = 0, stack.pop_back();
        }
        return false;
    }
    auto run() {
        vector<bool> in_stack(n), visited(n);
        vector<int> stack;
        stack.reserve(n);
        for (int u = 0; u < n; ++u)
            if (dfs(u, in_stack, stack, visited))
                return stack;
        return stack;
    }
    int n;
    vector<vector<int>> to;
};
} // namespace directed_cycle
// The templates end here.
int main() {
    fast, prec(12);
    many {
        directed_cycle::directed_cycle dc(26);
        string s;
        cin >> s;
        set<pii> st;
        vi cnt(26);
        for (int i = 0; i + 1 < s.size(); ++i) {
            int u = s[i] - 'a', v = s[i + 1] - 'a';
            if (!st.count(make_pair(u, v))) {
                dc.add_edge(u, v);
                dc.add_edge(v, u);
                st.insert(make_pair(u, v));
                st.insert(make_pair(v, u));
                ++cnt[u], ++cnt[v];
            }
        }
        auto circle = dc.run();
        string ans;
        vi vis(26);
        function<void(int, int)> dfs = [&vis, &dfs, &dc, &ans](int u, int p) {
            vis[u] = 1;
            ans.push_back('a' + u);
            for (auto v : dc.to[u])
                if (v != p) {
                    dfs(v, u);
                }
        };
        // ou(circle, "-----", cnt);
        if (circle.empty() && max(cnt) <= 2) {
            lp(i, 0, 25) {
                if (vis[i])
                    continue;
                if (cnt[i] <= 1)
                    dfs(i, -1);
            }
            ou("YES");
            assert(ans.size() == 26);
            ou(ans);
        } else {
            ou("NO");
        }
    }
    return 0;
}
