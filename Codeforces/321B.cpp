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
#include <functional>
#include <iostream>
#include <string>
vector<int> ax, dx, y;
int n, m, ans;
int solve1() {
    int ret = 0;
    for (int i = 1; i <= min(ax.size(), y.size()); ++i) {
        vector<int> tmp1, tmp2;
        for (int j = 0; j < i; ++j)
            tmp1.pb(ax[j]);
        for (int j = y.size() - i; j < y.size(); ++j)
            tmp2.pb(y[j]);
        int flg = 0;
        for (int j = 0; j < i; ++j)
            if (tmp1[j] > tmp2[j])
                flg = 1;
        if (!flg) {
            int tmp = 0;
            vp(j, tmp1) tmp -= tmp1[j];
            vp(j, tmp2) tmp += tmp2[j];
            ret = max(ret, tmp);
        }
    }
    return ret;
}
int solve2() {
    if (dx.size() > y.size())
        return 0;
    vp(i, dx) {
        vector<int>::iterator it = upper_bound(y.begin(), y.end(), dx[i]);
        if (it == y.end())
            return 0;
        y.erase(it);
    }
    if (ax.size() > y.size())
        return 0;
    vp(i, ax) if (ax[i] > y[y.size() - ax.size() + i]) return 0;
    int ret = 0;
    vp(i, ax) ret -= ax[i];
    vp(i, y) ret += y[i];
    return ret;
}
int main() {
    sf("%d%d", &n, &m);
    lp(i, 1, n) {
        string u;
        int v;
        cin >> u >> v;
        if (u == "ATK")
            ax.pb(v);
        else
            dx.pb(v);
    }
    lp(i, 1, m) {
        int v;
        sf("%d", &v);
        y.pb(v);
    }
    sort(ax.begin(), ax.end());
    sort(dx.begin(), dx.end());
    sort(y.begin(), y.end());
    int t = solve1();
    t = max(t, solve2());
    pf("%d\n", t);
    // ps;
    return 0;
}
/*
4 8
DEF 100
DEF 200
DEF 300
ATK 100
100
101
201
301
1
1
1
1
*/