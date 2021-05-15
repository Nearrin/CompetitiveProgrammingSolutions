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
typedef vector<vi> vvi;
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
int main() {
    fast;
    {
        int n, q;
        cin >> n >> q;
        const int N = 100010;
        static int a[N], next1[N], index1[N], next2[N], index2[N];
        lp(i, 1, n) {
            cin >> a[i];
            next1[i] = 0;
            index1[i] = 0;
            next2[i] = 0;
            index2[i] = 0;
            if (i != 1 and a[i - 1] < a[i]) {
                if (next1[i - 1] == 0) {
                    next1[i - 1] = 1;
                    index1[i - 1]++;
                }
                index1[i] = index1[i - 1];
                next1[i] = 1;
            } else if (i != 1) {
                if (next2[i - 1] == 0) {
                    next2[i - 1] = 1;
                    index2[i - 1]++;
                }
                index2[i] = index2[i - 1];
                next2[i] = 1;
            }
            if (i && index1[i] == 0)
                index1[i] = index1[i - 1];
            if (i && index2[i] == 0)
                index2[i] = index2[i - 1];
        }
        int count(int *, int *, int *, int, int, int);
        lp(i, 1, q) {
            int l, r;
            cin >> l >> r;
            if (count(a, next1, index1, l, r, 1) ==
                count(a, next2, index2, l, r, -1))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
int count(int *a, int *next, int *index, int l, int r, int tp) {
    if (tp * a[l] > tp * a[l + 1])
        l += 1;
    if (tp * a[r - 1] > tp * a[r])
        r -= 1;
    if (l > r)
        return 0;
    int sr = index[r];
    int sl = index[l] - next[l];
    return sr - sl;
}