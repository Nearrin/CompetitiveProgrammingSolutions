#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#define sf scanf
#define pf printf
#define ps for (;;)
#define lp(i, a, b) for (int i = a; i <= b; ++i)
#define rp(i, a, b) for (int i = a; i >= b; --i)
using namespace std;
int n;
vector<int> to[100010];
double ans;
int hei[100010];
int main() {
    sf("%d", &n);
    lp(i, 1, n - 1) {
        int a, b;
        sf("%d%d", &a, &b);
        to[a].push_back(b);
        to[b].push_back(a);
    }
    queue<int> qu;
    qu.push(1);
    hei[1] = 1;
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        lp(i, 0, int(to[u].size() - 1)) {
            if (!hei[to[u][i]]) {
                hei[to[u][i]] = hei[u] + 1;
                qu.push(to[u][i]);
            }
        }
    }
    lp(i, 1, n) ans += 1.0 / hei[i];
    pf("%.10lf\n", ans);
    // ps;
    return 0;
}