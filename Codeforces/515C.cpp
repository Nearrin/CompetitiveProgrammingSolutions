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
    string a;
    cin >> a;
    int tb[11] = {0};
    vp(i, a) {
        if (a[i] == '4')
            ++tb[2], ++tb[2], ++tb[3];
        else if (a[i] == '6')
            ++tb[5], ++tb[3];
        else if (a[i] == '8')
            ++tb[7], tb[2] += 3;
        else if (a[i] == '9')
            tb[3] += 2, tb[2]++, tb[7]++;
        else
            ++tb[a[i] - '0'];
    }
    for (int i = 9; i >= 2; --i)
        for (int j = 1; j <= tb[i]; ++j)
            cout << i;
    cout << endl;
    return 0;
}