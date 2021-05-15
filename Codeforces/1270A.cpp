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
#define asse assert
#pragma GCC optimize("O3")
using namespace std;
using namespace __gnu_pbds;
gene void sort(T &a) { sort(rang(a)); }
gene void reve(T &a) { reverse(rang(a)); }
gene void uniq(T &a) { sort(a), a.erase(unique(rang(a)), end(a)); }
gene void shuf(T &a) { random_shuffle(rang(a)); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
gene auto min(const T &a) { return *min_element(rang(a)); }
gene auto max(const T &a) { return *max_element(rang(a)); }
gene auto sum(const T &a) { return accumulate(rang(a), 0); }
gene T inf() { return numeric_limits<T>::max(); }
gene int tmax(T &a, T b) { return b < a ? a = b, 1 : 0; }
gene int tmin(T &a, T b) { return b > a ? a = b, 1 : 0; }
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
int main() {
    fast, prec(12);
    many {
        in(n);
        in(k1);
        in(k2);
        vector<int> a(k1), b(k2);
        cin >> a >> b;
        if (max(a) > max(b))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
