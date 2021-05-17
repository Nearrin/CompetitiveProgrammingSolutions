#ifdef LOCAL
#include <header.hpp>
#else
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#endif
#define lp(i, l, r) for (auto i = regu(l); i <= decltype(i)(r); ++i)
#define rp(i, r, l) for (auto i = regu(r); i >= decltype(i)(l); --i)
#define lv(i, a) for (int i = 0; i < int(a.size()); ++i)
#define rv(i, a) for (int i = int(a.size()) - 1; i >= 0; --i)
#define lm(i, m) for (auto i = m; i; i = (m) & (i - 1))
#define many for (int C = 1, T = -1; T < 0 && cin >> T, C <= T; ++C)
#define goog "Case #" + to_string(C) + ":"
#define rang(a) begin(a), end(a)
#define elif else if
#ifndef LOCAL
#define endl '\n'
#undef assert
#define assert
#endif
using namespace std;
using namespace __gnu_pbds;
const auto eps = 1e-8, pi = acos(-1);
template <class T> int comp(const T &a, const T &b) {
    return a < b - eps ? -1 : (a > b + eps);
}
#if __cplusplus > 201103L
template <class T> auto regu(const T &a) { return int(a); }
template <> auto regu(const int64_t &a) { return a; }
template <> auto regu(const uint64_t &a) { return int64_t(a); }
#else
template <class T> int64_t regu(const T &a) { return int(a); }
template <> int64_t regu(const int64_t &a) { return a; }
template <> int64_t regu(const uint64_t &a) { return a; }
#endif
template <class T> int barr(const T &a, const int &i) {
    return int(a >> i & 1);
}
template <class T> int bcnt(const T &a) { return __builtin_popcount(a); }
template <> int bcnt(const int64_t &a) { return __builtin_popcountll(a); }
template <class T> int blen(const T &a) { return a ? 1 + blen(a / 2) : 0; }
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T> T rint(T l, T r) {
    return uniform_int_distribution<T>(l, r)(rng);
}
template <class A, class B> B conv(const A &a, B b = B()) {
    stringstream s;
    s << a, s >> b;
    return b;
}
template <class T = int> T inf() { return numeric_limits<T>::max() / 2; }
template <class T> T sign(const T &a) { return a == 0 ? 0 : (a < 0 ? -1 : 1); }
template <class T> T floor(const T &a, const T &b) {
    assert(b != 0);
    return sign(a) * sign(b) > 0 ? abs(a) / abs(b)
                                 : -(abs(a) + abs(b) - 1) / abs(b);
}
template <class T> T ceil(const T &a, const T &b) {
    assert(b != 0);
    return sign(a) * sign(b) > 0 ? (abs(a) + abs(b) - 1) / abs(b)
                                 : -abs(a) / abs(b);
}
template <class T> bool tmin(T &a, T b) { return b < a ? a = b, true : false; }
template <class T> bool tmax(T &a, T b) { return b > a ? a = b, true : false; }
#if __cplusplus > 201103L
template <class T> auto min(const T &a) { return *min_element(rang(a)); }
template <class T> auto max(const T &a) { return *max_element(rang(a)); }
template <class T> auto sum(const T &a) {
    return accumulate(rang(a), (typename T::value_type)0);
}
template <> auto sum(const vector<int> &a) { return accumulate(rang(a), 0ll); }
template <> auto sum(const vector<string> &a) {
    return accumulate(rang(a), string());
}
template <class C, class V> auto find(C &c, const V &v) {
    return find(rang(c), v);
}
template <class C, class V> auto find(const C &c, const V &v) {
    return find(rang(c), v);
}
#endif
template <class T, class C = less<typename T::value_type>>
void sort(T &a, C c = C()) {
    sort(rang(a), c);
}
template <class T, class C> void sork(T &a, C c) {
    sort(a, [&](const typename T::value_type &x,
                const typename T::value_type &y) { return c(x) < c(y); });
}
template <class T> void reve(T &a) { reverse(rang(a)); }
template <class T> void uniq(T &a) {
    sort(a), a.erase(unique(rang(a)), end(a));
}
template <class T> void shuf(T &a) { shuffle(rang(a), rng); }
template <class T> void merg(T l, T m, T r) { inplace_merge(l, m, r); }
#if __cplusplus > 201103L
namespace lru_cache {
template <class F> struct dense_ {
    dense_(F function) : f(function) {}
    template <class V> auto build(int i) const {
        assert(i == l.size());
        return numeric_limits<V>::min();
    }
    template <class V, class T, class... K>
    auto build(int i, const T &t, const K &... k) const {
        auto u = build<V, K...>(i + 1, k...);
        return vector<decltype(u)>(l[i], u);
    }
    template <class M, class V> V &find(M &m) const { return m; }
    template <class M, class V, class T, class... K>
    V &find(M &m, const T &t, const K &... k) const {
        if (t < m.size())
            return find<decltype(m[t]), V, K...>(m[t], k...);
        return find<decltype(m[t]), V, K...>(m[e = false], k...);
    }
    /*
    The cache can handle outliers without crashing, but the values won't be
    saved.
    */
    template <class... K> auto operator()(const K &... k) const {
        typedef decltype(f(*this, k...)) V;
        typedef decltype(build<V, K...>(0, k...)) M;
        if (c) {
            if (p)
                delete (M *)p, p = 0;
            c = false;
        }
        if (!p)
            p = new M(move(build<V, K...>(0, k...)));
        e = true;
        auto &t = find<M, V, K...>(*((M *)p), k...);
        return e ? (t == numeric_limits<V>::min() ? t = f(*this, k...) : t)
                 : f(*this, k...);
    }
    F f;
    static vector<int> l;
    static void *p;
    static bool c, e;
};
template <class F> vector<int> dense_<F>::l;
template <class F> void *dense_<F>::p = 0;
template <class F> bool dense_<F>::c = false;
template <class F> bool dense_<F>::e = false;
template <class F> struct sparse_ {
    sparse_(F function) : f(function) {}
    template <class V> auto build() const { return V(); }
    template <class V, class T, class... K>
    auto build(const T &t, const K &... k) const {
        return unordered_map<T, decltype(build<V, K...>(k...))>();
    }
    template <class M, class V> V &find(M &m) const { return m; }
    template <class M, class V, class T, class... K>
    V &find(M &m, const T &t, const K &... k) const {
        auto i = m.find(t);
        if (i != m.end())
            return find<decltype(i->second), V, K...>(i->second, k...);
        e = false;
        return find<decltype(i->second), V, K...>(m[t], k...);
    }
    template <class... K> auto operator()(const K &... k) const {
        typedef decltype(f(*this, k...)) V;
        typedef decltype(build<V, K...>(k...)) M;
        if (c) {
            if (p)
                delete (M *)p, p = 0;
            c = false;
        }
        if (!p)
            p = new M(move(build<V, K...>(k...)));
        e = true;
        auto &t = find<M, V, K...>(*((M *)p), k...);
        return e ? t : t = f(*this, k...);
    }
    F f;
    static void *p;
    static bool c, e;
};
template <class F> void *sparse_<F>::p = 0;
template <class F> bool sparse_<F>::e = false;
template <class F> bool sparse_<F>::c = false;
/*
Decorating a function erases all cached values. Please save the resulting
function if you want to use the old values. Because of the use of member
variables, the decorators may not work when dealing with two functions of the
same type. However, lambda functions have unique types, so they will be handled.
*/
struct dense {
    auto convert() {}
    template <class T, class... L>
    auto convert(const T &t, const L &... limits) {
        l.push_back(t);
        convert(limits...);
    }
    template <class... L> dense(const L &... limits) { convert(limits...); }
    template <class F> auto operator()(const F &f) const {
        dense_<F>::l = l, dense_<F>::c = true;
        return dense_<F>(f);
    }
    vector<int> l;
};
struct sparse {
    template <class F> auto operator()(const F &f) const {
        sparse_<F>::c = true;
        return sparse_<F>(f);
    }
};
} // namespace lru_cache
/*
The last dimension should be large enough or using vect may be slow.
*/
template <class T> auto vect(const T &v, int n) { return vector<T>(n, v); }
template <class T, class... D> auto vect(const T &v, int n, D... m) {
    return vector<decltype(vect(v, m...))>(n, vect(v, m...));
}
#endif
template <class F, class S> istream &operator>>(istream &s, pair<F, S> &a) {
    return s >> a.first >> a.second;
}
template <class F, class S>
ostream &operator<<(ostream &s, const pair<F, S> &a) {
    return s << a.first << " " << a.second;
}
template <class T> istream &operator>>(istream &s, vector<T> &a) {
    for (int i = -1; i < 0 && (!a.size() && (cin >> i, a.resize(i), 0), i = 0),
             i < int(a.size());)
        s >> a[i++];
    return s;
}
template <class T> ostream &operator<<(ostream &s, const vector<T> &a) {
    lv(i, a) cout << a[i] << (i + 1 == int(a.size()) ? "" : " ");
    return s;
}
template <class T> T in() {
    T a;
    cin >> a;
    return a;
}
template <class T> istream &in(T &a) { return cin >> a; }
template <class A, class... B> istream &in(A &a, B &... b) {
    return cin >> a, in(b...);
}
void ou() { cout << endl; }
template <class T> void ou(const T &a) { cout << a << endl; }
template <class A, class... B> void ou(const A &a, const B &... b) {
    cout << a << ' ', ou(b...);
}
bool yep(const bool &a) { return ou(a ? "yes" : "no"), a; }
bool Yep(const bool &a) { return ou(a ? "Yes" : "No"), a; }
bool YEP(const bool &a) { return ou(a ? "YES" : "NO"), a; }
template <class T> struct hash_safe {};
template <> struct hash_safe<int> {
    size_t operator()(unsigned long long a) const {
        static unsigned long long d =
            chrono::steady_clock::now().time_since_epoch().count();
        a += d + 0x9e3779b97f4a7c15, a = (a ^ (a >> 30)) * 0xbf58476d1ce4e5b9;
        a = (a ^ (a >> 27)) * 0x94d049bb133111eb;
        return a ^ (a >> 31);
    }
};
template <> struct hash_safe<long long> {
    size_t operator()(unsigned long long a) const {
        return hash_safe<int>()(a);
    }
};
template <class A, class B> struct hash_safe<pair<A, B>> {
    size_t operator()(pair<A, B> a) const {
        auto h = hash_safe<A>()(a.first), g = hash_safe<B>()(a.second);
        return (h >> 16 << 16) + (g >> 16);
    }
};
template <class T> using unordered_set_safe = unordered_set<T, hash_safe<T>>;
template <class T>
using unordered_multiset_safe = unordered_multiset<T, hash_safe<T>>;
template <class K, class V>
using unordered_map_safe = unordered_map<K, V, hash_safe<K>>;
template <class K, class V>
using unordered_multimap_safe = unordered_multimap<K, V, hash_safe<K>>;
#define unordered_set unordered_set_safe
#define unordered_multiset unordered_multiset_safe
#define unordered_map unordered_map_safe
#define unordered_multimap unordered_multimap_safe
template <class T, class C = less<T>>
using bbst =
    tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;
