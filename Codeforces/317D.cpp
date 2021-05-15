#include <algorithm>
#include <cstdio>
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
#include <map>
#include <set>
map<int, int> f;
int dp(int x) {
    if (f.find(x) != f.end())
        return f[x];
    if (x == 0)
        return f[x] = 0;
    set<int> s;
    lp(i, 0, 29) {
        if ((x >> i) & 1) {
            int cur = x;
            for (int j = i + 1; j <= 30; j += i + 1)
                if ((cur >> (j - 1)) & 1)
                    cur -= (1 << (j - 1));
            s.insert(dp(cur));
        }
    }
    while (s.find(f[x]) != s.end())
        ++f[x];
    return f[x];
}
int sg[] = {0, 1, 2, 1, 4, 3, 2, 1, 5,  6, 2, 1, 8,  7,  5, 9,
            8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12, 14};
int main() {
    // pf("{");lp(i,0,30)pf("%d%c",dp((1<<i)-1),i==30?'}':',');
    ll n;
    sf("%I64d", &n);
    set<ll> s;
    int ans = 0;
    for (ll i = 2; i * i <= n; ++i) {
        if (s.find(i) != s.end())
            continue;
        int cnt = 0;
        for (ll j = i; j <= n; j *= i) {
            s.insert(j);
            ++cnt;
        }
        ans ^= sg[cnt];
    }
    if ((n - s.size()) & 1)
        ans ^= 1;
    if (ans)
        pf("Vasya\n");
    else
        pf("Petya\n");
    return 0;
}