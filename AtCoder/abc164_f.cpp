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
#define retu return
#define pufr push_front
#define pofr pop_front
#define puba push_back
#define poba pop_back
#define intm modular_arithmetic::integer
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
gene int bcnt(const T &a) { return __builtin_popcount(a); }
template <> int bcnt(const int64_t &a) { return __builtin_popcountll(a); }
gene int blen(const T &a) { return a ? 1 + blen(a / 2) : 0; }
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
#if __cplusplus > 201103L
gene auto min(const T &a) { return *min_element(rang(a)); }
gene auto max(const T &a) { return *max_element(rang(a)); }
gene auto sum(const T &a) {
    return accumulate(rang(a), (typename T::value_type)0);
}
template <> auto sum(const vector<int> &a) { return accumulate(rang(a), 0ll); }
template <> auto sum(const vector<string> &a) {
    return accumulate(rang(a), string());
}
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
#endif
template <class T, class C = less<typename T::value_type>>
void sort(T &a, C c = C()) {
    sort(rang(a), c);
}
gene void reve(T &a) { reverse(rang(a)); }
gene void uniq(T &a) { sort(a), a.erase(unique(rang(a)), end(a)); }
gene void shuf(T &a) { shuffle(rang(a), rng); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
#if __cplusplus > 201103L
gene auto vect(const vector<T> &v, int n) {
    assert(v.size() <= 1);
    return v.size() ? vector<T>(n, v[0]) : vector<T>(n);
}
template <class T, class... D> auto vect(const vector<T> &v, int n, D... m) {
    return vector<decltype(vect(v, m...))>(n, vect(v, m...));
}
#endif
template <class F, class S> pair<F, S> operator-(pair<F, S> a) {
    a.first = -a.first, a.second = -a.second;
    return a;
}
template <class F, class S>
pair<F, S> operator+(pair<F, S> a, const pair<F, S> &b) {
    a.first += b.first, a.second += b.second;
    return a;
}
template <class F, class S>
pair<F, S> operator-(pair<F, S> a, const pair<F, S> &b) {
    a.first -= b.first, a.second -= b.second;
    return a;
}
template <class F, class S>
pair<F, S> operator*(pair<F, S> a, const pair<F, S> &b) {
    a.first *= b.first, a.second *= b.second;
    return a;
}
template <class F, class S>
pair<F, S> operator/(pair<F, S> a, const pair<F, S> &b) {
    a.first /= b.first, a.second /= b.second;
    return a;
}
template <class F, class S, class T>
pair<F, S> operator*=(pair<F, S> a, const T &b) {
    a.first *= b, a.second *= b;
    return a;
}
template <class F, class S, class T>
pair<F, S> operator/=(pair<F, S> a, const T &b) {
    a.first /= b, a.second /= b;
    return a;
}
#if __cplusplus > 201103L
template <class F, class S> struct zip_ {
    zip_(F &f_, S &s_) : f(f_), s(s_) {}
    template <class I, class J> struct iterator {
        iterator(I i_, J j_) : i(i_), j(j_) {}
        auto operator++() {
            ++i, ++j;
            return *this;
        }
        bool operator!=(const iterator &a) const {
            assert((i != a.i && j != a.j) || (i == a.i && j == a.j));
            return i != a.i;
        }
        auto operator*() const { return make_pair(*i, *j); }
        I i;
        J j;
    };
    template <class I, class J> auto iterator_(I i, J j) const {
        return iterator<I, J>(i, j);
    }
    auto begin() const { return iterator_(f.begin(), s.begin()); }
    auto end() const { return iterator_(f.end(), s.end()); }
    F &f;
    S &s;
};
template <class F, class S> auto zip(F &f, S &s) { return zip_<F, S>(f, s); }
#endif
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
gene T in() {
    T a;
    cin >> a;
    return a;
}
gene void in(T &a) { cin >> a; }
template <class A, class... B> void in(A &a, B &... b) { cin >> a, in(b...); }
void ou() { cout << endl; }
gene void ou(const T &a) { cout << a << endl; }
template <class A, class... B> void ou(const A &a, const B &... b) {
    cout << a << ' ', ou(b...);
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
typedef string str;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pil> vpil;
typedef vector<pli> vpli;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
// The templates end here.
int fail = 0;
auto construct(vi &s, vi &t, vi &u, vi &v) {
    /*
    ou(s);
    ou(t);
    ou(u);
    ou(v);
    ou(fail);*/
    int n = s.size();
    auto a = vect<uint64_t>({2}, n, n);
    int row_one = 0, row_zero = 0, col_one = 0, col_zero = 0;
    vpii rows, cols;
    lp(i, 0, n - 1) {
        if (s[i] == 0 && u[i] == 1) {
            lp(j, 0, n - 1) a[i][j] = 1;
            ++row_one;
        }
        elif (s[i] == 1 && u[i] == 0) {
            lp(j, 0, n - 1) a[i][j] = 0;
            ++row_zero;
        }
        else rows.push_back({i, -1});
    }
    lp(i, 0, n - 1) {
        if (t[i] == 0 && v[i] == 1) {
            lp(j, 0, n - 1) a[j][i] = 1;
            ++col_one;
        }
        elif (t[i] == 1 && v[i] == 0) {
            lp(j, 0, n - 1) a[j][i] = 0;
            ++col_zero;
        }
        else cols.push_back({i, -1});
    }
    if (row_one && col_zero) {
        fail = 1;
        return a;
    }
    if (row_zero && col_one) {
        fail = 1;
        return a;
    }
    int rowhasm1 = 0, colhasm1 = 0;
    int rowhas0 = 0, rowhas1 = 0, colhas0 = 0, colhas1 = 0;
    for (auto &tt : rows) {
        int i = tt.first;
        if (s[i] == 0 && u[i] == 0) {
            if (col_zero) {
                rowhasm1 = 1;
            } else {
                tt.second = 0;
                rowhas0++;
            }
        } else {
            if (col_one) {
                rowhasm1 = 1;

            } else {
                tt.second = 1;
                rowhas1++;
            }
        }
    }
    for (auto &tt : cols) {
        int i = tt.first;
        if (t[i] == 0 && v[i] == 0) {
            if (row_zero) {
                colhasm1 = 1;
            } else {
                tt.second = 0;
                colhas0++;
            }
        } else {
            if (row_one) {
                colhasm1 = 1;
            } else {
                tt.second = 1;
                colhas1++;
            }
        }
    }
    /*
        ou("rows");
        for (auto tmp : rows)
            ou(tmp);
        ou("cols");
        for (auto tmp : cols)
            ou(tmp);
    */
    if (!rows.size() || !cols.size()) {
        if (rowhas0 || rowhas1 || colhas0 || colhas1)
            fail = 1;
        return a;
    }
    if (rowhasm1) {
        for (auto r : rows) {
            for (auto c : cols) {
                if (r.second == -1) {
                    a[r.first][c.first] = max(c.second, 0);
                } else {
                    a[r.first][c.first] = r.second;
                }
            }
        }
        return a;
    }
    if (colhasm1) {
        for (auto c : cols) {
            for (auto r : rows) {
                if (c.second == -1) {
                    // ou(r.first, c.first, max(r.second, 0));
                    a[r.first][c.first] = max(r.second, 0);
                } else {
                    a[r.first][c.first] = c.second;
                }
            }
        }
        return a;
    }
    if (!colhas1) {
        if (!rowhas0) {
            if (colhas0 == 1) {
                fail = 1;
            } else {
                int rcnt = 0;
                for (auto r : rows) {
                    int ccnt = 0;
                    for (auto c : cols) {
                        int tg = rowhas1 > colhas0 ? 0 : 1;
                        if (rcnt != ccnt)
                            a[r.first][c.first] = 1 - tg;
                        else
                            a[r.first][c.first] = tg;
                        ++ccnt;
                    }
                    ++rcnt;
                }
            }
            return a;
        }
        for (auto r : rows) {
            for (auto c : cols) {
                a[r.first][c.first] = r.second;
            }
        }
        return a;
    }
    if (!colhas0) {
        if (!rowhas1) {
            if (colhas1 == 1) {
                fail = 1;
            } else {
                int rcnt = 0;
                for (auto r : rows) {
                    int ccnt = 0;
                    for (auto c : cols) {
                        int tg = colhas1 > rowhas0 ? 0 : 1;
                        if (rcnt != ccnt)
                            a[r.first][c.first] = 1 - tg;
                        else
                            a[r.first][c.first] = tg;
                        ++ccnt;
                    }
                    ++rcnt;
                }
            }
            return a;
        }
        for (auto r : rows) {
            for (auto c : cols) {
                a[r.first][c.first] = r.second;
            }
        }
        return a;
    }
    for (auto r : rows) {
        for (auto c : cols) {
            a[r.first][c.first] = c.second;
        }
    }
    return a;
}
int main() {
    fast, prec(12);
    int n;
    in(n);
    vi s(n), t(n);
    vector<uint64_t> u(n), v(n);
    in(s, t, u, v);
    auto a = vect<uint64_t>({}, n, n);
    for (int i = 0; i < 64; ++i) {
        vi newu(n), newv(n);
        lp(j, 0, n - 1) {
            newu[j] = (u[j] >> i) & 1;
            newv[j] = (v[j] >> i) & 1;
        }
        auto b = construct(s, t, newu, newv);
        lp(j, 0, n - 1) lp(k, 0, n - 1) a[j][k] += b[j][k] << i;
    }
    if (fail) {
        ou(-1);
        return 0;
    }
    for (auto t : a)
        ou(t);
    return 0;
}
