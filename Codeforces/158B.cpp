#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;
int main() {
    int a[10] = {0}, n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        ++a[t];
    }
    int ans = 0;
    ans += a[4];
    if (a[1] >= a[3]) {
        ans += a[3];
        a[1] -= a[3];
        if (a[1] / 2 >= a[2]) {
            ans += a[2];
            a[1] -= a[2] * 2;
            ans += (a[1] + 3) / 4;
        } else {
            ans += (a[1] + 1) / 2;
            a[2] -= (a[1] + 1) / 2;
            ans += (a[2] + 1) / 2;
        }
    } else {
        ans += a[1];
        a[3] -= a[1];
        ans += a[3];
        ans += (a[2] + 1) / 2;
    }
    cout << ans << endl;
    return 0;
}