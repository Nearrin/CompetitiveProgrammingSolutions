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
int t, sx, sy, ex, ey, cnt[310], ned[310];
char tmp[100010];
int main() {
    sf("%d%d%d%d%d%s", &t, &sx, &sy, &ex, &ey, tmp + 1);
    lp(i, 1, t)++ cnt[tmp[i]];
    if (sx - ex > 0)
        ned['W'] += sx - ex;
    else
        ned['E'] += ex - sx;
    if (sy - ey > 0)
        ned['S'] += sy - ey;
    else
        ned['N'] += ey - sy;
    if (ned['E'] <= cnt['E'] && ned['W'] <= cnt['W'] && ned['N'] <= cnt['N'] &&
        ned['S'] <= cnt['S']) {
        ll u = ll(ned['E']) + ll(ned['N']) + ll(ned['S']) + ll(ned['W']);
        int f = 1;
        while (ned['E'] != 0 || ned['W'] != 0 || ned['S'] != 0 ||
               ned['N'] != 0) {
            if (ned[tmp[f]] > 0)
                --ned[tmp[f]];
            else
                ++u;
            ++f;
        }
        pf("%I64d\n", u);
    } else {
        pf("-1\n");
    }
    // ps;
    return 0;
}