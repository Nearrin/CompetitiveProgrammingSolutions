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
#define many for (int T = -1; T < 0 && cin >> T, T--;)
#define appl(x, f, a)                                                          \
    for (auto &x : a)                                                          \
    f
#define rang(a) begin(a), end(a)
#define gene template <class T>
#define elif else if
#define intm modular_arithmetic::integer
#define bcnt __builtin_popcount
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
    return (a > 0 && b > 0) || (a < 0 && b < 0)
               ? abs(a) / abs(b)
               : -(abs(a) + abs(b) - 1) / abs(b);
}
gene T ceil(const T &a, const T &b) {
    assert(b != 0);
    return (a > 0 && b > 0) || (a < 0 && b < 0) ? (abs(a) + abs(b) - 1) / abs(b)
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
namespace union_find_set {
struct statistic;
template <class T = statistic> struct union_find_set {
    int n;
    vector<int> p, r;
    vector<typename T::path> p_s;
    vector<typename T::tree> t_s;
    union_find_set(int _n) : n(_n), p(n), r(n), p_s(n), t_s(n) {
        for (int i = 0; i < n; ++i)
            p[i] = i;
    }
    int size() {
        int s = 0;
        for (int i = 0; i < n; ++i)
            s += (p[i] == i);
        return s;
    }
    auto find(int x) { return query_path(x).first; }
    void link(int x, int y) {
        typename T::path t;
        link(x, y, t);
    }
    void link(int x, int y, typename T::path t) {
        auto u = query_path(x), v = query_path(y);
        assert(u.first != v.first);
        if (r[u.first] > r[v.first])
            swap(u, v), t = decltype(t)() - t;
        if (r[u.first] == r[v.first])
            ++r[v.first];
        p[u.first] = v.first, p_s[u.first] = v.second + (t - u.second);
        t_s[v.first] = (p_s[u.first] + t_s[u.first]) + t_s[v.first];
    }
    auto query_path(int x) {
        if (x == p[x])
            return make_pair(x, p_s[x]);
        auto u = query_path(p[x]);
        p_s[x] = u.second + p_s[x], p[x] = u.first;
        return make_pair(p[x], p_s[x]);
    }
    auto query_path(int x, int y) { return query_path(x) - query_path(y); }
    auto query_single(int x) {
        auto u = query_path(x);
        return t_s[u.first].query_single(u.second);
    }
    auto &query_tree(int x) { return t_s[find(x)]; }
    template <class A> void modify_single(int x, A t) {
        auto u = query_path(x);
        t_s[u.first].modify_single(u.second, t);
    }
    template <class A> void modify_tree(int x, A t) {
        t_s[find(x)].modify_tree(t);
    }
};
struct statistic {
    struct path {
        path() {}
        friend auto operator+(const path &a, const path &b) { return path(); }
        friend auto operator-(const path &a, const path &b) { return path(); }
    };
    struct tree {
        tree() {}
        tree(const path &a) {}
        friend auto operator+(const path &a, const tree &b) { return tree(); }
        friend auto operator+(const tree &a, const tree &b) { return tree(); }
        auto query_single(const path &a) { return tree(); };
    };
};
struct bipartite {
    struct path {
        path(int _s = 0) : s(_s) {}
        friend auto operator+(const path &a, const path &b) {
            return path(a.s ^ b.s);
        }
        friend auto operator-(const path &a, const path &b) {
            return path(a.s ^ b.s);
        }
        int s;
    };
    struct tree {
        tree(int s_0 = 1, int s_1 = 0, int _c = -1) : s{s_0, s_1}, c(_c) {}
        friend auto operator+(const path &a, const tree &b) {
            return tree(b.s[a.s], b.s[1 ^ a.s], b.c == -1 ? -1 : (b.c ^ a.s));
        }
        friend auto operator+(const tree &a, const tree &b) {
            assert(a.c == -1 || b.c == -1 || a.c == b.c);
            return tree(a.s[0] + b.s[0], a.s[1] + b.s[1], max(a.c, b.c));
        }
        auto query_single(const path &a) {
            if (c == -1)
                return tree();
            else
                return tree(1, 0, c ^ a.s);
        }
        void modify_single(const path &a, int t) {
            assert(c == -1 || c == (a.s ^ t)), c = a.s ^ t;
        }
        void modify_tree(int t) { c = t; }
        int s[2], c;
    };
};
} // namespace union_find_set
// The templates end here.
int main() {
    fast, prec(12);
    many {
        int n, k;
        in(n, k);
        str s;
        in(s);
        union_find_set::union_find_set<> ufs(n);
        lv(i, s) {
            if (ufs.find(i) != ufs.find(n - i - 1)) {
                ufs.link(i, n - i - 1);
            }
            if (i + k < n && ufs.find(i) != ufs.find(i + k))
                ufs.link(i, i + k);
        }
        vector<vector<char>> a(n);
        lv(i, s) { a[ufs.find(i)].push_back(s[i]); }
        int ans = 0;
        lv(i, a) {
            int cnt = a[i].size();
            vector<int> c(26);
            for (auto tmp : a[i])
                ++c[tmp - 'a'];
            ans += cnt - max(c);
        }
        ou(ans);
    }
    return 0;
}
