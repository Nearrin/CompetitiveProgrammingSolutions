#include <bits/stdc++.h>
using namespace std;
auto bfs(vector<vector<int>> a, int r, int c) {
    vector<vector<int>> d(a.size(), vector<int>(a[0].size(), ~0u >> 1));
    d[r][c] = 0;
    queue<pair<int, int>> q;
    q.push({r, c});
    auto dir = vector<pair<int, int>>{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto [dx, dy] : dir) {
            if (x + dx < 0 || x + dx == a.size() || y + dy < 0 ||
                y + dy == a[0].size() || a[x + dx][y + dy] == -1 ||
                d[x + dx][y + dy] != ~0u >> 1)
                continue;
            d[x + dx][y + dy] = d[x][y] + 1;
            q.push({x + dx, y + dy});
        }
    }
    return move(d);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, w;
    cin >> n >> m >> w;
    vector<vector<int>> a(n, vector<int>(m));
    for (int r = 0; r < n; ++r)
        for (int c = 0; c < m; ++c)
            cin >> a[r][c];
    auto ds = bfs(a, 0, 0), dt = bfs(a, n - 1, m - 1);
    long long ans = numeric_limits<long long>::max(), d1 = ans, d2 = ans;
    if (ds[n - 1][m - 1] != ~0u >> 1)
        ans = min(ans, ds[n - 1][m - 1] * 1ll * w);
    for (int r = 0; r < n; ++r)
        for (int c = 0; c < m; ++c) {
            if (!a[r][c])
                continue;
            if (ds[r][c] != ~0u >> 1)
                d1 = min(d1, ds[r][c] * 1ll * w + a[r][c]);
            if (dt[r][c] != ~0u >> 1)
                d2 = min(d2, dt[r][c] * 1ll * w + a[r][c]);
        }
    if (d1 != numeric_limits<long long>::max() &&
        d2 != numeric_limits<long long>::max())
        ans = min(ans, d1 + d2);
    cout << (ans == numeric_limits<long long>::max() ? -1 : ans) << endl;
    return 0;
}
