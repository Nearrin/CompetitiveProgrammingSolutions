#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for (;;)
#define pb push_back
#define mp make_pair
#define lp(i, a, b) for (int i = a; i <= b; ++i)
#define rp(i, a, b) for (int i = a; i >= b; --i)
#define vp(i, v) for (int i = 0; i < v.size(); ++i)
#define wp(i, v) for (int i = int(v.size() - 1); i >= 0; --i)
using namespace std;
typedef long long ll;
ll p = 1000000000;
namespace fib {
struct mat {
    ll d[2][2];
};
mat operator*(const mat &a, const mat &b) {
    mat c;
    lp(i, 0, 1) lp(j, 0, 1) c.d[i][j] = 0;
    lp(i, 0, 1) lp(j, 0, 1) lp(k, 0, 1) c.d[i][j] =
        (c.d[i][j] + a.d[i][k] * b.d[k][j]) % p;
    return c;
}
ll calc(ll f0, ll f1, ll n) {
    static mat a;
    lp(i, 0, 1) lp(j, 0, 1) a.d[i][j] = 1;
    a.d[0][0] = 0;
    static mat r;
    lp(i, 0, 1) lp(j, 0, 1) r.d[i][j] = (i == j);
    while (n) {
        if (n & 1)
            r = r * a;
        a = a * a;
        n >>= 1;
    }
    return (r.d[0][0] * f0 + r.d[1][0] * f1) % p;
}
} // namespace fib
ll a[100010];
int n, q;
struct node {
    node(int a, int b) : l(a), r(b) { ch[0] = ch[1] = 0; }
    node *ch[2];
    int l, r;
    ll f0, f1;
} * rt;
void update(node *x) {
    int t1 = x->ch[0]->r - x->ch[0]->l + 1;
    x->f0 = (x->ch[0]->f0 + fib::calc(x->ch[1]->f0, x->ch[1]->f1, t1)) % p;
    x->f1 = (x->ch[0]->f1 + fib::calc(x->ch[1]->f0, x->ch[1]->f1, t1 + 1)) % p;
}
node *build(int l, int r) {
    node *ret = new node(l, r);
    if (l == r) {
        ret->f0 = ret->f1 = a[l];
    } else {
        int m = (l + r) / 2;
        ret->ch[0] = build(l, m);
        ret->ch[1] = build(m + 1, r);
        update(ret);
    }
    return ret;
}
node query(node *x, int l, int r) {
    if (l == x->l && r == x->r)
        return *x;
    else {
        int m = x->ch[0]->r;
        if (r <= m)
            return query(x->ch[0], l, r);
        else if (l > m)
            return query(x->ch[1], l, r);
        else {
            node t1 = query(x->ch[0], l, m);
            node t2 = query(x->ch[1], m + 1, r);
            node t3(l, r);
            t3.ch[0] = &t1;
            t3.ch[1] = &t2;
            update(&t3);
            return t3;
        }
    }
}
void modify(node *x, int p, int v) {
    if (x->l == x->r) {
        x->f0 = x->f1 = v;
    } else {
        int m = x->ch[0]->r;
        if (p <= m)
            modify(x->ch[0], p, v);
        else
            modify(x->ch[1], p, v);
        update(x);
    }
}
int main() {
    sf("%d%d", &n, &q);
    lp(i, 1, n) sf("%I64d", &a[i]);
    rt = build(1, n);
    lp(i, 1, q) {
        int t;
        sf("%d", &t);
        if (t == 1) {
            int x, v;
            sf("%d%d", &x, &v);
            modify(rt, x, v);
        } else {
            int l, r;
            sf("%d%d", &l, &r);
            pf("%d\n", (int)query(rt, l, r).f0);
        }
    }
    // ps;
    return 0;
}