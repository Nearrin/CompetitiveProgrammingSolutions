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
template <typename... T> void ou(T... a) { ((cout << a << ' '), ...); }
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
namespace linear_programming {
template <class T = double> struct simplex_algorithm {
    const T E;
    int n, m, p;
    vector<int> mp, ma, md;
    vector<vector<T>> a;
    vector<T> result;
    simplex_algorithm(int _n, int _m)
        : n(_n), m(_m), p(0), a(n + 2, vector<T>(m + 2)), mp(n + 1),
          ma(m + n + 2), md(m + 2), result(m + 1), E(1e-8) {}
    T &operator[](const pair<int, int> &i) {
        return a.at(i.first).at(i.second);
    }
    void pivot(int l, int e) {
        swap(mp[l], md[e]), ma[mp[l]] = l, ma[md[e]] = -1;
        double t = -a[l][e];
        a[l][e] = -1;
        vector<int> qu;
        for (int i = 0; i <= m + 1; ++i)
            if (fabs(a[l][i] /= t) > E)
                qu.push_back(i);
        for (int i = 0; i <= n + 1; ++i)
            if (i != l && fabs(a[i][e]) > E) {
                t = a[i][e];
                a[i][e] = 0;
                for (int j = 0; j < qu.size(); ++j)
                    a[i][qu[j]] += a[l][qu[j]] * t;
            }
        if (-p == l)
            p = e;
        else if (p == e)
            p = -l;
    }
    int optimize(int d) {
        for (int l = -1, e = -1;; pivot(l, e), l = -1, e = -1) {
            for (int i = 1; i <= m + 1; ++i)
                if (a[d][i] > E) {
                    e = i;
                    break;
                }
            if (e == -1)
                return 1;
            T t;
            for (int i = 1; i <= n; ++i)
                if (a[i][e] < -E && (l == -1 || a[i][0] / -a[i][e] < t))
                    t = a[i][0] / -a[i][e], l = i;
            if (l == -1)
                return 0;
        }
    }
    vector<T> run() {
        for (int i = 1; i <= m + 1; ++i)
            ma[i] = -1, md[i] = i;
        for (int i = m + 2; i <= m + n + 1; ++i)
            ma[i] = i - (m + 1), mp[i - (m + 1)] = i;
        T t;
        int l = -1;
        for (int i = 1; i <= n; ++i)
            if (l == -1 || a[i][0] < t)
                t = a[i][0], l = i;
        if (t < -E) {
            for (int i = 1; i <= n; ++i)
                a[i][m + 1] = 1;
            a[n + 1][m + 1] = -1, p = m + 1, pivot(l, m + 1);
            if (!optimize(n + 1) || fabs(a[n + 1][0]) > E)
                return vector<T>();
            if (p < 0)
                for (int i = 1; i <= m; ++i)
                    if (fabs(a[-p][i]) > E) {
                        pivot(-p, i);
                        break;
                    }
            for (int i = 0; i <= n; ++i)
                a[i][p] = 0;
        }
        if (!optimize(0))
            return vector<T>();
        result[0] = a[0][0];
        for (int i = 1; i <= m; ++i)
            if (ma[i] != -1)
                result[i] = a[ma[i]][0];
        return result;
    }
};
} // namespace linear_programming
int main() {
    fast, prec(1);
    int n;
    string s, t;
    in(n, s, t);
    static int g[4][4];
    lp(i, 1, 3) {
        lp(j, 1, 3) {
            string tmp{'a' + i - 1, 'a' + j - 1};
            if (tmp != s && tmp != t)
                g[i][j] = 1;
        }
    }
    vvi cycles;
    lp(i, 1, 3) if (g[i][i]) cycles.push_back({i});
    lp(i, 1, 3) lp(j, 1, 3) if (i != j && g[i][j] && g[j][i])
        cycles.push_back({i, j});
    lp(i, 1, 3) lp(j, 1, 3) lp(k, 1, 3) if (i != j && i != k && j != k &&
                                            g[i][j] && g[j][k] && g[k][i])
        cycles.push_back({i, j, k});

    if (cycles.back().size() == 3) {
        cout << "YES" << endl;
        int i = cycles.back()[0], j = cycles.back()[1], k = cycles.back()[2];
        lp(u, 1, n) cout << char('a' + i - 1) << char('a' + j - 1)
                         << char('a' + k - 1);
        cout << endl;
    } else if (s[0] == t[0]) {
        cout << "YES" << endl;
        lp(i, 1, n) cout << s[1];
        lp(i, 1, n) cout << t[1];
        lp(i, 1, n) cout << s[0];
        cout << endl;
    } else if (s[1] == t[1]) {
        cout << "YES" << endl;
        lp(i, 1, n) cout << s[1];
        lp(i, 1, n) cout << t[0];
        lp(i, 1, n) cout << s[0];
        cout << endl;
    } else if (s[0] != 'c' && s[1] != 'c') {
        cout << "YES" << endl;
        lp(i, 1, n) cout << 'a';
        lp(i, 1, n) cout << 'c';
        lp(i, 1, n) cout << 'b';
        cout << endl;
    } else if (s[0] != 'a' && s[1] != 'a') {
        cout << "YES" << endl;
        lp(i, 1, n) cout << 'c';
        lp(i, 1, n) cout << 'a';
        lp(i, 1, n) cout << 'b';
        cout << endl;
    } else {
        cout << "YES" << endl;
        lp(i, 1, n) cout << 'a';
        lp(i, 1, n) cout << 'b';
        lp(i, 1, n) cout << 'c';
        cout << endl;
    }
    if (0) {
        if (n > 1)
            cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            lp(i, 1, 3) lp(j, 1, 3) lp(
                k, 1, 3) if (i != j && i != k && j != k && g[i][j] && g[j][k]) {
                cout << char('a' + i - 1) << char('a' + j - 1)
                     << char('a' + k - 1) << endl;
                goto lb;
            }
        lb:
            1;
        }
    }
    return 0;
    linear_programming::simplex_algorithm sa(cycles.size() + 2 * 3 + 1,
                                             cycles.size() + 1);
    int cur_cons = 0;
    lv(i, cycles) {
        sa.a[++cur_cons][i + 1] = 1;
        sa.a[cur_cons][0] = 0;
    }
    lp(i, 1, 3) {
        ++cur_cons;
        lv(j, cycles) {
            if (find(rang(cycles[j]), i) != cycles[j].end()) {
                sa.a[cur_cons][j + 1] = 1;
            }
        }
        sa.a[cur_cons][cycles.size() + 1] = -1;
    }
    lp(i, 1, 3) {
        ++cur_cons;
        lv(j, cycles) {
            if (find(rang(cycles[j]), i) != cycles[j].end()) {
                sa.a[cur_cons][j + 1] = -1;
            }
        }
        sa.a[cur_cons][cycles.size() + 1] = 1;
    }
    ++cur_cons;
    sa.a[cur_cons][0] = -1;
    sa.a[cur_cons][cycles.size() + 1] = 1;
    assert(cur_cons == cycles.size() + 2 * 3 + 1);
    sa.a[0][cycles.size() + 1] = -1;
    lp(i, 0, cycles.size() + 3 * 2) {
        lp(j, 0, cycles.size() + 1) cout << sa.a[i][j] << " ";
        cout << endl;
    }
    auto result = sa.run();
    cout << -result[0] << endl;
    lp(i, 1, cycles.size()) {
        if (result[i] != 0) {
            cout << cycles[i - 1] << " * " << result[i] << endl;
        }
    }
    return 0;
}
