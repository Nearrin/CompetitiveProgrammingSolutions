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
typedef long long ll;
ll f[2010][2010], g[2010], h[2010], p = 1000000007, ans = 0;
ll s[2010][2010];
int main() {
    lp(i, 2, 2000) {
        lp(j, 1, 2000) {
            if (j == 1)
                f[i][j] = 1;
            else
                f[i][j] = (f[i][j] + h[j - 1]) % p;
            g[j] = (g[j] + f[i][j]) % p;
            h[j] = (h[j] + f[i][j]) % p;
        }
        lp(j, 1, 2000) h[j] = (h[j] + g[j]) % p;
    }
    lp(i, 2, 2000) lp(j, 1, 2000) s[i][j] = (s[i][j - 1] + f[i][j]) % p;
    int n, m;
    sf("%d%d", &n, &m);
    lp(i, 1, n) lp(j, 2, m) ans =
        (ans + f[j][i] * s[j][n - i + 1] % p * (m - j + 1) % p) % p;
    pf("%I64d\n", ans);
    // ps;
    return 0;
}