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
struct stu {
    int idx;
    int wat;
    int gt;
};
int main() {
    deque<stu> stus;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        stu t;
        t.idx = i + 1;
        cin >> t.wat;
        t.gt = 0;
        stus.push_back(t);
    }
    int lst;
    while (stus.size()) {
        stu t = stus.front();
        stus.pop_front();
        t.gt += m;
        if (t.gt < t.wat)
            stus.push_back(t);
        else {
            lst = t.idx;
        }
    }
    cout << lst << endl;
    return 0;
}