template <class T, class C = greater<T>>
using heap = __gnu_pbds::priority_queue<T, C, pairing_heap_tag>;
using ll = long long;
using ld = long double;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vvi = vector<vi>;
#include <bits/stdc++.h>
using namespace std;
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
    /*
    Please make sure x and y are not already connected before calling
    union_find_set<T>::link(int x,int y, typename T::path t). If they are
    connected, please check if there is a conflict.
    */
    void link(int x, int y, typename T::path t) {
        auto u = query_path(x), v = query_path(y);
        if(u.first == v.first)return;
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
    /*
    Please check if there will be a conflict before calling
    union_find_set<bipartite>::modify_single.
    */
    template <class A> void modify_single(int x, A t) {
        auto u = query_path(x);
        t_s[u.first].modify_single(u.second, t);
    }
    /*
    Please check if there will be a conflict before calling
    union_find_set<bipartite>::modify_tree.
    */
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
int main_() {
    ios::sync_with_stdio(0);
    cout << setprecision(16) << fixed;
    cin.tie(0);
    return 0;
}
int comcnt(vector<vector<int>>& a){
    union_find_set::union_find_set<>g(a.size()*a[0].size());
        int n=a.size(),m=a[0].size();
        lv(i,a)lv(j,a[i]){
            if(!a[i][j])continue;
            lp(di,-1,1)lp(dj,-1,1)if(abs(di)+abs(dj)==1){
                int ni=i+di,nj=j+dj;
                if(ni>=0&&ni<a.size()&&nj>=0&&nj<a[ni].size()&&a[ni][nj]){
                                                                          g.link(i*m+j,ni*m+nj);}
            }
        }
    vi cnt(a.size()*a[0].size());
     lv(i,a)lv(j,a[i]){
            if(!a[i][j])continue;
           cnt[g.find(i*m+j)]=1;
        }
    return sum(cnt);
}
class Solution {
public:
    int minDays(vector<vector<int>>& a) {
        if(comcnt(a)!=1)return 0;
        lv(i,a)lv(j,a[i]){
            if(!a[i][j])continue;
            a[i][j]=0;
            if(comcnt(a)!=1)return 1;
            a[i][j]=1;
        }
        return 2;
    }
};
