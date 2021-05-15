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
#define freo freopen
#define many for (int T = -1; T < 0 && cin >> T, T--;)
#define appl(f, a) for (auto i = begin(a); i != end(a); f, ++i)
#define rang(a) begin(a), end(a)
#define gene template <class T>
#define elif else if
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
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef string str;
// The templates end here.
vector<int> solve_naive(int n, int p, vi d) {
    vi l(n), cur(n), ans;
    lv(i, d) {
        if (p % d[i] != 0) {
            l[i] = p / d[i] + 1;
        } else
            l[i] = p / d[i] - 1;
    }
    function<void(int)> dfs = [&n, &p, &d, &l, &cur, &dfs, &ans](int level) {
        if (level == n) {
            int s = 0;
            lv(i, cur) s += cur[i] * d[i];
            if (s <= p)
                return;
            lv(i, cur) if (cur[i] && s - d[i] >= p) return;
            ans = cur;
        } else {
            lp(i, 0, l[level]) {
                cur[level] = i;
                dfs(level + 1);
                if (ans.size())
                    return;
            }
        }
    };
    dfs(0);
    if (!ans.size())
        ans = vi(n, -1);
    return ans;
}
vector<int> solve(int n, int p, vi d) {
    vi c;
    lv(i, d) if (p % d[i] != 0) {
        c.resize(n);
        lv(j, d) c[j] = (i == j ? p / d[i] + 1 : 0);
        return c;
    }
    for (int i = 1; i < d.size(); ++i) {
        if (d[i] % d[i - 1] != 0) {
            c.resize(n);
            lv(j, d) {
                if (j == i - 1) {
                    c[j] = p / d[i - 1] - 1;
                }
                elif (j == i) {
                    c[j] = 1;
                    ll sm = c[j - 1] * d[j - 1] + d[j] - p;
                    sm /= d[j - 1];
                    c[j - 1] -= sm;
                }
                else c[j] = 0;
            }
            return c;
        }
    }
    return vi(n, -1);
}
int main_duipai() {
    fast, prec(12);
    while (true) {
        int n, p;
        n = rint(1, 5);
        p = rint(1, 20);
        vi d(n);
        lv(i, d) {
            int f = i ? d[i - 1] : 0;
            d[i] = rint(f + 1, 20 - (n - i - 1));
        }
        // ou(n, p);
        // ou(d);
        auto ans1 = solve(n, p, d);
        auto ans2 = solve_naive(n, p, d);
        auto check = [&n, &p, &d](vi ans) {
            lv(i, ans) if (ans[i] < 0 || ans[i] > int(1e9)) return false;
            int s = 0;
            lv(i, ans) s += d[i] * ans[i];
            if (s <= p)
                return false;
            lv(i, ans) if (ans[i] && s - d[i] >= p) return false;
            return true;
        };
        // ou(ans1);
        // ou(ans2);
        cout << endl;
        if (check(ans1) != check(ans2)) {
            break;
        }
    }
    return 0;
}
int main() {
    fast, prec(12);
    many {
        int n, p;
        cin >> n >> p;
        vi d(n);
        cin >> d;
        auto ans = solve(n, p, d);
        if (ans[0] == -1)
            cout << "NO" << endl;
        else {
            cout << "YES ";
            lv(i, ans) cout << " " << ans[i];
            cout << endl;
        }
    }
    return 0;
}