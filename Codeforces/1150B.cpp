#include <iostream>
#include <vector>
using namespace std;
int n;
char a[110][110];
bool check() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == '#') {
                continue;
            }
            if (j == 0 || j == n - 1)
                return false;
            if (i == n - 1)
                return false;
            if (i == n - 2)
                return false;
            if (a[i + 1][j] == '#' || a[i + 2][j] == '#')
                return false;
            if (a[i + 1][j - 1] == '#' || a[i + 1][j + 1] == '#')
                return false;
            a[i + 1][j] = a[i + 2][j] = a[i + 1][j - 1] = a[i + 1][j + 1] = '#';
            a[i][j] = '#';
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (check())
        cout << "YES" << endl;
    else {
        cout << "NO" << endl;
    }
    return 0;
}