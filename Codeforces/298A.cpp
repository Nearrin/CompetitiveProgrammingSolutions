#include <algorithm>
#include <cstdio>
#include <vector>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for (;;)
#define lp(i, a, b) for (int i = a; i <= b; ++i)
#define rp(i, a, b) for (int i = a; i >= b; --i)
using namespace std;
char tmp[1010];
int n;
int main() {
    sf("%d%s", &n, tmp + 1);
    int l = 1, r = n;
    while (tmp[l] == '.')
        ++l;
    while (tmp[r] == '.')
        --r;
    if (tmp[l] == 'R' && tmp[r] == 'R')
        pf("%d %d\n", l, r + 1);
    else if (tmp[l] == 'L' && tmp[r] == 'L')
        pf("%d %d\n", r, l - 1);
    else {
        while (tmp[r] == 'L')
            --r;
        pf("%d %d\n", l, r);
    }
    // ps;
    return 0;
}