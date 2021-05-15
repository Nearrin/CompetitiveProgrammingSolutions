#include <algorithm>
#include <cstdio>
#include <utility>
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
int n, a[110];
int main() {
    sf("%d", &n);
    lp(i, 1, n) sf("%d", &a[i]), a[i] += a[i - 1];
    int ans = 0;
    lp(i, 1, n) lp(j, i, n) ans =
        max(ans, a[i - 1] + a[n] - a[j] + (j - i + 1) - (a[j] - a[i - 1]));
    pf("%d\n", ans);
    return 0;
}