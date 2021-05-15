#include <algorithm>
#include <cmath>
#include <cstdio>
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
struct Event {
    int tp; // 0 add 1 remove
    int x;
    int id; // lecture idx
};
bool operator<(const Event &e1, const Event &e2) { return e1.x < e2.x; }
bool exist(const vpii &a, const vpii &b) {
    int n = a.size();
    vector<Event> e;
    lp(i, 0, n - 1) {
        Event t;
        t.tp = 0;
        t.x = a[i].first;
        t.id = i;
        e.push_back(t);
        t.tp = 1;
        t.x = a[i].second + 1;
        t.id = i;
        e.push_back(t);
    }
    sort(e.begin(), e.end());
    set<pii> lft, rht;
    lp(i, 0, e.size() - 1) {
        int j = i;
        while (j + 1 < e.size() && e[j + 1].x == e[j].x)
            ++j;
        lp(k, i, j) {
            if (e[k].tp == 0) {
                lft.insert(make_pair(b[e[k].id].first, e[k].id));
                rht.insert(make_pair(b[e[k].id].second, e[k].id));
            } else {
                lft.erase(make_pair(b[e[k].id].first, e[k].id));
                rht.erase(make_pair(b[e[k].id].second, e[k].id));
            }
        }
        // cout << "at" << e[i].x << " " << lft.size() << " " << rht.size()
        //     << endl;
        // cout << lft.rbegin()->first << " " << rht.begin()->first << endl;
        if (lft.size() && lft.rbegin()->first > rht.begin()->first)
            return true;

        i = j;
    }
    return false;
}
int main() {
    fi;
    int n;
    cin >> n;
    vpii a(n), b(n);
    lp(i, 0, n - 1) {
        cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second;
    }
    if (exist(a, b) || exist(b, a)) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}