#include <algorithm>
#include <cstdio>
#include <vector>
#define sf scanf
#define pf printf
#define ps for (;;)
#define lp(i, a, b) for (int i = a; i <= b; ++i)
#define rp(i, a, b) for (int i = a; i >= b; --i)
using namespace std;
vector<int> a, b, c;
int main() {
    int n;
    sf("%d", &n);
    lp(i, 1, n) {
        int t;
        sf("%d", &t);
        if (t < 0)
            a.push_back(t);
        else if (t > 0)
            b.push_back(t);
        else
            c.push_back(t);
    }
    if (a.size() % 2 == 0) {
        c.push_back(a.back());
        a.pop_back();
    }
    if (b.size() == 0) {
        b.push_back(a.back());
        a.pop_back();
        b.push_back(a.back());
        a.pop_back();
    }
    pf("%d ", a.size());
    lp(i, 0, int(a.size() - 1))
        pf("%d%c", a[i], i + 1 == a.size() ? '\n' : ' ');
    pf("%d ", b.size());
    lp(i, 0, int(b.size() - 1))
        pf("%d%c", b[i], i + 1 == b.size() ? '\n' : ' ');
    pf("%d ", c.size());
    lp(i, 0, int(c.size() - 1))
        pf("%d%c", c[i], i + 1 == c.size() ? '\n' : ' ');
    // ps;
    return 0;
}