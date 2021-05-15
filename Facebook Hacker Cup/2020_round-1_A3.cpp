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
int main() {
    ios::sync_with_stdio(0);
    cout << setprecision(16) << fixed;
    cin.tie(0);
    many {
        int n, k;
        in(n, k);
        vi l(k);
        in(l);
        ll al, bl, cl, dl;
        in(al, bl, cl, dl);
        vi w(k);
        in(w);
        ll aw, bw, cw, dw;
        in(aw, bw, cw, dw);
        vi h(k);
        in(h);
        ll ah, bh, ch, dh;
        in(ah, bh, ch, dh);
        l.resize(n);
        h.resize(n);
        w.resize(n);
        lp(i, k, n - 1) {
            l[i] = (al * l[i - 2] + bl * l[i - 1] + cl) % dl + 1;
            w[i] = (aw * w[i - 2] + bw * w[i - 1] + cw) % dw + 1;
            h[i] = (ah * h[i - 2] + bh * h[i - 1] + ch) % dh + 1;
        }
        map<pii, int> covered;
        ll cur_peri = 0, ans = 1;
        auto insert_block = [&](int left, int right, int height) {
            assert(left < right);
            auto itright = covered.lower_bound({left, right});
            int touchright = 0;
            auto itleft = itright;
            int touchleft = 0;
            if (itright != covered.end() && itright->first.first == right) {
                touchright = 1;
            }
            if (itleft != covered.begin()) {
                --itleft;
                if (itleft->first.second == left) {
                    touchleft = 1;
                }
            }
            if (touchright + touchleft == 0) {
                cur_peri += 2 * height;
                cur_peri += 2 * (right - left);
                cur_peri %= int(1e9 + 7);
                covered[{left, right}] = height;
            }
            elif (touchleft == 0) {
                if (height < itright->second) {
                    cur_peri += 2 * (right - left);
                    cur_peri %= int(1e9 + 7);
                } else {
                    cur_peri += 2 * (right - left);
                    cur_peri += 2 * (height - itright->second);
                    cur_peri %= int(1e9 + 7);
                }
                covered[{left, right}] = height;
            }
            elif (touchright == 0) {
                if (height < itleft->second) {
                    cur_peri += 2 * (right - left);
                    cur_peri %= int(1e9 + 7);
                } else {
                    cur_peri += 2 * (right - left);
                    cur_peri += 2 * (height - itleft->second);
                    cur_peri %= int(1e9 + 7);
                }
                covered[{left, right}] = height;
            }
            else {
                cur_peri -= itleft->second;
                cur_peri -= itright->second;
                cur_peri += 2 * (right - left);
                cur_peri += abs(height - itleft->second);
                cur_peri += abs(height - itright->second);
                cur_peri %= int(1e9 + 7);
                cur_peri += int(1e9 + 7);
                cur_peri %= int(1e9 + 7);
                covered[{left, right}] = height;
            }
        };
        auto remove_block = [&](int left, int right) {
            auto it = covered.find({left, right});
            int height = it->second;
            covered.erase(it);
            auto itright = covered.lower_bound({left, right});
            int touchright = 0;
            auto itleft = itright;
            int touchleft = 0;
            if (itright != covered.end() && itright->first.first == right) {
                touchright = 1;
            }
            if (itleft != covered.begin()) {
                --itleft;
                if (itleft->first.second == left) {
                    touchleft = 1;
                }
            }
            if (touchright + touchleft == 0) {
                cur_peri -= 2 * height;
                cur_peri -= 2 * (right - left);
                cur_peri %= int(1e9 + 7);
                cur_peri += int(1e9 + 7);
                cur_peri %= int(1e9 + 7);
            }
            elif (touchleft == 0) {
                if (height < itright->second) {
                    cur_peri -= 2 * (right - left);
                    cur_peri %= int(1e9 + 7);
                    cur_peri += int(1e9 + 7);
                    cur_peri %= int(1e9 + 7);
                } else {
                    cur_peri -= 2 * (right - left);
                    cur_peri -= 2 * (height - itright->second);
                    cur_peri %= int(1e9 + 7);
                    cur_peri += int(1e9 + 7);
                    cur_peri %= int(1e9 + 7);
                }
            }
            elif (touchright == 0) {
                if (height < itleft->second) {
                    cur_peri -= 2 * (right - left);
                    cur_peri %= int(1e9 + 7);
                    cur_peri += int(1e9 + 7);
                    cur_peri %= int(1e9 + 7);
                } else {
                    cur_peri -= 2 * (right - left);
                    cur_peri -= 2 * (height - itleft->second);
                    cur_peri %= int(1e9 + 7);
                    cur_peri += int(1e9 + 7);
                    cur_peri %= int(1e9 + 7);
                }
            }
            else {
                cur_peri += itleft->second;
                cur_peri += itright->second;
                cur_peri -= 2 * (right - left);
                cur_peri -= abs(height - itleft->second);
                cur_peri -= abs(height - itright->second);
                cur_peri %= int(1e9 + 7);
                cur_peri += int(1e9 + 7);
                cur_peri %= int(1e9 + 7);
            }
        };
        lv(i, l) {
            while (1) {
                auto it = covered.lower_bound({l[i], -inf()});
                if (it == covered.end())
                    break;
                if (it->first.first >= l[i] + w[i])
                    break;
                if (it->first.second <= l[i] + w[i]) {
                    remove_block(it->first.first, it->first.second);
                } else {
                    int tl = it->first.first, tr = it->first.second,
                        th = it->second;
                    remove_block(tl, tr);
                    insert_block(tl, l[i] + w[i], h[i]);
                    insert_block(l[i] + w[i], tr, th);
                    w[i] = tl - l[i];
                    break;
                }
            }
            if (w[i]) {
                auto it = covered.lower_bound({l[i], -inf()});
                if (it == covered.begin()) {
                    insert_block(l[i], l[i] + w[i], h[i]);
                } else {
                    --it;
                    if (it->first.second <= l[i]) {
                        insert_block(l[i], l[i] + w[i], h[i]);
                    } else {
                        int tl = it->first.first, tr = it->first.second,
                            th = it->second;
                        remove_block(tl, tr);
                        if (tr <= l[i] + w[i]) {
                            insert_block(tl, l[i], th);
                            insert_block(l[i], l[i] + w[i], h[i]);
                        } else {
                            insert_block(tl, l[i], th);
                            insert_block(l[i], l[i] + w[i], h[i]);
                            insert_block(l[i] + w[i], tr, th);
                        }
                    }
                }
            }
            ans = ans * cur_peri % int(1e9 + 7);
        }
        ou(goog, ans);
    }
    return 0;
}
