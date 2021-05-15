#include <algorithm>
#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for (;;)
#define pb push_back
#define mp make_pair
#define lp(i, a, b) for (int i = a; i <= b; ++i)
#define rp(i, a, b) for (int i = a; i >= b; --i)
#define vp(i, v) for (int i = 0; i < v.size(); ++i)
using namespace std;
typedef long long ll;
int p = 1000000007;
int db[1000010];
void add(int i, int d) {
    for (; i <= 1000000; i += i & -i)
        db[i] = (db[i] + d) % p;
}
int ask(int i) {
    int r = 0;
    for (; i; i -= i & -i)
        r = (r + db[i]) % p;
    return r;
}
int top[1000010], a[100010], f[100010], pre[100010], vis[1000010], n, ans;
int main() {
    sf("%d", &n);
    lp(i, 1, n) {
        sf("%d", &a[i]);
        pre[i] = top[a[i]];
        top[a[i]] = i;
    }
    lp(i, 1, n) {
        f[i] = ll(ask(a[i]) + 1) * a[i] % p;
        add(a[i], f[i]);
        if (pre[i])
            add(a[i], (-f[pre[i]] + p) % p);
    }
    rp(i, n, 1) {
        if (!vis[a[i]]) {
            ans = (ans + f[i]) % p;
            vis[a[i]] = 1;
        }
    }
    pf("%d\n", ans);
    return 0;
}