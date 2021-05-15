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
template <typename... T> void ou(T... a) { ((cout << a << ' '), ...) << endl; }
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
            u->s.merge(u->c[0]->s, u->c[1]->s);
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
    void push(node *u) {
        if (u->c[0])
            u->c[0]->s.tag(u->s.tag()), u->c[1]->s.tag(u->s.tag());
        u->s.push();
    }
    void merge(node *u) { u->s.merge(u->c[0]->s, u->c[1]->s); }
    void modify_single(int p, const T &s, node *u = 0) {
        if (!u)
            u = root;
        push(u);
        if (u->l == u->r) {
            assert(p == u->l);
            u->s = s;
        } else {
            modify_single(p, s, u->c[p > u->c[0]->r]);
            push(u->c[p <= u->c[0]->r]), merge(u);
        }
    }
    template <class A>
    void modify_segment(int l, int r, const A &t, node *u = 0) {
        if (!u)
            u = root;
        assert((u != root || (u->l <= l && u->r >= r)) && l <= r), push(u);
        if (l <= u->l && r >= u->r)
            u->s.tag(t), push(u);
        else {
            if (l <= u->c[0]->r)
                modify_segment(l, r, t, u->c[0]);
            else
                push(u->c[0]);
            if (r >= u->c[1]->l)
                modify_segment(l, r, t, u->c[1]);
            else
                push(u->c[1]);
            merge(u);
        }
    }
    const T &query_single(int p, node *u = 0) {
        if (!u)
            u = root;
        push(u);
        if (u->l == u->r) {
            assert(p == u->l);
            return u->s;
        } else {
            return query_single(p, u->c[p > u->c[0]->r]);
        }
    }
    T query_segment(int l, int r, node *u = 0) {
        if (!u)
            u = root;
        assert((u != root || (u->l <= l && u->r >= r)) && l <= r), push(u);
        if (l <= u->l && r >= u->r)
            return u->s;
        else {
            if (r <= u->c[0]->r)
                return query_segment(l, r, u->c[0]);
            if (l >= u->c[1]->l)
                return query_segment(l, r, u->c[1]);
            T t;
            t.merge(query_segment(l, r, u->c[0]), query_segment(l, r, u->c[1]));
            return t;
        }
    }
};
struct add_sum {
    add_sum(int w = 0, int _c = 0) : c(_c), t(0) {
        if (c == 0) {
            s0 = w;
            s1 = 0;
            best = inf();
        } else {
            s0 = 0;
            s1 = w;
            best = inf();
        }
    }
    void push() {}
    void merge(const add_sum &a, const add_sum &b) {
        s1 = a.s1 + b.s1;
        s0 = a.s0 + b.s0;
        if (a.best == inf()) {
            assert(b.best == inf());
            best = a.s1 + b.s0;
        } else {
            best = min(a.best + b.s0, b.best + a.s1);
            best = min(best, a.s1 + b.s0);
        }
    }
    void tag(int a) {}
    int tag() { return t; }
    int t, c;
    ll s1, s0, best;
};
} // namespace segment_tree
int main() {
    fast, prec(12);
    int n;
    cin >> n;
    vi p(n);
    cin >> p;
    vi a(n);
    cin >> a;
    vector<segment_tree::add_sum> info;
    lv(i, p) { info.push_back(segment_tree::add_sum(a[i], 1)); }
    segment_tree::segment_tree seg(info);
    vi pos(n + 1);
    lv(i, p) pos[p[i]] = i;
    ll ans = seg.root->s.best;
    lp(i, 1, n) {
        segment_tree::add_sum newinfo(a[pos[i]], 0);
        seg.modify_single(pos[i], newinfo);
        tmin(ans, seg.root->s.best);
    }
    ou(ans);
    return 0;
}
