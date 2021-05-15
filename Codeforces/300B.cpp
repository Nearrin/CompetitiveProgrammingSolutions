#include <algorithm>
#include <cstdio>
#include <vector>
#define sf scanf
#define pf printf
#define ps for (;;)
#define lp(i, a, b) for (int i = a; i <= b; ++i)
#define rp(i, a, b) for (int i = a; i >= b; --i)
using namespace std;
int n, m, vis[110];
vector<int> to[110], ns;
vector<vector<int>> he[4];
void dfs(int u) {
    ns.push_back(u);
    vis[u] = 1;
    lp(i, 0, int(to[u].size() - 1)) {
        if (!vis[to[u][i]]) {
            dfs(to[u][i]);
        }
    }
}
int main() {
    sf("%d%d", &n, &m);
    lp(i, 1, m) {
        int a, b;
        sf("%d%d", &a, &b);
        to[a].push_back(b);
        to[b].push_back(a);
    }
    int can = 1;
    lp(i, 1, n) {
        if (!vis[i]) {
            ns.clear();
            dfs(i);
            if (ns.size() > 3) {
                can = 0;
                break;
            } else
                he[ns.size()].push_back(ns);
        }
    }
    if (can == 0)
        pf("-1\n");
    else {
        if (he[2].size() > he[1].size())
            pf("-1\n");
        else {
            int i = 0, j = 0, k = 0;
            for (; k < he[3].size(); ++k) {
                lp(l, 0, int(he[3][k].size() - 1)) pf(
                    "%d%c", he[3][k][l], l + 1 == he[3][k].size() ? '\n' : ' ');
            }
            for (; j < he[2].size(); ++j) {
                lp(l, 0, int(he[2][j].size() - 1)) pf("%d ", he[2][j][l]);
                pf("%d\n", he[1][i][0]);
                ++i;
            }
            for (; i < he[1].size(); i += 3) {
                pf("%d %d %d\n", he[1][i][0], he[1][i + 1][0], he[1][i + 2][0]);
            }
        }
    }
    // ps;
    return 0;
}