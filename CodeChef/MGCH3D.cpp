#include <cstdlib>

#include <vector>
namespace ntt {
using namespace std;
typedef long long I;
typedef vector<I> V;
const I P = 33 * (1 << 25) + 1, G = 10;
I mp(I a, I b, I c) {
    I r = 1;
    for (; b; b >>= 1, a = a * a % c)
        if (b % 2)
            r = r * a % c;
    return r;
}
void ntt(V &a, int n, int s) {
    V wm;
    I g = s == 1 ? G : mp(G, P - 2, P);
    for (int i = 0; (1 << i) <= n; ++i)
        wm.push_back(mp(g, (P - 1) / (1 << i), P));
    for (int i = 0; i < n; ++i) {
        int j = 0;
        for (int k = 0; (1 << k) < n; ++k)
            j <<= 1, j += ((i >> k) & 1);
        if (i < j)
            swap(a[i], a[j]);
    }
    for (int i = 1; (1 << i) <= n; ++i) {
        int m = (1 << i);
        V wmk;
        I wt = 1;
        for (int k = 0; k < (m >> 1); ++k) {
            wmk.push_back(wt);
            wt = wt * wm[i] % P;
        }

        for (int j = 0; j < n; j += m) {
            for (int k = 0; k < (m >> 1); ++k) {
                I u = a[j + k], v = wmk[k] * a[j + k + (m >> 1)] % P;
                a[j + k] = u + v;
                if (a[j + k] >= P)
                    a[j + k] -= P;
                I &tmp = a[j + k + (m >> 1)];
                tmp = u - v + P;
                if (tmp >= P)
                    tmp -= P;
            }
        }
    }
}
V con(V &a, V &b) {
    int n = 1;
    while (n < a.size() + b.size() - 1)
        n *= 2;
    V ta(n), tb(n);
    for (int i = 0; i < a.size(); ++i)
        ta[i] = a[i];

    //   vector<ll>a(1837756+1),b=a;
    // n=4194304
    ntt(ta, n, 1);
    long long w = mp(G, (P - 1) / n, P);
    w = mp(w, 1837756, P);
    long long tmp = 1;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            tb[i] = ta[0];
        } else
            tb[i] = ta[n - i];
        tb[i] = tb[i] * tmp % P;
        tmp = tmp * w % P;
    }

    // ntt(tb,n,1);
    for (int i = 0; i < n; ++i)
        ta[i] = ta[i] * tb[i] % P;
    ntt(ta, n, -1);
    V ret(a.size() + b.size() - 1);
    n = mp(n, P - 2, P);
    for (int i = 0; i < ret.size(); ++i)
        ret[i] = ta[i] * n % P;
    return ret;
}
} // namespace ntt
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
#include <cstdio>
struct tri {
    int x, y, z;
    double fm;
};

tri mp[1861937 * 2 + 10];
typedef long long ll;
int main() {
    for (int i = -77; i <= 77; ++i) {
        int ti = i * i * i * i;
        for (int j = -77; j <= 77; ++j) {
            int tj = j * j * j * j;
            for (int k = -77; k <= 77; ++k) {
                int tk = k * k * k * k;
                tri &tmp = mp[i * 155 * 155 + j * 155 + k + 1861937];
                tmp.x = i;
                tmp.y = j;
                tmp.z = k;
                tmp.fm = sqrt((double)(ti + tj + tk));
            }
        }
    }
    int n, q;
    scanf("%d%d", &n, &q);
    vector<ll> a(1837756 + 1), b = a;
    for (int i = 1; i <= n; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        int t = x * 155 * 155 + y * 155 + z;
        ++a[t - 24181];
        ++b[-t + 1861937];
    }
    vector<ll> d = ntt::con(a, b);
    static int nd[10000010], dn2[10000010];
    int nds = 0;
    for (int i = 0; i < d.size(); ++i)
        if (d[i]) {
            ++nds;
            nd[nds] = i;
            dn2[nds] = d[i];
        }
    double tyvj = 1.0 / n / (n - 1);
    for (int i = 1; i <= q; ++i) {
        int qa, qb, qc, qd;
        scanf("%d%d%d%d", &qa, &qb, &qc, &qd);
        double ans = 0;
        for (int j = 1; j <= nds; ++j) {
            int realj = nd[j] - 1837756;
            if (realj == 0)
                continue;
            tri &tmp = mp[realj + 1861937];
            double t1 = qa * tmp.x + qb * tmp.y + qc * tmp.z + qd;
            if (t1 < 0)
                t1 *= -1;
            ans += t1 * dn2[j] * tyvj / tmp.fm;
        }
        ans /= 1;
        printf("%.10lf\n", double(ans));
    }
    return 0;
}