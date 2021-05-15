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
template <class T> struct add_sum {
    add_sum(T a = 0) : s(a), t(0), l(1) {}
    void push() {
        if (t)
            s += t * l, t = 0;
    }
    void merge(const add_sum &a, const add_sum &b) {
        s = a.s + b.s, l = a.l + b.l;
    }
    void tag(T a) { t += a; }
    T tag() { return t; }
    T s, t;
    int l;
};
} // namespace segment_tree
int main() {
    fast, prec(12);
    int n;
    ll d, a;
    cin >> n >> d >> a;
    vector<pair<ll, ll>> m(n);
    cin >> m;
    sort(m);
    vector<segment_tree::add_sum<ll>> info;
    for (auto i : m)
        info.push_back(segment_tree::add_sum<ll>(i.second));
    segment_tree::segment_tree<segment_tree::add_sum<ll>> seg(info);
    ll ans = 0;
    rv(i, m) {
        ll cur_height = seg.query_single(i).s;
        if (cur_height <= 0)
            continue;
        ll cnt = cur_height / a;
        if (cur_height % a != 0)
            ++cnt;
        ans += cnt;
        cnt *= a;
        ll l = m[i].first - 2 * d;
        int j = lower_bound(m.begin(), m.end(), make_pair(l, 1ll)) - m.begin();
        seg.modify_segment(j, i, -cnt);
    }
    cout << ans << endl;
    return 0;
}
