#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    if (k > (n - 1) * (n - 2) / 2) {
        cout << -1 << endl;
        return 0;
    }
    cout << n - 1 + (n - 1) * (n - 2) / 2 - k << endl;
    for (int i = 2; i <= n; ++i) {
        cout << 1 << " " << i << endl;
        for (int j = i + 1; j <= n; ++j)
            if (k < (n - 1) * (n - 2) / 2)
                ++k, cout << i << " " << j << endl;
    }
    return 0;
}