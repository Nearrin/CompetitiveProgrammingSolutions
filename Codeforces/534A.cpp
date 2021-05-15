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
    cin >> n;
    if (n == 1 || n == 2)
        cout << "1\n1\n";
    else if (n == 3)
        cout << "2\n1 3\n";
    else if (n == 4)
        cout << "4\n3 1 4 2\n";
    else {
        cout << n << endl;
        vi t;
        for (int i = 1; i <= n; i += 2)
            t.pb(i);
        for (int i = 2; i <= n; i += 2)
            t.pb(i);
        vp(i, t) cout << t[i] << (i + 1 == t.size() ? '\n' : ' ');
    }
    return 0;
}