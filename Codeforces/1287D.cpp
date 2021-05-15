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
vector<int> child[2010];
int cnt[2010];
vpii build(int x) {
    if (!child[x].size()) {
        if (cnt[x] != 0) {
            return vpii();
        } else {
            return vpii(1, make_pair(1, x));
        }
    } else {
        vpii ret;
        for (auto c : child[x]) {
            vpii tmp = build(c);
            if (tmp.size() == 0)
                return vpii();
            int prv = ret.size();
            for (auto t : tmp)
                ret.push_back(make_pair(t.first + prv, t.second));
        }
        if (cnt[x] > ret.size())
            return vpii();
        int val = cnt[x] + 1;
        lv(i, ret) if (ret[i].first >= val) ret[i].first += 1;
        ret.push_back(make_pair(val, x));
        return ret;
    }
}
int main() {
    fast;
    int n;
    cin >> n;
    lp(i, 1, n) {
        int p, c;
        cin >> p >> c;
        cnt[i] = c;
        child[p].push_back(i);
    }
    int root = child[0][0];
    vpii assi = build(root);
    if (assi.size() == 0) {
        cout << "NO" << endl;
        return 0;
    }
    static int ans[2010];
    for (auto v : assi)
        ans[v.second] = v.first;
    cout << "YES" << endl;
    lp(i, 1, n) {
        cout << ans[i];
        if (i == n)
            cout << endl;
        else
            cout << " ";
    }
    return 0;
}