#ifdef LOCAL
#include <header.hpp>
#else
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#endif
#define lp(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define rp(i, r, l) for (int i = int(r); i >= int(l); --i)
#define ls(i, s) for (int i = 0; s[i]; ++i)
#define rs(i, s) for (int i = strlen(s) - 1; i >= 0; --i)
#define lv(i, a) for (int i = 0; i < int(a.size()); ++i)
#define rv(i, a) for (int i = int(a.size()) - 1; i >= 0; --i)
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define prec(a) cout << setprecision(a) << fixed
#define freo freopen
#define many for (int C = 1, T = -1; T < 0 && cin >> T, C <= T; ++C)
#define goog "Case #" + to_string(C) + ":"
#define appl(x, f, a)                                                          \
    for (auto &x : a)                                                          \
    f
#define rang(a) begin(a), end(a)
#define gene template <class T>
#define elif else if
#define intm modular_arithmetic::integer
#define bcnt __builtin_popcount
#ifdef LOCAL
#define debu(...)                                                              \
    {                                                                          \
        vector<string> S(1);                                                   \
        int A = 0;                                                             \
        for (auto V : #__VA_ARGS__) {                                          \
            if (V == ',' && !A)                                                \
                S.push_back("");                                               \
            elif (S.back().size() || V != ' ') S.back().push_back(V),          \
                A += map<char, int>{{'(', 1}, {')', -1}}[V];                   \
        }                                                                      \
        cout << "\x1b[33mDebugging @ Line " << __LINE__ << ":\x1b[0m\n";       \
        debu_(S.begin(), __VA_ARGS__);                                         \
    }
