#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#define lp(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define rp(i, r, l) for (int i = int(r); i >= int(l); --i)
#define ls(i, s) for (int i = 0; s[i]; ++i)
#define rs(i, s) for (int i = strlen(s) - 1; i >= 0; --i)
#define lv(i, a) for (int i = 0; i < int(a.size()); ++i)
#define rv(i, a) for (int i = int(a.size()) - 1; i >= 0; --i)
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define prec(a) cout << setprecision(a) << fixed
#define freo freopen
#define many for (int T = -1; T < 0 && cin >> T, T--;)
#define appl(f, a) for (auto i = begin(a); i != end(a); f, ++i)
#define rang(a) begin(a), end(a)
#define gene template <class T>
#define elif else if
#define intm modular_arithmetic::integer
#ifndef LOCAL
#define endl '\n'
#define assert
#endif
using namespace std;
using namespace __gnu_pbds;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
gene T rint(T l, T r) { return uniform_int_distribution<T>(l, r)(rng); }
template <class A, class B> B conv(const A &a, B b = B()) {
    stringstream s;
    s << a, s >> b;
    return b;
}
vector<string> spli(const string &s) {
    vector<string> r;
    for (int i = 0, j; i < int(s.size()); ++i)
        if (s[i] != ' ') {
            r.push_back("");
            for (j = i; j < int(s.size()) && s[j] != ' '; ++j)
                r.back().push_back(s[j]);
            i = j - 1;
        }
    return r;
}
template <class T = int> T inf() { return numeric_limits<T>::max(); }
gene T floor(const T &a, const T &b) {
    assert(b != 0);
    return (a > 0 && b > 0 || a < 0 && b < 0) ? abs(a) / abs(b)
                                              : -(abs(a) + abs(b) - 1) / abs(b);
}
gene T ceil(const T &a, const T &b) {
    assert(b != 0);
    return (a > 0 && b > 0 || a < 0 && b < 0) ? (abs(a) + abs(b) - 1) / abs(b)
                                              : -abs(a) / abs(b);
}
gene bool tmin(T &a, T b) { return b < a ? a = b, true : false; }
gene bool tmax(T &a, T b) { return b > a ? a = b, true : false; }
#if __cplusplus >= 201402L
gene auto min(const T &a) { return *min_element(rang(a)); }
gene auto max(const T &a) { return *max_element(rang(a)); }
gene auto sum(const T &a) {
    return accumulate(rang(a), (typename T::value_type)0);
}
template <class T, int N, class I>
auto gath(const T (&a)[N], const vector<I> &b) {
    vector<T> r;
    for (auto i : b)
        r.push_back(a[i]);
    return r;
}
template <class T, class I> auto gath(const T &a, const vector<I> &b) {
    vector<typename T::value_type> r;
    for (auto i : b)
        r.push_back(a[i]);
    return r;
}
#endif
template <class T, class C = less<typename T::value_type>>
void sort(T &a, C c = C()) {
    sort(rang(a), c);
}
gene void reve(T &a) { reverse(rang(a)); }
gene void uniq(T &a) { sort(a), a.erase(unique(rang(a)), end(a)); }
gene void shuf(T &a) { shuffle(rang(a), rng); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
#if __cplusplus >= 201703L
template <typename... T> void in(T &... a) { ((cin >> a), ...); }
template <typename A, typename... B> void ou(const A &a, const B &... b) {
    cout << a, ((cout << ' ' << b), ...), cout << endl;
}
#endif
template <class F, class S> istream &operator>>(istream &s, pair<F, S> &a) {
    return s >> a.first >> a.second;
}
template <class F, class S>
ostream &operator<<(ostream &s, const pair<F, S> &a) {
    return s << '(' << a.first << ", " << a.second << ')';
}
gene istream &operator>>(istream &s, vector<T> &a) {
    for (int i = -1; i < 0 && (!a.size() && (cin >> i, a.resize(i), 0), i = 0),
             i < int(a.size());)
        s >> a[i++];
    return s;
}
gene ostream &operator<<(ostream &s, const vector<T> &a) {
    lv(i, a) cout << a[i] << (i + 1 == int(a.size()) ? "" : " ");
    return s;
}
gene using bbst =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
gene using heap = __gnu_pbds::priority_queue<T, greater<T>, pairing_heap_tag>;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef string str;
// The templates end here.
struct node {
    node(int v_ = 0) {
        v = v_;
        c[0] = c[1] = 0;
        p = 0;
    }
    bool leaf() { return !c[0] && !c[1]; }
    void cut() {
        assert(p);
        if (p->c[0] == this) {
            p->c[0] = 0;
        } else {
            assert(p->c[1] == this);
            p->c[1] = 0;
        }
        p = 0;
    }
    void link(node *pp) {
        if (!pp->c[0]) {
            pp->c[0] = this;
        } else {
            assert(!pp->c[1]);
            pp->c[1] = this;
        }
        p = pp;
        level = pp->level + 1;
    }
    int v;
    int level;
    node *c[2];
    node *p;
};
void get_s(node *u, int d, int &s) {
    if (!u)
        return;
    u->level = d;
    s += d;
    lp(i, 0, 1) get_s(u->c[i], d + 1, s);
}
int main() {
    fast, prec(12);
    /*
    {
        int n = 10;
        vvi f(n + 1);
        f[0].push_back(0);
        lp(i, 1, n) {
            lp(j, 0, i - 1) {
                int k = i - 1 - j;
                for (auto u : f[j])
                    for (auto v : f[k])
                        f[i].push_back(u + j + v + k);
            }
            uniq(f[i]);
            ou(i);
            ou(f[i]);
        }
    }
    */
    many {
        int n, d;
        in(n, d);
        vector<node> a(n + 1);
        lp(i, 1, n) {
            a[i].v = i;
            if (i * 2 <= n)
                a[i].c[0] = &a[i * 2];
            if (i * 2 + 1 <= n)
                a[i].c[1] = &a[i * 2 + 1];
            if (i != 1)
                a[i].p = &a[i / 2];
        }
        int s = 0;
        get_s(&a[1], 0, s);
        // ou(s);
        if (d < s || d > n * (n - 1) / 2) {
            ou("NO");
        } else {
            ou("YES");
            while (s != d) {
                vi cnt(n);
                lp(i, 1, n) {
                    if (!a[i].c[0] && !a[i].c[1])
                        ++cnt[a[i].level];
                }
                int l = n - 1;
                while (cnt[l] == 0)
                    --l;
                if (cnt[l] > 1) {
                    int u = 1;
                    while (!a[u].leaf() || a[u].level != l) {
                        ++u;
                    }
                    int v = u + 1;
                    while (!a[v].leaf() || a[v].level != l) {
                        ++v;
                    }
                    a[u].cut();
                    a[u].link(&a[v]);
                } else {
                    int r = l - 1;
                    while (cnt[r] == 0)
                        --r;
                    int u = 1;
                    while (!a[u].leaf() || a[u].level != r) {
                        ++u;
                    }
                    int v = 1;
                    while (v == u || a[v].level != r) {
                        ++v;
                    }
                    a[u].cut();
                    a[u].link(&a[v]);
                }
                ++s;
            }
            vi ans;
            lp(i, 2, n) ans.push_back(a[i].p->v);
            ou(ans);
            int s2 = 0;
            // get_s(&a[1], 0, s2);
            // ou(s2);
        }
    }
    return 0;
}
