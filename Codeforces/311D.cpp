#include <algorithm>
#include <cstdio>
#include <deque>
#define sf scanf
#define pf printf
#define ps for (;;)
#define fr freopen
#define lp(i, a, b) for (int i = a; i <= b; ++i)
#define rp(i, a, b) for (int i = a; i >= b; --i)
using namespace std;
typedef long long ll;
int a[100010][48], n, q, p = 95542721;
int seg[100010 * 4][48], del[100010 * 4];
void down(int x, int l, int r) {
    static int tmp[48];
    lp(i, 0, 47) tmp[i] = seg[x][(i + del[x]) % 48];
    lp(i, 0, 47) seg[x][i] = tmp[i];
    if (l != r)
        del[x * 2] += del[x], del[x * 2 + 1] += del[x];
    del[x] = 0;
}
void upda(int x, int l, int r) {
    int m = (l + r) / 2;
    down(x * 2, l, m);
    down(x * 2 + 1, m + 1, r);
    lp(i, 0, 47) seg[x][i] = (seg[x * 2][i] + seg[x * 2 + 1][i]) % p;
}
void build(int x, int l, int r) {
    if (l == r) {
        lp(i, 0, 47) seg[x][i] = a[l][i];
    } else {
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        upda(x, l, r);
    }
}
int ask(int x, int l, int r, int b, int e) {
    down(x, l, r);
    if (b <= l && e >= r)
        return seg[x][0];
    else {
        int m = (l + r) / 2, ret = 0;
        if (b <= m)
            ret = (ret + ask(x * 2, l, m, b, e)) % p;
        if (e > m)
            ret = (ret + ask(x * 2 + 1, m + 1, r, b, e)) % p;
        return ret;
    }
}
void modify(int x, int l, int r, int b, int e) {
    down(x, l, r);
    if (b <= l && e >= r)
        ++del[x];
    else {
        int m = (l + r) / 2;
        if (b <= m)
            modify(x * 2, l, m, b, e);
        if (e > m)
            modify(x * 2 + 1, m + 1, r, b, e);
        upda(x, l, r);
    }
}
int main() {
    sf("%d", &n);
    lp(i, 1, n) {
        sf("%d", &a[i][0]);
        lp(j, 1, 47) a[i][j] =
            ll(a[i][j - 1]) * ll(a[i][j - 1]) % p * ll(a[i][j - 1]) % p;
    }
    build(1, 1, n);
    sf("%d", &q);
    lp(i, 1, q) {
        int t, l, r;
        sf("%d%d%d", &t, &l, &r);
        if (t == 1) {
            pf("%d\n", ask(1, 1, n, l, r));
        } else {
            modify(1, 1, n, l, r);
        }
    }
    // ps;
    return 0;
}