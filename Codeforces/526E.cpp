#include <algorithm>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
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
#define vp(i, a) for (int i = 0; i < int(a.size()); ++i)
#define wp(i, a) for (int i = int(a.size()) - 1; i >= 0; --i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int n, q, a[1000010 * 2], b[1000010 * 2];
int main() {
    sf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
        sf("%d", a + i), a[i + n] = a[i];
    for (int i = 1; i <= q; ++i) {
        ll qb = 0;
        cin >> qb;
        int p = 1;
        ll ts = 0;
        for (int j = 1; j <= 2 * n; ++j) {
            while (p <= 2 * n && ts + a[p] <= qb) {
                ts += a[p];
                ++p;
            }
            b[j] = p;
            ts -= a[j];
        }
        int ml = 3 * n, mlp = -1;
        for (int j = 1; j <= n; ++j)
            if (b[j] - j < ml)
                ml = b[j] - j, mlp = j;
        // for(int j=1;j<=2*n;++j)
        // cout<<b[j]-j<<endl;
        // cout<<ml<<" "<<mlp<<endl;

        mlp += n;

        p = 2 * n;
        ts = 0;
        for (int j = 2 * n; j >= 1; --j) {
            while (p >= 1 && ts + a[p] <= qb) {
                ts += a[p];
                --p;
            }
            b[j] = p;
            ts -= a[j];
        }
        int ans = 3 * n;
        for (int j = 0; j < ml; ++j) {
            int yy = mlp + j;
            if (yy > 2 * n)
                yy -= n;
            // cout<<yy<<endl;
            int t = yy;
            int tans = 0;
            while (t > yy - n) {
                ++tans;
                t = b[t];
            }
            ans = min(ans, tans);
        }
        pf("%d\n", ans);
    }
    return 0;
}