#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for (;;)
#define lp(i, a, b) for (int i = a; i <= b; ++i)
#define rp(i, a, b) for (int i = a; i >= b; --i)
using namespace std;
typedef long long ll;
int n, m, k;
multiset<int> a, b;
vector<int> c;
ll sum[200010];
int main() {
    sf("%d%d%d", &n, &m, &k);
    lp(i, 1, n) {
        int t;
        sf("%d", &t);
        a.insert(t);
    }
    lp(i, 1, m) {
        int t;
        sf("%d", &t);
        b.insert(t);
    }
    set<int>::iterator i1 = a.begin(), i2 = b.begin();
    while (i1 != a.end() || i2 != b.end()) {
        if (i1 == a.end()) {
            c.push_back(-int(b.count(*i2)));
            i2 = b.upper_bound(*i2);
        } else if (i2 == b.end()) {
            c.push_back(a.count(*i1));
            i1 = a.upper_bound(*i1);
        } else if (*i1 == *i2) {
            c.push_back(int(a.count(*i1)) - int(b.count(*i2)));
            i2 = b.upper_bound(*i2);
            i1 = a.upper_bound(*i1);
        } else if (*i2 < *i1) {
            c.push_back(-int(b.count(*i2)));
            i2 = b.upper_bound(*i2);
        } else {
            c.push_back(a.count(*i1));
            i1 = a.upper_bound(*i1);
        }
    }
    lp(i, 0, int(c.size() - 1)) sum[i + 1] = sum[i] + c[i];
    int f = 0;
    lp(i, 1, c.size() + 1) if (sum[i - 1] + (sum[c.size()] - sum[i - 1]) * k >
                               0) f = 1;
    pf("%s\n", f ? "YES" : "NO");
    // ps;
    return 0;
}