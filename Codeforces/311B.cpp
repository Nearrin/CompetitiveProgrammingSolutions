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
ll n, p, a[100010], s[100010], f[110][100010], y[110][100010];
int x[110][100010];
void init() {
    ll m;
    sf("%I64d%I64d%I64d", &m, &n, &p);
    static ll d[100010], h[100010], t[100010];
    lp(i, 2, m) sf("%I64d", &d[i]), d[i] += d[i - 1];
    lp(i, 1, n) sf("%I64d%I64d", &h[i], &t[i]), a[i] = t[i] - d[h[i]];
    sort(a + 1, a + n + 1);
    lp(i, 1, n) s[i] = s[i - 1] + a[i];
}
double slope(int i, int j, int k, int l) {
    return double(y[j][i] - y[l][k]) / double(x[j][i] - x[l][k]);
}
void solve() {
    lp(i, 1, n) f[1][i] = i * a[i] - s[i], x[1][i] = i,
                y[1][i] = s[i] + f[1][i];
    lp(j, 2, p) {
        deque<int> qu;
        qu.push_back(0);
        lp(i, 1, n) {
            while (qu.size() > 1) {
                int u = qu[0], v = qu[1];
                if (slope(u, j - 1, v, j - 1) < a[i] + 1e-8)
                    qu.pop_front();
                else
                    break;
            }
            f[j][i] = f[j - 1][qu[0]] + (i - qu[0]) * a[i] - (s[i] - s[qu[0]]);
            x[j][i] = i;
            y[j][i] = s[i] + f[j][i];
            while (qu.size() > 1) {
                int u = qu[qu.size() - 2], v = qu[qu.size() - 1];
                if (slope(u, j - 1, v, j - 1) >
                    slope(v, j - 1, i, j - 1) - 1e-8)
                    qu.pop_back();
                else
                    break;
            }
            qu.push_back(i);
        }
    }
    pf("%I64d\n", f[p][n]);
}
int main() {
    init();
    solve();
    // ps;
    return 0;
}