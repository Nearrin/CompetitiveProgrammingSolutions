#include <iostream>
#include <map>
#include <numeric>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<long long, int> a;
    int n, ans;
    cin >> n;
    ans = n + 1;
    for (int i = 0; i < n; ++i) {
        long long v;
        cin >> v;
        map<long long, int> b;
        b[v] = i;
        for (const auto &[g, p] : a) {
            auto h = gcd(g, v);
            b[h] = max(b[h], p);
        }
        a = b;
        if (a.count(1))
            ans = min(ans, i - a[1] + 1);
    }
    if (ans == n + 1)
        ans = -1;
    cout << ans << endl;
    return 0;
}