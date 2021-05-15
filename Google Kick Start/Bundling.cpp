#ifdef LOCAL
#include <header.hpp>
#else
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#endif
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
#define appl(x, f, a)                                                          \
    for (auto &x : a)                                                          \
    f
#define rang(a) begin(a), end(a)
#define gene template <class T>
#define elif else if
#define intm modular_arithmetic::integer
#define bcnt __builtin_popcount
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
    return (a > 0 && b > 0) || (a < 0 && b < 0)
               ? abs(a) / abs(b)
               : -(abs(a) + abs(b) - 1) / abs(b);
}
gene T ceil(const T &a, const T &b) {
    assert(b != 0);
    return (a > 0 && b > 0) || (a < 0 && b < 0) ? (abs(a) + abs(b) - 1) / abs(b)
                                                : -abs(a) / abs(b);
}
gene bool tmin(T &a, T b) { return b < a ? a = b, true : false; }
gene bool tmax(T &a, T b) { return b > a ? a = b, true : false; }
gene auto min(const T &a) { return *min_element(rang(a)); }
gene auto max(const T &a) { return *max_element(rang(a)); }
gene auto sum(const T &a) {
    return accumulate(rang(a), (typename T::value_type)0);
}
template <> auto sum(const vector<int> &a) { return accumulate(rang(a), 0ll); }
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
template <class T, class C = less<typename T::value_type>>
void sort(T &a, C c = C()) {
    sort(rang(a), c);
}
gene void reve(T &a) { reverse(rang(a)); }
gene void uniq(T &a) { sort(a), a.erase(unique(rang(a)), end(a)); }
gene void shuf(T &a) { shuffle(rang(a), rng); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }
gene void in(T &a) { cin >> a; }
template <class A, class... B> void in(A &a, B &... b) { cin >> a, in(b...); }
void ou() { cout << endl; }
gene void ou(const T &a) { cout << a << endl; }
template <class A, class... B> void ou(const A &a, const B &... b) {
    cout << a << ' ', ou(b...);
}
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
#include <bits/stdc++.h>
using namespace std;
namespace static_tree {
template <class T = int> struct static_tree {
    int n, root, block_size, num_blocks;
    vector<vector<pair<int, T>>> to;
    vector<T> depth;
    vector<int> father, level, size, tour_index, closest_size, block_type;
    vector<pair<int, int>> tour;
    vector<vector<pair<int, int>>> st;
    vector<vector<int>> block_min;
    static_tree(int _n, int _root = 0)
        : n(_n), root(_root), block_size(0), to(n), depth(n), father(n),
          level(n), size(n), tour_index(n) {}
    void add_edge(int u, int v, T w = 1) {
        to[u].emplace_back(v, w), to[v].emplace_back(u, w);
    }
    void build_info(int u, int p, vector<bool> &visited) {
        vector<pair<int, T>> new_to;
        size[u] = 1, father[u] = p, visited[u] = true;
        new_to.reserve(to[u].size());
        for (auto e : to[u]) {
            int v = e.first;
            T w = e.second;
            if (v != p) {
                assert(!visited[v]);
                depth[v] = depth[u] + w, level[v] = level[u] + 1;
                build_info(v, u, visited), new_to.push_back(e),
                    size[u] += size[v];
            }
        }
        to[u] = new_to;
    }
    void build_tour(int u) {
        tour_index[u] = int(tour.size()), tour.emplace_back(u, -1);
        for (int i = 0; i < int(to[u].size()); ++i) {
            int v = to[u][i].first;
            build_tour(v), tour_index[u] = int(tour.size());
            tour.emplace_back(u, i);
        }
    }
    pair<int, int> get_min(const pair<int, int> &a, const pair<int, int> &b) {
        int l_a = level[a.first], l_b = level[b.first];
        if (l_a != l_b)
            return l_a < l_b ? a : b;
        if (a.second < b.second)
            return a;
        return b;
    }
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
        st = vector<vector<pair<int, int>>>(
            num_blocks, vector<pair<int, int>>(closest_size[num_blocks] + 1));
        for (int h = 0; h <= closest_size[num_blocks]; ++h)
            for (int i = 0; i < num_blocks; ++i) {
                pair<int, int> &t = st[i][h];
                if (!h) {
                    t = tour[i * block_size];
                    for (int j = i * block_size;
                         j < (i + 1) * block_size && j < int(tour.size()); ++j)
                        t = get_min(t, tour[j]);
                } else if (i + (1 << (h - 1)) >= num_blocks)
                    t = st[i][h - 1];
                else
                    t = get_min(st[i][h - 1], st[i + (1 << (h - 1))][h - 1]);
            }
    }
    void build_block() {
        block_type.resize(num_blocks);
        for (int i = 0; i < num_blocks; ++i) {
            int m = 0;
            for (int j = i * block_size + 1; j < (i + 1) * block_size; ++j) {
                m <<= 1;
                if (j < int(tour.size()) &&
                    level[tour[j].first] > level[tour[j - 1].first])
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
#ifdef LOCAL
        int m = 0;
        for (int i = 0; i < n; ++i)
            m += to[i].size();
        assert(m == 2 * n - 2);
#endif
        vector<bool> visited(n);
        build_info(root, -1, visited);
        assert(*min_element(begin(visited), end(visited)) == 1);
        tour.reserve(2 * n - 1), build_tour(root);
        build_st(), build_block();
    }
    pair<int, int> query_st(int l, int r) {
        int s = closest_size[r - l + 1];
        return get_min(st[l][s], st[r - (1 << s) + 1][s]);
    }
    pair<int, int> query_block(int l, int r) {
        int i = l / block_size, n_l = l % block_size, n_r = r % block_size;
        return tour[i * block_size +
                    block_min[block_type[i]][n_l * block_size + n_r]];
    }
    pair<int, int> rmq(int l, int r) {
        int block_l = l / block_size, block_r = r / block_size;
        pair<int, int> t = tour[l];
        if (block_l == block_r)
            return query_block(l, r);
        t = get_min(t, query_block(l, (block_l + 1) * block_size - 1));
        t = get_min(t, query_block(block_r * block_size, r));
        if (++block_l <= --block_r)
            t = get_min(t, query_st(block_l, block_r));
        return t;
    }
    pair<int, int> _lca(int u, int v) {
        int l = tour_index[u], r = tour_index[v];
        if (l > r)
            swap(l, r);
        return rmq(l, r);
    }
    int lca(int u, int v) { return _lca(u, v).first; }
    T distance(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
    pair<int, T> move_to(int u, int v) {
        assert(u != v);
        pair<int, int> l = _lca(u, v);
        if (u != l.first)
            return make_pair(father[u], depth[u] - depth[father[u]]);
        return to[u][l.second];
    }
};
} // namespace static_tree
struct Trie {
    struct node {
        node(int i_) {
            i = i_;
            fill(c, c + 26, (node *)0);
            cnt = 0;
        }
        node *c[26];
        int i, depth, cnt;
    } * root;
    int index;
    vector<pair<int, int>> edges;
    vector<node *> all_nodes;
    Trie() {
        index = 0;
        root = new node(index++);
        all_nodes.push_back(root);
        root->depth = 0;
    }
    void remove(node *x) {
        if (x) {
            lp(i, 0, 25) remove(x->c[i]);
            delete x;
        }
    }
    ~Trie() { remove(root); }
    int insert(const string &s) {
        node *x = root;
        for (auto c : s) {
            if (!x->c[c - 'A']) {
                x->c[c - 'A'] = new node(index++);
                x->c[c - 'A']->depth = x->depth + 1;
                all_nodes.push_back(x->c[c - 'A']);
                edges.emplace_back(x->i, x->c[c - 'A']->i);
            }
            x = x->c[c - 'A'];
        }
        ++x->cnt;
        return x->i;
    }
    void dfs(node *x, vi &a) {
        a.push_back(x->i);
        lp(i, 0, 25) if (x->c[i]) {
            dfs(x->c[i], a);
            x->cnt += x->c[i]->cnt;
        }
    }
    auto dfs_all() {
        vector<int> tmp;
        dfs(root, tmp);
        vi idx(tmp.size());
        lv(i, tmp) idx[tmp[i]] = i;
        return idx;
    }
    pll solve(node *x, int k) {
        ll sm = 0, cnt = 0;
        lp(i, 0, 25) {
            if (x->c[i]) {
                auto tt = solve(x->c[i], k);
                sm += tt.first, cnt += tt.second;
            }
        }
        ll dcnt = (x->cnt - cnt * k) / k;
        cnt += dcnt;
        sm += dcnt * x->depth;
        return make_pair(sm, cnt);
    }
    ll solve3(int k) { return solve(root, k).first; }
};
int solve(int n, int k, const vector<str> &s) {
    Trie t;
    vi nodes;
    lp(i, 1, n) {
        const str &ss = s[i - 1];
        nodes.push_back(t.insert(ss));
    }
    auto idx = t.dfs_all();
    sort(nodes, [&](int a, int b) { return idx[a] < idx[b]; });
    // ou(nodes);
    static_tree::static_tree<int> tree(t.all_nodes.size());
    for (auto eg : t.edges) {
        tree.add_edge(eg.first, eg.second);
    }
    tree.build();
    int ans = 0;
    for (int i = 0; i < n; i += k) {
        int anss = (~0u >> 1);
        lp(j, i + 1, i + k - 1) {
            tmin(anss, t.all_nodes[tree.lca(nodes[j - 1], nodes[j])]->depth);
        }
        ans += anss;
    }
    return ans;
}
int solve3(int n, int k, const vector<str> &s) {
    Trie t;
    vi nodes;
    lp(i, 1, n) {
        const str &ss = s[i - 1];
        nodes.push_back(t.insert(ss));
    }
    auto idx = t.dfs_all();
    return t.solve3(k);
}
int lcp(const str &a, const str &b) {
    if (a[0] != b[0])
        return 0;
    int i = 0;
    while (i + 1 < a.size() && i + 1 < b.size() && a[i + 1] == b[i + 1])
        ++i;
    return i + 1;
}
int solve2(int n, int k, vector<str> s) {
    vi a(n);
    lp(i, 0, n - 1) a[i] = i;
    int ans = -1;
    do {
        int anss = 0;
        for (int i = 0; i < n; i += k) {
            int dd = (~0u >> 1);
            lp(j, i + 1, i + k - 1) { dd = min(dd, lcp(s[a[i]], s[a[j]])); }
            anss += dd;
        }
        tmax(ans, anss);
    } while (next_permutation(rang(a)));
    return ans;
}
int tmain() {
    fast, prec(12);
    for (int I = 1;; ++I) {
        srand(I);
        int n = rand() % 8 + 2;
        vi cand;
        lp(i, 2, n) if (n % i == 0) cand.push_back(i);
        int k = cand[rand() % cand.size()];
        vector<str> s;
        lp(i, 1, n) {
            str tmp;
            int l = rand() % 4 + 1;
            lp(j, 1, l) tmp.push_back('A' + rand() % 8);
            s.push_back(tmp);
        }
        ou(I);
        ou(n, k);
        for (auto tmp : s)
            ou(tmp);
        int a = solve3(n, k, s), b = solve2(n, k, s);
        ou(a, b);
        assert(a == b);
    }
    many {
        int n, k;
        in(n, k);
        vector<str> s(n);
        in(s);
        ou(solve3(n, k, s), solve2(n, k, s));
    }
    return 0;
}
int main() {
    fast, prec(12);
    int cases = 0;
    many {
        int n, k;
        in(n, k);
        Trie t;
        vi nodes;
        lp(i, 1, n) {
            str s;
            in(s);
            nodes.push_back(t.insert(s));
        }
        auto idx = t.dfs_all();
        ll tt = t.solve3(k);
        cout << "Case #" << ++cases << ": " << tt << endl;
    }
    return 0;
}
/*
1
8 2
AB
ACE
DHAE
DEC
ACAH
AHGC
F
DCGD
*/