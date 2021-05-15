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
    vi a;
    sf("%d", &n);
    lp(i, 1, n) {
        int t;
        sf("%d", &t);
        a.push_back(t);
    }
    ll ans = 0;
    vector<int> tmp;
    sort(a.begin(), a.end(), std::greater<int>());
    for (int i = 0; i + 1 < a.size(); ++i) {
        if (a[i] == a[i + 1] || a[i] == a[i + 1] + 1) {
            tmp.pb(a[i + 1]);
            ++i;
        }
    }
    for (int i = 0; i + 1 < tmp.size(); i += 2)
        ans += ll(tmp[i]) * tmp[i + 1];
    cout << ans << endl;
    return 0;
}