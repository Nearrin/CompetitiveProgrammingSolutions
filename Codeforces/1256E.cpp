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
namespace segment_tree {
template <class T> struct segment_tree {
    struct node {
        node *c[2];
        T s;
        int l, r;
    } * root;
    node *build(const vector<T> &a, int l, int r) {
        node *u = new node;
        if (l == r)
            u->c[0] = u->c[1] = 0, u->s = a[l];
        else {
            int m = (l + r) / 2;
            u->c[0] = build(a, l, m), u->c[1] = build(a, m + 1, r);
            u->s = T::merge(u->c[0]->s, u->c[1]->s);
        }
        u->l = l, u->r = r;
        return u;
    }
    segment_tree(const vector<T> &a) : root(build(a, 0, int(a.size() - 1))) {}
    void destroy(node *u) {
        if (u) {
            destroy(u->c[0]), destroy(u->c[1]);
            delete u;
        }
    }
    ~segment_tree() { destroy(root); }
    void modify(node *u) {
        auto t = u->s.modification();
        if (u->c[0])
            T::push(u->c[0]->s, t), T::push(u->c[1]->s, t);
        u->s.modify();
    }
    void merge(node *u) { u->s = T::merge(u->c[0]->s, u->c[1]->s); }
    void modify_single(int p, const T &s, node *u = 0) {
        u = u ? u : root;
        modify(u);
        if (u->l == u->r) {
            assert(p == u->l);
            u->s = s;
        } else {
            modify_single(p, s, u->c[p > u->c[0]->r]);
            modify(u->c[p <= u->c[0]->r]), merge(u);
        }
    }
    template <class A>
    void modify_segment(int l, int r, const A &t, node *u = 0) {
        u = u ? u : root;
        assert((u != root || (u->l <= l && u->r >= r)) && l <= r), modify(u);
        if (l <= u->l && r >= u->r)
            T::push(u->s, t), modify(u);
        else {
            if (l <= u->c[0]->r)
                modify_segment(l, r, t, u->c[0]);
            else
                modify(u->c[0]);
            if (r >= u->c[1]->l)
                modify_segment(l, r, t, u->c[1]);
            else
                modify(u->c[1]);
            merge(u);
        }
    }
    const T &query_single(int p, node *u = 0) {
        u = u ? u : root, modify(u);
        if (u->l == u->r) {
            assert(p == u->l);
            return u->s;
        } else {
            return query_single(p, u->c[p > u->c[0]->r]);
        }
    }
    T query_segment(int l, int r, node *u = 0) {
        u = u ? u : root, modify(u);
        assert((u != root || (u->l <= l && u->r >= r)) && l <= r);
        if (l <= u->l && r >= u->r)
            return u->s;
        else {
            if (r <= u->c[0]->r)
                return query_segment(l, r, u->c[0]);
            if (l >= u->c[1]->l)
                return query_segment(l, r, u->c[1]);
            return T::merge(query_segment(l, r, u->c[0]),
                            query_segment(l, r, u->c[1]));
        }
    }
};
} // namespace segment_tree
namespace statistic {
struct statistic {
    statistic(ll m_ = 0, int i_ = 0) : m(m_), d(0), i(i_) {}
    ll modification() { return d; }
    void modify() { m += d, d = 0; }
    void resverse() {}
    static statistic merge(const statistic &a, const statistic &b) {
        if (a.m < b.m)
            return statistic(a.m, a.i);
        return statistic(b.m, b.i);
    }
    static void push(statistic &a, const ll &t) { a.d += t; }
    ll m, d;
    int i;
};
template <class T> struct add_min {
    int i;
    T v, d;
    add_min(T _v, int _i) : i(_i), v(_v), d(0) {}
    T modification() { return d; }
    void modify() { v += d, d = 0; }
    void reverse() {}
    static add_min merge(const add_min &a, const add_min &b) {
        assert(!a.d && !b.d);
        if (a.v < b.v)
            return a;
        else
            return b;
    }
    static void push(add_min &a, T &d) { a.d += d; }
};
template <class T> struct add_sum {
    int l;
    T s, d;
    add_sum(T _s, int _l = 1) : l(_l), s(_s), d(0) {}
    T modification() { return d; }
    void modify() { s += d * l, d = 0; }
    void reverse() {}
    static add_sum merge(const add_sum &a, const add_sum &b) {
        return add_sum(a.s + b.s, a.l + b.l);
    }
    static void push(add_sum &a, T &d) { a.d += d; }
};
} // namespace statistic
// The templates end here.
int main() {
    fast, prec(12);
    vi a;
    in(a);
    vi p(a.size()), ans(a.size());
    vpii b;
    lv(i, a) b.emplace_back(a[i], i);
    sort(b);
    segment_tree::segment_tree<statistic::statistic> f(
        vector<statistic::statistic>(a.size() + 1));
    vpii mx, mi;
    lp(i, 1, a.size()) {
        while (mx.size() && mx.back().first <= b[i - 1].first) {
            int l = mx.size() == 1 ? 0 : mx[mx.size() - 2].second,
                r = mx.back().second - 1;
            f.modify_segment(l, r, b[i - 1].first - mx.back().first);
            // ou(l, r, b[i - 1].first - mx.back().first);
            mx.pop_back();
        }
        mx.emplace_back(b[i - 1].first, i);
        while (mi.size() && mi.back().first >= b[i - 1].first) {
            int l = mi.size() == 1 ? 0 : mi[mi.size() - 2].second,
                r = mi.back().second - 1;
            f.modify_segment(l, r, -b[i - 1].first + mi.back().first);
            // ou(l, r, -b[i - 1].first + mi.back().first);
            mi.pop_back();
        }
        mi.emplace_back(b[i - 1].first, i);
        if (i - 3 >= 0) {
            auto tmp = f.query_segment(0, i - 3);
            p[i - 1] = tmp.i - 1;
            f.modify_single(i, statistic::statistic(tmp.m, i));
        } else {
            f.modify_single(i, statistic::statistic(inf(), i));
        }
    }
    int cnt = 0;
    for (int i = a.size() - 1; i >= 0; i = p[i]) {
        ++cnt;
        lp(j, p[i] + 1, i) ans[b[j].second] = cnt;
    }
    ou(f.query_single(a.size()).m, cnt);
    ou(ans);
    return 0;
}
