#include <bits/stdc++.h>
#define lop(i, a, b) for (auto i = a; i <= b; ++i)
#define rlp(i, a, b) for (auto i = a; i >= b; --i)
#define vlp(i, a) for (int i = 0; i < a.size(); ++i)
#define all(a) a.begin(), a.end()
#define sqr(a) ((a) * (a))
#define pub push_back
#define pob pop_back
#define mkp make_pair
#define scf scanf
#define ptf printf
#define inf (~0u >> 1)
namespace CTL {}
using namespace CTL;
using namespace std;
typedef long long lli;
typedef unsigned long long ull;
typedef string str;
typedef vector<int> vei;
typedef vector<string> ves;
typedef map<int, int> mii;
typedef map<str, int> msi;
typedef set<int> sti;
typedef set<str> sts;
typedef pair<int, int> pii;
typedef vector<pii> vii;
#ifndef DOMINATOR_TREE
#define DOMINATOR_TREE
#include <bits/stdc++.h>
namespace CTL {
using namespace std;
struct DominatorTree {
    int n, r;
    vector<vector<int>> to, rto, chd, rsemi;
    vector<int> dfn, res, prt, rdfn, semi, misemi;
    DominatorTree(int _n, int _r)
        : n(_n), r(_r), to(n + 1), rto(n + 1), dfn(n + 1), res(n + 1),
          prt(n + 1), rdfn(1), semi(n + 1), misemi(n + 1), chd(n + 1),
          rsemi(n + 1) {}
    int fd(int a) {
        stack<int> stk;
        for (int b = a; prt[b] != prt[prt[b]]; b = prt[b])
            stk.push(b);
        for (int b; stk.empty() ? 0 : (b = stk.top(), stk.pop(), 1);) {
            if (dfn[semi[misemi[prt[b]]]] < dfn[semi[misemi[b]]])
                misemi[b] = misemi[prt[b]];
            prt[b] = prt[prt[b]];
        }
        return prt[a];
    }
    void add(int a, int b) {
        to[a].push_back(b);
        rto[b].push_back(a);
    }
    void dfs() {
        stack<pair<int, int>> stk;
        semi[r] = r;
        for (stk.push(make_pair(r, 0)); !stk.empty();) {
            int a = stk.top().first, i = stk.top().second;
            stk.pop();
            if (!i)
                dfn[a] = rdfn.size(), rdfn.push_back(a);
            if (i < to[a].size()) {
                stk.push(make_pair(a, i + 1));
                int b = to[a][i];
                if (!semi[b])
                    semi[b] = a, chd[a].push_back(b), stk.push(make_pair(b, 0));
            }
        }
        semi[r] = 0;
    }
    void calcsemi() {
        for (int i = 1; i <= n; ++i)
            prt[i] = i, misemi[i] = i;
        for (int i = rdfn.size() - 1; i >= 1; --i) {
            int a = rdfn[i];
            for (int b : rto[a]) {
                if (!dfn[b])
                    continue;
                if (dfn[b] < dfn[a]) {
                    if (dfn[b] < dfn[semi[a]])
                        semi[a] = b;
                } else {
                    int c = fd(b);
                    if (dfn[semi[c]] < dfn[semi[a]])
                        semi[a] = semi[c];
                    if (dfn[semi[misemi[b]]] < dfn[semi[a]])
                        semi[a] = semi[misemi[b]];
                }
            }
            for (int b : chd[a])
                prt[b] = a;
        }
    }
    void calcres() {
        for (int i = 1; i <= n; ++i)
            prt[i] = i, misemi[i] = i, rsemi[semi[i]].push_back(i);
        for (int i = rdfn.size() - 1; i >= 1; --i) {
            int a = rdfn[i];
            for (int b : rsemi[a]) {
                fd(b);
                int c = misemi[b];
                if (dfn[semi[c]] > dfn[semi[prt[b]]])
                    c = prt[b];
                if (semi[c] == semi[b])
                    res[b] = semi[b];
                else
                    res[b] = -c;
            }
            for (int b : chd[a])
                prt[b] = a;
        }
        for (int i = 1; i < rdfn.size(); ++i) {
            int a = rdfn[i];
            if (res[a] < 0)
                res[a] = res[-res[a]];
        }
    }
    vector<int> run() {
        dfs();
        calcsemi();
        calcres();
        return res;
    }
};
} // namespace CTL
#endif

vector<int> myto[1000010];

int dfs(int u) {
    int r = 1;
    for (int i = 0; i < myto[u].size(); ++i)
        r += dfs(myto[u][i]);
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    DominatorTree dtree(n, 1);
    lop(i, 1, m) {
        int u, v;
        cin >> u >> v;
        dtree.add(u, v);
    }

    auto res = dtree.run();
    for (int i = 1; i <= n; ++i)
        myto[res[i]].push_back(i);
    long long ans = dfs(1) - 1;
    vector<long long> vals;
    for (int i = 0; i < myto[1].size(); ++i) {
        vals.push_back(dfs(myto[1][i]));
    }
    long long sum = 0;
    vlp(i, vals) sum += vals[i];
    sum *= sum;
    vlp(i, vals) sum -= vals[i] * vals[i];
    sum /= 2;
    ans += sum;
    cout << ans << '\n';
    return 0;
}
