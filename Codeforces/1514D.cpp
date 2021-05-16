#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> p(n + 1);
    vector<valarray<int>> c(n + 1, valarray<int>(32));
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        p[a].push_back(i);
        c[i] = c[i - 1];
        for (int j = 0; j < 32; ++j)
            c[i][j] += (a >> j) & 1;
    }
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        int v = 0;
        auto clr = c[r] - c[l - 1];
        for (int j = 0; j < 32; ++j)
            v += int(clr[j] > (r - l + 1) / 2) << j;
        int cv = 0;
        if (v < p.size())
            cv = upper_bound(begin(p[v]), end(p[v]), r) -
                 lower_bound(begin(p[v]), end(p[v]), l);
        cout << max(cv - (r - l + 1 - cv), 1) << endl;
    }
    return 0;
}
