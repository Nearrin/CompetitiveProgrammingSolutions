#include <algorithm>
#include <cctype>
#include <climits>
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
#define si(a) scanf("%d", &a)
#define pf printf
#define pi(a) printf("%d", a)
#define fr freopen
#define ps for (;;)
#define pb push_back
#define mp make_pair
#define lp(i, a, b) for (int i = a; i <= int(b); ++i)
#define rp(i, a, b) for (int i = int(a); i >= b; --i)
#define vp(i, a) for (int i = 0; i < int(a.size()); ++i)
#define wp(i, a) for (int i = int(a.size()) - 1; i >= 0; --i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
int main() {
    int n, m;
    si(n), si(m);
    vector<pii> a;
    lp(i, 1, m) {
        pii t;
        si(t.first);
        si(t.second);
        a.pb(t);
    }
    int ans = a[0].second;
    if (a[0].first != 1) {
        ans = max(ans, a[0].second + a[0].first - 1);
    }
    if (a[m - 1].first != n) {
        ans = max(ans, a[m - 1].second + n - a[m - 1].first);
    }
    for (int i = 0; i + 1 < m; ++i) {
        int i1 = a[i].first, i2 = a[i + 1].first;
        int a1 = a[i].second, a2 = a[i + 1].second;
        if (a1 > a2)
            swap(a1, a2);
        int t = a2 - a1;
        i1 += t;
        a1 += t;
        if (i1 > i2) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        ans = max(ans, a2);
        ans = max(ans, (i2 - i1) / 2 + a1);
    }
    cout << ans << endl;
    return 0;
}