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
#define wp(i, v) for (int i = int(v.size()) - 1; i >= 0; --i)
typedef long long ll;
using namespace std;
#include <iostream>
ll x1[110], y1[110], x2[110], y2[110], n;
ll inf = ~0u >> 1;
ll xmi = inf, xmx = -inf, ymi = inf, ymx = -inf;
int main() {
    cin >> n;
    lp(i, 1, n) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        xmi = min(xmi, x1[i]);
        xmx = max(xmx, x2[i]);
        ymi = min(ymi, y1[i]);
        ymx = max(ymx, y2[i]);
    }
    if (xmx - xmi != ymx - ymi)
        cout << "NO" << endl;
    else {
        ll t = (xmx - xmi) * (xmx - xmi);
        lp(i, 1, n) t -= (x2[i] - x1[i]) * (y2[i] - y1[i]);
        if (t == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    // ps;
    return 0;
}