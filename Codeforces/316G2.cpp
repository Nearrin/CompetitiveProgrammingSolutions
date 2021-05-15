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
#include <iostream>
#include <string>
namespace tam {
int tr[1200010][26], pr[1200010], ln[1200010], nw, cnt[1200010][11];
int make() {
    ++nw;
    return nw;
}
void init() {
    nw = 0;
    make();
}
int add(int c, int lst) {
    if (tr[lst][c]) {
        int p = lst, q = tr[lst][c];
        if (ln[q] == ln[p] + 1)
            return q;
        else {
            int np = make();
            ln[np] = ln[p] + 1;
            pr[np] = pr[q];
            copy(tr[q], tr[q] + 26, tr[np]);
            pr[q] = np;
            for (; p && tr[p][c] == q; p = pr[p])
                tr[p][c] = np;
            return np;
        }
    } else {
        int p = lst, np = make();
        ln[np] = ln[p] + 1;
        for (; p && !tr[p][c]; p = pr[p])
            tr[p][c] = np;
        if (!p)
            pr[np] = 1;
        else {
            int q = tr[p][c];
            if (ln[p] + 1 == ln[q])
                pr[np] = q;
            else {
                int nq = make();
                ln[nq] = ln[p] + 1;
                pr[nq] = pr[q];
                copy(tr[q], tr[q] + 26, tr[nq]);
                pr[q] = pr[np] = nq;
                for (; p && tr[p][c] == q; p = pr[p])
                    tr[p][c] = nq;
            }
        }
        return np;
    }
}
void dfs(int u, string t) {
    cout << t << endl;
    lp(i, 0, 25) {
        if (tr[u][i]) {
            string t2 = t;
            t2.pb(i + 'a');
            dfs(tr[u][i], t2);
        }
    }
}
} // namespace tam
void print(int x, string t) {
    cout << t << endl;
    int y;
    lp(i, 0, 25) if (y = tam::tr[x][i]) {
        string u = t;
        u.push_back(i + 'a');
        print(y, u);
    }
}
using namespace tam;
int lft[11], rght[11], n;
char tmp[50010];
bool cmp(int x, int y) { return ln[x] > ln[y]; }
int main() {
    init();
    sf("%s", tmp + 1);
    for (int u = 1, i = 1; tmp[i]; ++i) {
        u = add(tmp[i] - 'a', u);
        ++cnt[u][0];
    }
    sf("%d", &n);
    lp(i, 1, n) {
        sf("%s%d%d", tmp + 1, &lft[i], &rght[i]);
        for (int u = 1, j = 1; tmp[j]; ++j) {
            u = add(tmp[j] - 'a', u);
            ++cnt[u][i];
        }
    }
    // print(1,"");return 0;
    static int tmp[600010 * 2];
    lp(i, 1, nw) tmp[i] = i;
    sort(tmp + 1, tmp + nw + 1, cmp);
    lp(i, 1, nw) {
        int u = tmp[i];
        lp(j, 0, n) cnt[pr[u]][j] += cnt[u][j];
    }
    ll ans = 0;
    lp(i, 1, nw) {
        int flg = 1;
        lp(j, 1, n) if (cnt[i][j] >= lft[j] && cnt[i][j] <= rght[j]) {}
        else flg = 0;
        if (flg && cnt[i][0])
            ans += ln[i] - ln[pr[i]];
    }
    pf("%I64d\n", ans);
    // ps;
    return 0;
}