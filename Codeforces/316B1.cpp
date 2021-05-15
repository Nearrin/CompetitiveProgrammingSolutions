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
ll p = 1000000000;
int pr[1010], ind[1010], n, x;
vector<int> item;
int bbp;
int sz[1010];
int f[1010][1010];
int main() {
    sf("%d%d", &n, &x);
    lp(i, 1, n) {
        int a;
        sf("%d", &a);
        if (a)
            pr[i] = a, ind[a] = 1;
    }
    lp(i, 1, n) {
        if (ind[i] == 0) {
            int isbb = 0, siz = 0, tcnt;
            for (int j = i; j; j = pr[j]) {
                if (j == x) {
                    isbb = 1;
                    tcnt = siz;
                }
                ++siz;
            }
            if (isbb)
                bbp = siz - tcnt;
            else
                item.pb(siz);
        }
    }
    f[0][0] = 1;
    lp(i, 1, item.size()) {
        lp(j, 0, n) {
            if (j < item[i - 1])
                f[i][j] = f[i - 1][j];
            else
                f[i][j] = (f[i - 1][j] || f[i - 1][j - item[i - 1]]);
        }
    }
    lp(i, 0, n) if (f[item.size()][i]) pf("%d\n", i + bbp);
    // ps;
    return 0;
}