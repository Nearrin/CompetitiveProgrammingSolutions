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
#include <cstring>
ll p = 1000000007;
ll npow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1)
            ret = ret * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ret;
}
char s[100010];
ll n, k;
int main() {
    sf("%s%I64d", s + 1, &k);
    n = strlen(s + 1);
    ll ans = 0;
    lp(i, 1, n) {
        if (s[i] == '0' || s[i] == '5') {
            ll t1 = npow(2, i - 1) * (npow(2, n * k) - 1 + p) % p;
            ll t2 = (npow(2, n) - 1 + p) % p;
            t2 = npow(t2, p - 2);
            ans = ans + t1 * t2 % p;
            ans %= p;
        }
    }
    pf("%I64d\n", ans);
    return 0;
}