#include <algorithm>
#include <cstdio>
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
#define vp(i, v) for (int i = 0; i < v.size(); ++i)
#define wp(i, v) for (int i = int(v.size() - 1); i >= 0; --i)
using namespace std;
typedef long long ll;
#include <queue>
namespace costflow {
struct edge {
    int v, c, w;
};
vector<int> to[7010];
vector<edge> eg;
int vcnt;
void add(int u, int v, int c, int w) {
    // pf("(%d,%d,%d,%d)\n",u,v,c,w);
    edge t;
    t.v = v;
    t.c = c;
    t.w = w;
    to[u].pb(eg.size());
    eg.pb(t);
}
int dis[7010], in[7010];
bool spfa() {
    lp(i, 1, vcnt) dis[i] = ~0u >> 1, in[i] = 0;
    dis[1] = 0;
    in[1] = 1;
    queue<int> qu;
    qu.push(1);
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        in[u] = 0;
        vp(i, to[u]) {
            edge &e = eg[to[u][i]], &ev = eg[to[u][i] ^ 1];
            if (e.c && dis[e.v] > dis[u] + e.w) {
                dis[e.v] = dis[u] + e.w;
                if (!in[e.v]) {
                    in[e.v] = 1;
                    qu.push(e.v);
                }
            }
        }
        // pf("[%d,%d]",u,dis[u]);
    }
    return dis[vcnt] != ~0u >> 1;
}
int cst;
int dfs(int u, int f) {
    if (u == vcnt)
        return f;
    int g = f;
    in[u] = 1;
    vp(i, to[u]) {
        edge &e = eg[to[u][i]], &ev = eg[to[u][i] ^ 1];
        if (e.c && dis[e.v] == dis[u] + e.w && !in[e.v]) {
            int t = dfs(e.v, min(g, e.c));
            g -= t, e.c -= t, ev.c += t;
            cst += e.w * t;
            if (!g)
                return f;
        }
    }
    return f - g;
}
int run() {
    while (spfa()) {
        fill(in + 1, in + vcnt + 1, 0);
        while (dfs(1, ~0u >> 1))
            ;
    }
    return cst;
}
} // namespace costflow
int col[110][110], n, m;
int id[110][110], nw = 1;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool ava(int x, int y) { return x > 0 && x <= n && y > 0 && y <= m; }
int main() {
    sf("%d%d", &n, &m);
    lp(i, 1, n) lp(j, 1, m) {
        sf("%d", &col[i][j]);
        id[i][j] = ++nw;
    }
    costflow::vcnt = ++nw;
    lp(x1, 1, n) lp(y1, 1, m) {
        if ((x1 + y1) % 2) {
            costflow::add(1, id[x1][y1], 1, 0);
            costflow::add(id[x1][y1], 1, 0, 0);
            lp(k, 0, 3) {
                int tx = x1 + dir[k][0], ty = y1 + dir[k][1];
                if (ava(tx, ty)) {
                    costflow::add(id[x1][y1], id[tx][ty], 1,
                                  col[x1][y1] != col[tx][ty]);
                    costflow::add(id[tx][ty], id[x1][y1], 0,
                                  -(col[x1][y1] != col[tx][ty]));
                }
            }
        } else {
            costflow::add(id[x1][y1], nw, 1, 0);
            costflow::add(nw, id[x1][y1], 0, 0);
        }
    }
    pf("%d\n", costflow::run());
    // ps;
    return 0;
}