#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
ll A, B, n;
bool check(ll l, ll r, ll t, ll m) {
    if (A + (r - 1) * B > t)
        return false;
    if (A * (r - l + 1) + B * (r * (r - 1) / 2 - (l - 1) * (l - 2) / 2) > m * t)
        return false;
    return true;
}
int main() {
    cin >> A >> B >> n;
    for (int i = 0; i < n; ++i) {
        ll l, t, m;
        cin >> l >> t >> m;
        if (!check(l, l, t, m))
            cout << -1 << endl;
        else {
            ll rl = l;
            ll rr = l;
            while (check(l, rr, t, m))
                rr *= 2;
            while (rl + 1 < rr) {
                ll rm = (rl + rr) / 2;
                if (check(l, rm, t, m))
                    rl = rm;
                else
                    rr = rm;
            }
            cout << rl << endl;
        }
    }
    return 0;
}