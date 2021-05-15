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
const int vmx = 10000000;
ll isp[vmx + 10], pri[vmx + 10], low[vmx + 10];
int pct;
ll cnt[vmx + 10];
ll gty(ll n, ll p) {
    ll r = 0;
    while (n) {
        r += n / p;
        n /= p;
    }
    return r;
}
bool check(ll x) {
    lp(i, 1, pct) {
        if (gty(x, pri[i]) < cnt[pri[i]])
            return false;
    }
    return true;
}
int main() {
    for (ll i = 2; i <= vmx; ++i) {
        if (!isp[i])
            pri[++pct] = i, low[i] = i;
        for (int j = 1; j <= pct && pri[j] * i <= vmx; ++j) {
            isp[pri[j] * i] = 1;
            low[pri[j] * i] = pri[j];
        }
    }
    // lp(i,1,10)pf("%I64d\n",low[i]);
    ll l = 1, r = 0;
    int k;
    sf("%d", &k);
    lp(i, 1, k) {
        ll t;
        sf("%I64d", &t);
        ++cnt[t];
        r += t;
    }
    for (ll i = vmx; i >= 2; --i)
        cnt[i] += cnt[i + 1];
    for (ll i = vmx; i >= 2; --i) {
        if (low[i] != i) {
            cnt[low[i]] += cnt[i];
            cnt[i / low[i]] += cnt[i];
        }
    }
    if (check(l))
        pf("1\n");
    else {
        while (l + 1 < r) {
            ll m = (l + r) / 2;
            if (check(m))
                r = m;
            else
                l = m;
        }
        pf("%I64d\n", r);
    }
    // ps;
    return 0;
}