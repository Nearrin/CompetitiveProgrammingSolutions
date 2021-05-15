#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#define lp(i, l, r) for (int i = l; i <= r; ++i)
#define rp(i, r, l) for (int i = r; i >= l; --i)
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
gene int tmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
gene int tmax(T &a, T b) { return b > a ? a = b, 1 : 0; }
#if __cplusplus >= 201402L
gene auto min(const T &a) { return *min_element(rang(a)); }
gene auto max(const T &a) { return *max_element(rang(a)); }
gene auto sum(const T &a) { return accumulate(rang(a), 0); }
gene auto gath(const T &a, const vector<int> &b) {
    vector<typename T::value_type> r;
    for (auto i : b)
        r.push_back(a[i]);
    return r;
}
#endif
gene void sort(T &a) { sort(rang(a)); }
gene void reve(T &a) { reverse(rang(a)); }
gene void uniq(T &a) { sort(a), a.erase(unique(rang(a)), end(a)); }
gene void shuf(T &a) { random_shuffle(rang(a)); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
#if __cplusplus >= 201703L
template <typename... T> void in(T &... a) { ((cin >> a), ...); }
template <typename... T> void ou(T... a) { ((cout << a << ' '), ...) << '\n'; }
#endif
#if __cplusplus >= 201402L
template <class F, class S> auto &operator>>(istream &s, pair<F, S> &a) {
    return s >> a.first >> a.second;
}
template <class F, class S> auto &operator<<(ostream &s, const pair<F, S> &a) {
    return s << '(' << a.first << ", " << a.second << ')';
}
gene auto &operator>>(istream &s, vector<T> &a) {
    for (int i = -1; i < 0 && (!a.size() && (cin >> i, a.resize(i), 0), i = 0),
             i < int(a.size());)
        s >> a[i++];
    return s;
}
gene auto &operator<<(ostream &s, const vector<T> &a) {
    lv(i, a) cout << a[i] << (i + 1 == int(a.size()) ? "" : " ");
    return s;
}
#endif
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
namespace static_rmq {
struct static_tree {
    int n, root, block_size, num_blocks;
    vector<vector<int>> to;
    vector<int> level, tour_index, closest_size, block_type, tour;
    vector<vector<int>> st;
    vector<vector<int>> block_min;
    static_tree(int _n, int _root = 0)
        : n(_n), root(_root), block_size(0), to(n), level(n), tour_index(n) {}
    void add_edge(int u, int v) { to[u].push_back(v); }
    void build_tour(int u) {
        tour_index[u] = int(tour.size()), tour.push_back(u);
        for (auto v : to[u]) {
            level[v] = level[u] + 1;
            build_tour(v), tour_index[u] = int(tour.size());
            tour.push_back(u);
        }
    }
    int get_min(int a, int b) { return level[a] < level[b] ? a : b; }
    void build_st() {
        block_size = max(1, int(log2(tour.size()) / 2));
        num_blocks =
            int(tour.size()) / block_size + bool(tour.size() % block_size);
        closest_size.resize(num_blocks + 1, 0);
        for (int i = 2; i <= num_blocks; ++i) {
            closest_size[i] = closest_size[i - 1];
            if ((1 << (closest_size[i] + 1)) <= i)
                ++closest_size[i];
        }
        st = vector<vector<int>>(closest_size[num_blocks] + 1,
                                 vector<int>(num_blocks));
        for (int h = 0; h <= closest_size[num_blocks]; ++h)
            for (int i = 0; i < num_blocks; ++i) {
                int &t = st[h][i];
                if (!h) {
                    t = tour[i * block_size];
                    for (int j = i * block_size;
                         j < (i + 1) * block_size && j < int(tour.size()); ++j)
                        t = get_min(t, tour[j]);
                } else if (i + (1 << (h - 1)) >= num_blocks)
                    t = st[h - 1][i];
                else
                    t = get_min(st[h - 1][i], st[h - 1][i + (1 << (h - 1))]);
            }
    }
    void build_block() {
        block_type.resize(num_blocks);
        for (int i = 0; i < num_blocks; ++i) {
            int m = 0;
            for (int j = i * block_size + 1; j < (i + 1) * block_size; ++j) {
                m <<= 1;
                if (j < int(tour.size()) && level[tour[j]] > level[tour[j - 1]])
                    ++m;
            }
            block_type[i] = m;
        }
        block_min = vector<vector<int>>(1 << (block_size - 1),
                                        vector<int>(block_size * block_size));
        for (int m = 0; m < (1 << (block_size - 1)); ++m) {
            for (int i = 0; i < block_size; ++i) {
                pair<int, int> t(0, i);
                int v = 0, k = i * block_size;
                block_min[m][k + i] = i;
                for (int j = i + 1; j < block_size; ++j) {
                    if ((m >> (block_size - 1 - j)) & 1)
                        ++v;
                    else
                        --v;
                    if (v < t.first)
                        t = make_pair(v, j);
                    block_min[m][k + j] = t.second;
                }
            }
        }
    }
    void build() {
        tour.reserve(2 * n - 1), build_tour(root), build_st(), build_block();
    }
    int lca(int u, int v) {
        int l = tour_index[u], r = tour_index[v];
        if (l > r)
            swap(l, r);
        int b_l = l / block_size, i_l = l % block_size, b_r = r / block_size,
            i_r = r % block_size;
        if (b_l == b_r)
            return tour[(l - i_l) +
                        block_min[block_type[b_l]][i_l * block_size + i_r]];
        u = tour[l - i_l +
                 block_min[block_type[b_l]][i_l * block_size + block_size - 1]];
        v = tour[r - i_r + block_min[block_type[b_r]][i_r]];
        if (level[v] < level[u])
            u = v;
        if (++b_l <= --b_r) {
            int s = closest_size[b_r - b_l + 1];
            v = get_min(st[s][b_l], st[s][b_r - (1 << s) + 1]);
            if (level[v] < level[u])
                u = v;
        }
        return u;
    }
};
template <class T, class C> struct berkman_vishkin_algorithm {
    int n;
    vector<T> a;
    vector<int> p;
    static_tree tree;
    berkman_vishkin_algorithm(int _n) : n(_n), a(n), p(n, -1), tree(n) {}
    void build() {
        stack<int> s;
        for (int i = 0; i < n; i++) {
            int last = -1;
            while (!s.empty() && !C()(a[s.top()], a[i]))
                last = s.top(), s.pop();
            if (!s.empty())
                p[i] = s.top();
            if (last >= 0)
                p[last] = i;
            s.push(i);
        }
        for (int i = 0; i < n; ++i)
            if (p[i] == -1)
                tree.root = i;
            else
                tree.add_edge(p[i], i);
        tree.build();
    }
    const T &query(int l, int r) {
        assert(l <= r);
        return a[tree.lca(l, r)];
    }
};
} // namespace static_rmq
int main() {
    fast, prec(12);
    int n;
    cin >> n;
    static_rmq::berkman_vishkin_algorithm<int, less<int>> rmq(n);
    lp(i, 1, n) { cin >> rmq.a[i - 1]; }
    int m;
    cin >> m;
    rmq.build();
    lp(i, 1, m) {
        int l, r;
        cin >> l >> r;
        cout << rmq.query(l, r) << endl;
    }
    return 0;
}
