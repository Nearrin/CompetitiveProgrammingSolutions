#include <algorithm>
#include <cstdio>
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
#define wp(i, v) for (int i = int(v.size() - 1); i >= 0; --i)
using namespace std;
typedef long long ll;
ll p = 1000000007;
ll f[1000010], g[1000010];
ll inv(ll a) {
    ll r = 1;
    for (ll t = p - 2; t; t >>= 1) {
        if (t & 1)
            r = r * a % p;
        a = a * a % p;
    }
    return r;
}
int main() {
    f[0] = f[1] = 1;
    lp(i, 2, 1000000) f[i] = (f[i - 1] + f[i - 2] * (i - 1)) % p;
    g[0] = 1;
    lp(i, 1, 1000000) g[i] = g[i - 1] * i % p;
    ll n = 0, m = 0;
    int k;
    sf("%d", &k);
    lp(i, 1, k) {
        int t;
        sf("%d", &t);
        if (t == 1)
            ++n;
        else
            ++m;
    }
    ll t1 = g[n + m] * inv(g[n]) % p;
    ll t2 = t1 * f[n] % p;
    pf("%d\n", int(t2));
    // ps;
    return 0;
}