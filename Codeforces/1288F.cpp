#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
#define many for (int T = -1; T < 0 && cin >> T, T--;)
#define rang(a) begin(a), end(a)
#define gene template <class T>
#pragma GCC optimize("O3")
using namespace std;
using namespace __gnu_pbds;
gene void sort(vector<T> &a) { sort(rang(a)); }
gene void reve(vector<T> &a) { reverse(rang(a)); }
gene void uniq(vector<T> &a) { sort(a), a.erase(unique(rang(a)), end(a)); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
gene T min(const vector<T> &a) { return *min_element(rang(a)); }
gene T max(const vector<T> &a) { return *max_element(rang(a)); }
gene T sum(const vector<T> &a) { return accumulate(rang(a), 0); }
gene T inf() { return numeric_limits<T>::max(); }
gene int updl(T &a, T b) { return b < a ? a = b, 1 : 0; }
gene int updg(T &a, T b) { return b > a ? a = b, 1 : 0; }
gene using bbst =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
gene auto &operator>>(istream &s, pair<T, T> &a) {
    return s >> a.first >> a.second;
}
gene auto &operator>>(istream &s, vector<T> &a) {
    for (int i = -1; i < 0 && (!a.size() && (cin >> i, a.resize(i), 0), i = 0),
             i < a.size();)
        s >> a[i++];
    return s;
}
gene auto &operator<<(ostream &s, const pair<T, T> &a) {
    return s << '(' << a.first << ", " << a.second << ')';
}
gene auto &operator<<(ostream &s, const vector<T> &a) {
    lv(i, a) cout << a[i] << (i + 1 == a.size() ? "" : " ");
    return s;
}
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
        swap(mp[l], md[e]);
        ma[mp[l]] = l;
        ma[md[e]] = -1;
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
            a[n + 1][m + 1] = -1, p = m + 1;
            pivot(l, m + 1);
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
    fast, prec(12);
    int n1, n2, m, r, b;
    cin >> n1 >> n2 >> m >> r >> b;
    int num_vars = m * 2;
    int num_cons = 0;
    num_cons += 2 * m; // e_c>=0
    num_cons += 2 * m; // 1-e_c>=0;
    num_cons += m;     // 1-sigma e_c>=0;
    num_cons += n1;
    num_cons += n2;
    //(5m+n1+n2)*(2m)=7*200*400=0.56m
    linear_programming::simplex_algorithm sa(num_cons, num_vars);
    // e*2-1 red e*2 blue
    int cur_cons = 0;
    lp(i, 1, m) {
        sa[{++cur_cons, 2 * i - 1}] = 1;
        sa[{++cur_cons, 2 * i}] = 1;
        sa[{++cur_cons, 2 * i - 1}] = -1;
        sa[{cur_cons, 0}] = 1;
        sa[{++cur_cons, 2 * i}] = -1;
        sa[{cur_cons, 0}] = 1;
        sa[{++cur_cons, 2 * i}] = -1;
        sa[{cur_cons, 2 * i - 1}] = -1;
        sa[{cur_cons, 0}] = 1;
    }
    assert(cur_cons == 5 * m);
    string color, cc1, cc2;
    cin >> cc1 >> cc2;
    color = " " + cc1 + cc2;
    assert(color.size() == n1 + n2 + 1);
    static vector<int> nei[410];
    lp(i, 1, m) {
        in(u);
        in(v);
        nei[u].push_back(i);
        nei[v + n1].push_back(i);
    }
    lp(i, 1, m) {
        sa[{0, i * 2 - 1}] = -r;
        sa[{0, i * 2}] = -b;
    }
    lp(i, 1, n1 + n2) {
        ++cur_cons;
        if (color[i] == 'U')
            continue;
        else if (color[i] == 'R') {
            sa[{cur_cons, 0}] = -1;
            for (auto j : nei[i])
                sa[{cur_cons, j * 2 - 1}] = 1, sa[{cur_cons, j * 2}] = -1;
        } else {
            sa[{cur_cons, 0}] = -1;
            for (auto j : nei[i])
                sa[{cur_cons, j * 2 - 1}] = -1, sa[{cur_cons, j * 2}] = 1;
        }
    }
    assert(cur_cons == num_cons);
    auto result = sa.run();
    if (!result.size())
        ou(-1);
    else {
        int ans1 = round(-result[0]);
        cout << ans1 << endl;
        lp(i, 1, m) {
            if (round(result[i * 2 - 1])) {
                cout << 'R';
            } else if (round(result[i * 2])) {
                cout << "B";
            } else
                cout << "U";
        }
        ou("");
    }
    return 0;
}