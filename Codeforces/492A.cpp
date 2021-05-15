#include <algorithm>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
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
#define vp(i, a) for (int i = 0; i < int(a.size()); ++i)
#define wp(i, a) for (int i = int(a.size()) - 1; i >= 0; --i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
bool check(ll t, ll n) {
    return (t * (t + 1) * (2 * t + 1) / 6 + t * (t + 1) / 2) / 2 <= n;
}
int main() {
    ll n;
    cin >> n;
    ll l = 1, r = 1;
    while (check(r, n))
        r *= 2;
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        if (check(m, n))
            l = m;
        else
            r = m;
    }
    cout << l << endl;
    return 0;
}