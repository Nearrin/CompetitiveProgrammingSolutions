#include <algorithm>
#include <cstdio>
#define sf scanf
#define pf printf
#define ps for (;;)
#define fr freopen
#define lp(i, a, b) for (int i = a; i <= b; ++i)
#define rp(i, a, b) for (int i = a; i >= b; --i)
using namespace std;
int a[100010], b[100010], c[100010];
int main() {
    int n;
    sf("%d", &n);
    if (n % 2 == 0)
        pf("-1\n");
    else {
        lp(i, 0, n - 1) a[i] = i;
        lp(i, 0, n - 2) c[i] = n - i - 2;
        c[n - 1] = n - 1;
        lp(i, 0, n - 1) b[i] = (c[i] - a[i] + n) % n;
        lp(i, 0, n - 1) pf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
        lp(i, 0, n - 1) pf("%d%c", b[i], i == n - 1 ? '\n' : ' ');
        lp(i, 0, n - 1) pf("%d%c", c[i], i == n - 1 ? '\n' : ' ');
    }
    // ps;
    return 0;
}