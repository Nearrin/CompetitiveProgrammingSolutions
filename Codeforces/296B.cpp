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
typedef long long ll;
char s[100010], w[100010];
int n;
ll p = 1000000007ll, all = 1, big = 1, sma = 1, equ = 1;
int main() {
    sf("%d%s%s", &n, s + 1, w + 1);
    lp(i, 1, n) if (s[i] == '?') all = all * 10 % p;
    lp(i, 1, n) if (w[i] == '?') all = all * 10 % p;
    lp(i, 1, n) {
        if (s[i] == '?' && w[i] == '?')
            big = big * 55 % p;
        else if (s[i] == '?')
            big = big * (9 - (w[i] - '0') + 1) % p;
        else if (w[i] == '?')
            big = big * (s[i] - '0' + 1) % p;
        else if (s[i] < w[i])
            big = 0;
    }
    lp(i, 1, n) {
        if (s[i] == '?' && w[i] == '?')
            sma = sma * 55 % p;
        else if (s[i] == '?')
            sma = sma * (w[i] - '0' + 1) % p;
        else if (w[i] == '?')
            sma = sma * (9 - (s[i] - '0') + 1) % p;
        else if (s[i] > w[i])
            sma = 0;
    }
    lp(i, 1, n) {
        if (s[i] == '?' && w[i] == '?')
            equ = equ * 10 % p;
        else if (s[i] == '?')
            equ *= 1;
        else if (w[i] == '?')
            equ *= 1;
        else if (w[i] != s[i])
            equ = 0;
    }
    ll ans = ((all - big - sma + equ) % p + p) % p;
    pf("%I64d\n", ans);
    // ps;
    return 0;
}