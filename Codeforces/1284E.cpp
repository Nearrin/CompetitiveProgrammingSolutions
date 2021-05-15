#pragma GCC optimize("O3")
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define lp(i, l, r) for (int i = l; i <= r; ++i)
#define rp(i, r, l) for (int i = r; i >= l; --i)
#define lv(i, a) for (int i = 0; i < a.size(); ++i)
#define rv(i, a) for (int i = (int)a.size() - 1; i >= 0; --i)
#define mc                                                                     \
    int T;                                                                     \
    cin >> T;                                                                  \
    lp(I, 1, T)
#define fi ios::sync_with_stdio(0)
#define pc(a) cout << setprecision(a) << fixed
#define al(a) a.begin(), a.end()
#define va(x, y, n, m) (x > 0 && x <= n && y > 0 && y <= m)
#define vb(x, y, n, m) (x >= 0 && x < n && y >= 0 && y < m)
#define inf (~0u >> 1)
using namespace std;
int d4[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int d8[8][2] = {{-1, 0}, {1, 0},  {0, 1}, {0, -1},
                {-1, 1}, {1, -1}, {1, 1}, {-1, -1}};
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
template <class T = int> T ipt() {
    T a;
    cin >> a;
    return a;
}
template <class T> T sqr(T a) { return a * a; }
ll mod = 1e9 + 7;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll add(ll a, ll b, ll p = mod) { return (a + b) % p; }
ll sub(ll a, ll b, ll p = mod) { return (a - b + p) % p; }
ll mul(ll a, ll b, ll p = mod) { return a * b % p; }
ll pow(ll a, ll b, ll p = mod, ll r = 1) {
    b ? (r = pow(a, b / 2, p), r = r * r % p * (b % 2 ? 1 : a) % p) : 0;
    return r;
}
ll inv(ll a, ll p = mod) { return pow(a, p - 2); }
ll div(ll a, ll b, ll p = mod) { return a * inv(b, p) % p; }
template <class T> int ckl(T &a, T b) { return b < a ? a = b, 1 : 0; }
template <class T> int ckg(T &a, T b) { return b > a ? a = b, 1 : 0; }
template <class T> struct vec_2d {
    int dir() const {
        return x == 0 ? (y == 0 ? 0 : (y > 0 ? 1 : 2)) : (x > 0 ? 1 : 2);
    }
    T x, y;
};
template <class T> T operator*(const vec_2d<T> &a, const vec_2d<T> &b) {
    return a.x * b.y - b.x * a.y;
}
template <class T> T operator<(const vec_2d<T> &a, const vec_2d<T> &b) {
    int t = a.dir() - b.dir();
    return t ? (t < 0) : (a * b < 0);
}
ll ch3(ll n) {
    if (n < 3)
        return 0;
    return n * (n - 1) * (n - 2) / 6;
}
ll f(const vpii &p, int i) {
    ll s = 0;
    vector<vec_2d<ll>> dts;
    lp(j, 0, p.size() - 1) {
        if (j != i) {
            vec_2d<ll> d;
            d.x = p[j].first - p[i].first;
            d.y = p[j].second - p[i].second;
            dts.push_back(d);
        }
    }
    sort(dts.begin(), dts.end());
    ll n = p.size();
    s = (n - 1) * (n - 2) * (n - 3) * (n - 4) / 24;
    int k = 0;
    lp(j, 0, dts.size() - 1) {
        if (k < j)
            k = j;
        while (dts[j] * dts[(k + 1) % dts.size()] < 0)
            k = k + 1;
        // cout << j << "to" << k << endl;
        s -= ch3(k - j);
    }
    // cout << i << " " << s << endl;
    return s;
}
int main() {
    fi;
    int n;
    cin >> n;
    vpii p(n);
    lp(i, 0, n - 1) cin >> p[i].first >> p[i].second;
    ll s = 0;
    lp(i, 0, n - 1) { s += f(p, i); }
    // f(p, 6);
    cout << s << endl;
    return 0;
}