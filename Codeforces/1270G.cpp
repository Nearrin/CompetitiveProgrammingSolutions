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
#pragma GCC optimize("O3")
using namespace std;
using namespace __gnu_pbds;
gene void sort(T &a) { sort(rang(a)); }
gene void reve(T &a) { reverse(rang(a)); }
gene void uniq(T &a) { sort(a), a.erase(unique(rang(a)), end(a)); }
gene void shuf(T &a) { random_shuffle(rang(a)); }
gene auto min(const T &a) { return *min_element(rang(a)); }
gene auto max(const T &a) { return *max_element(rang(a)); }
gene auto sum(const T &a) { return accumulate(rang(a), 0); }
gene auto gath(const T &a, const vector<int> &b) {
    vector<typename T::value_type> r;
    for (auto i : b)
        r.push_back(a[i]);
    return r;
}
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
gene T inf() { return numeric_limits<T>::max(); }
gene int tmax(T &a, T b) { return b < a ? a = b, 1 : 0; }
gene int tmin(T &a, T b) { return b > a ? a = b, 1 : 0; }
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
namespace direct_cycle {
struct direct_cycle {
    direct_cycle(int _n) : n(_n), to(n) {}
    void add_edge(int u, int v) {
        assert(v >= 0 && v < n), to.at(u).push_back(v);
    }
    bool dfs(int u, vector<bool> &in_stack, vector<int> &stack,
             vector<bool> &visited) {
        if (!visited[u]) {
            in_stack[u] = visited[u] = 1, stack.push_back(u);
            for (auto v : to[u])
                if (in_stack[v]) {
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
} // namespace direct_cycle
int main() {
    fast, prec(12);
    many {
        vi a;
        cin >> a;
        // i-a[i]->i
        direct_cycle::direct_cycle dc(a.size());
        lv(i, a) dc.add_edge(i - a[i], i);
        auto cy = dc.run();
        cout << cy.size() << endl;
        // cout << gath(a, cy) << endl;
        appl(*i += 1, cy);
        cout << cy << endl;
    }
    return 0;
}