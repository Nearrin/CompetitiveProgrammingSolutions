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
struct node {
    node() {
        lp(i, 0, 2) ch[i] = 0;
        cnt = 0;
    }
    node *ch[3];
    int cnt;
};
node root;
void insert(const string &s) {
    node *n = &root;
    for (auto c : s) {
        int i;
        if (c == 'S')
            i = 0;
        else if (c == 'E')
            i = 1;
        else
            i = 2;
        if (!n->ch[i]) {
            n->ch[i] = new node;
        }
        n = n->ch[i];
    }
    n->cnt += 1;
}
int count(const string &s) {
    node *n = &root;
    for (auto c : s) {
        int i;
        if (c == 'S')
            i = 0;
        else if (c == 'E')
            i = 1;
        else
            i = 2;
        if (!n->ch[i]) {
            return 0;
        }
        n = n->ch[i];
    }
    return n->cnt;
}
int main() {
    fast;
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    lv(i, s) {
        cin >> s[i];
        insert(s[i]);
    }
    ll ans = 0;
    lp(i, 0, n - 1) {
        lp(j, i + 1, n - 1) {
            string t1 = s[i];
            const string &t2 = s[j];
            lv(k, t1) {
                char c1 = t1[k], c2 = t2[k];
                if (c1 != c2) {
                    if (c1 > c2)
                        swap(c1, c2);
                    // EST
                    if (c1 == 'E' && c2 == 'S')
                        t1[k] = 'T';
                    else if (c1 == 'E' && c2 == 'T')
                        t1[k] = 'S';
                    else
                        t1[k] = 'E';
                }
            }
            ll other = count(t1);
            if (t1 == s[i])
                other--;
            if (t1 == s[j])
                other--;
            ans += other;
        }
    }
    cout << ans / 3 << endl;
    return 0;
}