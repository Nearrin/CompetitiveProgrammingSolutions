#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
#define sf scanf
#define pf printf
#define ps for (;;)
#define fr freopen
#define pb push_back
#define mp make_pair
#define lp(i, a, b) for (int i = a; i <= b; ++i)
#define rp(i, a, b) for (int i = a; i >= b; --i)
#define vp(i, v) for (int i = 0; i < v.size(); ++i)
#define wp(i, v) for (int i = int(v.size() - 1); i >= 0; --i)
typedef long long ll;
using namespace std;
int w[4010][4010], n, k;
int cost(int i, int j) {
    return (w[j][j] - w[i - 1][j] - w[j][i - 1] + w[i - 1][i - 1]) / 2;
}
int dp[810][4010];
void calc(int i, int jl, int jr, int vl, int vr) {
    if (jl > jr)
        return;
    // pf("[%d,%d,%d,%d,%d]\n",i,jl,jr,vl,vr);
    int m = (jl + jr) / 2, opt = -1;
    lp(k, vl, min(vr, m - 1)) if (opt == -1 ||
                                  dp[i][m] > dp[i - 1][k] + cost(k + 1, m)) {
        opt = k;
        dp[i][m] = dp[i - 1][k] + cost(k + 1, m);
    }
    calc(i, jl, m - 1, vl, opt);
    calc(i, m + 1, jr, opt, vr);
}
int main() {
    sf("%d%d\n", &n, &k);
    lp(i, 1, n) {
        static char buff[10010];
        gets(buff + 1);
        lp(j, 1, n) w[i][j] = buff[2 * j - 1] - '0';
    }
    // lp(i,1,n)lp(j,1,n)pf("%d%c",w[i][j],j==n?'\n':' ');
    lp(i, 1, n) lp(j, 1, n) w[i][j] +=
        w[i - 1][j] + w[i][j - 1] - w[i - 1][j - 1];
    // lp(i,1,n)lp(j,1,n)pf("%d%c",w[i][j],j==n?'\n':' ');
    // lp(i,1,n)lp(j,i+1,n)pf("%d,%d,%d\n",i,j,cost(i,j));
    lp(i, 1, n) dp[1][i] = cost(1, i);
    lp(i, 2, k) calc(i, i, n, i - 1, n);
    pf("%d\n", dp[k][n]);
    return 0;
}