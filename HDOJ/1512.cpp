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
namespace pairing_heap {
template <class T, class C> struct pairing_heap {
    pairing_heap() : root(0), siz(0) {}
    ~pairing_heap() { clear(root); }
    struct node {
        node(const T &_val) : val(_val), ch(0), br(0), pr(0) {}
        T val;
        node *ch, *br, *pr;
    } * root;
    int siz;
    void merge(node *&x, node *y) {
        if (!x)
            x = y;
        else if (y) {
            if (C()(y->val, x->val))
                swap(x, y);
            y->br = x->ch;
            if (x->ch)
                x->ch->pr = y;
            y->pr = x;
            x->ch = y;
        }
    }
    void cut(node *&x, node *y) {
        if (x == y)
            x = 0;
        else {
            if (y == y->pr->ch)
                y->pr->ch = y->br;
            else
                y->pr->br = y->br;
            if (y->br)
                y->br->pr = y->pr;
            y->pr = y->br = 0;
        }
    }
    node *split(node *x) {
        vector<node *> t;
        for (node *i = x->ch; i; i = i->br)
            t.push_back(i);
        x->ch = 0;
        node *r = 0;
        for (int i = 0; i < int(t.size()); ++i)
            t[i]->pr = t[i]->br = 0;
        for (int i = 0; i + 1 < int(t.size()); i += 2)
            merge(t[i], t[i + 1]);
        for (int i = 0; i < int(t.size()); i += 2)
            merge(r, t[i]);
        return r;
    }
    void clear(node *x) {
        if (x) {
            clear(x->ch);
            clear(x->br);
            delete x;
        }
    }
    void clear() {
        clear(root);
        root = 0;
        siz = 0;
    }
    node *push(T a) {
        node *r = new node(a);
        merge(root, r);
        ++siz;
        return r;
    }
    void erase(node *x) {
        cut(root, x);
        merge(root, split(x));
        --siz;
    }
    T top() { return root->val; }
    void pop() { erase(root); }
    void merge(pairing_heap<T, C> &a) {
        merge(root, a.root);
        a.root = 0;
        siz += a.siz;
        a.siz = 0;
    }
    void modify(node *x, T v) {
        if (C()(x->val, v))
            x->val = v, merge(root, split(x));
        else
            x->val = v, cut(root, x), merge(root, x);
    }
    int size() { return siz; }
};
} // namespace pairing_heap
namespace skew_heap {
template <class T, class C> struct skew_heap {
    skew_heap() : root(0), siz(0) {}
    ~skew_heap() { clear(root); }
    struct node {
        node(T _val) : val(_val) { ch[0] = ch[1] = 0; }
        T val;
        node *ch[2];
    } * root;
    int siz;
    node *merge(node *x, node *y) {
        if (!x)
            return y;
        if (!y)
            return x;
        if (C()(y->val, x->val))
            swap(x, y);
        swap(x->ch[0], x->ch[1] = merge(x->ch[1], y));
        return x;
    }
    void clear(node *x) {
        if (x) {
            clear(x->ch[0]);
            clear(x->ch[1]);
            delete x;
        }
    }
    void clear() {
        clear(root);
        root = 0;
        siz = 0;
    }
    node *push(T a) {
        node *r = new node(a);
        root = merge(root, r);
        ++siz;
        return r;
    }
    T top() { return root->val; }
    void pop() {
        root = merge(root->ch[0], root->ch[1]);
        --siz;
    }
    void merge(skew_heap<T, C> &a) {
        root = merge(root, a.root);
        a.root = 0;
        siz += a.siz;
        a.siz = 0;
    }
    int size() { return siz; }
};
} // namespace skew_heap
namespace union_find_set {
struct union_find_set {
    int n;
    vector<int> p;
    union_find_set(int _n) : n(_n), p(n) {
        for (int i = 0; i < n; ++i)
            p[i] = i;
    }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    void link(int x, int y) {
        assert(find(x) != find(y));
        p[find(x)] = y;
    }
};
} // namespace union_find_set
int main() {
    fast, prec(12);
    int n;
    while (cin >> n) {
        using heap = skew_heap::skew_heap<int, greater<int>>;
        vector<heap *> a(n);
        union_find_set::union_find_set ufs(n);
        lp(i, 1, n) {
            int t;
            cin >> t;
            a[i - 1] = new heap;
            a[i - 1]->push(t);
        }
        int m;
        cin >> m;
        lp(i, 1, m) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            if (ufs.find(u) == ufs.find(v))
                cout << -1 << endl;
            else {
                int pu = ufs.find(u), pv = ufs.find(v);
                int t1 = a[pu]->top();
                a[pu]->pop();
                a[pu]->push(t1 / 2);
                t1 = a[pv]->top();
                a[pv]->pop();
                a[pv]->push(t1 / 2);
                a[pu]->merge(*a[pv]);
                delete a[pv];
                a[pv] = a[pu];
                cout << a[pu]->top() << endl;
                ufs.link(u, v);
            }
        }
        lp(i, 1, n) if (ufs.find(i - 1) == i - 1) { delete a[i - 1]; }
    }
    return 0;
}
