#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for (;;)
#define pb push_back
#define mp make_pair
#define lp(i, a, b) for (int i = a; i <= b; ++i)
#define rp(i, a, b) for (int i = a; i >= b; --i)
#define vp(i, v) for (int i = 0; i < v.size(); ++i)
#define wp(i, v) for (int i = int(v.size() - 1); i >= 0; --i)
typedef long long ll;
using namespace std;
#include <iostream>
#include <string>
int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    ll t1 = 1;
    for (int i = 1; i < s.size(); ++i)
        t1 = t1 * 2 % 1000000007;
    ll t2 = 0, t3 = 1;
    vp(i, s) {
        if (s[i] == '1')
            t2 = (t2 + t3) % 1000000007;
        t3 = t3 * 2 % 1000000007;
    }
    cout << t2 * t1 % 1000000007 << endl;
    // ps;
    return 0;
}