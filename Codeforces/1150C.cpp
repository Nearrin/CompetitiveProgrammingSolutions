#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if (t == 1)
            c1 += 1;
        else
            c2 += 1;
    }
    vector<int> a;
    if (c1 == 0) {
        a = vector<int>(c2, 2);
    } else if (c2 == 0) {
        a = vector<int>(c1, 1);
    } else {
        a.push_back(2);
        a.push_back(1);
        for (int i = 1; i < c2; ++i)
            a.push_back(2);
        for (int i = 1; i < c1; ++i)
            a.push_back(1);
    }
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i];
        if (i + 1 == a.size())
            cout << endl;
        else
            cout << " ";
    }
    return 0;
}