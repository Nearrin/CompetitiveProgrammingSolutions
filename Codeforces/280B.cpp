#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#define sf scanf
#define pf printf
#define ps for (;;)
#define lp(i, a, b) for (int i = a; i <= b; ++i)
#define rp(i, a, b) for (int i = a; i >= b; --i)
using namespace std;
int a[100010], n, ans = -1;
void solve(int l, int r) {
    if (l == r)
        return;
    int m = (l + r) / 2;
    vector<int> ll, rr;
    lp(i, l, m) {
        while (!ll.empty() && ll.back() < a[i])
            ll.pop_back();
        ll.push_back(a[i]);
    }
    rp(i, r, m + 1) {
        while (!rr.empty() && rr.back() < a[i])
            rr.pop_back();
        rr.push_back(a[i]);
    }
    reverse(ll.begin(), ll.end());
    rp(i, int(rr.size() - 1), 0) {
        int lw = ((i == int(rr.size() - 1)) ? 0 : rr[i + 1]);
        int up = rr[i] - 1;
        int j = lower_bound(ll.begin(), ll.end(), lw) - ll.begin();
        int k = upper_bound(ll.begin(), ll.end(), up) - ll.begin();
        lp(u, j, k - 1) ans = max(ans, (ll[u] ^ rr[i]));
    }
    solve(l, m);
    solve(m + 1, r);
}
int main() {
    sf("%d", &n);
    lp(i, 1, n) sf("%d", &a[i]);
    solve(1, n);
    reverse(a + 1, a + n + 1);
    solve(1, n);
    pf("%d\n", ans);
    // ps;
    return 0;
}