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
template <class T, class C> void sort(T &a, C c) { sort(rang(a), c); }
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
namespace matroid {
struct colored_matroid {
    colored_matroid(const vector<int> &_color, int _limit = -1)
        : n(int(_color.size())),
          m(*max_element(begin(_color), end(_color)) + 1),
          limit(_limit < 0 ? n : _limit), current_num_colors(0), color(_color),
          in_current(n), color_in_current(m) {
        assert(limit >= 0 && *min_element(begin(_color), end(_color)) >= 0);
    }
    auto current_elements() {
        vector<int> t;
        for (int i = 0; i < n; ++i)
            if (in_current[i])
                t.push_back(i);
        return t;
    }
    auto free_elements() {
        vector<int> t;
        if (current_num_colors < limit)
            for (int i = 0; i < n; ++i)
                if (!in_current[i] && !color_in_current[color[i]])
                    t.push_back(i);
        return t;
    }
    bool can_exchange(int u, int v) {
        assert(in_current[u] && !in_current[v]);
        return color[u] == color[v] || !color_in_current[color[v]];
    }
    void modify(int u, bool t) {
        assert(t ^ in_current[u]), in_current[u] = t;
        bool c = color_in_current[color[u]];
        assert(!t || !c);
        current_num_colors -= c - t, color_in_current[color[u]] = t;
        assert(current_num_colors <= limit);
    }
    int n, m, limit, current_num_colors;
    vector<int> color;
    vector<bool> in_current, color_in_current;
};
// Not implemented.
struct linear_matroid {};
template <int N> struct linear_matroid_z2 {
    linear_matroid_z2(const vector<bitset<N>> &_vector,
                      const vector<bitset<N>> &_additonal = {})
        : n(int(_vector.size())), vect(_vector), additional(_additonal),
          in_current(n), modified(true), damaged(false), basis_excluded(n) {}
    auto current_elements() {
        vector<int> t;
        for (int i = 0; i < n; ++i)
            if (in_current[i])
                t.push_back(i);
        return t;
    }
    auto free_elements() {
        repair();
        vector<int> t;
        if (damaged)
            return t;
        for (int i = 0; i < n; ++i) {
            if (!in_current[i]) {
                auto x = vect[i];
                for (auto &y : basis) {
                    int p = int(y._Find_first());
                    if (x[p])
                        x ^= y;
                }
                if (x.any())
                    t.push_back(i);
            }
        }
        return t;
    }
    bool can_exchange(int u, int v) {
        repair();
        assert(in_current[u] && !in_current[v]);
        if (damaged)
            return false;
        auto x = vect[v];
        for (auto &y : basis_excluded[u]) {
            int t = int(y._Find_first());
            if (x[t])
                x ^= y;
        }
        return x.any();
    }
    auto eliminate(const vector<bitset<N>> &a, int excluded) {
        vector<bitset<N>> b;
        for (int i = 0; i < int(a.size()); ++i)
            if (i != excluded)
                b.push_back(a[i]);
        for (int i = 0; i < int(b.size()); ++i) {
            int t = int(b[i]._Find_first());
            if (t == N) {
                damaged = true;
                continue;
            }
            for (int j = 0; j < int(b.size()); ++j)
                if (j != i && b[j][t])
                    b[j] ^= b[i];
        }
        return b;
    }
    void repair() {
        if (modified) {
            modified = false;
            vector<bitset<N>> t;
            for (int i = 0; i < n; ++i)
                if (!in_current[i])
                    basis_excluded[i].clear();
                else
                    t.push_back(vect[i]);
            for (auto &i : additional)
                t.push_back(i);
            basis = eliminate(t, -1);
            for (int i = 0, j = 0; i < n; ++i)
                if (in_current[i])
                    basis_excluded[i] = eliminate(t, j++);
        }
    }
    void modify(int u, bool t) {
        assert(t ^ in_current[u]), in_current[u] = t, modified = true;
    }
    int n;
    vector<bitset<N>> vect, additional;
    vector<bool> in_current;
    bool modified, damaged;
    vector<vector<bitset<N>>> basis_excluded;
    vector<bitset<N>> basis;
};
template <class A, class B> vector<int> intersection(A &m1, B &m2) {
    assert(m1.n == m2.n);
    int n = m1.n;
    vector<int> parent(n);
    vector<bool> in_y1(n), in_y2(n);
    while (true) {
        fill(begin(parent), end(parent), -2);
        fill(begin(in_y1), end(in_y1), 0), fill(begin(in_y2), end(in_y2), 0);
        queue<int> qu;
        int target = -1;
        for (int u : m1.free_elements())
            in_y1[u] = true, qu.push(u), parent[u] = -1;
        for (int u : m2.free_elements()) {
            if (in_y1[u]) {
                target = u;
                break;
            }
            in_y2[u] = true;
        }
        while (target == -1 && qu.size()) {
            int u = qu.front();
            qu.pop();
            if (in_y2[u]) {
                target = u;
                break;
            }
            for (int v = 0; v < n; ++v) {
                if (parent[v] == -2 &&
                    ((m1.in_current[u] && !m1.in_current[v] &&
                      m1.can_exchange(u, v)) ||
                     (!m1.in_current[u] && m1.in_current[v] &&
                      m2.can_exchange(v, u)))) {
                    parent[v] = u;
                    if (in_y2[v]) {
                        target = v;
                        break;
                    }
                    qu.push(v);
                }
            }
        }
        if (target == -1)
            break;
        for (int i = 1, j = target; j != -1; ++i, j = parent[j])
            if (i % 2 == 0)
                m1.modify(j, 0), m2.modify(j, 0);
        for (int i = 1, j = target; j != -1; ++i, j = parent[j])
            if (i % 2)
                m1.modify(j, 1), m2.modify(j, 1);
    }
    return m1.current_elements();
}
} // namespace matroid
int main() {
    fast, prec(12);
    vector<bitset<60>> addtional;
    int n;
    cin >> n;
    lp(i, 1, n) {
        ll t;
        cin >> t;
        addtional.push_back(t);
    }
    vi color;
    vector<bitset<60>> vect;
    int m;
    cin >> m;
    lp(i, 1, m) {
        int k;
        cin >> k;
        lp(j, 1, k) {
            ll t;
            cin >> t;
            color.push_back(i);
            vect.push_back(t);
        }
    }
    // try swap
    matroid::colored_matroid m1(color);
    matroid::linear_matroid_z2<60> m2(vect, addtional);
    auto ans = matroid::intersection(m2, m1);
    if (ans.size() != m)
        cout << -1 << endl;
    else {
        for (auto i : ans) {
            cout << vect[i].to_ullong() << endl;
        }
    }
    return 0;
}