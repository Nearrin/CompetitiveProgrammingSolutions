#include <iostream>

using namespace std;

int main() {
    int a[2], b[2], c[2];
    cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1];
    int ans = 0;
    for (int i = 0; i <= 1; ++i)
        for (int j = 0; j <= 1; ++j)
            for (int k = 0; k <= 1; ++k) {
                if (b[j] + c[k] <= a[i] && b[j ^ 1] <= a[i ^ 1] &&
                    c[k ^ 1] <= a[i ^ 1]) {
                    ans = 1;
                }
            }
    if (ans)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}