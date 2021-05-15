#include <bits/stdc++.h>
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
#define rang(a) a.begin(), a.end()
#define gene template <class T>
#pragma GCC optimize("O3")
using namespace std;
gene void sort(vector<T> &a) { sort(rang(a)); }
gene void reve(vector<T> &a) { reverse(rang(a)); }
gene T min(const vector<T> &a) { return *min_element(rang(a)); }
gene T max(const vector<T> &a) { return *max_element(rang(a)); }
gene T sum(const vector<T> &a) { return accumulate(rang(a), 0); }
gene T inf() { return numeric_limits<T>::max(); }
gene int updl(T &a, T b) { return b < a ? a = b, 1 : 0; }
gene int updg(T &a, T b) { return b > a ? a = b, 1 : 0; }
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
gene auto &operator>>(istream &s, pair<T, T> &a) {
    return s >> a.first >> a.second;
}
gene auto &operator>>(istream &s, vector<T> &a) {
    for (int i = -1; i < 0 && (!a.size() && (cin >> i, a.resize(i), 0), i = 0),
             i<a.size(); s>> a[i++])
        ;
    return s;
}
gene auto &operator<<(ostream &s, const pair<T, T> &a) {
    return s << '(' << a.first << ", " << a.second << ')';
}
gene auto &operator<<(ostream &s, const vector<T> &a) {
    lv(i, a) cout << a[i] << (i + 1 == a.size() ? "" : " ");
    return s;
}
int check(int sx, int sy, int tx, int ty, int x, int y) {
    // cout << vi{sx, sy, tx, ty, x, y} << endl;
    int lx = min(sx, tx), ly = min(sy, ty);
    int rx = max(sx, tx), ry = max(sy, ty);
    // cout << vi{lx, rx, ly, ry, x, y} << endl;
    return x >= lx && x <= rx && y >= ly && y <= ry;
}
int main() {
    fast, prec(12);
    int n, sx, sy;
    cin >> n >> sx >> sy;
    vpii a(n);
    cin >> a;
    // cout << a << endl;
    int ans1 = -1, ans2, ans3;
    lp(dx, -1, 1) lp(dy, -1, 1) {
        if (dx == 0 && dy == 0)
            continue;
        int tx = sx + dx, ty = sy + dy;
        if (tx < 0 || ty < 0)
            continue;
        if (tx > 1000000000 || ty > 1000000000)
            continue;
        int tmp = 0;
        lv(i, a) { tmp += check(sx, sy, a[i].first, a[i].second, tx, ty); }
        // cout << endl;
        // cout << tx << " " << ty << " " << tmp << "!" << endl;
        if (tmp > ans1) {
            ans1 = tmp;
            ans2 = tx;
            ans3 = ty;
        }
    }
    ou(ans1);
    cout << ans2 << " " << ans3 << endl;
    return 0;
}
