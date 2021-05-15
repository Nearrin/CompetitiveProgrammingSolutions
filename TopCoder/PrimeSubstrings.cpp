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
#include <bits/stdc++.h>
using namespace std;
namespace primality_test {
#ifdef LOCAL
template <class T> T multiply(T x, T y, const T &z) {
    return T((long long)x * y % z);
}
template <>
long long multiply<long long>(long long a, long long b, const long long &c) {
    ll r = 0;
    for (; b; b & 1 ? r = (r + a) % c : 0, b >>= 1, a = (a + a) % c)
        ;
    return r;
}
#else
template <class T> T multiply(const T &x, const T &y, const T &z) {
    return T((long long)x * y % z);
}
template <>
long long multiply<long long>(const long long &x, const long long &y,
                              const long long &z) {
    return (x * y - (long long)(((long double)x * y + 0.5) / z) * z + z) % z;
}
#endif
template <class T> T pow(T a, T b, const T &c) {
    T r = 1;
    for (; b; b & 1 ? r = multiply(r, a, c) : 0, b >>= 1, a = multiply(a, a, c))
        ;
    return r;
}
template <class T> bool miller_rabin_primality_test(T a) {
    if (a == 2)
        return true;
    if (a % 2 == 0 || a < 2)
        return false;
    static int p_1[] = {2, 7, 61},
               p_2[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    int c, *pi;
    if (a < 4759123141ll)
        c = 3, pi = p_1;
    else
        c = 7, pi = p_2;
    T u = a - 1, t = 0, p = 1;
    for (; u % 2 == 0; u /= 2, ++t)
        ;
    for (int i = 0; i < c; ++i) {
        p = pi[i] % a;
        if (!p)
            return true;
        T x = pow(p, u, a);
        if (x == 1)
            continue;
        for (int j = 0; x != a - 1 && j < t; ++j) {
            x = multiply(x, x, a);
            if (x == 1)
                return false;
        }
        if (x == a - 1)
            continue;
        return false;
    }
    return true;
}
vector<int> linear_sieve(int n) {
    vector<int> p, is_prime(n + 1, 1);
    is_prime[1] = 0;
    for (int i = 2; i <= n; ++i) {
        is_prime[i] && (p.push_back(i), 0);
        for (int j = 0; j < int(p.size()) && p[j] * i <= n; ++j) {
            is_prime[p[j] * i] = 0;
            if (i % p[j] == 0)
                break;
        }
    }
    return is_prime;
}
} // namespace primality_test
struct directed_cycle {
    directed_cycle(int _n) : n(_n), to(n) {}
    void add_edge(int u, int v) { to[u].push_back(v); }
    bool dfs(int u, vector<bool> &in_stack, vector<int> &stack,
             vector<bool> &visited) {
        if (!visited[u]) {
            in_stack[u] = visited[u] = 1, stack.push_back(u);
            for (auto v : to[u])
                if (in_stack[v]) {
                    stack.erase(begin(stack),
                                find(begin(stack), end(stack), v));
                    return true;
                } else if (dfs(v, in_stack, stack, visited))
                    return true;
            in_stack[u] = 0, stack.pop_back();
        }
        return false;
    }
    vi run() {
        vector<bool> in_stack(n), visited(n);
        vector<int> stack;
        stack.reserve(n);
        for (int u = 0; u < n; ++u)
            if (dfs(u, in_stack, stack, visited))
                return stack;
        return stack;
    }
    int n;
    vector<vector<int>> to;
};
// The templates end here.
/*
vi check(int x) {
    int l = 1;
    lp(i, 1, x - 1) l *= 10;
    int r = 1;
    lp(i, 1, x) r *= 10;
    --r;
    map<int, int> name;
    auto update = [&](int t) {
        if (!name.count(t)) {
            int s = name.size();
            name[t] = s;
        }
    };
    vi cand;
    for (int i = l; i <= r; ++i)
        if (primality_test::miller_rabin_primality_test(i))
            cand.push_back(i);
    for (auto i : cand) {
        update(i);
        update(i / 10);
        int t = i;
        for (int i = l; i < x; ++i)
            t /= 10;
        for (int i = l; i < x; ++i)
            t *= 10;
        t = i - t;
        update(t);
    }
    vi old(name.size());
    for (auto t : name)
        old[t.second] = t.first;
    directed_cycle dc(name.size());
    for (auto i : cand) {
        int t = i;
        for (int i = l; i < x; ++i)
            t /= 10;
        for (int i = l; i < x; ++i)
            t *= 10;
        t = i - t;
        dc.add_edge(name[i], name[t]);
        dc.add_edge(name[i / 10], name[i]);
    }
    vi ans;
    for (auto t : dc.run())
        if (old[t] >= l)
            ans.push_back(old[t]);
    return ans;
}
*/
struct PrimeSubstrings {
    string construct(int n, int l) {
        vi t;
        if (l == 1)
            t = {2};
        if (l == 2)
            t = {11};
        if (l == 3)
            t = {113, 131, 311};
        if (l == 4)
            t = {3119, 1193, 1931, 9311};
        if (l == 5)
            t = {11393, 13931, 39313, 93133, 31333, 13331, 33311, 33113, 31139};
        if (l == 6)
            t = {111791, 117911, 179111, 791117, 911179};
        if (l == 7)
            t = {3133399, 1333991, 3339913, 3399131,
                 3991313, 9913133, 9131333, 1313339};
        str ans;
        ans = (conv<int, str>(t[0]));
        int i = 1 % t.size();
        while (ans.size() < n) {
            ans.push_back('0' + t[i] % 10);
            ++i;
            i %= t.size();
        }
        return ans;
    }
};
/*
int main_() {
    ios::sync_with_stdio(0);
    cout << setprecision(16) << fixed;
    cin.tie(0);
    lp(i, 1, 7) {
        auto t = check(i);
        cout << "{";
        lv(j, t) {
            cout << t[j];
            if (j + 1 != t.size())
                cout << ",";
        }
        cout << "}" << endl;
    }
    return 0;
}
*/