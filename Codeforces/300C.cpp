#include <algorithm>
#include <cstdio>
#include <vector>
#define sf scanf
#define pf printf
#define ps for (;;)
#define lp(i, a, b) for (int i = a; i <= b; ++i)
#define rp(i, a, b) for (int i = a; i >= b; --i)
using namespace std;
typedef long long ll;
ll ans;
int a, b, n;
bool check(int x) {
    while (x) {
        if (x % 10 != a && x % 10 != b)
            return false;
        x /= 10;
    }
    return true;
}
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    } else {
        ll r = exgcd(b, a % b, y, x);
        y -= a / b * x;
        return r;
    }
}
ll fac[1000010];
ll com(int n, int k) {
    if (n < k)
        return 0; //ע������
    ll t1 = fac[n], t2 = fac[k] * fac[n - k] % 1000000007;
    ll x, y;
    exgcd(t2, 1000000007, x, y);
    return (t1 * x % 1000000007 + 1000000007) % 1000000007;
}
int main() {
    sf("%d%d%d", &a, &b, &n);
    fac[0] = 1;
    for (ll i = 1; i <= n; ++i)
        fac[i] = fac[i - 1] * i % 1000000007;
    lp(i, 0, n) {
        int ca = i, cb = n - i;
        if (check(ca * a + cb * b)) {
            ans = (ans + com(n, i)) % 1000000007;
        }
    }
    pf("%I64d\n", ans);
    // ps;
    return 0;
}