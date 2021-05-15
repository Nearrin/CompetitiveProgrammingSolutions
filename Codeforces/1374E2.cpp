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
template <> auto regu(const long long &a) { return a; }
template <> auto regu(const uint64_t &a) { return int64_t(a); }
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
template <class T> void reve(T &a) { reverse(rang(a)); }
template <class T> void uniq(T &a) {
    sort(a), a.erase(unique(rang(a)), end(a));
}
template <class T> void shuf(T &a) { shuffle(rang(a), rng); }
template <class T> void merg(T l, T m, T r) { inplace_merge(l, m, r); }
#if __cplusplus > 201103L
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
template <class T> void in(T &a) { cin >> a; }
template <class A, class... B> void in(A &a, B &... b) { cin >> a, in(b...); }
void ou() { cout << endl; }
template <class T> void ou(const T &a) { cout << a << endl; }
template <class A, class... B> void ou(const A &a, const B &... b) {
    cout << a << ' ', ou(b...);
}
bool yep(const bool &a) { return ou(a ? "yes" : "no"), a; }
bool Yep(const bool &a) { return ou(a ? "Yes" : "No"), a; }
bool YEP(const bool &a) { return ou(a ? "YES" : "NO"), a; }
#if __cplusplus > 201103L
template <class T> struct func {
    func(T &&t_) : t(forward<T>(t_)) {}
    template <class... A> auto operator()(A &&... a) const {
        return t(*this, forward<A>(a)...);
    }
    T t;
};
#endif
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
int solve(int n, int m, int k, vector<pair<int, pii>> books_) {
    // int n, m, k;
    // in(n, m, k);
    vi a, b, both, none;
    vector<pair<pii, pii>> books;
    lp(i, 1, n) {
        int t, u, v;
        // in(t, u, v);
        t = books_[i - 1].first;
        u = books_[i - 1].second.first;
        v = books_[i - 1].second.second;
        books.push_back({{t, i}, {u, v}});
        if (u + v == 2) {
            both.push_back(t);
        }
        elif (u) { a.push_back(t); }
        elif (v) { b.push_back(t); }
        else none.push_back(t);
    }
    sort(a), sort(b), sort(both), sort(none);
    auto fix = [](vi &tt) {
        vi t = tt;
        lv(i, t) if (i) t[i] += t[i - 1];
        return t;
    };
    auto as = fix(a), bs = fix(b), boths = fix(both), nones = fix(none);
    auto vis = [](vi &tt, int i) {
        if (i >= 0)
            return tt[i];
        return 0;
    };
    int ans = ~0u >> 1, bothcount = -1;
    if (a.size() >= k && b.size() >= k && k + k <= m &&
        m - 2 * k <= none.size()) {
        if (tmin(ans, as[k - 1] + bs[k - 1] + vis(nones, m - k - k - 1)))
            bothcount = 0;
    }
    int pa = 0, pb = 0;
    vi tree_cnt(10010), tree_sum(10010);
    int tree_size = 0;
    auto insert = [&](int v) {
        ++tree_size;
        int t = v;
        for (; v <= 10000; v += v & -v) {
            tree_cnt[v]++;
            tree_sum[v] += t;
        }
    };
    auto erase = [&](int v) {
        --tree_size;
        int t = v;
        for (; v <= 10000; v += v & -v) {
            tree_cnt[v]--;
            tree_sum[v] -= t;
        }
    };
    auto query = [&](int k) {
        int r = 0, tt = 0;
        for (int i = 1 << 14; i; i >>= 1)
            if (r + i <= 10000 && tree_cnt[r + i] < k)
                k -= tree_cnt[r += i], tt += tree_sum[r];
        return tt + (r + 1) * k;
    };
    for (auto v : none)
        insert(v);
    for (auto v : a)
        insert(v);
    for (auto v : b)
        insert(v);
    rp(i, both.size() - 1, -1) {
        while (pa != a.size() && i + 1 + pa < k) {
            erase(a[pa]);
            ++pa;
        }
        while (pb != b.size() && i + 1 + pb < k) {
            erase(b[pb]);
            ++pb;
        }
        if (i + 1 + pa >= k && i + 1 + pb >= k && i + 1 + pa + pb <= m) {
            int need = m - (i + 1 + pa + pb);
            // ou(i, need, tree.size());
            // ou(i, tree.size(), treesum);
            if (need <= tree_size)
                if (tmin(ans, vis(boths, i) + vis(as, pa - 1) +
                                  vis(bs, pb - 1) + query(need)))
                    bothcount = i + 1;
        }
    }
    /*
    4 2 1
    2 1 0
    2 1 1
    3 0 1
    1 0 0
    */
    if (ans == ~0u >> 1) {
        ans = -1;
    }
    ou(ans);
    if (ans == -1)
        return ans;
    // ou(ans);
    sort(books);
    int bt_c = bothcount;
    int a_c = max(k - bothcount, 0);
    int b_c = a_c;
    int other_c = m - bt_c - a_c - b_c;
    vi ass;
    for (auto bk : books) {
        if (bk.second == pii{1, 1} && bt_c) {
            --bt_c;
            ass.push_back(bk.first.second);
            continue;
        }
        if (bk.second == pii{1, 0} && a_c) {
            --a_c;
            ass.push_back(bk.first.second);
            continue;
        }
        if (bk.second == pii{0, 1} && b_c) {
            --b_c;
            ass.push_back(bk.first.second);
            continue;
        }
        if (other_c) {
            --other_c;
            ass.push_back(bk.first.second);
        }
    }
    ou(ass);
    return ans;
}
int solve2(int n, int m, int k, vector<pair<int, pii>> books_) {
    int ans = ~0u >> 1;
    lp(i, 0, (1 << n) - 1) {
        if (bcnt(i) == m) {
            int ca = 0, cb = 0, tm = 0;
            lv(j, books_) if (barr(i, j)) {
                ca += books_[j].second.first;
                cb += books_[j].second.second;
                tm += books_[j].first;
            }
            if (ca >= k && cb >= k)
                tmin(ans, tm);
        }
    }
    if (ans == ~0u >> 1) {
        ans = -1;
    }
    return ans;
}
void gen1() {
    int n, m, k;
    in(n, m, k);
    vector<pair<int, pii>> books_;
    lp(i, 1, n) {
        int x, y, z;
        in(x, y, z);
        books_.push_back({x, {y, z}});
    }
    solve(n, m, k, books_);
    // ou(solve(n, m, k, books_));
    // ou(solve2(n, m, k, books_));
}
void gen2() {
    int n, m, k;
    n = rint(1, 20), m = rint(1, n), k = rint(1, m);
    vector<pair<int, pii>> books_;
    ou(n, m, k);
    lp(i, 1, n) {
        int x, y, z;
        x = rint(1, 100), y = rint(0, 1), z = rint(0, 1);
        books_.push_back({x, {y, z}});
        ou(x, y, z);
    }
    int a1 = solve(n, m, k, books_);
    int a2 = solve2(n, m, k, books_);
    ou(a1, a2);
    if (a1 != a2) {
        exit(0);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cout << setprecision(16) << fixed;
    cin.tie(0);
    gen1();
    return 0;
    while (1)
        gen2();
    return 0;
}