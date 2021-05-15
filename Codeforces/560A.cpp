#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool has1 = 0;
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        if (t == 1)
            has1 = 1;
    }
    if (has1)
        cout << -1 << endl;
    else
        cout << 1 << endl;
    return 0;
}
 