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
// The templates end here.
vector<pair<string, ll>> get_steps(ll n, ll m) {
    vector<pair<string, ll>> ans, rev;
    if (n == 1 && m == 1) {
        return ans;
    }
    if (n == 1) {
        ans.emplace_back("R", m - 1);
        ans.emplace_back("L", m - 1);
        return ans;
    }
    if (m == 1) {
        ans.emplace_back("D", n - 1);
        ans.emplace_back("U", n - 1);
        return ans;
    }
    char dir = 'u';
    lp(j, 1, m) {
       // ou(j);
        if (j == m) {
            if (dir == 'u') {
                ans.emplace_back("D", n - 1);
                rev.emplace_back("U", n - 1);
            } else {
                ans.emplace_back("U", n - 1);
                rev.emplace_back("D", n - 1);
            }
        } else {
            if (dir == 'u') {
                ans.emplace_back("RLD", n - 1);
                ans.emplace_back("R", 1);
                rev.emplace_back("U", n - 1);
                rev.emplace_back("L", 1);
            } else {
                ans.emplace_back("RLU", n - 1);
                ans.emplace_back("R", 1);
                rev.emplace_back("D", n - 1);
                rev.emplace_back("L", 1);
            }
        }
        if (dir == 'u')
            dir = 'd';
        else
            dir = 'u';
    }
    reve(rev);
    for (auto tmp : rev)
        ans.push_back(tmp);
    return ans;
}
int main() {
    fast, prec(12);
    ll n, m, k;
    in(n, m, k);
    auto steps = get_steps(n, m);
    // ou(steps);
    ll t = 0;
    for (auto &i : steps)
        t += ll(i.first.size()) * i.second;
    assert(t == 4 * n * m - 2 * n - 2 * m);
    if (k > t) {
        ou("NO");
    } else {
        // ou(steps);
        while (t - ll(steps.back().first.size()) * steps.back().second >= k) {
            t -= ll(steps.back().first.size()) * steps.back().second;
            steps.pop_back();
        }
        // ou(steps);
        while (t - steps.back().first.size() >= k) {
            t -= steps.back().first.size();
            steps.back().second--;
        }
        // ou(steps);
        ll remain = t - k;
        // ou(remain);
        if (remain != 0) {
            string tmp = steps.back().first;
            tmp = tmp.substr(0, tmp.size() - remain);
            --steps.back().second;
            if (steps.back().second == 0)
                steps.pop_back();
            steps.emplace_back(tmp, 1);
        }
        ou("YES");
        ou(steps.size());
        for (auto &i : steps) {
            ou(i.second, i.first);
        }
    }
    return 0;
}
