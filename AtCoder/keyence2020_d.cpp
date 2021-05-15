#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(2));
    for (int i = 0; i < n; ++i)
        cin >> a[i][0];
    for (int i = 0; i < n; ++i)
        cin >> a[i][1];
    int c = ~0u >> 1;
    for (int m = 0; m < (1 << n); ++m) {
        vector<int> b(n);
        iota(begin(b), end(b), 0);
        int t = 0;
        auto d = [&](int i) { return a[b[i]][m >> b[i] & 1]; };
        for (int i = 0; i < n; ++i) {
            int j = i;
            for (int k = i; k < n; ++k)
                if (d(k) < d(j) ||
                    (d(k) == d(j) && ((b[j] ^ i ^ m >> b[j]) & 1)))
                    j = k;
            if ((b[j] ^ i ^ m >> b[j]) & 1) {
                t = ~0u >> 1;
                break;
            }
            int e = b[j];
            for (int k = j; k != i; --k)
                ++t, b[k] = b[k - 1];
            b[i] = e;
        }
        c = min(c, t);
    }
    cout << (c == ~0u >> 1 ? -1 : c) << endl;
    return 0;
}