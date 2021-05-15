#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
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
#define appl(f, a) for (auto i = begin(a); i != end(a); f, ++i)
#define rang(a) begin(a), end(a)
#define gene template <class T>
#define elif else if
#define intm modular_arithmetic::integer
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
    return (a > 0 && b > 0 || a < 0 && b < 0) ? abs(a) / abs(b)
                                              : -(abs(a) + abs(b) - 1) / abs(b);
}
gene T ceil(const T &a, const T &b) {
    assert(b != 0);
    return (a > 0 && b > 0 || a < 0 && b < 0) ? (abs(a) + abs(b) - 1) / abs(b)
                                              : -abs(a) / abs(b);
}
gene bool tmin(T &a, T b) { return b < a ? a = b, true : false; }
gene bool tmax(T &a, T b) { return b > a ? a = b, true : false; }
#if __cplusplus >= 201402L
gene auto min(const T &a) { return *min_element(rang(a)); }
gene auto max(const T &a) { return *max_element(rang(a)); }
gene auto sum(const T &a) {
    return accumulate(rang(a), (typename T::value_type)0);
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
#if __cplusplus >= 201703L
template <typename... T> void in(T &... a) { ((cin >> a), ...); }
template <typename A, typename... B> void ou(const A &a, const B &... b) {
    cout << a, ((cout << ' ' << b), ...), cout << endl;
}
#endif
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
        s = (a[0] == '-') ? -1 : (a != "0");
        for (int i = a.size() - 1; i >= (a[0] == '-'); i -= L) {
            int t = 0, j = max(i - L + 1, int(a[0] == '-'));
            for (int k = j; k <= i; ++k)
                t = t * 10 + a[k] - '0';
            d.push_back(t);
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
    static const int B = 1e8, L = 8;
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
int main() {
    fast, prec(12);
    int a, b;
    in(a, b);
    integer::integer p = 1, q = 1;
    lp(i, 1, b) p *= a;
    lp(i, 1, a) q *= b;
    ou(p - q);
    return 0;
}
