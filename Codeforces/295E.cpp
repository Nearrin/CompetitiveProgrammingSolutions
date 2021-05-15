#include <algorithm>
#include <cstdio>
#include <vector>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for (;;)
#define lp(i, a, b) for (int i = a; i <= b; ++i)
#define rp(i, a, b) for (int i = a; i >= b; --i)
using namespace std;
namespace seg {
typedef long long ll;
struct node {
    node(node *a, node *b, int c, int d, ll e, ll f, int g)
        : lc(a), rc(b), l(c), r(d), t1(e), t2(f), sz(g){};
    node *lc, *rc;
    int l, r, sz;
    ll t1, t2;
} * rt;
#define SZ(x) (x ? x->sz : 0)
#define T1(x) (x ? x->t1 : 0)
#define T2(x) (x ? x->t2 : 0)
void upda(node *x) {
    x->sz = SZ(x->lc) + SZ(x->rc);
    x->t1 = T1(x->lc) + T1(x->rc);
    x->t2 = T2(x->lc) + T2(x->rc) + T1(x->rc) * SZ(x->lc);
}
void add(node *x, int t, int v) {
    if (x->l == x->r) {
        if (t == 1)
            x->sz = 1, x->t1 = v, x->t2 = v;
        else
            x->sz = 0, x->t1 = 0, x->t2 = 0;
    } else {
        int m = ll(x->l) + (ll(x->r) - ll(x->l)) / 2; // attention
        if (v <= m) {
            if (!x->lc)
                x->lc = new node(0, 0, x->l, m, 0, 0, 0);
            add(x->lc, t, v);
        } else {
            if (!x->rc)
                x->rc = new node(0, 0, m + 1, x->r, 0, 0, 0);
            add(x->rc, t, v);
        }
        upda(x);
    }
}
vector<node *> nds;
void ask(node *x, int b, int e) {
    if (b <= x->l && e >= x->r) {
        node *t = new node(0, 0, x->l, x->r, x->t1, x->t2, x->sz);
        nds.push_back(t);
    } else {
        int m = ll(x->l) + (ll(x->r) - ll(x->l)) / 2; // attention
        if (b <= m && x->lc)
            ask(x->lc, b, e);
        if (e > m && x->rc)
            ask(x->rc, b, e);
    }
}
void build() { rt = new node(0, 0, -(~0u >> 1), ~0u >> 1, 0, 0, 0); }
ll query(int l, int r) {
    nds.clear();
    ask(rt, l, r);
    if (nds.size() < 1)
        return 0; // attention
    while (nds.size() > 1) {
        node *t2 = nds.back();
        nds.pop_back();
        node *t1 = nds.back();
        nds.pop_back();
        node *t = new node(t1, t2, t1->l, t2->r, 0, 0, 0);
        upda(t);
        delete t1;
        delete t2;
        nds.push_back(t);
    }
    node *t = nds.front();
    ll ret = 2 * t->t2 - (t->sz + 1) * t->t1;
    delete t;
    return ret;
}
} // namespace seg
int a[100010];
int main() {
    int n, q;
    sf("%d", &n);
    seg::build();
    lp(i, 1, n) {
        sf("%d", &a[i]);
        seg::add(seg::rt, 1, a[i]);
    }
    sf("%d", &q);
    lp(i, 1, q) {
        int u, v, w;
        sf("%d%d%d", &u, &v, &w);
        if (u == 2) {
            pf("%I64d\n", seg::query(v, w));
        } else {
            seg::add(seg::rt, 2, a[v]);
            a[v] += w;
            seg::add(seg::rt, 1, a[v]);
        }
    }
    // ps;
    return 0;
}