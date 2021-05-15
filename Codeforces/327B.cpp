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
ll pri[10000010], isp[10000010];
int main() {
    for (ll i = 2; i <= 10000000; ++i) {
        if (!isp[i])
            pri[++pri[0]] = i;
        for (ll j = 1; j <= pri[0] && i * pri[j] <= 10000000; ++j) {
            isp[i * pri[j]] = 1;
            if (i % pri[j] == 0)
                break;
        }
    }
    int n;
    sf("%d", &n);
    lp(i, 1, n) pf("%I64d%c", pri[i], i == n ? '\n' : ' ');
    return 0;
}