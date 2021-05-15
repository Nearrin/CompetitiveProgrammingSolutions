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
#include <cstring>
int bg[6] = {0, 1, 10, 100, 1000, 10000};
int ed[6] = {0, 9, 99, 999, 9999, 99999};
char str[11];
int len;
int main() {
    sf("%s", str + 1);
    len = strlen(str + 1);
    int ans = 0;
    lp(i, bg[len], ed[len]) {
        static char str2[11];
        int t = i;
        lp(j, 1, len) str2[j] = t % 10, t /= 10;
        reverse(str2 + 1, str2 + len + 1);
        int flg = 1;
        lp(j, 1, len) {
            if (str[j] >= '0' && str[j] <= '9') {
                if (str2[j] + '0' != str[j])
                    flg = 0;
            } else if (str[j] != '?') {
                lp(k, j + 1, len) {
                    if (str[k] == str[j]) {
                        if (str2[k] != str2[j])
                            flg = 0;
                    } else if (str[k] >= 'A' && str[k] <= 'Z') {
                        if (str2[k] == str2[j])
                            flg = 0;
                    }
                }
            }
        }
        // if(flg)pf("[%d]\n",i);
        ans += flg;
    }
    pf("%d\n", ans);
    // ps;
    return 0;
}