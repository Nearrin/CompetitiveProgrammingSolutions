#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s[1] == '+')
            ++ans;
        else
            --ans;
    }
    cout << ans << endl;
    return 0;
}