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
#include <cstring>
char s[100010];
int l, zero;
int cnt[210];
char tag;
ll ans = 1;
int main() {
    sf("%s", s + 1);
    l = strlen(s + 1);
    if (s[1] == '0')
        pf("0\n");
    else {
        lp(i, 1, l) {
            if (s[i] == '?') {
                if (i == 1)
                    ans *= 9;
                else
                    ++zero;
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                if (i == 1)
                    tag = s[i];
                cnt[s[i]] = 1;
            }
        }
        int tc = 0;
        lp(i, 'A', 'Z') tc += cnt[i];
        if (tag) {
            if (tc > 10)
                pf("0\n");
            else {
                int mo = 9;
                ans *= 9;
                lp(i, 1, tc - 1) ans *= mo, --mo;
                pf("%I64d", ans);
                lp(i, 1, zero) pf("0");
                pf("\n");
            }
        } else {
            if (tc > 10)
                pf("0\n");
            else {
                if (tc)
                    ++zero;
                int mo = 9;
                lp(i, 2, tc) ans *= mo, --mo;
                pf("%I64d", ans);
                lp(i, 1, zero) pf("0");
                pf("\n");
            }
        }
    }
    // ps;
    return 0;
}