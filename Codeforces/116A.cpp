#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    int ans = 0;
    int t = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        t -= a;
        t += b;
        ans = max(ans, t);
    }
    cout << ans << endl;
    return 0;
}