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
namespace integer {
struct integer operator+(integer a, integer b);
integer operator+(integer a, int b);
integer operator-(integer a, integer b);
integer operator*(integer a, integer b);
integer operator*(integer a, integer b);
integer operator/(integer a, integer b);
integer operator%(integer a, integer b);
integer operator%(integer a, int b);
integer operator%(integer a, long long b);
bool operator!=(integer a, int b);
bool operator<=(integer a, int b);
struct integer {
    operator bool() { return *this != 0; }
    integer(long long a = 0) {
        if (a < 0) {
            s = -1;
            a = -a;
        } else
            s = a != 0;
        do {
            d.push_back(a % B);
            a /= B;
        } while (a);
    }
    integer(string a) {
        s = 1;
        reve(a);
        for (auto v : a) {
            if (v >= '0' && v <= '9')
                d.push_back(v - '0' + 1);
            if (v >= 'a' && v <= 'z')
                d.push_back(v - 'a' + 11);
            if (v >= 'A' && v <= 'Z')
                d.push_back(v - 'A' + 37);
        }
    }
    integer(const integer &a) {
        d = a.d;
        s = a.s;
    }
    integer &operator=(long long a) { return *this = integer(a); }
    integer &operator+=(integer a) { return *this = *this + a; }
    integer &operator-=(integer a) { return *this = *this - a; }
    integer &operator*=(integer a) { return *this = *this * a; }
    integer &operator/=(integer a) { return *this = *this / a; }
    integer &operator%=(integer a) { return *this = *this % a; }
    integer &operator++() { return *this = *this + 1; }
    operator string() const {
        string r;
        for (int i = 0; i < d.size(); ++i) {
            stringstream ts;
            ts << d[i];
            string tt;
            ts >> tt;
            reverse(tt.begin(), tt.end());
            while (i + 1 != d.size() && tt.size() < L)
                tt.push_back('0');
            r += tt;
        }
        reverse(r.begin(), r.end());
        return r;
    }
    int s;
    vector<int> d;
    static const int B = 63, L = 8;
};
string str(const integer &a) { return string(a); }
bool operator<(integer a, integer b) {
    if (a.s != b.s)
        return a.s < b.s;
    if (a.d.size() != b.d.size())
        return (a.s != 1) ^ (a.d.size() < b.d.size());
    for (int i = a.d.size() - 1; i >= 0; --i)
        if (a.d[i] != b.d[i])
            return (a.s != 1) ^ (a.d[i] < b.d[i]);
    return false;
}
bool operator>(integer a, integer b) { return b < a; }
bool operator<=(integer a, integer b) { return !(a > b); }
bool operator>=(integer a, integer b) { return !(a < b); }
bool operator==(integer a, integer b) { return !(a < b) && !(a > b); }
bool operator!=(integer a, integer b) { return !(a == b); }
istream &operator>>(istream &s, integer &a) {
    string t;
    s >> t;
    a = integer(t);
    return s;
}
ostream &operator<<(ostream &s, integer a) {
    if (a.s == -1)
        s << '-';
    for (int i = a.d.size() - 1; i >= 0; --i) {
        if (i != a.d.size() - 1)
            s << setw(integer::L) << setfill('0');
        s << a.d[i];
    }
    s << setw(0) << setfill(' ');
    return s;
}
void dzero(integer &a) {
    while (a.d.size() > 1 && a.d.back() == 0)
        a.d.pop_back();
}
integer operator-(integer a) {
    a.s *= -1;
    if (a.d.size() == 1 && a.d[0] == 0)
        a.s = 1;
    return a;
}
integer operator+(integer a, int b) { return a + integer(b); }
integer operator*(integer a, int b) { return a * integer(b); }
integer operator%(integer a, int b) { return a % integer(b); }
integer operator%(integer a, long long b) { return a % integer(b); }
bool operator!=(integer a, int b) { return a != integer(b); }
bool operator<=(integer a, int b) { return a <= integer(b); }
integer operator+(integer a, integer b) {
    if (a.s * b.s != -1) {
        integer c;
        c.s = a.s ? a.s : b.s;
        c.d.resize(max(a.d.size(), b.d.size()) + 1);
        for (int i = 0; i < c.d.size() - 1; ++i) {
            if (i < a.d.size())
                c.d[i] += a.d[i];
            if (i < b.d.size())
                c.d[i] += b.d[i];
            if (c.d[i] >= integer::B) {
                c.d[i] -= integer::B;
                ++c.d[i + 1];
            }
        }
        dzero(c);
        return c;
    }
    return a - (-b);
}
integer operator-(integer a, integer b) {
    if (a.s * b.s == 1) {
        if (a.s == -1)
            return (-b) - (-a);
        if (a < b)
            return -(b - a);
        if (a == b)
            return 0;
        for (int i = 0; i < a.d.size(); ++i) {
            if (i < b.d.size())
                a.d[i] -= b.d[i];
            if (a.d[i] < 0) {
                a.d[i] += integer::B;
                --a.d[i + 1];
            }
        }
        dzero(a);
        return a;
    }
    return a + (-b);
}
integer operator*(integer a, integer b) {
    vector<long long> t(a.d.size() + b.d.size());
    for (int i = 0; i < a.d.size(); ++i)
        for (int j = 0; j < b.d.size(); ++j)
            t[i + j] += (long long)a.d[i] * b.d[j];
    for (int i = 0; i < t.size() - 1; ++i) {
        t[i + 1] += t[i] / integer::B;
        t[i] %= integer::B;
    }
    integer c;
    c.s = a.s * b.s;
    c.d.resize(t.size());
    copy(t.begin(), t.end(), c.d.begin());
    dzero(c);
    return c;
}
integer div2(integer a) {
    for (int i = a.d.size() - 1; i >= 0; --i) {
        if (i)
            a.d[i - 1] += (a.d[i] & 1) * integer::B;
        a.d[i] >>= 1;
    }
    dzero(a);
    if (a.d.size() == 1 && a.d[0] == 0)
        a.s = 0;
    return a;
}
integer operator/(integer a, integer b) {
    if (!a.s)
        return 0;
    if (a.s < 0)
        return -((-a) / b);
    if (a < b)
        return 0;
    integer l = 1, r = 1;
    while (r * b <= a)
        r = r * 2;
    while (l + 1 < r) {
        integer m = div2(l + r);
        if (m * b > a)
            r = m;
        else
            l = m;
    }
    return l;
}
integer operator%(integer a, integer b) { return a - a / b * b; }
integer gcd(integer a, integer b) {
    integer r = 1;
    while (a != 0 && b != 0) {
        if (!(a.d[0] & 1) && !(b.d[0] & 1)) {
            a = div2(a);
            b = div2(b);
            r = r * 2;
        } else if (!(a.d[0] & 1))
            a = div2(a);
        else if (!(b.d[0] & 1))
            b = div2(b);
        else {
            if (a < b)
                swap(a, b);
            a = div2(a - b);
        }
    }
    if (a != 0)
        return r * a;
    return r * b;
}
int length(integer a) {
    a.s = 1;
    return string(a).size();
}
int len(integer a) { return length(a); }
} // namespace integer
// The templates end here.
char int_to_char(int x) {
    if (x >= 1 && x <= 10)
        return '0' + x - 1;
    if (x >= 11 && x <= 36)
        return 'a' + x - 11;
    if (x >= 37 && x <= 62)
        return 'A' + x - 37;
    return '?';
}
ll work(vi a) {
    vl f(a.size() + 1);
    f[0] = 1;
    for (auto v : a) {
        auto g = f;
        lv(i, f) {
            if (i + 1 < f.size())
                g[i + 1] += f[i] * i * v;
        }
        f = g;
    }
    ll ans = 0;
    for (auto v : f)
        ans += v;
    return ans;
}
struct HorseTicket {
    string getTicket(vector<string> races, long long index) {
        map<char, int> pos;
        lv(i, races) for (auto c : races[i]) pos[c] = i;
        auto count = [&](integer::integer x) {
            ll ans = 0;
            vi vis(races.size());
            lv(i, x.d) {
                lp(v, 1, x.d[i] - 1) {
                    if (!pos.count(v))
                        continue;
                    int p = pos[v];
                    if (vis[p])
                        continue;
                    vis[p] = 1;
                    vi tmp;
                    lv(j, races) if (!vis[j]) tmp.push_back(j);
                    ans += work(tmp);
                    vis[p] = 0;
                }
                int v = x.d[i];
                if (!pos.count(v))
                    break;
                int p = pos[v];
                if (vis[p])
                    break;
                vis[p] = 1;
            }
        };
        integer::integer l;
        l.d.resize(62);
        integer::integer r(str(62, 'Z'));
        if (count(r) <= index) {
            return "!";
        }
        while (l + 1 < r) {
            auto m = (l + r) / 2;
            if (count(m) <= index)
                l = m;
            else
                r = m;
        }
        return l;
    }
};
int main_() {
    ios::sync_with_stdio(0);
    cout << setprecision(16) << fixed;
    cin.tie(0);
    return 0;
}
