#include <algorithm>
#include <cstdio>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for (;;)
#define lp(i, a, b) for (int i = a; i <= b; ++i)
#define rp(i, a, b) for (int i = a; i >= b; --i)
using namespace std;
int a[100010], n, t = (~0u >> 1), f = 1;
int main() {
    sf("%d", &n);
    lp(i, 1, n) {
        sf("%d", &a[i]);
        t = min(t, a[i]);
    }
    lp(i, 1, n) if (a[i] % t != 0) f = 0;
    pf("%d\n", f == 1 ? t : -1);
    // ps;
    return 0;
}