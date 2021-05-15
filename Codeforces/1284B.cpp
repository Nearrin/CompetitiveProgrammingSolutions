#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
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
#define pc(a) cout << setprecision(a) << fixed
#define io(a, b) freopen(#a, "r", stdin), freopen(#b, "w", stdout)
#define fi ios::sync_with_stdio(0)
#define al(a) a.begin(), a.end()
#define va(x, y, n, m) (x > 0 && x <= n && y > 0 && y <= m)
#define vb(x, y, n, m) (x >= 0 && x < n && y >= 0 && y < m)
#define inf (~0u >> 1)
int d4[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int d8[8][2] = {{-1, 0}, {1, 0},  {0, 1}, {0, -1},
                {-1, 1}, {1, -1}, {1, 1}, {-1, -1}};
using namespace std;
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
template <class T = int> vector<T> arr(int n) { return vector<T>(n); }
template <class T = int> vector<vector<T>> mat(int n, int m) {
    return vector<vector<T>>(n, vector<T>(m));
}
template <class T> istream &operator>>(istream &s, vector<T> &a) {
    if (!a.size()) {
        int n;
        s >> n;
        a = arr<T>(n);
    }
    lp(i, 0, a.size() - 1) s >> a[i];
    return s;
}
template <class T> istream &operator>>(istream &s, vector<vector<T>> &a) {
    if (!a.size()) {
        int n, m;
        s >> n >> m;
        a = mat<T>(n, m);
    }
    lp(i, 0, a.size() - 1) lp(j, 0, a[i].size() - 1) s >> a[i][j];
    return s;
}
int main() {
    fi;
    int n;
    cin >> n;
    vector<int> mi, mx, has_a;
    lp(i, 1, n) {
        int this_mi = inf;
        int this_mx = -inf;
        int this_has = 0;
        int l;
        cin >> l;
        int prev;
        lp(j, 1, l) {
            int t;
            cin >> t;
            if (j != 1 && prev < t)
                this_has = 1;
            ckg(this_mx, t);
            ckl(this_mi, t);
            prev = t;
        }
        mi.push_back(this_mi);
        if (this_has)
            this_mx = inf;
        mx.push_back(this_mx);
        has_a.push_back(this_has);
    }
    sort(mx.begin(), mx.end());
    ll ans = 0;
    lp(i, 0, n - 1) {
        if (has_a[i])
            ans += n;
        else {
            ans += mx.end() - upper_bound(mx.begin(), mx.end(), mi[i]);
        }
    }
    cout << ans << endl;
    return 0;
}