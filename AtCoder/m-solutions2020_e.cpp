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
void solve(int n, vi x, vi y, vi p) {
    vl ans(n + 1, inf<ll>());
    auto build2 = [&](vpii a) {
        if (a.empty()) {
            return vl(n + 1);
        }
        int truen = n;
        int n = a.size();
        auto f = vect<ll>(0, n, n);
        rp(i, n - 1, 0) {
            ll allsum = 0;
            vl psum;
            int now = i;
            ll nowcost = 0;
            lp(j, i, n - 1) {
                if (psum.size())
                    psum.push_back(psum.back() + a[j].second);
                else
                    psum.push_back(0 + a[j].second);
                allsum += a[j].second;
                nowcost += ll(a[j].first - a[now].first) * a[j].second;
                while (now != j) {
                    ll delta = (psum[now - i] - (allsum - psum[now - i])) *
                               (a[now + 1].first - a[now].first);
                    if (delta <= 0) {
                        ++now;
                        nowcost += delta;
                    } else {
                        break;
                    }
                }
                f[i][j] = nowcost;
                if (nowcost < 0) {
                    ou(a);
                    ou(i, j);
                    ou(nowcost);
                    exit(-1);
                }
            }
        }
        // ou(111);
        auto dp = vect<ll>(inf<ll>(), n + 1, truen + 1);
        dp[0][0] = 0;
        lp(i, 1, n) {
            dp[i][0] = 0;
            lp(j, 0, i - 1) { dp[i][0] += (ll)a[j].first * a[j].second; }
        }
        lp(cnt, 0, truen - 1) {
            lp(i, 0, n - 1) {
                if (dp[i][cnt] == inf<ll>())
                    continue;
                tmin(dp[i][cnt + 1], dp[i][cnt]);
                lp(k, i + 1, n) {
                    tmin(dp[k][cnt + 1], dp[i][cnt] + f[i + 1 - 1][k - 1]);
                }
            }
        }
        return dp.back();
    };
    auto build = [&](vpii a) {
        // ou("in", a.size());
        vpii a0, a1;
        for (auto t : a)
            if (t.first < 0)
                a0.push_back({t.first * -1, t.second});
            else
                a1.push_back(t);
        reve(a0);
        auto fx = build2(a0);
        auto fy = build2(a1);
        vl ans(n + 1, inf<ll>());
        lp(cx, 0, n) lp(cy, 0, n - cx) tmin(ans[cx + cy], fx[cx] + fy[cy]);
        // ou("out", a.size());
        return ans;
    };
    lp(m, 0, (1 << n) - 1) {
        vpii xx, yy;
        lp(i, 0, n - 1) {
            if (barr(m, i))
                xx.push_back({x[i], p[i]});
            else
                yy.push_back({y[i], p[i]});
        }
        sort(xx);
        sort(yy);
        auto fx = build(xx);
        auto fy = build(yy);
        lp(cx, 0, n) lp(cy, 0, n - cx) tmin(ans[cx + cy], fx[cx] + fy[cy]);
    }
    for (auto v : ans) {
        ou(v);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cout << setprecision(16) << fixed;
    cin.tie(0);
    int n;
    in(n);
    vi x(n), y(n), p(n);
    lv(i, x) in(x[i], y[i], p[i]);
    solve(n, x, y, p);
    while (0) {
        int n = rint(1, 15);
        vi x(n), y(n), p(n);
        lv(i, x) x[i] = rint(-10000, 10000), y[i] = rint(-10000, 10000),
                 p[i] = rint(1, 1000000);
        solve(n, x, y, p);
    }
    return 0;
}
