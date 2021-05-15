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
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int t = n - max(a + 1, n - b) + 1;
    if (t < 0)
        t = 0;
    cout << t << endl;
    return 0;
}