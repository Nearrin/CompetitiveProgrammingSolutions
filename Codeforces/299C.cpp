#include <algorithm>
#include <cstdio>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for (;;)
#define lp(i, a, b) for (int i = a; i <= b; ++i)
#define rp(i, a, b) for (int i = a; i >= b; --i)
using namespace std;
int n;
char s1[2000010], s2[2000010];
int main() {
    sf("%d%s%s", &n, s1 + 1, s2 + 1);
    int c11 = 0, c10 = 0, c01 = 0;
    lp(i, 1, n * 2) {
        if (s1[i] == '1' && s2[i] == '1')
            ++c11;
        else if (s1[i] == '1' && s2[i] == '0')
            ++c10;
        else if (s1[i] == '0' && s2[i] == '1')
            ++c01;
    }
    int vl = 0, vr = 0;
    lp(i, 1, n) {
        // pf("[%d,%d,%d]\n",c11,c10,c01);
        if (c11 != 0)
            --c11, ++vl;
        else if (c10 != 0)
            --c10, ++vl;
        else if (c01 != 0)
            --c01;
        if (c11 != 0)
            --c11, ++vr;
        else if (c01 != 0)
            --c01, ++vr;
        else if (c10 != 0)
            --c10;
        // pf("[%d,%d,%d]\n",c11,c10,c01);
    }
    if (vl == vr)
        pf("Draw\n");
    else if (vl > vr)
        pf("First\n");
    else
        pf("Second\n");
    // ps;
    return 0;
}