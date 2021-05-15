#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
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
#define ls(i, s) for (int i = 0; s[i]; ++i)
#define rs(i, s) for (int i = strlen(s) - 1; i >= 0; --i)
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
template <class T> int upda_l(T &a, T b) { return b < a ? a = b, 1 : 0; }
template <class T> int upda_g(T &a, T b) { return b > a ? a = b, 1 : 0; }
namespace number_theory {
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
} // namespace number_theory
namespace computational_geometry {
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
} // namespace computational_geometry
namespace string_algorithms {
int inte(char c) {
    return c >= 'a' ? c - 'a' : (c >= 'A' ? c - 'A' + 26 : c - '0' + 52);
}
vi inte(const char *s) {
    vi r(strlen(s));
    ls(i, s) r[i] = inte(s[i]);
    return r;
}
vi inte(const string &s) {
    vi r(s.size());
    lv(i, s) r[i] = inte(s[i]);
    return r;
}
struct info_1 {
    info_1(int t = 0) : c(t) {}
    void operator+=(const info_1 &i) { c += i.c; }
    int c;
};
struct info_2 {
    info_2() {}
    info_2(int t) : c(1, t) {}
    void operator+=(const info_2 &i) {
        for (auto t : i.c)
            c.push_back(t);
    }
    vi c;
};
int trie_n = 0;
template <class I = info_1, int S = 26> struct trie {
    trie() : c(S), n(++trie_n) {}
    template <class T> void inse(const T &t, const I &j) {
        auto p = this;
        auto s = inte(t);
        for (auto c : s)
            p = p->c[c] ? p->c[c] : (p->c[c] = new trie<I, S>);
        p->i += j;
    }
    template <class T> I quer(const T &t) {
        auto p = this;
        auto s = inte(t);
        for (auto c : s)
            p = p ? p->c[c] : 0;
        return p ? p->i : I();
    }
    I i;
    vector<trie<I, S> *> c;
    int n;
};
} // namespace string_algorithms
using namespace string_algorithms;
vector<int> dfs_stk;
void dfs(trie<info_2> *x, int d, vvi &pos) {
    int st = dfs_stk.size();
    lp(i, 0, 25) if (x->c[i]) dfs(x->c[i], d + 1, pos);
    for (auto t : x->i.c)
        dfs_stk.push_back(t);
    for (int i = st; i < dfs_stk.size(); ++i)
        pos[dfs_stk[i]][d] = x->n;
}
vi dfs2(trie<info_2> *x, int d, vvi &pos, ll &ans) {
    vi cur = x->i.c;
    lp(i, 0, 25) if (x->c[i]) {
        vi tmp = dfs2(x->c[i], d + 1, pos, ans);
        for (auto t : tmp)
            cur.push_back(t);
    }
    vpii cur_sid;
    for (auto i : cur)
        cur_sid.push_back(make_pair(pos[i][d], i));
    sort(rang(cur_sid));
    vi remain;
    for (int i = 0; i < cur_sid.size(); ++i) {
        if (i + 1 == cur_sid.size()) {
            remain.push_back(cur_sid[i].second);
        } else if (cur_sid[i].first != cur_sid[i + 1].first) {
            remain.push_back(cur_sid[i].second);
        } else {
            ans += ll(d) * d;
            i += 1;
        }
    }
    return remain;
}
int main() {
    fast;
    many {
        int n;
        cin >> n;
        trie<info_2> prefix, suffix;
        vvi pos(n + 1);
        lp(i, 1, n) {
            string s;
            cin >> s;
            pos[i].resize(s.size() + 1);
            prefix.inse(s, info_2(i));
            reverse(rang(s));
            suffix.inse(s, info_2(i));
        }
        dfs(&suffix, 0, pos);
        ll ans = 0;
        dfs2(&prefix, 0, pos, ans);
        cout << ans << endl;
    }
    return 0;
}