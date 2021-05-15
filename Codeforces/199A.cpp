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

int check(int n) {
    while (n != 0) {
        int t = n % 10;
        n /= 10;
        if (t != 4 && t != 7)
            return false;
    }
    return true;
}
int ac(int n) {
    lp(i, 1, n) if (n % i == 0 && check(i)) return true;
    return false;
}
ll f[100010];
int main() {
    f[1] = 0;
    f[2] = 1;
    for (int i = 3; i <= 10000; ++i)
        f[i] = f[i - 1] + f[i - 2];
    ll t;
    cin >> t;
    if (t == 0) {
        cout << "0 0 0\n";
    } else if (t == 1) {
        cout << "1 0 0\n";
    } else {
        int id = 1;
        while (f[id] != t)
            ++id;
        cout << f[id - 2] << " " << f[id - 2] << " " << f[id - 3] << endl;
    }
    return 0;
}