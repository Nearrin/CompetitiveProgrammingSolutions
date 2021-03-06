#include <algorithm>
#include <cstdio>
#include <vector>
#define sf scanf
#define pf printf
#define ps for (;;)
#define fr freopen
#define pb push_back
#define lp(i, a, b) for (int i = a; i <= b; ++i)
#define rp(i, a, b) for (int i = a; i >= b; --i)
using namespace std;
typedef long long ll;
namespace isap {
struct edge {
    int v, c;
};
vector<edge> eg;
vector<int> to[20010];
int dis[20010], gap[20010], vcnt;
void add(int u, int v, int c) {
    edge e;
    e.v = v;
    e.c = c;
    to[u].pb(eg.size());
    eg.pb(e);
}
int dfs(int u, int f) {
    if (u == vcnt)
        return f;
    int g = f, mh = vcnt - 1;
    lp(i, 0, int(to[u].size() - 1)) {
        edge &e = eg[to[u][i]], &ev = eg[to[u][i] ^ 1];
        if (e.c) {
            if (dis[e.v] + 1 == dis[u]) {
                int t = dfs(e.v, min(g, e.c));
                e.c -= t, ev.c += t, g -= t;
                if (!g || dis[1] == vcnt)
                    return f - g;
            }
            mh = min(mh, dis[e.v]);
        }
    }
    if (!--gap[dis[u]])
        dis[1] = vcnt;
    ++gap[dis[u] = mh + 1];
    return f - g;
}
int run() {
    int r = 0;
    gap[0] = vcnt;
    while (dis[1] < vcnt)
        r += dfs(1, ~0u >> 1);
    return r;
}
} // namespace isap
int n, m, g, sex[10010];
int main() {
    sf("%d%d%d", &n, &m, &g);
    isap::vcnt = n + m + 2;
    lp(i, 1, n) sf("%d", &sex[i]);
    lp(i, 1, n) {
        int v;
        sf("%d", &v);
        if (!sex[i])
            isap::add(1, i + 1, v), isap::add(i + 1, 1, 0);
        else
            isap::add(i + 1, n + m + 2, v), isap::add(n + m + 2, i + 1, 0);
    }
    int ans = 0;
    lp(i, 1, m) {
        int tsex, w, k, isf;
        sf("%d%d%d", &tsex, &w, &k);
        ans += w;
        lp(j, 1, k) {
            int t;
            sf("%d", &t);
            if (!tsex)
                isap::add(n + 1 + i, t + 1, ~0u >> 1),
                    isap::add(t + 1, n + 1 + i, 0);
            else
                isap::add(n + 1 + i, t + 1, 0),
                    isap::add(t + 1, n + 1 + i, ~0u >> 1);
        }
        sf("%d", &isf);
        if (!tsex)
            isap::add(1, n + 1 + i, w + isf * g), isap::add(n + 1 + i, 1, 0);
        else
            isap::add(n + 1 + i, n + m + 2, w + isf * g),
                isap::add(n + m + 2, n + 1 + i, 0);
    }
    pf("%d\n", ans - isap::run());
    // ps;
    return 0;
}