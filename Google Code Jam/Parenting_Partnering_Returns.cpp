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
#define kick "Case #" + to_string(C) + ":"
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
    auto query_path(int x, int y) {
        return query_path(x).second - query_path(y).second;
    }
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
        vpii a;
        in(a);
        int n = a.size();
        union_find_set::union_find_set<union_find_set::bipartite> g(n);
        int fail = 0;
        lp(i, 0, n - 1) lp(j, i + 1, n - 1) {
            int l = max(a[i].first, a[j].first),
                r = min(a[i].second, a[j].second);
            if (l < r) {
                if (g.find(i) != g.find(j))
                    g.link(i, j, 1);
                else {
                    if (g.query_path(i, j).s == 0)
                        fail = 1;
                }
            }
        }
        if (fail) {
            ou(kick, "IMPOSSIBLE");
        } else {
            str ans;
            lp(i, 0, n - 1) {
                if (g.query_single(i).c == -1)
                    g.modify_single(i, 0);
                ans.push_back("CJ"[g.query_single(i).c]);
            }
            ou(kick, ans);
        }
    }
    return 0;
}
