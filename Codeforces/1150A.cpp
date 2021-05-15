#include <algorithm>
#include <iostream>
#include <vector>
#define inf (~0u >> 1)
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    int n, m, r;
    cin >> n >> m >> r;
    int s = inf, b = -inf;
    for (size_t i = 0; i < n; i++) {
        int t;
        cin >> t;
        s = min(s, t);
    }
    for (size_t i = 0; i < m; i++) {
        int t;
        cin >> t;
        b = max(b, t);
    }
    if (b <= s) {
        cout << r << endl;
    } else {
        cout << r % s + r / s * b << endl;
    }
    return 0;
}