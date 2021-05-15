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
#define endl '\n'
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
namespace fenwick_tree {
// Not tested.
template <class T, int D = 1> struct fenwick_tree {
    fenwick_tree(const vector<int> &_n)
        : n(_n[0]), l(log2(n) + 1e-8), s(n + 1) {
        assert(_n.size() == D);
    }
    void modify(const vector<int> &k, T v) {
        auto j = vector<int>(begin(k) + 1, end(k));
        for (int i = k[0] + 1; i <= n; i += i & -i)
            s[i].modify(j, v);
    }
    T sum(const vector<int> &k) {
        T r = 0;
        auto j = vector<int>(begin(k) + 1, end(k));
        for (int i = k[0] + 1; i; i -= i & -i)
            r += s[i].sum(j);
        return r;
    }
    T sum(int k, const vector<int> &l, const vector<int> &r) {
        T t = 0;
        for (int i = k + 1; i; i -= i & -i)
            t += s[i].sum(l, r);
        return t;
    }
    T sum(const vector<int> &l, const vector<int> &r) {
        auto i = vector<int>(begin(l) + 1, end(l)),
             j = vector<int>(begin(r) + 1, end(r));
        return sum(r[0], l, r) - sum(l[0] - 1, l, r);
    }
    int n, l;
    vector<fenwick_tree<T, D - 1>> s;
};
template <class T> struct fenwick_tree<T, 1> {
    fenwick_tree(const vector<int> &_n)
        : n(_n[0]), l(log2(n) + 1e-8), a(n), s(n + 1) {
        assert(_n.size() == 1);
    }
    fenwick_tree(int _n) : n(_n), l(log2(n) + 1e-8), a(n), s(n + 1) {}
    void modify(int k, T v) {
        assert(k >= 0 && k < n);
        for (v -= a[k], a[k++] += v; k <= n; k += k & -k)
            s[k] += v;
    }
    T sum(int k) {
        assert(k >= 0 && k < n);
        T r = 0;
        for (++k; k; k -= k & -k)
            r += s[k];
        return r;
    }
    T sum(const vector<int> &l, const vector<int> &r) {
        assert(l.size() == 1 && r.size() == 1);
        return sum(r[0]) - sum(l[0] - 1);
    }
    T sum(int l, int r) { return sum(r) - sum(l - 1); }
    int kth(T k) {
        int r = 0;
        for (int i = 1 << l; i; i >>= 1)
            if (r + i <= n && s[r + i] < k)
                k -= s[r += i];
        return r;
    }
    int n, l;
    vector<T> a, s;
};
}; // namespace fenwick_tree
int main() {
    fast, prec(12);
    in(n);
    in(m);
    fenwick_tree::fenwick_tree<int> queue(n + m);
    vi mi(n + 1), mx(n + 1), val(n + 1);
    lp(i, 1, n) {
        val[i] = m + i - 1;
        mi[i] = i;
        mx[i] = i;
        queue.modify(val[i], 1);
    }
    int clk = m - 1;
    lp(i, 1, m) {
        in(a);
        mi[a] = 1;
        updg(mx[a], queue.sum(val[a]));
        queue.modify(val[a], 0);
        val[a] = clk;
        --clk;
        queue.modify(val[a], 1);
    }
    lp(a, 1, n) {
        updg(mx[a], queue.sum(val[a]));
        cout << mi[a] << " " << mx[a] << endl;
    }
    return 0;
}