#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#define lp(i, l, r) for (int i = l; i <= r; ++i)
#define rp(i, r, l) for (int i = r; i >= l; --i)
#define ls(i, s) for (int i = 0; s[i]; ++i)
#define rs(i, s) for (int i = strlen(s) - 1; i >= 0; --i)
#define lv(i, a) for (int i = 0; i < a.size(); ++i)
#define rv(i, a) for (int i = (int)a.size() - 1; i >= 0; --i)
#define in(a) int a = (cin >> a, a)
#define ou(a) cout << a << endl
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define prec(a) cout << setprecision(a) << fixed
#define many for (int T = -1; T < 0 && cin >> T, T--;)
#define rang(a) begin(a), end(a)
#define gene template <class T>
#define endl '\n'
#pragma GCC optimize("O3")
using namespace std;
using namespace __gnu_pbds;
gene void sort(vector<T> &a) { sort(rang(a)); }
gene void reve(vector<T> &a) { reverse(rang(a)); }
gene void uniq(vector<T> &a) { sort(a), a.erase(unique(rang(a)), end(a)); }
gene void shuf(vector<T> &a) { random_shuffle(rang(a)); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
gene T min(const vector<T> &a) { return *min_element(rang(a)); }
gene T max(const vector<T> &a) { return *max_element(rang(a)); }
gene T sum(const vector<T> &a) { return accumulate(rang(a), 0); }
gene T inf() { return numeric_limits<T>::max(); }
gene int updl(T &a, T b) { return b < a ? a = b, 1 : 0; }
gene int updg(T &a, T b) { return b > a ? a = b, 1 : 0; }
gene using bbst =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
gene using heap = __gnu_pbds::priority_queue<T, greater<T>, pairing_heap_tag>;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
template <class F, class S> auto &operator>>(istream &s, pair<F, S> &a) {
    return s >> a.first >> a.second;
}
gene auto &operator>>(istream &s, vector<T> &a) {
    for (int i = -1; i < 0 && (!a.size() && (cin >> i, a.resize(i), 0), i = 0),
             i < a.size();)
        s >> a[i++];
    return s;
}
template <class F, class S> auto &operator<<(ostream &s, const pair<F, S> &a) {
    return s << '(' << a.first << ", " << a.second << ')';
}
gene auto &operator<<(ostream &s, const vector<T> &a) {
    lv(i, a) cout << a[i] << (i + 1 == a.size() ? "" : " ");
    return s;
}
namespace smallest_circle {
template <class T> auto operator+(const pair<T, T> &a, const pair<T, T> &b) {
    return make_pair(a.first + b.first, a.second + b.second);
}
template <class T> auto operator-(const pair<T, T> &a, const pair<T, T> &b) {
    return make_pair(a.first - b.first, a.second - b.second);
}
template <class T> auto operator*(const pair<T, T> &a, const pair<T, T> &b) {
    return a.first * b.second - a.second * b.first;
}
template <class T> auto operator*(const pair<T, T> &a, T b) {
    return make_pair(a.first * b, a.second * b);
}
template <class T> auto operator/(const pair<T, T> &a, T b) {
    return make_pair(a.first / b, a.second / b);
}
template <class T> T square(T x) { return x * x; }
template <class T> T abs(const pair<T, T> &a) {
    return sqrt(square(a.first) + square(a.second));
}
template <class T> pair<T, T> rotate(const pair<T, T> &a) {
    return make_pair(a.second, -a.first);
}
template <class T = double> struct circle {
    circle(const vector<pair<T, T>> &b) {
        if (!b.size())
            r = -1;
        else if (b.size() == 1)
            c = b[0], r = 0;
        else if (b.size() == 2)
            c = (b[0] + b[1]) / T(2), r = abs(c - b[0]);
        else {
            assert(b.size() == 3);
            auto c_1 = (b[0] + b[1]) / T(2), c_2 = (b[0] + b[2]) / T(2),
                 v_1 = rotate(b[1] - b[0]), v_2 = rotate(b[2] - b[0]);
            c = v_1 * ((c_2 - c_1) * v_2) / (v_1 * v_2) + c_1,
            r = abs(c - b[0]);
        }
    }
    bool contains(const pair<T, T> &p) { return abs(p - c) <= r + 1e-8; }
    pair<T, T> c;
    T r;
};
template <class T, class I>
circle<T> welzls_algorithm(const I &l, const I &r,
                           const vector<pair<T, T>> &b) {
    circle<T> c(b);
    if (b.size() != 3 || l == r) {
        for (auto i = l; i != r; ++i) {
            if (!c.contains(*i)) {
                auto t = b;
                t.push_back(*i);
                c = welzls_algorithm(l, i, t);
            }
        }
    }
    return c;
}
template <class T> auto welzls_algorithm(vector<pair<T, T>> points) {
    shuf(points);
    return welzls_algorithm(begin(points), end(points), vector<pair<T, T>>());
}
} // namespace smallest_circle
int main() {
    fast, prec(12);
    vector<pair<double, double>> p;
    cin >> p;
    auto c = smallest_circle::welzls_algorithm(p);
    cout << c.r << endl;
    return 0;
}