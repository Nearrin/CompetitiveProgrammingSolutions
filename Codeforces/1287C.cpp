#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <limits>
#include <random>
#include <set>
#include <string>
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
typedef vector<pii> vpii;
template <class T> T sqra(T a) { return a * a; }
ll modu = 1e9 + 7;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll addi(ll a, ll b, ll p = modu) { return (a + b) % p; }
ll subs(ll a, ll b, ll p = modu) { return (a - b + p) % p; }
ll mult(ll a, ll b, ll p = modu) { return a * b % p; }
ll powe(ll a, ll b, ll p = modu, ll r = 1) {
    b ? (r = powe(a, b / 2, p), r = r * r % p * (b % 2 ? 1 : a) % p) : 0;
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
static int vis[110][110][2];
static int mem[110][110][2];
int f(const vi &a, int i, int has_0, int has_1, int tail_val) {
    if (vis[i][has_0][tail_val])
        return mem[i][has_0][tail_val];
    vis[i][has_0][tail_val] = 1;
    int this_f = infi<int>() - 10;
    if (a[i] != -1) {
        if (tail_val != a[i]) {
            // do nothing
        } else {
            if (i == 0) {
                this_f = 0;
            } else {
                this_f = min(f(a, i - 1, has_0, has_1, 0) + (a[i] != 0),
                             f(a, i - 1, has_0, has_1, 1) + (a[i] != 1));
            }
        }
    } else {
        if (tail_val == 0 && !has_0) {

        } else if (tail_val == 1 && !has_1) {

        } else {
            if (tail_val == 0)
                has_0--;
            else
                has_1--;
            if (i == 0) {
                this_f = 0;
            } else {
                this_f = min(f(a, i - 1, has_0, has_1, 0) + (tail_val != 0),
                             f(a, i - 1, has_0, has_1, 1) + (tail_val != 1));
            }
            if (tail_val == 0)
                has_0++;
            else
                has_1++;
        }
    }
    mem[i][has_0][tail_val] = this_f;
    // cout << i << " " << has_0 << " " << has_1 << " " << tail_val << " "
    //     << this_f << endl;
    return this_f;
}
int main() {
    fast;
    int n;
    cin >> n;
    vi a(n);
    int cnt_0 = 0, cnt_1 = 0;
    lp(i, 0, n - 1) {
        int p;
        cin >> p;
        if (!p)
            a[i] = -1;
        else
            a[i] = p % 2;
        if (a[i] == 0)
            cnt_0 += 1;
        else if (a[i] == 1)
            cnt_1 += 1;
    }
    int has_0 = n / 2 - cnt_0, has_1 = n - n / 2 - cnt_1;
    cout << min(f(a, n - 1, has_0, has_1, 0), f(a, n - 1, has_0, has_1, 1))
         << endl;
    return 0;
}