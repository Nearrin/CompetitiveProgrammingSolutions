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
#define freo freopen
#define many for (int T = -1; T < 0 && cin >> T, T--;)
#define appl(f, a) for (auto i = begin(a); i != end(a); f, ++i)
#define rang(a) begin(a), end(a)
#define tstr(a) to_string(a)
#define gene template <class T>
#define elif else if
#ifndef LOCAL
#define endl '\n'
#define assert
#endif
using namespace std;
using namespace __gnu_pbds;
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
gene void shuf(T &a) { random_shuffle(rang(a)); }
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
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef string str;
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
    template <class I> T sum(const I &k_begin, const I &k_end) {
        T r = 0;
        for (int i = *k_begin + 1; i; i -= i & -i)
            r += s[i].sum(k_begin + 1, k_end);
        ;
        return r;
    }
    T sum(const vector<int> &k) { return sum(begin(k), end(k)); }
    template <class I>
    T sum(const I &l_begin, const I &l_end, const I &r_begin, const I &r_end) {
        return sum(*r_begin, l_begin + 1, l_end, r_begin + 1, r_end) -
               sum(*l_begin - 1, l_begin + 1, l_end, r_begin + 1, r_end);
    }
    template <class I>
    T sum(int k, const I &l_begin, const I &l_end, const I &r_begin,
          const I &r_end) {
        T t = 0;
        for (int i = k + 1; i; i -= i & -i)
            t += s[i].sum(l_begin, l_end, r_begin, r_end);
        return t;
    }
    T sum(const vector<int> &_l, const vector<int> &r) {
        return sum(r[0], begin(_l) + 1, end(_l), begin(r) + 1, end(r)) -
               sum(_l[0] - 1, begin(_l) + 1, end(_l), begin(r) + 1, end(r));
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
        assert(k >= -1 && k < n);
        T r = 0;
        for (++k; k; k -= k & -k)
            r += s[k];
        return r;
    }
    template <class I> T sum(const I &k_begin, const I &k_end) {
        return sum(*k_begin);
    }
    template <class I>
    T sum(const I &l_begin, const I &l_end, const I &r_begin, const I &r_end) {
        assert(l_begin + 1 == l_end && r_begin + 1 == r_end);
        return sum(*r_begin) - sum(*l_begin);
    }
    T sum(int _l, int r) { return sum(r) - sum(_l - 1); }
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
} // namespace fenwick_tree
int main() {
    fast, prec(12);
    vi pre;
    many {
        int n, q;
        in(n, q);
        fenwick_tree::fenwick_tree<ll> tree(n);
        lp(i, 0, n - 1) if (i < pre.size()) tree.modify(i, pre[i]);
        lp(i, 1, q) {
            int u, v, w;
            in(u, v, w);
            if (u == 2) {
                ou(tree.sum(v - 1, w - 1));
            } else {
                tree.modify(v - 1, w);
            }
        }
        if (pre.size() < n)
            pre.resize(n);
        lp(i, 0, n - 1) pre[i] = tree.a[i];
    }
    return 0;
}