#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#define sf scanf
#define pf printf
#define ps for (;;)
#define fr freopen
#define lp(i, a, b) for (int i = a; i <= b; ++i)
#define rp(i, a, b) for (int i = a; i >= b; --i)
using namespace std;
/*
莫队算法
求区间Σ值*次数*次数
*/
typedef long long ll;
namespace mos {
const int nmx = 200000, qmx = 200000, vmx = 10000000;
int n, sn, cnt[vmx + 10], val[nmx + 10];
ll ans[qmx + 10];
int as;
struct query {
    query(int a, int b) : l(a), r(b), w(++as) {}
    int l, r, w;
};
bool cmp(query a, query b) {
    return (a.l / sn == b.l / sn) ? (a.r < b.r) : (a.l / sn < b.l / sn);
}
vector<query> qs;
void add(int l, int r) { qs.push_back(query(l, r)); }
void solve() {
    sn = int(sqrt(double(n)) + 0.5); //注意sn不能为0
    sort(qs.begin(), qs.end(), cmp);
    ll now = 0, tl = 0, tr = -1; //注意初始化为0和-1
    lp(i, 0, int(qs.size() - 1)) {
        int l = qs[i].l, r = qs[i].r;
        if (tr < l || tl > r) { //和先前区间不相交
            lp(j, tl, tr)-- cnt[val[j]];
            now = 0;
            tl = l;
            tr = r;
            lp(j, tl, tr) {
                now -= ll(cnt[val[j]]) * ll(cnt[val[j]]) * ll(val[j]);
                ++cnt[val[j]];
                now += ll(cnt[val[j]]) * ll(cnt[val[j]]) * ll(val[j]);
            }
        } else {
            while (tl < l) {
                now -= ll(cnt[val[tl]]) * ll(cnt[val[tl]]) * ll(val[tl]);
                --cnt[val[tl]];
                now += ll(cnt[val[tl]]) * ll(cnt[val[tl]]) * ll(val[tl]);
                ++tl;
            }
            while (tl > l) {
                --tl;
                now -= ll(cnt[val[tl]]) * ll(cnt[val[tl]]) * ll(val[tl]);
                ++cnt[val[tl]];
                now += ll(cnt[val[tl]]) * ll(cnt[val[tl]]) * ll(val[tl]);
            }
            while (tr > r) {
                now -= ll(cnt[val[tr]]) * ll(cnt[val[tr]]) * ll(val[tr]);
                --cnt[val[tr]];
                now += ll(cnt[val[tr]]) * ll(cnt[val[tr]]) * ll(val[tr]);
                --tr;
            }
            while (tr < r) {
                ++tr;
                now -= ll(cnt[val[tr]]) * ll(cnt[val[tr]]) * ll(val[tr]);
                ++cnt[val[tr]];
                now += ll(cnt[val[tr]]) * ll(cnt[val[tr]]) * ll(val[tr]);
            }
        }
        ans[qs[i].w] = now;
    }
}
} // namespace mos
int main() {
    int n, m;
    sf("%d%d", &n, &m);
    mos::n = n;
    lp(i, 1, n) sf("%d", &mos::val[i]);
    lp(i, 1, m) {
        int u, v;
        sf("%d%d", &u, &v);
        mos::add(u, v);
    }
    mos::solve();
    lp(i, 1, m) pf("%I64d\n", mos::ans[i]);
    // ps;
    return 0;
}