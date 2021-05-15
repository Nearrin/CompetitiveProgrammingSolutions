#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
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
#define si(a) scanf("%d", &a)
#define pf printf
#define pi(a) printf("%d", a)
#define fr freopen
#define ps for (;;)
#define pb push_back
#define mp make_pair
#define lp(i, a, b) for (int i = a; i <= int(b); ++i)
#define rp(i, a, b) for (int i = int(a); i >= b; --i)
#define vp(i, a) for (int i = 0; i < int(a.size()); ++i)
#define wp(i, a) for (int i = int(a.size()) - 1; i >= 0; --i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <typename FLOW> class MaximumFlow {
  private:
    class edge {
      public:
        int v;
        FLOW c, l;
        inline edge(const int &_v, const FLOW &_c) : v(_v), c(_c), l(_c) {}
    };
    std::vector<edge> edges;
    std::vector<std::vector<int>> start;
    std::vector<int> height, gap, cur, from;
    int n, source, sink;
    inline void label() {
        height[sink] = 0;
        std::queue<int> qu;
        qu.push(sink);
        while (!qu.empty()) {
            int u = qu.front();
            qu.pop();
            for (int i = 0; i < start[u].size(); ++i) {
                edge &e = edges[start[u][i]], &ev = edges[start[u][i] ^ 1];
                if (ev.c != FLOW(0) && height[e.v] == n) {
                    height[e.v] = height[u] + 1;
                    qu.push(e.v);
                }
            }
        }
        for (int i = 0; i < n; ++i)
            ++gap[height[i]];
    }
    inline FLOW augment() {
        FLOW f = 0;
        for (int u = sink; u != source; u = edges[from[u] ^ 1].v)
            if (f == FLOW(0) || f > edges[from[u]].c)
                f = edges[from[u]].c;
        for (int u = sink; u != source; u = edges[from[u] ^ 1].v) {
            edges[from[u]].c -= f;
            edges[from[u] ^ 1].c += f;
        }
        return f;
    }

  public:
    inline MaximumFlow(const int &_n, const int &_source, const int &_sink)
        : start(_n), height(_n, _n), gap(_n + 1), n(_n), cur(_n), from(_n),
          source(_source), sink(_sink) {}
    inline std::vector<edge> &Edges() { return edges; }
    inline std::vector<std::vector<int>> &Start() { return start; }
    inline void AddEdge(const int &u, const int &v, const FLOW &c) {
        start[u].push_back(edges.size());
        edges.push_back(edge(v, c));
        start[v].push_back(edges.size());
        edges.push_back(edge(u, 0));
    }
    inline FLOW Run() {
        label();
        FLOW r = 0;
        int u = source;
        while (height[source] != n) {
            if (u == sink) {
                r += augment();
                u = source;
            }
            bool flag = false;
            for (int &i = cur[u]; i < start[u].size(); ++i) {
                edge &e = edges[start[u][i]];
                if (e.c != FLOW(0) && height[u] == height[e.v] + 1) {
                    flag = true;
                    from[e.v] = start[u][i];
                    u = e.v;
                    break;
                }
            }
            if (!flag) {
                int mh = n - 1;
                for (int i = 0; i < start[u].size(); ++i) {
                    edge &e = edges[start[u][i]];
                    if (e.c != FLOW(0) && mh > height[e.v])
                        mh = height[e.v];
                }
                if (!--gap[height[u]])
                    break;
                ++gap[height[u] = mh + 1];
                cur[u] = 0;
                if (u != source)
                    u = edges[from[u] ^ 1].v;
            }
        }
        return r;
    }
};
class MaximumBipartiteMatching {
  private:
    MaximumFlow<int> flow;
    int xcnt, ycnt;
    std::vector<int> res;

  public:
    inline MaximumBipartiteMatching(const int &_xcnt, const int &_ycnt)
        : xcnt(_xcnt), ycnt(_ycnt), res(_xcnt, -1),
          flow(_xcnt + _ycnt + 2, _xcnt + _ycnt, _xcnt + _ycnt + 1) {}
    inline void AddEdge(const int &x, const int &y) {
        flow.AddEdge(x, y + xcnt, 1);
    }
    inline int Run() {
        for (int i = 0; i < xcnt; ++i)
            flow.AddEdge(xcnt + ycnt, i, 1);
        for (int i = xcnt; i < xcnt + ycnt; ++i)
            flow.AddEdge(i, xcnt + ycnt + 1, 1);
        int r = flow.Run();
        for (int i = 0; i < xcnt; ++i)
            for (int j = 0; j < flow.Start()[i].size(); ++j)
                if (flow.Edges()[flow.Start()[i][j]].v != xcnt + ycnt &&
                    !flow.Edges()[flow.Start()[i][j]].c) {
                    res[i] = flow.Edges()[flow.Start()[i][j]].v - xcnt;
                    break;
                }
        return r;
    }
    inline const std::vector<int> &Result() { return res; }
};
int main() {
    int n, m;
    cin >> n >> m;
    MaximumBipartiteMatching mbm(n, n);
    lp(i, 1, m) {
        int u, v;
        cin >> u >> v;
        mbm.AddEdge(u - 1, v - 1);
        mbm.AddEdge(v - 1, u - 1);
    }
    cout << n - mbm.Run() << endl;
    return 0;
}
