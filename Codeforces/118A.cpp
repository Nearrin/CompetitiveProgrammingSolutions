#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    for_each(s.begin(), s.end(), [](char &c) {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u' ||
            c == 'y') {
        } else {
            cout << '.' << c;
        }
    });
    cout << endl;
    // for(;;);
    return 0;
}