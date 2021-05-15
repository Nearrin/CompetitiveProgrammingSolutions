#include <algorithm>
#include <cstdio>
#include <vector>
#define sf scanf
#define pf printf
#define ps for (;;)
#define fr freopen
#define pb push_back
#define mp make_pair
#define lp(i, a, b) for (int i = a; i <= b; ++i)
#define rp(i, a, b) for (int i = a; i >= b; --i)
#define vp(i, v) for (int i = 0; i < v.size(); ++i)
#define wp(i, v) for (int i = int(v.size() - 1); i >= 0; --i)
typedef long long ll;
using namespace std;
int cnt[150][150], n, q;
#define C(x, y) cnt[x + 70][y + 70]
void dfs(int x, int y) {
    if (C(x, y) < 4)
        return;
    int t = C(x, y) / 4;
    C(x, y) %= 4;
    C(x - 1, y) += t;
    dfs(x - 1, y);
    C(x, y - 1) += t;
    dfs(x, y - 1);
    C(x + 1, y) += t;
    dfs(x + 1, y);
    C(x, y + 1) += t;
    dfs(x, y + 1);
}
int main() {
    sf("%d%d", &n, &q);
    C(0, 0) = n;
    dfs(0, 0);
    lp(i, 1, q) {
        int x, y;
        sf("%d%d", &x, &y);
        if (x > 70 || x < -70 || y > 70 || y < -70)
            pf("0\n");
        else
            pf("%d\n", C(x, y));
    }
    return 0;
}