#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s.size() > 10)
            cout << *s.begin() << s.size() - 2 << *s.rbegin() << endl;
        else
            cout << s << endl;
    }
    // for(;;);
    return 0;
}