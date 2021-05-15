#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s >> s;
    for (int i = 0; i < s.size(); ++i)
        s[i] = tolower(s[i]);
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    cout << (s.size() == 26 ? "YES\n" : "NO\n");
    // for(;;);
    return 0;
}