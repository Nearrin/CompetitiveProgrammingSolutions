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

int main() {
    int n;
    ll A;
    sf("%d", &n);
    cin >> A;
    static int d[200010];
    ll sd = 0;
    lp(i, 1, n) sf("%d", d + i), sd += d[i];
    lp(i, 1, n) {
        ll t1 = A - (sd - d[i]);
        ll t2 = A - (n - 1);
        t1 = max(1ll, t1);
        t2 = min(ll(d[i]), t2);
        pf("%d%c", int(t1 - 1 + d[i] - t2), (i == n ? '\n' : ' '));
    }
    return 0;
}