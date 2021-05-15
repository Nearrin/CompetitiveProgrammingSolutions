#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for (;;)
#define lp(i, a, b) for (int i = a; i <= b; ++i)
#define rp(i, a, b) for (int i = a; i >= b; --i)
using namespace std;
int main() {
    map<int, int> cnt;
    int n;
    sf("%d", &n);
    int ans = 1;
    lp(i, 1, n) {
        int t;
        sf("%d", &t);
        if ((++cnt[t]) > (n + 1) / 2)
            ans = 0;
    }
    pf("%s\n", ans ? "YES" : "NO");
    // ps;
    return 0;
}