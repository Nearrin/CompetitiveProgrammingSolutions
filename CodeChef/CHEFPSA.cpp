#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <random>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#define lp(i, l, r) for (int i = l; i <= r; ++i)
#define rp(i, r, l) for (int i = r; i >= l; --i)
#define lv(i, a) for (int i = 0; i < a.size(); ++i)
#define rv(i, a) for (int i = (int)a.size() - 1; i >= 0; --i)
#define many                                                                   \
    int T;                                                                     \
    cin >> T;                                                                  \
    lp(I, 1, T)
#define fast ios::sync_with_stdio(0)
#define prec(a) cout << setprecision(a) << fixed
#define rang(a) a.begin(), a.end()
#define vali_1(x, y, n, m) (x > 0 && x <= n && y > 0 && y <= m)
#define vali_2(x, y, n, m) (x >= 0 && x < n && y >= 0 && y < m)
#pragma GCC optimize("O3")
using namespace std;
int rand_i(int n) {
    static mt19937 t(random_device{}());
    return t() % n;
}
template <class T> T infi() { return numeric_limits<T>::max(); }
template <class T = int> T inpu() {
    T a;
    cin >> a;
    return a;
}
int dire_4[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int dire_8[8][2] = {{-1, 0}, {1, 0},  {0, 1}, {0, -1},
                    {-1, 1}, {1, -1}, {1, 1}, {-1, -1}};
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
template <class T> T sqra(T a) { return a * a; }
ll modu = 1e9 + 7;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll fact(ll a) { return a ? fact(a - 1) * a % modu : 1; }
ll addi(ll a, ll b, ll p = modu) { return (a + b) % p; }
ll subs(ll a, ll b, ll p = modu) { return (a - b + p) % p; }
ll mult(ll a, ll b, ll p = modu) { return a * b % p; }
ll powe(ll a, ll b, ll p = modu, ll r = 1) {
    b ? (r = powe(a, b / 2, p), r = r * r % p * (b % 2 ? a : 1) % p) : 0;
    return r;
}
ll inve(ll a, ll p = modu) { return powe(a, p - 2); }
ll divi(ll a, ll b, ll p = modu) { return a * inve(b, p) % p; }
template <class T> int upda_l(T &a, T b) { return b < a ? a = b, 1 : 0; }
template <class T> int upda_g(T &a, T b) { return b > a ? a = b, 1 : 0; }
template <class T> struct vect {
    int dir() const {
        return x == 0 ? (y == 0 ? 0 : (y > 0 ? 1 : 2)) : (x > 0 ? 1 : 2);
    }
    T x, y;
};
template <class T> T operator*(const vect<T> &a, const vect<T> &b) {
    return a.x * b.y - b.x * a.y;
}
template <class T> T operator<(const vect<T> &a, const vect<T> &b) {
    int t = a.dir() - b.dir();
    return t ? (t < 0) : (a * b < 0);
}
struct FastReader {
    FILE *f;
    char *p, *e;
    vector<char> v;
    void ipt() {
        for (int i = 1, t;; i <<= 1) {
            v.resize(v.size() + i);
            if (i != (t = fread(&v[0] + v.size() - i, 1, i, f))) {
                p = &v[0], e = p + v.size() - i + t;
                break;
            }
        }
    }
    void ign() {
        while (p != e && isspace(*p))
            ++p;
    }
    int isc() { return p != e && !isspace(*p); }
    int isd() { return p != e && isdigit(*p); }
    FastReader(FILE *_f) : f(_f) { ipt(); }
    FastReader(string _f) : f(fopen(_f.c_str(), "r")) { ipt(); }
    ~FastReader() { fclose(f); }
    template <class T> FastReader &operator>>(T &a) {
        int n = 1;
        ign();
        if (*p == '-')
            n = -1, ++p;
        for (a = 0; isd();)
            a = (a << 3) + (a << 1) + *p++ - '0';
        a *= n;
        return *this;
    }
    FastReader &operator>>(char &a) {
        ign();
        a = *p++;
        return *this;
    }
    FastReader &operator>>(char *a) {
        for (ign(); isc();)
            *a++ = *p++;
        *a = 0;
        return *this;
    }
    char get() { return *p++; }
};
int main() {
    const int N = 100010;
    static ll powe_2[N];
    powe_2[0] = 1;
    lp(i, 1, N) powe_2[i] = powe_2[i - 1] * 2 % modu;
    static ll rev_fac[N];
    rev_fac[1] = 1;
    lp(i, 2, N) rev_fac[i] = (modu - (modu / i)) * rev_fac[modu % i] % modu;
    lp(i, 2, N) rev_fac[i] = rev_fac[i] * rev_fac[i - 1] % modu;
    // cout << rev_fac[110] << " " << inve(fact(110)) << endl;
    FastReader fr(stdin);
    int T;
    fr >> T;
    while (T--) {
        int n;
        // cin >> n;
        // canf("%d", &n);
        fr >> n;
        ll s = 0;
        unordered_map<int, int> cnt;
        lp(i, 1, 2 * n) {
            int t;
            // cin >> t;
            // scanf("%d", &t);
            fr >> t;
            s += t;
            cnt[t] += 1;
        }
        if (s % (n + 1) != 0) {
            printf("0\n");
            // cout << 0 << endl;
            continue;
        }
        s /= n + 1;
        ll ans = fact(n - 1);
        if (cnt[s] < 2) {
            printf("0\n");
            // cout << 0 << endl;
            continue;
        }
        cnt[s] -= 2;
        if (cnt[s] == 0) {
            cnt.erase(s);
        }
        int fail = 0;
        for (auto t : cnt) {
            int v = t.first, c = t.second;
            int other = s - v;
            if (cnt.count(other) == 0) {
                fail = 1;
                break;
            }
            if (other > v)
                continue;
            if (other == v) {
                if (c % 2 == 1) {
                    fail = 1;
                    break;
                }
                // ans = mult(ans, inve(fact(c / 2)));
                ans = ans * rev_fac[c / 2] % modu;
            }
            if (other < v) {
                if (c != cnt[other]) {
                    fail = 1;
                    break;
                }
                // ans = mult(ans, inve(fact(c)));
                ans = ans * rev_fac[c] % modu;
                // ans = mult(ans, powe(2, c));
                ans = ans * powe_2[c] % modu;
            }
            // cout << v << " " << c << " " << ans << endl;
        }
        if (fail) {
            printf("0\n");
            // cout << 0 << endl;;
            continue;
        }
        printf("%lld\n", ans);
        // cout << ans << endl;
    }
    return 0;
}