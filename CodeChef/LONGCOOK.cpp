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
#define intm modular_arithmetic::integer<int>
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
gene bool tmin(T &a, T b) { return b < a ? a = b, true : false; }
gene bool tmax(T &a, T b) { return b > a ? a = b, true : false; }
#if __cplusplus >= 201402L
gene auto min(const T &a) { return *min_element(rang(a)); }
gene auto max(const T &a) { return *max_element(rang(a)); }
gene auto sum(const T &a) { return accumulate(rang(a), 0); }
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
namespace date {
struct date {
    long long y, m, d, w;
    date &operator++() { return *this = *this + 1; }
    bool leap(long long a) const {
        return a % 400 == 0 || (a % 4 == 0 && a % 100 != 0);
    }
    long long month_sum(long long a, long long b) const {
        if (b == 0)
            return 0;
        if (b == 1)
            return 31;
        return 59 + leap(a) + 30 * (b - 2) + (b + 1) / 2 - 1 +
               (b >= 8 && b % 2 == 0);
    }
    string month_name(long long a) const {
        if (a == 1)
            return "January";
        if (a == 2)
            return "February";
        if (a == 3)
            return "March";
        if (a == 4)
            return "April";
        if (a == 5)
            return "May";
        if (a == 6)
            return "June";
        if (a == 7)
            return "July";
        if (a == 8)
            return "August";
        if (a == 9)
            return "September";
        if (a == 10)
            return "October";
        if (a == 11)
            return "November";
        if (a == 12)
            return "December";
    }
    string day_name(long long a) const {
        if (a == 0)
            return "Sunday";
        if (a == 1)
            return "Monday";
        if (a == 2)
            return "Tuesday";
        if (a == 3)
            return "Wednesday";
        if (a == 4)
            return "Thursday";
        if (a == 5)
            return "Friday";
        if (a == 6)
            return "Saturday";
    }
    operator long long() const {
        long long t = (y - 1) * 365 + (y - 1) / 4 - (y - 1) / 100 +
                      (y - 1) / 400 + month_sum(y, m - 1) + d;
        if (y == 1752 && m >= 9 && d > 2 || y > 1752)
            t -= 11;
        t -= min(y - 1, 1700ll) / 400 - min(y - 1, 1700ll) / 100;
        if (y <= 1700 && y % 400 != 0 && y % 100 == 0 && m > 2)
            ++t;
        return t;
    }
    static long long days_in_month(long long y, long long mm) {
        long long mt;
        if (mm == 2) {
            if (y <= 1700)
                mt = 28 + (y % 4 == 0);
            else
                mt = 28 + (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
        } else if (mm <= 7)
            mt = 30 + mm % 2;
        else
            mt = 31 - mm % 2;
        return mt;
    }
    date(long long _y, long long _m, long long _d)
        : y(_y), m(_m), d(_d), w(((long long)(*this) + 5) % 7) {}
    date(long long a) {
        long long yl = 0, yr = 1;
        while ((long long)(date(yr, 12, 31)) < a)
            yr *= 2;
        while (yl + 1 < yr) {
            long long ym = (yl + yr) / 2;
            if ((long long)(date(ym, 12, 31)) < a)
                yl = ym;
            else
                yr = ym;
        }
        y = yr;
        long long ml = 0, mr = 12;
        while (ml + 1 < mr) {
            long long mm = (ml + mr) / 2, mt = days_in_month(y, mm);
            if ((long long)(date(y, mm, mt)) < a)
                ml = mm;
            else
                mr = mm;
        }
        m = mr;
        for (long long i = 1;; ++i) {
            if (y == 1752 && m == 9 && i > 2 && i < 14)
                continue;
            if ((long long)(date(y, m, i)) == a) {
                d = i;
                break;
            }
        }
        w = (5 + a) % 7;
    }
    operator string() const {
        stringstream s;
        string t;
        s << day_name(w) + ", " + month_name(m) + " " << d << ", " << y;
        getline(s, t);
        return t;
    }
};
ostream &operator<<(ostream &s, const date &a) { return s << string(a); }
long long operator-(const date &a, const date &b) {
    return (long long)(a) - (long long)(b);
}
date operator+(const date &a, long long b) { return date((long long)(a) + b); }
date operator-(const date &a, long long b) { return date((long long)(a)-b); }
bool operator<(const date &a, const date &b) {
    if (a.y == b.y && a.m == b.m)
        return a.d < b.d;
    if (a.y == b.y)
        return a.m < b.m;
    return a.y < b.y;
}
bool operator>(const date &a, const date &b) { return b < a; }
bool operator!=(const date &a, const date &b) {
    return a.y != b.y || a.m != b.m || a.d != b.d;
}
bool operator==(const date &a, const date &b) { return !(a != b); }
} // namespace date
// The templates end here.
ll brute_force(int m1, int y1, int m2, int y2) {
    ll ans = 0;
    lp(y, y1, y2) {
        lp(m, 1, 12) {
            if (y == y1 && m < m1)
                continue;
            if (y == y2 && m > m2)
                continue;
            int num_days = date::date::days_in_month(y, m);
            vi fri, sun;
            lp(d, 1, num_days) {
                if (date::date(y, m, d).w == 5)
                    fri.push_back(d);
                if (date::date(y, m, d).w == 0)
                    sun.push_back(d);
            }
            int st_cha = fri[0], ed_cha = st_cha + 9;
            int st_coo = sun[sun.size() - 2];
            if (st_coo >= st_cha && st_coo <= ed_cha)
                ++ans;
        }
    }
    return ans;
}
int main() {
    fast, prec(12);
    many {
        int m1, y1, m2, y2;
        cin >> m1 >> y1 >> m2 >> y2;
        cout << brute_force(m1, y1, m2, y2) << endl;
    }
    return 0;
}
