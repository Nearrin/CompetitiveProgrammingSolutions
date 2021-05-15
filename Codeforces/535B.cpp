#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
typedef long long ll;
ll calc(ll n) {
    stringstream ss;
    ss << n;
    string sn;
    ss >> sn;
    ll ans = 0;
    ans += (1 << sn.size()) - 2;
    for (int i = 0; i < sn.size(); ++i) {
        if (sn[i] == '4')
            continue;
        ans += (1 << (int(sn.size()) - 1 - i));
    }
    return ans + 1;
}
int main() {
    ll n;
    cin >> n;
    cout << calc(n) << endl;
    return 0;
}