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
ll convert(vector<int> t, int n) {
    sort(t);
    ll r = 0;
    for (auto i : t)
        r = r * n + i - 1;
    return r;
}
int main() {
    fast, prec(12);
    many {
        in(n);
        vvi t(n - 2, vi(3));
        unordered_map<ll, int> cnt;
        unordered_set<ll> exist;
        unordered_map<ll, int> idx;
        lp(i, 0, n - 3) {
            cin >> t[i];
            cnt[convert({t[i][0], t[i][1]}, n)] += 1;
            cnt[convert({t[i][1], t[i][2]}, n)] += 1;
            cnt[convert({t[i][2], t[i][0]}, n)] += 1;
            exist.insert(convert(t[i], n));
            idx[convert(t[i], n)] = i + 1;
        }
        // cout << endl;
        vvi to(n + 1);
        for (auto i : cnt) {
            if (i.second == 1) {
                int v1 = i.first % n + 1, v2 = i.first / n + 1;
                // cout << vi{v1, v2, i.second} << endl;
                to[v1].push_back(v2);
                to[v2].push_back(v1);
            }
        }
        // cout.flush();
        int s = 1;
        vi vis(n + 1);
        vi poly;
        lp(i, 1, n) {
            poly.push_back(s);
            vis[s] = 1;
            if (i != n) {
                assert(to[s].size() == 2);
                int c1 = to[s][0], c2 = to[s][1];
                if (vis[c1]) {
                    s = c2;
                } else
                    s = c1;
            }
        }
        cout << poly << endl;
        vi next(n + 1), pre(n + 1);
        for (int i = 0; i < n; ++i) {
            next[poly[i]] = poly[(i + 1) % n];
            pre[poly[i]] = poly[(i - 1 + n) % n];
        }
        queue<vi> qu;
        lp(i, 0, n - 1) {
            ll tmp =
                convert({poly[i], poly[(i + 1) % n], poly[(i + 2) % n]}, n);
            if (exist.count(tmp)) {
                qu.push({poly[i], poly[(i + 1) % n], poly[(i + 2) % n]});
            }
        }
#define check(v1, v2, v3)                                                      \
    ((pre[v2] == v1 || pre[v2] == v3) && (next[v2] == v1 || next[v2] == v3))
        lp(i, 1, n - 2) {
            assert(qu.size());
            auto v = qu.front();
            qu.pop();
            int v1 = v[0], v2 = v[1], v3 = v[2];
            if (check(v1, v2, v3))
                swap(v1, v2);
            else if (check(v1, v3, v2))
                swap(v1, v3);
            // cout << "d" << vi{v2, v1, v3} << endl << flush;
            assert(check(v2, v1, v3));
            cout << idx[convert({v1, v2, v3}, n)];
            if (i == n - 2)
                cout << endl;
            else
                cout << " ";
            ll tmp = convert({v2, v3, pre[pre[v1]]}, n);
            if (exist.count(tmp))
                qu.push({v2, v3, pre[pre[v1]]});
            tmp = convert({v2, v3, next[next[v1]]}, n);
            if (exist.count(tmp))
                qu.push({v2, v3, next[next[v1]]});
            pre[next[v1]] = pre[v1];
            next[pre[v1]] = next[v1];
        }
    }
    return 0;
}
