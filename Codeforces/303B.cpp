#include <algorithm>
#include <cstdio>
#define sf scanf
#define pf printf
#define ps for (;;)
#define fr freopen
#define lp(i, a, b) for (int i = a; i <= b; ++i)
#define rp(i, a, b) for (int i = a; i >= b; --i)
using namespace std;
typedef long long ll;
ll n, m, x, y, a, b;
ll gcd(ll u, ll v) { return v ? gcd(v, u % v) : u; }
int main() {
    sf("%I64d%I64d%I64d%I64d%I64d%I64d", &n, &m, &x, &y, &a, &b);
    ll d = gcd(a, b);
    a /= d, b /= d;
    ll t = min(n / a, m / b);
    a *= t, b *= t;
    ll x1 = 0, y1 = 0, x2 = a, y2 = b;
    if (x1 + x2 < x * 2) {
        ll l = 0, r = n - a;
        if (x1 + r + x2 + r < x * 2)
            x1 += r, x2 += r;
        else {
            while (l + 1 < r) {
                ll m = (l + r) / 2;
                if (x1 + m + x2 + m < x * 2)
                    l = m;
                else
                    r = m;
            }
            if (x1 + r + x2 + r == x * 2)
                x1 += r, x2 += r;
            else
                x1 += l, x2 += l;
        }
    }
    if (y1 + y2 < y * 2) {
        ll l = 0, r = m - b;
        if (y1 + r + y2 + r < y * 2)
            y1 += r, y2 += r;
        else {
            while (l + 1 < r) {
                ll m = (l + r) / 2;
                if (y1 + m + y2 + m < y * 2)
                    l = m;
                else
                    r = m;
            }
            if (y1 + r + y2 + r == y * 2)
                y1 += r, y2 += r;
            else
                y1 += l, y2 += l;
        }
    }
    pf("%I64d %I64d %I64d %I64d\n", x1, y1, x2, y2);
    // ps;
    return 0;
}