#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
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
#define make make_pair
#define vali_0(x, y, n, m) (x >= 0 && x < n && y >= 0 && y < m)
#define vali_1(x, y, n, m) (x > 0 && x <= n && y > 0 && y <= m)
#pragma GCC optimize("O3")
using namespace std;
using namespace __gnu_pbds;
template <class T> void sort(vector<T> &a) { sort(rang(a)); }
template <class T> void reverse(vector<T> &a) { reverse(rang(a)); }
template <class T> T min(const vector<T> &a) { return *min_element(rang(a)); }
template <class T> T max(const vector<T> &a) { return *max_element(rang(a)); }
template <class T> T sum(const vector<T> &a) { return accumulate(rang(a), 0); }
int rand_int(int n) {
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
template <class T> T squr(T a) { return a * a; }
template <class T> int upda_l(T &a, T b) { return b < a ? a = b, 1 : 0; }
template <class T> int upda_g(T &a, T b) { return b > a ? a = b, 1 : 0; }
template <class T> istream &operator>>(istream &s, pair<T, T> &a) {
    return s >> a.first >> a.second;
}
template <class T> istream &operator>>(istream &s, vector<T> &a) {
    if (!a.size()) {
        int n;
        s >> n;
        a = vector<T>(n);
    }
    lp(i, 0, a.size() - 1) s >> a[i];
    return s;
}
template <class T> ostream &operator<<(ostream &s, const pair<T, T> &a) {
    return s << '(' << a.first << ", " << a.second << ')';
}
template <class T> ostream &operator<<(ostream &s, const vector<T> &a) {
    lv(i, a) cout << a[i] << (i + 1 == a.size() ? "" : " ");
    return s;
}
namespace numb_theo {
ll modu = 1e9 + 7;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll exte_gcd(ll a, ll b, ll &x, ll &y) {
    if (!b)
        return x = 1, y = 0, a;
    else {
        ll d = exte_gcd(b, a % b, y, x);
        y -= a / b * x;
        return d;
    }
} // namespace numb_theo
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll gamm(ll a) { return a ? gamm(a - 1) * a % modu : 1; }
ll addi(ll a, ll b, ll p = modu) { return (a + b) % p; }
ll subs(ll a, ll b, ll p = modu) { return (a - b + p) % p; }
ll mult(ll a, ll b, ll p = modu) { return a * b % p; }
ll powe(ll a, ll b, ll p = modu, ll r = 1) {
    b ? (r = powe(a, b / 2, p), r = r * r % p * (b % 2 ? a : 1) % p) : 0;
    return r;
}
ll inve_sing(ll a, ll p = modu) { return powe(a, p - 2); }
ll inve_all(ll a, ll p = modu) {
    static vector<ll> t(2, 1);
    while (t.size() <= a)
        t.push_back((p - (p / t.size())) * t[p % t.size()] % p);
    return t[a];
}
ll divi(ll a, ll b, ll p = modu) { return a * inve_sing(b, p) % p; }
template <class T> vector<pair<T, T>> fact(T n) {
    vector<pair<T, T>> a;
    for (T i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            T t = 0;
            for (; n % i == 0; n /= i, ++t)
                ;
            a.push_back(make(i, t));
        }
    }
    if (n != 1)
        a.push_back(make(n, 1));
    return a;
}
vi mobi(int n) {
    vi p, ntp(n + 1), u(n + 1);
    ntp[1] = 1;
    u[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!ntp[i])
            p.push_back(i), u[i] = -1;
        for (int j = 0; j < p.size() && p[j] * i <= n; ++j) {
            ntp[p[j] * i] = 1;
            if (i % p[j] == 0)
                break;
            else
                u[p[j] * i] = -u[i];
        }
    }
    return u;
}
} // namespace numb_theo
namespace comp_geom {
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
} // namespace comp_geom
namespace data_stru {
template <class T>
using rb_tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using pair_heap =
    __gnu_pbds::priority_queue<int, greater<int>, pairing_heap_tag>;
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
struct info_coun {
    info_coun(int t = 0) : c(t) {}
    void operator+=(const info_coun &i) { c += i.c; }
    int c;
};
struct info_labe {
    info_labe() {}
    info_labe(int t) : c(1, t) {}
    void operator+=(const info_labe &i) {
        for (auto t : i.c)
            c.push_back(t);
    }
    vi c;
};
int trie_n = 0;
template <class I = info_coun, int S = 26> struct trie {
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
} // namespace data_stru
namespace stri_algo {
template <class T> vector<int> matc(const T &a, const T &b) {
    vector<int> r, p(b.size(), -1);
    int j;
    lp(i, 1, int(b.size() - 1)) {
        j = p[i - 1];
        for (; j != -1 && b[j + 1] != b[i]; j = p[j])
            ;
        p[i] = j + (b[j + 1] == b[i]);
    }
    j = -1;
    lv(i, a) {
        for (; j != -1 && b[j + 1] != a[i]; j = p[j])
            ;
        j += (b[j + 1] == a[i]);
        if (j + 1 == b.size()) {
            r.push_back(i - j);
            j = p[j];
        }
    }
    return r;
}
} // namespace stri_algo
void dfs(vvi &to, vi &vis, int u) {
    vis[u] = 1;
    for (auto v : to[u])
        if (!vis[v])
            dfs(to, vis, v);
}
int main() {
    fast;
    ll n_edge = 0;
    vpii a;
    cin >> a;
    vpii e;
    int n = 0;
    for (auto v : a) {
        e.push_back(make(v.first, ++n));
        e.push_back(make(v.second, -n));
    }
    sort(e);
    set<pii> st;
    vpii edges;
    for (auto v : e) {
        if (v.second > 0) {
            for (auto i = st.begin();
                 i != st.end() && i->first < a[v.second - 1].second; ++i) {
                ++n_edge;
                edges.push_back(make(v.second - 1, i->second - 1));
                if (n_edge >= n)
                    break;
            }
            st.insert(make(a[v.second - 1].second, v.second));
            ;
        } else {
            st.erase(make(a[-v.second - 1].second, -v.second));
        }
    }
    // cout << edges << endl;
    if (n_edge != n - 1) {
        cout << "NO" << endl;
    } else {
        vvi to(n);
        for (auto v : edges) {
            to[v.first].push_back(v.second);
            to[v.second].push_back(v.first);
        }
        vi vis(n);
        dfs(to, vis, 0);
        // cout << vis << endl;
        if (sum(vis) != vis.size()) {
            cout << "NO" << endl;
        } else
            cout << "YES" << endl;
    }
    return 0;
}