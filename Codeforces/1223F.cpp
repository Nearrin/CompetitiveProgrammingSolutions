#ifdef LOCAL
#include <header.hpp>
#else
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#endif
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
#define appl(x, f, a)                                                          \
    for (auto &x : a)                                                          \
    f
#define rang(a) begin(a), end(a)
#define gene template <class T>
#define elif else if
#define intm modular_arithmetic::integer
#define bcnt __builtin_popcount
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
gene T floor(const T &a, const T &b) {
    assert(b != 0);
    return (a > 0 && b > 0) || (a < 0 && b < 0)
               ? abs(a) / abs(b)
               : -(abs(a) + abs(b) - 1) / abs(b);
}
gene T ceil(const T &a, const T &b) {
    assert(b != 0);
    return (a > 0 && b > 0) || (a < 0 && b < 0) ? (abs(a) + abs(b) - 1) / abs(b)
                                                : -abs(a) / abs(b);
}
gene bool tmin(T &a, T b) { return b < a ? a = b, true : false; }
gene bool tmax(T &a, T b) { return b > a ? a = b, true : false; }
gene auto min(const T &a) { return *min_element(rang(a)); }
gene auto max(const T &a) { return *max_element(rang(a)); }
gene auto sum(const T &a) {
    return accumulate(rang(a), (typename T::value_type)0);
}
template <> auto sum(const vector<int> &a) { return accumulate(rang(a), 0ll); }
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
template <class T, class C = less<typename T::value_type>>
void sort(T &a, C c = C()) {
    sort(rang(a), c);
}
gene void reve(T &a) { reverse(rang(a)); }
gene void uniq(T &a) { sort(a), a.erase(unique(rang(a)), end(a)); }
gene void shuf(T &a) { shuffle(rang(a), rng); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
gene void in(T &a) { cin >> a; }
template <class A, class... B> void in(A &a, B &... b) { cin >> a, in(b...); }
void ou() { cout << endl; }
gene void ou(const T &a) { cout << a << endl; }
template <class A, class... B> void ou(const A &a, const B &... b) {
    cout << a << ' ', ou(b...);
}
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
// The templates end here.
namespace persistent_map {
template <class K, class V, class C = less<K>> struct persistent_map {
    struct node {
        node(const K &k_, const V &v_, node *l, node *r, int f_)
            : k(k_), v(v_), c{l, r}, s(1 + size(l) + size(r)), f(f_) {}
        K k;
        V v;
        node *c[2];
        int s, f;
    } * root;
    static int size(node *x) { return x ? x->s : 0; }
    void flatten(node *x, vector<pair<K, V>> &t) {
        if (x) {
            flatten(x->c[0], t);
            t.emplace_back(x->k, x->v);
            flatten(x->c[1], t);
        }
    }
    pair<node *, node *> split(node *x, int r) {
        if (!x)
            return {0, 0};
        int s = size(x->c[0]);
        if (s >= r) {
            auto t = split(x->c[0], r);
            return {t.first, new node(x->k, x->v, t.second, x->c[1], x->f)};
        } else {
            auto t = split(x->c[1], r - s - 1);
            return {new node(x->k, x->v, x->c[0], t.first, x->f), t.second};
        }
    }
    node *merge(node *x, node *y) {
        if (!x || !y)
            return x ? x : y;
        if (x->f < y->f)
            return new node(x->k, x->v, x->c[0], merge(x->c[1], y), x->f);
        else
            return new node(y->k, y->v, merge(x, y->c[0]), y->c[1], y->f);
    }
    node *find(const K &k) {
        node *x = root;
        while (x)
            if (C()(k, x->k))
                x = x->c[0];
            else if (C()(x->k, k))
                x = x->c[1];
            else
                break;
        return x;
    }
    persistent_map(node *root_ = 0) : root(root_) {}
    int size() { return size(root); }
    auto flatten() {
        vector<pair<K, V>> t;
        flatten(root, t);
        return t;
    }
    auto rank(const K &k, int d) {
        int r = 0;
        node *x = root, *y = 0;
        while (x)
            if (C()(d ? k : x->k, d ? x->k : k))
                y = x, r += size(x->c[d]) + 1, x = x->c[!d];
            else
                x = x->c[d];
        return make_pair(y, r);
    }
    auto select(int r) {
        for (node *x = (++r, root);;)
            if (size(x->c[0]) >= r)
                x = x->c[0];
            else if (size(x->c[0]) + 1 < r)
                r -= size(x->c[0]) + 1, x = x->c[1];
            else
                return x;
    }
    int count(const K &k) { return find(k) ? 1 : 0; }
    const V &operator[](const K &k) { return find(k)->v; }
    auto insert(const K &k, const V &v) {
        static mt19937 g(
            unsigned(chrono::steady_clock::now().time_since_epoch().count()));
        node *x = new node(
            k, v, 0, 0,
            uniform_int_distribution<int>(numeric_limits<int>::min(),
                                          numeric_limits<int>::max())(g));
        auto t = split(root, rank(k, 0).second);
        auto y = t.second;
        while (y && y->c[0])
            y = y->c[0];
        if (y && !C()(y->k, k) && !C()(k, y->k))
            t.second = split(t.second, 1).second;
        return persistent_map<K, V, C>(merge(merge(t.first, x), t.second));
    }
    auto erase(const K &k) {
        auto t = split(root, rank(k, 0).second);
        auto y = t.second;
        while (y && y->c[0])
            y = y->c[0];
        assert(y && !C()(y->k, k) && !C()(k, y->k));
        t.second = split(t.second, 1).second;
        return persistent_map<K, V, C>(merge(t.first, t.second));
    }
};
} // namespace persistent_map
int main() {
    fast, prec(12);
    many {
        vi a;
        in(a);
        int n = a.size();
        vector<persistent_map::persistent_map<int, int>> m(n + 1);
        vi p(n, -1), c(n + 1);
        rp(i, n - 1, 0) {
            if (m[i + 1].count(a[i])) {
                p[i] = m[i + 1][a[i]] + 1;
                c[i] = c[p[i]] + 1;
                m[i] = m[p[i]].insert(a[i], i);
            } else
                m[i] = m[i].insert(a[i], i);
        }
        ou(sum(c));
    }
    return 0;
}
