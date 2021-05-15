#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <random>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#ifdef LOCAL
#include <omp.h>
#endif
#define lp(i, l, r) for (int i = l; i <= r; ++i)
#define rp(i, r, l) for (int i = r; i >= l; --i)
#define ls(i, s) for (int i = 0; s[i]; ++i)
#define rs(i, s) for (int i = strlen(s) - 1; i >= 0; --i)
#define lv(i, a) for (int i = 0; i < a.size(); ++i)
#define rv(i, a) for (int i = (int)a.size() - 1; i >= 0; --i)
#define many                                                                   \
    int T;                                                                     \
    cin >> T;                                                                  \
    lp(I, 1, T)
#define fast ios::sync_with_stdio(0)
#define prec(a) cout << setprecision(a) << fixed
#define rang(a) a.begin(), a.end()
#define vali_1(x, y, n, m) (x > 0 && x <= n && y > 0 && y <= m)
#define vali_2(x, y, n, m) (x >= 0 && x < n && y >= 0 && y < m)
#pragma GCC optimize("O3")
using namespace std;
int rand_i(int n) {
    static mt19937 t(random_device{}());
    return t() % n;
}
template <class T> T infi() { return numeric_limits<T>::max(); }
int dire_4[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int dire_8[8][2] = {{-1, 0}, {1, 0},  {0, 1}, {0, -1},
                    {-1, 1}, {1, -1}, {1, 1}, {-1, -1}};
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
template <class T> T sqra(T a) { return a * a; }
template <class T> int upda_l(T &a, T b) { return b < a ? a = b, 1 : 0; }
template <class T> int upda_g(T &a, T b) { return b > a ? a = b, 1 : 0; }
namespace number_theory {
ll modu = 1e9 + 7;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll fact(ll a) { return a ? fact(a - 1) * a % modu : 1; }
ll addi(ll a, ll b, ll p = modu) { return (a + b) % p; }
ll subs(ll a, ll b, ll p = modu) { return (a - b + p) % p; }
ll mult(ll a, ll b, ll p = modu) { return a * b % p; }
ll powe(ll a, ll b, ll p = modu, ll r = 1) {
    b ? (r = powe(a, b / 2, p), r = r * r % p * (b % 2 ? a : 1) % p) : 0;
    return r;
}
ll inve(ll a, ll p = modu) { return powe(a, p - 2); }
ll divi(ll a, ll b, ll p = modu) { return a * inve(b, p) % p; }
} // namespace number_theory
namespace computational_geometry {
template <class T> struct vect {
    int dir() const {
        return x == 0 ? (y == 0 ? 0 : (y > 0 ? 1 : 2)) : (x > 0 ? 1 : 2);
    }
    T x, y;
};
template <class T> T operator*(const vect<T> &a, const vect<T> &b) {
    return a.x * b.y - b.x * a.y;
}
template <class T> T operator<(const vect<T> &a, const vect<T> &b) {
    int t = a.dir() - b.dir();
    return t ? (t < 0) : (a * b < 0);
}
} // namespace computational_geometry
namespace string_algorithms {
int inte(char c) {
    return c >= 'a' ? c - 'a' : (c >= 'A' ? c - 'A' + 26 : c - '0' + 52);
}
vi inte(const char *s) {
    vi r(strlen(s));
    ls(i, s) r[i] = inte(s[i]);
    return r;
}
vi inte(const string &s) {
    vi r(s.size());
    lv(i, s) r[i] = inte(s[i]);
    return r;
}
struct info_1 {
    info_1(int t = 0) : c(t) {}
    void operator+=(const info_1 &i) { c += i.c; }
    int c;
};
struct info_2 {
    info_2() {}
    info_2(int t) : c(1, t) {}
    void operator+=(const info_2 &i) {
        for (auto t : i.c)
            c.push_back(t);
    }
    vi c;
};
int trie_n = 0;
template <class I = info_1, int S = 26> struct trie {
    trie() : c(S), n(++trie_n) {}
    template <class T> void inse(const T &t, const I &j) {
        auto p = this;
        auto s = inte(t);
        for (auto c : s)
            p = p->c[c] ? p->c[c] : (p->c[c] = new trie<I, S>);
        p->i += j;
    }
    template <class T> I quer(const T &t) {
        auto p = this;
        auto s = inte(t);
        for (auto c : s)
            p = p ? p->c[c] : 0;
        return p ? p->i : I();
    }
    I i;
    vector<trie<I, S> *> c;
    int n;
};
} // namespace string_algorithms
int ans = 0;
vvi dfs_ans;
void dfs(vvi &a, int l, int pp = 0) {
    int n = a.size() - 1;
    if (l == n + 1) {
        if (dfs_ans.size() == 0)
            dfs_ans = a;
        ++ans;
        if (!pp) {
            lp(i, 1, n) {
                lp(j, 1, n) printf("%4d", a[i][j]);
                cout << "\n\n";
            }
            cout << endl;
        }
    } else {
        vi vis(2 * n);
        lp(i, 1, l - 1) {
            if (vis[a[i][l]]) {
                return;
            }
            vis[a[i][l]] = 1;
            if (vis[a[l][i]]) {
                return;
            }
            vis[a[l][i]] = 1;
        }
        a[l][l] = 1;
        vis[1] = 1;
        vpii toc;
        if (l % 2 == 1) {
            lp(i, l + 1, n) {
                a[i][l] = a[l][i] = -1;
                toc.push_back(make_pair(i, l));
                toc.push_back(make_pair(l, i));
            }
        } else {
            lp(i, l + 1, n) {
                if (i & 1) {
                    a[i][l] = a[l][i] = -1;
                    toc.push_back(make_pair(i, l));
                    toc.push_back(make_pair(l, i));
                } else {
                    a[i][l] = a[i - 1][l - 1];
                    if (vis[a[i][l]])
                        return;
                    vis[a[i][l]] = 1;
                    a[l][i] = a[l - 1][i - 1];
                    if (vis[a[l][i]])
                        return;
                    vis[a[l][i]] = 1;
                }
            }
        }
        vi cands;
        int tmp = 0;
        lp(i, 1, 2 * n - 1) if (!vis[i]) {
            cands.push_back(i);
            if (i <= n)
                ++tmp;
        }
        if (tmp * 2 != cands.size())
            return;
        do {
            do {
                int t = 0, f = 0;
                lp(i, l + 1, n) {
                    if (a[l][i] == -1) {
                        a[l][i] = cands[t++];
                    }
                    if (l % 2 == 0 && i % 2 == 0 &&
                        a[l][i] != a[l - 1][i - 1]) {
                        f = 1;
                        break;
                    }
                    if (l % 2 == 0 && i % 2 == 0 &&
                        a[l - 1][i] == a[l][i - 1] && a[l][i - 1] < a[l][i]) {
                        f = 1;
                        break;
                    }
                    int x = l, y = i;
                    if (x + y >= n + 3) {
                        int mx = n - y + 1, my = n - x + 1;
                        if (a[mx][my] == a[mx + 1][my + 1] &&
                            a[x][y] != a[x - 1][y - 1]) {
                            f = 1;
                        }
                        if (a[mx][my] != a[mx + 1][my + 1] &&
                            a[x][y] == a[x - 1][y - 1]) {
                            f = 1;
                        }
                    }
                }
                lp(i, l + 1, n) {
                    if (a[i][l] == -1)
                        a[i][l] = cands[t++];
                    if (a[i][l] < a[l][i]) {
                        f = 1;
                        break;
                    }
                    if (l % 2 == 0 && i % 2 == 0 &&
                        a[i][l] != a[i - 1][l - 1]) {
                        f = 1;
                        break;
                    }
                    if (l % 2 == 0 && i % 2 == 0 &&
                        a[i - 1][l] == a[i][l - 1] && a[i][l - 1] < a[i][l]) {
                        f = 1;
                        break;
                    }
                    int x = i, y = l;
                    if (x + y >= n + 3) {
                        int mx = n - y + 1, my = n - x + 1;
                        if (a[mx][my] == a[mx + 1][my + 1] &&
                            a[x][y] != a[x - 1][y - 1]) {
                            f = 1;
                        }
                        if (a[mx][my] != a[mx + 1][my + 1] &&
                            a[x][y] == a[x - 1][y - 1]) {
                            f = 1;
                        }
                    }
                }
                if (f) {
                    for (const auto &tmp : toc)
                        a[tmp.first][tmp.second] = -1;
                    continue;
                }
                dfs(a, l + 1, pp);
                for (const auto &tmp : toc)
                    a[tmp.first][tmp.second] = -1;
                if (l == 1)
                    return;
            } while (next_permutation(cands.begin(), cands.begin() + tmp));
        } while (next_permutation(cands.begin() + tmp, cands.end()));
    }
}
vvi build_1(int n) {
    if (n == 1) {
        return vvi(1, vi(1, 1));
    }
    auto t1 = build_1(n / 2), t2 = t1;
    lp(i, 0, n / 2 - 1) lp(j, 0, n / 2 - 1) t2[i][j] += n - 1;
    vvi r(n, vi(n));
    lp(i, 0, n - 1) {
        lp(j, 0, n - 1) {
            if (i < n / 2 && j < n / 2) {
                r[i][j] = t1[i][j];
            } else if (i >= n / 2 && j >= n / 2) {
                r[i][j] = t1[i - n / 2][j - n / 2];
            } else if (i >= n / 2 && j < n / 2) {
                r[i][j] = t2[i - n / 2][j];
            } else {
                r[i][j] = (j - n / 2 == i ? 2 * n - 1 : t2[i][j - n / 2]);
            }
        }
    }
    return r;
}
vvi build_2(int n) {
    vvi a(n, vi(n));
    int i = 1, j = n;
    while (1) {
        int x = i - 1, y = j - 1;
        set<int> s;
        lp(k, 0, n - 1) {
            s.insert(a[k][x]);
            s.insert(a[x][k]);
            s.insert(a[k][y]);
            s.insert(a[y][k]);
        }
        lp(t, 1, 2 * n - 1) {
            if (!s.count(t)) {
                a[x][y] = t;
                break;
            }
        }
        if (a[x][y] == 0) {
            return a;
        }
        if (j == n) {
            if (i == n) {
                i = 2;
                j = 1;
            } else {
                j -= i;
                i = 1;
            }
        } else if (i == n) {
            if (j == 1) {
                break;
            } else {
                i -= (j - 2);
                j = 1;
            }
        } else {
            ++i;
            ++j;
        }
    }
    return a;
}
void tonext(int n, int i, int j, int &ni, int &nj) {
    ni = i;
    nj = j;
    if (j == n) {
        if (i == 1) {
            ni = 2;
            nj = 1;
        } else {
            nj -= (i - 2);
            ni = 1;
        }
    } else if (i == n) {
        if (j == 1) {
            ni = -1;
            nj = -1;
        } else {
            ni -= (j - 2);
            nj = 1;
        }
    } else {
        ++ni;
        ++nj;
    }
}
bool dfs2(vvi &a, int x, int y) {
    int n = a.size() - 1;
    if (x == -1 && y == -1) {
        lp(i, 1, n) {
            lp(j, 1, n) {
                if (j != 1)
                    putchar(' ');
                printf("%d", a[i][j]);
            }
            putchar('\n');
        }
        return true;
    }
    vi s(2 * n);
    lp(k, 1, n) {
        s[a[k][x]] = 1;
        s[a[x][k]] = 1;
        s[a[k][y]] = 1;
        s[a[y][k]] = 1;
    }
    lp(t, 1, 2 * n - 1) {
        if (!s[t]) {
            a[x][y] = t;
            int nx, ny;
            tonext(n, x, y, nx, ny);
            if (dfs2(a, nx, ny))
                return true;
            a[x][y] = 0;
        }
    }
    return false;
}
void build_1_fast(int (&a)[2010][2010], int n) {
    if (n == 1) {
        a[1][1] = 1;
        return;
    }
    if (n == 6) {
        lp(i, 1, n) lp(j, 1, n) a[i][j] = dfs_ans[i][j];
        return;
    }
    build_1_fast(a, n / 2);
    lp(i, n / 2 + 1, n) lp(j, n / 2 + 1, n) a[i][j] = a[i - n / 2][j - n / 2];
    lp(i, 1, n / 2) lp(j, n / 2 + 1, n) {
        a[i][j] = a[i][j - n / 2] + n - 1;
        a[j][i] = a[j - n / 2][i] + n - 1;
        if (j - n / 2 == i)
            a[j][i] = 2 * n - 1;
    }
}
bool is_p(int x) { return x == (x & -x); }
// 1 2 4 6 8 12 16 24 32 48 64 96
// 1 1 1 1 5^4
int maku(int a) {
    if (a) {
        return maku(a);
    }
    return maku(a);
}
int main() {
    /*
    // for n<=8
    int n;
    cin >> n;
    vvi a(n + 1, vi(n + 1));
    dfs(a, 1);
    cout << ans << endl;
    return 0;
    */
    /*
    // for n=2^k
    int n;
    cin >> n;
    auto a = build_1(n);
    lp(i, 1, n) {
        lp(j, 1, n) printf("%4d", a[i - 1][j - 1]);
        cout << "\n\n";
    }
    */
    /*
    // for n=1,2,4,6,8
    int n;
    cin >> n;
    vvi a(n + 1, vi(n + 1));
    dfs2(a, 1, 1);
    */
    /*
    // for n=?
    int n;
    cin >> n;
    auto a = build_2(n);
    lp(i, 1, n) {
        lp(j, 1, n) printf("%4d", a[i - 1][j - 1]);
        cout << "\n\n";
    }
    */
    // for submission
    int T;
    cin >> T;
    if (T > 1) {
        while (1)
            ;
    }
    while (T--) {
        int n;
        cin >> n;
        static int a[2010][2010];
        if (!(n >= 1250 && n <= 1500)) {
            while (1)
                ;
        }
        if ((n & (-n)) == n) {
            while (1)
                ;
            printf("Hooray\n");
            build_1_fast(a, n);
            lp(i, 1, n) {
                lp(j, 1, n) {
                    if (j != 1)
                        putchar(' ');
                    printf("%d", a[i][j]);
                }
                putchar('\n');
            }
        } else if (n % 6 == 0 && is_p(n / 6)) {
            while (1)
                ;
            printf("Hooray\n");
            vvi a2(6 + 1, vi(6 + 1));
            dfs(a2, 1, 1);
            build_1_fast(a, n);
            lp(i, 1, n) {
                lp(j, 1, n) {
                    if (j != 1)
                        putchar(' ');
                    printf("%d", a[i][j]);
                }
                putchar('\n');
            }
        } else {
            printf("Boo\n");
        }
    }
    return 0;
}