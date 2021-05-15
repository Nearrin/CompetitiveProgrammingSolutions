#include <iostream>
using namespace std;
int main() {
    long long a, b, n;
    cin >> a >> b >> n;
    cout << a * min(n, b - 1) / b << endl;
    return 0;
}