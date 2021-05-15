#include <iostream>

using namespace std;

int main() {
    int n, k, a[110];
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int p = k;
    while (p < n && a[p] == a[p + 1])
        ++p;
    while (p > 0 && a[p] == 0)
        --p;
    cout << p << endl;
    // for(;;);
    return 0;
}