#else
#define endl '\n'
#undef assert
#define assert
#define debu(...)
#endif
using namespace std;
using namespace __gnu_pbds;
template <class I, class T> void debu_(I i, const T &a) {
    cout << "\x1b[33m    " << *i << " = " << a << "\x1b[0m" << endl;
}
template <class I, class A, class... B>
void debu_(I i, const A &a, const B &... b) {
    cout << "\x1b[33m    " << *i << " = " << a << "\x1b[0m" << endl;
    debu_(++i, b...);
}
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
template <class T = int> T inf() { return numeric_limits<T>::max() / 2; }
gene T sign(const T &a) { return a == 0 ? 0 : (a < 0 ? -1 : 1); }
gene T floor(const T &a, const T &b) {
    assert(b != 0);
    return sign(a) * sign(b) > 0 ? abs(a) / abs(b)
                                 : -(abs(a) + abs(b) - 1) / abs(b);
}
gene T ceil(const T &a, const T &b) {
    assert(b != 0);
    return sign(a) * sign(b) > 0 ? (abs(a) + abs(b) - 1) / abs(b)
                                 : -abs(a) / abs(b);
}
gene bool tmin(T &a, T b) { return b < a ? a = b, true : false; }
gene bool tmax(T &a, T b) { return b > a ? a = b, true : false; }
gene auto min(const T &a) { return *min_element(rang(a)); }
gene auto max(const T &a) { return *max_element(rang(a)); }
gene auto sum(const T &a) {
    return accumulate(rang(a), (typename T::value_type)0);
}
template <> auto sum(const vector<int> &a) { return accumulate(rang(a), 0ll); }
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
template <class T, class C = less<typename T::value_type>>
void sort(T &a, C c = C()) {
    sort(rang(a), c);
}
gene void reve(T &a) { reverse(rang(a)); }
gene void uniq(T &a) { sort(a), a.erase(unique(rang(a)), end(a)); }
gene void shuf(T &a) { shuffle(rang(a), rng); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
gene auto vect(const vector<T> &v, int n) {
    assert(v.size() <= 1);
    return v.size() ? vector<T>(n, v[0]) : vector<T>(n);
}
template <class T, class... D> auto vect(const vector<T> &v, int n, D... m) {
    return vector<decltype(vect(v, m...))>(n, vect(v, m...));
}
gene void in(T &a) { cin >> a; }
template <class A, class... B> void in(A &a, B &... b) { cin >> a, in(b...); }
void ou() { cout << endl; }
gene void ou(const T &a) { cout << a << endl; }
template <class A, class... B> void ou(const A &a, const B &... b) {
    cout << a << ' ', ou(b...);
}
template <class F, class S> istream &operator>>(istream &s, pair<F, S> &a) {
    return s >> a.first >> a.second;
}
template <class F, class S>
ostream &operator<<(ostream &s, const pair<F, S> &a) {
    return s << a.first << " " << a.second;
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
gene struct hash_safe {};
template <> struct hash_safe<int> {
    size_t operator()(uint64_t a) const {
        static uint64_t d =
            chrono::steady_clock::now().time_since_epoch().count();
        a += d + 0x9e3779b97f4a7c15, a = (a ^ (a >> 30)) * 0xbf58476d1ce4e5b9;
        a = (a ^ (a >> 27)) * 0x94d049bb133111eb;
        return a ^ (a >> 31);
    }
};
template <> struct hash_safe<int64_t> {
    size_t operator()(uint64_t a) const {
        static uint64_t d =
            chrono::steady_clock::now().time_since_epoch().count();
        a += d + 0x9e3779b97f4a7c15, a = (a ^ (a >> 30)) * 0xbf58476d1ce4e5b9;
        a = (a ^ (a >> 27)) * 0x94d049bb133111eb;
        return a ^ (a >> 31);
    }
};
gene using unordered_set_safe = unordered_set<T, hash_safe<T>>;
gene using unordered_multiset_safe = unordered_multiset<T, hash_safe<T>>;
template <class K, class V>
using unordered_map_safe = unordered_map<K, V, hash_safe<K>>;
template <class K, class V>
using unordered_multimap_safe = unordered_multimap<K, V, hash_safe<K>>;
#define unordered_set unordered_set_safe
#define unordered_multiset unordered_multiset_safe
#define unordered_map unordered_map_safe
#define unordered_multimap unordered_multimap_safe
gene using bbst =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
gene using heap = __gnu_pbds::priority_queue<T, greater<T>, pairing_heap_tag>;
typedef int64_t ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<pii> vpii;
typedef vector<pil> vpil;
typedef vector<pli> vpli;
typedef vector<pll> vpll;
typedef string str;
// The templates end here.
int vun_queen(vvi a) {
    int n = a.size();
    int sx, sy;
    lp(i, 0, n - 1) lp(j, 0, n - 1) {
        if (a[i][j] == 1) {
            sx = i, sy = j;
        }
    }
    auto vis = vect<int>({}, n, n);
    vis[sx][sy] = 1;
    int ans = 0;
    lp(i, 2, n * n) {
        int tx = -1, ty = -1;
        int cx = -1, cy = -1;
        lp(x, 0, n - 1) lp(y, 0, n - 1) {
            if (x + y == sx + sy || x - y == sx - sy || x == sx || y == sy) {
                if (!vis[x][y] && (tx == -1 || a[tx][ty] > a[x][y]))
                    tx = x, ty = y;
            }
            if (!vis[x][y] && (cx == -1 || a[cx][cy] > a[x][y]))
                cx = x, cy = y;
        }
        if (tx == -1)
            tx = cx, ty = cy, ans += 1;
        vis[tx][ty] = 1;
        sx = tx, sy = ty;
    }
    return ans;
}
int vun_stone(vvi a) {
    int n = a.size();
    int sx, sy;
    lp(i, 0, n - 1) lp(j, 0, n - 1) {
        if (a[i][j] == 1) {
            sx = i, sy = j;
        }
    }
    auto vis = vect<int>({}, n, n);
    vis[sx][sy] = 1;
    int ans = 0;
    lp(i, 2, n * n) {
        int tx = -1, ty = -1;
        int cx = -1, cy = -1;
        lp(x, 0, n - 1) lp(y, 0, n - 1) {
            if (x == sx || y == sy) {
                if (!vis[x][y] && (tx == -1 || a[tx][ty] > a[x][y]))
                    tx = x, ty = y;
            }
            if (!vis[x][y] && (cx == -1 || a[cx][cy] > a[x][y]))
                cx = x, cy = y;
        }
        if (tx == -1)
            tx = cx, ty = cy, ans += 1;
        vis[tx][ty] = 1;
        sx = tx, sy = ty;
    }
    return ans;
}
auto generate_random(int n) {
    vi tmp(n * n);
    lv(i, tmp) tmp[i] = i + 1;
    shuf(tmp);
    auto a = vect<int>({}, n, n);
    int p = 0;
    lp(i, 0, n - 1) lp(j, 0, n - 1) a[i][j] = tmp[p++];
    return a;
}
auto generate_good(int n) {
    vvi helper{{1, 3, 5}, {7, 4, 8}, {2, 6, 9}};
    auto a = vect<int>({}, n, n);
    lp(i, 0, 2) lp(j, 0, 2) a[i][j] = helper[i][j] + n * n - 9;
    int p = 1;
    int x = 0, y = 3, d = 0;
    while (x < n && y < n) {
        a[x][y] = p++;
        if (d == 0) {
            if (x < y) {
                ++x;
            } else {
                --y;
            }
            if (y == -1) {
                y = 0, ++x;
                d = 1;
            }
        } else {
            if (y < x) {
                ++y;
            } else {
                --x;
            }
            if (x == -1) {
                x = 0, ++y;
                d = 0;
            }
        }
    }
    return a;
}
int main() {
    fast, prec(12);
    while (0) {
        auto a = generate_random(3);
        for (auto t : a)
            ou(t);
        ou(vun_stone(a), vun_queen(a));
        assert(vun_stone(a) >= vun_queen(a));
    }
    int n;
    in(n);
    if (n < 3) {
        ou(-1);
        return 0;
    }
    auto a = generate_good(n);
    for (auto t : a)
        ou(t);
    // ou(vun_stone(a), vun_queen(a));
    return 0;
}
