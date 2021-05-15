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
// The templates end here.
#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
#define sf scanf
#define pf printf
#define ps for (;;)
#define fr freopen
#define lp(i, a, b) for (int i = a; i <= b; ++i)
#define rp(i, a, b) for (int i = a; i >= b; --i)
using namespace std;
struct edge {
    edge(int a, int b, int c) : u(a + 1), v(b + 1), w(c) {}
    int u, v, w;
};
bool operator<(edge a, edge b) { return a.w < b.w; }
struct graph {
    vector<edge> es;
    int nc;
};
struct query {
    query(int a, int b) : t(a), w(b), r(0) {}
    int t, w;
    long long r;
};
// remember to clear this one
vector<query> qs;
vi pr(2000010);
int fd(int x) { return x == pr[x] ? x : pr[x] = fd(pr[x]); }
void contract(graph &gr, int ql, int qr) {
    static vi tm(2000010);
    lp(i, 0, int(gr.es.size() - 1)) tm[i] = 0;
    lp(i, ql, qr) tm[qs[i].t] = 1;
    lp(i, 1, gr.nc) pr[i] = i;
    vector<edge> t1, t2;
    lp(i, 0, int(gr.es.size() - 1)) {
        if (tm[i]) {
            int u = gr.es[i].u, v = gr.es[i].v;
            if (fd(u) != fd(v))
                pr[fd(u)] = v; //, ou(fd(u), v);
        } else {
            t1.push_back(gr.es[i]);
        }
    }
    sort(t1.begin(), t1.end());
    lp(i, 0, int(t1.size() - 1)) {
        int u = t1[i].u, v = t1[i].v;
        if (fd(u) != fd(v)) {
            pr[fd(u)] = v; //, ou(fd(u), v);
            t2.push_back(t1[i]);
        }
    }
    // ou(111);
    long long dl = 0;
    lp(i, 1, gr.nc) pr[i] = i;
    lp(i, 0, int(t2.size() - 1)) {
        int u = t2[i].u, v = t2[i].v;
        pr[fd(u)] = v; //, ou(fd(u), v);
        dl += t2[i].w;
    }
    lp(i, ql, qr) qs[i].r += dl;
    static vi id(2000010);
    lp(i, 1, gr.nc) id[i] = 0;
    int nw = 0;
    // ou(111);
    lp(i, 1, gr.nc) if (id[fd(i)] == 0) id[fd(i)] = ++nw;
    // ou(111);
    gr.nc = nw;
    lp(i, 0, int(gr.es.size() - 1)) {
        gr.es[i].u = id[fd(gr.es[i].u)];
        gr.es[i].v = id[fd(gr.es[i].v)];
    }
    // ou(111);
}
void reduct(graph &gr, int ql, int qr) {
    static vi tm(2000010);
    lp(i, 0, int(gr.es.size() - 1)) tm[i] = 0;
    lp(i, ql, qr) tm[qs[i].t] = 1;
    vector<pair<edge, int>> t1;
    lp(i, 0, int(gr.es.size() - 1)) if (tm[i] == 0)
        t1.push_back(make_pair(gr.es[i], i));
    sort(t1.begin(), t1.end());
    static vi bj(2000010);
    lp(i, 0, int(gr.es.size() - 1)) bj[i] = 0;
    lp(i, 1, gr.nc) pr[i] = i;
    lp(i, 0, int(t1.size() - 1)) {
        int u = t1[i].first.u, v = t1[i].first.v;
        if (fd(u) != fd(v))
            pr[fd(u)] = v;
        else
            bj[t1[i].second] = 1;
    }
    vector<edge> t2;
    static vi mp(2000010);
    lp(i, 0, int(gr.es.size() - 1)) if (bj[i] == 0) {
        mp[i] = t2.size();
        t2.push_back(gr.es[i]);
    }
    lp(i, ql, qr) qs[i].t = mp[qs[i].t];
    gr.es = t2;
}
void print(graph gr, int ql, int qr) {
    pf("{%d}\n", gr.nc);
    lp(i, 0, int(gr.es.size() - 1))
        pf("{%d,%d,%d}\n", gr.es[i].u, gr.es[i].v, gr.es[i].w);
    lp(i, ql, qr) pf("{%d,%d}\n", qs[i].t, qs[i].w);
}
void solve(graph gr, int ql, int qr) {
    // pf("[%d,%d,%d,%lld]\n", ql, qr, gr.nc, qs[ql].r);
    // print(gr,ql,qr);
    contract(gr, ql, qr);
    // pf("[%d,%d,%d,%lld]\n", ql, qr, gr.nc, qs[ql].r);
    // print(gr,ql,qr);
    reduct(gr, ql, qr);
    // pf("[%d,%d,%d,%lld]\n", ql, qr, gr.nc, qs[ql].r);
    // print(gr,ql,qr);
    if (ql != qr) {
        int m = (ql + qr) / 2;
        graph gt = gr;
        lp(i, ql, m) gt.es[qs[i].t].w = qs[i].w;
        solve(gr, ql, m);
        solve(gt, m + 1, qr);
    } else {
        gr.es[qs[ql].t].w = qs[ql].w;
        sort(gr.es.begin(), gr.es.end());
        lp(i, 1, gr.nc) pr[i] = i;
        lp(i, 0, int(gr.es.size() - 1)) {
            int u = gr.es[i].u, v = gr.es[i].v, w = gr.es[i].w;
            if (fd(u) != fd(v)) {
                qs[ql].r += w;
                pr[fd(u)] = v;
            }
        }
    }
}
vi read(int n, int k, ll ds) {
    vi s(n);
    lp(i, 0, k - 1) in(s[i]);
    ll as, bs, cs;
    in(as, bs, cs);
    lp(i, k, n - 1) { s[i] = (as * s[i - 2] + bs * s[i - 1] + cs) % ds; }
    return s;
}
int main() {
    many {
        int tn, tm, te, tk;
        in(tn, tm, te, tk);
        auto tx = read(tn, tk, tm);
        auto ty = read(tn, tk, tm);
        auto ti = read(te, tk, tn * tm + tn);
        auto tw = read(te, tk, int(1e9));
        graph g;
        g.nc = tn * tm;
        lp(cid, 0, tn - 1) {
            lp(eid, 0, tm - 1) {
                g.es.push_back(
                    edge(cid * tm + eid, cid * tm + (eid + 1) % tm, 1));
            }
        }
        lp(eid, tn * tm, tn * tm + tn - 1) {
            int i = eid - tn * tm;
            g.es.push_back(edge(tm * i + ty[i],
                                tm * ((i + 1) % tn) + tx[(i + 1) % tn], 1));
        }
        qs.clear();
        lp(i, 1, te) {
            int t, w;
            t = ti[i - 1] + 1;
            w = tw[i - 1];
            qs.push_back(query(t - 1, w));
        }
        solve(g, 0, int(qs.size() - 1));
        // lv(i, qs) ou(qs[i].r);
        ll ans = 1;
        lp(i, 0, int(qs.size() - 1)) ans *= qs[i].r % int(1e9 + 7),
            ans %= int(1e9 + 7);
        ou(goog, ans);
    }
    return 0;
}
