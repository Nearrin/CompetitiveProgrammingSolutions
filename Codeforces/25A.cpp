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
    int a[110], n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int t;
    if (a[1] % 2 == a[2] % 2)
        t = a[1] % 2;
    else if (a[2] % 2 == a[3] % 2)
        t = a[2] % 2;
    else
        t = a[1] % 2;
    for (int i = 1; i <= n; ++i)
        if (a[i] % 2 != t)
            cout << i << endl;
    return 0;
}