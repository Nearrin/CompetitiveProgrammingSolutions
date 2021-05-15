#include <algorithm>
#include <cstdio>
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
#include <iostream>
int main() {
    ll x, y, m;
    cin >> x >> y >> m;
    if (x >= m || y >= m)
        cout << 0 << endl;
    else {
        if (x <= 0 && y <= 0)
            cout << -1 << endl;
        else {
            ll cnt = 0;
            if (x > y)
                swap(x, y);
            if (x < 0) {
                cnt = (-x) % y == 0 ? (-x) / y : (-x) / y + 1;
                x += cnt * y;
            }
            while (x < m && y < m) {
                ll tmp = x + y;
                if (x < y)
                    x = tmp;
                else
                    y = tmp;
                ++cnt;
            }
            cout << cnt << endl;
        }
    }
    return 0;
}