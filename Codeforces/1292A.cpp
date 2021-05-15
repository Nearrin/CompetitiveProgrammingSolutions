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
#define endl '\n'
#define asse assert
using namespace std;
using namespace __gnu_pbds;
gene T inf() { return numeric_limits<T>::max(); }
gene int tmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
gene int tmax(T &a, T b) { return b > a ? a = b, 1 : 0; }
gene auto min(const T &a) { return *min_element(rang(a)); }
gene auto max(const T &a) { return *max_element(rang(a)); }
gene auto sum(const T &a) { return accumulate(rang(a), 0); }
gene auto gath(const T &a, const vector<int> &b) {
    vector<typename T::value_type> r;
    for (auto i : b)
        r.push_back(a[i]);
    return r;
}
gene void sort(T &a) { sort(rang(a)); }
gene void reve(T &a) { reverse(rang(a)); }
gene void uniq(T &a) { sort(a), a.erase(unique(rang(a)), end(a)); }
gene void shuf(T &a) { random_shuffle(rang(a)); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
#if __cplusplus >= 201703L
template <typename... T> void in(T &... a) { ((cin >> a), ...); }
template <typename... T> void ou(T... a) { ((cout << a << ' '), ...); }
#endif
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
struct info {
    info() { lp(i, 0, 1) lp(j, 0, 1) c[i][j] = true; }
    bool c[2][2];
};
info merge(const info &a, const info &b) {
    info c;
    lp(i, 0, 1) lp(j, 0, 1) c.c[i][j] =
        (a.c[i][0] && b.c[0][j]) || (a.c[i][1] && b.c[1][j]);
    return c;
}
struct node {
    node(int _l, int _r) {
        l = _l, r = _r;
        c[0] = c[1] = 0;
    }
    int l, r;
    info i;
    node *c[2];
};
node *build(int l, int r) {
    node *t = new node(l, r);
    if (l == r) {
        return t;
    }
    int m = (l + r) / 2;
    t->c[0] = build(l, m);
    t->c[1] = build(m + 1, r);
    return t;
}
bool a[100010][2];
void update(node *x, int p) {
    if (x->l == x->r) {
        x->i.c[0][0] = a[p][0];
        x->i.c[1][1] = a[p][1];
        x->i.c[0][1] = (a[p][0] && a[p][1]);
        x->i.c[1][0] = (a[p][0] && a[p][1]);
    } else {
        int m = (x->l + x->r) / 2;
        if (p <= m)
            update(x->c[0], p);
        else
            update(x->c[1], p);
        x->i = merge(x->c[0]->i, x->c[1]->i);
    }
}
int main() {
    fast, prec(12);
    int n, q;
    cin >> n >> q;
    auto root = build(1, n);
    lp(i, 1, n) a[i][0] = a[i][1] = true;
    lp(i, 1, q) {
        int r, c;
        cin >> r >> c;
        --r;
        a[c][r] = !a[c][r];
        update(root, c);
        if (root->i.c[0][1]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
