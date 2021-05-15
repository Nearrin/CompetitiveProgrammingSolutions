#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#define lp(i, l, r) for (int i = l; i <= int(r); ++i)
#define rp(i, r, l) for (int i = int(r); i >= l; --i)
#define ls(i, s) for (int i = 0; s[i]; ++i)
#define rs(i, s) for (int i = strlen(s) - 1; i >= 0; --i)
#define lv(i, a) for (int i = 0; i < int(a.size()); ++i)
#define rv(i, a) for (int i = int(a.size()) - 1; i >= 0; --i)
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define prec(a) cout << setprecision(a) << fixed
#define many for (int T = -1; T < 0 && cin >> T, T--;)
#define appl(f, a) for (auto i = begin(a); i != end(a); f, ++i)
#define rang(a) begin(a), end(a)
#define tstr(a) to_string(a)
#define gene template <class T>
#ifndef LOCAL
#define endl '\n'
#define assert
#endif
using namespace std;
using namespace __gnu_pbds;
gene T inf() { return numeric_limits<T>::max(); }
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
gene void shuf(T &a) { random_shuffle(rang(a)); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
#if __cplusplus >= 201703L
template <typename... T> void in(T &... a) { ((cin >> a), ...); }
template <typename... T> void ou(T... a) { ((cout << a << ' '), ...) << endl; }
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
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef string str;
namespace half_plane_intersection {
struct point {
    point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
    double x, y;
};
double angle(const point &p) { return atan2(double(p.x), double(p.y)); }
point operator+(const point &p, const point &q) {
    return point(p.x + q.x, p.y + q.y);
}
point operator-(const point &p, const point &q) {
    return point(p.x - q.x, p.y - q.y);
}
point operator*(const point &p, double q) { return point(p.x * q, p.y * q); }
point operator/(const point &p, double q) { return point(p.x / q, p.y / q); }
double cross(const point &p, const point &q) { return p.x * q.y - q.x * p.y; }
double dot(const point &p, const point &q) { return p.x * q.x + p.y * q.y; }
struct line {
    point p, q;
    double a;
    line(const point &_p, const point &_q) : p(_p), q(_q), a(angle(p - q)) {}
};
point intersection(const line &a, const line &b) {
    double a1 = cross(b.p - a.q, b.q - b.p);
    double a2 = cross(a.p - b.q, b.q - b.p);
    return (a.p * a1 + a.q * a2) / (a1 + a2);
}
bool operator<(const line &a, const line &b) {
    if (fabs(a.a - b.a) > 1e-8)
        return a.a < b.a;
    else
        return cross(a.q - b.p, b.q - b.p) < -1e-8;
}
bool left(const line &a, const line &b, const line &c) {
    return cross(intersection(a, b) - c.p, c.q - c.p) < -1e-8;
}
double area(const vector<point> &points) {
    assert(points.size());
    double a = 0;
    for (int i = 0; i < int(points.size()); ++i)
        a += cross(points[i] - points[0],
                   points[(i + 1) % points.size()] - points[0]);
    return fabs(a) / 2;
}
point rotate(const point &p, double a) {
    double s = sin(a), c = cos(a);
    return point(p.x * c - p.y * s, p.x * s + p.y * c);
}
line rotate(const line &l, double a) {
    return line(rotate(l.p, a), rotate(l.q, a));
}
pair<vector<line>, vector<point>> half_plane_intersection(vector<line> lines) {
    deque<line> result;
    sort(lines.begin(), lines.end());
    for (int i = 0; i < int(lines.size()); ++i) {
        while (result.size() > 1 &&
               !left(result.back(), result[result.size() - 2], lines[i]))
            result.pop_back();
        while (result.size() > 1 && !left(result[0], result[1], lines[i]))
            result.pop_front();
        if (result.empty() || fabs(result.back().a - lines[i].a) > 1e-8)
            result.push_back(lines[i]);
    }
    while (result.size() > 1 &&
           !left(result.back(), result[result.size() - 2], result.front()))
        result.pop_back();
    if (result.size() < 3)
        result.clear();
    vector<point> points;
    lines.clear();
    for (const auto &l : result) {
        if (lines.size())
            points.push_back(intersection(lines.back(), l));
        lines.push_back(l);
    }
    if (lines.size())
        points.push_back(intersection(lines.front(), lines.back()));
    return make_pair(lines, points);
}
} // namespace half_plane_intersection
int main() {
    fast, prec(12);
    using namespace half_plane_intersection;
    vector<line> lines;
    double w, h, a;
    cin >> w >> h >> a;
    lines.push_back(line(point(w / 2, -h / 2), point(w / 2, h / 2)));
    lines.push_back(line(point(w / 2, h / 2), point(-w / 2, h / 2)));
    lines.push_back(line(point(-w / 2, h / 2), point(-w / 2, -h / 2)));
    lines.push_back(line(point(-w / 2, -h / 2), point(w / 2, -h / 2)));
    lp(i, 0, 3) lines.push_back(rotate(lines[i], a / 180 * acos(-1)));
    ou(area(half_plane_intersection::half_plane_intersection(lines).second));
    return 0;
}
