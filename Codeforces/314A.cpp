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
int main() {
    int n;
    ll k, tsum = 0, tcnt = 1, tsiv;
    sf("%d%I64d", &n, &k);
    tsiv = n;
    lp(i, 1, n) {
        ll a;
        sf("%I64d", &a);
        if (tsum - (tsiv - tcnt) * a * (tcnt - 1) < k) {
            pf("%d\n", i);
            --tsiv;
        } else {
            tsum += a * (tcnt - 1);
            ++tcnt;
        }
    }
    return 0;
}